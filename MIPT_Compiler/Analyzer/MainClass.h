#pragma once

#include <Tree.h>
#include <Function.h>

class CMainArgument : public ITree {
public:
	
	CMainArgument(CId* name, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CId> name;

	std::string GetLabel() const override;
};

class CMainFunction : public ITree {
public:

	CMainFunction(CMainArgument* argument, CStatementList* body, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CMainArgument> argument;
	std::unique_ptr<CStatementList> body;

	std::string GetLabel() const override;
};

class CMain : public ITree {
public:

	CMain(CId* name, CMainFunction* mainFunction, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CId> name;
	std::unique_ptr<CMainFunction> mainFunction;

	std::string GetLabel() const override;
};