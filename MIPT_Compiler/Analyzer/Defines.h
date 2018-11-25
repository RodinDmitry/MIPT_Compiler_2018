#pragma once
#include <PrettyPrinter.h>
#include <StackBuilder.h>
#include <string>

extern int yylex();
extern int yyparse(ITree*);
extern FILE* yyin;