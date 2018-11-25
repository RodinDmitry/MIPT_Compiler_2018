#pragma once
#include <Symbol.h>
#include <DataType.h>

class CVariableInfo : public CSymbol {
public:
	CVariableInfo(const std::string& _name, TDataType _type, CSymbol* _userType);

	static CVariableInfo* GetSymbol(const std::string& src, TDataType _type, CSymbol* _userType);
private:
	const TDataType type;
	const CSymbol* userType = nullptr;
};