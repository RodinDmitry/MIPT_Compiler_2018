#pragma once
#include <string>

class CCommandLineArguments {
public:

	void ParseArgs(int argc, char* argv[]);

	bool IsLexDumping() const;
	bool IsASTDumping() const;
	bool IsBisonDumping() const;
	bool HasCustomErrorsFile() const;

	const std::string& GetInputFileName() const;
	const std::string& GetLexFileName() const;
	const std::string& GetBisonFileName() const;
	const std::string& GetASTFileName() const;
	const std::string& GetErrorsFileName() const;

private:
	bool dumpLex = false;
	bool dumpBison = false;
	bool dumpAST = false;
	bool customErrors = false;
	std::string lexFileName = "dumps/LEXdump.txt";
	std::string bisonFileName = "dumps/BISONdump.txt";
	std::string ASTFileName = "dumps/ASTFileName.txt";
	std::string inputFileName = "";
	std::string syntaxErrorsFileName = "";
	std::string tokensErrorsFileName = "";
	std::string typeErrorsFileName = "";

	static std::string getNextName(int argc, char* argv[], int i);
};
