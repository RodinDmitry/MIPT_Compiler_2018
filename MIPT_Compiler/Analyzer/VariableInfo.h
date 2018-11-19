#pragma once
#include <Symbol.h>
#include <DataType.h>

class CVariableInfo : public CSymbol {
public:
	CVariableInfo(TDataType _type, CSymbol* _userType);

	static CVariableInfo* GetSymbol(const std::string& src);
private:
	TDataType type;
	const std::unique_ptr<CSymbol*> userType = nullptr;
};