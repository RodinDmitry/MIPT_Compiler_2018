#pragma once
#include <Visitor.h>
#include <string>

extern int yylex();
extern int yyparse(ITree*);
extern FILE* yyin;