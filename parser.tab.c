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
#line 1 "parser.y" /* yacc.c:339  */

//----------------------------- Declaraciones -----------------------------
#include <iostream>
#include "funcionesParser.h"
using namespace std;

typedef NodeParseTree * pNodeParseTree;
int contNodos=0;
bool flagSintaxError = false;


pNodeParseTree nodo = new NodeParseTree();

std::vector<pNodeParseTree> childsToAdd;

std::vector<std::vector<pNodeParseTree>> listChildsToAdd;

void createNewNode(string pToken, string pValue, int pRow, int pColumn);
void addBlankToChilds();
void createNewListaChilds();
void addNodeToChilds();
void addChildsToNode(int offset);
void printTree(pNodeParseTree root);
void printChilds(pNodeParseTree root, int tabs);
std::vector<string> treeToPrint;

extern void addError(int pRow,int pColumn,string pError);
extern int yylex(void);
extern void printTable();
extern int yyparse();
extern FILE *yyin;
extern int yylineno;
extern int yycolumn;
extern bool flagLexicalError;

int yyerror(char *s);

#line 104 "parser.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    CLASS = 258,
    VOID = 259,
    STRING = 260,
    THIS = 261,
    WHILE = 262,
    BREAK = 263,
    READINTEGER = 264,
    INT = 265,
    EXTENDS = 266,
    IF = 267,
    NEW = 268,
    READLINE = 269,
    DOUBLE = 270,
    INTERFACE = 271,
    IMPLEMENTS = 272,
    ELSE = 273,
    NEWARRAY = 274,
    TRUE = 275,
    BOOL = 276,
    TNULL = 277,
    FOR = 278,
    RETURN = 279,
    PRINT = 280,
    FALSE = 281,
    SUM = 282,
    SUBTRACTION = 283,
    MULTIPLICATION = 284,
    DIVISION = 285,
    MODULE = 286,
    LESSTHAN = 287,
    LESSEQUALTHAN = 288,
    GREATERTHAN = 289,
    GREATEREQUALTHAN = 290,
    EQUAL = 291,
    EEQUAL = 292,
    DISTINCT = 293,
    AND = 294,
    OR = 295,
    NEGATION = 296,
    SEMICOLON = 297,
    COMMA = 298,
    DOT = 299,
    LBRACKET = 300,
    RBRACKET = 301,
    LPAREN = 302,
    RPAREN = 303,
    LBRACE = 304,
    RBRACE = 305,
    ID = 306,
    CONSINTEGERDEC = 307,
    CONSINTEGERHEX = 308,
    CONSDOUBLEDEC = 309,
    CONSDOUBLECIEN = 310,
    CONSSTRING = 311,
    CONSBOOLEAN = 312
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 61 "parser.y" /* yacc.c:355  */

    char* sval;

