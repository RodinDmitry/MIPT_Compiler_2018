#pragma once

#include <Tree.h>
#include <Expressions.h>
#include <vector>

class IStatement : public ITree
{
public:
	virtual void Accept(IVisitor* visitor) override;
};

class CStatementList : public ITree
{
public:
	virtual void Accept(IVisitor* visitor) override;
	void AddStatement(IStatement* statement);

	std::vector<IStatement*> statements;
};

class CVisibilityStatement : public IStatement {
public:
	CVisibilityStatement(IStatement* statement);
	virtual void Accept(IVisitor* visitor) override;

	IStatement* statement;
};

class CIfStatement : public IStatement {
public:
	CIfStatement(IExpression* condition, IStatement* thenStatement, IStatement* elseStatement);
	virtual void Accept(IVisitor* visitor) override;

	IExpression* condition;
	IStatement* thenStatement;
	IStatement* elseStatement;
};

class CWhileStatement : public IStatement {
public:
	CWhileStatement(IExpression* condition, IStatement* statement);
	virtual void Accept(IVisitor* visitor) override;

	IExpression* condition;
	IStatement* statement;
};

class CPrintStatement : public IStatement {
public:
	CPrintStatement(IExpression* expression);
	virtual void Accept(IVisitor* visitor) override;

	IExpression* expression;
};

class CEqualStatement : public IStatement {
public:
	CEqualStatement(CLValueExpression* left, IExpression* right);
	virtual void Accept(IVisitor* visitor) override;

	CLValueExpression* left;
	IExpression* right;
};


class CVariable;
class CVariableStatement : public IStatement {
public:
	CVariableStatement(CVariable* variable);
	virtual void Accept(IVisitor* visitor) override;

	CVariable* variable;
	 
};