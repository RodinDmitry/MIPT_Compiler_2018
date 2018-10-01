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

// Типы
%token PT_Void
%token<stringValue> PT_String 
%token<integerValue> PT_Integer PT_Number
%token<logicalValue> PT_Boolean
//Логические константы
%token<logicalValue> PT_True PT_False
// Части для классов
%token PT_Class PT_Static PT_Public PT_Private
//Точка входа
%token PT_Main
// Скобки 
%token PT_LeftRoundBracket PT_LeftSquareBracket PT_LeftBrace 
%token PT_RightRoundBracket PT_RightSquareBracket PT_RightBrace
// Принт
%token PT_Print
//Условные операторы
%token PT_If PT_While PT_Else
// Что-то
%token PT_Length
// Ключевые слова
%token PT_This PT_New
// Логические операции
%token PT_Negation PT_And PT_Or
// Сравнения
%token PT_More PT_Less
// Арифмметические операции
%token PT_Plus PT_Minus
%token PT_Multiplication PT_Division PT_IntegerDivision PT_Equal
// Точка с запятой
%token PT_Semicolon
// Переменная
%token PT_ID

%start calculation

%%

calculation: 
	   | 
;

%%
