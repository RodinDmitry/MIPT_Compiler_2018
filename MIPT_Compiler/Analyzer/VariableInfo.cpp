#include <VariableInfo.h>
#include <SymbolTable.h>
#include <UndefinedTypeException.h>

CVariableInfo::CVariableInfo(std::string& table, CSymbol* _name, TDataType _type, CSymbol* _userType)
	: name(_name), type(_type), userType(_userType)
{
	if (type == DT_Instance) {
		dataType.reset(new CType(userType->String().c_str()));
	}
	else {
		dataType.reset(new CType(type));
	}
}

const CSymbol* CVariableInfo::String() const
{
	return name;
}

std::shared_ptr<CType> CVariableInfo::GetType() const
{
	return dataType;
}
