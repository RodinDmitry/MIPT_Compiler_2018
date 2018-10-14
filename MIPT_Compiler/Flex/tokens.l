%option noyywrap

%{
#include <iostream>
#include <grammar.tab.h>

#define YY_DECL int yylex()

%}

%%

[\n] ; // ignore end lines
[ \t]	; // ignore all whitespace
[0-9]+		{ return PT_Number  ;};
"static" { return PT_Static  ;};
"public" { return PT_Public  ;};
"private" { return PT_Private  ;};

"void" {return PT_Void  ;};
"main" {return PT_Main  ;};
"class" {return PT_Class  ;};
"extends" {return PT_Extends  }
"(" {return PT_LeftRoundBracket  ;};
")" {return PT_RightRoundBracket  ;};
"String" {return PT_String  ;};
"[" {return PT_LeftSquareBracket  ;};
"]" {return PT_LeftSquareBracket  ;};
"{" {return PT_LeftBrace  ;};
"}" {return PT_RightBrace  ;};
"int" {return PT_Integer  ;};
"boolean" {return PT_Boolean  ;};
"System.out.println" {return PT_Print  ;};
"if" {return PT_If  ;};
"while" {return PT_While  ;};
"length" {return PT_Length  ;};
"true" {return PT_True  ;};
"false" {return PT_False  ;};
"this" {return PT_This   ;};
"new" {return PT_New  ;};
"return" {return PT_Return  }
"!" {return PT_Negation  ;};
"&&" {return PT_And  ;};
"<" {return PT_Less  ;};
">" {return PT_More  ;};
"+" {return PT_Plus  ;};
"-" {return PT_Minus  ;};
"*" {return PT_Multiplication  ;};
"%" {return PT_IntegerDivision  ;};
"/" {return PT_Division  ;}
"||" {return PT_Or  ;};
"=" {return PT_Equal  ;};
";" {return PT_Semicolon  ;};
"." {return PT_Dot  ;};
"," {return PT_Coma  ;}
[a-zA-z]+[a-zA-Z0-9_]* {{ return PT_ID  ;};}


%%