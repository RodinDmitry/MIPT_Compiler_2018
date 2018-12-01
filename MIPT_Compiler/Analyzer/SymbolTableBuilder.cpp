#include <SymbolTableBuilder.h>
#include <assert.h>

void CSymbolTableBuilder::visit(ITree* )
{
	throw new std::exception();
}

void CSymbolTableBuilder::visit(CArgumentList* node)
{
	for (int i = 0; i < node->arguments.size(); i++) {
		waitingNodes.push_front(node->arguments[i].get());
	}
}

void CSymbolTableBuilder::visit(CClassDeclaration*)
{
	CSymbolTable::CreateClassInCurrent(std::)
}

void CSymbolTableBuilder::visit(CClassInternals*)
{
}

void CSymbolTableBuilder::visit(CClassInternalsList*)
{
}

void CSymbolTableBuilder::visit(CClass*)
{
}

void CSymbolTableBuilder::visit(CClassList *)
{
}

void CSymbolTableBuilder::visit(IExpression *)
{
}

void CSymbolTableBuilder::visit(CExpressionList *)
{
}

void CSymbolTableBuilder::visit(CLValueExpression *)
{
}

void CSymbolTableBuilder::visit(CBinaryExpression *)
{
}

void CSymbolTableBuilder::visit(CArrayExpression *)
{
}

void CSymbolTableBuilder::visit(CCallExpression *)
{
}

void CSymbolTableBuilder::visit(CValueExpression *)
{
}

void CSymbolTableBuilder::visit(CNewArrayExpression *)
{
}

void CSymbolTableBuilder::visit(CNewExpression *)
{
}

void CSymbolTableBuilder::visit(CIdExpression *)
{
}

void CSymbolTableBuilder::visit(CThisExpression *)
{
}

void CSymbolTableBuilder::visit(CNotExpression *)
{
}

void CSymbolTableBuilder::visit(CBracketsExpression *)
{
}

void CSymbolTableBuilder::visit(CReturnExpression *)
{
}

void CSymbolTableBuilder::visit(CFunction *)
{
}

void CSymbolTableBuilder::visit(CId *)
{
}

void CSymbolTableBuilder::visit(CMainArgument *)
{
}

void CSymbolTableBuilder::visit(CMainFunction *)
{
}

void CSymbolTableBuilder::visit(CMain *)
{
}

void CSymbolTableBuilder::visit(CModifier *)
{
}

void CSymbolTableBuilder::visit(CProgram *)
{
}

void CSymbolTableBuilder::visit(IStatement *)
{
}

void CSymbolTableBuilder::visit(CStatementList *)
{
}

void CSymbolTableBuilder::visit(CVisibilityStatement *)
{
}

void CSymbolTableBuilder::visit(CIfStatement *)
{
}

void CSymbolTableBuilder::visit(CWhileStatement *)
{
}

void CSymbolTableBuilder::visit(CPrintStatement *)
{
}

void CSymbolTableBuilder::visit(CEqualStatement *)
{
}

void CSymbolTableBuilder::visit(CVariableStatement *)
{
}

void CSymbolTableBuilder::visit(CType *)
{
}

void CSymbolTableBuilder::visit(IValue *)
{
}

void CSymbolTableBuilder::visit(CValue *)
{
}

void CSymbolTableBuilder::visit(CVariable *)
{
}
