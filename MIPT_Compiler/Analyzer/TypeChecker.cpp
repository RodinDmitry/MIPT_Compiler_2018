#include <TypeChecker.h>
#include <TypeGetter.h>
#include <ErrorTable.h>

void CTypeChecker::CheckTypes(ITree* startNode, std::string _tableName)
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

void CTypeChecker::visit(CArgumentList* node)
{
	for (int i = 0; i < node->arguments.size(); i++) {
		waitingNodes.push_front(node->arguments[i].get());
	}
}

void CTypeChecker::visit(CClassInternals* node)
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

void CTypeChecker::visit(CClassInternalsList* node)
{
	for (int i = 0; i < node->internals.size(); i++) {
		waitingNodes.push_front(node->internals[i].get());
	}
}

void CTypeChecker::visit(CClass* node)
{
	createLeaveClassPlaceholder();
	currentClassName = node->declaration->name->name;
	waitingNodes.push_front(node->internals.get());
}

void CTypeChecker::visit(CClassList* node)
{
	for (int i = node->classes.size() - 1; i >= 0; i--) {
		waitingNodes.push_front(node->classes[i].get());
	}
}

void CTypeChecker::visit(CExpressionList* node)
{
	for (int i = node->expressions.size() - 1; i >= 0; i--) {
		waitingNodes.push_front(node->expressions[i].get());
	}
}

void CTypeChecker::visit(CBinaryExpression* node)
{
	if (!typeCheck(node->left.get(), node->right.get())) {
		CErrorTable::AddError("Binary type check failed");
	}
	waitingNodes.push_front(node->right.get());
	waitingNodes.push_front(node->left.get());
}

void CTypeChecker::visit(CArrayExpression* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
	if (!typeCheck(type.get(), node->index.get())) {
		CErrorTable::AddError("Array index not integer");
	}
	waitingNodes.push_front(node->index.get());
	waitingNodes.push_front(node->caller.get());
}

void CTypeChecker::visit(CCallExpression* node)
{
	if (!callerCheck(node->caller.get(), node->function.get(), node->list.get())) {
		CErrorTable::AddError("Suitable function not found");
	}
	waitingNodes.push_front(node->caller.get());
}

void CTypeChecker::visit(CNewArrayExpression* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
	if (!typeCheck(type.get(), node->expression.get())) {
		CErrorTable::AddError("Array size not integer");
	}
	waitingNodes.push_front(node->expression.get());
}

void CTypeChecker::visit(CNewExpression* node)
{
	const CClassInfo* info = CSymbolTable::FindClass(tableName, CSymbol::GetSymbol(node->id->name));
	if (info == nullptr) {
		CErrorTable::AddError("Unknown class " + node->id->name);
	}
}

void CTypeChecker::visit(CNotExpression* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Boolean));
	if (!typeCheck(type.get(), node->expression.get())) {
		CErrorTable::AddError("Expression is not boolean");
	}
	waitingNodes.push_front(node->expression.get());
}

