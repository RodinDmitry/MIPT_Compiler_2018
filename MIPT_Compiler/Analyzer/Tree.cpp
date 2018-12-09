#include <Tree.h>
#include <Visitor.h>

ITree::ITree(int _line) : line(_line) {};

void CClassVisibilityStart::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CClassVisibilityEnd::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CFunctionVisibilityStart::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CFunctionVisibilityEnd::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CVisibilityBlockStart::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CVisibilityBlockEnd::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

int ITree::GetLine() const {
	return line;
}

void ITree::Accept(IVisitor* visitor) 
{
	visitor->visit(this);
}
