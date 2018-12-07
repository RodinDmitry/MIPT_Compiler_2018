#pragma once
#include <VariableInfo.h>
#include <VisabilityModifier.h>
#include <vector>
#include <string>
#include <Type.h>

class CNamespaceBlock;

class CFunctionInfo {
public:
	CFunctionInfo(std::string& table, const CSymbol* _name, const CSymbol* _userType,
		TDataType _returnType, TVisabilityModifierType _modifierType);
	void AddArgument(const CVariableInfo* argument);
	void AddLocal(const CVariableInfo* local);
	void AddArguments(std::vector<const CVariableInfo* >&& _arguments);
	const std::vector<const CVariableInfo* >& GetArguments () const;
	const std::vector<const CVariableInfo* >& GetLocals() const;
	const CVariableInfo* GetVariable(const CSymbol* name) const;
	const CSymbol* String() const;
	std::shared_ptr<CType> GetType() const;
	void SetParent(const CNamespaceBlock* parentBlock);
	const CNamespaceBlock* GetParent() const;
private:
	const CNamespaceBlock* parentBlock;
	const CSymbol* name;
	const CSymbol* userType;
	const TDataType returnType;
	const TVisabilityModifierType modifierType;
	std::vector<const CVariableInfo* > arguments;
	std::vector<const CVariableInfo* > locals;
	std::shared_ptr<CType> dataType;
};
