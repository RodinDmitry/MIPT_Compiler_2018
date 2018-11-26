#pragma once
#include <ClassInfo.h>

class NamespaceBlock {
public:
	NamespaceBlock();
	explicit NamespaceBlock(const NamespaceBlock* _parent);

	const NamespaceBlock* GetParent() const;

	virtual void AddClass(const CClassInfo* classDecl);
	virtual void AddMember(const CVariableInfo* variable);
	virtual void AddMethod(const CFunctionInfo* method);

	virtual const CClassInfo* FindClass(const CSymbol* id) const;
	virtual const CFunctionInfo* FindMethod(const CSymbol* id) const;
	virtual const CVariableInfo* FindMember(const CSymbol* id) const;

protected:
	const NamespaceBlock* parent;
	std::vector<std::unique_ptr<CVariableInfo> > members;
	std::vector<std::unique_ptr<CFunctionInfo> > methods;
	std::vector<std::unique_ptr<CClassInfo> > classes;
};

class FunctionNamespaceBlock : public NamespaceBlock {
public:
	FunctionNamespaceBlock(const NamespaceBlock* _parent, const CFunctionInfo* function);

	void AddMember(const CVariableInfo* variable);
};

class ClassNamespaceBlock : public NamespaceBlock {
public:
	ClassNamespaceBlock(const NamespaceBlock* _parent, CClassInfo* classToUpdate);

	void AddMember(const CVariableInfo* member);
	void AddMethod(const CFunctionInfo* method);
private:
	CClassInfo* classToUpdate;
};