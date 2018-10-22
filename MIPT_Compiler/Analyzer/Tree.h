#pragma once
#include <set>
#include <deque>

class ITree;
class IVisitor;

extern std::set< ITree* > printerSet;
extern std::deque< ITree* > printerStack;

class ITree {
public:
	ITree() {
		printerStack.push_front(this);
		printerSet.insert(this);
	}

	virtual void Accept(IVisitor* visitor) = 0;
};


class IExpression : public ITree {

};
