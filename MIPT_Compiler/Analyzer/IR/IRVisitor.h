#pragma once

#include <IR/Tree.h>

namespace IR {

class IIRVisitor {
public:
	virtual void visit(ITree*) = 0;
};

}