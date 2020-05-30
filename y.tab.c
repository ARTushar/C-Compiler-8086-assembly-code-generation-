/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "1605070.y" /* yacc.c:339  */


#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>
#include "1605070_SymbolTable.h"
#include <vector>
#include <unordered_set>

using namespace std;
int yyparse(void);
extern "C" int yylex();
extern FILE *yyin;
extern int line_count;
FILE *logout  = fopen("1605070_log.txt","w");
// FILE *logout_er  = fopen("1605070_loger.txt","w");
FILE *codeout = fopen("1605070_code.asm", "w");

extern int total_error;

SymbolTable *table = new SymbolTable(30, logout);
vector<pair<string, string>> parameters;
bool parameterSaved = false;
string functionReturnType = "";
bool hasReturnType = false;
bool matchFunction(vector<string> &, vector<string> &);
vector<string> split_token(const string& s, const string& delimeters);
unordered_set<string> variable_set;
vector<string> tempVar_set;
string current_function_name = "";

int labelCount = 0;
int tempCount = 0;

string newLabel();
string newTempVar();
string initialized_code = ".model small\n.stack 100h\n.data\n";
string variable_defined = "";
string function_defined = "";
string main_defined = "";
string funct_call_var();
int totalArguments = 0;
int max_parameters = 0;

void yyerror(const char *s)
{
	//write your code
	fprintf(logout, "Error at line %d : %s\n\n", line_count, s);
}


#line 120 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    ASSIGNOP = 262,
    COMMA = 263,
    INCOP = 264,
    DECOP = 265,
    FLOAT = 266,
    CHAR = 267,
    INT = 268,
    LCURL = 269,
    LPAREN = 270,
    LTHIRD = 271,
    NOT = 272,
    PRINTLN = 273,
    RCURL = 274,
    RETURN = 275,
    SEMICOLON = 276,
    RTHIRD = 277,
    RPAREN = 278,
    VOID = 279,
    DOUBLE = 280,
    ADDOP = 281,
    CONST_FLOAT = 282,
    CONST_INT = 283,
    ID = 284,
    LOGICOP = 285,
    MULOP = 286,
    RELOP = 287,
    LOWER_THAN_ELSE = 288
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define ASSIGNOP 262
#define COMMA 263
#define INCOP 264
#define DECOP 265
#define FLOAT 266
#define CHAR 267
#define INT 268
#define LCURL 269
#define LPAREN 270
#define LTHIRD 271
#define NOT 272
#define PRINTLN 273
#define RCURL 274
#define RETURN 275
#define SEMICOLON 276
#define RTHIRD 277
#define RPAREN 278
#define VOID 279
#define DOUBLE 280
#define ADDOP 281
#define CONST_FLOAT 282
#define CONST_INT 283
#define ID 284
#define LOGICOP 285
#define MULOP 286
#define RELOP 287
#define LOWER_THAN_ELSE 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 57 "1605070.y" /* yacc.c:355  */

	SymbolInfo* info;

#line 230 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 247 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,   153,   162,   172,   180,   189,   200,   213,
     224,   259,   292,   344,   390,   414,   425,   438,   450,   463,
     475,   500,   556,   607,   613,   619,   625,   633,   643,   654,
     663,   675,   686,   701,   712,   723,   734,   757,   774,   793,
     812,   828,   838,   854,   865,   872,   886,   913,   955,   968,
    1002,  1015,  1058,  1071,  1117,  1130,  1162,  1175,  1219,  1244,
    1261,  1276,  1303,  1303,  1374,  1387,  1405,  1414,  1433,  1454,
    1467,  1476,  1496
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "ASSIGNOP",
  "COMMA", "INCOP", "DECOP", "FLOAT", "CHAR", "INT", "LCURL", "LPAREN",
  "LTHIRD", "NOT", "PRINTLN", "RCURL", "RETURN", "SEMICOLON", "RTHIRD",
  "RPAREN", "VOID", "DOUBLE", "ADDOP", "CONST_FLOAT", "CONST_INT", "ID",
  "LOGICOP", "MULOP", "RELOP", "LOWER_THAN_ELSE", "$accept", "start",
  "program", "unit", "func_declaration", "func_definition",
  "function_first_part_1", "function_first_part_2", "parameter_list",
  "compound_statement", "left_curl", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor", "$@1",
  "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      35,   -67,   -67,   -67,   -67,    17,    35,   -67,   -67,   -67,
       1,     2,   -67,     7,   -67,   -67,   -67,   -67,   -67,    75,
     -67,   -67,     3,     4,    18,    26,    38,    11,    11,    46,
     -67,    11,   -67,    11,   -67,   -67,    29,   -67,   -67,    40,
     102,   -67,   -67,   155,    56,   -67,    34,    -5,    53,   -67,
     -67,   148,    57,   -67,    62,   -67,    11,    45,    11,    77,
      58,   -67,    80,     9,   -67,   -67,    11,    90,   -67,   -67,
      11,   -67,   -67,   -67,    11,    11,    11,    11,   -67,    12,
      81,    89,    96,    95,    45,   101,   -67,   104,   -67,   -67,
      11,   103,   -67,   -67,    53,   107,   -67,    35,   -67,   -67,
     -67,   108,   129,    11,   129,    10,   -67,   114,   130,   -67,
     110,   123,   144,   128,   -67,   -67,   -67,   -67,    11,   -67,
     -67,   129,   129,   -67,   -67,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    24,    26,    23,    25,     0,     2,     4,     6,     7,
       0,     0,     5,     0,     1,     3,    20,     8,    10,     0,
       9,    11,    29,     0,     0,     0,     0,     0,     0,     0,
      19,     0,    44,     0,    66,    65,    46,    35,    33,     0,
       0,    31,    34,    61,     0,    48,    50,    52,    54,    56,
      60,     0,     0,    22,     0,    21,     0,     0,     0,     0,
      61,    59,     0,     0,    58,    62,     0,    29,    18,    32,
       0,    67,    68,    45,     0,     0,     0,     0,    13,     0,
      17,     0,    27,     0,     0,     0,    64,     0,    43,    42,
      70,     0,    49,    51,    55,    53,    57,     0,    12,    16,
      30,     0,     0,     0,     0,     0,    72,     0,    69,    47,
      15,     0,    37,     0,    39,    41,    40,    63,     0,    14,
      28,     0,     0,    71,    38,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   146,   -67,   -67,   -67,   -67,   -67,    65,
     -67,    43,     0,   -67,   -67,   -39,   -55,   -20,   -24,   -66,
      92,    78,    88,   -19,   -67,   -67,   -67,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    10,    11,    79,    37,
      19,    38,    39,    23,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    90,   107,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    69,    84,    59,    92,    53,    13,    63,    60,    61,
      88,   115,    54,    60,    64,    16,    16,    14,    51,    52,
      97,    75,    17,    20,   106,    55,    27,    76,    28,   103,
      89,   116,    83,    56,    85,    98,    22,    33,    34,    35,
      36,    57,    91,    12,    65,    66,     1,     2,     3,    12,
      60,    80,   123,    58,    60,    60,    60,    60,    96,     4,
      27,    62,    28,   112,    74,   114,    32,    71,    72,    67,
      60,    33,    34,    35,    36,    18,    21,    73,    24,   113,
      25,    26,   124,   125,    77,    81,     1,     2,     3,    16,
      27,    82,    28,    29,    30,    31,    32,   110,    60,     4,
      86,    33,    34,    35,    36,    24,    52,    25,    26,    87,
      99,   100,   101,     1,     2,     3,    16,    27,   102,    28,
      29,    68,    31,    32,   104,   109,     4,   105,    33,    34,
      35,    36,    24,    75,    25,    26,   111,   117,   118,   119,
       1,     2,     3,    16,    27,   120,    28,    29,   121,    31,
      32,   122,    15,     4,    95,    33,    34,    35,    36,     1,
       2,     3,    70,    94,    71,    72,    93,     0,     0,     0,
       0,    78,     4
};

