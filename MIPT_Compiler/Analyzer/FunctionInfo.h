#pragma once
#include <VariableInfo.h>
#include <VisabilityModifier.h>
#include <vector>

class CFunctionInfo : public CSymbol {
public:
	CFunctionInfo(const std::string& _name, const CSymbol* _userType, TDataType _returnType, TVisabilityModifierType _modifierType);
	void AddArgument(CVariableInfo* argument);
	void AddArguments(std::vector<std::unique_ptr<CVariableInfo> >&& _arguments);

	static CFunctionInfo* GetSymbol(const std::string & src, const CSymbol* _userType, TDataType _returnType, TVisabilityModifierType _modifierType);
private:
	const CSymbol* userType = nullptr;
	const TDataType returnType;
	const TVisabilityModifierType modifierType;
	std::vector<const CVariableInfo* > arguments;
};
