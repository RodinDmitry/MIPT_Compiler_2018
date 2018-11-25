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

	std::unique_ptr<CId> name;
	std::unique_ptr<CId> extend;

	std::string GetLabel() override;
};

class CClassInternals : public ITree {
public:
	CClassInternals(CFunction* function);
	CClassInternals(CVariable* variable);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CFunction> function;
	std::unique_ptr<CVariable> variable;

	std::string GetLabel() override;
};

class CClassInternalsList : public ITree {
public:
	
	void Add(CClassInternals* item);
	virtual void Accept(IVisitor* visitor) override;

	std::vector<std::shared_ptr<CClassInternals>> internals;

	std::string GetLabel() override;
};

class CClass : public ITree {
public:
	CClass(CClassDeclaration* declaration, CClassInternalsList* internals);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CClassDeclaration> declaration;
	std::unique_ptr<CClassInternalsList> internals;

	std::string GetLabel() override;
};

class CClassList : public ITree {
public:

	void Add(CClass* item);
	virtual void Accept(IVisitor* visitor) override;

	std::vector<std::shared_ptr<CClass>> classes;

	std::string GetLabel() override;
};