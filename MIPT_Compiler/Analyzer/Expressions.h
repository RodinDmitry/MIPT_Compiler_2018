#pragma once
#include <Tree.h>
#include <vector>

class IExpression : public ITree {
public:
	virtual void Accept(IVisitor* visitor) override;
};

class CExpressionList : public ITree {
public:
	virtual void Accept(IVisitor* visitor) override;
	void Add(IExpression* expression);

	std::vector<std::shared_ptr<IExpression>> expressions;

	std::string GetLabel() override;
};

class CLValueExpression : public IExpression
{
public:
	virtual void Accept(IVisitor* visitor) override;

	std::string GetLabel() override;
};

class CBinaryExpression : public IExpression
{
public:

	enum TOpeartor {
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

	CBinaryExpression(IExpression* left, IExpression* right, TOpeartor operation);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> left;
	std::unique_ptr<IExpression> right;
	TOpeartor operation;

	std::string GetLabel() override;
};

class CArrayExpression : public IExpression
{
public:
	CArrayExpression(IExpression* caller, IExpression* index);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> caller;
	std::unique_ptr<IExpression> index;

	std::string GetLabel() override;
};

class CId;
class CCallExpression : public CLValueExpression
{
public:
	CCallExpression(IExpression* caller, CId* function, CExpressionList* list);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> caller;
	std::unique_ptr<CId> function;
	std::unique_ptr<CExpressionList> list;

	std::string GetLabel() override;
};

class CCallLengthExpression : public IExpression
{
public:
	CCallLengthExpression(IExpression* caller);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> caller;

	std::string GetLabel() override;
};


class IValue;
class CValueExpression : public IExpression
{
public:
	CValueExpression(IValue* value);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IValue> value;

	std::string GetLabel() override;
};

class CNewArrayExpression : public IExpression
{
public:
	CNewArrayExpression(IExpression* expression);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> expression;

	std::string GetLabel() override;
};

class CNewExpression : public IExpression
{
public:
	CNewExpression(CId* id);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CId> id;

	std::string GetLabel() override;
};

class CIdExpression : public CLValueExpression
{	
public:
	CIdExpression(CId* id);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CId> id;

	std::string GetLabel() override;
};

class CThisExpression : public CLValueExpression
{
public:
	CThisExpression();

	virtual void Accept(IVisitor* visitor) override;

	std::string GetLabel() override;
};

class CNotExpression : public IExpression
{
public:
	CNotExpression(IExpression* expression);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> expression;

	std::string GetLabel() override;
};

class CBracketsExpression : public IExpression
{
public:
	CBracketsExpression(IExpression* expression);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> expression;

	std::string GetLabel() override;
};

class CReturnExpression : public IExpression {
public:
	CReturnExpression(IExpression* expression);
	virtual void Accept(IVisitor* visitior) override;

	std::unique_ptr<IExpression> expression;

	std::string GetLabel() override;
};