#include <Statement.h>
#include <Visitor.h>

CStatementBase::CStatementBase(CStatementBase* _next) : next(_next)
{
}

void CStatementBase::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}
