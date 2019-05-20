#include <MainCompiler.h>
#include <fstream>
#include <Defines.h>
#include <FrameVistor.h>
#include <IRPrinter.h>
#include <IR/CallUpliftVisitor.h>
#include <IR/EseqRemoverVisitor.h>
#include <IR/LinearizationVisitor.h>
#include <IR/BlockVisitor.h>
#include <IR/TraceBuilderVisitor.h>
#include <Synthesis/CommandBuilder.h>
#include <TreeWrapper.h>
#include <sstream>

void CMainCompiler::Process(int argc, char * argv[])
{
	args.ParseArgs(argc, argv);
	tableName = args.GetInputFileName();
	initStreams();
	buildAST();
	if (!root) {
		return;
	}
	dumpAST();
	typeCheck();
	if (CErrorTable::HasErrors()) {
		return;
	}
	AddFrames();
	buildIR();

	dumpIR("original");
	updateCalls();
	dumpIR("calls");
	removeEseq();
	dumpIR("eseq");
	linearizeTree();
	dumpIR();

	buildBlocks();
	buildTraces();
	buildTiling();
	buildASM();
	dumpAsm("asm");
}

void CMainCompiler::dumpBisonToken(const std::string & token)
{
	if (args.IsBisonDumping()) {
		*bisonDumpFile << token << ' ';
	}
}

void CMainCompiler::dumpLexToken(const std::string& token)
{
	if (args.IsLexDumping()) {
		*lexDumpFile << token << ' ';
	}
}

void CMainCompiler::dumpSyntaxError(const std::string& name, int line)
{
	CErrorTable::AddError(name, line);
}

void CMainCompiler::SetRoot(ITree* _root)
{
	root.reset(_root);
}

CMainCompiler::~CMainCompiler()
{
	if (!args.HasCustomErrorsFile()) {
		errorsFile.release();
	}
}

void CMainCompiler::initStreams()
{
	std::unique_ptr<std::ofstream> tmpstr;

	if (args.IsLexDumping()) {
		tmpstr.reset(new std::ofstream);
		tmpstr->open(args.GetLexFileName(), std::ofstream::out);
		lexDumpFile.reset(tmpstr.release());
	}

	if (args.IsBisonDumping()) {
		tmpstr.reset(new std::ofstream);
		tmpstr->open(args.GetBisonFileName(), std::ofstream::out);
		bisonDumpFile.reset(tmpstr.release());
	}

	if (args.HasCustomErrorsFile()) {
		tmpstr.reset(new std::ofstream);
		tmpstr->open(args.GetErrorsFileName(), std::ofstream::out);
		errorsFile.reset(tmpstr.release());
	}
	else {
		errorsFile.reset(&std::cerr);
	}
}

void CMainCompiler::dumpAST()
{
	if (args.IsASTDumping()) {
		CStackBuilder builder;
		builder.BuildStack(root.get());

		CPrettyPrinter printer(args.GetASTFileName());
		for (int i = static_cast<int>(builder.nodesStack.size()) - 1; i >= 0; i--) {
			ITree* node = builder.nodesStack[i];
			node->Accept(&printer);
		}
		printer.close();
	}
}

void CMainCompiler::typeCheck()
{
	CStackBuilder builder;
	builder.BuildStack(root.get());

	CMalformedProgramChecker checker;
	CTypeChecker typeChecker;
	checker.BuildTable(root.get(), tableName);
	typeChecker.CheckTypes(root.get(), tableName);
	CErrorTable::Print(*errorsFile);
}

void CMainCompiler::buildAST()
{
	yyscan_t scanner;
	yylex_init(&scanner);

	FILE* str;
	fopen_s(&str, args.GetInputFileName().c_str(), "r");

	yyset_in(str, scanner);
	yyparse(scanner, this);

	yylex_destroy(scanner);

	fclose(str);
}

void CMainCompiler::AddFrames()
{
	CFrameVisitor visitor;
	visitor.AddFrames(root.get(), tableName);
}

void CMainCompiler::buildIR()
{
	CIRTreeBuilder builder;
	IRTrees = builder.BuildIRTree(root.get(), tableName);
}

