%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern "C++" int yyparse();
extern FILE* yyin;

extern void yyerror(const char* s);
%}

%code requires {
#include "../Analyzer/BisonUtils.h"
}

%union {

	int integerValue;
	bool logicalValue;
	char* stringValue;
	
	Tree* node;
}

// Типы
%token PT_Void
%token PT_String 
%token<integerValue> PT_Number
%token PT_Boolean PT_Integer
//Логические константы
%token<logicalValue> PT_True PT_False
// Части для классов
%token PT_Class PT_Static PT_Public PT_Private PT_Extends
//Точка входа
%token PT_Main
// Принт
%token PT_Print
//Условные операторы
%token PT_If PT_While PT_Else
// Что-то
%token PT_Length
// Ключевые слова
%token PT_This PT_New
// Логические операции

// Точка с запятой
%token PT_Semicolon
// Переменная
%token<stringValue> PT_ID
%token PT_EOF
%token PT_Dot
%token PT_Coma
%token PT_Return

%type<node> ValueT
%type<node> Expression
%type<node> BinaryOperator
%type<node> FunctionCall
%type<node> Expressions
%type<node> ExpressionList
%type<node> Type
%type<node> Statement
%type<node> StatementList
%type<node> Variable
%type<node> Argument
%type<node> ArgumentsList
%type<node> Function
%type<node> MainArgument
%type<node> Return
%type<node> Visibility
%type<node> MainFunction
%type<node> ClassInternals
%type<stringValue> Extends
%type<node> Goal
%type<node> MainClass
%type<node> Class
%type<node> ClassStart
%type<node> ClassDeclaration



%left PT_LeftRoundBracket PT_LeftSquareBracket PT_LeftBrace 
%left PT_RightRoundBracket PT_RightSquareBracket PT_RightBrace
%left PT_Dot
%left PT_Negation 
%left PT_Multiplication PT_Division PT_IntegerDivision 
%left PT_Equal PT_And PT_Or PT_More PT_Less PT_Plus PT_Minus

%left BRACKETS
%left ARRAY
%left LENGTH CALL
%right NOT 
%left BINARY 


%start Goal

%%

Goal: MainClass ClassDeclaration PT_EOF { $$ = new Goal(ToMCl($1), ToClDecl($2)); }  
;

MainClass: ClassWord PT_ID LeftBrace MainFunction RightBrace { $$ = new MainClass(ToFunc($4), new Identifier($2)); } 
;

ClassDeclaration: { $$ = new ClassDeclaration(cdt::EMPTY_TYPE); }
	| Class ClassDeclaration { $$ = new ClassDeclaration(ToClDecl($1),
		ToClDecl($2), cdt::LIST_TYPE); }

Class: ClassStart LeftBrace ClassInternals RightBrace { $$ = new ClassDeclaration(ToClSt($1),
		ToClInt($3), cdt::CLASS_TYPE); }
;

ClassStart: ClassWord PT_ID Extends {$$ = new ClassStart(new Identifier($2), $3);}
;

Extends: { $$ = 0; }
	| ExtendsWord PT_ID {$$ = $2;}
;

ClassInternals: { $$ = new ClassInternals(cit::EMPTY_TYPE); }
	| Function ClassInternals { $$ = new ClassInternals(ToFunc($1), ToClInt($2), cit::METHOD_TYPE); }
	| Variable ClassInternals { $$ = new ClassInternals(ToVar($1), ToClInt($2), cit::MEMBER_TYPE);}
;

MainFunction: PT_Public PT_Static PT_Void PT_Main LeftRoundBracket MainArgument RightRoundBracket LeftBrace Statement RightBrace { 
		$$ = new MainMethodDeclaration( ToArg($6), ToState($9) ); }
;

MainArgument: PT_String LeftSquareBracket RightSquareBracket PT_ID { $$ = new Argument(new Identifier($4), aas::LAST_STATE); }
;

Function: Visibility PT_ID ArgumentsList LeftBrace Statement Return RightBrace { $$ = new MethodDeclaration(ToMod($1),
				new Identifier($2), ToArg($3), ToState($5), ToExpr($6)); }
;

Visibility: PT_Public { $$ = new Modifier(mv::PT_Public); }
	| PT_Private { $$ = new Modifier(mv::PT_Private);}
;

Return: PT_Return Expression Semicolon { $$=new Expression(ToExpr($2), exst::RETURN_STATE);}
;

ArgumentsList: LeftRoundBracket RightRoundBracket { $$ = new Argument(aas::EMPTY_STATE); }
	| LeftRoundBracket Argument RightRoundBracket { $$ = $2;}
;

Argument : Variable { $$ = new Argument(ToVar($1), aas::LAST_STATE); }
	| Variable PT_Coma Argument { $$ = new Argument(ToArg($3), ToVar($1), aas::LIST_STATE); }
;

Variable: Type PT_ID Semicolon { $$ = new VarDeclaration(ToType($1), new Identifier($2)); }
;

Type: Integer  { $$ = new TypeIdentifier(titt::INT_TYPE); }
	| Integer PT_LeftSquareBracket PT_RightSquareBracket  { $$ = new TypeIdentifier(titt::INTA_TYPE); }
	| Boolean  { $$ = new TypeIdentifier(titt::BOOL_TYPE); }
	| PT_ID  { $$ = new TypeIdentifier(new Identifier($1), titt::USER_TYPE); }