static const yytype_int8 yycheck[] =
{
       0,    40,    57,    27,    70,     1,     6,    31,    28,    28,
       1,     1,     8,    33,    33,    14,    14,     0,    15,    16,
       8,    26,    21,    21,    90,    21,    15,    32,    17,    84,
      21,    21,    56,    15,    58,    23,    29,    26,    27,    28,
      29,    15,    66,     0,    15,    16,    11,    12,    13,     6,
      70,    51,   118,    15,    74,    75,    76,    77,    77,    24,
      15,    15,    17,   102,    30,   104,    21,     9,    10,    29,
      90,    26,    27,    28,    29,    10,    11,    21,     3,   103,
       5,     6,   121,   122,    31,    28,    11,    12,    13,    14,
      15,    29,    17,    18,    19,    20,    21,    97,   118,    24,
      23,    26,    27,    28,    29,     3,    16,     5,     6,    29,
      29,    22,    16,    11,    12,    13,    14,    15,    23,    17,
      18,    19,    20,    21,    23,    22,    24,    23,    26,    27,
      28,    29,     3,    26,     5,     6,    28,    23,     8,    29,
      11,    12,    13,    14,    15,    22,    17,    18,     4,    20,
      21,    23,     6,    24,    76,    26,    27,    28,    29,    11,
      12,    13,     7,    75,     9,    10,    74,    -1,    -1,    -1,
      -1,    23,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    13,    24,    35,    36,    37,    38,    39,
      40,    41,    45,    46,     0,    37,    14,    21,    43,    44,
      21,    43,    29,    47,     3,     5,     6,    15,    17,    18,
      19,    20,    21,    26,    27,    28,    29,    43,    45,    46,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    15,    16,     1,     8,    21,    15,    15,    15,    52,
      51,    57,    15,    52,    57,    15,    16,    29,    19,    49,
       7,     9,    10,    21,    30,    26,    32,    31,    23,    42,
      46,    28,    29,    52,    50,    52,    23,    29,     1,    21,
      59,    52,    53,    54,    56,    55,    57,     8,    23,    29,
      22,    16,    23,    50,    23,    23,    53,    60,    61,    22,
      46,    28,    49,    52,    49,     1,    21,    23,     8,    29,
      22,     4,    23,    53,    49,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    37,    38,    38,
      39,    39,    40,    41,    42,    42,    42,    42,    43,    43,
      44,    45,    45,    46,    46,    46,    46,    47,    47,    47,
      47,    48,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      57,    58,    59,    58,    58,    58,    58,    58,    58,    60,
      60,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     2,     2,
       2,     2,     5,     4,     4,     3,     2,     1,     3,     2,
       1,     3,     3,     1,     1,     1,     1,     3,     6,     1,
       4,     1,     2,     1,     1,     1,     7,     5,     7,     5,
       5,     5,     3,     3,     1,     2,     1,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     0,     5,     3,     1,     1,     2,     2,     1,
       0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 72 "1605070.y" /* yacc.c:1646  */
    {
	// //fprintf(logout_er, "At line no: %d start : program\n", line_count);
	//fprintf(logout_er, "\t\t Symbol Table:\n\n");
	// table->printAll();
	if(total_error == 0){
		// peephole optimization
		vector<string> check1 = split_token(main_defined, "\n");
		vector<string> check2 = split_token(function_defined, "\n");
		// unordered_set<string> variable_set;
		bool previous_hole = false;

		string main_defined_new = "";
		string function_defined_new = "";
		string variable_defined_new = "";
		string test1 = check1[0];
		string test2;
		vector<string> tokens1 = split_token(test1, " ,");
		vector<string> tokens2;
		for(int i = 1; i < check1.size()-4; i++){
			test2 = check1[i];
			tokens2 = split_token(test2, " ,");
			if(tokens1.size() == 3 && tokens2.size() == 3 && tokens1[0] == "mov" && tokens2[0] == "mov" && tokens1[1] == tokens2[2] && tokens1[2] == tokens2[1] ){
				if((tokens1[1][0] == 't' || tokens1[2][0] == 't')){
					variable_set.erase(tokens1[1]+"\tdw\t'?'\n");
					variable_set.erase(tokens1[2]+"\tdw\t'?'\n");
				} else if(tokens1[1][0] != 't'){
					main_defined_new += test1 + "\n";
				}
				previous_hole = true;
			} else{
				if(!previous_hole) main_defined_new += test1 + "\n";
				previous_hole = false;
			}
			test1 = test2 ;
			tokens1 = tokens2;
		}
		main_defined_new += "mov ah, 4ch\nint 21h\n";

		test1 = check2[0];
		tokens1 = split_token(test1, " ,");
		tokens2;

		for(int i = 1; i < check2.size(); i++){
			test2 = check2[i];
			tokens2 = split_token(test2, " ,");
			if(tokens1.size() == 3 && tokens2.size() == 3 && tokens1[0] == "mov" && tokens2[0] == "mov" && tokens1[1] == tokens2[2] && tokens1[2] == tokens2[1]){
				if((tokens1[1][0] == 't' || tokens1[2][0] == 't')){
					variable_set.erase(tokens1[1]+"\tdw\t'?'\n");
					variable_set.erase(tokens1[2]+"\tdw\t'?'\n");
				} else if(tokens1[1][0] != 't'){
					function_defined_new += test1 + "\n";
				}
				previous_hole = true;
			}
			 else if(tokens1.size() == 2 && (tokens1[0] == "push" || tokens1[0] == "pop") && tokens1[1][0] == 't' && variable_set.find(tokens1[1]+"\tdw\t'?'\n") == variable_set.end()){

			} else{
				if(!previous_hole) function_defined_new += test1 + "\n";
				previous_hole = false;
			}
			
			test1 = test2 ;
			tokens1 = tokens2;
		}

		for(string var : variable_set){
			variable_defined_new += var;
		}

		string print_func = "println proc\npush ax\npush bx\npush cx\npush dx\nor ax, ax\njge @end_if\npush ax\nmov dl, '-'\nmov ah, 2\nint 21h\npop ax\nneg ax\n@end_if:\nxor cx, cx\nmov bx, 10d\n@repeat1:\nxor dx, dx\ndiv bx\npush dx\ninc cx\nor ax, ax\njne @repeat1\nmov ah, 2\n@print_loop:\npop dx\nor dl, 30h\nint 21h\nloop @print_loop\nmov ah, 2\nmov dl, 0dh\nint 21h\nmov dl, 0ah\nint 21h\n\npop dx\npop cx\npop bx\npop ax\nret\nprintln endp\n";

		fprintf(codeout, "%s%s",initialized_code.c_str(), variable_defined_new.c_str());
		for(int i = 1; i <= max_parameters; i++){
			fprintf(codeout, "%s\tdw\t'?'\n", funct_call_var().c_str());
		}
		fprintf(codeout, "\n%smain\tendp\n\n%s\n%s\tend main", main_defined_new.c_str(), function_defined_new.c_str(), print_func.c_str());
	}
	delete (yyvsp[0].info);
}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 153 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d program : program unit\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[-1].info)->getName() + (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());
	delete (yyvsp[-1].info);
	delete (yyvsp[0].info);
}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 162 "1605070.y" /* yacc.c:1646  */
    {
		//fprintf(logout_er, "At line no: %d program : unit\n", line_count);
		(yyval.info) = new SymbolInfo();
		string str = (yyvsp[0].info)->getName();
		(yyval.info)->setName(str);
		//fprintf(logout_er, "\n%s\n\n", str.c_str());
		delete (yyvsp[0].info);
 	}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 172 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d unit : var_declaration\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[0].info)->getName() ;
	(yyval.info)->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());
	delete (yyvsp[0].info);
}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 180 "1605070.y" /* yacc.c:1646  */
    {
		 //fprintf(logout_er, "At line no: %d unit : func_declaration\n", line_count);
		 (yyval.info) = new SymbolInfo();
		 string str = (yyvsp[0].info)->getName();
		 (yyval.info)->setName(str);
		 //fprintf(logout_er, "\n%s\n\n", str.c_str());

		 delete (yyvsp[0].info);
	 }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 189 "1605070.y" /* yacc.c:1646  */
    {
		 //fprintf(logout_er, "At line no: %d unit : func_definition\n", line_count);
		 (yyval.info) = new SymbolInfo();
		 string str = (yyvsp[0].info)->getName();
		 (yyval.info)->setName(str);
		 //fprintf(logout_er, "\n%s\n\n", str.c_str());

		 delete (yyvsp[0].info);
	 }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 200 "1605070.y" /* yacc.c:1646  */
    {
	if(parameterSaved){
		parameters.clear();
		parameterSaved = false;
	}
	//fprintf(logout_er, "At line no: %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[-1].info)->getName() + ";\n";
	(yyval.info)->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	delete (yyvsp[-1].info);
}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 213 "1605070.y" /* yacc.c:1646  */
    {
			//fprintf(logout_er, "At line no: %d func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n", line_count);
			(yyval.info) = new SymbolInfo();
			string str = (yyvsp[-1].info)->getName() + ";\n";
			(yyval.info)->setName(str);
			//fprintf(logout_er, "\n%s\n\n", str.c_str());

			delete (yyvsp[-1].info);
		}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 224 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[-1].info)->getName() + " " + (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());
	SymbolInfo* symbol = table->lookUp((yyvsp[-1].info)->getType());
	if(symbol){
		if(symbol->isDefined){
			fprintf(logout, "Error at line %s : redefinition of '%s'\n\n", (yyvsp[-1].info)->parameterList[0].c_str(), (yyvsp[-1].info)->getType().c_str());
			total_error++;
		} else {
			symbol->isDefined = true;
			if(!hasReturnType && symbol->parameterList[0] != "void") {
				fprintf(logout, "Error at line  %d : function body has no return statement\n\n", line_count);
				total_error++;
			} else {
				hasReturnType = false;
				(yyval.info)->code += (yyvsp[-1].info)->getType()+"\tproc\n";
				/* for(int i = 1; i <= stoi($1->getCategory()); i++ ){
					$$->code += "push f"+to_string(i)+"\n";
				} */
				(yyval.info)->code += (yyvsp[0].info)->code;
				/* for(int i = stoi($1->getCategory()); i >= 1; i-- ){
					$$->code += "pop f"+to_string(i)+"\n";
				} */
				(yyval.info)->code += (yyvsp[-1].info)->getType()+"\tendp\n\n";
				function_defined += (yyval.info)->code;
			}
		}
	}

	delete (yyvsp[-1].info);
	delete (yyvsp[0].info);
}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 259 "1605070.y" /* yacc.c:1646  */
    {
			//fprintf(logout_er, "At line no: %d func_definition : type_specifier ID LPAREN RPAREN compound_statement\n", line_count);
			(yyval.info) = new SymbolInfo();
			string str = (yyvsp[-1].info)->getName() + " " + (yyvsp[0].info)->getName();
			(yyval.info)->setName(str);
			//fprintf(logout_er, "\n%s\n\n", str.c_str());
			SymbolInfo* symbol = table->lookUp((yyvsp[-1].info)->getType());
			if(symbol){
				if(symbol->isDefined){
				fprintf(logout, "Error at line %s : redefinition of '%s'\n\n", (yyvsp[-1].info)->parameterList[0].c_str(), (yyvsp[-1].info)->getType().c_str());
				total_error++;
				} else {
					symbol->isDefined = true;
					if(!hasReturnType && symbol->parameterList[0] != "void") {
						fprintf(logout, "Error at line  %d : function body has no return statement\n\n", line_count);
						total_error++;
					} else {
						hasReturnType = false;

						if((yyvsp[-1].info)->getType() == "main"){
							main_defined += "main\tproc\nmov ax, @data\nmov ds, ax\n" + (yyvsp[0].info)->code + "main\tendp\n\n";
						} else {
							function_defined += (yyvsp[-1].info)->getType() + "\tproc\n"+(yyvsp[0].info)->code+(yyvsp[-1].info)->getType()+ "\tendp\n\n";
						}
					}
				}
			}

			delete (yyvsp[-1].info);
			delete (yyvsp[0].info);
		}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 292 "1605070.y" /* yacc.c:1646  */
    {

	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[-4].info)->getName() + " " + (yyvsp[-3].info)->getName() + "(" + (yyvsp[-1].info)->getName() + ")";
	(yyval.info)->setName(str);
	parameterSaved = true;
	(yyval.info)->setCategory(to_string((yyvsp[-1].info)->parameterList.size()));

	SymbolInfo* foundSymbol = table->lookUp((yyvsp[-3].info)->getName());

	if(foundSymbol){
		vector<string> list = foundSymbol->parameterList;
		vector<string> para;
		para.push_back((yyvsp[-4].info)->getName());
		para.insert(para.end(), (yyvsp[-1].info)->parameterList.begin(), (yyvsp[-1].info)->parameterList.end());
		para.push_back("function");
		if(list[list.size() - 1] == "function"){
			if(!matchFunction(list, para)){
				fprintf(logout, "Erorr at line %d : conflicting types for  '%s'\n\n", line_count, (yyvsp[-3].info)->getName().c_str());
				total_error++;
				(yyval.info)->setName("error");
			} else {
				functionReturnType = (yyvsp[-4].info)->getName();
				(yyval.info)->setType((yyvsp[-3].info)->getName());
				(yyval.info)->parameterList.push_back(to_string(line_count));
			}
		}
		else {
			fprintf(logout, "Erorr at line %d : '%s' redeclared as different kind of symbol\n\n", line_count, (yyvsp[-3].info)->getName().c_str());
			total_error++;
			(yyval.info)->setName("error");
		}
	} else {

		SymbolInfo* symbol = new SymbolInfo((yyvsp[-3].info)->getName(), "ID");
		symbol->parameterList.push_back((yyvsp[-4].info)->getName());
		symbol->parameterList.insert(symbol->parameterList.end(), (yyvsp[-1].info)->parameterList.begin(), (yyvsp[-1].info)->parameterList.end());
		symbol->parameterList.push_back("function");
		functionReturnType = (yyvsp[-4].info)->getName();
		(yyval.info)->setType((yyvsp[-3].info)->getName());
		current_function_name = (yyvsp[-3].info)->getName();

		(yyval.info)->parameterList.push_back(to_string(line_count));
		table->insert(symbol);
	}

	delete (yyvsp[-4].info);
	delete (yyvsp[-3].info);
	delete (yyvsp[-1].info);
}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 344 "1605070.y" /* yacc.c:1646  */
    {

	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[-3].info)->getName() + " " + (yyvsp[-2].info)->getName() + "()";
	(yyval.info)->setName(str);

	SymbolInfo* foundSymbol = table->lookUp((yyvsp[-2].info)->getName());

	if(foundSymbol){
		vector<string> list = foundSymbol->parameterList;
		if(list[list.size() - 1] == "function"){
			if(list.size() != 2){
				fprintf(logout, "Erorr at line %d : conflicting types for  '%s'\n\n", line_count, (yyvsp[-2].info)->getName().c_str());
				(yyval.info)->setName("error");
				total_error++;
			} else {
				functionReturnType = (yyvsp[-3].info)->getName();
				(yyval.info)->setType((yyvsp[-2].info)->getName());
				(yyval.info)->parameterList.push_back(to_string(line_count));
			}
		}
		else {
			fprintf(logout, "Erorr at line %d : '%s' redeclared as different kind of symbol\n\n", line_count, (yyvsp[-2].info)->getName().c_str());
			(yyval.info)->setName("error");
			total_error++;
		}

	} else {
		SymbolInfo* symbol = new SymbolInfo((yyvsp[-2].info)->getName(), "ID");
		symbol->parameterList.push_back((yyvsp[-3].info)->getName());
		symbol->parameterList.push_back("function");
		functionReturnType = (yyvsp[-3].info)->getName();
		(yyval.info)->setType((yyvsp[-2].info)->getName());
		current_function_name = (yyvsp[-2].info)->getName();
		(yyval.info)->parameterList.push_back(to_string(line_count));

		table->insert(symbol);
	}

	delete (yyvsp[-3].info);
	delete (yyvsp[-2].info);

}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 390 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d parameter_list  : parameter_list COMMA type_specifier ID\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[-3].info)->getName() + ", " + (yyvsp[-1].info)->getName() + " "+ (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	(yyval.info)->parameterList.insert((yyval.info)->parameterList.end(), (yyvsp[-3].info)->parameterList.begin(), (yyvsp[-3].info)->parameterList.end());
	(yyval.info)->parameterList.push_back((yyvsp[-1].info)->getName());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	bool duplicateName = false;
	for(int i = 0; i < parameters.size(); i++) {
		if(parameters[i].first == (yyvsp[0].info)->getName()){
			duplicateName = true;
			break;
		}
	}
	if(duplicateName) {
		fprintf(logout, "Error at line %d : multiple definition of '%s'\n\n", line_count, (yyvsp[0].info)->getName().c_str());
	} else parameters.push_back(make_pair((yyvsp[0].info)->getName(), (yyvsp[-1].info)->getName()));

	delete (yyvsp[-3].info);
	delete (yyvsp[-1].info);
	delete (yyvsp[0].info);
}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 414 "1605070.y" /* yacc.c:1646  */
    {
			//fprintf(logout_er, "At line no: %d parameter_list  : parameter_list COMMA type_specifier\n", line_count);
			(yyval.info) = new SymbolInfo();
			string str = (yyvsp[-2].info)->getName() + ", " + (yyvsp[0].info)->getName();
			(yyval.info)->setName(str);
			(yyval.info)->parameterList.insert((yyval.info)->parameterList.end(), (yyvsp[-2].info)->parameterList.begin(), (yyvsp[-2].info)->parameterList.end());
			(yyval.info)->parameterList.push_back((yyvsp[0].info)->getName());
			//fprintf(logout_er, "\n%s\n\n", str.c_str());
			delete (yyvsp[-2].info);
			delete (yyvsp[0].info);
		}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 425 "1605070.y" /* yacc.c:1646  */
    {
			 //fprintf(logout_er, "At line no: %d parameter_list  : type_specifier ID\n", line_count);
			 (yyval.info) = new SymbolInfo();
			 string str = (yyvsp[-1].info)->getName() + " " + (yyvsp[0].info)->getName();
			 (yyval.info)->setName(str);
			 (yyval.info)->parameterList.push_back((yyvsp[-1].info)->getName());
			 //fprintf(logout_er, "\n%s\n\n", str.c_str());

			 parameters.push_back(make_pair((yyvsp[0].info)->getName(), (yyvsp[-1].info)->getName()));

			 delete (yyvsp[-1].info);
			 delete (yyvsp[0].info);
		 }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 438 "1605070.y" /* yacc.c:1646  */
    {
			//fprintf(logout_er, "At line no: %d parameter_list  : type_specifier\n", line_count);
			(yyval.info) = new SymbolInfo();
			string str = (yyvsp[0].info)->getName();
			(yyval.info)->setName(str);
			(yyval.info)->parameterList.push_back((yyvsp[0].info)->getName());
			//fprintf(logout_er, "\n%s\n\n", str.c_str());
			delete (yyvsp[0].info);
		}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 450 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d compound_statement : LCURL statements RCURL\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = "{\n" + (yyvsp[-1].info)->getName() + "}\n";
	(yyval.info)->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());
	// table->printAll();
	table->exitScope();

	(yyval.info)->code += (yyvsp[-1].info)->code;

	delete (yyvsp[-1].info);
}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 463 "1605070.y" /* yacc.c:1646  */
    {
				 //fprintf(logout_er, "At line no: %d compound_statement : LCURL RCURL\n", line_count);
				 (yyval.info) = new SymbolInfo();
			 	 string str = "{\n}\n";
			 	 (yyval.info)->setName(str);
			 	 //fprintf(logout_er, "\n%s\n\n", str.c_str());

				//  table->printAll();
				 table->exitScope();
			 }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 475 "1605070.y" /* yacc.c:1646  */
    {
	table->enterScope();

	if(parameters.size() != 0){
		tempVar_set.clear();

	}

	for(int i = 0; i < parameters.size(); i++){
		SymbolInfo* symbol = new SymbolInfo(parameters[i].first, "ID");
		symbol->parameterList.push_back(parameters[i].second);
		symbol->parameterList.push_back("normal");
		table->insert(symbol);
		int temp = i + 1;
		string var = "f"+to_string(temp);
		symbol->setSymbol(var);
	}
	if(parameters.size() > max_parameters) max_parameters = parameters.size();

	if(parameters.size() != 0){
		parameters.clear();
	}
}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 500 "1605070.y" /* yacc.c:1646  */
    {
		//fprintf(logout_er, "At line no: %d var_declaration : type_specifier declaration_list SEMICOLON\n", line_count);
		(yyval.info) = new SymbolInfo();
		string str = (yyvsp[-2].info)->getName() + " " + (yyvsp[-1].info)->getName() + ";\n";
		if((yyvsp[-2].info)->getName() == "void") {
			(yyval.info)->setName("error");
			fprintf(logout, "Error at line %d : variable declared void\n\n", line_count);
			total_error++;
		} else {
			(yyval.info)->setName(str);
			//fprintf(logout_er, "\n%s\n\n", str.c_str());

			stringstream tokenize((yyvsp[-1].info)->getName());
			string temp;

			while(getline(tokenize, temp, ',')){
				int found = temp.find("[");
				if(found == -1) {
					SymbolInfo* got = table->lookUpCurrent(temp);
					if(got) {
						fprintf(logout, "Error at line %d : redeclaration of '%s'\n\n", line_count, temp.c_str());
						total_error++;
					} else {
						SymbolInfo* symbol = new SymbolInfo(temp, "ID");
						symbol->parameterList.push_back((yyvsp[-2].info)->getName());
						symbol->parameterList.push_back("normal");
						table->insert(symbol);
						variable_defined += symbol->getSymbol() + "\tdw\t'?'\n";
						variable_set.insert(symbol->getSymbol()+"\tdw\t'?'\n");

					}
				}
				else{
					int found2 = temp.find("]", found+1);
					string size = temp.substr(found+1, found2-found-1);
					string content = temp.substr(0,found);
					bool got = table->lookUpCurrent(content);
					if(got) {
						fprintf(logout, "Error at line %d : redeclaration of '%s'\n\n", line_count, content.c_str());
						total_error++;
					} else {
						SymbolInfo* symbol = new SymbolInfo(content, "ID");
						symbol->parameterList.push_back((yyvsp[-2].info)->getName());
						symbol->parameterList.push_back(size);
						symbol->parameterList.push_back("array");
						table->insert(symbol);
						variable_defined += symbol->getSymbol() + "\tdw\t" + size + " dup (?)\n";
						variable_set.insert(symbol->getSymbol() + "\tdw\t"+ size + " dup (?)\n");
					}
				}
			}
		}

		delete (yyvsp[-2].info);
		delete (yyvsp[-1].info);
	}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 556 "1605070.y" /* yacc.c:1646  */
    {
		//fprintf(logout_er, "';' not provided after variable declaration\n\n");

		//fprintf(logout_er, "At line no: %d var_declaration : type_specifier declaration_list SEMICOLON\n", line_count);
		(yyval.info) = new SymbolInfo();
		string str = (yyvsp[-2].info)->getName() + " " + (yyvsp[-1].info)->getName() + "; // corrected\n";
		(yyval.info)->setName(str);
		//fprintf(logout_er, "\n%s\n\n", str.c_str());

		stringstream tokenize((yyvsp[-1].info)->getName());
		string temp;

		while(getline(tokenize, temp, ',')){
			int found = temp.find("[");
			if(found == -1) {
				bool got = table->lookUpCurrent(temp);
				if(got) {
					fprintf(logout, "Error at line %d : redeclaration of '%s'\n\n", line_count, temp.c_str());
					total_error++;
				} else {
					SymbolInfo* symbol = new SymbolInfo(temp, "ID");
					symbol->parameterList.push_back((yyvsp[-2].info)->getName());
					symbol->parameterList.push_back("normal");
					table->insert(symbol);
				}
			}
			else{
				int found2 = temp.find("]", found+1);
				string size = temp.substr(found+1, found2-found-1);
				string content = temp.substr(0,found);
				bool got = table->lookUpCurrent(content);
				if(got) {
					fprintf(logout, "Error at line %d : redeclaration of '%s'\n\n", line_count, content.c_str());
					total_error++;
				} else {
					SymbolInfo* symbol = new SymbolInfo(content, "ID");
					symbol->parameterList.push_back((yyvsp[-2].info)->getName());
					symbol->parameterList.push_back(size);
					symbol->parameterList.push_back("array");
					table->insert(symbol);
				}
			}
		}

		delete (yyvsp[-2].info);
		delete (yyvsp[-1].info);

	}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 607 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d type_specifier : INT\n", line_count);
	(yyval.info) = new SymbolInfo();
	(yyval.info)->setName("int");
	//fprintf(logout_er, "\nint\n\n");
}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 613 "1605070.y" /* yacc.c:1646  */
    {
			 //fprintf(logout_er, "At line no: %d type_specifier	: FLOAT\n", line_count);
			 (yyval.info) = new SymbolInfo();
			 (yyval.info)->setName("float");
			 //fprintf(logout_er, "\nfloat\n\n");
		 }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 619 "1605070.y" /* yacc.c:1646  */
    {
			 //fprintf(logout_er, "At line no: %d type_specifier : VOID\n", line_count);
			 (yyval.info) = new SymbolInfo();
			 (yyval.info)->setName("void");
			 //fprintf(logout_er, "\nvoid\n\n");
		 }
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 625 "1605070.y" /* yacc.c:1646  */
    {
			//fprintf(logout_er, "At line no: %d type_specifier : CHAR\n", line_count);
			(yyval.info) = new SymbolInfo();
			(yyval.info)->setName("char");
			//fprintf(logout_er, "\nchar\n\n");
		}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 633 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d declaration_list : declaration_list COMMA ID\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[-2].info)->getName() + "," + (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	delete (yyvsp[-2].info);
	delete (yyvsp[0].info);
}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 643 "1605070.y" /* yacc.c:1646  */
    {
			   //fprintf(logout_er, "At line no: %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n", line_count);
			   (yyval.info) = new SymbolInfo();
			   string str = (yyvsp[-5].info)->getName() + "," + (yyvsp[-3].info)->getName() + "[" + (yyvsp[-1].info)->getName() + "]";
			   (yyval.info)->setName(str);
			   //fprintf(logout_er, "\n%s\n\n", str.c_str());

			   delete (yyvsp[-5].info);
			   delete (yyvsp[-3].info);
			   delete (yyvsp[-1].info);
		   }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 654 "1605070.y" /* yacc.c:1646  */
    {
			   //fprintf(logout_er, "At line no: %d declaration_list : ID\n", line_count);
			   (yyval.info) = new SymbolInfo();
			   string str = (yyvsp[0].info)->getName();
			   (yyval.info)->setName(str);
			   //fprintf(logout_er, "\n%s\n\n", str.c_str());
			   delete (yyvsp[0].info);

		   }
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 663 "1605070.y" /* yacc.c:1646  */
    {
			   //fprintf(logout_er, "At line no: %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n", line_count);
			   (yyval.info) = new SymbolInfo();
			   string str = (yyvsp[-3].info)->getName() + "[" + (yyvsp[-1].info)->getName() + "]";
			   (yyval.info)->setName(str);
			   //fprintf(logout_er, "\n%s\n\n", str.c_str());

			   delete (yyvsp[-3].info);
			   delete (yyvsp[-1].info);
		   }
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 675 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d statements : statement\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	(yyval.info)->code = (yyvsp[0].info)->code;

	delete (yyvsp[0].info);
}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 686 "1605070.y" /* yacc.c:1646  */
    {
		   //fprintf(logout_er, "At line no: %d statements : statements statement\n", line_count);
		   (yyval.info) = new SymbolInfo();
		   string str = (yyvsp[-1].info)->getName()+ (yyvsp[0].info)->getName();
		   (yyval.info)->setName(str);
		   //fprintf(logout_er, "\n%s\n\n", str.c_str());

		   (yyval.info)->code = (yyvsp[-1].info)->code + (yyvsp[0].info)->code;

		   delete (yyvsp[-1].info);
		   delete (yyvsp[0].info);
	   }
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 701 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d statement : var_declaration\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);

	(yyval.info)->code = (yyvsp[0].info)->code;

	//fprintf(logout_er, "\n%s\n\n", str.c_str());
	delete (yyvsp[0].info);
}
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 712 "1605070.y" /* yacc.c:1646  */
    {
		  //fprintf(logout_er, "At line no: %d statement : expression_statement\n", line_count);
		  (yyval.info) = new SymbolInfo();
		  string str = (yyvsp[0].info)->getName() + "\n";
		  (yyval.info)->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  (yyval.info)->code = (yyvsp[0].info)->code;

		  delete (yyvsp[0].info);
	  }
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 723 "1605070.y" /* yacc.c:1646  */
    {
		  //fprintf(logout_er, "At line no: %d statement : compound_statement\n", line_count);
		  (yyval.info) = new SymbolInfo();
		  string str = (yyvsp[0].info)->getName();
		  (yyval.info)->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  (yyval.info)->code = (yyvsp[0].info)->code;

		  delete (yyvsp[0].info);
	  }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 734 "1605070.y" /* yacc.c:1646  */
    {
		  //fprintf(logout_er, "At line no: %d statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n", line_count);
		  (yyval.info) = new SymbolInfo();
		  string str = "for(" + (yyvsp[-4].info)->getName() + (yyvsp[-3].info)->getName() + (yyvsp[-2].info)->getName() +") " + (yyvsp[0].info)->getName();
		  (yyval.info)->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  (yyval.info)->code = (yyvsp[-4].info)->code;
		  string label1 = newLabel();
		  string label2 = newLabel();
		  (yyval.info)->code += label1 + ":\n";
		  (yyval.info)->code += (yyvsp[-3].info)->code;
		  (yyval.info)->code += "mov ax, "+(yyvsp[-3].info)->getSymbol()+"\n";
		  (yyval.info)->code += "cmp ax, 0\n";
		  (yyval.info)->code += "jz "+label2+"\n";
		  (yyval.info)->code += (yyvsp[0].info)->code + (yyvsp[-2].info)->code + "jmp "+label1+"\n";
		  (yyval.info)->code += label2+":\n";

		  delete (yyvsp[-4].info);
		  delete (yyvsp[-3].info);
		  delete (yyvsp[-2].info);
		  delete (yyvsp[0].info);
	  }
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 757 "1605070.y" /* yacc.c:1646  */
    {
		  //fprintf(logout_er, "At line no: %d statement : IF LPAREN expression RPAREN statement\n", line_count);
		  (yyval.info) = new SymbolInfo();
		  string str = "if(" + (yyvsp[-2].info)->getName() + ") " + (yyvsp[0].info)->getName();
		  (yyval.info)->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  (yyval.info)->code = (yyvsp[-2].info)->code;
		  string label1 = newLabel();
		  (yyval.info)->code += "mov ax, "+(yyvsp[-2].info)->getSymbol()+"\n";
		  (yyval.info)->code += "cmp ax, 0\n";
		  (yyval.info)->code += "je "+label1+"\n";
		  (yyval.info)->code += (yyvsp[0].info)->code + label1+":\n";

		  delete (yyvsp[-2].info);
		  delete (yyvsp[0].info);
	  }
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 774 "1605070.y" /* yacc.c:1646  */
    {
		  //fprintf(logout_er, "At line no: %d statement : IF LPAREN expression RPAREN statement ELSE statement\n", line_count);
		  (yyval.info) = new SymbolInfo();
		  string str = "if(" + (yyvsp[-4].info)->getName() + ") " + (yyvsp[-2].info)->getName() + "else " + (yyvsp[0].info)->getName();
		  (yyval.info)->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  (yyval.info)->code = (yyvsp[-4].info)->code;
		  string label1 = newLabel();
		  (yyval.info)->code += "mov ax, "+(yyvsp[-4].info)->getSymbol()+"\n";
		  (yyval.info)->code += "cmp ax, 0\n";
		  (yyval.info)->code += "je "+label1+"\n";
		  (yyval.info)->code += (yyvsp[-2].info)->code + label1+":\n";
		  (yyval.info)->code += (yyvsp[0].info)->code;

		  delete (yyvsp[-4].info);
		  delete (yyvsp[-2].info);
		  delete (yyvsp[0].info);
	  }
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 793 "1605070.y" /* yacc.c:1646  */
    {
		  //fprintf(logout_er, "At line no: %d statement : WHILE LPAREN expression RPAREN statement\n", line_count);
		  (yyval.info) = new SymbolInfo();
		  string str = "while(" + (yyvsp[-2].info)->getName() + ") " + (yyvsp[0].info)->getName();
		  (yyval.info)->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  string label1 = newLabel();
		  string label2 = newLabel();
		  (yyval.info)->code += label1 + ":\n"+(yyvsp[-2].info)->code;
		  (yyval.info)->code += "mov ax, "+(yyvsp[-2].info)->getSymbol()+"\n";
		  (yyval.info)->code += "cmp ax, 0\n";
		  (yyval.info)->code += "jz "+label2+"\n";
		  (yyval.info)->code += (yyvsp[0].info)->code + "jmp "+label1+"\n";
		  (yyval.info)->code += label2+":\n";

		  delete (yyvsp[-2].info);
		  delete (yyvsp[0].info);
	  }
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 812 "1605070.y" /* yacc.c:1646  */
    {
		  //fprintf(logout_er, "At line no: %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n", line_count);
		  (yyval.info) = new SymbolInfo();
		  string str = "println(" + (yyvsp[-2].info)->getName() + ")" +";\n";
		  (yyval.info)->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  SymbolInfo* symbol = table->lookUp((yyvsp[-2].info)->getName());
		  if(symbol && symbol->getType() == "ID"){
		  	(yyval.info)->code += "mov ax, "+symbol->getSymbol()+"\ncall println\n";
		  } else{
			  fprintf(logout, "Error at line %d : not declared '%s'\n\n", line_count, (yyvsp[-2].info)->getName().c_str());
		  }

		  delete (yyvsp[-2].info);
	  }
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 828 "1605070.y" /* yacc.c:1646  */
    {
		  //fprintf(logout_er, "';' not provided\n\n");
		  //fprintf(logout_er, "At line no: %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n", line_count);
		  (yyval.info) = new SymbolInfo();
		  string str = "println(" + (yyvsp[-2].info)->getName() + ")" +"; // corrected\n";
		  (yyval.info)->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  delete (yyvsp[-2].info);
	  }
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 838 "1605070.y" /* yacc.c:1646  */
    {
		  //fprintf(logout_er, "At line no: %d statement : RETURN expression SEMICOLON\n", line_count);
		  (yyval.info) = new SymbolInfo();
		  string str = "return " + (yyvsp[-1].info)->getName() + ";\n";
		  if(functionReturnType != (yyvsp[-1].info)->getType() && (yyvsp[-1].info)->getType() != "error"){
			  fprintf(logout, "Error at line %d : function return type not matched(have '%s' and '%s')\n\n", line_count, functionReturnType.c_str(), (yyvsp[-1].info)->getType().c_str());
		  }
		  hasReturnType = true;
		  (yyval.info)->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());

		  (yyval.info)->code += (yyvsp[-1].info)->code;
		  (yyval.info)->code += "mov ax, "+(yyvsp[-1].info)->getSymbol()+"\nret\n";

		  delete (yyvsp[-1].info);
	  }
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 854 "1605070.y" /* yacc.c:1646  */
    {
		  //fprintf(logout_er, "';' not provided\n\n");
		  //fprintf(logout_er, "At line no: %d statement : RETURN expression SEMICOLON\n", line_count);
		  (yyval.info) = new SymbolInfo();
		  string str = "return " + (yyvsp[-1].info)->getName() + "; // corrected\n";
		  (yyval.info)->setName(str);
		  //fprintf(logout_er, "\n%s\n\n", str.c_str());
		  delete (yyvsp[-1].info);
	  }
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 865 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d expression_statement : SEMICOLON\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = ";";
	(yyval.info)->setName(str);
	//fprintf(logout_er, "\n%s\n\n", str.c_str());
}
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 872 "1605070.y" /* yacc.c:1646  */
    {
				//fprintf(logout_er, "At line no: %d expression_statement : expression SEMICOLON\n", line_count);
				(yyval.info) = new SymbolInfo();
		  		string str = (yyvsp[-1].info)->getName() + ";";
		  		(yyval.info)->setName(str);
		  		//fprintf(logout_er, "\n%s\n\n", str.c_str());

				(yyval.info)->code = (yyvsp[-1].info)->code;
				(yyval.info)->setSymbol((yyvsp[-1].info)->getSymbol());

				delete (yyvsp[-1].info);
			}
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 886 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d variable : ID\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	SymbolInfo* symbol = table->lookUp((yyvsp[0].info)->getName());
	if(symbol){
		if(symbol->parameterList[symbol->parameterList.size()-1] == "normal") {
			(yyval.info)->setType(symbol->parameterList[0]);
		}
		else{
			(yyval.info)->setType("error");
			fprintf(logout, "Error at line %d : lvalue required\n\n", line_count);
			total_error++;
		}
	} else{
		(yyval.info)->setType("error");
		total_error++;
		fprintf(logout, "Error at line %d : '%s' undeclared\n\n", line_count, (yyvsp[0].info)->getName().c_str());
	}
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	(yyval.info)->setCategory("notarray");
	(yyval.info)->setSymbol(symbol->getSymbol());

	delete (yyvsp[0].info);
}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 913 "1605070.y" /* yacc.c:1646  */
    {
		 //fprintf(logout_er, "At line no: %d variable : ID LTHIRD expression RTHIRD\n", line_count);
		 (yyval.info) = new SymbolInfo();
		 string str = (yyvsp[-3].info)->getName() + "[" + (yyvsp[-1].info)->getName() + "]";
		 (yyval.info)->setName(str);
		 //fprintf(logout_er, "\n%s\n\n", str.c_str());
		 if((yyvsp[-1].info)->getType() != "int") {
			 (yyval.info)->setType("error");
			 fprintf(logout, "Error at line %d : array subscript is not an integer (have '%s')\n\n", line_count, (yyvsp[-1].info)->getType().c_str());
			 total_error++;
		 } else {
			SymbolInfo* symbol = table->lookUp((yyvsp[-3].info)->getName());
			if(symbol){
				if(symbol->parameterList[symbol->parameterList.size()-1] == "array") {
					(yyval.info)->setType(symbol->parameterList[0]);
					string size = symbol->parameterList[1];
					if(stoi((yyvsp[-1].info)->getName()) >= stoi(size)){
						fprintf(logout, "Error at line %d : Array index out of bound (array size '%s', used index '%s')\n\n", line_count, size.c_str(), (yyvsp[-1].info)->getName().c_str());
						total_error++;
					}

					(yyval.info)->setCategory("array");
		 			(yyval.info)->setSymbol(symbol->getSymbol());
		 			(yyval.info)->code += (yyvsp[-1].info)->code + "mov bx, "+(yyvsp[-1].info)->getSymbol()+"\nsll bx, 2\n";
				}
				else{
					(yyval.info)->setType("error");
					fprintf(logout, "Error at line %d : subscripted value is not array\n\n", line_count);
					total_error++;
				}
			}   else{
					(yyval.info)->setType("error");
					fprintf(logout, "Error at line %d : undeclared\n\n", line_count);
					total_error++;
			}
		 }

		 delete (yyvsp[-3].info);
		 delete (yyvsp[-1].info);
	 }
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 955 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d expression : logic_expression\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	(yyval.info)->setType((yyvsp[0].info)->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	(yyval.info)->code += (yyvsp[0].info)->code;
	(yyval.info)->setSymbol((yyvsp[0].info)->getSymbol());

	delete (yyvsp[0].info);
}
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 968 "1605070.y" /* yacc.c:1646  */
    {
		   //fprintf(logout_er, "At line no: %d expression : variable ASSIGNOP logic_expression\n", line_count);
		   (yyval.info) = new SymbolInfo();
		   string str = (yyvsp[-2].info)->getName() + " = " + (yyvsp[0].info)->getName();
		   (yyval.info)->setName(str);
		   (yyval.info)->setType((yyvsp[-2].info)->getType());

		   if((yyvsp[-2].info)->getType() != (yyvsp[0].info)->getType()) {
			   if((yyvsp[0].info)->getType() == "void") {
					fprintf(logout, "Error at line %d : 'void' type cannot be assigned\n\n", line_count);
					total_error++;
			   } else if((yyvsp[0].info)->getType() != "error" && (yyvsp[-2].info)->getType() != "error") {
			   		fprintf(logout, "Error at line %d : operands types mismatch (have '%s' and '%s' )\n\n", line_count, (yyvsp[-2].info)->getType().c_str(), (yyvsp[0].info)->getType().c_str());
					total_error++;
			   }
			   (yyval.info)->setType("error");
		   }

		   //fprintf(logout_er, "\n%s\n\n", str.c_str());

		   (yyval.info)->code = (yyvsp[0].info)->code + (yyvsp[-2].info)->code;
		   (yyval.info)->setSymbol((yyvsp[0].info)->getSymbol());
		   (yyval.info)->code += "mov ax, "+(yyvsp[0].info)->getSymbol()+"\n";
		   if((yyvsp[-2].info)->getCategory() == "notarray"){
			   (yyval.info)->code += "mov "+(yyvsp[-2].info)->getSymbol()+", ax\n";
		   } else {
			   (yyval.info)->code  += "mov "+(yyvsp[-2].info)->getSymbol()+"[bx], ax\n";
		   }

		   delete (yyvsp[-2].info);
		   delete (yyvsp[0].info);
	   }
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1002 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d logic_expression : rel_expression\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	(yyval.info)->setType((yyvsp[0].info)->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	(yyval.info)->code += (yyvsp[0].info)->code;
	(yyval.info)->setSymbol((yyvsp[0].info)->getSymbol());

	delete (yyvsp[0].info);
}
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1015 "1605070.y" /* yacc.c:1646  */
    {
			 //fprintf(logout_er, "At line no: %d logic_expression : rel_expression LOGICOP rel_expression\n", line_count);
			 (yyval.info) = new SymbolInfo();
		  	 string str = (yyvsp[-2].info)->getName() + " " + (yyvsp[-1].info)->getName() + " " + (yyvsp[0].info)->getName();
		  	 (yyval.info)->setName(str);
			 (yyval.info)->setType("int");
		  	 //fprintf(logout_er, "\n%s\n\n", str.c_str());

			 (yyval.info)->code += (yyvsp[-2].info)->code + (yyvsp[0].info)->code;
			 (yyval.info)->code += "mov ax, "+(yyvsp[-2].info)->getSymbol()+"\n";
			(yyval.info)->code += "cmp ax, 0\n";
			string tempVar = newTempVar();
			tempVar_set.push_back(tempVar);
			string label1 = newLabel();
			string label2 = newLabel();
			variable_defined += tempVar + "\tdw\t'?'\n";
			variable_set.insert(tempVar + "\tdw\t'?'\n");

			 if((yyvsp[-1].info)->getName() == "&&"){
				 (yyval.info)->code += "jz "+label1+"\n";
				 (yyval.info)->code += "mov ax, "+(yyvsp[0].info)->getSymbol()+"\n";
				 (yyval.info)->code += "cmp ax, 0\n";
				 (yyval.info)->code += "jz "+label1+"\n";
				 (yyval.info)->code += "mov "+tempVar+", 1\njmp "+label2+"\n";
				 (yyval.info)->code += label1+":\n"+"mov "+tempVar+", 0\n";
				 (yyval.info)->code += label2+":\n";
			 } else{
				 (yyval.info)->code += "jnz "+label1+"\n";
				 (yyval.info)->code += "mov ax, "+(yyvsp[0].info)->getSymbol()+"\n";
				 (yyval.info)->code += "cmp ax, 0\n";
				 (yyval.info)->code += "jnz "+label1+"\n";
				 (yyval.info)->code += "mov "+tempVar+", 0\njmp "+label2+"\n";
				 (yyval.info)->code += label1+":\n"+"mov "+tempVar+", 1\n";
				 (yyval.info)->code += label2+":\n";
			 }
			 (yyval.info)->setSymbol(tempVar);

			 delete (yyvsp[-2].info);
			 delete (yyvsp[-1].info);
			 delete (yyvsp[0].info);
		 }
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1058 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d rel_expression	: simple_expression\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	(yyval.info)->setType((yyvsp[0].info)->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	(yyval.info)->code += (yyvsp[0].info)->code;
	(yyval.info)->setSymbol((yyvsp[0].info)->getSymbol());

	delete (yyvsp[0].info);
}
#line 2629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1071 "1605070.y" /* yacc.c:1646  */
    {
			//fprintf(logout_er, "At line no: %d rel_expression	: simple_expression RELOP simple_expression\n", line_count);
			(yyval.info) = new SymbolInfo();
		  	string str = (yyvsp[-2].info)->getName() + " " + (yyvsp[-1].info)->getName() + " " + (yyvsp[0].info)->getName();
		  	(yyval.info)->setName(str);
			(yyval.info)->setType("int");
		  	//fprintf(logout_er, "\n%s\n\n", str.c_str());

			(yyval.info)->code += (yyvsp[-2].info)->code + (yyvsp[0].info)->code;
			(yyval.info)->code += "mov ax, " + (yyvsp[-2].info)->getSymbol()+"\n";
			(yyval.info)->code += "cmp ax, " + (yyvsp[0].info)->getSymbol()+"\n";

			string tempVar = newTempVar();
			tempVar_set.push_back(tempVar);
			variable_defined += tempVar + "\tdw\t'?'\n";
			variable_set.insert(tempVar + "\tdw\t'?'\n");

			string label1 = newLabel();
			string label2 = newLabel();

			if((yyvsp[-1].info)->getName() == "<"){
				(yyval.info)->code += "jl " + label1 + "\n";

			} else if((yyvsp[-1].info)->getName() == "<="){
				(yyval.info)->code += "jle " + label1 + "\n";
			} else if((yyvsp[-1].info)->getName() == ">"){
				(yyval.info)->code += "jg " + label1 + "\n";
			} else if((yyvsp[-1].info)->getName() == ">="){
				(yyval.info)->code += "jge " + label1 + "\n";
			} else if((yyvsp[-1].info)->getName() == "=="){
				(yyval.info)->code += "je " + label1 + "\n";
			} else if((yyvsp[-1].info)->getName() == "!="){
				(yyval.info)->code += "jne " + label1 + "\n";
			}
			(yyval.info)->code += "mov "+tempVar+", 0\n";
			(yyval.info)->code += "jmp "+label2+"\n";
			(yyval.info)->code += label1+":\nmov "+tempVar+", 1\n";
			(yyval.info)->code += label2+":\n";
			(yyval.info)->setSymbol(tempVar);

			delete (yyvsp[-2].info);
			delete (yyvsp[-1].info);
			delete (yyvsp[0].info);
		}
