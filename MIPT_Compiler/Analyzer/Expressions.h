#pragma once
#include <Tree.h>

class CBinaryExpression : public IExpression
{
public:

	inline enum TOpeartor {
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



class IId;
class IArgumentList;
class CCallExpression : public IExpression
{
public:
	CCallExpression(IExpression* caller, IId* function, IArgumentList* list);

	virtual void Accept(IVisitor* visitor) override;

	IExpression* caller;
	IId* function;
	IArgumentList* list;
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
	CNewArrayExpression(IId* id, IExpression* expression);

	virtual void Accept(IVisitor* visitor) override;

	IId* id;
	IExpression* expression;
};

class CIdExpression : public IExpression
{	
public:
	CIdExpression(IId* id);

	virtual void Accept(IVisitor* visitor) override;

	IId* id;
};

class CThisExpression : public IExpression
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

