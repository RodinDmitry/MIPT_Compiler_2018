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
