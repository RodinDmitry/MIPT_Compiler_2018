#include <Value.h>
#include <Visitor.h>

void IValue::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

CValue::CValue(int _value, TType _type) : value(_value), type(_type)
{
}

void CValue::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CValue::GetLabel()
{
	return "value" + labelAddings;
}
