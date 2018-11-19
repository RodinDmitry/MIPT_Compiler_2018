/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "MIPT_Compiler\\Bison\\grammar.y"

#include <stdio.h>
#include <stdlib.h>
#include <string>
extern int yylex();


extern void yyerror(const char* s);

extern FILE* yyin;

extern void yyerror(const char* s);
extern void dumpBisonToken(std::string token);
extern void syntaxError(const std::string& name, int line);

/* Line 371 of yacc.c  */
#line 84 "MIPT_Compiler/Analyzer/grammar.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.tab.h".  */
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
/* Line 387 of yacc.c  */
#line 17 "MIPT_Compiler\\Bison\\grammar.y"

#include "../Analyzer/BisonUtils.h"
#include <iostream>


/* Line 387 of yacc.c  */
#line 122 "MIPT_Compiler/Analyzer/grammar.tab.cpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PT_Error = 258,
     PT_Void = 259,
     PT_String = 260,
     PT_Number = 261,
     PT_Boolean = 262,
     PT_Integer = 263,
     PT_True = 264,
     PT_False = 265,
     PT_Class = 266,
     PT_Static = 267,
     PT_Public = 268,
     PT_Private = 269,
     PT_Extends = 270,
     PT_Main = 271,
     PT_Print = 272,
     PT_If = 273,
     PT_While = 274,
     PT_Else = 275,
     PT_Length = 276,
     PT_This = 277,
     PT_New = 278,
     PT_Semicolon = 279,
     PT_ID = 280,
     PT_Dot = 281,
     PT_Coma = 282,
     PT_Return = 283,
     PT_LeftBrace = 284,
     PT_LeftSquareBracket = 285,
     PT_LeftRoundBracket = 286,
     PT_RightBrace = 287,
     PT_RightSquareBracket = 288,
     PT_RightRoundBracket = 289,
     PT_Negation = 290,
     PT_IntegerDivision = 291,
     PT_Division = 292,
     PT_Multiplication = 293,
     PT_Minus = 294,
     PT_Plus = 295,
     PT_Less = 296,
     PT_More = 297,
     PT_Or = 298,
     PT_And = 299,
     PT_Equal = 300,
     BRACKETS = 301,
     ARRAY = 302,
     CALL = 303,
     LENGTH = 304,
     NOT = 305,
     BINARY = 306
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 24 "MIPT_Compiler\\Bison\\grammar.y"


	int integerValue;
	bool logicalValue;
	char* stringValue;
	
	ITree* node;


