#include <TypeChecker.h>
#include <TypeGetter.h>
#include <ErrorTable.h>

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
	typeCheck(node->left.get(), node->right.get());
	waitingNodes.push_front(node->right.get());
	waitingNodes.push_front(node->left.get());
}

void CTypeChecker::visit(CArrayExpression* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
	typeCheck(type.get(), node->index.get());
	waitingNodes.push_front(node->index.get());
	waitingNodes.push_front(node->caller.get());
}

void CTypeChecker::visit(CCallExpression* node)
{
	callerCheck(node->caller.get(), node->function.get(), node->list.get());
	waitingNodes.push_front(node->caller.get());
}

void CTypeChecker::visit(CNewArrayExpression* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
	typeCheck(type.get(), node->expression.get());
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
	typeCheck(type.get(), node->expression.get());
	waitingNodes.push_front(node->expression.get());
}

void CTypeChecker::visit(CBracketsExpression* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CTypeChecker::visit(CFunction* node)
{
	typeCheck(node->returns.get(), node->returnExpression.get());
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
	std::shared_ptr<CType> type(new CType(TDataType::DT_Boolean));
	typeCheck(type.get(), node->condition.get());
	waitingNodes.push_front(node->elseStatement.get());
	waitingNodes.push_front(node->thenStatement.get());
	waitingNodes.push_front(node->condition.get());
}

void CTypeChecker::visit(CWhileStatement* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Boolean));
	typeCheck(type.get(), node->condition.get());
	waitingNodes.push_front(node->statement.get());
	waitingNodes.push_front(node->condition.get());
}

void CTypeChecker::visit(CPrintStatement* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CTypeChecker::visit(CAssignStatement* node)
{
	typeCheck(node->left.get(), node->right.get());
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

void CTypeChecker::typeCheck(IExpression* left, IExpression* right)
{
	CTypeGetter getter;
	std::shared_ptr<CType> leftType = getter.GetType(left, tableName);
	typeCheck(leftType.get(), right);
}

void CTypeChecker::typeCheck(CType* type, IExpression* node)
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

void CTypeChecker::notVoidCheck(IExpression* node)
{
	CTypeGetter getter;
	std::shared_ptr<CType> nodeType = getter.GetType(node, tableName);
	if (nodeType->type == DT_Void) {
		CErrorTable::AddError("Type check failed");
	}
}

void CTypeChecker::callerCheck(CId* caller, CId* function, CArgumentList* list)
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