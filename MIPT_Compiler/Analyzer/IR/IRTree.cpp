#include <IR/IRTree.h>
#include <IR/IRVisitor.h>

namespace IR {

	void ITree::Accept(IIRVisitor* visitor) const
	{
		visitor->visit(this);
	}

}