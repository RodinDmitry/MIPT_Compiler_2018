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
			CSymbolTable::AddArgument(tableName, info);
		}
	}
}

void CMalformedProgramChecker::visit(CClassDeclaration* node)
{
	assert(node->name != nullptr);
	std::string name = node->name->name;
	std::string extend = "";
	if (node->extend != nullptr) {
		extend = node->extend->name;
	}
	CSymbolTable::CreateClass(tableName, name, extend);
}

void CMalformedProgramChecker::visit(CClassInternals* node)
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

void CMalformedProgramChecker::visit(CClassInternalsList* node)
{
	for (int i = 0; i < node->internals.size(); i++) {
		waitingNodes.push_front(node->internals[i].get());
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
	// typeCheck(node->left.get(), node->right.get());
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
	// callerCheck(node->caller.get(), node->function.get(), node->list.get());
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
	const CClassInfo* info = CSymbolTable::FindClass(tableName, CSymbol::GetSymbol(node->id->name));
	if (info == nullptr) {
		CErrorTable::AddError("Unknown class");
	}

}

void CMalformedProgramChecker::visit(CIdExpression* node)
{
	const CVariableInfo* info = CSymbolTable::FindMember(tableName, CSymbol::GetSymbol(node->id->name));
	if (info == nullptr) {
		CErrorTable::AddError("Unknown variable");
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
	// notVoidCheck(node);
	waitingNodes.push_front(node->expression.get());
}

void CMalformedProgramChecker::visit(CReturnExpression* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CMalformedProgramChecker::visit(CFunction* node)
{
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

void CMalformedProgramChecker::visit(CMainFunction*)
{
	// ignore ? TODO
}

void CMalformedProgramChecker::visit(CMain*)
{
	// ignore ? TODO
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
	for (int i = node->statements.size() - 1; i >= 0; i--) {
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
	waitingNodes.push_back(node->elseStatement.get());
	createEnterPlaceholder();
	createLeavePlaceholder();
	waitingNodes.push_back(node->thenStatement.get());
	createEnterPlaceholder();
	waitingNodes.push_back(node->condition.get());
}

void CMalformedProgramChecker::visit(CWhileStatement* node)
{
	createLeavePlaceholder();
	waitingNodes.push_back(node->statement.get());
	createEnterPlaceholder();
	waitingNodes.push_back(node->condition.get());
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

void CMalformedProgramChecker::visit(CVariable*)
{
	// все случаи обьявления переменной должны обрабатываться выше
	// assert(false);
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
	// typeCheck(node->returns.get(), node->returnExpression.get());
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
/*
void CMalformedProgramChecker::typeCheck(IExpression* left, IExpression* right)
{
	CTypeGetter getter;
	std::shared_ptr<CType> leftType = getter.GetType(left, tableName);
	typeCheck(leftType.get(), right);
}

void CMalformedProgramChecker::typeCheck(CType* type, IExpression* node)
{
	CTypeGetter getter;
	std::shared_ptr<CType> nodeType = getter.GetType(node, tableName);
	if (type->type != nodeType->type) {
		if (type->type == DT_Integer && nodeType->type == DT_Boolean) {
			return;
		}
		CErrorTable::AddError("Type check failed");
	}
	if (type->instance != nodeType->instance) {
		CErrorTable::AddError("Type check failed");
	}
	
}

void CMalformedProgramChecker::notVoidCheck(IExpression * node)
{
	CTypeGetter getter;
	std::shared_ptr<CType> nodeType = getter.GetType(node, tableName);
	if (nodeType->type == DT_Void) {
		CErrorTable::AddError("Type check failed");
	}
}

void CMalformedProgramChecker::callerCheck(CId* caller, CId* function, CArgumentList* list)
{
	const CVariableInfo* info = CSymbolTable::FindMember(tableName, CSymbol::GetSymbol(caller->name));
	const CClassInfo* classInfo = CSymbolTable::FindClass(tableName, info->String());
	const std::vector<const CFunctionInfo*> methods = classInfo->GetMethods();

	std::vector<CType*> arguments;
	for (int i = 0; i < list->arguments.size(); i++) {
		arguments.push_back(list->arguments[i]->type.get());
	}

	bool hasCompatibleMethod = false;
	for (int i = 0; i < methods.size(); i++) {
		if (methods[i]->String()->String() == function->name) {
			if (argumentCheck(methods[i], arguments)) {
				hasCompatibleMethod = true;
			}
		}
	}
	if (!hasCompatibleMethod) {
		CErrorTable::AddError("Invalid call");
	}
}

bool CMalformedProgramChecker::argumentCheck(const CFunctionInfo* info, std::vector<CType*>& arguments)
{
	const std::vector<const CVariableInfo*> variables = info->GetArguments();
	if (arguments.size() != variables.size()) {
		return false;
	}
	for (int i = 0; i < arguments.size(); i++) {
		std::shared_ptr<CType> variableType = variables[i]->GetType();
		if (variableType->type != arguments[i]->type || variableType->instance != arguments[i]->instance) {
			return false;
		}
	}

	return true;
}
*/