#include <Defines.h>
#include <fstream>

std::ofstream lexDumpFile;
bool LEX_DUMP = false;
std::ofstream bisonDumpFile;
bool BISON_DUMP = false;

int main() {
	LEX_DUMP = true;
	BISON_DUMP = true;
	lexDumpFile.open("lex_dump.txt", std::ofstream::out);
	bisonDumpFile.open("bison_dump.txt", std::ofstream::out);
	FILE *stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	//yyin = stdin;
	//yyparse();
	do {
		yyparse();
		//yylex();
	} while (!feof(stdin));
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