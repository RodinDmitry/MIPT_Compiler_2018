#include <Visitor.h>
#include <Entities.h>

static int lastId = 0;
std::set< ITree* > printerSet;
std::deque< ITree* > printerStack;

/*void CPrettyPrinter::visit(ITree *)
{
	output << "dynamic_cast failed" << std::endl;
}

void CPrettyPrinter::visit(Modifier *)
{
	std::string name = "modifier" + std::to_string(lastId++);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(Value *)
{
	std::string name = "value" + std::to_string(lastId++);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(Identifier * id)
{
	std::string name = "id" + id->name + std::to_string(lastId++);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(Statement * statement)
{
	std::string name = "statement" + std::to_string(lastId++);
	visitNullable(statement->statement, name);
	visitNullable(statement->expr1, name);
	visitNullable(statement->expr2, name);
	visitNullable(statement->elseState, name);
	visitNullable(statement->id, name);
	visitNullable(statement->decl, name);
	visitNullable(statement->next, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(FunctionCall * fcall)
{
	std::string name = "fcall" + std::to_string(lastId++);
	visitNullable(fcall->expr, name);
	visitNullable(fcall->id, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(BinaryOperator *)
{
	std::string name = "binOperator" + std::to_string(lastId++);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(Expression *expr)
{
	std::string name = "expression" + std::to_string(lastId++);
	visitNullable(expr->expr1, name);
	visitNullable(expr->expr2, name);
	visitNullable(expr->fcall, name);
	visitNullable(expr->value, name);
	visitNullable(expr->id, name);
	visitNullable(expr->binaryOperator, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(TypeIdentifier * tid)
{
	std::string name = "tid" + std::to_string(lastId++);
	visitNullable(tid->id, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(MainMethodDeclaration *mmdecl)
{
	std::string name = "mmdecl" + std::to_string(lastId++);
	visitNullable(mmdecl->arguments, name);
	visitNullable(mmdecl->body, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(MethodDeclaration * mdecl)
{
	std::string name = "mdecl" + std::to_string(lastId++);
	visitNullable(mdecl->modifier, name);
	visitNullable(mdecl->name, name);
	visitNullable(mdecl->arguments, name);
	visitNullable(mdecl->body, name);
	visitNullable(mdecl->ret, name);
	visitNullable(mdecl->retType, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(VarDeclaration * vardecl)
{
	std::string name = "vardecl" + std::to_string(lastId++);
	visitNullable(vardecl->type, name);
	visitNullable(vardecl->id, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(Argument * arg)
{
	std::string name = "arg" + std::to_string(lastId++);
	visitNullable(arg->arg, name);
	visitNullable(arg->var, name);
	visitNullable(arg->id, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(ClassInternals * cint)
{
	std::string name = "cint" + std::to_string(lastId++);
	visitNullable(cint->method, name);
	visitNullable(cint->member, name);
	visitNullable(cint->next, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(ClassStart * cstart)
{
	std::string name = "cstart" + std::to_string(lastId++);
	visitNullable(cstart->name, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(ClassDeclaration * cldecl)
{
	std::string name = "cldecl" + std::to_string(lastId++);
	visitNullable(cldecl->title, name);
	visitNullable(cldecl->internals, name);
	visitNullable(cldecl->first, name);
	visitNullable(cldecl->next, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(MainClass * mclass)
{
	std::string name = "mclass" + std::to_string(lastId++);
	visitNullable(mclass->method, name);
	visitNullable(mclass->name, name);
	nodes.push_front(name);
}

void CPrettyPrinter::visit(Goal * goal)
{
	std::string name = "goal" + std::to_string(lastId++);
	visitNullable(goal->mClass, name);
	visitNullable(goal->decls, name);
	nodes.push_front(name);
}
*/