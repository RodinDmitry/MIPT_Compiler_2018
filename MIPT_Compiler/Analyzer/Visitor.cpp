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

void CPrettyPrinter::visit(CNotExpression * cnotexpr)
{
	std::string name = "cnotexpr" + std::to_string(lastId++);
	visitIfNotNull(cnotexpr->expression, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CBracketsExpression * cbrexpr) 
{
	std::string name = "cbrexpr" + std::to_string(lastId++);
	visitIfNotNull(cbrexpr->expression, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CReturnExpression * cretexpr) 
{
	std::string name = "cretexpr" + std::to_string(lastId++);
	visitIfNotNull(cretexpr->expression, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CFunction * cfunc) 
{
	std::string name = "cfunc" + std::to_string(lastId++);
	visitIfNotNull(cfunc->visibility, name);
	visitIfNotNull(cfunc->name, name);
	visitIfNotNull(cfunc->arguments, name);
	visitIfNotNull(cfunc->body, name);
	visitIfNotNull(cfunc->returns, name);
	visitIfNotNull(cfunc->returnExpression, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CId * cid) 
{
	std::string name = "cid" + cid->name + std::to_string(lastId++);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CMainArgument * cmainrg) 
{
	std::string name = "cmainarg" + std::to_string(lastId++);
	visitIfNotNull(cmainrg->name, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CMainFunction * cmainfunc) 
{
	std::string name = "cmainfunc" + std::to_string(lastId++);
	visitIfNotNull(cmainfunc->argument, name);
	visitIfNotNull(cmainfunc->body, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CMain * cmain)
{
	std::string name = "cmain" + std::to_string(lastId++);
	visitIfNotNull(cmain->name, name);
	visitIfNotNull(cmain->mainFunction, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CModifier * cmod)
{
	std::string name = "cmod" + std::to_string(lastId++);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CProgram * cprogr)
{
	std::string name = "cprogr" + std::to_string(lastId++);
	visitIfNotNull(cprogr->main, name);
	visitIfNotNull(cprogr->classes, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(IStatement * istat)
{
	std::string name = "istat" + std::to_string(lastId++);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CStatementList * cstatlist)
{
	std::string name = "cstatlist" + std::to_string(lastId++);
	for (auto* statement : cstatlist->statements) {
		visitIfNotNull(statement, name);
	}

	nodes.push_front(name);
}

void CPrettyPrinter::visit(CVisibilityStatement * cvisstat)
{
	std::string name = "cvisstat" + std::to_string(lastId++);
	visitIfNotNull(cvisstat->statement, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CIfStatement * cifstat)
{
	std::string name = "cifstat" + std::to_string(lastId++);
	visitIfNotNull(cifstat->condition, name);
	visitIfNotNull(cifstat->thenStatement, name);
	visitIfNotNull(cifstat->elseStatement, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CWhileStatement * cwhstat)
{
	std::string name = "cwhstat" + std::to_string(lastId++);
	visitIfNotNull(cwhstat->condition, name);
	visitIfNotNull(cwhstat->statement, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CPrintStatement * cprintstat)
{
	std::string name = "cprintstat" + std::to_string(lastId++);
	visitIfNotNull(cprintstat->expression, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CEqualStatement * ceqstat)
{
	std::string name = "ceqstat" + std::to_string(lastId++);
	visitIfNotNull(ceqstat->left, name);
	visitIfNotNull(ceqstat->right, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CVariableStatement * cvarstat)
{
	std::string name = "cvarstat" + std::to_string(lastId++);
	visitIfNotNull(cvarstat->variable, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CType * ctype)
{
	std::string name = "ctype" + std::to_string(lastId++);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(IValue * ival)
{
	std::string name = "ival" + std::to_string(lastId++);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CValue * cval)
{
	std::string name = "cval" + std::to_string(lastId++);
	name += "_" + std::to_string(cval->value);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(CVariable * cvar)
{
	std::string name = "cvar" + std::to_string(lastId++);
	visitIfNotNull(cvar->type, name);
	visitIfNotNull(cvar->name, name);
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
	/*switch (binOp->operation) {
		case CBinaryExpression::O_Plus: name += "+";  break;
		case CBinaryExpression::O_Minus: name += "-";  break;
		case CBinaryExpression::O_Division: name += "/";  break;
		case CBinaryExpression::O_IntegerDivision: name += "%";  break;
		case CBinaryExpression::O_And: name += "&&";  break;
		case CBinaryExpression::O_Or: name += "||";  break;
		case CBinaryExpression::O_Multiplication: name += "*";  break;
		case CBinaryExpression::O_Less: name += "<";  break;
		case CBinaryExpression::O_More: name += ">";  break;
	}*/
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
