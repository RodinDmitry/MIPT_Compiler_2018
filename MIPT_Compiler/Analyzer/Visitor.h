#pragma once

#include <Tree.h>

class IVisitor {
public:
	virtual void visit(ITree* ) = 0;
};

class CPrettyPrinter : public IVisitor {
public:
	virtual void visit(ITree*) override {}
};