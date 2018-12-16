#include <IR/IRStatement.h>
#include <IR/IRExpression.h>
#include <IR/IRVisitor.h>


namespace IR {

	void IStatement::Accept(IIRVisitor* visitor) const
	{
		visitor->visit(this);
	}

	void CMoveStatement::Accept(IIRVisitor* visitor) const
	{
		visitor->visit(this);
	}

	void CExpStatement::Accept(IIRVisitor* visitor) const
	{
		visitor->visit(this);
	}

	void CJumpStatement::Accept(IIRVisitor* visitor) const
	{
		visitor->visit(this);
	}

	void CJumpConditionalStatement::Accept(IIRVisitor* visitor) const
	{
		visitor->visit(this);
	}

	void CSeqStatement::Accept(IIRVisitor* visitor) const
	{
		visitor->visit(this);
	}

	void CLabelStatement::Accept(IIRVisitor* visitor) const
	{
		visitor->visit(this);
	}

	void IR::CStatementList::Accept(IIRVisitor* visitor) const
	{
		visitor->visit(this);
	}

} // namespace IR