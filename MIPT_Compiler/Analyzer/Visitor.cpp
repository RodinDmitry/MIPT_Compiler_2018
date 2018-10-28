#include <Visitor.h>
#include <Entities.h>

static int lastId = 0;
std::set< ITree* > printerSet;
std::deque< ITree* > printerStack;

void CPrettyPrinter::visit(CClassDeclaration * cldecl)
{
	std::string name = "cdecl" + std::to_string(lastId++);
	visitIfNotNull(cldecl->name, name);
	visitIfNotNull(cldecl->extend, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(ITree *)
{
	output << "dynamic_cast failed" << std::endl;
}

void CPrettyPrinter::visit(CArgumentList *argList)
{
	std::string name = "argList" + std::to_string(lastId++);
	for (CVariable* arg : argList->arguments) {
		visitIfNotNull(argList, name);
	}
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CClassInternals * clInter)
{
	std::string name = "clInter" + std::to_string(lastId++);
	visitIfNotNull(clInter->function, name);
	visitIfNotNull(clInter->variable, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CClassInternalsList * clInterList)
{
	std::string name = "clInterList" + std::to_string(lastId++);
	for (CClassInternals* clInt : clInterList->internals) {
		visitIfNotNull(clInt, name);
	}
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CClass * cclass)
{
	std::string name = "cclass" + std::to_string(lastId++);
	visitIfNotNull(cclass->declaration, name);
	visitIfNotNull(cclass->internals, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CClassList * clList)
{
	std::string name = "clList" + std::to_string(lastId++);
	for (CClass* cclass : clList->classes) {
		visitIfNotNull(cclass, name);
	}
	nodes.push_front(name);
}

void CPrettyPrinter::visit(IExpression *)
{
	output << "dynamic_cast failed" << std::endl;
}

void CPrettyPrinter::visit(CExpressionList * exprList)
{
	std::string name = "exprList" + std::to_string(lastId++);
	for (auto* iter : exprList->expressions) {
		visitIfNotNull(iter, name);
	}
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CLValueExpression *)
{
	std::string name = "clvalueExpr" + std::to_string(lastId++);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CBinaryExpression * binOp)
{
	std::string name = "binOp" + std::to_string(lastId++);
	switch (binOp->operation) {
		case CBinaryExpression::O_Plus: name += " +";  break;
		case CBinaryExpression::O_Minus: name += " -";  break;
		case CBinaryExpression::O_Division: name += " /";  break;
		case CBinaryExpression::O_IntegerDivision: name += " %";  break;
		case CBinaryExpression::O_And: name += " &&";  break;
		case CBinaryExpression::O_Or: name += " ||";  break;
		case CBinaryExpression::O_Multiplication: name += " *";  break;
		case CBinaryExpression::O_Less: name += " <";  break;
		case CBinaryExpression::O_More: name += " >";  break;
	}
	visitIfNotNull(binOp->left, name);
	visitIfNotNull(binOp->right, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CArrayExpression * arrayExpr)
{
	std::string name = "arrayExpr" + std::to_string(lastId++);
	visitIfNotNull(arrayExpr->caller, name);
	visitIfNotNull(arrayExpr->index, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CCallExpression * calExpr)
{
	std::string name = "calExpr" + std::to_string(lastId++);
	visitIfNotNull(calExpr->caller, name);
	visitIfNotNull(calExpr->function, name);
	visitIfNotNull(calExpr->list, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CValueExpression * valueExpr)
{
	std::string name = "valueExpr" + std::to_string(lastId++);
	visitIfNotNull(valueExpr->value, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CNewArrayExpression * newArray)
{
	std::string name = "newArray" + std::to_string(lastId++);
	visitIfNotNull(newArray->expression, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CNewExpression * newExpr)
{
	std::string name = "newExpr" + std::to_string(lastId++);
	visitIfNotNull(newExpr->id, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CIdExpression * idExpr)
{
	std::string name = "idExpr" + std::to_string(lastId++);
	visitIfNotNull(idExpr->id, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CThisExpression *)
{
	std::string name = "thisExpr" + std::to_string(lastId++);
	nodes.push_front(name);
}
