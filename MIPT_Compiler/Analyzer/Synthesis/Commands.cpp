#include <Synthesis/Commands.h>
#include <Synthesis/Visitor.h>


namespace Synthesis
{
	void ICommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CNullExpression::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CTempExpression::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CAddCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CAddConstCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CSubCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CSubConstCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CMultCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CDivCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CLoadCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CStatement::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CMemoryStatement::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CStoreCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CMoveRegisterCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CLabelDeclarationCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CCallFunctionCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CJumpCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CConditionalJumpCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
	void CExpStatementCommand::Accept(IVisitor * visitor) const
	{
		visitor->Visit(this);
	}
}