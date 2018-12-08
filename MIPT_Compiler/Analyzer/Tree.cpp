#include <Tree.h>
#include <Visitor.h>

ITree::ITree(int _line) : line(_line) {};

void IExpression::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

int ITree::getLine() const {
	return line;
}