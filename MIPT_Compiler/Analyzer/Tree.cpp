#include <Tree.h>
#include <Visitor.h>


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
