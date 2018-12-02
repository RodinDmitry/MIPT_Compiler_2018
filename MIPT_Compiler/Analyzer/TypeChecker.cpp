#include <TypeChecker.h>
#include <SymbolTable.h>

CType* CTypeGetter::GetType(IExpression* node)
{
	currentType = nullptr;
	waitingNodes.push_back(node);
	while (waitingNodes.size() > 0) {
		ITree* current = waitingNodes.front();
		waitingNodes.pop_front();
		current->Accept(this);
	}
	return currentType;
}

void CTypeGetter::visit(CBinaryExpression* node)
{
	waitingNodes.push_front(node->right.get());
	waitingNodes.push_front(node->left.get());
}

void CTypeGetter::visit(CArrayExpression* )
{
	CType* type = new CType(TDataType::DT_Integer);
	resultingTypes.push_back(type);
}

void CTypeGetter::visit(CCallExpression* node)
{
	const CFunctionInfo* info = CSymbolTable::FindMethod(symbolTable, CSymbol::GetSymbol(node->function->name));
	if (info != nullptr) {
		resultingTypes.push_back(info->)
	}
}

void CTypeGetter::visit(CValueExpression *)
{
}

void CTypeGetter::visit(CNewArrayExpression *)
{
}

void CTypeGetter::visit(CNewExpression *)
{
}

void CTypeGetter::visit(CIdExpression *)
{
}

void CTypeGetter::visit(CThisExpression *)
{
}

void CTypeGetter::visit(CNotExpression *)
{
}

void CTypeGetter::visit(CBracketsExpression *)
{
}

void CTypeGetter::visit(CReturnExpression *)
{
}
