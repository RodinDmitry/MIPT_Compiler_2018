#include <Defines.h>
#include <fstream>

std::ofstream lexDumpFile;
bool LEX_DUMP = false;
std::ofstream bisonDumpFile;
bool BISON_DUMP = false;
Goal* result;


int main() {
	LEX_DUMP = true;
	BISON_DUMP = true;
	lexDumpFile.open("lex_dump.txt", std::ofstream::out);
	bisonDumpFile.open("bison_dump.txt", std::ofstream::out);
	FILE *stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	yyin = stdin;
	do {
		yyparse();
	} while (!feof(stdin));
	CPrettyPrinter printer("printer.txt");
	while (!printerSet.empty()) {
		ITree* node = printerStack.front();
		printerStack.pop_front();
		while (printerSet.find(node) == printerSet.end()) {
			node = printerStack.front();
			printerStack.pop_front();
		}
		node->Accept(&printer);
		printerSet.erase(node);
	}
	printer.close();
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