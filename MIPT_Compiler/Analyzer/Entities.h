#pragma once
#include <string>
#include <iostream>
#include <Visitor.h>


class Modifier : public ITree
{
public:
	enum Value
	{
		PT_Public,
		PT_Private,
		NO_STATE
	} value = NO_STATE;

	Modifier(Value val);

	void Accept(IVisitor* visitor);
};

class Value : public ITree
{
public:
	int intValue = 0;
	bool boolValue = false;
	enum ValueState {
		INT_STATE,
		BOOL_STATE,
		NO_STATE
	} state = NO_STATE;

	explicit Value(int a);

	explicit Value(bool a);

	void Accept(IVisitor* visitor);
};

class Identifier : public ITree
{
public:
	std::string name = "default";

	Identifier(std::string str);

	void Accept(IVisitor* visitor);
};

class Statement: public ITree
{
public:
	Statement* statement = nullptr;
	Expression* expr1 = nullptr;
	Expression* expr2 = nullptr;
	Statement* elseState = nullptr;
	Identifier* id = nullptr;
	VarDeclaration* decl = nullptr;
	Statement* next = nullptr;
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
		VAR_TYPE,
		NO_TYPE
	} type = NO_TYPE;

	Statement(Statement* nex, StatementType state);
	Statement(Statement* st, Statement* nex, StatementType state);;
	Statement(VarDeclaration* var, Statement* nex, StatementType state);;
	Statement(Expression* condition, Statement* st, Statement* elseSt, Statement* nex, StatementType state);;
	Statement(Expression* condition, Statement* st, Statement* nex, StatementType state);;
	Statement(Expression* expres, Statement* nex, StatementType state);;
	Statement(Expression* expres, Identifier* ident, Statement* nex, StatementType state);;
	Statement(Expression* expres, Identifier* ident, Expression* value, Statement* nex, StatementType state);;

	void Accept(IVisitor* visitor);

};

class FunctionCall : public ITree
{
public:
	Expression* expr = nullptr;
	Identifier* id = nullptr;

	FunctionCall(Expression* exp, Identifier* ident);

	void Accept(IVisitor* visitor);
};

class BinaryOperator : public ITree
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
		PT_More,
		NO_TYPE
	} type = NO_TYPE;

	BinaryOperator(OperationType oper);

	void Accept(IVisitor* visitor);
};

class Expression : public ITree
{
public:
	Expression* expr1 = nullptr;
	Expression* expr2 = nullptr;
	FunctionCall* fcall = nullptr;
	Value* value = nullptr;
	Identifier* id = nullptr;
	BinaryOperator* binaryOperator = nullptr;

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
		RETURN_STATE,
		NO_STATE
	} state = NO_STATE;

	Expression(Value* a, ExpressionState st);

	Expression(Expression* a, Expression* b, BinaryOperator* oper, ExpressionState st);

	Expression(Expression* a, Expression* b, ExpressionState st);

	Expression(Expression* a, ExpressionState st);

	Expression(Expression* a, FunctionCall* b, ExpressionState st);

	Expression(Identifier* a, ExpressionState st);

	explicit Expression(ExpressionState st);

	void Accept(IVisitor* visitor);
};
	
class TypeIdentifier : public ITree
{
public:
	// :)
	enum TypeType
	{
		INT_TYPE,
		BOOL_TYPE,
		INTA_TYPE,
		USER_TYPE,
		VOID_TYPE,
		NO_TYPE
	} type = NO_TYPE;
	Identifier* id = nullptr;

	TypeIdentifier(TypeType tp);

	TypeIdentifier(Identifier* userType, TypeType tp);

	void Accept(IVisitor* visitor);
};

class MainMethodDeclaration : public ITree
{
public:
	Argument* arguments = nullptr;
	Statement* body = nullptr;

	MainMethodDeclaration(Argument* args, Statement* stats);

	void Accept(IVisitor* visitor);
};

class MethodDeclaration : public ITree
{
public:
	Modifier* modifier = nullptr;
	Identifier* name = nullptr;
	Argument* arguments = nullptr;
	Statement* body = nullptr;
	Expression* ret = nullptr;
	TypeIdentifier* retType = nullptr;

	MethodDeclaration(Modifier* visibility, Identifier* id, Argument* args, Statement* stats, Expression* res, TypeIdentifier* rett);

	void Accept(IVisitor* visitor);
};

class VarDeclaration : public ITree
{
public:
	TypeIdentifier* type = nullptr;
	Identifier* id = nullptr;

	VarDeclaration(TypeIdentifier* tid, Identifier* name);

	void Accept(IVisitor* visitor);
};

class Argument : public ITree
{
public:
	enum ArgumentState
	{
		EMPTY_STATE,
		LAST_STATE,
		ONE_STATE,
		LIST_STATE,
		MAIN_STATE,
		NO_STATE
	} state = NO_STATE;

	Argument* arg = nullptr;
	VarDeclaration* var = nullptr;
	Identifier* id = nullptr;
	Argument(ArgumentState st);

	Argument(Identifier* ident, ArgumentState st);

	Argument(VarDeclaration* variab, ArgumentState st);

	Argument(Argument* argum, VarDeclaration* variab, ArgumentState st);

	void Accept(IVisitor* visitor);
};

class ClassInternals : public ITree
{
public:
	enum Type
	{
		METHOD_TYPE,
		MEMBER_TYPE,
		EMPTY_TYPE,
		NO_TYPE
	} type = NO_TYPE;
	MethodDeclaration* method = nullptr;
	VarDeclaration* member = nullptr;
	ClassInternals* next = nullptr;

	ClassInternals(Type typ);

	ClassInternals(MethodDeclaration* meth, ClassInternals* intern, Type typ);

	ClassInternals(VarDeclaration* mem, ClassInternals* intern, Type typ);

	void Accept(IVisitor* visitor);
};

class ClassStart : public ITree
{
public:
	Identifier* name = nullptr;
	char* extend;

	ClassStart(Identifier* id, char* ext);

	void Accept(IVisitor* visitor);
};

class ClassDeclaration : public ITree
{
public:
	ClassStart* title = nullptr;
	ClassInternals* internals = nullptr;
	ClassDeclaration* first = nullptr;
	ClassDeclaration* next = nullptr;

	enum Type
	{
		CLASS_TYPE,
		LIST_TYPE,
		EMPTY_TYPE,
		NO_TYPE
	} type = NO_TYPE;

	ClassDeclaration(Type typ);

	ClassDeclaration(ClassStart* name, ClassInternals* inter, Type typ);

	ClassDeclaration(ClassDeclaration* fir, ClassDeclaration* nex, Type typ);
	
	void Accept(IVisitor* visitor);
};

class MainClass : public ITree
{
public:
	MethodDeclaration* method = nullptr;
	Identifier* name = nullptr;
	MainClass(MethodDeclaration* meth, Identifier* id);

	void Accept(IVisitor* visitor);
};

class Goal : public ITree
{
public:
	MainClass* mClass = nullptr;
	ClassDeclaration* decls = nullptr;

	Goal(MainClass* mClas, ClassDeclaration* decl);

	void Accept(IVisitor* visitor);
};