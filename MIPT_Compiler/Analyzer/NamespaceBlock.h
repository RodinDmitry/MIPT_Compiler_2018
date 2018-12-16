#pragma once
#include <VariableInfo.h>

class CNamespaceBlock {
public:
	CNamespaceBlock();
	explicit CNamespaceBlock(CNamespaceBlock* _parent);

	CNamespaceBlock* GetParent();
	
	virtual void AddLocal(std::unique_ptr< const CVariableInfo> variable);
	virtual const CVariableInfo* FindLocal(const CSymbol* id) const;

protected:
	CNamespaceBlock* parent;
	std::vector<std::unique_ptr<const CVariableInfo> > locals;
};
