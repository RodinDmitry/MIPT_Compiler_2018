#include "FunctionInfo.h"
#include <SymbolTable.h>
#include <UndefinedTypeException.h>

CFunctionInfo::CFunctionInfo(const CSymbol* _name, const CSymbol* _userType, TDataType _returnType, TVisabilityModifierType _modifierType)
	:name(_name), userType(_userType), returnType(_returnType), modifierType(_modifierType)
{
	if (returnType == TDataType::DT_Instance) {
		if (CSymbolTable::FindClassInCurrent(userType)) {
			throw new CUndefinedTypeException(userType->String());
		}
	}
}

void CFunctionInfo::AddArgument(const CVariableInfo* argument)
{
	arguments.push_back(argument);
}

void CFunctionInfo::AddArguments(std::vector<const CVariableInfo*>&& _arguments)
{
	arguments = _arguments;
}

const std::vector<const CVariableInfo*>& CFunctionInfo::GetArguments() const
{
	return arguments;
}

const CSymbol * CFunctionInfo::String() const
{
	return name;
}