#line 2678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1117 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d simple_expression : term\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	(yyval.info)->setType((yyvsp[0].info)->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	(yyval.info)->code += (yyvsp[0].info)->code;
	(yyval.info)->setSymbol((yyvsp[0].info)->getSymbol());

	delete (yyvsp[0].info);
}
#line 2696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1130 "1605070.y" /* yacc.c:1646  */
    {
			  //fprintf(logout_er, "At line no: %d simple_expression : simple_expression ADDOP term\n", line_count);
			  (yyval.info) = new SymbolInfo();
		  	  string str = (yyvsp[-2].info)->getName() + " " + (yyvsp[-1].info)->getName() + " " + (yyvsp[0].info)->getName();
		  	  (yyval.info)->setName(str);

			  if((yyvsp[-2].info)->getType() == "float" || (yyvsp[-1].info)->getType() == "float")	(yyval.info)->setType("float");
			  else (yyval.info)->setType("int");

		  	  //fprintf(logout_er, "\n%s\n\n", str.c_str());

			  (yyval.info)->code += (yyvsp[-2].info)->code + (yyvsp[0].info)->code;
			  (yyval.info)->code += "mov ax, "+(yyvsp[-2].info)->getSymbol()+"\n";
			  string tempVar = newTempVar();
			  tempVar_set.push_back(tempVar);
			  variable_defined += tempVar + "\tdw\t'?'\n";
			  variable_set.insert(tempVar + "\tdw\t'?'\n");

			  if((yyvsp[-1].info)->getName() == "+"){
				  (yyval.info)->code += "add ax, "+(yyvsp[0].info)->getSymbol()+"\n";
			  } else {
				  (yyval.info)->code += "sub ax, "+(yyvsp[0].info)->getSymbol()+"\n";
			  }
			  (yyval.info)->code += "mov "+tempVar + ", ax\n";
			  (yyval.info)->setSymbol(tempVar);

			  delete (yyvsp[-2].info);
			  delete (yyvsp[-1].info);
			  delete (yyvsp[0].info);
		  }
