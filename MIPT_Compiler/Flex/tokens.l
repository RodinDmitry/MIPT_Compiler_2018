%option noyywrap

%{
#include <iostream>
#include <string>
#include <grammar.tab.h>

#define YY_DECL int yylex()
extern void dumpToken(std::string token);
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;
%}
%option yylineno

%%

"//"[^\n]*"\n" {dumpToken("ñomment\n");} ;
[\n] ; {dumpToken("\n");}
[ \t]	; // ignore all whitespace
[0-9]+  { dumpToken("number"); yylval.integerValue = atoi(yytext); return PT_Number;};
"static" { dumpToken("static"); return PT_Static;};
"public" { dumpToken("public"); return PT_Public;};
"private" { dumpToken("private"); return PT_Private;};

"void" {dumpToken("void"); return PT_Void;};
"main" {dumpToken("main"); return PT_Main;};
"class" {dumpToken("class"); return PT_Class;};
"extends" {dumpToken("extends"); return PT_Extends; }
"(" {dumpToken("("); return PT_LeftRoundBracket;};
")" {dumpToken(")"); return PT_RightRoundBracket;};
"String" {dumpToken("String"); return PT_String;};
"[" {dumpToken("["); return PT_LeftSquareBracket;};
"]" {dumpToken("]"); return PT_RightSquareBracket;};
"{" {dumpToken("{"); return PT_LeftBrace;};
"}" {dumpToken("}"); return PT_RightBrace;};
"int" {dumpToken("int"); return PT_Integer;};
"boolean" {dumpToken("boolean"); return PT_Boolean;};
"System.out.println" {dumpToken("println"); return PT_Print;};
"if" {dumpToken("if"); return PT_If;};
"else" {dumpToken("else"); return PT_Else;};
"while" {dumpToken("while"); return PT_While;};
"length" {dumpToken("length"); return PT_Length;};
"true" {dumpToken("true"); yylval.logicalValue = true; return PT_True;};
"false" {dumpToken("false"); yylval.logicalValue = false; return PT_False;};
"this" {dumpToken("this"); return PT_This;};
"new" {dumpToken("new"); return PT_New;};
"return" {dumpToken("return"); return PT_Return;}
"!" {dumpToken("!"); return PT_Negation;};
"&&" {dumpToken("&&"); return PT_And;};
"<" {dumpToken("<"); return PT_Less;};
">" {dumpToken(">"); return PT_More;};
"+" {dumpToken("+"); return PT_Plus;};
"-" {dumpToken("-"); return PT_Minus;};
"*" {dumpToken("*"); return PT_Multiplication;};
"%" {dumpToken("%"); return PT_IntegerDivision;};
"/" {dumpToken("/"); return PT_Division;}
"||" {dumpToken("||"); return PT_Or;};
"=" {dumpToken("="); return PT_Equal;};
";" {dumpToken(";"); return PT_Semicolon;};
"." {dumpToken("."); return PT_Dot;};
"," {dumpToken(","); return PT_Coma;};
[a-zA-Z]+[a-zA-Z0-9_]* { 
		dumpToken("ID");
		yylval.stringValue = (char*) std::malloc(strlen(yytext)+1);
		strcpy_s(yylval.stringValue, strlen(yytext)+1, yytext);
		return PT_ID;
	};

[^,\.;=|/\%\*-+><!&\(\)\[\]\{\} \t\n]* { 
	dumpToken(yytext);
	fprintf(stderr, "Line %d: Bad token %s.\n", yylloc.first_line, yytext);
	return PT_Error; }

%%

void yyerror(ITree* tree, const char* s) {
	//std::cerr << s << " in line: " << yylineno << std::endl;
};