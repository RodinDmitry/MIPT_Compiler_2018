#include <Id.h>
#include <Visitor.h>

CId::CId(char* _name) : name(_name)
{
}

void CId::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

