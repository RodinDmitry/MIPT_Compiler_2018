%{
#include <stdio.h>
#include <stdlib.h>
#include <string>
extern int yylex();
extern "C++" int yyparse();
extern FILE* yyin;

extern void yyerror(const char* s);
extern void dumpBisonToken(std::string token);
%}

%code requires {
#include "../Analyzer/BisonUtils.h"
extern Goal* result;
}

%union {

	int integerValue;
	bool logicalValue;
	char* stringValue;
	
	ITree* node;
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

Goal: MainClass ClassDeclaration {  dumpBisonToken("Red:Goal");result = new Goal(ToMCl($1), ToClDecl($2)); $$ = result;}  
;

MainClass: ClassWord PT_ID LeftBrace MainFunction RightBrace {  dumpBisonToken("Red:MainClass");$$ = new MainClass(ToFunc($4), new Identifier($2)); } 
;

ClassDeclaration: {  dumpBisonToken("Red:ClasDecl");$$ = new ClassDeclaration(cdt::EMPTY_TYPE); }
	| Class ClassDeclaration {  dumpBisonToken("Red:ClasDecl");$$ = new ClassDeclaration(ToClDecl($1),
		ToClDecl($2), cdt::LIST_TYPE); }

Class: ClassStart LeftBrace ClassInternals RightBrace {  dumpBisonToken("Red:Class");$$ = new ClassDeclaration(ToClSt($1),
		ToClInt($3), cdt::CLASS_TYPE); }
;

ClassStart: ClassWord PT_ID Extends { dumpBisonToken("Red:ClasStart");$$ = new ClassStart(new Identifier($2), $3);}
;

Extends: {  dumpBisonToken("Red:extend");$$ = 0; }
	| ExtendsWord PT_ID { dumpBisonToken("Red:extend");$$ = $2;}
;

ClassInternals: {  dumpBisonToken("Red:ClasInt");$$ = new ClassInternals(cit::EMPTY_TYPE); }
	| Function ClassInternals {  dumpBisonToken("Red:ClasInt");$$ = new ClassInternals(ToFunc($1), ToClInt($2), cit::METHOD_TYPE); }
	| Variable Semicolon ClassInternals {  dumpBisonToken("Red:ClasInt");$$ = new ClassInternals(ToVar($1), ToClInt($3), cit::MEMBER_TYPE);}
;

MainFunction: PT_Public PT_Static PT_Void PT_Main LeftRoundBracket MainArgument RightRoundBracket LeftBrace Statement RightBrace { 
		 dumpBisonToken("Red:MainFunc");$$ = new MainMethodDeclaration( ToArg($6), ToState($9) ); }
;

MainArgument: PT_String LeftSquareBracket RightSquareBracket PT_ID {  dumpBisonToken("Red:MainArg");$$ = new Argument(new Identifier($4), aas::LAST_STATE); }
;

Function: Visibility Type PT_ID ArgumentsList LeftBrace Statement Return RightBrace {  dumpBisonToken("Red:function"); $$ = new MethodDeclaration(ToMod($1),
				new Identifier($3), ToArg($4), ToState($6), ToExpr($7), ToType($2)); }
;

Visibility: PT_Public {  dumpBisonToken("Red:public");$$ = new Modifier(mv::PT_Public); }
	| PT_Private {  dumpBisonToken("Red:private");$$ = new Modifier(mv::PT_Private);}
;

Return: PT_Return Expression Semicolon {  dumpBisonToken("Red:return"); $$=new Expression(ToExpr($2), exst::RETURN_STATE);}
;

ArgumentsList: LeftRoundBracket RightRoundBracket { dumpBisonToken("Red:ArgumentList"); $$ = new Argument(aas::EMPTY_STATE); }
	| LeftRoundBracket Argument RightRoundBracket { dumpBisonToken("Red:ArgumentList"); $$ = $2;}
;

Argument : Variable { dumpBisonToken("Red:Argument"); $$ = new Argument(ToVar($1), aas::LAST_STATE); }
	| Variable PT_Coma Argument { dumpBisonToken("Red:Argument"); $$ = new Argument(ToArg($3), ToVar($1), aas::LIST_STATE); }
;

Variable: Type PT_ID { dumpBisonToken("Red:Variable"); $$ = new VarDeclaration(ToType($1), new Identifier($2)); }
;

Type: Integer  {  dumpBisonToken("Red:Type");$$ = new TypeIdentifier(titt::INT_TYPE); }
	| Integer PT_LeftSquareBracket PT_RightSquareBracket  {  dumpBisonToken("Red:Type");$$ = new TypeIdentifier(titt::INTA_TYPE); }
	| Boolean  {  dumpBisonToken("Red:Type");$$ = new TypeIdentifier(titt::BOOL_TYPE); }
	| PT_ID  {  dumpBisonToken("Red:Type");$$ = new TypeIdentifier(new Identifier($1), titt::USER_TYPE); }
	| PT_Void  {  dumpBisonToken("Red:Type");$$ = new TypeIdentifier(titt::VOID_TYPE); }
;

Statement: { dumpBisonToken("Red:Statement"); $$ = new Statement(ToState(nullptr), sst::EMPTY_TYPE); }
	| StatementList Semicolon Statement { dumpBisonToken("Red:Statement"); $$ = new Statement(ToState($1), ToState(nullptr), sst::LIST_TYPE); }
;

StatementList: LeftBrace StatementList RightBrace { dumpBisonToken("Red:StatementList"); $$ = new Statement(ToState($2), sst::SHADE_TYPE); }
	| If LeftRoundBracket Expression RightRoundBracket StatementList PT_Else StatementList { dumpBisonToken("Red:StatementList"); $$ = new Statement(ToExpr($3), ToState($5), ToState($7), sst::IF_TYPE); }
	| While LeftRoundBracket Expression RightRoundBracket  StatementList { dumpBisonToken("Red:StatementList"); $$ = new Statement(ToExpr($3), ToState($5), sst::WHILE_TYPE); }
	| Print LeftRoundBracket Expression RightRoundBracket { dumpBisonToken("Red:StatementList"); $$ = new Statement(ToExpr($3), sst::PRINT_TYPE); }
	| PT_ID Equals Expression { dumpBisonToken("Red:StatementList"); $$ = new Statement(ToExpr($3), new Identifier($1), sst::ASSIGN_TYPE); }
	| Variable { dumpBisonToken("Red:StatementList"); $$ = new Statement(ToVar($1), sst::VAR_TYPE); }


;

Expression: Expression BinaryOperator Expression %prec BINARY { dumpBisonToken("Red:Expression"); $$=new Expression(ToExpr($1), ToExpr($3), ToBinOp($2), exst::BinaryOperator_STATE);}
	| Expression LeftSquareBracket Expression RightSquareBracket %prec ARRAY{ dumpBisonToken("Red:Expression"); $$=new Expression(ToExpr($1), ToExpr($3), exst::SquareBracket_STATE);}
	| Expression MethodCall Length %prec LENGTH { dumpBisonToken("Red:Expression"); $$=new Expression(ToExpr($1), exst::Length_STATE);}
	| Expression MethodCall FunctionCall %prec CALL { dumpBisonToken("Red:Expression"); $$=new Expression(ToExpr($1), ToFcall($3), exst::FunctionCall_STATE);}
	| ValueT { dumpBisonToken("Red:Expression"); $$=new Expression(ToVal($1), exst::Value_STATE);}
	| PT_ID { dumpBisonToken("Red:Expression"); $$=new Expression(new Identifier($1), exst::ID_STATE);}
	| This { dumpBisonToken("Red:Expression"); $$=new Expression(exst::This_State);}
	| New Integer LeftSquareBracket Expression RightSquareBracket { dumpBisonToken("Red:Expression"); $$=new Expression(ToExpr($4), exst::Array_STATE);}
	| New PT_ID LeftRoundBracket RightRoundBracket { dumpBisonToken("Red:Expression"); $$=new Expression(new Identifier($2), exst::NewObj_STATE);}
	| Not Expression %prec NOT { dumpBisonToken("Red:Expression"); $$=new Expression(exst::Not_STATE); }
	| LeftRoundBracket Expression RightRoundBracket %prec BRACKETS { dumpBisonToken("Red:Expression"); $$=$2;}
;

BinaryOperator : PT_Plus { dumpBisonToken("Red:BinaryOperator"); $$=new BinaryOperator(boot::PT_Plus); }
	| PT_Minus { dumpBisonToken("Red:BinaryOperator"); $$=new BinaryOperator(boot::PT_Minus); }
	| PT_Division { dumpBisonToken("Red:BinaryOperator"); $$=new BinaryOperator(boot::PT_Division); }
	| PT_IntegerDivision { dumpBisonToken("Red:BinaryOperator"); $$=new BinaryOperator(boot::PT_IntegerDivision); }
	| PT_And { dumpBisonToken("Red:BinaryOperator"); $$=new BinaryOperator(boot::PT_And); }
	| PT_Or { dumpBisonToken("Red:BinaryOperator"); $$=new BinaryOperator(boot::PT_Or); }
	| PT_Multiplication {  dumpBisonToken("Red:BinaryOperator"); $$=new BinaryOperator(boot::PT_Multiplication); }
	| PT_Less {  dumpBisonToken("Red:BinaryOperator"); $$=new BinaryOperator(boot::PT_Less); }
	| PT_More {  dumpBisonToken("Red:BinaryOperator"); $$=new BinaryOperator(boot::PT_More); }
;

MethodCall: PT_Dot { dumpBisonToken("Red:Dot");}
;

FunctionCall: PT_ID LeftRoundBracket ExpressionList RightRoundBracket {  dumpBisonToken("Red:functionCall"); $$=new FunctionCall(ToExpr($3), new Identifier($1)); }
;

ExpressionList: {  dumpBisonToken("Red:expressionList"); $$=new Expression(exst::Empty_STATE);}
	| Expressions {  dumpBisonToken("Red:expresionList"); $$=new Expression(ToExpr($1), exst::List_STATE);}
;

Expressions : Expression {  dumpBisonToken("Red:expressions"); $$=new Expression(ToExpr($1), exst::List_STATE);}
	| Expression PT_Coma Expressions {  dumpBisonToken("Red:expressions"); $$=new Expression(ToExpr($1), ToExpr($3), exst::List_STATE);}
;

ValueT: PT_True {  dumpBisonToken("Red:value"); $$=new Value(true);}
	| PT_False {  dumpBisonToken("Red:value"); $$=new Value(false);}
	| PT_Number {  dumpBisonToken("Red:value"); $$=new Value($1);}
;

This: PT_This {  dumpBisonToken("this"); }
;

ClassWord: PT_Class {  dumpBisonToken("class"); }
;

ExtendsWord: PT_Extends { dumpBisonToken("extend"); }
;

Equals: PT_Equal {  dumpBisonToken("equal"); }
;

If: PT_If {  dumpBisonToken("if"); }
;

Integer: PT_Integer {  dumpBisonToken("int"); }
;

Boolean: PT_Boolean {  dumpBisonToken("bool"); }
;

LeftBrace: PT_LeftBrace {  dumpBisonToken("{"); }
;

RightBrace: PT_RightBrace {  dumpBisonToken("}"); }
;

LeftRoundBracket: PT_LeftRoundBracket {  dumpBisonToken("("); }
;

RightRoundBracket: PT_RightRoundBracket {  dumpBisonToken(")"); }
;

LeftSquareBracket: PT_LeftSquareBracket {  dumpBisonToken("["); }
;

RightSquareBracket: PT_RightSquareBracket {  dumpBisonToken("]"); }
;

Length: PT_Length {  dumpBisonToken("length"); }
;

New: PT_New {  dumpBisonToken("new"); }
;

Not: PT_Negation {  dumpBisonToken("!"); }
;

Print: PT_Print {  dumpBisonToken("print"); }
;

Semicolon: PT_Semicolon {  dumpBisonToken("semicolon"); }
;

While: PT_While { dumpBisonToken("while"); }
;

%%