#line 206 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 223 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   459

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    86,    88,    90,    92,    96,    98,   101,
     105,   109,   110,   111,   112,   113,   114,   119,   125,   133,
     135,   138,   141,   144,   153,   155,   158,   161,   164,   167,
     170,   172,   174,   177,   184,   191,   198,   201,   207,   209,
     212,   214,   217,   219,   220,   221,   222,   223,   224,   225,
     228,   236,   238,   241,   248,   259,   264,   268,   276,   279,
     282,   283,   286,   289,   290,   291,   292,   293,   296,   299,
     302,   305,   308,   311,   313,   316,   319,   322,   325,   328,
     331,   334,   337,   339,   342,   345,   349,   357,   358,   361,
     367,   371,   379,   381,   384,   385,   386,   387,   388,   389,
     390
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "VOID", "STRING", "THIS",
  "WHILE", "BREAK", "READINTEGER", "INT", "EXTENDS", "IF", "NEW",
  "READLINE", "DOUBLE", "INTERFACE", "IMPLEMENTS", "ELSE", "NEWARRAY",
  "TRUE", "BOOL", "TNULL", "FOR", "RETURN", "PRINT", "FALSE", "SUM",
  "SUBTRACTION", "MULTIPLICATION", "DIVISION", "MODULE", "LESSTHAN",
  "LESSEQUALTHAN", "GREATERTHAN", "GREATEREQUALTHAN", "EQUAL", "EEQUAL",
  "DISTINCT", "AND", "OR", "NEGATION", "SEMICOLON", "COMMA", "DOT",
  "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "ID",
  "CONSINTEGERDEC", "CONSINTEGERHEX", "CONSDOUBLEDEC", "CONSDOUBLECIEN",
  "CONSSTRING", "CONSBOOLEAN", "$accept", "Program", "Decl", "OtraDecl",
  "VariableDecl", "Variable", "Type", "FunctionDecl", "Formals",
  "FormalsVars", "ClassDecl", "ExtendDecl", "ImplementsDecl", "OtroID",
  "Field", "InterfaceDecl", "Prototype", "StmtBlock", "BlockVariables",
  "BlockStmts", "Stmt", "IfStmt", "ElseStmt", "WhileStmt", "ForStmt",
  "ReturnStmt", "BreakStmt", "PrintStmt", "OtraExpr", "ExprOpcional",
  "Expr", "LValue", "Call", "Actuals", "Constant", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

#define YYPACT_NINF -177

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-177)))

