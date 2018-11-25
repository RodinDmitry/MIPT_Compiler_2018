#include "VariableInfo.h"
#include <SymbolTable.h>
#include <UndefinedTypeException.h>

CVariableInfo::CVariableInfo(const std::string & _name, TDataType _type, CSymbol * _userType)
	: CSymbol(_name), type(_type), userType(_userType)
{
	if (type == TDataType::DT_Instance) {
		if (CSymbolTable::FindClassInCurrent(userType)) {
			throw new CUndefinedTypeException(userType->String());
		}
	}
}

CVariableInfo * CVariableInfo::GetSymbol(const std::string & src, TDataType type, CSymbol* userType)
{
	CVariableInfo* symb = static_cast<CVariableInfo*>(GetSymbolOrNull(src));
	if (symb == nullptr) {
		symb = new CVariableInfo(src, type, userType);
	}
	return symb;
}
