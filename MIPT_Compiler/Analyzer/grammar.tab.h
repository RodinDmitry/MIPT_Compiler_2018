/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_MIPT_COMPILER_ANALYZER_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_MIPT_COMPILER_ANALYZER_GRAMMAR_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2058 of yacc.c  */
#line 13 "MIPT_Compiler\\Bison\\grammar.y"

#include "../Analyzer/BisonUtils.h"
extern Goal* result;


/* Line 2058 of yacc.c  */
#line 52 "MIPT_Compiler/Analyzer/grammar.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PT_Void = 258,
     PT_String = 259,
     PT_Number = 260,
     PT_Boolean = 261,
     PT_Integer = 262,
     PT_True = 263,
     PT_False = 264,
     PT_Class = 265,
     PT_Static = 266,
     PT_Public = 267,
     PT_Private = 268,
     PT_Extends = 269,
     PT_Main = 270,
     PT_Print = 271,
     PT_If = 272,
     PT_While = 273,
     PT_Else = 274,
     PT_Length = 275,
     PT_This = 276,
     PT_New = 277,
     PT_Semicolon = 278,
     PT_ID = 279,
     PT_Dot = 280,
     PT_Coma = 281,
     PT_Return = 282,
     PT_LeftBrace = 283,
     PT_LeftSquareBracket = 284,
     PT_LeftRoundBracket = 285,
     PT_RightBrace = 286,
     PT_RightSquareBracket = 287,
     PT_RightRoundBracket = 288,
     PT_Negation = 289,
     PT_IntegerDivision = 290,
     PT_Division = 291,
     PT_Multiplication = 292,
     PT_Minus = 293,
     PT_Plus = 294,
     PT_Less = 295,
     PT_More = 296,
     PT_Or = 297,
     PT_And = 298,
     PT_Equal = 299,
     BRACKETS = 300,
     ARRAY = 301,
     CALL = 302,
     LENGTH = 303,
     NOT = 304,
     BINARY = 305
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 18 "MIPT_Compiler\\Bison\\grammar.y"


	int integerValue;
	bool logicalValue;
	char* stringValue;
	
	ITree* node;


/* Line 2058 of yacc.c  */
#line 127 "MIPT_Compiler/Analyzer/grammar.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_MIPT_COMPILER_ANALYZER_GRAMMAR_TAB_H_INCLUDED  */
