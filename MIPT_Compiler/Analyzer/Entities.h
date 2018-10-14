#pragma once
#include <vector>
#include <string>
#include <cassert>

class Tree {
public:

	void SetParent(Tree* parent);

protected:
	Tree* parent;
	std::vector<Tree*> children;
};

class Expression;

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

class Statement: public Tree {};

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
		Empty_STATE
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
	

class TypeIdentifier : public Tree {};

class MethodDeclaration : public Tree {};

class ClassDeclaration : public Tree {};

class MainClass : public Tree {};

class Goal : public Tree {};

class VarDeclaration : public Tree {};



