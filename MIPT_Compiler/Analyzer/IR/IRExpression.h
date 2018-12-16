#pragma once

#include <IR/IRTree.h>
#include <IR/Label.h>
#include <IR/Temporary.h>
#include <IR/IRStatement.h>
#include <vector>

namespace IR {

class IExpression : public ITree {
public:
	virtual void Accept(IIRVisitor* visitor) const override;
	virtual ~IExpression() = default;
};

enum TOperator {
	O_Plus,
	O_Minus,
	O_Division,
	O_IntegerDivision,
	O_And,
	O_Or,
	O_Multiplication,
	O_Less,
	O_More
};

class CExpressionList : public IExpression {
public:
	virtual ~CExpressionList() = default;
	CExpressionList() = default;
	virtual void Accept(IIRVisitor* visitor) const override;
	explicit CExpressionList(const IExpression* expression) { Add(expression); }
	explicit CExpressionList(std::shared_ptr<const IExpression> expression) { Add(expression); }
	void Add(const IExpression* expression) { Add(std::shared_ptr<const IExpression>(expression)); };
	void Add(std::shared_ptr<const IExpression> expression) { expressions.push_back(expression); }

	const std::vector<std::shared_ptr<const IExpression>>& Get() const { return expressions; }

private:
	std::vector<std::shared_ptr<const IExpression>> expressions;
};

class CConstExpression : public IExpression {
public:
	virtual ~CConstExpression() = default;
	explicit CConstExpression(int _value) : value(_value) {}
	
	int Get() const { return value; }

private:
	int value;
};

class CNameExpression : public IExpression {
public:
	virtual ~CNameExpression() = default;
	explicit CNameExpression(const CLabel& label) : name(label) {}

	virtual void Accept(IIRVisitor* visitor) const override;
	const CLabel& Get() const { return name; }

private:
	CLabel name;
};

class CTempExpression : public IExpression {
public:
	explicit CTempExpression(const CTemp& _temp) : temp(_temp) {}
	virtual ~CTempExpression() = default;

	const CTemp& Temporary() const { return temp; }
	virtual void Accept(IIRVisitor* visitor) const override;
private:
	CTemp temp;
};

class CBinaryExpression : public IExpression {
public:
	CBinaryExpression(TOperator _operation, const IExpression* _left, const IExpression* _right) : operation(_operation), 
			left(_left), right(_right) {}
	CBinaryExpression(TOperator _operation, std::shared_ptr<const IExpression> _left, std::shared_ptr<const IExpression> _right) : 
		operation(_operation), left(_left), right(_right) {}
	virtual ~CBinaryExpression() = default;

	virtual void Accept(IIRVisitor* visitor) const override;

	TOperator Operation() const { return operation; }
	const IExpression* LeftOperand() const { return left.get(); }
	const IExpression* RightOperand() const { return right.get(); }

private:
	std::shared_ptr<const IExpression> left;
	std::shared_ptr<const IExpression> right;
	TOperator operation;
};

class CMemExpression : public IExpression {
public:
	explicit CMemExpression(const IExpression* _address) : address(_address) {}
	explicit CMemExpression(std::shared_ptr<const IExpression> _address) : address(_address) {}
	virtual ~CMemExpression() = default;

	virtual void Accept(IIRVisitor* visitor) const override;

	const IExpression* Get() const { return address.get(); }

private:
	std::shared_ptr<const IExpression> address;
};

class CCallExpression : public IExpression {
public:
	CCallExpression(const IExpression* _function, const CExpressionList* _arguments) : function(_function), arguments(_arguments) {}
	CCallExpression(std::shared_ptr<const IExpression> _function, std::shared_ptr<const CExpressionList> _arguments) :
		function(_function), arguments(_arguments) {}
	virtual ~CCallExpression() = default;
	virtual void Accept(IIRVisitor* visitor) const override;

	const IExpression* Function() const { return function.get(); }
	const CExpressionList* Arguments() const { return arguments.get(); }

private:
	std::shared_ptr<const IExpression> function;
	std::shared_ptr<const CExpressionList> arguments;
};

class IStatement;

class CEseqExpression : public IExpression {
public:
	CEseqExpression(const IStatement* _statement, const IExpression* _expression) : 
		statement(_statement), expression(_expression) {}
	CEseqExpression(std::shared_ptr<const IStatement> _statement, std::shared_ptr<const IExpression> _expression) : 
		statement(_statement), expression(_expression) {}
	virtual ~CEseqExpression() = default;

	virtual void Accept(IIRVisitor* visitor) const override;
	const IStatement* Statement() const { return statement.get(); }
	const IExpression* Expression() const { return expression.get(); }

private:
	std::shared_ptr<const IStatement> statement;
	std::shared_ptr<const IExpression> expression;
};

} // namespace IR