#line 2731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1162 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d term : unary_expression\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	(yyval.info)->setType((yyvsp[0].info)->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	(yyval.info)->code += (yyvsp[0].info)->code;
	(yyval.info)->setSymbol((yyvsp[0].info)->getSymbol());

	delete (yyvsp[0].info);
}
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1175 "1605070.y" /* yacc.c:1646  */
    {
		 //fprintf(logout_er, "At line no: %d term : term MULOP unary_expression\n", line_count);
		 (yyval.info) = new SymbolInfo();
		 string str = (yyvsp[-2].info)->getName() + (yyvsp[-1].info)->getName() + (yyvsp[0].info)->getName();
		 (yyval.info)->setName(str);

		 if((yyvsp[-2].info)->getType() == "float" || (yyvsp[0].info)->getType() == "float")	(yyval.info)->setType("float");
		 else (yyval.info)->setType("int");

		 if((yyvsp[-1].info)->getName() == "%" && ((yyvsp[-2].info)->getType() == "float" || (yyvsp[0].info)->getType() == "float")) {
			(yyval.info)->setType("error");
			fprintf(logout, "Error at line %d : invalid operands to binary % (have '%s' and '%s')\n\n", line_count, (yyvsp[-2].info)->getType().c_str(), (yyvsp[0].info)->getType().c_str());
			total_error++;
		 }

		 //fprintf(logout_er, "\n%s\n\n", str.c_str());

		 (yyval.info)->code = (yyvsp[-2].info)->code + (yyvsp[0].info)->code;
		 (yyval.info)->code += "mov ax, "+(yyvsp[-2].info)->getSymbol()+"\n";
		 (yyval.info)->code += "mov bx, "+(yyvsp[0].info)->getSymbol()+"\n";
		 string tempVar = newTempVar();
		 tempVar_set.push_back(tempVar);
		 variable_defined += tempVar + "\tdw\t'?'\n";
		 variable_set.insert(tempVar + "\tdw\t'?'\n");
		 if((yyvsp[-1].info)->getName() == "*"){
			 (yyval.info)->code += "imul bx\n";
			 (yyval.info)->code += "mov "+tempVar+", ax\n";
		 } else if((yyvsp[-1].info)->getName() == "/"){
			 //  $$->code += "xor dx, dx\n";
			 (yyval.info)->code += "cwd\n";
			 (yyval.info)->code += "idiv bx\nmov "+tempVar+", ax\n";
		 } else{
			//  $$->code += "xor dx, dx\n";
			 (yyval.info)->code += "cwd\n";
			 (yyval.info)->code += "idiv bx\nmov "+tempVar+", dx\n";
		 }
		 (yyval.info)->setSymbol(tempVar);

		 delete (yyvsp[-2].info);
		 delete (yyvsp[-1].info);
		 delete (yyvsp[0].info);
	 }
