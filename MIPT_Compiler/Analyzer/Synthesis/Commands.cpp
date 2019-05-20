#include <Synthesis/Commands.h>
#include <Synthesis/Visitor.h>


namespace Synthesis
{
	void ICommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CNullExpression::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CTempExpression::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CAddCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CAddConstCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CSubCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CSubConstCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CMultCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CDivCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CLoadCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CStatement::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CMemoryStatement::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CStoreCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CMoveRegisterCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CLabelDeclarationCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CCallFunctionCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CJumpCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CConditionalJumpCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
	void CExpStatementCommand::Accept(IVisitor * visitor) const
	{
		visitor->visit(this);
	}
}