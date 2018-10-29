#pragma once

#include <Tree.h>
#include <Function.h>

class CMainArgument : public ITree {
public:
	
	CMainArgument(CId* name);
	virtual void Accept(IVisitor* visitor) override;

	CId* name;

	std::string GetLabel() override;
};

class CMainFunction : public ITree {
public:

	CMainFunction(CMainArgument* argument, CStatementList* body);
	virtual void Accept(IVisitor* visitor) override;

	CMainArgument* argument;
	CStatementList* body;

	std::string GetLabel() override;
};

class CMain : public ITree {
public:

	CMain(CId* name, CMainFunction* mainFunction);
	virtual void Accept(IVisitor* visitor) override;

	CId* name;
	CMainFunction* mainFunction;

	std::string GetLabel() override;
};