#line 2796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1219 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d unary_expression : ADDOP unary_expression\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[-1].info)->getName() + (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	(yyval.info)->setType((yyvsp[0].info)->getType());

	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	(yyval.info)->code += (yyvsp[0].info)->code;
	string tempVar = newTempVar();
	tempVar_set.push_back(tempVar);
	variable_defined += tempVar + "\tdw\t'?'\n";
	variable_set.insert(tempVar + "\tdw\t'?'\n");
	(yyval.info)->code += "mov ax, "+(yyvsp[0].info)->getSymbol()+"\n";
	(yyval.info)->code += "mov "+tempVar+", ax\n";

	if((yyvsp[-1].info)->getName() == "-"){
		(yyval.info)->code += "neg "+tempVar+"\n";
	}
	(yyval.info)->setSymbol(tempVar);

	delete (yyvsp[-1].info);
	delete (yyvsp[0].info);
}
#line 2826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1244 "1605070.y" /* yacc.c:1646  */
    {
			 //fprintf(logout_er, "At line no: %d unary_expression : NOT unary_expression\n", line_count);
			 (yyval.info) = new SymbolInfo();
		  	 string str = "!" + (yyvsp[0].info)->getName();
		  	 (yyval.info)->setName(str);
			 (yyval.info)->setType("int");
		  	 //fprintf(logout_er, "\n%s\n\n", str.c_str());

			 (yyval.info)->code += (yyvsp[0].info)->code;
			 string tempVar = newTempVar();
			 tempVar_set.push_back(tempVar);
			 (yyval.info)->code += "mov ax, "+(yyvsp[0].info)->getSymbol()+"\n";
			 (yyval.info)->code += "not ax\nmov "+tempVar+", ax\n";
			 (yyval.info)->setSymbol(tempVar);

			 delete (yyvsp[0].info);
		 }
