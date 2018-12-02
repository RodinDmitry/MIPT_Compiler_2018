#include <PrettyPrinter.h>

static int LastId = 0;

void CPrettyPrinter::visitIfNotNull(ITree* node, std::string currentNode) {
	if (node != nullptr) {
		output << currentNode << " -- " << nodes.front() << std::endl;
		nodes.pop_front();
	}
}

void CPrettyPrinter::visitIfNotNull(ITree* node, std::string currentNode, std::string adding)
{
	if (node != nullptr) {
		node->AddToLabel(adding);
		output << currentNode << " -- " << nodes.front() << std::endl;
		nodes.pop_front();
	}
}

CPrettyPrinter::CPrettyPrinter(std::string name) {
	output.open(name, std::ofstream::out);
	output << "strict graph {" << std::endl;
}

void CPrettyPrinter::close()
{
	for (auto label : labels) {
		output << label.first << " [ label = \"" << label.second->GetLabel() << "\"]" << std::endl;
	}
	output << "}" << std::endl;
}

void CPrettyPrinter::visit(CClassDeclaration* node)
{
	std::string name = "classDeclaration" + std::to_string(LastId++);
	visitIfNotNull(node->name.get(), name);
	visitIfNotNull(node->extend.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CNotExpression* node)
{
	std::string name = "not_expression" + std::to_string(LastId++);
	visitIfNotNull(node->expression.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CBracketsExpression* node)
{
	std::string name = "brackets" + std::to_string(LastId++);
	visitIfNotNull(node->expression.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CReturnExpression* node)
{
	std::string name = "return" + std::to_string(LastId++);
	visitIfNotNull(node->expression.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CFunction* node)
{
	std::string name = "Function" + std::to_string(LastId++);
	visitIfNotNull(node->visibility.get(), name);
	visitIfNotNull(node->name.get(), name);
	visitIfNotNull(node->arguments.get(), name);
	visitIfNotNull(node->body.get(), name);
	visitIfNotNull(node->returns.get(), name);
	visitIfNotNull(node->returnExpression.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CId* node)
{
	std::string name = "id_" + node->name + "_" + std::to_string(LastId++);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CMainArgument* node)
{
	std::string name = "mainArguments" + std::to_string(LastId++);
	visitIfNotNull(node->name.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CMainFunction* node)
{
	std::string name = "mainFunction" + std::to_string(LastId++);
	visitIfNotNull(node->argument.get(), name);
	visitIfNotNull(node->body.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CMain* node)
{
	std::string name = "main" + std::to_string(LastId++);
	visitIfNotNull(node->name.get(), name);
	visitIfNotNull(node->mainFunction.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CModifier* node)
{
	std::string name = "modifier" + std::to_string(LastId++);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CProgram* node)
{
	std::string name = "program" + std::to_string(LastId++);
	visitIfNotNull(node->main.get(), name);
	visitIfNotNull(node->classes.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(IStatement*)
{
	output << "dynamic_cast failed" << std::endl;
}

void CPrettyPrinter::visit(CStatementList* node)
{
	std::string name = "statements" + std::to_string(LastId++);

	for (int i = 0; i < node->statements.size(); i++) {
		visitIfNotNull(node->statements[i].get(), name);
	}

	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CVisibilityStatement* node)
{
	std::string name = "visibility" + std::to_string(LastId++);
	visitIfNotNull(node->statement.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CIfStatement* node)
{
	std::string name = "if" + std::to_string(LastId++);
	visitIfNotNull(node->condition.get(), name, " (condition)");
	visitIfNotNull(node->thenStatement.get(), name, " (then)");
	visitIfNotNull(node->elseStatement.get(), name, " (else)");
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CWhileStatement* node)
{
	std::string name = "while" + std::to_string(LastId++);
	visitIfNotNull(node->condition.get(), name, " (condition)");
	visitIfNotNull(node->statement.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CPrintStatement* node)
{
	std::string name = "print" + std::to_string(LastId++);
	visitIfNotNull(node->expression.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CAssignStatement* node)
{
	std::string name = "assignStatement" + std::to_string(LastId++);
	visitIfNotNull(node->left.get(), name);
	visitIfNotNull(node->right.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CVariableStatement* node)
{
	std::string name = "varStatement" + std::to_string(LastId++);
	visitIfNotNull(node->variable.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CType* node)
{
	std::string name = "type" + std::to_string(LastId++);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(IValue* node)
{
	output << "dynamic_cast failed" << std::endl;
}

void CPrettyPrinter::visit(CValue* node)
{
	std::string name = "value" + std::to_string(LastId++);
	switch (node->type) {
	case node->T_Integer:
		name = "Integer_" + name;
		break;
	case node->T_Boolean:
		name = "Boolean_" + name;
		break;
	}
	name = "_" + std::to_string(node->value) + name;
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CVariable* node)
{
	std::string name = "var" + std::to_string(LastId++);
	visitIfNotNull(node->type.get(), name);
	visitIfNotNull(node->name.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(ITree*)
{
	output << "dynamic_cast failed" << std::endl;
}

void CPrettyPrinter::visit(CArgumentList* node)
{
	std::string name = "arguments" + std::to_string(LastId++);

	for (int i = 0; i < node->arguments.size(); i++) {
		visitIfNotNull(node->arguments[i].get(), name);
	}

	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CClassInternals* node)
{
	std::string name = "classInternal" + std::to_string(LastId++);
	visitIfNotNull(node->function.get(), name);
	visitIfNotNull(node->variable.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CClassInternalsList* node)
{
	std::string name = "classInternals" + std::to_string(LastId++);

	for (int i = 0; i < node->internals.size(); i++) {
		visitIfNotNull(node->internals[i].get(), name);
	}

	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CClass* node)
{
	std::string name = "class" + std::to_string(LastId++);
	visitIfNotNull(node->declaration.get(), name);
	visitIfNotNull(node->internals.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CClassList* node)
{
	std::string name = "classes" + std::to_string(LastId++);

	for (int i = 0; i < node->classes.size(); i++) {
		visitIfNotNull(node->classes[i].get(), name);
	}

	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(IExpression*)
{
	output << "dynamic_cast failed" << std::endl;
}

void CPrettyPrinter::visit(CExpressionList* node)
{
	std::string name = "expressions" + std::to_string(LastId++);

	for (int i = 0; i < node->expressions.size(); i++) {
		visitIfNotNull(node->expressions[i].get(), name);
	}

	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CLValueExpression* node)
{
	std::string name = "lvalue" + std::to_string(LastId++);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CBinaryExpression * node)
{
	std::string name = "binaryOperator" + std::to_string(LastId++);
	visitIfNotNull(node->left.get(), name);
	visitIfNotNull(node->right.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CArrayExpression * node)
{
	std::string name = "arrayExpr" + std::to_string(LastId++);
	visitIfNotNull(node->caller.get(), name);
	visitIfNotNull(node->index.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CCallExpression* node)
{
	std::string name = "callExpr" + std::to_string(LastId++);
	visitIfNotNull(node->caller.get(), name);
	visitIfNotNull(node->function.get(), name);
	visitIfNotNull(node->list.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CValueExpression* node)
{
	std::string name = "valueExpr" + std::to_string(LastId++);
	visitIfNotNull(node->value.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CNewArrayExpression* node)
{
	std::string name = "newArray" + std::to_string(LastId++);
	visitIfNotNull(node->expression.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CNewExpression* node)
{
	std::string name = "newExpression" + std::to_string(LastId++);
	visitIfNotNull(node->id.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CIdExpression* node)
{
	std::string name = "idExpression" + std::to_string(LastId++);
	visitIfNotNull(node->id.get(), name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, node));
}

void CPrettyPrinter::visit(CThisExpression * thisExpr)
{
	std::string name = "thisExpression" + std::to_string(LastId++);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, thisExpr));
}
