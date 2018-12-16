#pragma once
#include <exception>
#include <string>

class CInvalidDefinitionException : public std::exception {
public:
	explicit CInvalidDefinitionException(const std::string& _idName);
	const std::string& GetIdName();
private:
	const std::string& idName;
};

inline const std::string& CInvalidDefinitionException::GetIdName() {
	return idName;
}

inline CInvalidDefinitionException::CInvalidDefinitionException(const std::string& _idName)
	: idName(_idName) {}
