#include <IR/IRStatement.h>
#include <IR/IRExpression.h>
#include <IR/IRVisitor.h>


namespace IR {

	void CStatement::Accept(IIRVisitor* visitor)
	{
		visitor->visit(this);
	}

	void CMoveStatement::Accept(IIRVisitor* visitor)
	{
		visitor->visit(this);
	}

	void CExpStatement::Accept(IIRVisitor* visitor)
	{
		visitor->visit(this);
	}

	void CJumpStatement::Accept(IIRVisitor* visitor)
	{
		visitor->visit(this);
	}

	void CJumpConditionalStatement::Accept(IIRVisitor* visitor)
	{
		visitor->visit(this);
	}

	void CSeqStatement::Accept(IIRVisitor* visitor)
	{
		visitor->visit(this);
	}

	void CLabelStatement::Accept(IIRVisitor* visitor)
	{
		visitor->visit(this);
	}

	void IR::CStatementList::Accept(IIRVisitor* visitor)
	{
		visitor->visit(this);
	}

} // namespace IR