#include <IR/Tree.h>
#include <IR/IRVisitor.h>

namespace IR {

	void ITree::Accept(IIRVisitor* visitor)
	{
		visitor->visit(this);
	}

}