/* Line 387 of yacc.c  */
#line 198 "MIPT_Compiler/Analyzer/grammar.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 239 "MIPT_Compiler/Analyzer/grammar.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    10,    16,    17,    20,    25,    27,
      31,    32,    35,    36,    39,    43,    46,    57,    62,    71,
      73,    75,    79,    82,    86,    88,    92,    95,    97,   101,
     103,   105,   107,   108,   111,   114,   118,   126,   132,   138,
     144,   149,   152,   157,   161,   163,   165,   167,   171,   175,
     177,   183,   188,   191,   195,   197,   199,   201,   203,   205,
     207,   209,   211,   213,   215,   220,   221,   223,   225,   227,
     231,   233,   235,   237,   239,   241,   243,   245,   247,   249,
     251,   253,   255,   257,   259,   261,   263,   265,   267,   269,
     271
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    55,    -1,     1,    54,    55,    -1,
      80,    25,    85,    60,    86,    -1,    -1,    56,    55,    -1,
      57,    85,    59,    86,    -1,     1,    -1,    80,    25,    58,
      -1,    -1,    81,    25,    -1,    -1,    62,    59,    -1,    67,
      95,    59,    -1,     1,    59,    -1,    13,    12,     4,    16,
      87,    61,    88,    85,    69,    86,    -1,     5,    89,    90,
      25,    -1,    63,    68,    25,    65,    85,    69,    64,    86,
      -1,    13,    -1,    14,    -1,    28,    72,    95,    -1,    87,
      88,    -1,    87,    66,    88,    -1,    67,    -1,    67,    27,
      66,    -1,    68,    25,    -1,    83,    -1,    83,    30,    33,
      -1,    84,    -1,    25,    -1,     4,    -1,    -1,    70,    69,
      -1,     1,    69,    -1,    85,    69,    86,    -1,    18,    87,
      72,    88,    70,    20,    70,    -1,    18,    87,    72,    88,
      70,    -1,    96,    87,    72,    88,    70,    -1,    94,    87,
      72,    88,    95,    -1,    71,    82,    72,    95,    -1,    67,
      95,    -1,    72,    89,    72,    90,    -1,    72,    74,    75,
      -1,    25,    -1,    79,    -1,    71,    -1,    72,    73,    72,
      -1,    72,    74,    91,    -1,    78,    -1,    92,    83,    89,
      72,    90,    -1,    92,    25,    87,    88,    -1,    93,    72,
      -1,    87,    72,    88,    -1,    40,    -1,    39,    -1,    37,
      -1,    36,    -1,    44,    -1,    43,    -1,    38,    -1,    41,
      -1,    42,    -1,    26,    -1,    25,    87,    76,    88,    -1,
      -1,    77,    -1,     1,    -1,    72,    -1,    72,    27,    77,
      -1,     9,    -1,    10,    -1,     6,    -1,    22,    -1,    11,
      -1,    15,    -1,    45,    -1,     8,    -1,     7,    -1,    29,
      -1,    32,    -1,    31,    -1,    34,    -1,    30,    -1,    33,
      -1,    21,    -1,    23,    -1,    35,    -1,    17,    -1,    24,
      -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   113,   117,   120,   121,   123,   124,   126,
     129,   130,   133,   134,   135,   136,   138,   142,   145,   148,
     149,   152,   155,   156,   159,   160,   163,   166,   167,   168,
     169,   170,   173,   174,   175,   178,   179,   180,   181,   182,
     183,   184,   188,   189,   190,   191,   194,   195,   196,   197,
     198,   199,   200,   201,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   215,   218,   221,   222,   223,   226,   227,
     230,   231,   232,   235,   238,   241,   244,   247,   250,   253,
     256,   259,   262,   265,   268,   271,   274,   277,   280,   283,
     286
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PT_Error", "PT_Void", "PT_String",
  "PT_Number", "PT_Boolean", "PT_Integer", "PT_True", "PT_False",
  "PT_Class", "PT_Static", "PT_Public", "PT_Private", "PT_Extends",
  "PT_Main", "PT_Print", "PT_If", "PT_While", "PT_Else", "PT_Length",
  "PT_This", "PT_New", "PT_Semicolon", "PT_ID", "PT_Dot", "PT_Coma",
  "PT_Return", "PT_LeftBrace", "PT_LeftSquareBracket",
  "PT_LeftRoundBracket", "PT_RightBrace", "PT_RightSquareBracket",
  "PT_RightRoundBracket", "PT_Negation", "PT_IntegerDivision",
  "PT_Division", "PT_Multiplication", "PT_Minus", "PT_Plus", "PT_Less",
  "PT_More", "PT_Or", "PT_And", "PT_Equal", "BRACKETS", "ARRAY", "CALL",
  "LENGTH", "NOT", "BINARY", "$accept", "Goal", "MainClass",
  "ClassDeclaration", "Class", "ClassStart", "Extends", "ClassInternals",
  "MainFunction", "MainArgument", "Function", "Visibility", "Return",
  "ArgumentsList", "Argument", "Variable", "Type", "Statement",
  "StatementItem", "LvalueExpression", "Expression", "BinaryOperator",
  "MethodCall", "FunctionCall", "ExpressionList", "Expressions", "ValueT",
  "This", "ClassWord", "ExtendsWord", "Equals", "Integer", "Boolean",
  "LeftBrace", "RightBrace", "LeftRoundBracket", "RightRoundBracket",
  "LeftSquareBracket", "RightSquareBracket", "Length", "New", "Not",
  "Print", "Semicolon", "While", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    54,    55,    55,    56,    56,    57,
      58,    58,    59,    59,    59,    59,    60,    61,    62,    63,
      63,    64,    65,    65,    66,    66,    67,    68,    68,    68,
      68,    68,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    75,    76,    76,    76,    77,    77,
      78,    78,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     5,     0,     2,     4,     1,     3,
       0,     2,     0,     2,     3,     2,    10,     4,     8,     1,
       1,     3,     2,     3,     1,     3,     2,     1,     3,     1,
       1,     1,     0,     2,     2,     3,     7,     5,     5,     5,
       4,     2,     4,     3,     1,     1,     1,     3,     3,     1,
       5,     4,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    74,     0,     0,     0,     0,     1,     8,     2,
       0,     0,     0,     0,     3,     6,    79,     0,    10,     0,
       0,    31,    78,    77,    19,    20,    30,     0,     0,     0,
       0,     0,    27,    29,    75,     9,     0,     0,     0,    15,
      80,     7,    13,     0,    89,     0,    26,     0,    11,     0,
       4,     0,    14,    28,     0,    81,     0,     0,     0,     0,
      82,     0,    24,    22,     0,     0,    72,    70,    71,    88,
       0,    90,    73,    86,    44,    87,     0,     0,     0,    46,
       0,    49,    45,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,    34,     0,    41,     0,     0,    33,    76,
       0,    63,    83,    57,    56,    60,    55,    54,    61,    62,
      59,    58,     0,     0,     0,     0,    44,    46,     0,     0,
       0,    52,     0,     0,    25,     0,     0,     0,     0,    18,
       0,    47,    85,     0,    43,    48,     0,    35,    53,     0,
       0,     0,     0,    84,     0,     0,     0,    21,    40,     0,
      42,    51,     0,     0,     0,    17,     0,    37,    67,    68,
       0,    66,    50,    39,    38,    16,     0,     0,    64,    36,
      69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     9,    10,    11,    35,    27,    38,    92,
      28,    29,    97,    56,    61,    76,    31,    77,    78,   117,
      80,   112,   113,   134,   160,   161,    81,    82,    12,    36,
     100,    32,    33,    83,    41,    84,    63,   114,   144,   135,
      85,    86,    87,    45,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -138
