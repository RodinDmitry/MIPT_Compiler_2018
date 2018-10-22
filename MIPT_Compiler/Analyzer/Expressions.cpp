#include <Expressions.h>
#include <Visitor.h>


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

CCallExpression::CCallExpression(IExpression* _caller, IId* _function, IArgumentList* _list) : caller(_caller), function(_function), list(_list) {}

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

CNewArrayExpression::CNewArrayExpression(IId* _id, IExpression* _expression): id(_id), expression(_expression) {}

void CNewArrayExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

CIdExpression::CIdExpression(IId* _id) : id(_id) {}

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