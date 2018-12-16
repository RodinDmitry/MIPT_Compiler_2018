#include <IR/IRExpression.h>
#include <IR/IRVisitor.h>
#include <IR/IRStatement.h>

namespace IR {
	void IExpression::Accept(IIRVisitor* visitor) const
	{
		visitor->visit(this);
	}

	void CExpressionList::Accept(IIRVisitor* visitor) const
	{
		visitor->visit(this);
	}

	void CNameExpression::Accept(IIRVisitor * visitor) const
	{
		visitor->visit(this);
	}

	void CTempExpression::Accept(IIRVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CBinaryExpression::Accept(IIRVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CMemExpression::Accept(IIRVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CCallExpression::Accept(IIRVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CEseqExpression::Accept(IIRVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CConstExpression::Accept(IIRVisitor * visitor) const
	{
		visitor->visit(this);
	}
}