#pragma once
#include <exception>
#include <string>

class CUndefinedTypeException : public std::exception {
public:
	CUndefinedTypeException(const std::string& typeName);
	const std::string& GetTypeName();
private:
	const std::string& typeName;
};
