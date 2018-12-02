#pragma once
#include <Symbol.h>
#include <DataType.h>
#include <Type.h>

class CVariableInfo {
public:
	CVariableInfo(std::string& table,  CSymbol* _name, TDataType _type, CSymbol* _userType);
	const CSymbol* String() const;
	std::shared_ptr<CType> GetType() const;
private:
	const CSymbol* name;
	const TDataType type;
	const CSymbol* userType;
	std::shared_ptr<CType> dataType;
};