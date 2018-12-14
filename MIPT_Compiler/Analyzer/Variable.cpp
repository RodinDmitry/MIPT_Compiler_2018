#include <Variable.h>
#include <Visitor.h>

CVariable::CVariable(CType* _type, CId* _name, int _line) : type(_type), name(_name), ITree(_line)
{
}

void CVariable::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CVariable::GetLabel() const
{
	return "variable" + labelAddings;
}


