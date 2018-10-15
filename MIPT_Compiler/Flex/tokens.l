%option noyywrap

%{
#include <iostream>
#include <grammar.tab.h>

#define YY_DECL int yylex()

%}

%%

[\n] ; // ignore end lines
[ \t]	; // ignore all whitespace
[0-9]+  { yylval.integerValue = atoi(yytext); return PT_Number;};
"static" { return PT_Static;};
"public" { return PT_Public;};
"private" { return PT_Private;};

"void" {printf("Class \n");return PT_Void;};
"main" {printf("Class \n");return PT_Main;};
"class" {printf("Class \n");return PT_Class;};
"extends" {printf("Class \n");return PT_Extends; }
"(" {printf("Class \n");return PT_LeftRoundBracket;};
")" {printf("Class \n");return PT_RightRoundBracket;};
"String" {printf("Class \n");return PT_String;};
"[" {printf("Class \n");return PT_LeftSquareBracket;};
"]" {printf("Class \n");return PT_LeftSquareBracket;};
"{" {printf("Class \n");return PT_LeftBrace;};
"}" {printf("Class \n");return PT_RightBrace;};
"int" {printf("Class \n");return PT_Integer;};
"boolean" {printf("Class \n");return PT_Boolean;};
"System.out.println" {printf("Class \n");return PT_Print;};
"if" {printf("Class \n");return PT_If;};
"while" {return PT_While;};
"length" {return PT_Length;};
"true" {yylval.logicalValue = true; return PT_True;};
"false" {yylval.logicalValue = false; return PT_False;};
"this" {return PT_This;};
"new" {return PT_New;};
"return" {return PT_Return;}
"!" {return PT_Negation;};
"&&" {return PT_And;};
"<" {return PT_Less;};
">" {return PT_More;};
"+" {return PT_Plus;};
"-" {return PT_Minus;};
"*" {return PT_Multiplication;};
"%" {return PT_IntegerDivision;};
"/" {return PT_Division;}
"||" {return PT_Or;};
"=" {return PT_Equal;};
";" {return PT_Semicolon;};
"." {return PT_Dot;};
"," {return PT_Coma;};
[a-zA-z]+[a-zA-Z0-9_]* {
		yylval.stringValue = (char*) std::malloc(strlen(yytext)+1);
		strcpy_s(yylval.stringValue, strlen(yytext)+1, yytext);
		return PT_ID;
	};

%%