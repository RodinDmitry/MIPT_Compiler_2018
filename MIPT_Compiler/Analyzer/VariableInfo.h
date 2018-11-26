#pragma once
#include <Symbol.h>
#include <DataType.h>

class CVariableInfo {
public:
	CVariableInfo(const CSymbol* _name, TDataType _type, CSymbol* _userType);
	const CSymbol* String() const;
private:
	const CSymbol* name;
	const TDataType type;
	const CSymbol* userType;
};