#pragma once
#include <Tree.h>
#include <vector>

class IExpression : public ITree {
public:
	IExpression() = default;
	IExpression(int line);
	virtual void Accept(IVisitor* visitor) override;
};

class CExpressionList : public ITree {
public:
	CExpressionList();
	virtual void Accept(IVisitor* visitor) override;
	void Add(IExpression* expression);

	std::vector<std::shared_ptr<IExpression>> expressions;

	std::string GetLabel() const override;
};

class CLValueExpression : public IExpression
{
public:
	CLValueExpression() = default;
	CLValueExpression(int line);
	virtual void Accept(IVisitor* visitor) override;

	std::string GetLabel() const override;
};

class CBinaryExpression : public IExpression
{
public:

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

	CBinaryExpression(IExpression* left, IExpression* right, TOperator operation, int line);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> left;
	std::unique_ptr<IExpression> right;
	TOperator operation;

	std::string GetLabel() const override;
};

class CArrayExpression : public IExpression
{
public:
	CArrayExpression(IExpression* caller, IExpression* index, int line);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> caller;
	std::unique_ptr<IExpression> index;

	std::string GetLabel() const override;
};

class CId;
class CCallExpression : public IExpression
{
public:
	CCallExpression(IExpression* caller, CId* function, CExpressionList* list, int line);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> caller;
	std::unique_ptr<CId> function;
	std::unique_ptr<CExpressionList> list;

	std::string GetLabel() const override;
};

class CCallLengthExpression : public IExpression
{
public:
	CCallLengthExpression(IExpression* caller, int line);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> caller;

	std::string GetLabel() const override;
};


class IValue;
class CValueExpression : public IExpression
{
public:
	CValueExpression(IValue* value, int line);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IValue> value;

	std::string GetLabel() const override;
};

class CNewArrayExpression : public IExpression
{
public:
	CNewArrayExpression(IExpression* expression, int line);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> expression;

	std::string GetLabel() const override;
};

class CNewExpression : public IExpression
{
public:
	CNewExpression(CId* id, int line);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CId> id;

	std::string GetLabel() const override;
};

class CIdExpression : public CLValueExpression
{	
public:
	CIdExpression(CId* id, int line);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CId> id;

	std::string GetLabel() const override;
};

class CThisExpression : public CLValueExpression
{
public:
	CThisExpression();

	virtual void Accept(IVisitor* visitor) override;

	std::string GetLabel() const override;
};

class CNotExpression : public IExpression
{
public:
	CNotExpression(IExpression* expression, int line);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> expression;

	std::string GetLabel() const override;
};

class CBracketsExpression : public IExpression
{
public:
	CBracketsExpression(IExpression* expression, int line);

	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<IExpression> expression;

	std::string GetLabel() const override;
};

class CReturnExpression : public IExpression {
public:
	CReturnExpression(IExpression* expression, int line);
	virtual void Accept(IVisitor* visitior) override;

	std::unique_ptr<IExpression> expression;

	std::string GetLabel() const override;
};