static const yytype_int16 yypact[] =
{
      26,    20,  -138,    39,    80,    15,    80,  -138,  -138,  -138,
      80,    16,    28,    16,  -138,  -138,  -138,    50,    52,    57,
      50,  -138,  -138,  -138,  -138,  -138,  -138,    60,    50,    48,
      70,    59,    65,  -138,  -138,  -138,    71,    86,    60,  -138,
    -138,  -138,  -138,    75,  -138,    50,  -138,    68,  -138,    98,
    -138,    74,  -138,  -138,    92,  -138,    16,    99,    74,   145,
    -138,    76,    85,  -138,   108,   113,  -138,  -138,  -138,  -138,
      74,  -138,  -138,  -138,    90,  -138,    70,    97,   113,    81,
     301,  -138,  -138,   177,   242,    -1,   242,    74,    74,  -138,
      48,   104,    76,  -138,   242,  -138,   242,    60,  -138,  -138,
     242,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,   242,    40,   242,    60,  -138,  -138,   181,    74,
     104,  -138,   242,   242,  -138,    94,    16,   181,   244,  -138,
     244,  -138,  -138,    74,  -138,  -138,   263,  -138,  -138,    76,
     242,   181,   181,  -138,   103,   177,   224,  -138,  -138,   204,
    -138,  -138,   263,    70,   224,  -138,    60,   109,  -138,   282,
      76,  -138,  -138,  -138,  -138,  -138,   224,   242,  -138,  -138,
    -138
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,   136,    62,  -138,  -138,  -138,     5,  -138,  -138,
    -138,  -138,  -138,  -138,    49,    21,   111,   -55,  -137,   -57,
     -80,  -138,  -138,  -138,  -138,   -24,  -138,  -138,    12,  -138,
    -138,    72,  -138,   -10,   -38,   -40,   -56,   -76,  -117,  -138,
    -138,  -138,  -138,   -54,  -138
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -66
static const yytype_int16 yytable[] =
{
      50,    17,    79,    19,   118,    89,   121,    23,    79,   157,
      93,    57,     5,     5,   127,   125,   128,   164,    64,   150,
     130,    79,    95,    98,   119,    39,    79,     1,   115,   169,
      94,     2,   131,    42,   136,   162,   126,     2,    30,     7,
      13,    30,   141,   142,   140,    16,    59,   122,   123,    30,
      52,    20,    21,    18,    21,    22,    23,    22,    23,   129,
     152,   132,   138,    24,    25,   133,    30,    34,    14,   159,
      37,   146,    15,    26,   147,    26,   148,   137,    62,   139,
      -5,     8,   -12,   151,    46,   153,   154,   159,    79,    79,
     156,     2,    40,   149,    44,    47,    48,    79,    49,   163,
      51,    53,    54,    21,   168,    55,    22,    23,    58,    79,
      60,    62,    90,    91,    65,   -30,   145,    21,   165,    66,
      22,    23,    67,    68,    26,    96,    99,   143,   155,   166,
      69,    70,    71,    60,   102,    72,    73,     6,    74,   124,
      43,   -32,    16,   170,    55,   -32,    65,     0,    75,    21,
       0,    66,    22,    23,    67,    68,     0,   120,     0,     0,
       0,     0,    69,    70,    71,     0,     0,    72,    73,     0,
      74,     0,     0,   -32,    16,     0,    55,     0,    65,     0,
      75,    21,     0,    66,    22,    23,    67,    68,     0,     0,
       0,     0,     0,     0,    69,    70,    71,     0,     0,    72,
      73,     0,    74,     0,     0,   158,    16,   101,    55,   -32,
      66,   102,    75,    67,    68,    60,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    72,    73,    21,   116,
      66,    22,    23,    67,    68,    55,     0,     0,   -65,    75,
       0,    69,    70,    71,     0,     0,    72,    73,    66,    74,
       0,    67,    68,    16,     0,    55,     0,     0,     0,    75,
       0,     0,     0,     0,    72,    73,     0,   116,    44,     0,
     101,     0,     0,    55,   102,     0,     0,    75,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   101,
       0,     0,     0,   102,     0,     0,   143,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   101,   167,
       0,     0,   102,     0,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   101,     0,     0,
       0,   102,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-138)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      38,    11,    59,    13,    84,    61,    86,     8,    65,   146,
      65,    51,     0,     1,    94,    91,    96,   154,    58,   136,
     100,    78,    76,    78,    25,    20,    83,     1,    83,   166,
      70,    11,   112,    28,   114,   152,    92,    11,    17,     0,
      25,    20,   122,   123,   120,    29,    56,    87,    88,    28,
      45,     1,     4,    25,     4,     7,     8,     7,     8,    97,
     140,    21,   118,    13,    14,    25,    45,    15,     6,   149,
      13,   127,    10,    25,   128,    25,   130,   115,    57,   119,
       0,     1,    32,   139,    25,   141,   142,   167,   145,   146,
     145,    11,    32,   133,    24,    30,    25,   154,    12,   153,
      25,    33,     4,     4,   160,    31,     7,     8,    16,   166,
      34,    90,    27,     5,     1,    25,   126,     4,   156,     6,
       7,     8,     9,    10,    25,    28,    45,    33,    25,    20,
      17,    18,    19,    34,    30,    22,    23,     1,    25,    90,
      29,    28,    29,   167,    31,    32,     1,    -1,    35,     4,
      -1,     6,     7,     8,     9,    10,    -1,    85,    -1,    -1,
      -1,    -1,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      25,    -1,    -1,    28,    29,    -1,    31,    -1,     1,    -1,
      35,     4,    -1,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    -1,    -1,     1,    29,    26,    31,    32,
       6,    30,    35,     9,    10,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    22,    23,     4,    25,
       6,     7,     8,     9,    10,    31,    -1,    -1,    34,    35,
      -1,    17,    18,    19,    -1,    -1,    22,    23,     6,    25,
      -1,     9,    10,    29,    -1,    31,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    22,    23,    -1,    25,    24,    -1,
      26,    -1,    -1,    31,    30,    -1,    -1,    35,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    26,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    11,    53,    54,    80,    54,     0,     1,    55,
      56,    57,    80,    25,    55,    55,    29,    85,    25,    85,
       1,     4,     7,     8,    13,    14,    25,    59,    62,    63,
      67,    68,    83,    84,    15,    58,    81,    13,    60,    59,
      32,    86,    59,    68,    24,    95,    25,    30,    25,    12,
      86,    25,    59,    33,     4,    31,    65,    87,    16,    85,
      34,    66,    67,    88,    87,     1,     6,     9,    10,    17,
      18,    19,    22,    23,    25,    35,    67,    69,    70,    71,
      72,    78,    79,    85,    87,    92,    93,    94,    96,    88,
      27,     5,    61,    69,    87,    95,    28,    64,    69,    45,
      82,    26,    30,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    73,    74,    89,    69,    25,    71,    72,    25,
      83,    72,    87,    87,    66,    89,    88,    72,    72,    86,
      72,    72,    21,    25,    75,    91,    72,    86,    88,    87,
      89,    72,    72,    33,    90,    85,    88,    95,    95,    87,
      90,    88,    72,    88,    88,    25,    69,    70,     1,    72,
      76,    77,    90,    95,    70,    86,    20,    27,    88,    70,
      77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      YY_LAC_DISCARD ("YYBACKUP");                              \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (YYID (0))

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (YYID (0))
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 25: /* PT_ID */
/* Line 1398 of yacc.c  */
#line 90 "MIPT_Compiler\\Bison\\grammar.y"
        { free(((*yyvaluep).stringValue)); };
/* Line 1398 of yacc.c  */
#line 1655 "MIPT_Compiler/Analyzer/grammar.tab.cpp"
        break;
      case 58: /* Extends */
/* Line 1398 of yacc.c  */
#line 90 "MIPT_Compiler\\Bison\\grammar.y"
        { free(((*yyvaluep).stringValue)); };
/* Line 1398 of yacc.c  */
#line 1662 "MIPT_Compiler/Analyzer/grammar.tab.cpp"
        break;

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
/* Line 1792 of yacc.c  */
#line 112 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CProgram(To<CMain>((yyvsp[(1) - (2)].node)), To<CClassList>((yyvsp[(2) - (2)].node))); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 113 "MIPT_Compiler\\Bison\\grammar.y"
    { syntaxError("Bad class definition", (yylsp[(1) - (3)]).first_line);
										(yyval.node) = new CProgram(To<CMain>((yyvsp[(2) - (3)].node)), To<CClassList>((yyvsp[(3) - (3)].node)));  yyerrok;}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 117 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CMain(new CId((yyvsp[(2) - (5)].stringValue)), To<CMainFunction>((yyvsp[(4) - (5)].node))); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 120 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CClassList(); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 121 "MIPT_Compiler\\Bison\\grammar.y"
    { To<CClassList>((yyvsp[(2) - (2)].node))->Add(To<CClass>((yyvsp[(1) - (2)].node))); (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 123 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CClass(To<CClassDeclaration>((yyvsp[(1) - (4)].node)), To<CClassInternalsList>((yyvsp[(3) - (4)].node)));}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 124 "MIPT_Compiler\\Bison\\grammar.y"
    {syntaxError("Bad class definition", (yylsp[(1) - (1)]).first_line); yyerrok; (yyval.node) = nullptr; }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 126 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CClassDeclaration(new CId((yyvsp[(2) - (3)].stringValue)), new CId((yyvsp[(3) - (3)].stringValue))); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 129 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.stringValue) = nullptr; }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 130 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.stringValue) = (yyvsp[(2) - (2)].stringValue);}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 133 "MIPT_Compiler\\Bison\\grammar.y"
    {  (yyval.node) = new CClassInternalsList(); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 134 "MIPT_Compiler\\Bison\\grammar.y"
    { To<CClassInternalsList>((yyvsp[(2) - (2)].node))->Add(new CClassInternals(To<CFunction>((yyvsp[(1) - (2)].node)))); (yyval.node) = (yyvsp[(2) - (2)].node);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 135 "MIPT_Compiler\\Bison\\grammar.y"
    { To<CClassInternalsList>((yyvsp[(3) - (3)].node))->Add(new CClassInternals(To<CVariable>((yyvsp[(1) - (3)].node)))); (yyval.node) = (yyvsp[(3) - (3)].node);}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 136 "MIPT_Compiler\\Bison\\grammar.y"
    {syntaxError("Bad method or member", (yylsp[(1) - (2)]).first_line); yyerrok; (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 138 "MIPT_Compiler\\Bison\\grammar.y"
    { 
		 (yyval.node) = new CMainFunction(To<CMainArgument>((yyvsp[(6) - (10)].node)), To<CStatementList>((yyvsp[(9) - (10)].node))); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 142 "MIPT_Compiler\\Bison\\grammar.y"
    {  (yyval.node) = new CMainArgument(new CId((yyvsp[(4) - (4)].stringValue))); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 145 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CFunction(To<CModifier>((yyvsp[(1) - (8)].node)), new CId((yyvsp[(3) - (8)].stringValue)), To<CArgumentList>((yyvsp[(4) - (8)].node)), To<CStatementList>((yyvsp[(6) - (8)].node)), To<CType>((yyvsp[(2) - (8)].node)), To<CReturnExpression>((yyvsp[(7) - (8)].node))); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 148 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CModifier(CModifier::MT_Public); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 149 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CModifier(CModifier::MT_Private); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 152 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CReturnExpression(To<IExpression>((yyvsp[(2) - (3)].node))); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 155 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CArgumentList(); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 156 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 159 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CArgumentList(); To<CArgumentList>((yyval.node))->Add(To<CVariable>((yyvsp[(1) - (1)].node)));}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 160 "MIPT_Compiler\\Bison\\grammar.y"
    {  To<CArgumentList>((yyvsp[(3) - (3)].node))->Add(To<CVariable>((yyvsp[(1) - (3)].node))); (yyval.node) = (yyvsp[(3) - (3)].node); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 163 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CVariable(To<CType>((yyvsp[(1) - (2)].node)), new CId((yyvsp[(2) - (2)].stringValue))); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 166 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CType(CType::VT_Integer); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 167 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CType(CType::VT_IntegerArray); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 168 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CType(CType::VT_Boolean); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 169 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CType((yyvsp[(1) - (1)].stringValue)); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 170 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CType(); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 173 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CStatementList();}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 174 "MIPT_Compiler\\Bison\\grammar.y"
    { To<CStatementList>((yyvsp[(2) - (2)].node))->Add(To<IStatement>((yyvsp[(1) - (2)].node))); (yyval.node)=(yyvsp[(2) - (2)].node);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 175 "MIPT_Compiler\\Bison\\grammar.y"
    {syntaxError("Bad Statement", (yylsp[(1) - (2)]).first_line); (yyval.node) = (yyvsp[(2) - (2)].node); yyerrok; }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 178 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CVisibilityStatement(To<IStatement>((yyvsp[(2) - (3)].node))); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 179 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CIfStatement(To<IExpression>((yyvsp[(3) - (7)].node)), To<IStatement>((yyvsp[(5) - (7)].node)), To<IStatement>((yyvsp[(7) - (7)].node))); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 180 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) =  new CIfStatement(To<IExpression>((yyvsp[(3) - (5)].node)), To<IStatement>((yyvsp[(5) - (5)].node)), nullptr); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 181 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CWhileStatement(To<IExpression>((yyvsp[(3) - (5)].node)), To<IStatement>((yyvsp[(5) - (5)].node))); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 182 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CPrintStatement(To<IExpression>((yyvsp[(3) - (5)].node))); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 183 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CEqualStatement(To<CLValueExpression>((yyvsp[(1) - (4)].node)), To<IExpression>((yyvsp[(3) - (4)].node))); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 184 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CVariableStatement(To<CVariable>((yyvsp[(1) - (2)].node))); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 188 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CArrayExpression(To<IExpression>((yyvsp[(1) - (4)].node)), To<IExpression>((yyvsp[(3) - (4)].node)));}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 189 "MIPT_Compiler\\Bison\\grammar.y"
    { To<CCallExpression>((yyvsp[(3) - (3)].node))->caller=To<CId>((yyvsp[(1) - (3)].node)); (yyval.node)=(yyvsp[(1) - (3)].node);}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 190 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CIdExpression(new CId ((yyvsp[(1) - (1)].stringValue)));}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 191 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CThisExpression();}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 194 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 195 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CBinaryExpression(To<IExpression>((yyvsp[(1) - (3)].node)), To<IExpression>((yyvsp[(3) - (3)].node)), static_cast<CBinaryExpression::TOpeartor>((yyvsp[(2) - (3)].integerValue)));}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 196 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CCallLengthExpression(To<IExpression>((yyvsp[(1) - (3)].node)));}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 197 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CValueExpression(To<IValue>((yyvsp[(1) - (1)].node))); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 198 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CNewArrayExpression(To<IExpression>((yyvsp[(4) - (5)].node)));}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 199 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CNewExpression(new CId((yyvsp[(2) - (4)].stringValue)));}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 200 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CNotExpression(To<IExpression>((yyvsp[(2) - (2)].node))); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 201 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = new CBracketsExpression(To<IExpression>((yyvsp[(2) - (3)].node)));}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 204 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.integerValue)=CBinaryExpression::O_Plus; }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 205 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.integerValue)=CBinaryExpression::O_Minus; }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 206 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.integerValue)=CBinaryExpression::O_Division; }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 207 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.integerValue)=CBinaryExpression::O_IntegerDivision; }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 208 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.integerValue)=CBinaryExpression::O_And; }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 209 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.integerValue)=CBinaryExpression::O_Or; }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 210 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.integerValue)=CBinaryExpression::O_Multiplication; }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 211 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.integerValue)=CBinaryExpression::O_Less; }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 212 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.integerValue)=CBinaryExpression::O_More; }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 215 "MIPT_Compiler\\Bison\\grammar.y"
    {}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 218 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CCallExpression(To<CId>(nullptr), new CId((yyvsp[(1) - (4)].stringValue)), To<CArgumentList>((yyvsp[(3) - (4)].node))); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 221 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CExpressionList(); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 222 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 223 "MIPT_Compiler\\Bison\\grammar.y"
    {syntaxError("Bad expression", (yylsp[(1) - (1)]).first_line); yyerrok; (yyval.node) = nullptr; }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 226 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CExpressionList(); To<CExpressionList>((yyval.node))->Add(To<IExpression>((yyvsp[(1) - (1)].node))); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 227 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=(yyvsp[(3) - (3)].node); To<CExpressionList>((yyval.node))->Add(To<IExpression>((yyvsp[(1) - (3)].node))); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 230 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CValue(true, CValue::T_Boolean); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 231 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CValue(true, CValue::T_Boolean); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 232 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new CValue((yyvsp[(1) - (1)].integerValue), CValue::T_Integer); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 235 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("this"); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 238 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("class"); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 241 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("extend"); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 244 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("equal"); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 247 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("int"); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 250 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("bool"); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 253 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("{"); }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 256 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("}"); }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 259 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("("); }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 262 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken(")"); }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 265 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("["); }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 268 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("]"); }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 271 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("length"); }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 274 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("new"); }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 277 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("!"); }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 280 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("print"); }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 283 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("semicolon"); }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 286 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("while"); }
    break;


/* Line 1792 of yacc.c  */
#line 2531 "MIPT_Compiler/Analyzer/grammar.tab.cpp"
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 289 "MIPT_Compiler\\Bison\\grammar.y"
