#include <Defines.h>
#include <iostream>
#include <MainCompiler.h>

int main(int argc, char* argv[]) {
	int flag;
	std::string filePath;

	CMainCompiler compiler;
	compiler.Process(argc, argv);
	return 0;
}
