%pure-parser
%lex-param { yyscan_t scanner }
%parse-param { yyscan_t scanner }
%parse-param { CMainCompiler* compiler}
%lex-param { CMainCompiler* compiler}
%{
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Tree.h>


%}

%code requires {
#include "../Analyzer/BisonUtils.h"
#include <iostream>
#include <MainCompiler.h>
typedef void* yyscan_t;
}


%code{
extern int yylex(YYSTYPE* yylvalp, YYLTYPE* yyllocp, yyscan_t scanner, CMainCompiler* compiler);
extern void yyerror(YYLTYPE* yyllocp, yyscan_t unused, CMainCompiler* compiler, const char* msg);
}



%define parse.lac full

%union {

	int integerValue;
	bool logicalValue;
	char* stringValue;
	
	ITree* node;
}
%locations

%token PT_Error
// Òèïû
%token PT_Void
%token PT_String 
%token<integerValue> PT_Number
%token PT_Boolean PT_Integer
//Ëîãè÷åñêèå êîíñòàíòû
%token<logicalValue> PT_True PT_False
// ×àñòè äëÿ êëàññîâ
%token PT_Class PT_Static PT_Public PT_Private PT_Extends
//Òî÷êà âõîäà
%token PT_Main
// Ïðèíò
%token PT_Print
//Óñëîâíûå îïåðàòîðû
%token PT_If PT_While PT_Else
// ×òî-òî
%token PT_Length
// Êëþ÷åâûå ñëîâà
%token PT_This PT_New
// Ëîãè÷åñêèå îïåðàöèè

// Òî÷êà ñ çàïÿòîé
%token PT_Semicolon
// Ïåðåìåííàÿ
%token<stringValue> PT_ID
%token PT_Dot
%token PT_Coma
%token PT_Return

%type<node> ValueT
%type<node> Expression
%type<integerValue> BinaryOperator
%type<node> FunctionCall
%type<node> Expressions
%type<node> ExpressionList
%type<node> Type
%type<node> Statement
%type<node> StatementItem
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
%type<node> LvalueExpression

%destructor { free($$); } <stringValue>

%left PT_LeftRoundBracket PT_LeftSquareBracket PT_LeftBrace 
%left PT_RightRoundBracket PT_RightSquareBracket PT_RightBrace
%left PT_Dot
%left PT_Negation 
%left PT_Multiplication PT_Division PT_IntegerDivision 
%left PT_Assign PT_And PT_Or PT_More PT_Less PT_Plus PT_Minus

%left BRACKETS
%left ARRAY
%left LENGTH CALL
%right NOT 
%left BINARY 
%left PT_If
%left PT_Else

%start Goal

%%

Goal: MainClass ClassDeclaration { $$ = new CProgram(To<CMain>($1), To<CClassList>($2), @1.first_line); compiler->SetRoot($$);
} 
	| error MainClass ClassDeclaration { compiler->dumpSyntaxError("Bad class definition", @1.first_line);
										$$ = new CProgram(To<CMain>($2), To<CClassList>($3), @1.first_line);  yyerrok;} 
;

MainClass: ClassWord PT_ID LeftBrace MainFunction RightBrace { $$ = new CMain(new CId($2, @2.first_line), To<CMainFunction>($4), @1.first_line);free($2);} 
;

ClassDeclaration: { $$ = new CClassList(); }
	| Class ClassDeclaration { To<CClassList>($2)->Add(To<CClass>($1)); $$ = $2; }

Class: ClassStart LeftBrace ClassInternals RightBrace { $$ = new CClass(To<CClassDeclaration>($1), To<CClassInternalsList>($3), @1.first_line);}
    | error {compiler->dumpSyntaxError("Bad class definition", @1.first_line); yyerrok; $$ = nullptr; };

ClassStart: ClassWord PT_ID Extends { $$ = new CClassDeclaration(new CId($2, @2.first_line), new CId($3, @3.first_line), @1.first_line); free($2);}
;

Extends: { $$ = nullptr; }
	| ExtendsWord PT_ID { $$ = $2;}
;

ClassInternals: {  $$ = new CClassInternalsList(); }
	| Function ClassInternals { To<CClassInternalsList>($2)->Add(new CClassInternals(To<CFunction>($1), @1.first_line)); $$ = $2;}
	| Variable Semicolon ClassInternals { To<CClassInternalsList>($3)->Add(new CClassInternals(To<CVariable>($1), @1.first_line)); $$ = $3;}
	| error ClassInternals {compiler->dumpSyntaxError("Bad method or member", @1.first_line); yyerrok; $$ = $2; };

