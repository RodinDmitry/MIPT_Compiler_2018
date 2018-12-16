#pragma once
#include <NamespaceBlock.h>
#include <VisabilityModifier.h>
#include <ClassInfo.h>
#include <vector>
#include <string>
#include <Type.h>


class CFunctionInfo : public CNamespaceBlock {
public:
	CFunctionInfo( const CSymbol* _name, const CType* _dataType, const CClassInfo* classInfo,
			TVisabilityModifierType _modifierType);
	
	void AddArgument(std::unique_ptr<const CVariableInfo> argument);
	void AddLocalVar(std::unique_ptr<const CVariableInfo> local);
	const std::vector<std::unique_ptr<const CVariableInfo> >& GetArguments() const;
	std::shared_ptr<const std::vector<const CVariableInfo* >> GetLocals() const;
	const CVariableInfo* GetVariable(const CSymbol* name) const;
	const CVariableInfo* FindVariable(const CSymbol* name);
	const CSymbol* String() const;
	const CType* GetType() const;

	void EnterBlock();
	void LeaveBlock();
private:
	const CSymbol* name;
	const CClassInfo* classInfo;

	CNamespaceBlock* currentBlock = nullptr;

	const TVisabilityModifierType modifierType;
	std::vector<std::unique_ptr<const CVariableInfo> > arguments;
	std::vector<std::pair<const CVariableInfo*, const CNamespaceBlock*> > localsBlocks;
	const CType* dataType;

	std::vector<std::unique_ptr<CNamespaceBlock> > blocks;

	CNamespaceBlock* GetCurrentBlock();
};
