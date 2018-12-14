#include <Modifier.h>
#include <Visitor.h>

CModifier::CModifier(TVisabilityModifierType _type) : type(_type)
{
}

void CModifier::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

const std::string& CModifier::GetLabel() const
{
	return  "modifier" + labelAddings;;
}