MainFunction: PT_Public PT_Static PT_Void PT_Main LeftRoundBracket MainArgument RightRoundBracket LeftBrace Statement RightBrace { 
		 $$ = new CMainFunction(To<CMainArgument>($6), To<CStatementList>($9), @1.first_line); }
;

MainArgument: PT_String LeftSquareBracket RightSquareBracket PT_ID {  $$ = new CMainArgument(new CId($4, @4.first_line), @1.first_line);free($4); }
;

Function: Visibility Type PT_ID ArgumentsList LeftBrace Statement Return RightBrace 
{ $$ = new CFunction(To<CModifier>($1), new CId($3, @3.first_line), To<CArgumentList>($4), To<CStatementList>($6), To<CType>($2), To<CReturnStatement>($7), @1.first_line); free($3);}
;

Visibility: PT_Public { $$ = new CModifier(TVisabilityModifierType::VMT_Public); }
	| PT_Private { $$ = new CModifier(TVisabilityModifierType::VMT_Private); }
;

Return: PT_Return Expression Semicolon { $$ = new CReturnStatement(To<IExpression>($2), @1.first_line); }
;

ArgumentsList: LeftRoundBracket RightRoundBracket { $$ = new CArgumentList(); }
	| LeftRoundBracket Argument RightRoundBracket { $$ = $2;}
;

Argument : Variable { $$ = new CArgumentList(); To<CArgumentList>($$)->Add(To<CVariable>($1));}
	| Variable PT_Coma Argument {  To<CArgumentList>($3)->Add(To<CVariable>($1)); $$ = $3; }
;

Variable: Type PT_ID { $$ = new CVariable(To<CType>($1), new CId($2, @2.first_line), @1.first_line); free($2);}
;

Type: Integer  { $$ = new CType(TDataType::DT_Integer, @1.first_line); }
	| Integer PT_LeftSquareBracket PT_RightSquareBracket  { $$ = new CType(TDataType::DT_IntegerArray, @1.first_line); }
	| Boolean  { $$ = new CType(TDataType::DT_Boolean, @1.first_line); }
	| PT_ID { $$ = new CType($1, @1.first_line); free($1);}
	| PT_Void  { $$ = new CType(); }
;

Statement: { $$ = new CStatementList();}
	| StatementItem Statement { To<CStatementList>($2)->Add(To<IStatement>($1)); $$=$2;}
	| error Statement {compiler->dumpSyntaxError("Bad Statement", @1.first_line); $$ = $2; yyerrok; }
;

StatementItem: LeftBrace Statement RightBrace { $$ = new CVisibilityStatement(To<IStatement>($2), @1.first_line); }
	| PT_If LeftRoundBracket Expression RightRoundBracket StatementItem PT_Else StatementItem { $$ = new CIfStatement(To<IExpression>($3), To<IStatement>($5), To<IStatement>($7), @1.first_line); }
	| PT_If LeftRoundBracket Expression RightRoundBracket StatementItem { $$ =  new CIfStatement(To<IExpression>($3), To<IStatement>($5), nullptr, @1.first_line); }
	| While LeftRoundBracket Expression RightRoundBracket  StatementItem { $$ = new CWhileStatement(To<IExpression>($3), To<IStatement>($5), @1.first_line); }
	| Print LeftRoundBracket Expression RightRoundBracket Semicolon { $$ = new CPrintStatement(To<IExpression>($3), @1.first_line); }
	| LvalueExpression Assign Expression Semicolon { $$ = new CAssignStatement(To<CLValueExpression>($1), To<IExpression>($3), @1.first_line); }
	| Variable Semicolon { $$ = new CVariableStatement(To<CVariable>($1), @1.first_line); }
;

LvalueExpression: 
	Expression LeftSquareBracket Expression RightSquareBracket %prec ARRAY{ $$=new CArrayExpression(To<IExpression>($1), To<IExpression>($3), @1.first_line);}
	| LvalueExpression MethodCall FunctionCall %prec CALL { To<CCallExpression>($3)->caller.reset(To<IExpression>($1)); $$=$3;}
	| PT_ID { $$=new CIdExpression(new CId ($1, @1.first_line), @1.first_line); free($1);}
	| This { $$=new CThisExpression();}
	| New PT_ID LeftRoundBracket RightRoundBracket { $$=new CNewExpression(new CId($2, @2.first_line), @1.first_line); free($2);}
	| LeftRoundBracket Expression RightRoundBracket %prec BRACKETS { $$ = new CBracketsExpression(To<IExpression>($2), @1.first_line);}
