#include "VariableInfo.h"
#include <SymbolTable.h>
#include <UndefinedTypeException.h>

CVariableInfo::CVariableInfo(const CSymbol * _name, TDataType _type, CSymbol * _userType)
	: name(_name), type(_type), userType(_userType)
{
	if (type == TDataType::DT_Instance) {
		if (CSymbolTable::FindClassInCurrent(userType)) {
			throw new CUndefinedTypeException(userType->String());
		}
	}
}

const CSymbol * CVariableInfo::String() const
{
	return name;
}
