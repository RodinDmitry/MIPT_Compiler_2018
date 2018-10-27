#include <Tree.h>
#include <Visitor.h>

void IExpression::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}
