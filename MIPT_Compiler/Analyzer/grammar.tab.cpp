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
extern "C++" int yyparse();
extern FILE* yyin;

extern void yyerror(const char* s);
extern void dumpBisonToken(std::string token);

/* Line 371 of yacc.c  */
#line 80 "MIPT_Compiler/Analyzer/grammar.tab.cpp"

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
#line 13 "MIPT_Compiler\\Bison\\grammar.y"

#include "../Analyzer/BisonUtils.h"
extern Goal* result;


/* Line 387 of yacc.c  */
#line 118 "MIPT_Compiler/Analyzer/grammar.tab.cpp"

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
/* Line 387 of yacc.c  */
#line 18 "MIPT_Compiler\\Bison\\grammar.y"


	int integerValue;
	bool logicalValue;
	char* stringValue;
	
	ITree* node;


/* Line 387 of yacc.c  */
#line 193 "MIPT_Compiler/Analyzer/grammar.tab.cpp"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 221 "MIPT_Compiler/Analyzer/grammar.tab.cpp"

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

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNRULES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    12,    13,    16,    21,    25,    26,
      29,    30,    33,    37,    48,    53,    62,    64,    66,    70,
      73,    77,    79,    83,    86,    88,    92,    94,    96,    98,
      99,   102,   106,   114,   120,   126,   132,   137,   140,   145,
     149,   151,   153,   155,   159,   163,   165,   171,   176,   179,
     183,   185,   187,   189,   191,   193,   195,   197,   199,   201,
     203,   208,   209,   211,   213,   217,   219,   221,   223,   225,
     227,   229,   231,   233,   235,   237,   239,   241,   243,   245,
     247,   249,   251,   253,   255,   257
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    54,    -1,    79,    24,    84,    59,
      85,    -1,    -1,    55,    54,    -1,    56,    84,    58,    85,
      -1,    79,    24,    57,    -1,    -1,    80,    24,    -1,    -1,
      61,    58,    -1,    66,    94,    58,    -1,    12,    11,     3,
      15,    86,    60,    87,    84,    68,    85,    -1,     4,    88,
      89,    24,    -1,    62,    67,    24,    64,    84,    68,    63,
      85,    -1,    12,    -1,    13,    -1,    27,    71,    94,    -1,
      86,    87,    -1,    86,    65,    87,    -1,    66,    -1,    66,
      26,    65,    -1,    67,    24,    -1,    82,    -1,    82,    29,
      32,    -1,    83,    -1,    24,    -1,     3,    -1,    -1,    69,
      68,    -1,    84,    68,    85,    -1,    17,    86,    71,    87,
      69,    19,    69,    -1,    17,    86,    71,    87,    69,    -1,
      95,    86,    71,    87,    69,    -1,    93,    86,    71,    87,
      94,    -1,    70,    81,    71,    94,    -1,    66,    94,    -1,
      71,    88,    71,    89,    -1,    71,    73,    74,    -1,    24,
      -1,    78,    -1,    70,    -1,    71,    72,    71,    -1,    71,
      73,    90,    -1,    77,    -1,    91,    82,    88,    71,    89,
      -1,    91,    24,    86,    87,    -1,    92,    71,    -1,    86,
      71,    87,    -1,    39,    -1,    38,    -1,    36,    -1,    35,
      -1,    43,    -1,    42,    -1,    37,    -1,    40,    -1,    41,
      -1,    25,    -1,    24,    86,    75,    87,    -1,    -1,    76,
      -1,    71,    -1,    71,    26,    76,    -1,     8,    -1,     9,
      -1,     5,    -1,    21,    -1,    10,    -1,    14,    -1,    44,
      -1,     7,    -1,     6,    -1,    28,    -1,    31,    -1,    30,
      -1,    33,    -1,    29,    -1,    32,    -1,    20,    -1,    22,
      -1,    34,    -1,    16,    -1,    23,    -1,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   106,   109,   110,   113,   117,   120,   121,
     124,   125,   126,   129,   133,   136,   140,   141,   144,   147,
     148,   151,   152,   155,   158,   159,   160,   161,   162,   165,
     166,   169,   170,   171,   172,   173,   174,   175,   179,   180,
     181,   182,   185,   186,   187,   188,   189,   190,   191,   192,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   206,
     209,   212,   213,   216,   217,   220,   221,   222,   225,   228,
     231,   234,   237,   240,   243,   246,   249,   252,   255,   258,
     261,   264,   267,   270,   273,   276
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PT_Void", "PT_String", "PT_Number",
  "PT_Boolean", "PT_Integer", "PT_True", "PT_False", "PT_Class",
  "PT_Static", "PT_Public", "PT_Private", "PT_Extends", "PT_Main",
  "PT_Print", "PT_If", "PT_While", "PT_Else", "PT_Length", "PT_This",
  "PT_New", "PT_Semicolon", "PT_ID", "PT_Dot", "PT_Coma", "PT_Return",
  "PT_LeftBrace", "PT_LeftSquareBracket", "PT_LeftRoundBracket",
  "PT_RightBrace", "PT_RightSquareBracket", "PT_RightRoundBracket",
  "PT_Negation", "PT_IntegerDivision", "PT_Division", "PT_Multiplication",
  "PT_Minus", "PT_Plus", "PT_Less", "PT_More", "PT_Or", "PT_And",
  "PT_Equal", "BRACKETS", "ARRAY", "CALL", "LENGTH", "NOT", "BINARY",
  "$accept", "Goal", "MainClass", "ClassDeclaration", "Class",
  "ClassStart", "Extends", "ClassInternals", "MainFunction",
  "MainArgument", "Function", "Visibility", "Return", "ArgumentsList",
  "Argument", "Variable", "Type", "Statement", "StatementItem",
  "LvalueExpression", "Expression", "BinaryOperator", "MethodCall",
  "FunctionCall", "ExpressionList", "Expressions", "ValueT", "This",
  "ClassWord", "ExtendsWord", "Equals", "Integer", "Boolean", "LeftBrace",
  "RightBrace", "LeftRoundBracket", "RightRoundBracket",
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
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    54,    54,    55,    56,    57,    57,
      58,    58,    58,    59,    60,    61,    62,    62,    63,    64,
      64,    65,    65,    66,    67,    67,    67,    67,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      74,    75,    75,    76,    76,    77,    77,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     5,     0,     2,     4,     3,     0,     2,
       0,     2,     3,    10,     4,     8,     1,     1,     3,     2,
       3,     1,     3,     2,     1,     3,     1,     1,     1,     0,
       2,     3,     7,     5,     5,     5,     4,     2,     4,     3,
       1,     1,     1,     3,     3,     1,     5,     4,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    69,     0,     4,     0,     1,     2,     4,     0,     0,
       0,     5,    74,    10,     8,     0,    28,    73,    72,    16,
      17,    27,     0,    10,     0,     0,     0,    24,    26,    70,
       7,     0,     0,     0,    75,     6,    11,     0,    84,    10,
      23,     0,     9,     0,     3,     0,    12,    25,     0,    76,
       0,     0,     0,    29,    77,     0,    21,    19,     0,    67,
      65,    66,    83,     0,    85,    68,    81,    40,    82,     0,
       0,    29,    42,     0,    45,    41,    29,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,    37,     0,     0,
      30,    71,     0,    59,    78,    53,    52,    56,    51,    50,
      57,    58,    55,    54,     0,     0,     0,     0,    40,    42,
       0,     0,     0,    48,     0,     0,    22,     0,     0,     0,
       0,    15,     0,    43,    80,     0,    39,    44,     0,    31,
      49,     0,     0,     0,     0,    79,     0,    29,     0,    18,
      36,    61,    38,    47,     0,     0,     0,    14,     0,    33,
      63,     0,    62,    46,    35,    34,    13,     0,     0,    60,
      32,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     7,     8,    30,    22,    33,    85,
      23,    24,    89,    50,    55,    69,    26,    70,    71,   109,
      73,   104,   105,   126,   151,   152,    74,    75,     9,    31,
      92,    27,    28,    76,    35,    77,    57,   106,   136,   127,
      78,    79,    80,    39,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -107
