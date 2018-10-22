#include <Modifier.h>
#include <Visitor.h>

CModifier::CModifier(TModifierType _type) : type(_type)
{
}

void CModifier::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}
