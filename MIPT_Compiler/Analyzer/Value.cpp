#include <Value.h>
#include <Visitor.h>

CValue::CValue(int _value, TType _type) : value(_value), type(_type)
{
}

void CValue::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}
