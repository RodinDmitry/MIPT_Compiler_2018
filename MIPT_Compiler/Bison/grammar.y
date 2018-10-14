%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);
%}

%union {
	int integerValue;
	bool logicalValue;
	std::strnig stringValue;
}

// ����
%token PT_Void
%token<stringValue> PT_String 
%token<integerValue> PT_Integer PT_Number
%token<logicalValue> PT_Boolean
//���������� ���������
%token<logicalValue> PT_True PT_False
// ����� ��� �������
%token PT_Class PT_Static PT_Public PT_Private PT_Extends
//����� �����
%token PT_Main
// �����
%token PT_Print
//�������� ���������
%token PT_If PT_While PT_Else
// ���-��
%token PT_Length
// �������� �����
%token PT_This PT_New
%token PT_Semicolon
// ����������
%token PT_ID
%token PT_EOF
%token PT_Dot
%token PT_Coma
%token PT_Return

%left PT_LeftRoundBracket PT_LeftSquareBracket PT_LeftBrace 
%left PT_RightRoundBracket PT_RightSquareBracket PT_RightBrace
%left PT_Dot
%left PT_And PT_Or
%left PT_Multiplication PT_Division PT_IntegerDivision
%left PT_More PT_Less
%left PT_Equal
%left PT_Plus PT_Minus
%left PT_Negation

%left BRACKETS
%left ARRAY
%left CALL LENGTH
%left NEW_INT NEW_ID
%left BINARY
%left NOT

%start Goal

%%

Goal: MainClass ClassDeclaration EndOfFile { printf("Start \n"); }  
;

MainClass: ClassWord PT_ID LeftBrace MainFunction RightBrace { printf("MainClass \n"); } 
;

ClassDeclaration: 
	| Class ClassDeclaration

Class: ClassStart LeftBrace ClassInternals RightBrace { printf("Class \n"); }
;

ClassStart: ClassWord PT_ID Extends
;

Extends: 
	| ExtendsWord PT_ID
;

ClassInternals: { printf("Empty internals \n"); }
	| Function ClassInternals { printf("Function \n"); }
	| Variable ClassInternals { printf("Filed \n"); }
;

MainFunction: PT_Public PT_Static PT_Void PT_Main MainArgument LeftBrace Statement RightBrace { printf("Main \n"); }
;

MainArgument: PT_String PT_LeftSquareBracket PT_RightSquareBracket PT_ID
;

Function: Visibility PT_ID ArgumentsList LeftBrace Statement Return RightBrace { printf("Function Decl \n"); }
;

Visibility: PT_Public
	| PT_Private
;

Return: PT_Return Expression Semicolon
;

ArgumentsList: LeftRoundBracket RightRoundBracket { printf("Zero Argumens \n"); }
	| LeftRoundBracket Argument RightRoundBracket { printf("Argument List \n"); }
;

Argument : Variable { printf("Last Variable \n"); }
	| Variable PT_Coma Argument { printf("Variable \n"); }
;

Variable: Type PT_ID Semicolon { printf("Variable \n"); }
;

Type: Integer  { printf("Integer \n"); }
	| Integer PT_LeftSquareBracket PT_RightSquareBracket { printf("Array of Int \n"); }
	| Boolean { printf("Bool \n"); }
	| PT_ID { printf("User Type \n"); }
;

Statement: { printf("Empty Statement \n"); }
	| StatementList { printf("Non empty statement \n"); }
;

StatementList: LeftBrace StatementList RightBrace { printf("Visibility \n"); }
	| If LeftRoundBracket Expression RightRoundBracket StatementList PT_Else Statement
	| While LeftRoundBracket Expression RightRoundBracket  StatementList
	| Print LeftRoundBracket Expression RightRoundBracket Semicolon
	| PT_ID Equals Expression Semicolon
	| PT_ID PT_LeftSquareBracket Expression PT_RightSquareBracket Equals Expression Semicolon

;

Expression: Expression BinaryOperator Expression %prec BINARY
	| Expression PT_LeftSquareBracket Expression PT_RightSquareBracket %prec ARRAY
	| Expression MethodCall Length %prec LENGTH
	| Expression MethodCall FunctionCall %prec CALL
	| IntegerLiteral
	| True
	| False
	| PT_ID
	| This
	| New Integer PT_LeftSquareBracket Expression PT_RightSquareBracket %prec NEW_INT
	| New PT_ID LeftRoundBracket RightRoundBracket  %prec NEW_ID
	| Not Expression %prec NOT
	| LeftRoundBracket Expression RightRoundBracket %prec BRACKETS
;

BinaryOperator : PT_Plus
	| PT_Minus
	| PT_Division
	| PT_IntegerDivision
	| PT_And
	| PT_Or
	| PT_Multiplication
	| PT_Less
	| PT_More
;

MethodCall: PT_Dot
;

FunctionCall: PT_ID LeftRoundBracket ExpressionList RightRoundBracket
;

ExpressionList: 
	| Expressions
;

Expressions : Expression
	| Expression PT_Coma Expression
;

True: PT_True
;

False: PT_False
;

This: PT_This
;

ClassWord: PT_Class { printf("Class \n"); }
;

EndOfFile: PT_EOF { printf("EOF \n"); }

ExtendsWord: PT_Extends { printf("Extends \n"); }
;

Equals: PT_Equal
;

If: PT_If
;

Integer: PT_Integer
;

IntegerLiteral: PT_Number
;

Boolean: PT_Boolean
;

LeftBrace: PT_LeftBrace
;

RightBrace: PT_RightBrace
;

LeftRoundBracket: PT_LeftRoundBracket
;

RightRoundBracket: PT_RightRoundBracket
;

Length: PT_Length
;

New: PT_New
;

Not: PT_Negation
;

Print: PT_Print
;

Semicolon: PT_Semicolon
;

While: PT_While
;

%%

%left PT_Less PT_More PT_Equals
%left PT_Plus PT_Minus
%left PT_Division PT_IntegerDivision PT_Multiplication