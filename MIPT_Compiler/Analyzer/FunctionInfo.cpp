#include "FunctionInfo.h"
#include <SymbolTable.h>
#include <UndefinedTypeException.h>

CFunctionInfo::CFunctionInfo(const std::string & _name, const CSymbol* _userType, TDataType _returnType, TVisabilityModifierType _modifierType)
	:CSymbol(_name), userType(_userType), returnType(_returnType), modifierType(_modifierType)
{
	if (returnType == TDataType::DT_Instance) {
		if (CSymbolTable::FindClassInCurrent(userType)) {
			throw new CUndefinedTypeException(userType->String());
		}
	}
}

void CFunctionInfo::AddArgument(CVariableInfo * argument)
{
}

void CFunctionInfo::AddArguments(std::vector<std::unique_ptr<CVariableInfo>>&& _arguments)
{
}

CFunctionInfo * CFunctionInfo::GetSymbol(const std::string & src, const CSymbol* _userType, TDataType _returnType, TVisabilityModifierType _modifierType)
{
	CFunctionInfo* symb = static_cast<CFunctionInfo*>(GetSymbolOrNull(src));
	if (symb == nullptr) {
		symb = new CFunctionInfo(src, _userType, _returnType, _modifierType);
	}
	return symb;
}