#define YYTABLE_NINF -62

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-62)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     201,   -44,   -36,  -177,  -177,  -177,   -23,  -177,  -177,    48,
    -177,   421,     8,   -29,   421,   421,   421,    41,    22,    24,
    -177,   421,  -177,  -177,    45,    23,  -177,  -177,  -177,    43,
      83,   204,    25,  -177,  -177,   204,  -177,    51,    58,    65,
     -26,    61,    60,    21,    62,    69,    70,   203,   204,  -177,
    -177,    72,    76,    84,  -177,    72,    85,  -177,   203,   203,
      87,    65,     3,  -177,   204,   204,  -177,    70,  -177,  -177,
    -177,  -177,     3,    73,    98,    99,  -177,  -177,  -177,   114,
     120,   117,   119,   129,   138,   139,  -177,   141,   146,   143,
     146,   146,   146,   144,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,   134,    73,  -177,  -177,  -177,  -177,  -177,  -177,   147,
     331,   156,  -177,  -177,   152,   153,   146,  -177,   148,   146,
     159,   164,   146,   146,   173,   146,   395,   395,   199,   146,
    -177,  -177,  -177,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   169,   146,   146,    25,
      25,   229,  -177,   251,   175,  -177,   293,   179,  -177,   312,
    -177,   312,   187,   414,   414,   395,   395,   395,   109,   109,
     109,   109,   388,   388,   369,   350,   193,   273,   137,  -177,
    -177,   126,   126,  -177,   204,   146,   146,   194,  -177,  -177,
     146,  -177,  -177,   223,    29,   206,   312,   207,   197,   126,
    -177,  -177,   146,  -177,  -177,  -177,  -177,   198,   126,  -177
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    14,    11,    12,     0,    13,    15,     0,
       2,     8,     0,     0,     8,     8,     8,    25,     0,     0,
       1,     8,     3,     9,     0,    10,     4,     5,     6,     0,
      27,    20,    36,     7,    16,    20,    24,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    29,    32,     0,    19,
      10,     0,     0,     0,    33,     0,     0,    26,    32,    32,
       0,    22,    39,    18,    20,    20,    17,    29,    30,    31,
      23,    21,    39,    41,     0,     0,    28,    38,    65,     0,
       0,     0,     0,     0,     0,     0,   100,     0,    61,     0,
       0,     0,     0,    87,    94,    95,    96,    97,    99,    98,
      49,     0,    41,    43,    44,    45,    47,    46,    48,     0,
      60,    64,    66,    63,     0,     0,     0,    56,     0,     0,
       0,     0,     0,    61,     0,     0,    73,    82,     0,    93,
      37,    40,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      36,     0,    83,     0,     0,    84,     0,     0,    55,    59,
      67,    59,     0,    68,    69,    70,    71,    72,    74,    75,
      76,    77,    78,    79,    80,    81,    88,     0,    62,    35,
      34,    61,    61,    85,     0,    61,     0,     0,    92,    90,
      93,    89,    53,    52,     0,     0,    59,     0,     0,    61,
      50,    86,    61,    58,    57,    91,    51,     0,    61,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,  -177,   250,   142,    31,    40,   -31,   -38,   -21,   190,
    -177,  -177,  -177,   186,   -32,  -177,   -66,    -4,   200,   163,
    -176,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -158,   -86,
     -80,  -177,  -177,    80,  -177
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    21,    22,    11,    12,    13,    14,    41,    49,
      15,    30,    38,    57,    60,    16,    44,   100,    73,   101,
     102,   103,   200,   104,   105,   106,   107,   108,   187,   109,
     110,   111,   112,   162,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    43,   124,   188,    40,   192,   193,    17,     3,    59,
     126,   127,   128,     4,    45,    18,    24,    40,     5,    24,
      59,    59,    25,   206,     7,    50,    68,    69,    19,    42,
       3,    40,   209,    40,    40,     4,   151,   157,   203,   153,
       5,    40,   156,    74,    75,   159,     7,    63,    20,   161,
      23,    66,    29,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    24,   177,   178,    31,
      35,    39,    53,    32,    24,    39,     8,   201,    58,    78,
      79,    80,    81,   179,   180,    82,    83,    84,    61,    58,
      58,    34,    85,    72,    36,    86,    87,    88,    89,   195,
      37,    90,    46,    72,    39,    39,   196,    47,    48,    51,
     161,    52,    54,    56,    91,   -61,   207,    55,    43,    43,
      92,    62,    62,    64,    93,    94,    95,    96,    97,    98,
      99,    65,    78,    79,    80,    81,    67,    70,    82,    83,
      84,   -62,   -62,   -62,   -62,    85,   114,   115,    86,    87,
      88,    89,    78,   194,    90,    81,    26,    27,    28,    83,
      84,   116,   117,    33,   118,    85,   119,    91,    86,   138,
     139,   140,   141,    92,    90,    62,   120,    93,    94,    95,
      96,    97,    98,    99,   130,   121,   122,    91,   123,   132,
     125,   129,   148,    92,   149,   150,   152,    93,    94,    95,
      96,    97,    98,    99,     1,     2,     3,     2,     3,     3,
     154,     4,   155,     4,     4,   158,     5,     6,     5,     5,
     176,   185,     7,   183,     7,     7,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   189,   142,   143,   144,   145,
     190,   199,   197,   146,   147,   205,   208,   160,   202,   204,
      10,    71,     8,    76,     8,     8,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   131,   142,   143,   144,   145,
     198,     0,    77,   146,   147,     0,     0,   181,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,   142,   143,
     144,   145,     0,     0,     0,   146,   147,     0,     0,   182,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
     142,   143,   144,   145,     0,     0,     0,   146,   147,   191,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
     142,   143,   144,   145,     0,     0,   184,   146,   147,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,   142,
     143,   144,   145,     0,     0,   186,   146,   147,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,   142,   143,
     144,   145,     0,     0,     0,   146,   147,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,   142,   143,   144,
       0,     0,     0,     0,   146,   147,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,   142,   143,     0,     0,
       0,     0,     0,   146,   147,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     1,     2,     3,   138,   139,   140,
     141,     4,   146,   147,     0,     0,     5,     6,     0,   146,
     147,     0,     7,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147
};

