#include <MainCompiler.h>
#include <fstream>
#include <Defines.h>

void CMainCompiler::Process(int argc, char * argv[])
{
	args.ParseArgs(argc, argv);
	initStreams();
	buildAST();
	dumpAST();
	typeCheck();
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
	checker.BuildTable(root.get(), "temp_name");
	typeChecker.CheckTypes(root.get(), "temp_name");
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