#line 2848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1261 "1605070.y" /* yacc.c:1646  */
    {
			 //fprintf(logout_er, "At line no: %d unary_expression : factor\n", line_count);
			 (yyval.info) = new SymbolInfo();
		  	 string str = (yyvsp[0].info)->getName();
		  	 (yyval.info)->setName(str);
			 (yyval.info)->setType((yyvsp[0].info)->getType());
		  	 //fprintf(logout_er, "\n%s\n\n", str.c_str());

			 (yyval.info)->code = (yyvsp[0].info)->code;
			 (yyval.info)->setSymbol((yyvsp[0].info)->getSymbol());

			 delete (yyvsp[0].info);
		 }
#line 2866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1276 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d factor : variable\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	(yyval.info)->setType((yyvsp[0].info)->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	(yyval.info)->code = (yyvsp[0].info)->code;
	(yyval.info)->setSymbol((yyvsp[0].info)->getSymbol());

	if((yyvsp[0].info)->getCategory() == "notarray"){

	} else{
		string tempVar = newTempVar();
		tempVar_set.push_back(tempVar);
		variable_defined += tempVar + "\tdw\t'?'\n";
		variable_set.insert(tempVar + "\tdw\t'?'\n");
		// fprintf(codeout, "%s\tdw\t'?'\n",tempVar.c_str());
		(yyval.info)->code +="mov ax, "+(yyvsp[0].info)->getSymbol()+"[bx]\n";
		(yyval.info)->code += "mov "+tempVar+", ax\n";
		(yyval.info)->setSymbol(tempVar);

	}

	delete (yyvsp[0].info);
}
#line 2898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1303 "1605070.y" /* yacc.c:1646  */
    {totalArguments = 0;}
