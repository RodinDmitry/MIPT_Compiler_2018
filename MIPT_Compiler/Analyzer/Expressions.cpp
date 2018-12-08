#include <Expressions.h>
#include <Visitor.h>
#include <Argument.h>
#include <Id.h>

void IExpression::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CLValueExpression::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CLValueExpression::GetLabel()
{
	return  "lvalue" + labelAddings;;
}

CBinaryExpression::CBinaryExpression(IExpression* _left, IExpression* _right, TOpeartor _operation):
	left(_left), right(_right), operation(_operation)
{
}

void CBinaryExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CBinaryExpression::GetLabel()
{
	std::string name;
	switch (operation) {
		case CBinaryExpression::O_Plus: name += "+";  break;
		case CBinaryExpression::O_Minus: name += "-";  break;
		case CBinaryExpression::O_Division: name += "/";  break;
		case CBinaryExpression::O_IntegerDivision: name += "%";  break;
		case CBinaryExpression::O_And: name += "&&";  break;
		case CBinaryExpression::O_Or: name += "||";  break;
		case CBinaryExpression::O_Multiplication: name += "*";  break;
		case CBinaryExpression::O_Less: name += "<";  break;
		case CBinaryExpression::O_More: name += ">";  break;
	}
	return  name + labelAddings;
}

CArrayExpression::CArrayExpression(IExpression* _caller, IExpression* _index): caller(_caller), index(_index)
{
}

void CArrayExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CArrayExpression::GetLabel()
{
	return  "arrayExpression" + labelAddings;;
}

CCallExpression::CCallExpression(IExpression* _caller, CId* _function, CArgumentList* _list) : caller(_caller), function(_function), list(_list) {}

void CCallExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CCallExpression::GetLabel()
{
	return  "call" + labelAddings;;
}

CCallLengthExpression::CCallLengthExpression(IExpression* _caller) : caller(_caller) {}

void CCallLengthExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CCallLengthExpression::GetLabel()
{
	return  "length" + labelAddings;;
}

CValueExpression::CValueExpression(IValue* _value) : value(_value) {}

void CValueExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CValueExpression::GetLabel()
{
	return  "valueExpr" + labelAddings;;
}

CNewArrayExpression::CNewArrayExpression(IExpression* _expression): expression(_expression) {}

void CNewArrayExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CNewArrayExpression::GetLabel()
{
	return  "newArray" + labelAddings;;
}

CIdExpression::CIdExpression(CId* _id) : id(_id) {}

void CIdExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CIdExpression::GetLabel()
{
	return  "idExpression" + labelAddings;;
}

CThisExpression::CThisExpression() {}

void CThisExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CThisExpression::GetLabel()
{
	return  "this" + labelAddings;;
}

CNotExpression::CNotExpression(IExpression* _expression): expression(_expression) {}

void CNotExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CNotExpression::GetLabel()
{
	return  "notExpression" + labelAddings;;
}

CBracketsExpression::CBracketsExpression(IExpression* _expression): expression(_expression) {}

void CBracketsExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CBracketsExpression::GetLabel()
{
	return  "brackets" + labelAddings;;
}

void CExpressionList::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CExpressionList::Add(IExpression* expression)
{
	std::shared_ptr<IExpression> ptr(expression);
	expressions.push_back(ptr);
}

std::string CExpressionList::GetLabel()
{
	return  "expressions" + labelAddings;;
}

CNewExpression::CNewExpression(CId* _id) : id(_id)
{
}

void CNewExpression::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CNewExpression::GetLabel()
{
	return  "new" + labelAddings;;
}

CReturnExpression::CReturnExpression(IExpression* _expression) : expression(_expression)
{
}

void CReturnExpression::Accept(IVisitor* visitior)
{
	visitior->visit(this);
}

std::string CReturnExpression::GetLabel()
{
	return  "return" + labelAddings;;
}
