#pragma once
#include <UndefinedTypeException.h>
#include <vector>

class CErrorTable {
public:
	static void AddError(const std::string& message, int line);
	static void AddError(CUndefinedTypeException* error, int line);
	static void Print(std::ostream& stream);
	static bool HasErrors();

	static const std::string UnknownVariable;
	static const std::string UnknownFunction;
	static const std::string UnknownClass;
	static const std::string DoubleDeclaration;
	static const std::string CyclicInheritance;
	static const std::string TypeCheckFailed;
	static const std::string ExpectedBoolean;
	static const std::string ExpectedInteger;
	static const std::string WrongIndex;
	static const std::string ReturnTypeMismatch;
	static const std::string InvalidPrint;
	static const std::string InvalidOperation;

private:
	CErrorTable() {}
	static void createIfNotNull();
	static std::shared_ptr<CErrorTable> instance;

	std::vector<std::string> errorMessages;
};