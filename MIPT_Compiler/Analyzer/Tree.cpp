#include <Tree.h>
#include <Visitor.h>
#include <IFrame.h>

ITree::ITree(int _line) : line(_line) {};

ITree::~ITree() {};

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

std::shared_ptr<IFrame> ITree::GetFrame()
{
	return frame;
}

void ITree::SetFrame(std::shared_ptr<IFrame> _frame)
{
	frame = _frame;
}

void ITree::Accept(IVisitor* visitor) 
{
	visitor->visit(this);
}