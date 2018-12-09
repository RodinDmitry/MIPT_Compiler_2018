#include <ErrorTable.h>
#include <fstream>

std::shared_ptr<CErrorTable> CErrorTable::instance(nullptr);
const std::string CErrorTable::UnknownVariable = "Unknown Variable : ";
const std::string CErrorTable::UnknownFunction = "Unknown Function : ";
const std::string CErrorTable::UnknownClass = "Unknown Class : ";
const std::string CErrorTable::DoubleDeclaration = "Declaration already found ";
const std::string CErrorTable::CyclicInheritance = "Is inherited from itself ";
const std::string CErrorTable::TypeCheckFailed = "Type check failed ";
const std::string CErrorTable::ExpectedBoolean = "Exprected boolean ";
const std::string CErrorTable::ExpectedInteger = "Expected Integer ";
const std::string CErrorTable::WrongIndex = "Array index must be integer ";
const std::string CErrorTable::ReturnTypeMismatch = "Return type mismatch ";
const std::string CErrorTable::InvalidPrint = "Unprintable type";
const std::string CErrorTable::InvalidOperation = "Invalide binary operation";

void CErrorTable::AddError(const std::string& message, int line)
{
	createIfNotNull();
	instance->errorMessages.push_back(message + " | at line " + std::to_string(line));
}

void CErrorTable::AddError(CUndefinedTypeException* error, int line)
{
	createIfNotNull();
	instance->errorMessages.push_back(std::string("Unknown type " + error->GetTypeName()) + "| line " + std::to_string(line));
}

void CErrorTable::Print(std::ofstream& stream)
{
	createIfNotNull();
	for (int i = 0; i < instance->errorMessages.size(); i++) {
		stream << instance->errorMessages[i] << std::endl;
	}
}

void CErrorTable::createIfNotNull()
{
	if (instance == nullptr) {
		instance.reset(new CErrorTable());
	}
}

