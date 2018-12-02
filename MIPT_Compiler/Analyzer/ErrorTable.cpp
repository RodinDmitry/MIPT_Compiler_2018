#include <ErrorTable.h>
#include <fstream>

std::shared_ptr<CErrorTable> CErrorTable::instance(nullptr);

void CErrorTable::AddError(std::string message)
{
	createIfNotNull();
	instance->errorMessages.push_back(message);
}

void CErrorTable::AddError(CUndefinedTypeException* error)
{
	createIfNotNull();
	instance->errorMessages.push_back(std::string("Unknown type ") + error->GetTypeName());
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

