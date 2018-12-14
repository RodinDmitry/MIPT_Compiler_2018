%option noinput nounput noyywrap nodefault                                 
%option yylineno
%option reentrant bison-bridge bison-locations 

%{
#include <iostream>
#include <string>
#include <grammar.tab.h>

#include <ErrorTable.h>
#define YY_DECL int yylex(YYSTYPE* yylval_param, YYLTYPE* yylloc_param, yyscan_t yyscanner, CMainCompiler* compiler)

#define YY_USER_ACTION yylloc->first_line = yylloc->last_line = yylineno;
%}

%%

"//"[^\n]*"\n" {compiler->dumpLexToken("ñomment\n");} ;
[\n] ; {compiler->dumpLexToken("\n");}
[ \t]	; // ignore all whitespace
[0-9]+  { compiler->dumpLexToken("number"); yylval->integerValue = atoi(yytext); return PT_Number;};
"static" { compiler->dumpLexToken("static"); return PT_Static;};
"public" { compiler->dumpLexToken("public"); return PT_Public;};
"private" { compiler->dumpLexToken("private"); return PT_Private;};

"void" {compiler->dumpLexToken("void"); return PT_Void;};
"main" {compiler->dumpLexToken("main"); return PT_Main;};
"class" {compiler->dumpLexToken("class"); return PT_Class;};
"extends" {compiler->dumpLexToken("extends"); return PT_Extends; }
"(" {compiler->dumpLexToken("("); return PT_LeftRoundBracket;};
")" {compiler->dumpLexToken(")"); return PT_RightRoundBracket;};
"String" {compiler->dumpLexToken("String"); return PT_String;};
"[" {compiler->dumpLexToken("["); return PT_LeftSquareBracket;};
"]" {compiler->dumpLexToken("]"); return PT_RightSquareBracket;};
"{" {compiler->dumpLexToken("{"); return PT_LeftBrace;};
"}" {compiler->dumpLexToken("}"); return PT_RightBrace;};
"int" {compiler->dumpLexToken("int"); return PT_Integer;};
"boolean" {compiler->dumpLexToken("boolean"); return PT_Boolean;};
"System.out.println" {compiler->dumpLexToken("println"); return PT_Print;};
"if" {compiler->dumpLexToken("if"); return PT_If;};
"else" {compiler->dumpLexToken("else"); return PT_Else;};
"while" {compiler->dumpLexToken("while"); return PT_While;};
"length" {compiler->dumpLexToken("length"); return PT_Length;};
"true" {compiler->dumpLexToken("true"); yylval->logicalValue = true; return PT_True;};
"false" {compiler->dumpLexToken("false"); yylval->logicalValue = false; return PT_False;};
"this" {compiler->dumpLexToken("this"); return PT_This;};
"new" {compiler->dumpLexToken("new"); return PT_New;};
"return" {compiler->dumpLexToken("return"); return PT_Return;}
"!" {compiler->dumpLexToken("!"); return PT_Negation;};
"&&" {compiler->dumpLexToken("&&"); return PT_And;};
"<" {compiler->dumpLexToken("<"); return PT_Less;};
">" {compiler->dumpLexToken(">"); return PT_More;};
"+" {compiler->dumpLexToken("+"); return PT_Plus;};
"-" {compiler->dumpLexToken("-"); return PT_Minus;};
"*" {compiler->dumpLexToken("*"); return PT_Multiplication;};
"%" {compiler->dumpLexToken("%"); return PT_IntegerDivision;};
"/" {compiler->dumpLexToken("/"); return PT_Division;}
"||" {compiler->dumpLexToken("||"); return PT_Or;};
"=" {compiler->dumpLexToken("="); return PT_Assign;};
";" {compiler->dumpLexToken(";"); return PT_Semicolon;};
"." {compiler->dumpLexToken("."); return PT_Dot;};
"," {compiler->dumpLexToken(","); return PT_Coma;};
[a-zA-Z]+[a-zA-Z0-9_]* { 
		compiler->dumpLexToken("ID");
		yylval->stringValue = (char*) std::malloc(strlen(yytext)+1);
		strcpy_s(yylval->stringValue, strlen(yytext)+1, yytext);
		return PT_ID;
	};

[^,\.;=|/\%\*\-+><!&\(\)\[\]\{\} \t\n]* { 
	compiler->dumpLexToken(yytext);
	CErrorTable::AddError("Bad Token", yylloc->first_line);
	return PT_Error; }

%%

void yyerror(YYLTYPE* yyllocp, yyscan_t unused, CMainCompiler* compiler, const char* msg) {
	//std::cerr << msg << " in line: " << yylineno << std::endl;
	compiler->dumpSyntaxError(msg, yyllocp->first_line);
};