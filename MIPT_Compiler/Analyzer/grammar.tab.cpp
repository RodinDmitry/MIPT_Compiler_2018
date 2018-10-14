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

extern int yylex();
extern "C++" int yyparse();
extern FILE* yyin;

void yyerror(const char* s){};

/* Line 371 of yacc.c  */
#line 79 "MIPT_Compiler/Analyzer/grammar.tab.cpp"

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
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 387 of yacc.c  */
#line 12 "MIPT_Compiler\\Bison\\grammar.y"

#include "../Analyzer/BisonUtils.h"


/* Line 387 of yacc.c  */
#line 116 "MIPT_Compiler/Analyzer/grammar.tab.cpp"

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
     PT_LeftRoundBracket = 271,
     PT_LeftSquareBracket = 272,
     PT_LeftBrace = 273,
     PT_RightRoundBracket = 274,
     PT_RightSquareBracket = 275,
     PT_RightBrace = 276,
     PT_Print = 277,
     PT_If = 278,
     PT_While = 279,
     PT_Else = 280,
     PT_Length = 281,
     PT_This = 282,
     PT_New = 283,
     PT_Negation = 284,
     PT_And = 285,
     PT_Or = 286,
     PT_More = 287,
     PT_Less = 288,
     PT_Plus = 289,
     PT_Minus = 290,
     PT_Multiplication = 291,
     PT_Division = 292,
     PT_IntegerDivision = 293,
     PT_Equal = 294,
     PT_Semicolon = 295,
     PT_ID = 296,
     PT_EOF = 297,
     PT_Dot = 298,
     PT_Coma = 299,
     PT_Return = 300
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 16 "MIPT_Compiler\\Bison\\grammar.y"


	int integerValue;
	bool logicalValue;
	char* stringValue;
	
	Tree* node;