static const yytype_int16 yycheck[] =
{
      31,    32,    88,   161,    35,   181,   182,    51,     5,    47,
      90,    91,    92,    10,    35,    51,    45,    48,    15,    45,
      58,    59,    51,   199,    21,    51,    58,    59,    51,     4,
       5,    62,   208,    64,    65,    10,   116,   123,   196,   119,
      15,    72,   122,    64,    65,   125,    21,    51,     0,   129,
      42,    55,    11,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    45,   147,   148,    47,
      47,    31,    51,    49,    45,    35,    51,    48,    47,     6,
       7,     8,     9,   149,   150,    12,    13,    14,    48,    58,
      59,    46,    19,    62,    51,    22,    23,    24,    25,   185,
      17,    28,    51,    72,    64,    65,   186,    49,    43,    48,
     190,    51,    50,    43,    41,    42,   202,    48,   149,   150,
      47,    49,    49,    47,    51,    52,    53,    54,    55,    56,
      57,    47,     6,     7,     8,     9,    51,    50,    12,    13,
      14,    32,    33,    34,    35,    19,    48,    48,    22,    23,
      24,    25,     6,   184,    28,     9,    14,    15,    16,    13,
      14,    47,    42,    21,    47,    19,    47,    41,    22,    32,
      33,    34,    35,    47,    28,    49,    47,    51,    52,    53,
      54,    55,    56,    57,    50,    47,    47,    41,    47,    42,
      47,    47,    36,    47,    42,    42,    48,    51,    52,    53,
      54,    55,    56,    57,     3,     4,     5,     4,     5,     5,
      51,    10,    48,    10,    10,    42,    15,    16,    15,    15,
      51,    42,    21,    48,    21,    21,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    48,    37,    38,    39,    40,
      47,    18,    48,    44,    45,    48,    48,    48,    42,    42,
       0,    61,    51,    67,    51,    51,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   102,    37,    38,    39,    40,
     190,    -1,    72,    44,    45,    -1,    -1,    48,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    44,    45,    -1,    -1,    48,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    44,    45,    46,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    -1,    -1,    43,    44,    45,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    37,
      38,    39,    40,    -1,    -1,    43,    44,    45,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    44,    45,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    37,    38,    39,
      -1,    -1,    -1,    -1,    44,    45,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    44,    45,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     3,     4,     5,    32,    33,    34,
      35,    10,    44,    45,    -1,    -1,    15,    16,    -1,    44,
      45,    -1,    21,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    10,    15,    16,    21,    51,    59,
      60,    62,    63,    64,    65,    68,    73,    51,    51,    51,
       0,    60,    61,    42,    45,    51,    61,    61,    61,    11,
      69,    47,    49,    61,    46,    47,    51,    17,    70,    63,
      64,    66,     4,    64,    74,    66,    51,    49,    43,    67,
      51,    48,    51,    51,    50,    48,    43,    71,    62,    65,
      72,    63,    49,    75,    47,    47,    75,    51,    72,    72,
      50,    67,    62,    76,    66,    66,    71,    76,     6,     7,
       8,     9,    12,    13,    14,    19,    22,    23,    24,    25,
      28,    41,    47,    51,    52,    53,    54,    55,    56,    57,
      75,    77,    78,    79,    81,    82,    83,    84,    85,    87,
      88,    89,    90,    92,    48,    48,    47,    42,    47,    47,
      47,    47,    47,    47,    87,    47,    88,    88,    88,    47,
      50,    77,    42,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    37,    38,    39,    40,    44,    45,    36,    42,
      42,    88,    48,    88,    51,    48,    88,    87,    42,    88,
      48,    88,    91,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    51,    88,    88,    74,
      74,    48,    48,    48,    43,    42,    43,    86,    86,    48,
      47,    46,    78,    78,    64,    87,    88,    48,    91,    18,
      80,    48,    42,    86,    42,    48,    78,    87,    48,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    60,    60,    61,    61,    62,
      63,    64,    64,    64,    64,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    72,    73,    74,    74,    74,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    80,    80,    81,    82,    83,    84,    85,    86,    86,
      87,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    89,
      90,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     2,     0,     2,
       2,     1,     1,     1,     1,     1,     3,     6,     6,     2,
       0,     3,     0,     7,     2,     0,     3,     0,     3,     0,
       2,     2,     0,     5,     7,     7,     0,     4,     2,     0,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       6,     2,     0,     5,     9,     3,     2,     6,     3,     0,
       1,     0,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     4,     6,     1,     3,     4,
       4,     6,     2,     0,     1,     1,     1,     1,     1,     1,
       1
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
#line 83 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();	createNewNode("Decl","",yylineno,yycolumn);	addChildsToNode(0);}
#line 1499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();	createNewNode("VariableDecl","",yylineno,yycolumn);	addChildsToNode(1);	addNodeToChilds();
					createNewNode("OtraDecl","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("FunctionDecl","",yylineno,yycolumn);	addChildsToNode(1);	addNodeToChilds();
					createNewNode("OtraDecl","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1513 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 90 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("ClassDecl","",yylineno,yycolumn);		addChildsToNode(1);	addNodeToChilds();
					createNewNode("OtraDecl","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 92 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("InterfaceDecl","",yylineno,yycolumn);	addChildsToNode(1);	addNodeToChilds();
					createNewNode("OtraDecl","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1527 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 96 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();	createNewNode("OtraDecl","",yylineno,yycolumn);		addChildsToNode(1);	addNodeToChilds();
					createNewNode("OtraDecl","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 98 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 101 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("Variable","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();
					createNewNode("SEMICOLON",";",yylineno,yycolumn);		addNodeToChilds();}
#line 1547 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 105 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();	createNewNode("Type","",yylineno,yycolumn); 			addChildsToNode(0);	addNodeToChilds();
					createNewNode("ID",(yyvsp[0].sval),yylineno,yycolumn);				addNodeToChilds();}
#line 1554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 109 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();	createNewNode("INT","",yylineno,yycolumn);			addNodeToChilds();}
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 110 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("DOUBLE","",yylineno,yycolumn);			addNodeToChilds();}
#line 1566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 111 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("BOOL","",yylineno,yycolumn);			addNodeToChilds();}
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 112 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();	createNewNode("STRING","",yylineno,yycolumn);			addNodeToChilds();}
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 113 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("ID",(yyvsp[0].sval),yylineno,yycolumn);				addNodeToChilds();}
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 114 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("Type","",yylineno,yycolumn);			addChildsToNode(0);	addNodeToChilds();
						createNewNode("LBRACKET","",yylineno,yycolumn);	addNodeToChilds();
						createNewNode("RBRACKET","",yylineno,yycolumn);	addNodeToChilds();}
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 119 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("Type","",yylineno,yycolumn);			addChildsToNode(2); addNodeToChilds();
					createNewNode("ID",(yyvsp[-4].sval),yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Formals","",yylineno,yycolumn);		addChildsToNode(1);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("StmtBlock","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 125 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("VOID","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",(yyvsp[-4].sval),yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Formals","",yylineno,yycolumn);		addChildsToNode(1);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("StmtBlock","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 133 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("Variable","",yylineno,yycolumn);		addChildsToNode(1);	addNodeToChilds();
					createNewNode("FormalsVars","",yylineno,yycolumn);	addChildsToNode(0);		addNodeToChilds();}
#line 1621 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 138 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("COMMA","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Variable","",yylineno,yycolumn);		addChildsToNode(1);		addNodeToChilds();
					createNewNode("FormalsVars","",yylineno,yycolumn);	addChildsToNode(0);		addNodeToChilds();}
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 141 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 144 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("CLASS","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",(yyvsp[-5].sval),yylineno,yycolumn);				addNodeToChilds();
					createNewNode("ExtendDecl","",yylineno,yycolumn);		addChildsToNode(2);		addNodeToChilds();
					createNewNode("ImplementsDecl","",yylineno,yycolumn);	addChildsToNode(1);		addNodeToChilds();
					createNewNode("LBRACE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Field","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();
					createNewNode("RBRACE","",yylineno,yycolumn);			addNodeToChilds();}
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 153 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("EXTENDS","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("ID",(yyvsp[0].sval),yylineno,yycolumn);				addNodeToChilds();}
#line 1660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 155 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 158 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("IMPLEMENTS","",yylineno,yycolumn);		addNodeToChilds();
						createNewNode("ID",(yyvsp[-1].sval),yylineno,yycolumn);			addNodeToChilds();
						createNewNode("OtroID","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 161 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 164 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("COMMA","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",(yyvsp[-1].sval),yylineno,yycolumn);				addNodeToChilds();
					createNewNode("OtroID","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 167 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 170 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("VariableDecl","",yylineno,yycolumn);	addChildsToNode(1);	addNodeToChilds();
					createNewNode("Field","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 172 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();	createNewNode("FunctionDecl","",yylineno,yycolumn);	addChildsToNode(1);	addNodeToChilds();
					createNewNode("Field","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 1708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 174 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 177 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();	createNewNode("INTERFACE","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("ID",(yyvsp[-3].sval),yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LBRACE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Prototype","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();
					createNewNode("RBRACE","",yylineno,yycolumn);			addNodeToChilds();}
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 184 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("Type","",yylineno,yycolumn);			addChildsToNode(2);	addNodeToChilds();
					createNewNode("ID",(yyvsp[-5].sval),yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Formals","",yylineno,yycolumn);		addChildsToNode(1);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Prototype","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 191 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("VOID","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",(yyvsp[-5].sval),yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Formals","",yylineno,yycolumn);		addChildsToNode(1);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Prototype","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 198 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 201 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("LBRACE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("BlockVariables","",yylineno,yycolumn);	addChildsToNode(1);		addNodeToChilds();
					createNewNode("BlockStmts","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();
					createNewNode("RBRACE","",yylineno,yycolumn);			addNodeToChilds();}
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 207 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();	createNewNode("VariableDecl","",yylineno,yycolumn);	addChildsToNode(1);	addNodeToChilds();
					createNewNode("BlockVariables","",yylineno,yycolumn);	addChildsToNode(0);		addNodeToChilds();}
#line 1770 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 209 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 212 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("Stmt","",yylineno,yycolumn);			addChildsToNode(1);	addNodeToChilds();
					createNewNode("BlockStmts","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1783 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 214 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1789 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 217 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("ExprOpcional","",yylineno,yycolumn);	addChildsToNode(0);	addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();}
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 219 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("IfStmt","",yylineno,yycolumn);			addChildsToNode(0);	addNodeToChilds();}
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 220 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("WhileStmt","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 221 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("ForStmt","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 222 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("BreakStmt","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 223 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("ReturnStmt","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 224 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("PrintStmt","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 225 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("StmtBlock","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 228 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("IF","",yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(2);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Stmt","",yylineno,yycolumn);			addChildsToNode(1);		addNodeToChilds();
					createNewNode("ElseStmt","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1849 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 236 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("ELSE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Stmt","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 238 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 241 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("WHILE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Stmt","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 1872 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 248 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("FOR","",yylineno,yycolumn); addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn); 		addNodeToChilds();
					createNewNode("ExprOpcional","",yylineno,yycolumn); 	addChildsToNode(3);		addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn); 		addNodeToChilds();
					createNewNode("ExprOpcional","",yylineno,yycolumn);	addChildsToNode(2);		addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("ExprOpcional","",yylineno,yycolumn); 	addChildsToNode(1);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn); 		addNodeToChilds();
					createNewNode("Stmt","",yylineno,yycolumn); 			addChildsToNode(0);		addNodeToChilds();}
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 259 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();	createNewNode("RETURN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ExprOpcional","",yylineno,yycolumn);	addChildsToNode(0);		addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();}
#line 1894 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 264 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("BREAK","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();}
#line 1901 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 268 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();	createNewNode("PRINT","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);		addNodeToChilds();
					createNewNode("OtraExpr","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();}
#line 1912 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 276 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("COMMA","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);		addNodeToChilds();
					createNewNode("OtraExpr","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
#line 1920 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 279 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1926 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 282 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);	addNodeToChilds();}
#line 1932 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 283 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 1938 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 286 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("LValue","",yylineno,yycolumn);			addChildsToNode(1);	addNodeToChilds();
					createNewNode("EQUAL","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 289 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();	createNewNode("Constant","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
#line 1952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 290 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("LValue","",yylineno,yycolumn);			addChildsToNode(0);	addNodeToChilds();}
#line 1958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 291 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("THIS","",yylineno,yycolumn);			addNodeToChilds();}
#line 1964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 292 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("Call","",yylineno,yycolumn);			addChildsToNode(0);	addNodeToChilds();}
#line 1970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 293 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
#line 1978 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 296 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);	addNodeToChilds();
					createNewNode("SUM","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 1986 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 299 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);	addNodeToChilds();
					createNewNode("SUBTRACTION","",yylineno,yycolumn);							addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 1994 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 302 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);	addNodeToChilds();
					createNewNode("MULTIPLICATION","",yylineno,yycolumn);	addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2002 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 305 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); 	createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);	addNodeToChilds();
					createNewNode("DIVISION","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2010 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 308 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("MODULE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2018 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 311 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("SUBTRACTION","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 313 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("LESSTHAN","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2033 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 316 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("LESSEQUALTHAN","",yylineno,yycolumn);	addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 319 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("GREATERTHAN","",yylineno,yycolumn);						addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 322 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("GREATEREQUALTHAN","",yylineno,yycolumn);					addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2057 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 325 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("EEQUAL","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2065 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 328 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("DISTINCT","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2073 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 331 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("AND","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2081 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 334 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("OR","",yylineno,yycolumn);				addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2089 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 337 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("NEGATION","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
#line 2096 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 339 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("READINTEGER","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
#line 2104 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 342 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("READLINE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
#line 2112 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 345 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("NEW","",yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",(yyvsp[-1].sval),yylineno,yycolumn);				addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
#line 2121 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 349 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("NEWARRAY","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);		addNodeToChilds();
					createNewNode("COMMA","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Type","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
#line 2132 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 357 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("ID",(yyvsp[0].sval),yylineno,yycolumn);				addNodeToChilds();}
#line 2138 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 358 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(0);	addNodeToChilds();
					createNewNode("DOT","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",(yyvsp[0].sval),yylineno,yycolumn);				addNodeToChilds();}
#line 2146 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 361 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("LBRACKET","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);	addNodeToChilds();
					createNewNode("RBRACKET","",yylineno,yycolumn);		addNodeToChilds();}
#line 2155 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 367 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("ID",(yyvsp[-3].sval),yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Actuals","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
#line 2164 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 371 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(0);	addNodeToChilds();
					createNewNode("DOT","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",(yyvsp[-3].sval),yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Actuals","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
#line 2175 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 379 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("OtraExpr","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
#line 2182 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 381 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds();addBlankToChilds();}
#line 2188 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 384 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("CONSINTEGERDEC",(yyvsp[0].sval),yylineno,yycolumn);	addNodeToChilds();}
#line 2194 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 385 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("CONSINTEGERHEX",(yyvsp[0].sval),yylineno,yycolumn);	addNodeToChilds();}
#line 2200 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 386 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("CONSDOUBLEDEC",(yyvsp[0].sval),yylineno,yycolumn);		addNodeToChilds();}
#line 2206 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 387 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("CONSDOUBLECIEN",(yyvsp[0].sval),yylineno,yycolumn);	addNodeToChilds();}
#line 2212 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 388 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("CONSBOOLEAN",(yyvsp[0].sval),yylineno,yycolumn);		addNodeToChilds();}
#line 2218 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 389 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("CONSSTRING",(yyvsp[0].sval),yylineno,yycolumn);		addNodeToChilds();}
#line 2224 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 390 "parser.y" /* yacc.c:1646  */
    {createNewListaChilds(); createNewNode("TNULL","",yylineno,yycolumn);				addNodeToChilds();}
#line 2230 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2234 "parser.tab.c" /* yacc.c:1646  */
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
#line 393 "parser.y" /* yacc.c:1906  */


//----------------------------- Funciones -----------------------------

int yyerror(char *s){
	//printf("\nERROR\n");
	addError(yylineno,yycolumn,"Sintax error");
  flagSintaxError = true;
	return 1;
}

int main(int argcount, char **argvector)
{
    if (argcount == 2)
    {
        FILE *myfile = fopen(argvector[1], "r");
	    if (!myfile) {
		    cout << "No se puede leer el archivo con código o no existe" << endl;
		    return -1;
	    }
	    yyin = myfile;
    }
    else{
        yyin=stdin;
    }
	yyparse();
  if (flagLexicalError == false && flagSintaxError == false){
      printTable();
      printTree(nodo);
  }else{
      printTable();
  }
}


void createNewListaChilds(){
	listChildsToAdd.push_back(childsToAdd);
}

void createNewNode(string pToken, string pValue, int pRow, int pColumn){
	nodo= newNode(pToken, pValue, pRow, pColumn);
}

void addBlankToChilds(){
	pNodeParseTree nodonull = new NodeParseTree("<Sin hijos>","",yylineno,yycolumn);
	listChildsToAdd.at(listChildsToAdd.size()-1).push_back(nodonull);
}

void addNodeToChilds(){
		listChildsToAdd.at(listChildsToAdd.size()-1).push_back(nodo);
}

void addChildsToNode(int offset){
	int position = (listChildsToAdd.size()-2)-offset;
	if(position>=0){
		for(int i=0;i<listChildsToAdd.at(position).size();i++)
		{
			pNodeParseTree child = listChildsToAdd.at(position).at(i);
			nodo->addChild(child);
		}
		listChildsToAdd.erase(listChildsToAdd.begin() + position);
	}
}


void printTree(pNodeParseTree root){
  if(flagSintaxError == false){
      cout << "Program" << "\n";
    	cout << " -" << root->token << "\n";

    	printChilds(root, 1);
    	for(int i=treeToPrint.size();i>0;i--){
    		cout<<treeToPrint[i];
    	}
  }
}

void printChilds(pNodeParseTree root, int tabs){
	for(int i=root->childs.size()-1;i>=0;i--)
    {
		//SI funciona
		//Agarra en hijo del parametro nodo root
		pNodeParseTree child = root->childs.at(i);

		//Si tiene otros hijos los imprime
		if(child->childs.size()>0)
			printChilds(child,tabs+1);

		string nodeToPrint="";
		//Se cuentan la cantidad de tabs necesarios
		int contHijos=0;
		for(int j=0;j<tabs;j++){
			if(j<15)
				nodeToPrint=nodeToPrint+" ";
			else
				contHijos++;
		}

		nodeToPrint=nodeToPrint+"-";
		//Por lo grande del arbol se muestra con numeros en lugar de tabs
		if(contHijos>0)
			nodeToPrint = nodeToPrint + "H(" + std::to_string(contHijos) + ") ";
			//cout << "H(" << contHijos << ") ";

		//Imprime el token del nodo actual y si tiene valor tambien lo imprime
		if(child->value == "")
			nodeToPrint = nodeToPrint + child->token /*+ " Linea: " + std::to_string(child->row) + " Columna: "+ std::to_string(child->column)*/+"\n";
			//cout << child->token << "\n";
		else
			nodeToPrint = nodeToPrint + child->token + " Valor: " + child->value /*+ " Linea: " + std::to_string(child->row) + " Columna: "+ std::to_string(child->column)*/+ "\n";
			//cout << child->token << "Valor: " << child->value << "\n";

		treeToPrint.push_back(nodeToPrint);
	}

}
