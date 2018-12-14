%option noinput nounput noyywrap nodefault                                 
%option yylineno
%option reentrant bison-bridge bison-locations 

%{
#include <iostream>
#include <string>
#include <grammar.tab.h>

#include <ErrorTable.h>
extern void dumpToken(std::string token);

#define YY_DECL int yylex(YYSTYPE* yylval_param, YYLTYPE* yylloc_param, yyscan_t yyscanner, CMainCompiler* compiler)

#define YY_USER_ACTION yylloc->first_line = yylloc->last_line = yylineno;
%}

%%

"//"[^\n]*"\n" {dumpToken("ñomment\n");} ;
[\n] ; {dumpToken("\n");}
[ \t]	; // ignore all whitespace
[0-9]+  { dumpToken("number"); yylval->integerValue = atoi(yytext); return PT_Number;};
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
"true" {dumpToken("true"); yylval->logicalValue = true; return PT_True;};
"false" {dumpToken("false"); yylval->logicalValue = false; return PT_False;};
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
"=" {dumpToken("="); return PT_Assign;};
";" {dumpToken(";"); return PT_Semicolon;};
"." {dumpToken("."); return PT_Dot;};
"," {dumpToken(","); return PT_Coma;};
[a-zA-Z]+[a-zA-Z0-9_]* { 
		dumpToken("ID");
		yylval->stringValue = (char*) std::malloc(strlen(yytext)+1);
		strcpy_s(yylval->stringValue, strlen(yytext)+1, yytext);
		return PT_ID;
	};

[^,\.;=|/\%\*\-+><!&\(\)\[\]\{\} \t\n]* { 
	dumpToken(yytext);
	CErrorTable::AddError("Bad Token", yylloc->first_line);
	return PT_Error; }

%%

void yyerror(YYLTYPE* yyllocp, yyscan_t unused, CMainCompiler* compiler, const char* msg) {
	//std::cerr << msg << " in line: " << yylineno << std::endl;
	CErrorTable::AddError(msg, yyllocp->first_line);
};