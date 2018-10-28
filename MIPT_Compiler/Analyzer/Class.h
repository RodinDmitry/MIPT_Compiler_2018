#pragma once
#include <Tree.h>
#include <vector>

class CId;
class CFunction;
class CVariable;

class CClassDeclaration : public ITree {
public:
	CClassDeclaration(CId* name, CId* extends);
	virtual void Accept(IVisitor* visitor) override;

	CId* name;
	CId* extend;
};

class CClassInternals : public ITree {
public:
	CClassInternals(CFunction* function);
	CClassInternals(CVariable* variable);
	virtual void Accept(IVisitor* visitor) override;

	CFunction* function;
	CVariable* variable;
};

class CClassInternalsList : public ITree {
public:
	
	void Add(CClassInternals* item);
	virtual void Accept(IVisitor* visitor) override;

	std::vector<CClassInternals*> internals;
};

class CClass : public ITree {
public:
	CClass(CClassDeclaration* declaration, CClassInternalsList* internals);
	virtual void Accept(IVisitor* visitor) override;

	CClassDeclaration* declaration;
	CClassInternalsList* internals;
};

class CClassList : public ITree {
public:

	void Add(CClass* item);
	virtual void Accept(IVisitor* visitor) override;

	std::vector<CClass*> classes;
};