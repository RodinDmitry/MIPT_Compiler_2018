#include <SymbolTableBuilder.h>
#include <assert.h>

void CSymbolTableBuilder::BuildTable(ITree* startNode, std::string _tableName)
{
	cleanup();
	tableName = _tableName;
	waitingNodes.push_front(startNode);
	while (waitingNodes.size() > 0) {
		ITree* current = waitingNodes.front();
		waitingNodes.pop_front();
		current->Accept(this);
	}
}

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
	createPlaceholder();
	CSymbolTable::CreateClass(tableName, name, extend);
}

void CSymbolTableBuilder::visit(CClassInternals* node)
{
	if (node->function != nullptr) {
		waitingNodes.push_front(node->function.get());
	}
	else if (node->variable != nullptr) {
		waitingNodes.push_front(node->variable.get());
	}
	else {
		assert(false);
	}
}

void CSymbolTableBuilder::visit(CClassInternalsList* node)
{
	for (int i = 0; i < node->internals.size(); i++) {
		waitingNodes.push_front(node->internals[i].get());
	}
}

void CSymbolTableBuilder::visit(CClass* node)
{
	waitingNodes.push_front(node->internals.get());
	waitingNodes.push_front(node->declaration.get());
}

void CSymbolTableBuilder::visit(CClassList* node)
{
	for (int i = node->classes.size() - 1; i >= 0; i--) {
		waitingNodes.push_front(node->classes[i].get());
	}
}

void CSymbolTableBuilder::visit(IExpression*)
{
	assert(false);
}

void CSymbolTableBuilder::visit(CExpressionList* node)
{
	for (int i = node->expressions.size() - 1; i >= 0; i--) {
		waitingNodes.push_front(node->expressions[i].get());
	}
}

void CSymbolTableBuilder::visit(CLValueExpression*)
{
	//ignore
}

void CSymbolTableBuilder::visit(CBinaryExpression* node)
{
	waitingNodes.push_front(node->right.get());
	waitingNodes.push_front(node->left.get());
}

void CSymbolTableBuilder::visit(CArrayExpression* node)
{
	waitingNodes.push_front(node->index.get());
	waitingNodes.push_front(node->caller.get());
}

void CSymbolTableBuilder::visit(CCallExpression* node)
{
	waitingNodes.push_front(node->caller.get());
}

void CSymbolTableBuilder::visit(CValueExpression*)
{
	//ignore
}

void CSymbolTableBuilder::visit(CNewArrayExpression*)
{
	//ignore
}

void CSymbolTableBuilder::visit(CNewExpression*)
{
	//ignore
}

void CSymbolTableBuilder::visit(CIdExpression*)
{
	//ignore
}

void CSymbolTableBuilder::visit(CThisExpression*)
{
	//ignore
}

void CSymbolTableBuilder::visit(CNotExpression* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CSymbolTableBuilder::visit(CBracketsExpression* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CSymbolTableBuilder::visit(CReturnExpression* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CSymbolTableBuilder::visit(CFunction* node)
{
	CFunctionInfo* info(createFunctionInfo(node));
	createPlaceholder();
	CSymbolTable::AddFunctionBlock(tableName, info);
	waitingNodes.push_front(node->body.get());
	waitingNodes.push_front(node->arguments.get());	
}

void CSymbolTableBuilder::visit(CId*)
{
	// ignore
}

void CSymbolTableBuilder::visit(CMainArgument*)
{
	// ignore ? TODO
}

void CSymbolTableBuilder::visit(CMainFunction*)
{
	// ignore ? TODO
}

void CSymbolTableBuilder::visit(CMain*)
{
	// ignore ? TODO
}

void CSymbolTableBuilder::visit(CModifier*)
{
	assert(false);
}

void CSymbolTableBuilder::visit(CProgram* node)
{
	waitingNodes.push_front(node->classes.get());
	waitingNodes.push_front(node->main.get());
}

void CSymbolTableBuilder::visit(IStatement*)
{
	assert(false);
}

void CSymbolTableBuilder::visit(CStatementList* node)
{
	for (int i = node->statements.size() - 1; i >= 0; i--) {
		waitingNodes.push_front(node->statements[i].get());
	}
}

void CSymbolTableBuilder::visit(CVisibilityStatement*)
{
	// ignore
}

void CSymbolTableBuilder::visit(CIfStatement* node)
{
	createPlaceholder();
	CSymbolTable::AddBlock(tableName);
	waitingNodes.push_back(node->elseStatement.get());
	waitingNodes.push_back(node->thenStatement.get());
	waitingNodes.push_back(node->condition.get());
}

void CSymbolTableBuilder::visit(CWhileStatement* node)
{
	createPlaceholder();
	CSymbolTable::AddBlock(tableName);
	waitingNodes.push_back(node->statement.get());
	waitingNodes.push_back(node->condition.get());
}

void CSymbolTableBuilder::visit(CPrintStatement* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CSymbolTableBuilder::visit(CEqualStatement* node)
{
	waitingNodes.push_front(node->right.get());
	waitingNodes.push_front(node->left.get());
}

void CSymbolTableBuilder::visit(CVariableStatement* node)
{
	CSymbolTable::AddMember(tableName, createVariableInfo(node->variable.get()));
}

void CSymbolTableBuilder::visit(CType*)
{
	// ignore
}

void CSymbolTableBuilder::visit(IValue*)
{
	// ignore
}

void CSymbolTableBuilder::visit(CValue*)
{
	// ignore
}

void CSymbolTableBuilder::visit(CVariable*)
{
	// все случаи обьявления переменной должны обрабатываться выше
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

void CSymbolTableBuilder::createPlaceholder()
{
	std::shared_ptr<ITree> placeholder(new ITree());
	placeholders.push_back(placeholder);
	waitingNodes.push_front(placeholder.get());
}

void CSymbolTableBuilder::cleanup()
{
	waitingNodes.clear();
	placeholders.clear();
}
