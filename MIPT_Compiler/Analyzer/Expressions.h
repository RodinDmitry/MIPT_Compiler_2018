#pragma once
#include <Tree.h>
#include <vector>

class CExpressionList : public ITree {
public:
	virtual void Accept(IVisitor* visitor) override;
	void Add(IExpression* expression);

	std::vector<IExpression*> expressions;
};

class CLValueExpression : public IExpression
{
public:
	virtual void Accept(IVisitor* visitor) override;
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

	IExpression* left = nullptr;
	IExpression* right = nullptr;
	TOpeartor operation;

};

class CArrayExpression : public IExpression
{
public:
	CArrayExpression(IExpression* caller, IExpression* index);

	virtual void Accept(IVisitor* visitor) override;

	IExpression* caller;
	IExpression* index;
};

class CId;
class CArgumentList;
class CCallExpression : public CLValueExpression
{
public:
	CCallExpression(CId* caller, CId* function, CArgumentList* list);

	virtual void Accept(IVisitor* visitor) override;

	CId* caller;
	CId* function;
	CArgumentList* list;
};

class CCallLengthExpression : public IExpression
{
public:
	CCallLengthExpression(IExpression* caller);

	virtual void Accept(IVisitor* visitor) override;

	IExpression* caller;
};


class IValue;
class CValueExpression : public IExpression
{
public:
	CValueExpression(IValue* value);

	virtual void Accept(IVisitor* visitor) override;

	IValue* value;
};

class CNewArrayExpression : public IExpression
{
public:
	CNewArrayExpression(IExpression* expression);

	virtual void Accept(IVisitor* visitor) override;

	IExpression* expression;
};

class CNewExpression : public IExpression
{
public:
	CNewExpression(CId* id);

	virtual void Accept(IVisitor* visitor) override;

	CId* id;
};

class CIdExpression : public CLValueExpression
{	
public:
	CIdExpression(CId* id);

	virtual void Accept(IVisitor* visitor) override;

	CId* id;
};

class CThisExpression : public CLValueExpression
{
public:
	CThisExpression();

	virtual void Accept(IVisitor* visitor) override;
};

class CNotExpression : public IExpression
{
public:
	CNotExpression(IExpression* expression);

	virtual void Accept(IVisitor* visitor) override;

	IExpression* expression;
};

class CBracketsExpression : public IExpression
{
public:
	CBracketsExpression(IExpression* expression);

	virtual void Accept(IVisitor* visitor) override;

	IExpression* expression;
};

class CReturnExpression : public IExpression {
public:
	CReturnExpression(IExpression* expression);
	virtual void Accept(IVisitor* visitior) override;

	IExpression* expression;
};