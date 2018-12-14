#pragma once

#include <IR/IRTree.h>

namespace IR {

class IIRVisitor {
public:
	virtual void visit(ITree*) = 0;
};

}