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
	for (int i = 0; i < node->arguments.size(); i++) {
		addIfNotNull(node->arguments[i].get());
	}
}

void CStackBuilder::visit(CClassDeclaration* node)
{
	addIfNotNull(node->name.get());
	addIfNotNull(node->extend.get());
}

void CStackBuilder::visit(CClassInternals* node)
{
	addIfNotNull(node->function.get());
	addIfNotNull(node->variable.get());
}

void CStackBuilder::visit(CClassInternalsList* node)
{
	for (int i = 0; i < node->internals.size(); i++) {
		addIfNotNull(node->internals[i].get());
	}

}

void CStackBuilder::visit(CClass* node)
{
	addIfNotNull(node->declaration.get());
	addIfNotNull(node->internals.get());
}

void CStackBuilder::visit(CClassList* node)
{
	for (int i = 0; i < node->classes.size(); i++) {
		addIfNotNull(node->classes[i].get());
	}
}

void CStackBuilder::visit(IExpression* node)
{
	throw std::exception();
}

void CStackBuilder::visit(CExpressionList* node)
{
	for (int i = 0; i < node->expressions.size(); i++) {
		addIfNotNull(node->expressions[i].get());
	}
}

void CStackBuilder::visit(CLValueExpression*)
{
}

void CStackBuilder::visit(CBinaryExpression* node)
{
	addIfNotNull(node->left.get());
	addIfNotNull(node->right.get());
}

void CStackBuilder::visit(CArrayExpression* node)
{
	addIfNotNull(node->caller.get());
	addIfNotNull(node->index.get());
}

void CStackBuilder::visit(CCallExpression* node)
{
	addIfNotNull(node->caller.get());
	addIfNotNull(node->function.get());
	addIfNotNull(node->list.get());
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
	addIfNotNull(node->visibility.get());
	addIfNotNull(node->name.get());
	addIfNotNull(node->arguments.get());
	addIfNotNull(node->body.get());
	addIfNotNull(node->returns.get());
	addIfNotNull(node->returnExpression.get());
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
	addIfNotNull(node->argument.get());
	addIfNotNull(node->body.get());
}

void CStackBuilder::visit(CMain* node)
{
	addIfNotNull(node->name.get());
	addIfNotNull(node->mainFunction.get());
}

void CStackBuilder::visit(CModifier*)
{
}

void CStackBuilder::visit(CProgram* node)
{
	addIfNotNull(node->main.get());
	addIfNotNull(node->classes.get());
}

void CStackBuilder::visit(IStatement*)
{
	throw std::exception();
}

void CStackBuilder::visit(CStatementList* node)
{
	for (int i = 0; i < node->statements.size(); i++) {
		addIfNotNull(node->statements[i].get());
	}
}

void CStackBuilder::visit(CVisibilityStatement* node)
{
	addIfNotNull(node->statement.get());
}

void CStackBuilder::visit(CIfStatement* node)
{
	addIfNotNull(node->condition.get());
	addIfNotNull(node->thenStatement.get());
	addIfNotNull(node->elseStatement.get());
}

void CStackBuilder::visit(CWhileStatement* node)
{
	addIfNotNull(node->condition.get());
	addIfNotNull(node->statement.get());
}

void CStackBuilder::visit(CPrintStatement* node)
{
	addIfNotNull(node->expression.get());
}

void CStackBuilder::visit(CEqualStatement* node)
{
	addIfNotNull(node->left.get());
	addIfNotNull(node->right.get());
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
	addIfNotNull(node->name.get());
	addIfNotNull(node->type.get());
}

void CStackBuilder::addIfNotNull(ITree* node)
{
	if (node != nullptr) {
		waitingNodes.push_front(node);
	}
}
