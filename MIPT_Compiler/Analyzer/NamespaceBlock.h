#pragma once
#include <ClassInfo.h>

class CNamespaceBlock {
public:
	CNamespaceBlock();
	explicit CNamespaceBlock(const CNamespaceBlock* _parent);

	const CNamespaceBlock* GetParent() const;

	virtual void AddClass(CClassInfo* classDecl);
	virtual void AddMember(const CVariableInfo* variable);
	virtual void AddMethod(const CFunctionInfo* method);

	virtual void AddArgument(const CVariableInfo* argument);

	virtual const CClassInfo* GetThis() const;

	virtual const CClassInfo* FindClass(const CSymbol* id) const;
	virtual const CFunctionInfo* FindMethod(const CSymbol* id) const;
	virtual const CVariableInfo* FindMember(const CSymbol* id) const;

protected:
	const CNamespaceBlock* parent;
	std::vector<std::unique_ptr<const CVariableInfo> > members;
	std::vector<std::unique_ptr<const CFunctionInfo> > methods;
	std::vector<std::unique_ptr<const CClassInfo> > classes;
};

class CFunctionNamespaceBlock : public CNamespaceBlock {
public:
	CFunctionNamespaceBlock(const CNamespaceBlock* _parent, CFunctionInfo* function);

	void AddMember(const CVariableInfo* variable);
	void AddArgument(const CVariableInfo* argument);

private:
	CFunctionInfo* funcToUpdate;
};

class CClassNamespaceBlock : public CNamespaceBlock {
public:
	CClassNamespaceBlock(const CNamespaceBlock* _parent, CClassInfo* classToUpdate);

	void AddMember(const CVariableInfo* member);
	void AddMethod(const CFunctionInfo* method);

	const CClassInfo* GetThis() const;
private:
	CClassInfo* classToUpdate;
};