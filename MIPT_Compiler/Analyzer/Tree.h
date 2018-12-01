#pragma once
#include <set>
#include <deque>
#include <memory>
#include <assert.h>

class ITree;
class IVisitor;

class ITree {
public:
	virtual void Accept(IVisitor* visitor);

	virtual std::string GetLabel();
	void AddToLabel(std::string adding);

protected:

	std::string labelAddings = "";
};

inline void ITree::Accept(IVisitor*) {
	assert(false);
}

inline std::string ITree::GetLabel() {
	assert(false);
}

inline void ITree::AddToLabel(std::string adding) {
	labelAddings += adding;
}