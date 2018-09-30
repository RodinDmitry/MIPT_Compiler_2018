%option noyywrap

%{
#include <iostream>

#define YY_DECL int yylex()

%}

%%

[\n] { std::cout << std::endl;};
[ \t]	; // ignore all whitespace
[0-9]+		{ std::cout << "NUMBER ";};
"static" { std::cout << "STATIC ";};
"public" { std::cout << "PUBLIC ";};
"private" { std::cout << "PRIVATE ";};

"void" { std::cout << "VOID ";};
"main" { std::cout << "MAIN ";};
"class" { std::cout << "CLASS ";};
"(" { std::cout << "LPAREN ";};
")" { std::cout << "RPAREN ";};
"String" { std::cout << "STRING ";};
"[" { std::cout << "LBRACKET ";};
"]" { std::cout << "RBRACKET ";};
"{" { std::cout << "LBRACE ";};
"}" { std::cout << "RBRACE ";};
"int" { std::cout << "INT ";};
"boolean" { std::cout << "BOOLEAN ";};
"System.out.println" { std::cout << "SOUT ";};
"if" { std::cout << "IF ";};
"while" { std::cout << "WHILE ";};
"length" { std::cout << "LENGTH ";};
"true" { std::cout << "TRUE ";};
"false" { std::cout << "FALSE ";};
"this" { std::cout << "THIS ";};
"new" { std::cout << "NEW ";};
"!" { std::cout << "! ";};
"&&" { std::cout << "&& ";};
"<" { std::cout << "< ";};
"+" { std::cout << "+ ";};
"-" { std::cout << "- ";};
"*" { std::cout << "* ";};
"%" { std::cout << "% ";};
"||" { std::cout << "|| ";};
"=" { std::cout << "= ";};
";" { std::cout << "SEMI ";};
[a-zA-z]+[a-zA-Z0-9_]* {{ std::cout << "ID(" << yytext << ") ";};}


%%