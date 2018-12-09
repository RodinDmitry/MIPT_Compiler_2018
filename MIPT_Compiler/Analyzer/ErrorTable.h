#pragma once
#include <UndefinedTypeException.h>
#include <vector>

class CErrorTable {
public:
	static void AddError(std::string message);
	static void AddError(CUndefinedTypeException* error);
	static void Print(std::ofstream& stream);

private:
	CErrorTable() {}
	static void createIfNotNull();
	static std::shared_ptr<CErrorTable> instance;

	std::vector<std::string> errorMessages;
};