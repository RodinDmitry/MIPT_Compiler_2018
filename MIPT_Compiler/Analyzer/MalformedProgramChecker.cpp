#include <MalformedProgramChecker.h>
#include <assert.h>
#include <ErrorTable.h>
#include <TypeGetter.h>

void CMalformedProgramChecker::BuildTable(ITree* startNode, std::string _tableName)
{
	cleanup();
	tableName = _tableName;
	CSymbolTable::CreateTable(_tableName);
	waitingNodes.push_front(startNode);
	while (waitingNodes.size() > 0) {
		ITree* current = waitingNodes.front();
		waitingNodes.pop_front();
		current->Accept(this);
	}
}

void CMalformedProgramChecker::visit(ITree* )
{
	assert(false);
}

void CMalformedProgramChecker::visit(CArgumentList* node)
{
	for (int i = 0; i < node->arguments.size(); i++) {
		CVariableInfo* info = createVariableInfo(node->arguments[i].get());
		if (info != nullptr) {
			checkVariableDoubleDeclaration(info->String());
			CSymbolTable::AddArgument(tableName, info);
		}
	}
}

void CMalformedProgramChecker::visit(CClassDeclaration* node)
{
	assert(node->name != nullptr);

	checkClassDoubleDeclaration(CSymbol::GetSymbol(node->name->name));
	std::string name = node->name->name;
	std::string extend = "";
	if (node->extend != nullptr) {
		extend = node->extend->name;
	}
	CSymbolTable::CreateClass(tableName, name, extend);
}

void CMalformedProgramChecker::visit(CClassInternals* node)
{
	// ignore
}

void CMalformedProgramChecker::visit(CClassInternalsList* node)
{
	for (int i = 0; i < node->internals.size(); i++) {
		if (node->internals[i]->function != nullptr) {
			waitingNodes.push_front(node->internals[i]->function.get());
		}
	}

	for (int i = 0; i < node->internals.size(); i++) {
		if (node->internals[i]->variable != nullptr) {
			waitingNodes.push_front(node->internals[i]->variable.get());
		}
	}
}

void CMalformedProgramChecker::visit(CClass* node)
{
	createLeavePlaceholder();
	waitingNodes.push_front(node->internals.get());
	waitingNodes.push_front(node->declaration.get());
}

void CMalformedProgramChecker::visit(CClassList* node)
{
	for (int i = node->classes.size() - 1; i >= 0; i--) {
		waitingNodes.push_front(node->classes[i].get());
	}
}

void CMalformedProgramChecker::visit(IExpression*)
{
	assert(false);
}

void CMalformedProgramChecker::visit(CExpressionList* node)
{
	for (int i = node->expressions.size() - 1; i >= 0; i--) {
		waitingNodes.push_front(node->expressions[i].get());
	}
}

void CMalformedProgramChecker::visit(CLValueExpression*)
{
	assert(false);
}

void CMalformedProgramChecker::visit(CBinaryExpression* node)
{
	waitingNodes.push_front(node->right.get());
	waitingNodes.push_front(node->left.get());
}

void CMalformedProgramChecker::visit(CArrayExpression* node)
{
	waitingNodes.push_front(node->index.get());
	waitingNodes.push_front(node->caller.get());
}

void CMalformedProgramChecker::visit(CCallExpression* node)
{
	waitingNodes.push_front(node->caller.get());
}

void CMalformedProgramChecker::visit(CValueExpression*)
{
	//ignore
}

void CMalformedProgramChecker::visit(CNewArrayExpression*)
{
	//ignore
}

void CMalformedProgramChecker::visit(CNewExpression* node)
{
	// ignore
}

void CMalformedProgramChecker::visit(CIdExpression* node)
{
	const CVariableInfo* info = CSymbolTable::FindMember(tableName, CSymbol::GetSymbol(node->id->name));
	if (info == nullptr) {
		CErrorTable::AddError("Unknown variable " + node->id->name);
	}
}

void CMalformedProgramChecker::visit(CThisExpression*)
{
	//ignore
}

