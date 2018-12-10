#include <MainCompiler.h>
#include <fstream>
#include <Defines.h>

void CMainCompiler::Process(int argc, char * argv[])
{
	args.ParseArgs(argc, argv);
	initStreams();
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
	assert(false);
}

void CMainCompiler::initStreams()
{
	std::unique_ptr<std::ofstream> tmpstr;
	tmpstr.reset(new std::ofstream);
	tmpstr->open(args.GetLexFileName(), std::ofstream::out);
	lexDumpFile.reset(tmpstr.release());

	tmpstr.reset(new std::ofstream);
	tmpstr->open(args.GetBisonFileName(), std::ofstream::out);
	bisonDumpFile.reset(tmpstr.release());

	if (args.HasCustomErrorsFile()) {
		tmpstr.reset(new std::ofstream);
		tmpstr->open(args.GetErrorsFileName(), std::ofstream::out);
		errorsFile.reset(tmpstr.release());
	}
}

void CMainCompiler::dumpAST()
{
	CStackBuilder builder;
	builder.BuildStack(root.get());

	CPrettyPrinter printer("graphs/printer.txt");
	for (int i = static_cast<int>(builder.nodesStack.size()) - 1; i >= 0; i--) {
		ITree* node = builder.nodesStack[i];
		node->Accept(&printer);
	}
	printer.close();
}

void CMainCompiler::typeCheck()
{
	CStackBuilder builder;
	builder.BuildStack(root.get());

	CMalformedProgramChecker checker;
	CTypeChecker typeChecker;
	checker.BuildTable(root.get(), "temp_name");
	typeChecker.CheckTypes(root.get(), "temp_name");
	//CErrorTable::Print(errorStream);
}

void CMainCompiler::buildAST()
{
	//fopen_s(&yyin, args.GetInputFileName().c_str(), "r");

	ITree* temp = nullptr;
	//yyparse(&temp);
	root.reset(temp);
}
