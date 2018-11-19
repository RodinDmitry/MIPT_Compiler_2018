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
	void Add(IStatement* statement);

	std::vector<std::unique_ptr<IStatement>> statements;

	std::string GetLabel() override;
};

class CVisibilityStatement : public IStatement {
public:
	CVisibilityStatement(IStatement* statement);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IStatement> statement;

	std::string GetLabel() override;
};

class CIfStatement : public IStatement {
public:
	CIfStatement(IExpression* condition, IStatement* thenStatement, IStatement* elseStatement);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> condition;
	std::unique_ptr<IStatement> thenStatement;
	std::unique_ptr<IStatement> elseStatement;

	std::string GetLabel() override;
};

class CWhileStatement : public IStatement {
public:
	CWhileStatement(IExpression* condition, IStatement* statement);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> condition;
	std::unique_ptr<IStatement> statement;

	std::string GetLabel() override;
};

class CPrintStatement : public IStatement {
public:
	CPrintStatement(IExpression* expression);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> expression;

	std::string GetLabel() override;
};

class CEqualStatement : public IStatement {
public:
	CEqualStatement(CLValueExpression* left, IExpression* right);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CLValueExpression> left;
	std::unique_ptr<IExpression> right;

	std::string GetLabel() override;
};


class CVariable;
class CVariableStatement : public IStatement {
public:
	CVariableStatement(CVariable* variable);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CVariable> variable;
	
	std::string GetLabel() override;
};