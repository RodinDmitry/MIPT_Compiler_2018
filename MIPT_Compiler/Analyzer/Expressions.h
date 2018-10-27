#pragma once
#include <Tree.h>

class CLValueExpression : public IExpression
{
public:
	virtual void Accept(IVisitor* visitor) override;
};

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

class CId;
class IArgumentList;
class CCallExpression : public CLValueExpression
{
public:
	CCallExpression(IExpression* caller, CId* function, IArgumentList* list);

	virtual void Accept(IVisitor* visitor) override;

	IExpression* caller;
	CId* function;
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
	CNewArrayExpression(CId* id, IExpression* expression);

	virtual void Accept(IVisitor* visitor) override;

	CId* id;
	IExpression* expression;
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
