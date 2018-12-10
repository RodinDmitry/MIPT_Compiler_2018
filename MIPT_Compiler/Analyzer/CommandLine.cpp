#include "CommandLine.h"
#include <exception>

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
		if (strncmp(argv[i], "--ename", 10) == 0) {
			typeErrorsFileName = getNextName(argc, argv, i);
			++i;
		}
	}
}

std::string CCommandLineArguments::getNextName(int argc, char * argv[], int i)
{
	if (argc <= i + 1) {
		throw new std::exception;
	}
	return std::string(argv[i + 1]);
}
