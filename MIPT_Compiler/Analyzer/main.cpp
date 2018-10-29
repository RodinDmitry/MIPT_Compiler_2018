#include <Defines.h>
#include <iostream>

std::ofstream lexDumpFile;
bool LEX_DUMP = false;
std::ofstream bisonDumpFile;
bool BISON_DUMP = false;

void printLastTree() {
	CPrettyPrinter printer("graphs/printer.txt");
	while (!printerSet.empty()) {
		ITree* node = printerStack.back();
		printerStack.pop_back();
		while (printerSet.find(node) == printerSet.end()) {
			node = printerStack.back();
			printerStack.pop_back();
		}
		node->Accept(&printer);
		printerSet.erase(node);
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
	if (flag ^ TOKEN_LIST == flag) {
		LEX_DUMP = true;
		BISON_DUMP = true;
	}


	FILE *stream;
	freopen_s(&stream, name.c_str(), "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	printerSet.clear();
	printerStack.clear();
	yyin = stdin;
	do {
		yyparse();
	} while (!feof(stdin));

	if (flag ^ TREE_OUTPUT == flag) {
		printLastTree();
	}
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
	//processFile("../../Samples/TreeVisitor.java");
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

void yyerror(const char* s) {
	std::cout << "error \n";
	std::cout << s << std::endl;
};