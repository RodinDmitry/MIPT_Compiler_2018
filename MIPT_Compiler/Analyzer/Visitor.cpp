#include <Visitor.h>

static int lastId = 0;
std::set< ITree* > printerSet;
std::deque< ITree* > printerStack;

void CPrettyPrinter::visitIfNotNull(ITree* node, std::string currentNode) {
	if (node != nullptr) {
		output << currentNode << " -- " << nodes.front() << std::endl;
		nodes.pop_front();
		printerSet.erase(node);
	}
}

void CPrettyPrinter::visitIfNotNull(ITree * node, std::string currentNode, std::string adding)
{
	if (node != nullptr) {
		node->AddToLabel(adding);
		output << currentNode << " -- " << nodes.front() << std::endl;
		nodes.pop_front();
		printerSet.erase(node);
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

void CPrettyPrinter::visit(CClassDeclaration * cldecl)
{
	std::string name = "classDeclaration" + std::to_string(lastId++);
	visitIfNotNull(cldecl->name, name);
	visitIfNotNull(cldecl->extend, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cldecl));
}

void CPrettyPrinter::visit(CNotExpression * cnotexpr)
{
	std::string name = "not_expression" + std::to_string(lastId++);
	visitIfNotNull(cnotexpr->expression, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cnotexpr));
}

void CPrettyPrinter::visit(CBracketsExpression * cbrexpr) 
{
	std::string name = "brackets" + std::to_string(lastId++);
	visitIfNotNull(cbrexpr->expression, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cbrexpr));
}

void CPrettyPrinter::visit(CReturnExpression * cretexpr) 
{
	std::string name = "return" + std::to_string(lastId++);
	visitIfNotNull(cretexpr->expression, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cretexpr));
}

void CPrettyPrinter::visit(CFunction * cfunc) 
{
	std::string name = "Function" + std::to_string(lastId++);
	visitIfNotNull(cfunc->visibility, name);
	visitIfNotNull(cfunc->name, name);
	visitIfNotNull(cfunc->arguments, name);
	visitIfNotNull(cfunc->body, name);
	visitIfNotNull(cfunc->returns, name);
	visitIfNotNull(cfunc->returnExpression, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cfunc));
}

void CPrettyPrinter::visit(CId * cid) 
{
	std::string name = "id_" + cid->name + "_" + std::to_string(lastId++);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cid));
}

void CPrettyPrinter::visit(CMainArgument * cmainrg) 
{
	std::string name = "mainArguments" + std::to_string(lastId++);
	visitIfNotNull(cmainrg->name, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cmainrg));
}

void CPrettyPrinter::visit(CMainFunction * cmainfunc) 
{
	std::string name = "mainFunction" + std::to_string(lastId++);
	visitIfNotNull(cmainfunc->argument, name);
	visitIfNotNull(cmainfunc->body, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cmainfunc));
}

void CPrettyPrinter::visit(CMain * cmain)
{
	std::string name = "main" + std::to_string(lastId++);
	visitIfNotNull(cmain->name, name);
	visitIfNotNull(cmain->mainFunction, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cmain));
}

void CPrettyPrinter::visit(CModifier * cmod)
{
	std::string name = "modifier" + std::to_string(lastId++);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cmod));
}

void CPrettyPrinter::visit(CProgram * cprogr)
{
	std::string name = "program" + std::to_string(lastId++);
	visitIfNotNull(cprogr->main, name);
	visitIfNotNull(cprogr->classes, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cprogr));
}

void CPrettyPrinter::visit(IStatement * istat)
{
	output << "dynamic_cast failed" << std::endl;
}

void CPrettyPrinter::visit(CStatementList * cstatlist)
{
	std::string name = "statements" + std::to_string(lastId++);
	for (auto* statement : cstatlist->statements) {
		visitIfNotNull(statement, name);
	}

	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cstatlist));
}

void CPrettyPrinter::visit(CVisibilityStatement * cvisstat)
{
	std::string name = "visibility" + std::to_string(lastId++);
	visitIfNotNull(cvisstat->statement, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cvisstat));
}

void CPrettyPrinter::visit(CIfStatement * cifstat)
{
	std::string name = "if" + std::to_string(lastId++);
	visitIfNotNull(cifstat->condition, name, " (condition)");
	visitIfNotNull(cifstat->thenStatement, name, " (then)");
	visitIfNotNull(cifstat->elseStatement, name, " (else)");
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cifstat));
}

void CPrettyPrinter::visit(CWhileStatement * cwhstat)
{
	std::string name = "while" + std::to_string(lastId++);
	visitIfNotNull(cwhstat->condition, name, " (condition)");
	visitIfNotNull(cwhstat->statement, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cwhstat));
}

void CPrettyPrinter::visit(CPrintStatement * cprintstat)
{
	std::string name = "print" + std::to_string(lastId++);
	visitIfNotNull(cprintstat->expression, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cprintstat));
}