;

Expression: LvalueExpression { $$=$1; }
	| Expression BinaryOperator Expression %prec BINARY { $$=new CBinaryExpression(To<IExpression>($1), To<IExpression>($3), static_cast<CBinaryExpression::TOperator>($2), @1.first_line);}	
	| LvalueExpression MethodCall Length %prec LENGTH { $$ = new CCallLengthExpression(To<IExpression>($1), @1.first_line);}	
	| ValueT { $$=new CValueExpression(To<IValue>($1), @1.first_line); }
	| New Integer LeftSquareBracket Expression RightSquareBracket { $$=new CNewArrayExpression(To<IExpression>($4), @1.first_line);}
	| Not Expression %prec NOT { $$ = new CNotExpression(To<IExpression>($2), @1.first_line); }
;

BinaryOperator : PT_Plus { $$=CBinaryExpression::O_Plus; }
	| PT_Minus { $$=CBinaryExpression::O_Minus; }
	| PT_Division { $$=CBinaryExpression::O_Division; }
	| PT_IntegerDivision { $$=CBinaryExpression::O_IntegerDivision; }
	| PT_And { $$=CBinaryExpression::O_And; }
	| PT_Or { $$=CBinaryExpression::O_Or; }
	| PT_Multiplication { $$=CBinaryExpression::O_Multiplication; }
	| PT_Less { $$=CBinaryExpression::O_Less; }
	| PT_More { $$=CBinaryExpression::O_More; }
;

MethodCall: PT_Dot {}
;

FunctionCall: PT_ID LeftRoundBracket ExpressionList RightRoundBracket { $$=new CCallExpression(To<IExpression>(nullptr), new CId($1, @1.first_line), To<CExpressionList>($3), @1.first_line);free($1); }
;

ExpressionList: { $$=new CExpressionList(); }
	| Expressions { $$ = $1; }
	| error ExpressionList {compiler->dumpSyntaxError("Bad expression", @1.first_line); yyerrok; $$ = $2; }
;

Expressions : Expression { $$=new CExpressionList(); To<CExpressionList>($$)->Add(To<IExpression>($1)); }
	| Expression PT_Coma Expressions { $$=$3; To<CExpressionList>($$)->Add(To<IExpression>($1)); }
;

ValueT: PT_True { $$=new CValue(true, CValue::T_Boolean); }
	| PT_False { $$=new CValue(true, CValue::T_Boolean); }
	| PT_Number { $$=new CValue($1, CValue::T_Integer); }
;

This: PT_This {  compiler->dumpBisonToken("this"); }
;

ClassWord: PT_Class {  compiler->dumpBisonToken("class"); }
;

ExtendsWord: PT_Extends { compiler->dumpBisonToken("extend"); }
;

Assign: PT_Assign {  compiler->dumpBisonToken("assign"); }
;

Integer: PT_Integer {  compiler->dumpBisonToken("int"); }
;

Boolean: PT_Boolean {  compiler->dumpBisonToken("bool"); }
;

LeftBrace: PT_LeftBrace {  compiler->dumpBisonToken("{"); }
;

RightBrace: PT_RightBrace {  compiler->dumpBisonToken("}"); }
;

LeftRoundBracket: PT_LeftRoundBracket {  compiler->dumpBisonToken("("); }
;

RightRoundBracket: PT_RightRoundBracket {  compiler->dumpBisonToken(")"); }
;

LeftSquareBracket: PT_LeftSquareBracket {  compiler->dumpBisonToken("["); }
;

RightSquareBracket: PT_RightSquareBracket {  compiler->dumpBisonToken("]"); }
;

Length: PT_Length {  compiler->dumpBisonToken("length"); }
;

New: PT_New {  compiler->dumpBisonToken("new"); }
;

Not: PT_Negation {  compiler->dumpBisonToken("!"); }
;

Print: PT_Print {  compiler->dumpBisonToken("print"); }
;

Semicolon: PT_Semicolon {  compiler->dumpBisonToken("semicolon"); }
;

While: PT_While { compiler->dumpBisonToken("while"); }
;

%%