;

Statement: { $$ = new Statement(sst::EMPTY_TYPE); }
	| StatementList { $$ = new Statement(ToState($1), sst::LIST_TYPE); }
;

StatementList: LeftBrace StatementList RightBrace { $$ = new Statement(ToState($2), sst::SHADE_TYPE); }
	| If LeftRoundBracket Expression RightRoundBracket StatementList PT_Else Statement { $$ = new Statement(ToExpr($3), ToState($5), ToState($7), sst::IF_TYPE); }
	| While LeftRoundBracket Expression RightRoundBracket  StatementList { $$ = new Statement(ToExpr($3), ToState($5), sst::WHILE_TYPE); }
	| Print LeftRoundBracket Expression RightRoundBracket Semicolon { $$ = new Statement(ToExpr($3), sst::PRINT_TYPE); }
	| PT_ID Equals Expression Semicolon { $$ = new Statement(ToExpr($3), new Identifier($1), sst::ASSIGN_TYPE); }
	| PT_ID LeftSquareBracket Expression RightSquareBracket Equals Expression Semicolon { $$ = new Statement(ToExpr($3), new Identifier($1), ToExpr($6), sst::ARR_ASSIGN_TYPE); }

;

Expression: Expression BinaryOperator Expression %prec BINARY { $$=new Expression(ToExpr($1), ToExpr($3), ToBinOp($2), exst::BinaryOperator_STATE);}
	| Expression LeftSquareBracket Expression RightSquareBracket %prec ARRAY{ $$=new Expression(ToExpr($1), ToExpr($3), exst::SquareBracket_STATE);}
	| Expression MethodCall Length %prec LENGTH { $$=new Expression(ToExpr($1), exst::Length_STATE);}
	| Expression MethodCall FunctionCall %prec CALL { $$=new Expression(ToExpr($1), ToFcall($3), exst::FunctionCall_STATE);}
	| ValueT { $$=new Expression(ToVal($1), exst::Value_STATE);}
	| PT_ID { $$=new Expression(new Identifier($1), exst::ID_STATE);}
	| This { $$=new Expression(exst::This_State);}
	| New Integer LeftSquareBracket Expression RightSquareBracket { $$=new Expression(ToExpr($4), exst::Array_STATE);}
	| New PT_ID LeftRoundBracket RightRoundBracket { $$=new Expression(new Identifier($2), exst::NewObj_STATE);}
	| Not Expression %prec NOT { $$=new Expression(exst::Not_STATE); }
	| LeftRoundBracket Expression RightRoundBracket %prec BRACKETS { $$=$2;}
;

BinaryOperator : PT_Plus { $$=new BinaryOperator(boot::PT_Plus); }
	| PT_Minus { $$=new BinaryOperator(boot::PT_Minus); }
	| PT_Division { $$=new BinaryOperator(boot::PT_Division); }
	| PT_IntegerDivision { $$=new BinaryOperator(boot::PT_IntegerDivision); }
	| PT_And { $$=new BinaryOperator(boot::PT_And); }
	| PT_Or { $$=new BinaryOperator(boot::PT_Or); }
	| PT_Multiplication { $$=new BinaryOperator(boot::PT_Multiplication); }
	| PT_Less { $$=new BinaryOperator(boot::PT_Less); }
	| PT_More { $$=new BinaryOperator(boot::PT_More); }
;

MethodCall: PT_Dot
;

FunctionCall: PT_ID LeftRoundBracket ExpressionList RightRoundBracket { $$=new FunctionCall(ToExpr($3), new Identifier($1)); }
;

ExpressionList: { $$=new Expression(exst::Empty_STATE);}
	| Expressions { $$=new Expression(ToExpr($1), exst::List_STATE);}
;

Expressions : Expression { $$=new Expression(ToExpr($1), exst::List_STATE);}
	| Expression PT_Coma Expressions { $$=new Expression(ToExpr($1), ToExpr($3), exst::List_STATE);}
;

ValueT: PT_True { $$=new Value(true);}
	| PT_False { $$=new Value(false);}
	| PT_Number { $$=new Value($1);printf("number \n");}
;

This: PT_This { printf("this \n"); }
;

ClassWord: PT_Class { printf("Class \n"); }
;

ExtendsWord: PT_Extends { printf("Extends \n"); }
;

Equals: PT_Equal { printf("equal \n"); }
;

If: PT_If { printf("if \n"); }
;

Integer: PT_Integer { printf("integer \n"); }
;

Boolean: PT_Boolean { printf("bool \n"); }
;

LeftBrace: PT_LeftBrace { printf("{ \n"); }
;

RightBrace: PT_RightBrace { printf("} \n"); }
;

LeftRoundBracket: PT_LeftRoundBracket { printf("( \n"); }
;

RightRoundBracket: PT_RightRoundBracket { printf(") \n"); }
;

LeftSquareBracket: PT_LeftSquareBracket { printf("[ \n"); }
;

RightSquareBracket: PT_RightSquareBracket { printf("] \n"); }
;

Length: PT_Length { printf("length \n"); }
;

New: PT_New { printf("new \n"); }
;

Not: PT_Negation { printf("not \n"); }
;

Print: PT_Print { printf("print \n"); }
;

Semicolon: PT_Semicolon { printf("; \n"); }
;

While: PT_While { printf("while \n"); }
;

%%