void CTypeChecker::visit(CBracketsExpression* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CTypeChecker::visit(CFunction* node)
{
	createLeaveFunctionPlaceholder();
	currentFunctionName = node->name->name;
	if (!typeCheck(node->returns.get(), node->returnExpression.get())) {
		typeCheck(node->returns.get(), node->returnExpression.get());
		CErrorTable::AddError("Return expression has different type");
	}
	waitingNodes.push_front(node->body.get());
	waitingNodes.push_front(node->arguments.get());
}

void CTypeChecker::visit(CMainFunction* node)
{
	waitingNodes.push_front(node->body.get());
}

void CTypeChecker::visit(CMain* node)
{
	waitingNodes.push_front(node->mainFunction.get());
}

void CTypeChecker::visit(CProgram* node)
{
	waitingNodes.push_front(node->classes.get());
	waitingNodes.push_front(node->main.get());
}

void CTypeChecker::visit(IStatement *)
{
	assert(false);
}

void CTypeChecker::visit(CStatementList* node)
{
	for (int i = 0; i < node->statements.size(); i++) {
		waitingNodes.push_front(node->statements[i].get());
	}
}

void CTypeChecker::visit(CIfStatement* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
	if (!typeCheck(type.get(), node->condition.get())) {
		CErrorTable::AddError("Condition not integer");
	}
	waitingNodes.push_front(node->elseStatement.get());
	waitingNodes.push_front(node->thenStatement.get());
	waitingNodes.push_front(node->condition.get());
}

void CTypeChecker::visit(CWhileStatement* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
	if (!typeCheck(type.get(), node->condition.get())) {
		CErrorTable::AddError("Condition not integer");
	}
	waitingNodes.push_front(node->statement.get());
	waitingNodes.push_front(node->condition.get());
}

void CTypeChecker::visit(CPrintStatement* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CTypeChecker::visit(CAssignStatement* node)
{
	if (!typeCheck(node->left.get(), node->right.get())) {
		typeCheck(node->left.get(), node->right.get());
		CErrorTable::AddError("Assigment types mismatch");
	}
	waitingNodes.push_front(node->right.get());
	waitingNodes.push_front(node->left.get());
}

void CTypeChecker::visit(CVariableStatement* node)
{
	waitingNodes.push_front(node->variable.get());
}

void CTypeChecker::visit(CVariable* node)
{
	if (node->type->type == DT_Instance) {
		const CClassInfo* info = CSymbolTable::FindClass(tableName, CSymbol::GetSymbol(node->type->instance));
		if (info == nullptr) {
			CErrorTable::AddError("Class not found: " + node->type->instance);
		}
	}
}

void CTypeChecker::visit(CFunctionVisibilityEnd*)
{
	currentFunctionName = "";
	blocksEntered = 0;
	blocksLeft = 0;
}

void CTypeChecker::visit(CClassVisibilityEnd*)
{
	currentFunctionName = "";
	currentClassName = "";
}

void CTypeChecker::visit(CVisibilityBlockStart*)
{
	blocksEntered++;
}

void CTypeChecker::visit(CVisibilityBlockEnd*)
{
	blocksLeft++;
}

bool CTypeChecker::typeCheck(IExpression* left, IExpression* right)
{
	CTypeGetter getter;
	std::shared_ptr<CType> leftType = getter.GetType(left, tableName, currentClassName, currentFunctionName,
		blocksEntered, blocksLeft);

	if (leftType == nullptr) {
		return false;
	}

	return typeCheck(leftType.get(), right);
}

bool CTypeChecker::typeCheck(CType* type, IExpression* node)
{
	CTypeGetter getter;
	std::shared_ptr<CType> nodeType = getter.GetType(node, tableName, currentClassName, currentFunctionName,
		blocksEntered, blocksLeft);

	if (nodeType == nullptr) {
		return false;
	}

	if (type->type != nodeType->type) {
		if (type->type == DT_Integer && nodeType->type == DT_Boolean) {
			return true;
		}
		return false;
	}
	if (type->instance != nodeType->instance) {
		return false;
	}
	return true;
}

bool CTypeChecker::notVoidCheck(IExpression* node)
{
	CTypeGetter getter;
	std::shared_ptr<CType> nodeType = getter.GetType(node, tableName, currentClassName, currentFunctionName,
		blocksEntered, blocksLeft);
	if (nodeType->type == DT_Void) {
		return false;
	}
}

bool CTypeChecker::callerCheck(CId* caller, CId* function, CArgumentList* list)
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
		return false;
	}
}

bool CTypeChecker::argumentCheck(const CFunctionInfo* info, std::vector<CType*>& arguments)
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

void CTypeChecker::cleanup()
{
	placeholders.clear();
}

void CTypeChecker::createLeaveClassPlaceholder()
{
	std::shared_ptr<ITree> placeholder(new CClassVisibilityEnd());
	placeholders.push_back(placeholder);
	waitingNodes.push_front(placeholder.get());
}

void CTypeChecker::createLeaveFunctionPlaceholder()
{
	std::shared_ptr<ITree> placeholder(new CFunctionVisibilityEnd());
	placeholders.push_back(placeholder);
	waitingNodes.push_front(placeholder.get());
}
