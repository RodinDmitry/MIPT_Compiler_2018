#include <iostream>
#include <Defines.h>

int main() {
	FILE *stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	yyin = stdin;
	do {
		yyparse();
	} while (!feof(yyin));

}

void yyerror(const char* s) {
	std::cout << "пиздень \n";
	std::cout << s << std::endl;
};