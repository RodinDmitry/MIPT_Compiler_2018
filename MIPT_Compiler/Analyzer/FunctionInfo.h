#pragma once
#include <VariableInfo.h>
#include <VisabilityModifier.h>
#include <vector>

class CFunctionInfo {
public:
	CFunctionInfo(const CSymbol* _name, const CSymbol* _userType, TDataType _returnType, TVisabilityModifierType _modifierType);
	void AddArgument(const CVariableInfo* argument);
	void AddArguments(std::vector<const CVariableInfo* >&& _arguments);
	const std::vector<const CVariableInfo* >& GetArguments() const;
	const CSymbol* String() const;
private:
	const CSymbol* name;
	const CSymbol* userType;
	const TDataType returnType;
	const TVisabilityModifierType modifierType;
	std::vector<const CVariableInfo* > arguments;
};
