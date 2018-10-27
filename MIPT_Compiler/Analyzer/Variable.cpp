#include <Variable.h>
#include <Visitor.h>

CVariable::CVariable(CId* _classInstance, CId* _name) : classInstance(_classInstance), name(_name)
{
}

void CVariable::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}


