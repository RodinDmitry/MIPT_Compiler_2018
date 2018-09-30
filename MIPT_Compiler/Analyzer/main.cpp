#include <iostream>

extern "C++" int yylex();

int main() {
	FILE *stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	yylex();
}