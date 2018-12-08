#pragma once
#include <set>
#include <deque>
#include <memory>

class ITree;
class IVisitor;

class ITree {
public:
	ITree() = default;
	ITree(int line);

	virtual void Accept(IVisitor* visitor) = 0;

	virtual std::string GetLabel() = 0;
	void AddToLabel(std::string adding);

	int getLine() const;

protected:

	std::string labelAddings = "";
	int line = -1;
};

inline void ITree::AddToLabel(std::string adding) {
	labelAddings += adding;
}