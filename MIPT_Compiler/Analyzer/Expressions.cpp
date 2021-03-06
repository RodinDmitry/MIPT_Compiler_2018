#include <Expressions.h>
#include <Visitor.h>
#include <Argument.h>
#include <Id.h>


IExpression::IExpression(int _line) : ITree(_line) {}

CLValueExpression::CLValueExpression(int _line) : IExpression(-1) {}

void IExpression::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}


void CLValueExpression::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CLValueExpression::GetLabel() const
{
	return  "lvalue" + labelAddings;;
}


CBinaryExpression::CBinaryExpression(IExpression* _left, IExpression* _right, TOperator _operation, int _line):
	left(_left), right(_right), operation(_operation), IExpression(_line)
{
}

void CBinaryExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CBinaryExpression::GetLabel() const
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

CArrayExpression::CArrayExpression(IExpression* _caller, IExpression* _index, int _line): caller(_caller), index(_index), IExpression(_line)
{
}

void CArrayExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CArrayExpression::GetLabel() const
{
	return  "arrayExpression" + labelAddings;;
}

CCallExpression::CCallExpression(IExpression* _caller, CId* _function, CExpressionList* _list, int _line) : caller(_caller), function(_function), list(_list), IExpression(_line) {}

void CCallExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CCallExpression::GetLabel() const
{
	return  "call" + labelAddings;;
}

CCallLengthExpression::CCallLengthExpression(IExpression* _caller, int _line) : caller(_caller), IExpression(_line) {}

void CCallLengthExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CCallLengthExpression::GetLabel() const
{
	return  "length" + labelAddings;;
}

CValueExpression::CValueExpression(IValue* _value, int _line) : value(_value), IExpression(_line) {}

void CValueExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CValueExpression::GetLabel() const
{
	return  "valueExpr" + labelAddings;;
}

CNewArrayExpression::CNewArrayExpression(IExpression* _expression, int _line): expression(_expression), IExpression(_line) {}

void CNewArrayExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CNewArrayExpression::GetLabel() const
{
	return  "newArray" + labelAddings;;
}

CIdExpression::CIdExpression(CId* _id, int _line) : id(_id), CLValueExpression(_line) {}

void CIdExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CIdExpression::GetLabel() const
{
	return  "idExpression" + labelAddings;;
}

CThisExpression::CThisExpression() : CLValueExpression(-1) {}

void CThisExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CThisExpression::GetLabel() const
{
	return  "this" + labelAddings;;
}

CNotExpression::CNotExpression(IExpression* _expression, int _line): expression(_expression), IExpression(_line) {}

void CNotExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CNotExpression::GetLabel() const
{
	return  "notExpression" + labelAddings;;
}

CBracketsExpression::CBracketsExpression(IExpression* _expression, int _line): expression(_expression), IExpression(_line) {}

void CBracketsExpression::Accept(IVisitor* visitor)
{
	visitor->visit( this );
}

std::string CBracketsExpression::GetLabel() const
{
	return  "brackets" + labelAddings;;
}

CExpressionList::CExpressionList() : ITree(-1) {}

void CExpressionList::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CExpressionList::Add(IExpression* expression)
{
	std::shared_ptr<IExpression> ptr(expression);
	expressions.push_back(ptr);
}

std::string CExpressionList::GetLabel() const
{
	return  "expressions" + labelAddings;;
}

CNewExpression::CNewExpression(CId* _id, int _line) : id(_id), IExpression(_line)
{
}

void CNewExpression::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CNewExpression::GetLabel() const
{
	return  "new" + labelAddings;;
}
