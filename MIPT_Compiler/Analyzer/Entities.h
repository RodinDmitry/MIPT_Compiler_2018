#pragma once
#include <vector>
#include <string>
#include <cassert>
#include <iostream>

class Tree {
public:

	void SetParent(Tree* parent);

protected:
	Tree* parent;
	std::vector<Tree*> children;
};

class Expression;

class Argument;

class Modifier : public Tree
{
public:
	enum Value
	{
		PT_Public,
		PT_Private
	} value;

	Modifier(Value val): value(val) {}
};

class Value : public Tree
{
public:
	int intValue;
	bool boolValue;
	enum ValueState {
		INT_STATE,
		BOOL_STATE
	} state;

	explicit Value(int a) : intValue(a)
	{
		state = INT_STATE;
		std::cout << "woohoo" << std::endl;
	}

	explicit Value(bool a) : boolValue(a)
	{
		state = BOOL_STATE;
	}
};

class Identifier : public Tree
{
public:
	std::string name;

	Identifier(std::string str): name(str) {}
};

class Statement: public Tree
{
public:
	Statement* statement;
	Expression* expr1;
	Expression* expr2;
	Statement* elseState;
	Identifier* id;

	enum StatementType
	{
		SHADE_TYPE,
		IF_TYPE,
		WHILE_TYPE,
		PRINT_TYPE,
		ASSIGN_TYPE,
		ARR_ASSIGN_TYPE,
		LIST_TYPE,
		EMPTY_TYPE,
	} type;

	Statement(StatementType state): type(state) {};
	Statement(Statement* st, StatementType state) : statement(st), type(state) {};
	Statement(Expression* condition, Statement* st, Statement* elseSt, StatementType state)
			: statement(st),
			expr1(condition),
			elseState(elseSt),
			type(state) {};
	Statement(Expression* condition, Statement* st, StatementType state) : statement(st), expr1(condition), type(state) {};
	Statement(Expression* expres, StatementType state) : expr1(expres), type(state) {};
	Statement(Expression* expres, Identifier* ident, StatementType state) : id(ident), expr1(expres), type(state) {};
	Statement(Expression* expres, Identifier* ident, Expression* value, StatementType state) 
			: id(ident),
			expr1(expres),
			expr2(value),
			type(state) {};

};

class FunctionCall : public Tree
{
public:
	Expression* expr;
	Identifier* id;

	FunctionCall(Expression* exp, Identifier* ident): expr(exp), id(ident) {}
};

class BinaryOperator : public Tree
{
public:
	enum OperationType
	{
		PT_Plus,
		PT_Minus,
		PT_Division,
		PT_IntegerDivision,
		PT_And,
		PT_Or,
		PT_Multiplication,
		PT_Less,
		PT_More
	} type;

	BinaryOperator(OperationType oper): type(oper) {}
};

class Expression : public Tree
{
public:
	Expression* expr1 = nullptr;
	Expression* expr2 = nullptr;
	FunctionCall* fcall;
	Value* value;
	Identifier* id;
	BinaryOperator* binaryOperator;

	enum ExpressionState {
		BinaryOperator_STATE,
		SquareBracket_STATE,
		Length_STATE,
		FunctionCall_STATE,
		Value_STATE,
		ID_STATE,
		This_State,
		Array_STATE,
		NewObj_STATE,
		Not_STATE,
		List_STATE,
		Empty_STATE,
		RETURN_STATE
	} state;

	Expression(Value* a, ExpressionState st) : value(a), state(st) {}

	Expression(Expression* a, Expression* b, BinaryOperator* oper, ExpressionState st) : expr1(a), expr2(b),
			binaryOperator(oper), state(st) {}

	Expression(Expression* a, Expression* b, ExpressionState st) : expr1(a), expr2(b), state(st) {}

	Expression(Expression* a, ExpressionState st) : expr1(a), state(st) {}

	Expression(Expression* a, FunctionCall* b, ExpressionState st) : expr1(a), fcall(b), state(st) {}

