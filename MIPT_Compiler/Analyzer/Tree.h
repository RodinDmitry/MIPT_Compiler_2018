#pragma once
#include <set>

class ITree;
class IVisitor;

extern std::set< ITree* > printerStack;

class ITree {
public:
	ITree() {
		printerStack.insert(this);
	}

	virtual void Accept(IVisitor* visitor) = 0;
};


class IExpression : public ITree {

};
