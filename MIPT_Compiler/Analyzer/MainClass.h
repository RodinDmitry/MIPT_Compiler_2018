#pragma once

#include <Tree.h>
#include <Function.h>

class CMainArgument : public ITree {
public:
	
	CMainArgument(CId* name);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CId> name;

	std::string GetLabel() override;
};

class CMainFunction : public ITree {
public:

	CMainFunction(CMainArgument* argument, CStatementList* body);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CMainArgument> argument;
	std::unique_ptr<CStatementList> body;

	std::string GetLabel() override;
};

class CMain : public ITree {
public:

	CMain(CId* name, CMainFunction* mainFunction);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CId> name;
	std::unique_ptr<CMainFunction> mainFunction;

	std::string GetLabel() override;
};