#pragma once
#include <Tree.h>

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

class CClass : public ITree {
public:
	CClass(CClassDeclaration* declaration, CClassInternals* internals);
	virtual void Accept(IVisitor* visitor) override;

	CClassDeclaration* declaration;
	CClassInternals* internals;
};