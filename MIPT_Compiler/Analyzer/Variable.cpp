#include <Variable.h>
#include <Visitor.h>

CVariable::CVariable(CType* _type, CId* _name) : type(_type), name(_name)
{
}

void CVariable::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}


