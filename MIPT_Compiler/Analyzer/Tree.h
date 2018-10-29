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

	virtual std::string GetLabel() = 0;
	void AddToLabel(std::string adding);

	std::string labelAddings = "";
};

inline void ITree::AddToLabel(std::string adding) {
	labelAddings += adding;
}

class IExpression : public ITree {
public:
	virtual void Accept(IVisitor* visitor) override;

};
