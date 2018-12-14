#pragma once
#include <Tree.h>
#include <vector>

class CId;
class CFunction;
class CVariable;

class CClassDeclaration : public ITree {
public:
	CClassDeclaration(CId* name, CId* extends, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CId> name;
	std::unique_ptr<CId> extend;

	const std::string& GetLabel() const override;
};

class CClassInternals : public ITree {
public:
	CClassInternals(CFunction* function, int _line);
	CClassInternals(CVariable* variable, int _line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CFunction> function;
	std::unique_ptr<CVariable> variable;

	const std::string& GetLabel() const override;
};

class CClassInternalsList : public ITree {
public:
	CClassInternalsList();
	void Add(CClassInternals* item);
	virtual void Accept(IVisitor* visitor) override;

	std::vector<std::shared_ptr<CClassInternals>> internals;

	const std::string& GetLabel() const override;
};

class CClass : public ITree {
public:
	CClass(CClassDeclaration* declaration, CClassInternalsList* internals, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CClassDeclaration> declaration;
	std::unique_ptr<CClassInternalsList> internals;

	const std::string& GetLabel() const override;
};

class CClassList : public ITree {
public:
	CClassList();
	void Add(CClass* item);
	virtual void Accept(IVisitor* visitor) override;

	std::vector<std::shared_ptr<CClass>> classes;

	const std::string& GetLabel() const override;
};