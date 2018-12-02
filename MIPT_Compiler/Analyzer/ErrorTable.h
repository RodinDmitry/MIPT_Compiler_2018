#pragma once
#include <string>
#include <UndefinedTypeException.h>
#include <vector>
#include <string>

class CErrorTable {
public:
	static void AddError(std::string message);
	static void AddError(CUndefinedTypeException* error);
	static void Print(std::fstream& stream);

private:
	CErrorTable() {}
	static void createIfNotNull();
	static std::shared_ptr<CErrorTable> instance;

	std::vector<std::string> errorMessages;
};