	Expression(Identifier* a, ExpressionState st) : id(a), state(st) {}

	explicit Expression(ExpressionState st) : state(st) {}
};
	
class TypeIdentifier : public Tree
{
public:
	// :)
	enum TypeType
	{
		INT_TYPE,
		BOOL_TYPE,
		INTA_TYPE,
		USER_TYPE
	} type;
	Identifier* id;

	TypeIdentifier(TypeType tp): type(tp) {}

	TypeIdentifier(Identifier* userType, TypeType tp) : type(tp), id(userType) {}
};

class MainMethodDeclaration : public Tree
{
public:
	Argument* arguments;
	Statement* body;

	MainMethodDeclaration(Argument* args, Statement* stats)
		: arguments(args),
		body(stats) {}
};

class MethodDeclaration : public Tree
{
public:
	Modifier* modifier;
	Identifier* name;
	Argument* arguments;
	Statement* body;
	Expression* ret;

	MethodDeclaration(Modifier* visibility, Identifier* id, Argument* args, Statement* stats, Expression* res)
		: modifier(visibility),
		name(id),
		arguments(args),
		body(stats),
		ret(res) {}
};

class VarDeclaration : public Tree
{
public:
	TypeIdentifier* type;
	Identifier* id;

	VarDeclaration(TypeIdentifier* tid, Identifier* name): type(tid), id(name) {}
};

class Argument : public Tree
{
public:
	enum ArgumentState
	{
		EMPTY_STATE,
		LAST_STATE,
		ONE_STATE,
		LIST_STATE,
		MAIN_STATE
	} state;

	Argument* arg;
	VarDeclaration* var;
	Identifier* id;
	Argument(ArgumentState st): state(st) {}

	Argument(Identifier* ident, ArgumentState st) : id(ident), state(st) {}

	Argument(VarDeclaration* variab, ArgumentState st): var(variab), state(st) {}

	Argument(Argument* argum, VarDeclaration* variab, ArgumentState st): var(variab), arg(argum), state(st) {}
};

class ClassInternals : public Tree
{
public:
	enum Type
	{
		METHOD_TYPE,
		MEMBER_TYPE,
		EMPTY_TYPE
	} type;
	MethodDeclaration* method;
	VarDeclaration* member;
	ClassInternals* next;

	ClassInternals(Type typ): type(typ) {}

	ClassInternals(MethodDeclaration* meth, ClassInternals* intern, Type typ) 
		: method(meth),
		next(intern),
		type(typ) {}

	ClassInternals(VarDeclaration* mem, ClassInternals* intern, Type typ)
		: member(mem),
		next(intern),
		type(typ) {}
};

class ClassStart : public Tree
{
public:
	Identifier* name;
	char* extend;

	ClassStart(Identifier* id, char* ext) : name(id), extend(ext) {}
};

class ClassDeclaration : public Tree
{
public:
	ClassStart* title;
	ClassInternals* internals;
	ClassDeclaration* first;
	ClassDeclaration* next;

	enum Type
	{
		CLASS_TYPE,
		LIST_TYPE,
		EMPTY_TYPE
	} type;

	ClassDeclaration(Type typ): type(typ) {}

	ClassDeclaration(ClassStart* name,	ClassInternals* inter, Type typ) 
		: title(name),
		internals(inter),
		type(typ) {}

	ClassDeclaration(ClassDeclaration* fir, ClassDeclaration* nex, Type typ) 
		: first(fir),
		next(nex),
		type(typ) {}
};

class MainClass : public Tree
{
public:
	MethodDeclaration* method;
	Identifier* name;
	MainClass(MethodDeclaration* meth, Identifier* id): method(meth), name(id) {}
};

class Goal : public Tree
{
public:
	MainClass* mClass;
	ClassDeclaration* decls;

	Goal(MainClass* mClas, ClassDeclaration* decl): mClass(mClas), decls(decl)
	{
		std::cout << "woohoo" << std::endl;
	}
};