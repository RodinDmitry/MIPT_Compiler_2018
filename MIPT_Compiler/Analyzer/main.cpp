#include <Defines.h>
#include <iostream>

std::ofstream lexDumpFile;
bool LEX_DUMP = false;
std::ofstream bisonDumpFile;
bool BISON_DUMP = false;

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

void processFile(std::string name, int flag) {
	if ((flag ^ TOKEN_LIST) == flag) {
		LEX_DUMP = true;
		BISON_DUMP = true;
	}


	FILE *stream;
	fopen_s( &yyin, name.c_str(), "r");

	std::shared_ptr<ITree> resultTree;
	{
		ITree* temp = nullptr;
		yyparse(&temp);
		resultTree.reset(temp);
	}

	if ((flag & TREE_OUTPUT) == TREE_OUTPUT) {
		printTree(resultTree.get());
	}
	system("pause");
}


void parseArguments(int argc, char* argv[], int& flag, std::string& filePath) {
	if (argc > 5) {
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
	filePath = argv[argc - 1];
}

int main(int argc, char* argv[]) {
	lexDumpFile.open("dumps/lex_dump.txt", std::ofstream::out);
	bisonDumpFile.open("dumps/bison_dump.txt", std::ofstream::out);

	int flag;
	std::string filePath;

	parseArguments(argc, argv, flag, filePath);

	processFile(filePath, flag);
}

void dumpToken(std::string token) {
	if (LEX_DUMP) {
		lexDumpFile << token << ' ';
	}
}

void dumpBisonToken(std::string token) {
	if (true) {
		bisonDumpFile << token << ' ';
	}
}

void syntaxError(const std::string& name, int line) {
	std::cerr << name << " in line: " << line << std::endl;
}