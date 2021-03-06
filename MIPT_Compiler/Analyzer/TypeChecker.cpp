#include <TypeChecker.h>
#include <TypeGetter.h>
#include <ErrorTable.h>

void CTypeChecker::CheckTypes(ITree* startNode, const std::string& _tableName)
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
	const CClassInfo* info = CSymbolTable::FindClass(tableName, CSymbol::GetSymbol(currentClassName));
	if (info->HasCyclicInheritance(tableName)) {
		CErrorTable::AddError(CErrorTable::CyclicInheritance, node->GetLine());
	}

	if (info->InheritedFromKnownClass(tableName)) {
		CErrorTable::AddError(CErrorTable::CyclicInheritance, node->GetLine());
	}

	waitingNodes.push_front(node->internals.get());
}

void CTypeChecker::visit(CClassList* node)
{
	for (int i = static_cast<int>(node->classes.size()) - 1; i >= 0; i--) {
		waitingNodes.push_front(node->classes[i].get());
	}
}

void CTypeChecker::visit(CExpressionList* node)
{
	for (int i = static_cast<int>(node->expressions.size()) - 1; i >= 0; i--) {
		waitingNodes.push_front(node->expressions[i].get());
	}
}

void CTypeChecker::visit(CBinaryExpression* node)
{
	if (!typeCheck(node->left.get(), node->right.get())) {
		CErrorTable::AddError(CErrorTable::TypeCheckFailed, node->GetLine());
	}
	waitingNodes.push_front(node->right.get());
	waitingNodes.push_front(node->left.get());
}

void CTypeChecker::visit(CArrayExpression* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
	if (!typeCheck(type.get(), node->index.get())) {
		CErrorTable::AddError(CErrorTable::WrongIndex, node->GetLine());
	}
	waitingNodes.push_front(node->index.get());
	waitingNodes.push_front(node->caller.get());
}

void CTypeChecker::visit(CCallExpression* node)
{
	if (!callerCheck(node->caller.get(), node->function.get(), node->list.get())) {
		CErrorTable::AddError(CErrorTable::UnknownFunction + node->function->name, node->GetLine());
	}
	waitingNodes.push_front(node->caller.get());
}

void CTypeChecker::visit(CCallLengthExpression* node)
{
	CTypeGetter getter;
	auto callerType = getter.GetType(node->caller.get(), tableName, currentClassName, currentFunctionName, blocksEntered, blocksLeft);
	if (callerType->type != DT_IntegerArray) {
		CErrorTable::AddError(CErrorTable::ExpectedArray, node->GetLine());
	}
	waitingNodes.push_front(node->caller.get());
}

void CTypeChecker::visit(CNewArrayExpression* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
	if (!typeCheck(type.get(), node->expression.get())) {
		CErrorTable::AddError(CErrorTable::WrongIndex, node->GetLine());
	}
	waitingNodes.push_front(node->expression.get());
}

void CTypeChecker::visit(CNewExpression* node)
{
	const CClassInfo* info = CSymbolTable::FindClass(tableName, CSymbol::GetSymbol(node->id->name));
	if (info == nullptr) {
		CErrorTable::AddError(CErrorTable::UnknownClass + node->id->name, node->GetLine());
	}
}

void CTypeChecker::visit(CNotExpression* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Boolean));
	if (!typeCheck(type.get(), node->expression.get())) {
		typeCheck(type.get(), node->expression.get());
		CErrorTable::AddError(CErrorTable::ExpectedBoolean, node->GetLine());
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
	if (!typeCheck(node->returns.get(), node->returnExpression->expression.get())) {
		typeCheck(node->returns.get(), node->returnExpression->expression.get());
		CErrorTable::AddError(CErrorTable::ReturnTypeMismatch, node->GetLine());
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

void CTypeChecker::visit(CVisibilityStatement* node)
{
	waitingNodes.push_front(node->statement.get());
}

void CTypeChecker::visit(CIfStatement* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Boolean));
	if (!typeCheck(type.get(), node->condition.get())) {
		CErrorTable::AddError(CErrorTable::ExpectedBoolean, node->GetLine());
	}
	waitingNodes.push_front(node->elseStatement.get());
	waitingNodes.push_front(node->thenStatement.get());
	waitingNodes.push_front(node->condition.get());
}

void CTypeChecker::visit(CWhileStatement* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Boolean));
	if (!typeCheck(type.get(), node->condition.get())) {
		CErrorTable::AddError(CErrorTable::ExpectedBoolean, node->GetLine());
	}
	waitingNodes.push_front(node->statement.get());
	waitingNodes.push_front(node->condition.get());
}

void CTypeChecker::visit(CPrintStatement* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
	std::shared_ptr<CType> arrayType(new CType(TDataType::DT_IntegerArray));
	if (!typeCheck(type.get(), node->expression.get()) && !typeCheck(arrayType.get(), node->expression.get())) {
		CErrorTable::AddError(CErrorTable::InvalidPrint, node->GetLine());
	}
	waitingNodes.push_front(node->expression.get());
}

void CTypeChecker::visit(CAssignStatement* node)
{
	if (!typeCheck(node->left.get(), node->right.get())) {
		typeCheck(node->left.get(), node->right.get());
		CErrorTable::AddError(CErrorTable::TypeCheckFailed, node->GetLine());
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
			CErrorTable::AddError(CErrorTable::UnknownClass + node->type->instance, node->GetLine());
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
	return true;
}

bool CTypeChecker::callerCheck(IExpression* caller, CId* function, CExpressionList* list)
{
	CTypeGetter getter;
	auto callerType = getter.GetType(caller, tableName, currentClassName, currentFunctionName, blocksEntered, blocksLeft);
	if (callerType->type != DT_Instance) {
		return false;
	}

	const CClassInfo* classInfo = CSymbolTable::FindClass(tableName, CSymbol::GetSymbol(callerType->instance));
	if (classInfo == nullptr) {
		return false;
	}

	const std::vector<std::unique_ptr<const CFunctionInfo>>& methods = classInfo->GetMethods();

	std::vector<std::shared_ptr<CType>> arguments;
	for (int i = 0; i < list->expressions.size(); i++) {
		std::shared_ptr<CType> type = getter.GetType(list->expressions[i].get(), tableName, currentClassName,
			currentFunctionName, blocksEntered, blocksLeft);
		arguments.push_back(type);
	}

	bool hasCompatibleMethod = false;
	for (int i = 0; i < methods.size(); i++) {
		if (methods[i]->String()->String() == function->name) {
			if (argumentCheck(methods[i].get(), arguments)) {
				hasCompatibleMethod = true;
			}
		}
	}
	if (!hasCompatibleMethod) {
		return false;
	}
	return true;
}

bool CTypeChecker::argumentCheck(const CFunctionInfo* info, std::vector<std::shared_ptr<CType>>& arguments)
{
	const std::vector<std::unique_ptr<const CVariableInfo> >& variables = info->GetArguments();
	if (arguments.size() != variables.size()) {
		return false;
	}
	for (int i = 0; i < arguments.size(); i++) {
		std::shared_ptr<CType> variableType = variables[i]->GetType();
		if (variableType->type != arguments[i]->type || variableType->instance != arguments[i]->instance) {
			if (variableType->type == DT_Instance && arguments[i]->type == DT_Instance
				&& CSymbolTable::IsDerived(tableName, arguments[i]->instance, variableType->instance)) {
				continue;
			}
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
