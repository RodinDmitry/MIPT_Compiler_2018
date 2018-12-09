#include <StackBuilder.h>

void CStackBuilder::BuildStack(ITree* tree)
{
	waitingNodes.push_back(tree);
	while (waitingNodes.size() > 0) {
		ITree* current = waitingNodes.front();
		waitingNodes.pop_front();
		current->Accept(this);

		nodesStack.push_back(current);
	}
}

void CStackBuilder::visit(ITree* node)
{
	throw std::exception();
}

void CStackBuilder::visit(CArgumentList* node)
{
	for (int i = node->arguments.size() - 1; i >= 0 ; i--) {
		addIfNotNull(node->arguments[i].get());
	}
}

void CStackBuilder::visit(CClassDeclaration* node)
{
	addIfNotNull(node->extend.get());
	addIfNotNull(node->name.get());
}

void CStackBuilder::visit(CClassInternals* node)
{
	addIfNotNull(node->variable.get());
	addIfNotNull(node->function.get());
}

void CStackBuilder::visit(CClassInternalsList* node)
{
	for (int i = node->internals.size() - 1; i >= 0; i--) {
		addIfNotNull(node->internals[i].get());
	}
}

void CStackBuilder::visit(CClass* node)
{
	addIfNotNull(node->internals.get());
	addIfNotNull(node->declaration.get());
}

void CStackBuilder::visit(CClassList* node)
{
	for (int i = node->classes.size() - 1; i >= 0 ; i--) {
		addIfNotNull(node->classes[i].get());
	}
}

void CStackBuilder::visit(IExpression* node)
{
	assert(false);
}

void CStackBuilder::visit(CExpressionList* node)
{
	for (int i = node->expressions.size() - 1; i >= 0; i--) {
		addIfNotNull(node->expressions[i].get());
	}
}

void CStackBuilder::visit(CLValueExpression*)
{
}

void CStackBuilder::visit(CBinaryExpression* node)
{
	addIfNotNull(node->right.get());
	addIfNotNull(node->left.get());
}

void CStackBuilder::visit(CArrayExpression* node)
{
	addIfNotNull(node->index.get());
	addIfNotNull(node->caller.get());
}

void CStackBuilder::visit(CCallExpression* node)
{
	addIfNotNull(node->list.get());
	addIfNotNull(node->function.get());
	addIfNotNull(node->caller.get());
}

void CStackBuilder::visit(CValueExpression* node)
{
	addIfNotNull(node->value.get());
}

void CStackBuilder::visit(CNewArrayExpression* node)
{
	addIfNotNull(node->expression.get());
}

void CStackBuilder::visit(CNewExpression* node)
{
	addIfNotNull(node->id.get());
}

void CStackBuilder::visit(CIdExpression* node)
{
	addIfNotNull(node->id.get());
}

void CStackBuilder::visit(CThisExpression*)
{
}

void CStackBuilder::visit(CNotExpression* node)
{
	addIfNotNull(node->expression.get());
}

void CStackBuilder::visit(CBracketsExpression* node)
{
	addIfNotNull(node->expression.get());
}

void CStackBuilder::visit(CReturnExpression* node)
{
	addIfNotNull(node->expression.get());
}

void CStackBuilder::visit(CFunction* node)
{
	addIfNotNull(node->returnExpression.get());
	addIfNotNull(node->returns.get());
	addIfNotNull(node->body.get());
	addIfNotNull(node->arguments.get());
	addIfNotNull(node->name.get());
	addIfNotNull(node->visibility.get());
}

void CStackBuilder::visit(CId*)
{
}

void CStackBuilder::visit(CMainArgument* node)
{
	addIfNotNull(node->name.get());
}

void CStackBuilder::visit(CMainFunction* node)
{
	addIfNotNull(node->body.get());
	addIfNotNull(node->argument.get());
}

void CStackBuilder::visit(CMain* node)
{
	addIfNotNull(node->mainFunction.get());
	addIfNotNull(node->name.get());
}

void CStackBuilder::visit(CModifier*)
{
}

void CStackBuilder::visit(CProgram* node)
{
	addIfNotNull(node->classes.get());
	addIfNotNull(node->main.get());
}

void CStackBuilder::visit(IStatement*)
{
	throw std::exception();
}

void CStackBuilder::visit(CStatementList* node)
{
	for (int i = node->statements.size() - 1; i >= 0; i--) {
		addIfNotNull(node->statements[i].get());
	}
}

void CStackBuilder::visit(CVisibilityStatement* node)
{
	addIfNotNull(node->statement.get());
}

void CStackBuilder::visit(CIfStatement* node)
{
	addIfNotNull(node->elseStatement.get());
	addIfNotNull(node->thenStatement.get());
	addIfNotNull(node->condition.get());
}

void CStackBuilder::visit(CWhileStatement* node)
{
	addIfNotNull(node->statement.get());
	addIfNotNull(node->condition.get());
}

void CStackBuilder::visit(CPrintStatement* node)
{
	addIfNotNull(node->expression.get());
}

void CStackBuilder::visit(CAssignStatement* node)
{
	addIfNotNull(node->right.get());
	addIfNotNull(node->left.get());
}

void CStackBuilder::visit(CVariableStatement* node)
{
	addIfNotNull(node->variable.get());
}

void CStackBuilder::visit(CType*)
{
}

void CStackBuilder::visit(IValue*)
{
	throw std::exception();
}

void CStackBuilder::visit(CValue*)
{
}

void CStackBuilder::visit(CVariable* node)
{
	addIfNotNull(node->type.get());
	addIfNotNull(node->name.get());
}

void CStackBuilder::addIfNotNull(ITree* node)
{
	if (node != nullptr) {
		waitingNodes.push_front(node);
	}
}
