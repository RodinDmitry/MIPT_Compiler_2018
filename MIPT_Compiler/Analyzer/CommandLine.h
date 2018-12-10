#pragma once
#include <string>

class CCommandLineArguments {
public:

	void ParseArgs(int argc, char* argv[]);

private:
	bool dumpLex = false;
	bool dumpBison = false;
	bool dumpAST = false;
	std::string lexFileName = "LEXdump.txt";
	std::string bisonFileName = "BISONdump.txt";
	std::string ASTFileName = "ASTFileName.txt";
	std::string inputFileName = "";
	std::string syntaxErrorsFileName = "";
	std::string tokensErrorsFileName = "";
	std::string typeErrorsFileName = "";

	static std::string getNextName(int argc, char* argv[], int i);
};
