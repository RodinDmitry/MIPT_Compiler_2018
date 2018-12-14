#include <Defines.h>
#include <iostream>
#include <MainCompiler.h>


std::ofstream lexDumpFile;
bool LEX_DUMP = false;
std::ofstream bisonDumpFile;
bool BISON_DUMP = true;

std::string outFileName;

void printTree(ITree* tree) {
	CStackBuilder builder;
	builder.BuildStack(tree);
	
	CPrettyPrinter printer("graphs/printer.txt");
	for (int i = static_cast<int>(builder.nodesStack.size()) - 1; i >= 0; i--) {
		ITree* node = builder.nodesStack[i];
		node->Accept(&printer);
	}
	printer.close();
}

enum FLAGS {
	NONE = 0,

	TOKEN_LIST = 1,
	TREE_OUTPUT = 1 << 1,
	TEST = 1 << 2,

	ALL = TOKEN_LIST | TREE_OUTPUT | TEST
};

void typeCheckTree(ITree* tree) {
	CStackBuilder builder;
	builder.BuildStack(tree);

	CMalformedProgramChecker checker;
	CTypeChecker typeChecker;
	checker.BuildTable(tree, "temp_name");
	typeChecker.CheckTypes(tree, "temp_name");
	std::ofstream errorStream;
	errorStream.open(outFileName, std::ofstream::out);
	CErrorTable::Print(errorStream);
}

void processFile(std::string name, int flag) {
	if ((flag & TOKEN_LIST) == TOKEN_LIST) {
		LEX_DUMP = true;
		BISON_DUMP = true;
		lexDumpFile.open(("lex"), std::ofstream::out);
		bisonDumpFile.open("bison" + name, std::ofstream::out);
	}


	yyscan_t scanner;
	yylex_init(&scanner);


	FILE* str;
	fopen_s(&str, name.c_str(), "r");
	

	/*std::shared_ptr<ITree> resultTree;
	{
		ITree* temp = nullptr;
		yyset_in(str, scanner);
		yyparse(scanner, &temp);
		resultTree.reset(temp);
	}*/
	yylex_destroy(scanner);

	
	/*typeCheckTree(resultTree.get());

	if ((flag & TREE_OUTPUT) == TREE_OUTPUT) {
		printTree(resultTree.get());
	}
	if ((flag & TOKEN_LIST) == TOKEN_LIST) {
		lexDumpFile.close();
		bisonDumpFile.close();
	}*/
}


void parseArguments(int argc, char* argv[], int& flag, std::string& filePath) {
	
	assert(argc > 2);
	if (argc > 6) {
		return;
	}
	flag = NONE;
	std::string currArgument;
	
	for (int i = 1; i < argc - 1; ++i) {
		currArgument = argv[i];
		if (currArgument == "TOKEN_LIST") {
			flag ^= TOKEN_LIST;
			LEX_DUMP = true;
			continue;
		}
		if (currArgument == "TREE_OUTPUT") {
			flag ^= TREE_OUTPUT;
			continue;
		}
		if (currArgument == "TEST") {
			flag ^= TEST;
			continue;
		}
	}
	if (flag == NONE) {
		flag = TREE_OUTPUT;
	}
	filePath = argv[argc - 2];
	outFileName = argv[argc - 1];
}

int main(int argc, char* argv[]) {
	int flag;
	std::string filePath;

	//parseArguments(argc, argv, flag, filePath);
	CMainCompiler compiler;
	compiler.Process(argc, argv);
	//processFile(filePath, flag);
	return 0;
}

void dumpToken(std::string token) {
	if (LEX_DUMP) {
		lexDumpFile << token << ' ';
	}
}

void dumpBisonToken(std::string token) {
	if (BISON_DUMP) {
		bisonDumpFile << token << ' ';
	}
}

void syntaxError(const std::string& name, int line) {
	CErrorTable::AddError(name, line);
}