static const yytype_int16 yypact[] =
{
       7,  -107,    23,     7,     2,  -107,  -107,     7,    25,     8,
      25,  -107,  -107,   137,    37,    42,  -107,  -107,  -107,  -107,
    -107,  -107,    27,   137,    33,    38,    40,    41,  -107,  -107,
    -107,    47,    51,    27,  -107,  -107,  -107,    48,  -107,   137,
    -107,    44,  -107,    70,  -107,    49,  -107,  -107,    62,  -107,
      25,     4,    49,   111,  -107,    58,    54,  -107,    78,  -107,
    -107,  -107,  -107,    49,  -107,  -107,  -107,    68,  -107,    38,
      66,   111,    50,   204,  -107,  -107,   111,   100,    43,   100,
      49,    49,  -107,    33,    67,    58,   100,  -107,   100,    27,
    -107,  -107,   100,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,   100,    28,   100,    27,  -107,  -107,
     147,    49,    67,  -107,   100,   100,  -107,    65,    25,   147,
     128,  -107,   128,  -107,  -107,    49,  -107,  -107,   166,  -107,
    -107,    58,   100,   147,   147,  -107,    74,   111,   111,  -107,
    -107,   100,  -107,  -107,   166,    38,   111,  -107,    27,    80,
     185,    58,  -107,  -107,  -107,  -107,  -107,   111,   100,  -107,
    -107,  -107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -107,  -107,  -107,    93,  -107,  -107,  -107,    -9,  -107,  -107,
    -107,  -107,  -107,  -107,    19,    -5,    79,   -47,   -91,   -51,
     -73,  -107,  -107,  -107,  -107,   -54,  -107,  -107,   107,  -107,
    -107,    32,  -107,    -7,   -33,   -36,   -50,   -63,  -106,  -107,
    -107,  -107,  -107,   -57,  -107
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -28
static const yytype_int16 yytable[] =
{
      44,    13,    72,    15,   110,    82,   113,    16,    25,    51,
      17,    18,    87,   119,    36,   120,    58,     1,    25,   122,
      72,   117,   142,     5,    90,    72,    10,    86,    21,   107,
      46,   123,    14,   128,    25,   118,    16,    54,   153,    17,
      18,   133,   134,    53,   114,   115,    56,   149,   124,   132,
      18,    29,   125,    12,    32,   155,   121,    21,    34,   144,
     130,    38,    43,   139,    40,   140,   160,   111,   150,   138,
      41,    42,    45,    48,   129,   131,    47,    52,    56,    49,
      83,   143,    84,   145,   146,   150,    72,    72,   154,   141,
     148,    54,   -27,    88,    91,    72,    94,   135,   147,   157,
      11,   159,   116,    37,   161,    59,    72,     4,    60,    61,
     112,   137,     0,     0,    16,   156,    59,    17,    18,    60,
      61,    65,    66,     0,   108,     0,     0,    62,    63,    64,
      49,     0,    65,    66,    68,    67,     0,     0,     0,    12,
      16,    49,     0,    17,    18,    68,     0,     0,     0,    19,
      20,    38,     0,    93,     0,     0,     0,    94,     0,     0,
       0,    21,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    93,     0,     0,     0,    94,     0,     0,     0,
      54,     0,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    93,     0,     0,     0,    94,     0,     0,   135,     0,
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      93,   158,     0,     0,    94,     0,     0,     0,     0,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    93,
       0,     0,     0,    94,     0,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      33,     8,    53,    10,    77,    55,    79,     3,    13,    45,
       6,     7,    69,    86,    23,    88,    52,    10,    23,    92,
      71,    84,   128,     0,    71,    76,    24,    63,    24,    76,
      39,   104,    24,   106,    39,    85,     3,    33,   144,     6,
       7,   114,   115,    50,    80,    81,    51,   138,    20,   112,
       7,    14,    24,    28,    12,   146,    89,    24,    31,   132,
     110,    23,    11,   120,    24,   122,   157,    24,   141,   119,
      29,    24,    24,     3,   107,   111,    32,    15,    83,    30,
      26,   131,     4,   133,   134,   158,   137,   138,   145,   125,
     137,    33,    24,    27,    44,   146,    29,    32,    24,    19,
       7,   151,    83,    24,   158,     5,   157,     0,     8,     9,
      78,   118,    -1,    -1,     3,   148,     5,     6,     7,     8,
       9,    21,    22,    -1,    24,    -1,    -1,    16,    17,    18,
      30,    -1,    21,    22,    34,    24,    -1,    -1,    -1,    28,
       3,    30,    -1,     6,     7,    34,    -1,    -1,    -1,    12,
      13,    23,    -1,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    24,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    25,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    52,    53,    79,     0,    54,    55,    56,    79,
      24,    54,    28,    84,    24,    84,     3,     6,     7,    12,
      13,    24,    58,    61,    62,    66,    67,    82,    83,    14,
      57,    80,    12,    59,    31,    85,    58,    67,    23,    94,
      24,    29,    24,    11,    85,    24,    58,    32,     3,    30,
      64,    86,    15,    84,    33,    65,    66,    87,    86,     5,
       8,     9,    16,    17,    18,    21,    22,    24,    34,    66,
      68,    69,    70,    71,    77,    78,    84,    86,    91,    92,
      93,    95,    87,    26,     4,    60,    86,    94,    27,    63,
      68,    44,    81,    25,    29,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    72,    73,    88,    68,    24,    70,
      71,    24,    82,    71,    86,    86,    65,    88,    87,    71,
      71,    85,    71,    71,    20,    24,    74,    90,    71,    85,
      87,    86,    88,    71,    71,    32,    89,    84,    87,    94,
      94,    86,    89,    87,    71,    87,    87,    24,    68,    69,
      71,    75,    76,    89,    94,    69,    85,    19,    26,    87,
      69,    76
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


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
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
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
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

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 103 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:Goal");result = new Goal(ToMCl((yyvsp[(1) - (2)].node)), ToClDecl((yyvsp[(2) - (2)].node))); (yyval.node) = result;}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 106 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:MainClass");(yyval.node) = new MainClass(ToFunc((yyvsp[(4) - (5)].node)), new Identifier((yyvsp[(2) - (5)].stringValue))); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 109 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:ClasDecl");(yyval.node) = new ClassDeclaration(cdt::EMPTY_TYPE); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 110 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:ClasDecl");(yyval.node) = new ClassDeclaration(ToClDecl((yyvsp[(1) - (2)].node)),
		ToClDecl((yyvsp[(2) - (2)].node)), cdt::LIST_TYPE); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 113 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:Class");(yyval.node) = new ClassDeclaration(ToClSt((yyvsp[(1) - (4)].node)),
		ToClInt((yyvsp[(3) - (4)].node)), cdt::CLASS_TYPE); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 117 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:ClasStart");(yyval.node) = new ClassStart(new Identifier((yyvsp[(2) - (3)].stringValue)), (yyvsp[(3) - (3)].stringValue));}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 120 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:extend");(yyval.stringValue) = 0; }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 121 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:extend");(yyval.stringValue) = (yyvsp[(2) - (2)].stringValue);}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 124 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:ClasInt");(yyval.node) = new ClassInternals(cit::EMPTY_TYPE); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 125 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:ClasInt");(yyval.node) = new ClassInternals(ToFunc((yyvsp[(1) - (2)].node)), ToClInt((yyvsp[(2) - (2)].node)), cit::METHOD_TYPE); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 126 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:ClasInt");(yyval.node) = new ClassInternals(ToVar((yyvsp[(1) - (3)].node)), ToClInt((yyvsp[(3) - (3)].node)), cit::MEMBER_TYPE);}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 129 "MIPT_Compiler\\Bison\\grammar.y"
    { 
		 dumpBisonToken("Red:MainFunc");(yyval.node) = new MainMethodDeclaration( ToArg((yyvsp[(6) - (10)].node)), ToState((yyvsp[(9) - (10)].node)) ); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 133 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:MainArg");(yyval.node) = new Argument(new Identifier((yyvsp[(4) - (4)].stringValue)), aas::LAST_STATE); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 136 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:function"); (yyval.node) = new MethodDeclaration(ToMod((yyvsp[(1) - (8)].node)),
				new Identifier((yyvsp[(3) - (8)].stringValue)), ToArg((yyvsp[(4) - (8)].node)), ToState((yyvsp[(6) - (8)].node)), ToExpr((yyvsp[(7) - (8)].node)), ToType((yyvsp[(2) - (8)].node))); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 140 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:public");(yyval.node) = new Modifier(mv::PT_Public); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 141 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:private");(yyval.node) = new Modifier(mv::PT_Private);}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 144 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:return"); (yyval.node)=new Expression(ToExpr((yyvsp[(2) - (3)].node)), exst::RETURN_STATE);}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 147 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:ArgumentList"); (yyval.node) = new Argument(aas::EMPTY_STATE); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 148 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:ArgumentList"); (yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 151 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Argument"); (yyval.node) = new Argument(ToVar((yyvsp[(1) - (1)].node)), aas::LAST_STATE); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 152 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Argument"); (yyval.node) = new Argument(ToArg((yyvsp[(3) - (3)].node)), ToVar((yyvsp[(1) - (3)].node)), aas::LIST_STATE); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 155 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Variable"); (yyval.node) = new VarDeclaration(ToType((yyvsp[(1) - (2)].node)), new Identifier((yyvsp[(2) - (2)].stringValue))); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 158 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:Type");(yyval.node) = new TypeIdentifier(titt::INT_TYPE); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 159 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:Type");(yyval.node) = new TypeIdentifier(titt::INTA_TYPE); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 160 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:Type");(yyval.node) = new TypeIdentifier(titt::BOOL_TYPE); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 161 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:Type");(yyval.node) = new TypeIdentifier(new Identifier((yyvsp[(1) - (1)].stringValue)), titt::USER_TYPE); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 162 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:Type");(yyval.node) = new TypeIdentifier(titt::VOID_TYPE); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 165 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Statement"); (yyval.node) = new Statement(nullptr, sst::EMPTY_TYPE); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 166 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Statement"); (yyval.node) = new Statement(ToState((yyvsp[(1) - (2)].node)), ToState((yyvsp[(2) - (2)].node)), sst::LIST_TYPE); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 169 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Statement"); (yyval.node) = new Statement(ToState((yyvsp[(2) - (3)].node)), ToState(nullptr), sst::SHADE_TYPE); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 170 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:StatementList"); (yyval.node) = new Statement(ToExpr((yyvsp[(3) - (7)].node)), ToState((yyvsp[(5) - (7)].node)), ToState((yyvsp[(7) - (7)].node)), sst::IF_TYPE); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 171 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:StatementList"); (yyval.node) = new Statement(ToExpr((yyvsp[(3) - (5)].node)), ToState((yyvsp[(5) - (5)].node)), ToState(nullptr), sst::IF_TYPE); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 172 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:StatementList"); (yyval.node) = new Statement(ToExpr((yyvsp[(3) - (5)].node)), ToState((yyvsp[(5) - (5)].node)), sst::WHILE_TYPE); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 173 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:StatementList"); (yyval.node) = new Statement(ToExpr((yyvsp[(3) - (5)].node)), nullptr, sst::PRINT_TYPE); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 174 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:StatementList"); (yyval.node) = new Statement(ToExpr((yyvsp[(3) - (4)].node)), nullptr, ToExpr((yyvsp[(1) - (4)].node)), nullptr, sst::ASSIGN_TYPE); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 175 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:StatementList"); (yyval.node) = new Statement(ToVar((yyvsp[(1) - (2)].node)), nullptr, sst::VAR_TYPE); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 179 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Expression"); (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (4)].node)), ToExpr((yyvsp[(3) - (4)].node)), exst::SquareBracket_STATE);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 180 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Expression"); (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (3)].node)), ToFcall((yyvsp[(3) - (3)].node)), exst::FunctionCall_STATE);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 181 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Expression"); (yyval.node)=new Expression(new Identifier((yyvsp[(1) - (1)].stringValue)), exst::ID_STATE);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 182 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Expression"); (yyval.node)=new Expression(exst::This_State);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 185 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=nullptr; }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 186 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Expression"); (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (3)].node)), ToExpr((yyvsp[(3) - (3)].node)), ToBinOp((yyvsp[(2) - (3)].node)), exst::BinaryOperator_STATE);}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 187 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Expression"); (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (3)].node)), exst::Length_STATE);}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 188 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Expression"); (yyval.node)=new Expression(ToVal((yyvsp[(1) - (1)].node)), exst::Value_STATE);}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 189 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Expression"); (yyval.node)=new Expression(ToExpr((yyvsp[(4) - (5)].node)), exst::Array_STATE);}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 190 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Expression"); (yyval.node)=new Expression(new Identifier((yyvsp[(2) - (4)].stringValue)), exst::NewObj_STATE);}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 191 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Expression"); (yyval.node)=new Expression(exst::Not_STATE); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 192 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Expression"); (yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 195 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:BinaryOperator"); (yyval.node)=new BinaryOperator(boot::PT_Plus); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 196 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:BinaryOperator"); (yyval.node)=new BinaryOperator(boot::PT_Minus); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 197 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:BinaryOperator"); (yyval.node)=new BinaryOperator(boot::PT_Division); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 198 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:BinaryOperator"); (yyval.node)=new BinaryOperator(boot::PT_IntegerDivision); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 199 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:BinaryOperator"); (yyval.node)=new BinaryOperator(boot::PT_And); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 200 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:BinaryOperator"); (yyval.node)=new BinaryOperator(boot::PT_Or); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 201 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:BinaryOperator"); (yyval.node)=new BinaryOperator(boot::PT_Multiplication); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 202 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:BinaryOperator"); (yyval.node)=new BinaryOperator(boot::PT_Less); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 203 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:BinaryOperator"); (yyval.node)=new BinaryOperator(boot::PT_More); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 206 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("Red:Dot");}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 209 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:functionCall"); (yyval.node)=new FunctionCall(ToExpr((yyvsp[(3) - (4)].node)), new Identifier((yyvsp[(1) - (4)].stringValue))); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 212 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:expressionList"); (yyval.node)=new Expression(exst::Empty_STATE);}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 213 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:expresionList"); (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (1)].node)), exst::List_STATE);}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 216 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:expressions"); (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (1)].node)), exst::List_STATE);}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 217 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:expressions"); (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (3)].node)), ToExpr((yyvsp[(3) - (3)].node)), exst::List_STATE);}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 220 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:value"); (yyval.node)=new Value(true);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 221 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:value"); (yyval.node)=new Value(false);}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 222 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("Red:value"); (yyval.node)=new Value((yyvsp[(1) - (1)].integerValue));}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 225 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("this"); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 228 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("class"); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 231 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("extend"); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 234 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("equal"); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 237 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("int"); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 240 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("bool"); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 243 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("{"); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 246 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("}"); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 249 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("("); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 252 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken(")"); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 255 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("["); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 258 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("]"); }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 261 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("length"); }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 264 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("new"); }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 267 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("!"); }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 270 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("print"); }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 273 "MIPT_Compiler\\Bison\\grammar.y"
    {  dumpBisonToken("semicolon"); }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 276 "MIPT_Compiler\\Bison\\grammar.y"
    { dumpBisonToken("while"); }
    break;


/* Line 1792 of yacc.c  */
#line 2093 "MIPT_Compiler/Analyzer/grammar.tab.cpp"
      default: break;
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
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 279 "MIPT_Compiler\\Bison\\grammar.y"

