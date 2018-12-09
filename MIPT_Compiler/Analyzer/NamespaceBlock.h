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
	virtual void AddArgument(std::unique_ptr<const CVariableInfo>&& argument);

	virtual void AddMember(std::unique_ptr<const CVariableInfo>&& member);
	virtual void AddMethod(std::unique_ptr<const CFunctionInfo>&& method);
	virtual void AddClass(std::unique_ptr<const CClassInfo>&& classDecl);

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

	void AddMember(std::unique_ptr<const CVariableInfo>&& member);
	void AddArgument(std::unique_ptr<const CVariableInfo>&& method);

private:
	CFunctionInfo* funcToUpdate;
};

class CClassNamespaceBlock : public CNamespaceBlock {
public:
	CClassNamespaceBlock(const CNamespaceBlock* _parent, CClassInfo* classToUpdate);

	void AddMember(const CVariableInfo* member);
	void AddMethod(const CFunctionInfo* method);

	void AddMember(std::unique_ptr<const CVariableInfo>&& member);
	void AddMethod(std::unique_ptr<const CFunctionInfo>&& method);

	const CClassInfo* GetThis() const;
private:
	CClassInfo* classToUpdate;
};