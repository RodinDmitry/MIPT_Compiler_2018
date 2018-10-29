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

void processFile(std::string name) {
	FILE *stream;
	freopen_s(&stream, name.c_str(), "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	printerSet.clear();
	printerStack.clear();
	yyin = stdin;
	do {
		yyparse();
	} while (!feof(stdin));
	printLastTree();
}


int main(char* argc[], int argv) {
	LEX_DUMP = true;
	BISON_DUMP = true;
	lexDumpFile.open("dumps/lex_dump.txt", std::ofstream::out);
	bisonDumpFile.open("dumps/bison_dump.txt", std::ofstream::out);
	processFile("../../Samples/Factorial.java");
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