void CPrettyPrinter::visit(CEqualStatement * ceqstat)
{
	std::string name = "assignStatement" + std::to_string(lastId++);
	visitIfNotNull(ceqstat->left, name);
	visitIfNotNull(ceqstat->right, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, ceqstat));
}

void CPrettyPrinter::visit(CVariableStatement * cvarstat)
{
	std::string name = "varStatement" + std::to_string(lastId++);
	visitIfNotNull(cvarstat->variable, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cvarstat));
}

void CPrettyPrinter::visit(CType * ctype)
{
	std::string name = "type" + std::to_string(lastId++);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, ctype));
}

void CPrettyPrinter::visit(IValue * ival)
{
	output << "dynamic_cast failed" << std::endl;
}

void CPrettyPrinter::visit(CValue * cval)
{
	std::string name = "value" + std::to_string(lastId++);
	switch (cval->type) {
		case cval->T_Integer: 
			name = "Integer_" + name;
			break;
		case cval->T_Boolean: 
			name = "Boolean_" + name;
			break;
	}
	name = "_" + std::to_string(cval->value) + name;
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cval));
}

void CPrettyPrinter::visit(CVariable * cvar)
{
	std::string name = "var" + std::to_string(lastId++);
	visitIfNotNull(cvar->type, name);
	visitIfNotNull(cvar->name, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cvar));
}

void CPrettyPrinter::visit(ITree *)
{
	output << "dynamic_cast failed" << std::endl;
}

void CPrettyPrinter::visit(CArgumentList *argList)
{
	std::string name = "arguments" + std::to_string(lastId++);
	for (CVariable* arg : argList->arguments) {
		visitIfNotNull(argList, name);
	}
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, argList));
}

void CPrettyPrinter::visit(CClassInternals * clInter)
{
	std::string name = "classInternal" + std::to_string(lastId++);
	visitIfNotNull(clInter->function, name);
	visitIfNotNull(clInter->variable, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, clInter));
}

void CPrettyPrinter::visit(CClassInternalsList * clInterList)
{
	std::string name = "classInternals" + std::to_string(lastId++);
	for (CClassInternals* clInt : clInterList->internals) {
		visitIfNotNull(clInt, name);
	}
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, clInterList));
}

void CPrettyPrinter::visit(CClass * cclass)
{
	std::string name = "class" + std::to_string(lastId++);
	visitIfNotNull(cclass->declaration, name);
	visitIfNotNull(cclass->internals, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, cclass));
}

void CPrettyPrinter::visit(CClassList * clList)
{
	std::string name = "classes" + std::to_string(lastId++);
	for (CClass* cclass : clList->classes) {
		visitIfNotNull(cclass, name);
	}
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, clList));
}

void CPrettyPrinter::visit(IExpression *)
{
	output << "dynamic_cast failed" << std::endl;
}

void CPrettyPrinter::visit(CExpressionList * exprList)
{
	std::string name = "expressions" + std::to_string(lastId++);
	for (auto* iter : exprList->expressions) {
		visitIfNotNull(iter, name);
	}
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, exprList));
}

void CPrettyPrinter::visit(CLValueExpression * clvalue)
{
	std::string name = "lvalue" + std::to_string(lastId++);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, clvalue));
}

void CPrettyPrinter::visit(CBinaryExpression * binOp)
{
	std::string name = "binaryOperator" + std::to_string(lastId++);
	visitIfNotNull(binOp->left, name);
	visitIfNotNull(binOp->right, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, binOp));
}

void CPrettyPrinter::visit(CArrayExpression * arrayExpr)
{
	std::string name = "arrayExpr" + std::to_string(lastId++);
	visitIfNotNull(arrayExpr->caller, name);
	visitIfNotNull(arrayExpr->index, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, arrayExpr));
}

void CPrettyPrinter::visit(CCallExpression * calExpr)
{
	std::string name = "callExpr" + std::to_string(lastId++);
	visitIfNotNull(calExpr->caller, name);
	visitIfNotNull(calExpr->function, name);
	visitIfNotNull(calExpr->list, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, calExpr));
}

void CPrettyPrinter::visit(CValueExpression * valueExpr)
{
	std::string name = "valueExpr" + std::to_string(lastId++);
	visitIfNotNull(valueExpr->value, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, valueExpr));
}

void CPrettyPrinter::visit(CNewArrayExpression * newArray)
{
	std::string name = "newArray" + std::to_string(lastId++);
	visitIfNotNull(newArray->expression, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, newArray));
}

void CPrettyPrinter::visit(CNewExpression * newExpr)
{
	std::string name = "newExpression" + std::to_string(lastId++);
	visitIfNotNull(newExpr->id, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, newExpr));
}

void CPrettyPrinter::visit(CIdExpression * idExpr)
{
	std::string name = "idExpression" + std::to_string(lastId++);
	visitIfNotNull(idExpr->id, name);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, idExpr));
}

void CPrettyPrinter::visit(CThisExpression * thisExpr)
{
	std::string name = "thisExpression" + std::to_string(lastId++);
	nodes.push_front(name);
	labels.push_back(std::make_pair(name, thisExpr));
}
