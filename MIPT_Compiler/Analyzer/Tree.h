#pragma once
#include <set>
#include <deque>
#include <memory>

class ITree;
class IVisitor;

class ITree {
public:
	virtual void Accept(IVisitor* visitor) = 0;

	virtual std::string GetLabel() = 0;
	void AddToLabel(std::string adding);

protected:

	std::string labelAddings = "";
};

inline void ITree::AddToLabel(std::string adding) {
	labelAddings += adding;
}