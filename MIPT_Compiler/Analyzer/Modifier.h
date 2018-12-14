#pragma once
#include <Tree.h>
#include <VisabilityModifier.h>

class CModifier : public ITree
{
public:

	CModifier(TVisabilityModifierType type);
	virtual void Accept(IVisitor* visitor) override;

	TVisabilityModifierType type;

	std::string GetLabel() const override;
};