#line 2904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1303 "1605070.y" /* yacc.c:1646  */
    {
		//fprintf(logout_er, "At line no: %d factor : ID LPAREN argument_list RPAREN\n", line_count);
		(yyval.info) = new SymbolInfo();
		string str = (yyvsp[-4].info)->getName() + "(" + (yyvsp[-1].info)->getName() + ")";
		(yyval.info)->setName(str);
		SymbolInfo* symbol = table->lookUp((yyvsp[-4].info)->getName());
		int t_args = 0;
		if(symbol){
			if(symbol->parameterList[symbol->parameterList.size() -1] == "function"){
				bool matched = true;
				for(int i = 0; i < (yyvsp[-1].info)->parameterList.size(); i++){
					if((yyvsp[-1].info)->parameterList[i] != symbol->parameterList[i+1]) matched = false;
				}
				if(matched == false) {
					fprintf(logout , "Error at line %d : function arguments types not matched\n\n", line_count);
					(yyval.info)->setType("error");
					total_error++;
				} else {
					(yyval.info)->setType(symbol->parameterList[0]);
					t_args = (yyvsp[-1].info)->parameterList.size();
				}
			}
			else{
				(yyval.info)->setType("error");
				fprintf(logout, "Error at line %d : '%s' is not a function\n\n", line_count, (yyvsp[-4].info)->getName().c_str());
				total_error++;
			}
		} else{
			(yyval.info)->setType("error");
			fprintf(logout, "Error at line %d : function '%s' not declared\n\n", line_count, (yyvsp[-4].info)->getName().c_str());
			total_error++;
		}

		//fprintf(logout_er, "\n%s\n\n", str.c_str());

		(yyval.info)->code += (yyvsp[-1].info)->code;
		string tempVar = newTempVar();
		tempVar_set.push_back(tempVar);
		variable_defined += tempVar + "\tdw\t'?'\n";
		variable_set.insert(tempVar + "\tdw\t'?'\n");

		if(current_function_name != "main" && current_function_name == (yyvsp[-4].info)->getName()){
			for(string var : tempVar_set){
				(yyval.info)->code += "push "+var+"\n";
			}
		}
		// if(current_function_name != "main"){
		// 	for(int i = 1; i <= t_args; i++){
		// 		$$->code += "push f"+to_string(i)+"\n";
		// 	}
		// }
		(yyval.info)->code += "call "+(yyvsp[-4].info)->getName()+"\n";

		if(current_function_name != "main" && current_function_name == (yyvsp[-4].info)->getName()){
			for(int i = tempVar_set.size()-1; i >=0; i--){
				string var = tempVar_set[i];
				(yyval.info)->code += "pop "+var+"\n";
			}
		}

		for(int i = t_args; i >=1 ; i--){
			(yyval.info)->code += "pop f"+to_string(i)+"\n";
		}
		
		(yyval.info)->code += "mov "+tempVar+", ax\n";
		(yyval.info)->setSymbol(tempVar);
		totalArguments = 0;

		delete (yyvsp[-4].info);
		delete (yyvsp[-1].info);
	}
