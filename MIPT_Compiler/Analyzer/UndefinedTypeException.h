#pragma once
#include <exception>
#include <string>

class CUndefinedTypeException : public std::exception {
public:
	CUndefinedTypeException(const std::string& _typeName);
	const std::string& GetTypeName();
private:
	const std::string& typeName;
};

inline const std::string& CUndefinedTypeException::GetTypeName() {
	return typeName;
}

inline CUndefinedTypeException::CUndefinedTypeException(const std::string& _typeName)
	: typeName(_typeName) {}
