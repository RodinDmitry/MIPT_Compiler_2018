#pragma once

#include <Tree.h>
#include <Expressions.h>
#include <vector>

class IStatement : public ITree
{
public:
	IStatement(int line);
	virtual void Accept(IVisitor* visitor) override;
};

class CStatementList : public ITree
{
public:
	CStatementList();
	virtual void Accept(IVisitor* visitor) override;
	void Add(IStatement* statement);

	std::vector<std::shared_ptr<IStatement>> statements;

	std::string GetLabel() const override;
};

class CVisibilityStatement : public IStatement {
public:
	CVisibilityStatement(IStatement* statement, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IStatement> statement;

	std::string GetLabel() const override;
};

class CIfStatement : public IStatement {
public:
	CIfStatement(IExpression* condition, IStatement* thenStatement, IStatement* elseStatement, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> condition;
	std::unique_ptr<IStatement> thenStatement;
	std::unique_ptr<IStatement> elseStatement;

	std::string GetLabel() const override;
};

class CWhileStatement : public IStatement {
public:
	CWhileStatement(IExpression* condition, IStatement* statement, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> condition;
	std::unique_ptr<IStatement> statement;

	std::string GetLabel() const override;
};

class CPrintStatement : public IStatement {
public:
	CPrintStatement(IExpression* expression, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> expression;

	std::string GetLabel() const override;
};

class CAssignStatement : public IStatement {
public:
	CAssignStatement(CLValueExpression* left, IExpression* right, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CLValueExpression> left;
	std::unique_ptr<IExpression> right;

	std::string GetLabel() const override;
};


class CVariable;
class CVariableStatement : public IStatement {
public:
	CVariableStatement(CVariable* variable, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CVariable> variable;
	
	std::string GetLabel() const override;
};