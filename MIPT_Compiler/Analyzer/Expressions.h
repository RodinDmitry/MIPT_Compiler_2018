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

	IExpression* caller;
	IExpression* index;
};



class IId;
class IArgumentList;
class CCallExpression : public IExpression
{
public:
	CCallExpression(IExpression* caller, IExpression* index, IArgumentList* list);

	IExpression* caller;
	IId* function;
	IArgumentList* list;
};

class CCallLenghtExpression : public IExpression
{
public:
	CCallLenghtExpression(IExpression* caller);

	IExpression* caller;
};


class IValue;
class CValueExpression : public IExpression
{
public:
	CValueExpression(IValue* value);
	IValue* value;
};

class CNewArrayExpression : public IExpression
{
public:
	CNewArrayExpression(IId id, IExpression* expression);

	IId* id;
	IExpression* expression;
};

class CIdExpression : public IExpression
{	
public:
	CIdExpression(IId* id);
	IId* id;
};

class CThisExpression : public IExpression
{
public:
	CThisExpression();
};

class CNotExpression : public IExpression
{
public:
	CNotExpression(IExpression* expression);

	IExpression* expression;
};

class CBracketsExpression : public IExpression
{
public:
	CBracketsExpression(IExpression* expression);

	IExpression* expression;
};

