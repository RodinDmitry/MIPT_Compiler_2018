#pragma once
#include <iostream>
#include <string>

extern int yylex();
extern int yyparse();
extern FILE* yyin;