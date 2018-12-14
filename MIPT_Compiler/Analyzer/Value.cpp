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

const std::string& CValue::GetLabel() const
{
	std::string name;
	if (type == T_Boolean) {
		name = value ? "true" : "false";
	}
	else {
		name = std::to_string(value);
	}
	return name + labelAddings;
}
