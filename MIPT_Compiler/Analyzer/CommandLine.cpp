#include "CommandLine.h"
#include <exception>
#include <cassert>

void CCommandLineArguments::ParseArgs(int argc, char* argv[])
{
	if (argc < 2) {
		throw new std::exception;
	}

	inputFileName = argv[argc - 1];
	for (int i = 1; i < argc; ++i) {
		if (strncmp(argv[i], "--lname", 10) == 0) {
			dumpLex = true;
			lexFileName = getNextName(argc, argv, i);
			++i;
		}
		if (strncmp(argv[i], "-l", 5) == 0) {
			dumpLex = true;
		}
		if (strncmp(argv[i], "--bname", 10) == 0) {
			dumpBison = true;
			bisonFileName = getNextName(argc, argv, i);
			++i;
		}
		if (strncmp(argv[i], "-b", 5) == 0) {
			dumpBison = true;
		}
		if (strncmp(argv[i], "--astname", 10) == 0) {
			dumpAST = true;
			ASTFileName = getNextName(argc, argv, i);
			++i;
		}
		if (strncmp(argv[i], "-a", 5) == 0) {
			dumpAST = true;
		}
		if (strncmp(argv[i], "--irname", 10) == 0) {
			dumpIR = true;
			IRFileName = getNextName(argc, argv, i);
			++i;
		}
		if (strncmp(argv[i], "-i", 5) == 0) {
			dumpIR = true;
		}
		if (strncmp(argv[i], "--ename", 10) == 0) {
			customErrors = true;
			typeErrorsFileName = getNextName(argc, argv, i);
			++i;
		}
	}
	return;
}

bool CCommandLineArguments::IsLexDumping() const
{
	return dumpLex;
}

bool CCommandLineArguments::IsASTDumping() const
{
	return dumpAST;
}

bool CCommandLineArguments::IsBisonDumping() const
{
	return dumpBison;
}

bool CCommandLineArguments::IsIRDumping() const
{
	return dumpIR;
}

bool CCommandLineArguments::HasCustomErrorsFile() const
{
	return customErrors;
}

const std::string & CCommandLineArguments::GetInputFileName() const
{
	return inputFileName;
}

const std::string & CCommandLineArguments::GetLexFileName() const
{
	return lexFileName;
}

const std::string & CCommandLineArguments::GetBisonFileName() const
{
	return bisonFileName;
}

const std::string & CCommandLineArguments::GetASTFileName() const
{
	return ASTFileName;
}

const std::string & CCommandLineArguments::GetErrorsFileName() const
{
	assert(customErrors);
	return typeErrorsFileName;
}

const std::string & CCommandLineArguments::GetIRFileName() const
{
	return IRFileName;
}

std::string CCommandLineArguments::getNextName(int argc, char * argv[], int i)
{
	if (argc <= i + 1) {
		throw new std::exception;
	}
	return std::string(argv[i + 1]);
}
