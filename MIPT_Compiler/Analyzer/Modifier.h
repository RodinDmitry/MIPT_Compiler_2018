#include <Tree.h>

class CModifier : public ITree
{
public:
	enum TModifierType
	{
		MT_Public,
		MT_Private,
	};

	CModifier(TModifierType type);
	virtual void Accept(IVisitor* visitor) override;

	TModifierType type;
};