void CMalformedProgramChecker::visit(CNotExpression* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CMalformedProgramChecker::visit(CBracketsExpression* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CMalformedProgramChecker::visit(CReturnExpression* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CMalformedProgramChecker::visit(CFunction* node)
{
	checkFunctionDoubleDeclaration(CSymbol::GetSymbol(node->name->name));
	CFunctionInfo* info(createFunctionInfo(node));
	if (info != nullptr) {
		createLeavePlaceholder();
		CSymbolTable::AddFunctionBlock(tableName, info);
	}
	waitingNodes.push_front(node->body.get());
	waitingNodes.push_front(node->arguments.get());	
}

void CMalformedProgramChecker::visit(CId*)
{
	// ignore
}

void CMalformedProgramChecker::visit(CMainArgument*)
{
	// ignore ? TODO
}

void CMalformedProgramChecker::visit(CMainFunction* node)
{
	waitingNodes.push_front(node->body.get());
}

void CMalformedProgramChecker::visit(CMain* node)
{
	waitingNodes.push_front(node->mainFunction.get());
}

void CMalformedProgramChecker::visit(CModifier*)
{
	assert(false);
}

void CMalformedProgramChecker::visit(CProgram* node)
{
	waitingNodes.push_front(node->classes.get());
	waitingNodes.push_front(node->main.get());
}

void CMalformedProgramChecker::visit(IStatement*)
{
	assert(false);
}

void CMalformedProgramChecker::visit(CStatementList* node)
{
	for (int i = 0; i < node->statements.size(); i++) {
		waitingNodes.push_front(node->statements[i].get());
	}
}

void CMalformedProgramChecker::visit(CVisibilityStatement*)
{
	// ignore
}

void CMalformedProgramChecker::visit(CIfStatement* node)
{
	createLeavePlaceholder();
	waitingNodes.push_front(node->elseStatement.get());
	createEnterPlaceholder();
	createLeavePlaceholder();
	waitingNodes.push_front(node->thenStatement.get());
	createEnterPlaceholder();
	waitingNodes.push_front(node->condition.get());
}

void CMalformedProgramChecker::visit(CWhileStatement* node)
{
	createLeavePlaceholder();
	waitingNodes.push_front(node->statement.get());
	createEnterPlaceholder();
	waitingNodes.push_front(node->condition.get());
}

void CMalformedProgramChecker::visit(CPrintStatement* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CMalformedProgramChecker::visit(CAssignStatement* node)
{
	// typeCheck(node->left.get(), node->right.get());
	waitingNodes.push_front(node->right.get());
	waitingNodes.push_front(node->left.get());
}

void CMalformedProgramChecker::visit(CVariableStatement* node)
{
	CVariableInfo* info = createVariableInfo(node->variable.get());
	if (info != nullptr) {
		checkVariableDoubleDeclaration(info->String());
		CSymbolTable::AddMember(tableName, info);
	}
}

void CMalformedProgramChecker::visit(CType*)
{
	// ignore
}

void CMalformedProgramChecker::visit(IValue*)
{
	// ignore
}

void CMalformedProgramChecker::visit(CValue*)
{
	// ignore
}

void CMalformedProgramChecker::visit(CVariable* node)
{
	CVariableInfo* info = createVariableInfo(node);
	if (info != nullptr) {
		checkVariableDoubleDeclaration(info->String());
		CSymbolTable::AddMember(tableName, info);
	}
}

void CMalformedProgramChecker::visit(CVisibilityBlockStart*)
{
	CSymbolTable::AddBlock(tableName);
}

void CMalformedProgramChecker::visit(CVisibilityBlockEnd*)
{
	CSymbolTable::LeaveBlock(tableName);
}

CVariableInfo* CMalformedProgramChecker::createVariableInfo(CVariable* node)
{
	try {
		CVariableInfo* info = new CVariableInfo(tableName, CSymbol::GetSymbol(node->name->name), node->type->type,
			CSymbol::GetSymbol(node->type->instance));
		return info;
	}
	catch (CUndefinedTypeException* exception) {
		CErrorTable::AddError(exception);
	}
	return nullptr;
}

CFunctionInfo* CMalformedProgramChecker::createFunctionInfo(CFunction* node)
{
	try {
		CFunctionInfo* info = new CFunctionInfo(tableName, CSymbol::GetSymbol(node->name->name),
			CSymbol::GetSymbol(node->returns->instance), node->returns->type, node->visibility->type);
		return info;
	}
	catch (CUndefinedTypeException* exception) {
		CErrorTable::AddError(exception);
	}
	return nullptr;
}

void CMalformedProgramChecker::createEnterPlaceholder()
{
	std::shared_ptr<ITree> placeholder(new CVisibilityBlockStart());
	placeholders.push_back(placeholder);
	waitingNodes.push_front(placeholder.get());
}

void CMalformedProgramChecker::createLeavePlaceholder()
{
	std::shared_ptr<ITree> placeholder(new CVisibilityBlockEnd());
	placeholders.push_back(placeholder);
	waitingNodes.push_front(placeholder.get());
}

void CMalformedProgramChecker::cleanup()
{
	waitingNodes.clear();
	placeholders.clear();
}

void CMalformedProgramChecker::checkVariableDoubleDeclaration(const CSymbol * symbol)
{
	const CVariableInfo* info = CSymbolTable::FindMember(tableName, symbol);
	if (info != nullptr) {
		CErrorTable::AddError("Variable double declaration");
	}
}

void CMalformedProgramChecker::checkFunctionDoubleDeclaration(const CSymbol* symbol)
{
	const CFunctionInfo* info = CSymbolTable::FindMethod(tableName, symbol);
	if (info != nullptr) {
		CErrorTable::AddError("Function double declaration");
	}
}

void CMalformedProgramChecker::checkClassDoubleDeclaration(const CSymbol * symbol)
{
	const CClassInfo* info = CSymbolTable::FindClass(tableName, symbol);
	if (info != nullptr) {
		CErrorTable::AddError("Class double declaration");
	}
}
