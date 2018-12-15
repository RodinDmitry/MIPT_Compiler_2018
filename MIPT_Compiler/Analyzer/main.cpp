#include <Defines.h>
#include <iostream>
#include <MainCompiler.h>

int main(int argc, char* argv[]) {
	CMainCompiler compiler;
	compiler.Process(argc, argv);
	return 0;
}
