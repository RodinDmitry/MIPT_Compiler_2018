#pragma once

#include <CommandLine.h>
#include <Tree.h>
#include <iostream>

class CMainCompiler {
public:

	void Process(int argc, char* argv[]);

	void dumpBisonToken(const std::string& token);
	void dumpLexToken(const std::string& token);
	void dumpSyntaxError(const std::string& name, int line);
private:
	CCommandLineArguments args;
	std::unique_ptr<ITree> root;

	std::unique_ptr<std::ostream> lexDumpFile;
	std::unique_ptr<std::ostream> bisonDumpFile;
	std::unique_ptr<std::ostream> errorsFile;


	void initStreams();
	void dumpAST();
	void typeCheck();
	void buildAST();

};