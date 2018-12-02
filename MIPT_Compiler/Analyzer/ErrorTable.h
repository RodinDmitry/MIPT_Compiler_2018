#pragma once
#include <string>
#include <UndefinedTypeException.h>

class CErrorTable {
public:
	static void AddError(std::string message);
	static void AddError(CUndefinedTypeException* error);

};