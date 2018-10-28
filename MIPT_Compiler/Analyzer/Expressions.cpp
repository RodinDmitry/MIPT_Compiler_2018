#include <Expressions.h>
#include <Visitor.h>
#include <Argument.h>
#include <Id.h>

void CLValueExpression::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

CBinaryExpression::CBinaryExpression(IExpression* _left, IExpression* _right, TOpeartor _operation):
	left(_left), right(_right), operation(_operation)
{
}

void CBinaryExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

CArrayExpression::CArrayExpression(IExpression* _caller, IExpression* _index): caller(_caller), index(_index)
{
}

void CArrayExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

CCallExpression::CCallExpression(CId* _caller, CId* _function, CArgumentList* _list) : caller(_caller), function(_function), list(_list) {}

void CCallExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

CCallLengthExpression::CCallLengthExpression(IExpression* _caller) : caller(_caller) {}

void CCallLengthExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

CValueExpression::CValueExpression(IValue* _value) : value(_value) {}

void CValueExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

CNewArrayExpression::CNewArrayExpression(IExpression* _expression): expression(_expression) {}

void CNewArrayExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

CIdExpression::CIdExpression(CId* _id) : id(_id) {}

void CIdExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

CThisExpression::CThisExpression() {}

void CThisExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

CNotExpression::CNotExpression(IExpression* _expression): expression(_expression) {}

void CNotExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

CBracketsExpression::CBracketsExpression(IExpression* _expression): expression(_expression) {}

void CBracketsExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

void CExpressionList::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CExpressionList::Add(IExpression* expression)
{
	expressions.push_back(expression);
}

CNewExpression::CNewExpression(CId* _id) : id(_id)
{
}

void CNewExpression::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

CReturnExpression::CReturnExpression(IExpression* _expression) : expression(_expression)
{
}

void CReturnExpression::Accept(IVisitor* visitior)
{
	visitior->visit(this);
}
