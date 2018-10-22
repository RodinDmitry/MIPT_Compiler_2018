#include "Entities.h"

Modifier::Modifier(Value val) : value(val) {}

void Modifier::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

Goal::Goal(MainClass * mClas, ClassDeclaration * decl) : mClass(mClas), decls(decl)
{
	std::cout << "woohoo" << std::endl;
}

void Goal::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

MainClass::MainClass(MethodDeclaration * meth, Identifier * id) : method(meth), name(id) {}

void MainClass::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

ClassDeclaration::ClassDeclaration(Type typ) : type(typ) {}

ClassDeclaration::ClassDeclaration(ClassStart * name, ClassInternals * inter, Type typ)
	: title(name),
	internals(inter),
	type(typ) {}

ClassDeclaration::ClassDeclaration(ClassDeclaration * fir, ClassDeclaration * nex, Type typ)
	: first(fir),
	next(nex),
	type(typ) {}

void ClassDeclaration::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

ClassStart::ClassStart(Identifier * id, char * ext) : name(id), extend(ext) {}

void ClassStart::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

ClassInternals::ClassInternals(Type typ) : type(typ) {}

ClassInternals::ClassInternals(MethodDeclaration * meth, ClassInternals * intern, Type typ)
	: method(meth),
	next(intern),
	type(typ) {}

ClassInternals::ClassInternals(VarDeclaration * mem, ClassInternals * intern, Type typ)
	: member(mem),
	next(intern),
	type(typ) {}

void ClassInternals::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

Argument::Argument(ArgumentState st) : state(st) {}

Argument::Argument(Identifier * ident, ArgumentState st) : id(ident), state(st) {}

Argument::Argument(VarDeclaration * variab, ArgumentState st) : var(variab), state(st) {}

Argument::Argument(Argument * argum, VarDeclaration * variab, ArgumentState st) : var(variab), arg(argum), state(st) {}

void Argument::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

VarDeclaration::VarDeclaration(TypeIdentifier * tid, Identifier * name) : type(tid), id(name) {}

void VarDeclaration::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

MethodDeclaration::MethodDeclaration(Modifier * visibility, Identifier * id, Argument * args, Statement * stats, Expression * res, TypeIdentifier * rett)
	: modifier(visibility),
	name(id),
	arguments(args),
	body(stats),
	ret(res),
	retType(rett) {}

void MethodDeclaration::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

MainMethodDeclaration::MainMethodDeclaration(Argument * args, Statement * stats)
	: arguments(args),
	body(stats) {}

void MainMethodDeclaration::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

TypeIdentifier::TypeIdentifier(TypeType tp) : type(tp) {}

TypeIdentifier::TypeIdentifier(Identifier * userType, TypeType tp) : type(tp), id(userType) {}

void TypeIdentifier::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

Expression::Expression(Value * a, ExpressionState st) : value(a), state(st) {}

Expression::Expression(Expression * a, Expression * b, BinaryOperator * oper, ExpressionState st) : expr1(a), expr2(b),
binaryOperator(oper), state(st) {}

Expression::Expression(Expression * a, Expression * b, ExpressionState st) : expr1(a), expr2(b), state(st) {}

Expression::Expression(Expression * a, ExpressionState st) : expr1(a), state(st) {}

Expression::Expression(Expression * a, FunctionCall * b, ExpressionState st) : expr1(a), fcall(b), state(st) {}

Expression::Expression(Identifier * a, ExpressionState st) : id(a), state(st) {}

Expression::Expression(ExpressionState st) : state(st) {}

void Expression::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

BinaryOperator::BinaryOperator(OperationType oper) : type(oper) {}

void BinaryOperator::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

FunctionCall::FunctionCall(Expression * exp, Identifier * ident) : expr(exp), id(ident) {}

void FunctionCall::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

Statement::Statement(Statement * nex, StatementType state) : next(nex), type(state) {}

Statement::Statement(Statement * st, Statement * nex, StatementType state) : statement(st), next(nex), type(state) {}

Statement::Statement(VarDeclaration * var, Statement * nex, StatementType state) : decl(var), next(nex), type(state) {}

Statement::Statement(Expression * condition, Statement * st, Statement * elseSt, Statement * nex, StatementType state)
	: statement(st),
	expr1(condition),
	elseState(elseSt),
	next(nex),
	type(state) {}

Statement::Statement(Expression * condition, Statement * st, Statement * nex, StatementType state) : statement(st), expr1(condition), next(nex), type(state) {}

Statement::Statement(Expression * expres, Statement * nex, StatementType state) : expr1(expres), next(nex), type(state) {}

Statement::Statement(Expression * expres, Identifier * ident, Statement * nex, StatementType state) : id(ident), expr1(expres), next(nex), type(state) {}

Statement::Statement(Expression * expres, Identifier * ident, Expression * value, Statement * nex, StatementType state)
	: id(ident),
	expr1(expres),
	expr2(value),
	next(nex),
	type(state) {}

void Statement::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

Identifier::Identifier(std::string str) : name(str) {}

void Identifier::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

Value::Value(int a) : intValue(a)
{
	state = INT_STATE;
}

Value::Value(bool a) : boolValue(a)
{
	state = BOOL_STATE;
}

void Value::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}
