#pragma once

#include <IR/IRTree.h>
#include <IR/Label.h>
#include <IR/Temporary.h>
#include <vector>

namespace IR {

class IExpression : public ITree {
public:
	virtual void Accept(IIRVisitor* visitor) override;
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
	virtual void Accept(IIRVisitor* visitor) override;
	void Add(IExpression* expression) { Add(std::shared_ptr<IExpression>(expression)); };
	void Add(std::shared_ptr<IExpression> expression) { expressions.push_back(expression); }

	const std::vector<std::shared_ptr<IExpression>> Get() const { return expressions; }

private:
	std::vector<std::shared_ptr<IExpression>> expressions;
};

class CConstExpression : public IExpression {
public:
	virtual ~CConstExpression() = default;
	CConstExpression(int _value) : value(_value) {}
	
	int Get() { return value; }

private:
	int value;
};

class CNameExpression : public IExpression {
public:
	virtual ~CNameExpression() = default;
	CNameExpression(const CLabel& label) : name(label) {}

	virtual void Accept(IIRVisitor* visitor) override;
	const CLabel& Get() const { return name; }

private:
	CLabel name;
};

class CTempExpression : public IExpression {
public:
	CTempExpression(const CTemp& _temp) : temp(_temp) {}
	~CTempExpression() = default;

	const CTemp& Temporary() const { return temp; }
	virtual void Accept(IIRVisitor* visitor) override;
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

	virtual void Accept(IIRVisitor* visitor) override;

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
	CMemExpression(const IExpression* _address) : address(_address) {}
	CMemExpression(std::shared_ptr<const IExpression> _address) : address(_address) {}
	virtual ~CMemExpression() = default;

	virtual void Accept(IIRVisitor* visitor) override;

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
	virtual void Accept(IIRVisitor* visitor) override;

	const IExpression* Function() const { return function.get(); }
	const CExpressionList* Arguments() const { return arguments.get(); }

private:
	std::shared_ptr<const IExpression> function;
	std::shared_ptr<const CExpressionList> arguments;
};

class CStatement;

class CEseqExpression : public IExpression {
public:
	CEseqExpression(const CStatement* _statement, const IExpression* _expression) : 
		statement(_statement), expression(_expression) {}
	CEseqExpression(std::shared_ptr<const CStatement> _statement, std::shared_ptr<const IExpression> _expression) : 
		statement(_statement), expression(_expression) {}
	virtual ~CEseqExpression() = default;

	virtual void Accept(IIRVisitor* visitor) override;
	const CStatement* Statement() const { return statement.get(); }
	const IExpression* Expression() const { return expression.get(); }

private:
	std::shared_ptr<const CStatement> statement;
	std::shared_ptr<const IExpression> expression;
};

} // namespace IR