#line 2980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1374 "1605070.y" /* yacc.c:1646  */
    {
		//fprintf(logout_er, "At line no: %d factor : LPAREN expression RPAREN\n", line_count);
		(yyval.info) = new SymbolInfo();
		string str = "(" + (yyvsp[-1].info)->getName() + ")";
		(yyval.info)->setName(str);
		(yyval.info)->setType((yyvsp[-1].info)->getType());
		//fprintf(logout_er, "\n%s\n\n", str.c_str());

		(yyval.info)->code += (yyvsp[-1].info)->code;
		(yyval.info)->setSymbol((yyvsp[-1].info)->getSymbol());

		delete (yyvsp[-1].info);
	}
#line 2998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1387 "1605070.y" /* yacc.c:1646  */
    {
		//fprintf(logout_er, "At line no: %d factor : CONST_INT\n", line_count);
		(yyval.info) = new SymbolInfo();
		string str = (yyvsp[0].info)->getName();
		(yyval.info)->setName(str);
		(yyval.info)->setType("int");
		//fprintf(logout_er, "\n%s\n\n", str.c_str());

		string tempVar = newTempVar();
		tempVar_set.push_back(tempVar);
		variable_defined += tempVar + "\tdw\t'?'\n";
		variable_set.insert(tempVar + "\tdw\t'?'\n");
		(yyval.info)->code += "mov ax, "+(yyvsp[0].info)->getName()+"\n";
		(yyval.info)->code += "mov " +tempVar+ ", ax\n";
		(yyval.info)->setSymbol(tempVar);

		delete (yyvsp[0].info);
	}
#line 3021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1405 "1605070.y" /* yacc.c:1646  */
    {
		//fprintf(logout_er, "At line no: %d factor : CONST_FLOAT\n", line_count);
		(yyval.info) = new SymbolInfo();
		string str = (yyvsp[0].info)->getName();
		(yyval.info)->setName(str);
		(yyval.info)->setType("float");
		//fprintf(logout_er, "\n%s\n\n", str.c_str());
		delete (yyvsp[0].info);
	}
#line 3035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1414 "1605070.y" /* yacc.c:1646  */
    {
		//fprintf(logout_er, "At line no: %d factor : variable INCOP\n", line_count);
		(yyval.info) = new SymbolInfo();
		string str = (yyvsp[-1].info)->getName() + "++";
		(yyval.info)->setName(str);
		(yyval.info)->setType((yyvsp[-1].info)->getType());
		//fprintf(logout_er, "\n%s\n\n", str.c_str());

		(yyval.info)->code = (yyvsp[-1].info)->code;
		(yyval.info)->setSymbol((yyvsp[-1].info)->getSymbol());

		if((yyvsp[-1].info)->getCategory() == "notarray"){
			(yyval.info)->code += "inc "+(yyvsp[-1].info)->getSymbol()+"\n";
		} else{
			(yyval.info)->code +="inc "+(yyvsp[-1].info)->getSymbol()+"[bx]\n";
		}

		delete (yyvsp[-1].info);
	}
#line 3059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1433 "1605070.y" /* yacc.c:1646  */
    {
		//fprintf(logout_er, "At line no: %d factor : variable DECOP\n", line_count);
		(yyval.info) = new SymbolInfo();
		string str = (yyvsp[-1].info)->getName() + "--";
		(yyval.info)->setName(str);
		(yyval.info)->setType((yyvsp[-1].info)->getType());
		//fprintf(logout_er, "\n%s\n\n", str.c_str());

		(yyval.info)->code = (yyvsp[-1].info)->code;
		(yyval.info)->setSymbol((yyvsp[-1].info)->getSymbol());

		if((yyvsp[-1].info)->getCategory() == "notarray"){
			(yyval.info)->code += "dec "+(yyvsp[-1].info)->getSymbol()+"\n";
		} else{
			(yyval.info)->code +="dec "+(yyvsp[-1].info)->getSymbol()+"[bx]\n";
		}

		delete (yyvsp[-1].info);
	}
#line 3083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1454 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d argument_list : arguments\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	(yyval.info)->parameterList.insert((yyval.info)->parameterList.end(), (yyvsp[0].info)->parameterList.begin(), (yyvsp[0].info)->parameterList.end());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	(yyval.info)->code = (yyvsp[0].info)->code;
	(yyval.info)->setSymbol((yyvsp[0].info)->getSymbol());

	delete (yyvsp[0].info);
}
#line 3101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1467 "1605070.y" /* yacc.c:1646  */
    {
				  //fprintf(logout_er, "At line no: %d argument_list : \n", line_count);
				  (yyval.info) = new SymbolInfo();
				  string str = "";
				  (yyval.info)->setName(str);
				  //fprintf(logout_er, "\n%s\n\n", str.c_str());
			  }
#line 3113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1476 "1605070.y" /* yacc.c:1646  */
    {
	//fprintf(logout_er, "At line no: %d arguments : arguments COMMA logic_expression\n", line_count);
	(yyval.info) = new SymbolInfo();
	string str = (yyvsp[-2].info)->getName() + ", " + (yyvsp[0].info)->getName();
	(yyval.info)->setName(str);
	(yyval.info)->parameterList.insert((yyval.info)->parameterList.end(), (yyvsp[-2].info)->parameterList.begin(), (yyvsp[-2].info)->parameterList.end());
	(yyval.info)->parameterList.push_back((yyvsp[0].info)->getType());
	//fprintf(logout_er, "\n%s\n\n", str.c_str());

	(yyval.info)->code += (yyvsp[-2].info)->code + (yyvsp[0].info)->code;
	(yyval.info)->setSymbol((yyvsp[-2].info)->getSymbol());

	(yyval.info)->code += "mov ax, "+(yyvsp[0].info)->getSymbol()+"\n";
	string fVar = funct_call_var();
	(yyval.info)->code += "push f"+to_string(totalArguments)+"\n";
	(yyval.info)->code += "mov "+fVar+", ax\n";

	delete (yyvsp[-2].info);
	delete (yyvsp[0].info);
}
#line 3138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1496 "1605070.y" /* yacc.c:1646  */
    {
			  //fprintf(logout_er, "At line no: %d arguments : logic_expression\n", line_count);
			  (yyval.info) = new SymbolInfo();
			  string str = (yyvsp[0].info)->getName();
			  (yyval.info)->setName(str);
			  (yyval.info)->parameterList.push_back((yyvsp[0].info)->getType());
			  //fprintf(logout_er, "\n%s\n\n", str.c_str());

			  (yyval.info)->code += (yyvsp[0].info)->code;
			  (yyval.info)->setSymbol((yyvsp[0].info)->getSymbol());

			  (yyval.info)->code += "mov ax, "+(yyvsp[0].info)->getSymbol()+"\n";
			  string fVar = funct_call_var();
			  (yyval.info)->code += "push f"+to_string(totalArguments)+"\n";
			  (yyval.info)->code += "mov "+ fVar+", ax\n";

			  delete (yyvsp[0].info);
		  }
#line 3161 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3165 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1517 "1605070.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{
	FILE* fp;

	if((fp=fopen(argv[1],"r"))==NULL) {
		printf("Cannot Open Input File.\n");
		exit(1);
	}
	yyin=fp;
	yyparse();
	fprintf(logout, "Total lines: %d\n\n", line_count);
	fprintf(logout, "Total errors: %d\n", total_error);
	fclose(yyin);
	fclose(logout);
	fclose(codeout);
	fclose(fp);

	return 0;
}

bool matchFunction(vector<string> &a, vector<string> &b) {
	if(a.size() == b.size()) {
		for(int i = 0; i < a.size(); i++) {
			if(a[i] != b[i]) return false;
		}
	}
	else return false;
	return true;
}

string newLabel(){
	labelCount++;
	string ret = "Label" + to_string(labelCount);
	return ret;
}

string newTempVar(){
	tempCount++;
	string ret = "t" + to_string(tempCount);
	return ret;
}

string funct_call_var(){
	totalArguments++;
	string ret = "f" + to_string(totalArguments);
	return ret;
}

vector<string> split_token(const string& s, const string& delimeters){
	vector<string> tokens;
	char str[s.size()+1];
	char del[delimeters.size()+1];
	strcpy(str, s.c_str());
	strcpy(del, delimeters.c_str());

	for (auto i = strtok(str, del); i != NULL; i = strtok(NULL, del))
		tokens.push_back(i);
	return tokens;
}
