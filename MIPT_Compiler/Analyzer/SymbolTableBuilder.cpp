#include <SymbolTableBuilder.h>
#include <assert.h>

void CSymbolTableBuilder::visit(ITree* )
{
	// для определения того где конец класса иногда появляются заглушки в стеке
	CSymbolTable::LeaveBlock(tableName);
}

void CSymbolTableBuilder::visit(CArgumentList* node)
{
	for (int i = 0; i < node->arguments.size(); i++) {
		CSymbolTable::AddArgument(tableName, createVariableInfo(node->arguments[i].get()));
	}
}

void CSymbolTableBuilder::visit(CClassDeclaration* node)
{
	assert(node->name != nullptr);
	std::string name = node->name->name;
	std::string extend = "";
	if (node->extend != nullptr) {
		extend = node->extend->name;
	}
	CSymbolTable::CreateClass(tableName, name, extend);
}

void CSymbolTableBuilder::visit(CClassInternals* node)
{
	if (node->function != nullptr) {
		CFunctionInfo* info(createFunctionInfo(node->function.get()));
		std::shared_ptr<ITree> placeholder(new ITree());
		placeholders.push_back(placeholder);
		waitingNodes.push_front(placeholder.get());
		waitingNodes.push_front(node->function->body.get());
		waitingNodes.push_front(node->function->arguments.get());
		CSymbolTable::AddFunctionBlock(tableName, info);
	}
	else if (node->variable != nullptr) {
		CSymbolTable::AddMember(tableName, createVariableInfo(node->variable.get()));
	}
}

void CSymbolTableBuilder::visit(CClassInternalsList* node)
{
	for (int i = 0; i < node->internals.size(); i++) {
		waitingNodes.push_front(node->internals[i].get());
	}
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
	assert(false);
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
	assert(false);
}

void CSymbolTableBuilder::visit(CProgram* node)
{
	waitingNodes.push_front(node->classes.get());
	waitingNodes.push_front(node->main.get());
}

void CSymbolTableBuilder::visit(IStatement *)
{
	assert(false);
}

void CSymbolTableBuilder::visit(CStatementList *)
{
}

void CSymbolTableBuilder::visit(CVisibilityStatement *)
{
	assert(false);
}

void CSymbolTableBuilder::visit(CIfStatement *)
{
	// TODO
}

void CSymbolTableBuilder::visit(CWhileStatement *)
{
	// TODO
}

void CSymbolTableBuilder::visit(CPrintStatement *)
{
	assert(false);
}

void CSymbolTableBuilder::visit(CEqualStatement *)
{
	assert(false);
}

void CSymbolTableBuilder::visit(CVariableStatement* node)
{
	CSymbolTable::AddMember(tableName, createVariableInfo(node->variable.get()));
}

void CSymbolTableBuilder::visit(CType *)
{
	assert(false);
}

void CSymbolTableBuilder::visit(IValue *)
{
	assert(false);
}

void CSymbolTableBuilder::visit(CValue *)
{
	assert(false);
}

void CSymbolTableBuilder::visit(CVariable *)
{
	assert(false);
}

CVariableInfo* CSymbolTableBuilder::createVariableInfo(CVariable* node)
{
	CVariableInfo* info = new CVariableInfo(CSymbol::GetSymbol(node->name->name), node->type->type,
		CSymbol::GetSymbol(node->type->instance));
	return info;
}

CFunctionInfo* CSymbolTableBuilder::createFunctionInfo(CFunction* node)
{
	CFunctionInfo* info = new CFunctionInfo(CSymbol::GetSymbol(node->name->name), CSymbol::GetSymbol(node->returns->instance),
		node->returns->type, node->visibility->type);
	return info;
}