/* Line 387 of yacc.c  */
#line 186 "MIPT_Compiler/Analyzer/grammar.tab.cpp"
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
#line 214 "MIPT_Compiler/Analyzer/grammar.tab.cpp"

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
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    13,    14,    17,    22,    26,    27,
      30,    34,    35,    38,    41,    50,    55,    63,    65,    67,
      71,    74,    78,    80,    84,    88,    90,    94,    96,    98,
      99,   101,   105,   112,   118,   124,   129,   137,   141,   146,
     150,   154,   156,   158,   160,   166,   171,   174,   178,   180,
     182,   184,   186,   188,   190,   192,   194,   196,   197,   200,
     202,   207,   208,   210,   212,   216,   218,   220,   222,   224,
     226,   228,   230,   232,   234,   236,   238,   240,   242,   244,
     246,   248,   250,   252,   254,   256,   258
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    49,    42,    -1,    75,    41,    81,
      53,    82,    -1,    -1,    50,    49,    -1,    51,    81,    54,
      82,    -1,    75,    41,    52,    -1,    -1,    76,    41,    -1,
      54,    55,    54,    -1,    -1,    57,    54,    -1,    62,    54,
      -1,    12,    11,     3,    15,    56,    81,    64,    82,    -1,
       4,    85,    86,    41,    -1,    58,    41,    60,    81,    64,
      59,    82,    -1,    12,    -1,    13,    -1,    45,    66,    91,
      -1,    83,    84,    -1,    83,    61,    84,    -1,    62,    -1,
      62,    44,    61,    -1,    63,    41,    91,    -1,    79,    -1,
      79,    17,    20,    -1,    80,    -1,    41,    -1,    -1,    65,
      -1,    81,    65,    82,    -1,    78,    83,    66,    84,    65,
      68,    -1,    92,    83,    66,    84,    65,    -1,    90,    83,
      66,    84,    91,    -1,    41,    77,    66,    91,    -1,    41,
      85,    66,    86,    77,    66,    91,    -1,    66,    67,    66,
      -1,    66,    85,    66,    86,    -1,    66,    69,    87,    -1,
      66,    69,    70,    -1,    73,    -1,    41,    -1,    74,    -1,
      88,    79,    85,    66,    86,    -1,    88,    41,    83,    84,
      -1,    89,    66,    -1,    83,    66,    84,    -1,    34,    -1,
      35,    -1,    37,    -1,    38,    -1,    30,    -1,    31,    -1,
      36,    -1,    33,    -1,    32,    -1,    -1,    25,    64,    -1,
      43,    -1,    41,    83,    71,    84,    -1,    -1,    72,    -1,
      66,    -1,    66,    44,    72,    -1,     8,    -1,     9,    -1,
       5,    -1,    27,    -1,    10,    -1,    14,    -1,    39,    -1,
      23,    -1,     7,    -1,     6,    -1,    18,    -1,    21,    -1,
      16,    -1,    19,    -1,    17,    -1,    20,    -1,    26,    -1,
      28,    -1,    29,    -1,    22,    -1,    40,    -1,    24,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    74,    74,    77,    80,    81,    83,    86,    89,    90,
      93,    96,    97,    98,   101,   104,   107,   110,   111,   114,
     117,   118,   121,   122,   125,   128,   129,   130,   131,   134,
     135,   138,   139,   140,   141,   142,   143,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   171,   172,   175,
     178,   181,   182,   185,   186,   189,   190,   191,   194,   197,
     200,   203,   206,   209,   212,   215,   218,   221,   224,   227,
     230,   233,   236,   239,   242,   245,   248
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
  "PT_LeftRoundBracket", "PT_LeftSquareBracket", "PT_LeftBrace",
  "PT_RightRoundBracket", "PT_RightSquareBracket", "PT_RightBrace",
  "PT_Print", "PT_If", "PT_While", "PT_Else", "PT_Length", "PT_This",
  "PT_New", "PT_Negation", "PT_And", "PT_Or", "PT_More", "PT_Less",
  "PT_Plus", "PT_Minus", "PT_Multiplication", "PT_Division",
  "PT_IntegerDivision", "PT_Equal", "PT_Semicolon", "PT_ID", "PT_EOF",
  "PT_Dot", "PT_Coma", "PT_Return", "$accept", "Goal", "MainClass",
  "ClassDeclaration", "Class", "ClassStart", "Extends",
  "MainClassInternals", "ClassInternals", "MainFunction", "MainArgument",
  "Function", "Visibility", "Return", "ArgumentsList", "Argument",
  "Variable", "Type", "Statement", "StatementList", "Expression",
  "BinaryOperator", "ElseOptional", "MethodCall", "FunctionCall",
  "ExpressionList", "Expressions", "ValueT", "This", "ClassWord",
  "ExtendsWord", "Equals", "If", "Integer", "Boolean", "LeftBrace",
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
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    49,    49,    50,    51,    52,    52,
      53,    54,    54,    54,    55,    56,    57,    58,    58,    59,
      60,    60,    61,    61,    62,    63,    63,    63,    63,    64,
      64,    65,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      70,    71,    71,    72,    72,    73,    73,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     5,     0,     2,     4,     3,     0,     2,
       3,     0,     2,     2,     8,     4,     7,     1,     1,     3,
       2,     3,     1,     3,     3,     1,     3,     1,     1,     0,
       1,     3,     6,     5,     5,     4,     7,     3,     4,     3,
       3,     1,     1,     1,     5,     4,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     1,
       4,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    69,     0,     4,     0,     1,     0,     4,     0,     0,
       0,     2,     5,    75,    11,     8,     0,    74,    73,    17,
      18,    28,     0,    11,     0,    11,     0,    25,    27,    70,
       7,     0,     0,     0,    76,     6,    12,     0,    13,     0,
       0,     9,     3,     0,    11,    77,     0,     0,    85,    24,
      26,     0,    10,    29,    78,     0,    22,    20,     0,    84,
      72,    86,     0,     0,    30,     0,     0,     0,     0,    21,
       0,     0,    79,    71,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     0,    67,    65,    66,    68,    82,
      83,    42,     0,    41,    43,     0,     0,     0,     0,     0,
      16,     0,    31,     0,     0,     0,    29,    52,    53,    56,
      55,    48,    49,    54,    50,    51,    59,     0,     0,     0,
      35,     0,     0,     0,    46,    80,     0,    19,     0,     0,
       0,     0,     0,    37,    81,     0,    40,    39,     0,    47,
       0,     0,     0,    57,    34,    33,    15,    14,    61,    38,
      45,     0,     0,    29,    32,    63,     0,    62,    44,    36,
      58,     0,    60,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     7,     8,    30,    32,    22,    44,
      84,    23,    24,    77,    46,    55,    25,    26,    63,    64,
     155,   117,   154,   118,   136,   156,   157,    93,    94,     9,
      31,    74,    65,    27,    28,    66,    35,    95,    57,   119,
     126,   137,    96,    97,    67,    49,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
       1,  -101,    25,     1,   -24,  -101,   -14,     1,    16,    -3,
      16,  -101,  -101,  -101,    81,    33,    81,  -101,  -101,  -101,
    -101,  -101,    18,    81,    10,    81,    13,    42,  -101,  -101,
    -101,    21,    18,    60,  -101,  -101,  -101,    61,  -101,    36,
      69,  -101,  -101,    70,    81,  -101,    16,    17,  -101,  -101,
    -101,    87,  -101,    51,  -101,    76,    58,  -101,    88,  -101,
    -101,  -101,     3,    59,  -101,    61,    51,    61,    61,  -101,
      20,   102,  -101,  -101,    55,    55,    55,    18,    55,    18,
      55,    55,  -101,    90,    16,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,   103,  -101,  -101,    55,     0,    55,   125,   103,
    -101,   147,  -101,   147,   147,    89,    51,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,    55,    -4,    55,
    -101,   147,    61,    90,   169,  -101,    82,  -101,    51,    36,
      51,    67,    18,   169,  -101,    61,  -101,  -101,   125,  -101,
      76,    55,    55,   100,  -101,  -101,  -101,  -101,    55,  -101,
    -101,   125,   103,    51,  -101,    80,    76,  -101,  -101,  -101,
    -101,    55,  -101,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,   119,  -101,  -101,  -101,  -101,    75,  -101,
    -101,  -101,  -101,  -101,  -101,    57,   -26,  -101,  -100,   -63,
     -62,  -101,  -101,  -101,  -101,  -101,   -33,  -101,  -101,   129,
    -101,     4,  -101,    35,  -101,    -6,   -27,   -36,   -55,   -53,
     -95,  -101,  -101,  -101,  -101,   -84,  -101
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      69,    47,    14,    79,    16,    42,   132,    18,   120,    75,
     131,     1,    92,    98,    99,   127,   101,    10,   103,   104,
      72,    56,   134,    17,    18,     5,    17,    18,    11,    78,
     105,    80,    81,   121,    13,   124,    54,   135,    15,    34,
      53,   122,    73,   149,    56,   144,   128,    29,   129,   130,
     100,    37,   102,   160,    39,   133,   158,   138,    21,    40,
      85,    21,    41,    86,    87,   143,   139,   145,   159,    13,
     141,    45,    43,    59,    60,    61,    48,    45,   106,   151,
     152,    51,    88,    89,    90,   150,   140,    17,    18,    50,
      58,    33,    62,    19,    20,    54,    91,    72,    36,   148,
      38,   162,    70,    71,    76,   147,    83,    72,   146,   125,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    52,
      72,    73,    21,   116,   161,   153,    12,    82,   163,     4,
     142,   123,     0,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    72,    48,     0,   125,   116,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    72,     0,    54,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    72,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,   116
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-101)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      55,    37,     8,    66,    10,    32,   106,     7,    92,    62,
     105,    10,    74,    75,    76,    99,    78,    41,    80,    81,
      17,    47,    26,     6,     7,     0,     6,     7,    42,    65,
      83,    67,    68,    95,    18,    97,    19,    41,    41,    21,
      46,    41,    39,   138,    70,   129,   101,    14,   103,   104,
      77,    41,    79,   153,    41,   117,   151,   119,    41,    17,
       5,    41,    41,     8,     9,   128,   121,   130,   152,    18,
     123,    16,    12,    22,    23,    24,    40,    16,    84,   141,
     142,    11,    27,    28,    29,   140,   122,     6,     7,    20,
       3,    16,    41,    12,    13,    19,    41,    17,    23,   135,
      25,   156,    44,    15,    45,   132,     4,    17,    41,    20,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    44,
      17,    39,    41,    43,    44,    25,     7,    70,   161,     0,
     126,    96,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    17,    40,    -1,    20,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    17,    -1,    19,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    17,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    47,    48,    75,     0,    49,    50,    51,    75,
      41,    42,    49,    18,    81,    41,    81,     6,     7,    12,
      13,    41,    54,    57,    58,    62,    63,    79,    80,    14,
      52,    76,    53,    54,    21,    82,    54,    41,    54,    41,
      17,    41,    82,    12,    55,    16,    60,    83,    40,    91,
      20,    11,    54,    81,    19,    61,    62,    84,     3,    22,
      23,    24,    41,    64,    65,    78,    81,    90,    92,    84,
      44,    15,    17,    39,    77,    85,    45,    59,    83,    65,
      83,    83,    61,     4,    56,     5,     8,     9,    27,    28,
      29,    41,    66,    73,    74,    83,    88,    89,    66,    66,
      82,    66,    82,    66,    66,    85,    81,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    43,    67,    69,    85,
      91,    66,    41,    79,    66,    20,    86,    91,    84,    84,
      84,    86,    64,    66,    26,    41,    70,    87,    66,    84,
      83,    85,    77,    65,    91,    65,    41,    82,    83,    86,
      84,    66,    66,    25,    68,    66,    71,    72,    86,    91,
      64,    44,    84,    72
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
#line 74 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Start \n"); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 77 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("MainClass \n"); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 83 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Class \n"); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 96 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Empty internals \n"); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 97 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Function \n"); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 98 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Filed \n"); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 101 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Main \n"); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 107 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Function Decl \n"); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 117 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Zero Argumens \n"); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 118 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Argument List \n"); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 121 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Last Variable \n"); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 122 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Variable \n"); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 125 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Variable \n"); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 128 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Integer \n"); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 129 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Array of Int \n"); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 130 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Bool \n"); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 131 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("User Type \n"); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 134 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Empty Statement \n"); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 135 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Non empty statement \n"); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 138 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Visibility \n"); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 147 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (3)].node)), ToExpr((yyvsp[(3) - (3)].node)), ToBinOp((yyvsp[(2) - (3)].node)), exst::BinaryOperator_STATE);}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 148 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (4)].node)), ToExpr((yyvsp[(3) - (4)].node)), exst::SquareBracket_STATE);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 149 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (3)].node)), exst::Length_STATE);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 150 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (3)].node)), ToFcall((yyvsp[(3) - (3)].node)), exst::FunctionCall_STATE);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 151 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(ToVal((yyvsp[(1) - (1)].node)), exst::Value_STATE);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 152 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(new Identifier((yyvsp[(1) - (1)].stringValue)), exst::ID_STATE);}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 153 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(exst::This_State);}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 154 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(ToExpr((yyvsp[(4) - (5)].node)), exst::Array_STATE);}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 155 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(new Identifier((yyvsp[(2) - (4)].stringValue)), exst::NewObj_STATE);}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 156 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(exst::Not_STATE); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 157 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 160 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new BinaryOperator(boot::PT_Plus); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 161 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new BinaryOperator(boot::PT_Minus); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 162 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new BinaryOperator(boot::PT_Division); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 163 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new BinaryOperator(boot::PT_IntegerDivision); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 164 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new BinaryOperator(boot::PT_And); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 165 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new BinaryOperator(boot::PT_Or); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 166 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new BinaryOperator(boot::PT_Multiplication); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 167 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new BinaryOperator(boot::PT_Less); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 168 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new BinaryOperator(boot::PT_More); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 178 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new FunctionCall(ToExpr((yyvsp[(3) - (4)].node)), new Identifier((yyvsp[(1) - (4)].stringValue))); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 181 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(exst::Empty_STATE);}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 182 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (1)].node)), exst::List_STATE);}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 185 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (1)].node)), exst::List_STATE);}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 186 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Expression(ToExpr((yyvsp[(1) - (3)].node)), ToExpr((yyvsp[(3) - (3)].node)), exst::List_STATE);}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 189 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Value(true);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 190 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Value(false);}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 191 "MIPT_Compiler\\Bison\\grammar.y"
    { (yyval.node)=new Value((yyvsp[(1) - (1)].integerValue));}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 197 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Class \n"); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 200 "MIPT_Compiler\\Bison\\grammar.y"
    { printf("Extends \n"); }
    break;


/* Line 1792 of yacc.c  */
#line 1871 "MIPT_Compiler/Analyzer/grammar.tab.cpp"
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
#line 251 "MIPT_Compiler\\Bison\\grammar.y"

