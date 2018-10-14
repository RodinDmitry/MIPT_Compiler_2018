%option noyywrap

%{
#include <iostream>
#include <grammar.tab.h>

#define YY_DECL int yylex()

%}

%%

[\n] ; // ignore end lines
[ \t]	; // ignore all whitespace
[0-9]+		{ std::cout << PT_Number << yytext << " ";};
"static" { std::cout << PT_Static << " ";};
"public" { std::cout << PT_Public << " ";};
"private" { std::cout << PT_Private << " ";};

"void" {std::cout << PT_Void << " ";};
"main" {std::cout << PT_Main << " ";};
"class" {std::cout << PT_Class << " ";};
"extends" {std::cout << PT_Extends << " "}
"(" {std::cout << PT_LeftRoundBracket << " ";};
")" {std::cout << PT_RightRoundBracket << " ";};
"String" {std::cout << PT_String << " ";};
"[" {std::cout << PT_LeftSquareBracket << " ";};
"]" {std::cout << PT_LeftSquareBracket << " ";};
"{" {std::cout << PT_LeftBrace << " ";};
"}" {std::cout << PT_RightBrace << " ";};
"int" {std::cout << PT_Integer << " ";};
"boolean" {std::cout << PT_Boolean << " ";};
"System.out.println" {std::cout << PT_Print << " ";};
"if" {std::cout << PT_If << " ";};
"while" {std::cout << PT_While << " ";};
"length" {std::cout << PT_Length << " ";};
"true" {std::cout << PT_True << " ";};
"false" {std::cout << PT_False << " ";};
"this" {std::cout << PT_This << " " ;};
"new" {std::cout << PT_New << " ";};
"return" {std::cout << PT_Return << " "}
"!" {std::cout << PT_Negation << " ";};
"&&" {std::cout << PT_And << " ";};
"<" {std::cout << PT_Less << " ";};
">" {std::cout << PT_More << " ";};
"+" {std::cout << PT_Plus << " ";};
"-" {std::cout << PT_Minus << " ";};
"*" {std::cout << PT_Multiplication << " ";};
"%" {std::cout << PT_IntegerDivision << " ";};
"/" {std::cout << PT_Division << " ";}
"||" {std::cout << PT_Or << " ";};
"=" {std::cout << PT_Equal << " ";};
";" {std::cout << PT_Semicolon << " ";};
"." {std::cout << PT_Dot << " ";};
"," {std::cout << PT_Coma << " ";}
[a-zA-z]+[a-zA-Z0-9_]* {{ std::cout << PT_ID << yytext << " ";};}


%%