void CMainCompiler::dumpIR(const std::string& suffix)
{
	if (args.IsIRDumping()) {
		IR::CIRPrinterVisitor printer(args.GetIRFileName() + suffix);
		std::map<const CSymbol*, std::shared_ptr<IR::ITreeWrapper>>::iterator tree = IRTrees->begin();
		for (tree; tree != IRTrees->end(); ++tree) {
			printer.PrintTree((*tree).second->ToStatement().get());

		}
		printer.close();
	}
}

void CMainCompiler::dumpAsm(const std::string& suffix)
{
	std::ofstream output;
	std::string name = args.GetIRFileName() + suffix;
	output.open(name, std::ofstream::out);

	for (auto code : codes) {
		output << code << std::endl;
	}
	output.close();
}

void CMainCompiler::buildBlocks()
{
	programBlocks = std::make_shared< std::vector<Synthesis::CBlock>>();

	std::map<const CSymbol*, std::shared_ptr<IR::ITreeWrapper>>::iterator tree = IRTrees->begin();
	for (tree; tree != IRTrees->end(); ++tree) {
		IR::CBlockVisitor visitor;
		(*tree).second->ToStatement()->Accept(&visitor);
		auto blocks = visitor.getResult();
		for (int i = 0; i < blocks->size(); i++) {
			programBlocks->push_back(blocks->at(i));
		}
	}
}

void CMainCompiler::buildTraces()
{
	Synthesis::CTraceBuilder builder;
	traces = builder.buildTraces(programBlocks);
	
}

void CMainCompiler::buildTiling()
{
	for (auto trace = traces->begin(); trace != traces->end(); ++trace) {
		IR::CTraceBuilderVisitor traceVisitor;
		trace->at(0)->Accept(&traceVisitor);
		std::string label = traceVisitor.getLabel();

		for (auto block = trace->begin(); block != trace->end(); ++block) {
			
			for (const auto& statement : (*block)->Get()) {
				std::shared_ptr<Synthesis::CTilingVisitor> visitor =
					std::make_shared<Synthesis::CTilingVisitor>(statement.get());
				statement->Accept(visitor.get());
				commands[label].push_back(visitor);
			}

		}
	}
}

void CMainCompiler::buildASM()
{
	for (auto methodIt = commands.begin(); methodIt != commands.end(); ++methodIt) {
		for (auto visitorIt = methodIt->second.begin(); visitorIt != methodIt->second.end(); ++visitorIt) {
			Synthesis::CCommandBuilder builder;
			(*visitorIt)->Result()->Accept(&builder);
			for (const auto& line : builder.Result()) {
				std::stringstream textStream;
				textStream << line.Text();
				for (const auto& reg : line.Registers()) {
					textStream << ' ' << reg;
				}
				codes.push_back(textStream.str());
			}
		}
	}
}

void CMainCompiler::updateCalls()
{
	std::map<const CSymbol*, std::shared_ptr<IR::ITreeWrapper>>::iterator tree = IRTrees->begin();
	for (tree; tree != IRTrees->end(); tree++) {
		IR::CCallUpliftVisitor visitor;
		(*tree).second->ToStatement()->Accept(&visitor);
		std::shared_ptr<IR::CStatementWrapper> wrapper = std::make_shared<IR::CStatementWrapper>(visitor.getStatementTree());
		IRTrees->at((*tree).first) = wrapper;
	}

}

void CMainCompiler::removeEseq()
{
	std::map<const CSymbol*, std::shared_ptr<IR::ITreeWrapper>>::iterator tree = IRTrees->begin();
	for (tree; tree != IRTrees->end(); tree++) {
		IR::CEseqRemoverVisitor visitor;
		(*tree).second->ToStatement()->Accept(&visitor);
		std::shared_ptr<IR::CStatementWrapper> wrapper = std::make_shared<IR::CStatementWrapper>(visitor.getStatementTree());
		IRTrees->at((*tree).first) = wrapper;
	}
}

void CMainCompiler::linearizeTree()
{
	std::map<const CSymbol*, std::shared_ptr<IR::ITreeWrapper>>::iterator tree = IRTrees->begin();
	for (tree; tree != IRTrees->end(); tree++) {
		IR::CLinearizationVisitor visitor;
		(*tree).second->ToStatement()->Accept(&visitor);
		std::shared_ptr<IR::CStatementWrapper> wrapper = std::make_shared<IR::CStatementWrapper>(visitor.getResult());
		IRTrees->at((*tree).first) = wrapper;
	}
}
