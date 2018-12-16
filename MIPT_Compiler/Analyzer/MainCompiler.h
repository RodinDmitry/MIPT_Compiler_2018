#pragma once

#include <CommandLine.h>
#include <Tree.h>
#include <IRTreeBuilder.h>
#include <iostream>
#include <map>

class CMainCompiler {
public:

	void Process(int argc, char* argv[]);

	void dumpBisonToken(const std::string& token);
	void dumpLexToken(const std::string& token);
	void dumpSyntaxError(const std::string& name, int line);

	void SetRoot(ITree* root);
	~CMainCompiler();
private:
	CCommandLineArguments args;
	std::unique_ptr<ITree> root;
	std::shared_ptr<std::map<const CSymbol*, std::shared_ptr<IR::ITreeWrapper>>> IRTrees;
	std::string tableName;

	std::unique_ptr<std::ostream> lexDumpFile;
	std::unique_ptr<std::ostream> bisonDumpFile;
	std::unique_ptr<std::ostream> errorsFile;


	void initStreams();
	void dumpAST();
	void typeCheck();
	void buildAST();
	void AddFrames();
	void buildIR();
	void dumpIR();

};