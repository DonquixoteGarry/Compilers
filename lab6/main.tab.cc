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
#line 1 "main.y" /* yacc.c:339  */

    #include"common.h"
    #include<string>
    #include<queue>
    extern TreeNode * root;
    int yylex();
    int yyerror( char const * );

    extern vector<layer> layers;
    extern vector<var> work_layer;
    extern int layerid;
    extern rodata_part rodata_code;
    extern func_part func_code;
    
    int temp_dec_size = 1;
    vector<string> while_stmt_code,for_stmt_code;
    
    bool declear_flag = 0,scan_flag = 0,while_flag = 0;
    bool for_flag = 0,for_flag_expr3 = 0;
    
    int curlabel;
    vector<int> label;
    int if_lev = 0;
    int whilectr = 0;
    int forctr = 0;
    int if_asm_order = 0; //if汇编语句块编号
    vector<temp_var> for_temp_varlist;
    int for_stmt_level = 0;

#line 96 "main.tab.cc" /* yacc.c:339  */

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
   by #include "main.tab.hh".  */
#ifndef YY_YY_MAIN_TAB_HH_INCLUDED
# define YY_YY_MAIN_TAB_HH_INCLUDED
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
    ID = 258,
    addr_id = 259,
    content_id = 260,
    INTEGER = 261,
    CHARACTER = 262,
    STRING = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    FOR = 267,
    RETURN = 268,
    CONST = 269,
    INT = 270,
    VOID = 271,
    CHAR = 272,
    STR = 273,
    SLB = 274,
    SRB = 275,
    MLB = 276,
    MRB = 277,
    LLB = 278,
    LRB = 279,
    COMMA = 280,
    SEMICOLON = 281,
    TRUE = 282,
    FALSE = 283,
    ADD = 284,
    SUB = 285,
    MUL = 286,
    DIV = 287,
    MOD = 288,
    ANSC = 289,
    DESC = 290,
    NEG = 291,
    POS = 292,
    ASSIGN = 293,
    ADD_ASS = 294,
    SUB_ASS = 295,
    MUL_ASS = 296,
    DIV_ASS = 297,
    MOD_ASS = 298,
    EQ = 299,
    NEQ = 300,
    GT = 301,
    GE = 302,
    LT = 303,
    LE = 304,
    NOT = 305,
    AND = 306,
    OR = 307,
    PRINTF = 308,
    SCANF = 309,
    dot = 310,
    LOWER_THEN_ELSE = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MAIN_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "main.tab.cc" /* yacc.c:358  */

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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   253

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    69,    71,    74,    76,    77,    78,    79,
      90,    91,    92,    93,    96,   124,   146,   168,   193,   220,
     247,   262,   279,   293,   294,   307,   309,   311,   312,   313,
     314,   315,   317,   326,   335,   346,   357,   369,   383,   388,
     406,   417,   441,   448,   457,   475,   485,   519,   521,   534,
     590,   605,   641,   703,   716,   721,   788,   805,   821,   870,
     919,   968,  1017,  1066,  1115,  1170,  1225,  1256,  1288,  1303,
    1304,  1305,  1339,  1373,  1407,  1445,  1482,  1506,  1532,  1539,
    1545,  1551,  1559
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "addr_id", "content_id", "INTEGER",
  "CHARACTER", "STRING", "IF", "ELSE", "WHILE", "FOR", "RETURN", "CONST",
  "INT", "VOID", "CHAR", "STR", "SLB", "SRB", "MLB", "MRB", "LLB", "LRB",
  "COMMA", "SEMICOLON", "TRUE", "FALSE", "ADD", "SUB", "MUL", "DIV", "MOD",
  "ANSC", "DESC", "NEG", "POS", "ASSIGN", "ADD_ASS", "SUB_ASS", "MUL_ASS",
  "DIV_ASS", "MOD_ASS", "EQ", "NEQ", "GT", "GE", "LT", "LE", "NOT", "AND",
  "OR", "PRINTF", "SCANF", "dot", "LOWER_THEN_ELSE", "$accept", "program",
  "statements", "statement", "assign", "params", "args", "funcs", "_else",
  "if_condi", "if_else", "_while", "while_condi", "while", "for", "_for",
  "for_condi", "for_expr12", "for_expr3", "return_stmt", "bool_statment",
  "instruction", "printf", "_SCANF", "scanf", "bool_expr", "expr", "type",
  "_ID", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     141,   -68,    -9,   -68,   -68,   199,   145,   -68,   -68,   -68,
     -68,   141,    12,   -68,    17,   141,   -68,   -68,    32,   -68,
     141,   -68,    -9,   141,   -68,   -68,    28,   -68,   -68,     7,
      52,    42,    88,   202,    -1,   -68,   -68,   -68,   -68,   199,
     199,   220,   -68,    96,   123,    97,   -68,   -68,    96,   -68,
     114,   -68,   -68,    86,   141,    96,   -68,   117,   -68,   108,
      59,   -68,   -68,   199,   199,   199,   199,   199,   199,   -68,
     -68,    -1,    -6,    49,    83,   -68,   -68,   199,   199,   199,
     199,   199,    92,   -68,    14,   -68,   202,   -68,   141,    -1,
      96,   -68,   109,   -68,   202,   106,   162,   -68,    83,    83,
      83,    83,    83,    83,   -68,   186,   -68,    -1,    -1,   -68,
     199,   199,   199,   199,   199,   199,    89,    89,   -68,   -68,
     -68,   -68,   -68,   180,   -68,   -14,   -68,   180,   -68,   -68,
     141,    31,    83,    82,   -27,    83,    83,    83,    83,    83,
      83,    45,   -68,    47,   -68,   141,   193,   -68,   -68,   -68,
     -68,   -68,    83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    82,     0,    38,    42,     0,     0,    78,    79,    80,
      81,     0,     0,    54,     0,     2,     3,    23,     0,    10,
       0,     6,     0,     0,     7,     8,     0,    13,     5,     0,
       0,     0,     0,    22,     0,    35,    68,    69,    70,     0,
       0,     0,    67,     0,     0,     0,     1,     4,     0,    50,
      36,    39,    40,     0,     0,     0,    11,     0,    12,    82,
       0,    20,    21,     0,     0,     0,     0,     0,     0,    56,
      57,     0,     0,     0,    77,    76,    46,     0,     0,     0,
       0,     0,     0,     9,     0,    25,    24,    34,     0,     0,
       0,    41,     0,    43,     0,     0,     0,    49,    14,    15,
      16,    17,    18,    19,    66,     0,    47,     0,     0,    48,
       0,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,    51,    53,     0,    37,     0,    45,     0,    27,    28,
       0,     0,    26,    64,    65,    58,    59,    60,    61,    62,
      63,     0,    44,     0,    33,     0,     0,    52,    55,    32,
      30,    31,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   137,    -2,   -39,   -24,   -40,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     127,    98,   -68,   -68,   -68,   -67,    -4,    -3,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,   131,    19,    88,    20,
      21,    22,    23,    24,    25,    26,    54,    55,    93,    27,
      35,    28,    29,    30,    31,    72,   105,    32,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    41,     1,    43,   104,    36,    37,    38,    60,    85,
      34,    33,   142,    47,   106,    33,    92,    46,    50,    82,
      33,    52,   125,    33,   107,   108,    69,    70,    39,    40,
      73,    45,    33,    56,   122,    74,    75,   107,   108,   123,
     133,   134,    47,    33,    33,   107,   108,    53,    86,    71,
      90,   145,    91,    33,    33,    94,   146,    48,    49,    98,
      99,   100,   101,   102,   103,   147,    60,   148,    58,   109,
     146,    57,   146,   116,   117,   118,   119,   120,    77,    78,
      79,    80,    81,   141,    48,    97,   124,   143,    33,     1,
      33,    59,   132,   110,   111,   112,   113,   114,   115,     1,
       6,     7,     8,     9,    10,    84,   135,   136,   137,   138,
     139,   140,    77,    78,    79,    80,    81,    48,   121,   132,
      79,    80,    81,   132,    87,    95,     1,    96,   144,   126,
      33,   127,     2,   107,     3,     4,     5,     6,     7,     8,
       9,    10,   152,   149,     1,    33,    11,    83,    44,    51,
       2,    89,     3,     4,     5,     6,     7,     8,     9,    10,
       7,     8,     9,    10,    11,     1,   128,   129,    36,    37,
      38,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,     0,   130,     1,   128,   129,    36,    37,    38,     0,
       0,    39,    40,     0,    12,    13,     1,   150,   151,    36,
      37,    38,     1,     0,     0,    36,    37,    38,     0,    39,
      40,     0,     0,     0,     0,    77,    78,    79,    80,    81,
       0,     0,    39,    40,     0,     0,     0,     0,    39,    40,
     110,   111,   112,   113,   114,   115,    61,    62,     0,     0,
      63,    64,    65,    66,    67,    68,    76,     0,     0,    77,
      78,    79,    80,    81
};

static const yytype_int16 yycheck[] =
{
       0,     5,     3,     6,    71,     6,     7,     8,    32,    48,
      19,    11,    26,    15,    20,    15,    55,     0,    20,    43,
      20,    23,    89,    23,    51,    52,    27,    28,    29,    30,
      34,    19,    32,    26,    20,    39,    40,    51,    52,    25,
     107,   108,    44,    43,    44,    51,    52,    19,    48,    50,
      53,    20,    54,    53,    54,    55,    25,    25,    26,    63,
      64,    65,    66,    67,    68,    20,    90,    20,    26,    20,
      25,    19,    25,    77,    78,    79,    80,    81,    29,    30,
      31,    32,    33,   123,    25,    26,    88,   127,    88,     3,
      90,     3,    96,    44,    45,    46,    47,    48,    49,     3,
      14,    15,    16,    17,    18,     8,   110,   111,   112,   113,
     114,   115,    29,    30,    31,    32,    33,    25,    26,   123,
      31,    32,    33,   127,    10,     8,     3,    19,   130,    20,
     130,    25,     9,    51,    11,    12,    13,    14,    15,    16,
      17,    18,   146,   145,     3,   145,    23,    24,    11,    22,
       9,    53,    11,    12,    13,    14,    15,    16,    17,    18,
      15,    16,    17,    18,    23,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,
      -1,    -1,    20,     3,     4,     5,     6,     7,     8,    -1,
      -1,    29,    30,    -1,    53,    54,     3,     4,     5,     6,
       7,     8,     3,    -1,    -1,     6,     7,     8,    -1,    29,
      30,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    29,    30,
      44,    45,    46,    47,    48,    49,    34,    35,    -1,    -1,
      38,    39,    40,    41,    42,    43,    26,    -1,    -1,    29,
      30,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    11,    12,    13,    14,    15,    16,    17,
      18,    23,    53,    54,    58,    59,    60,    61,    62,    64,
      66,    67,    68,    69,    70,    71,    72,    76,    78,    79,
      80,    81,    84,    85,    19,    77,     6,     7,     8,    29,
      30,    83,    85,    84,    59,    19,     0,    60,    25,    26,
      60,    77,    60,    19,    73,    74,    26,    19,    26,     3,
      62,    34,    35,    38,    39,    40,    41,    42,    43,    27,
      28,    50,    82,    83,    83,    83,    26,    29,    30,    31,
      32,    33,    62,    24,     8,    61,    85,    10,    65,    78,
      84,    60,    61,    75,    85,     8,    19,    26,    83,    83,
      83,    83,    83,    83,    82,    83,    20,    51,    52,    20,
      44,    45,    46,    47,    48,    49,    83,    83,    83,    83,
      83,    26,    20,    25,    60,    82,    20,    25,     4,     5,
      20,    63,    83,    82,    82,    83,    83,    83,    83,    83,
      83,    63,    26,    63,    60,    20,    25,    20,    20,    60,
       4,     5,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    64,    65,    66,    67,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    77,    78,
      78,    78,    79,    79,    80,    81,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    84,    84,
      84,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     3,
       1,     2,     2,     1,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     3,     3,     1,     1,     1,     3,
       3,     3,     6,     5,     1,     2,     2,     4,     1,     2,
       2,     3,     1,     2,     4,     2,     3,     3,     3,     3,
       2,     4,     6,     4,     1,     6,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     2,     2,     1,     1,
       1,     1,     1
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
#line 59 "main.y" /* yacc.c:1646  */
    {
        root=new TreeNode(NODE_PROG);
        root->addChild((yyvsp[0]));
        printf("\n\t.text\n\t.section\t.rodata\n");
        rodata_code.output();
        func_code.output();
        printf("\t.section\t.note.GNU-stack,\"\",@progbits\n\n");
    }
#line 1420 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 70 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1426 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 71 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);(yyval)->addSibling((yyvsp[0]));}
#line 1432 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 75 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1438 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1444 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 77 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1450 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 78 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1456 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 79 "main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[-1]);    
        vector<var> var = layers[layers.size()-1].var_list;
        while(work_layer.size()!=var.size())
        {
            if(work_layer[work_layer.size()-1].type != 4) func_code.addCode("\taddl\t$4, %esp\n");
            work_layer.pop_back();
        }
        layers.pop_back();
        layerid--;
    }
#line 1472 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 90 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1478 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 91 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1484 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 92 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1490 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 97 "main.y" /* yacc.c:1646  */
    {
        string offset;
        TreeNode* node=new TreeNode(NODE_ASSIGN);
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        if((yyvsp[-2])->varType != -1 && (yyvsp[-2])->varType != (yyvsp[0])->varType)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if((yyvsp[0])->varType == VAR_STR)
            goto STREND;
        if((yyvsp[-2])->int_val == -1)
        {
            offset = to_string(-(4*(temp_dec_size)));
            temp_dec_size++;
        }
        else
            offset = to_string(-(4*(yyvsp[-2])->int_val));
        func_code.addCode("\tpopl\t%eax\n");
        func_code.addCode("\tmovl\t%eax, " + offset + "(%ebp)\n");
        if(for_flag){func_code.addCode("FBG"+to_string(forctr)+":\n");}
        if(declear_flag) func_code.addCode("\tsubl\t$4, %esp\n");
       
    STREND:
        (yyval)=node;
    }
#line 1522 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 124 "main.y" /* yacc.c:1646  */
    {
        TreeNode* node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_ADD;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        if((yyvsp[-2])->varType != -1 && (yyvsp[-2])->varType != (yyvsp[0])->varType)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\taddl\t%ebx,-"+to_string(4*(yyvsp[-2])->int_val)+"(%ebp)\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\taddl\t%ebx,-"+to_string(4*(yyvsp[-2])->int_val)+"(%ebp)\n");
        }
        (yyval)=node;
    }
#line 1549 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 146 "main.y" /* yacc.c:1646  */
    {
        TreeNode* node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_MINUS;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        if((yyvsp[-2])->varType != -1 && (yyvsp[-2])->varType != (yyvsp[0])->varType)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tsubl\t%ebx,-"+to_string(4*(yyvsp[-2])->int_val)+"(%ebp)\n");
        }
        else{
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tsubl\t%ebx,-"+to_string(4*(yyvsp[-2])->int_val)+"(%ebp)\n");
        }
        (yyval)=node;
        
    }
#line 1576 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 168 "main.y" /* yacc.c:1646  */
    {
        TreeNode* node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_MULTI;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        if((yyvsp[-2])->varType != -1 && !((yyvsp[-2])->varType == (yyvsp[0])->varType == VAR_INTEGER))
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tmovl\t-" + to_string(4*(yyvsp[-2])->int_val) + "(%ebp), %eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tmovl\t%eax, -"+to_string(4*(yyvsp[-2])->int_val)+"(%ebp)\n");
        }
        else{
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tmovl\t-" + to_string(4*(yyvsp[-2])->int_val) + "(%ebp), %eax\n");
            func_code.addCode("\timull\t%ebx\n");
            func_code.addCode("\tmovl\t%eax, -"+to_string(4*(yyvsp[-2])->int_val)+"(%ebp)\n");
        }
        (yyval)=node;
    }
#line 1606 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 193 "main.y" /* yacc.c:1646  */
    {
        TreeNode* node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_DIV;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        if((yyvsp[-2])->varType != -1 && !((yyvsp[-2])->varType == (yyvsp[0])->varType == VAR_INTEGER))
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tmovl\t-" + to_string(4*(yyvsp[-2])->int_val) + "(%ebp), %eax\n");
            for_stmt_code.emplace_back("\tcltd\n");
            for_stmt_code.emplace_back("\tidivl\t%ebx\n");
            for_stmt_code.emplace_back("\tmovl\t%eax, -"+to_string(4*(yyvsp[-2])->int_val)+"(%ebp)\n");
        }
        else{
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tmovl\t-" + to_string(4*(yyvsp[-2])->int_val) + "(%ebp), %eax\n");
            func_code.addCode("\tcltd\n");
            func_code.addCode("\tidivl\t%ebx\n");
            func_code.addCode("\tmovl\t%eax, -"+to_string(4*(yyvsp[-2])->int_val)+"(%ebp)\n");
        }
        (yyval)=node;
    }
#line 1638 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 220 "main.y" /* yacc.c:1646  */
    {
        TreeNode* node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_MOD;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        if((yyvsp[-2])->varType != -1 && (yyvsp[-2])->varType != (yyvsp[0])->varType)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tmovl\t-" + to_string(4*(yyvsp[-2])->int_val) + "(%ebp), %eax\n");
            for_stmt_code.emplace_back("\tcltd\n");
            for_stmt_code.emplace_back("\tidivl\t%ebx\n");
            for_stmt_code.emplace_back("\tmovl\t%edx, -"+to_string(4*(yyvsp[-2])->int_val)+"(%ebp)\n");
        }
        else{
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tmovl\t-" + to_string(4*(yyvsp[-2])->int_val) + "(%ebp), %eax\n");
            func_code.addCode("\tcltd\n");
            func_code.addCode("\tidivl\t%ebx\n");
            func_code.addCode("\tmovl\t%edx, -"+to_string(4*(yyvsp[-2])->int_val)+"(%ebp)\n");
        }
        (yyval)=node;
    }
#line 1670 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 247 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_SADD;
        node->addChild((yyvsp[-1]));
        (yyval)=node; 
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\taddl\t$1,-"+to_string(4*(yyvsp[-1])->int_val)+"(%ebp)\n");
        }
        else{
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\taddl\t$1,-"+to_string(4*(yyvsp[-1])->int_val)+"(%ebp)\n");
        }
    }
#line 1690 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 262 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_SMIN;
        node->addChild((yyvsp[-1]));
        (yyval)=node; 
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tsubl\t$1,-"+to_string(4*(yyvsp[-1])->int_val)+"(%ebp)\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tsubl\t$1,-"+to_string(4*(yyvsp[-1])->int_val)+"(%ebp)\n");
        }
    }
#line 1711 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 280 "main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[0]); 
        string index;
        if((yyvsp[0])->int_val == -1)
            index = to_string(4*(temp_dec_size++));
        else
            index = to_string(4*(yyvsp[0])->int_val);
        func_code.addCode("\tmovl\t$0, -"+index+"(%ebp)\n"); 
        if(for_flag){func_code.addCode("FBG"+to_string(forctr)+":\n");}
        if(declear_flag) func_code.addCode("\tsubl\t$4, %esp\n");
        
        
    }
#line 1729 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 293 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1735 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 294 "main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[-2]);
        (yyval)->addSibling((yyvsp[0]));
        string index;
        if((yyvsp[-2])->int_val == -1)
            index = to_string(4*(temp_dec_size++));
        else
            index = to_string(4*(yyvsp[0])->int_val);
        func_code.addCode("\tmovl\t$0, -"+index+"(%ebp)\n"); 
        if(for_flag){func_code.addCode("FBG"+to_string(forctr)+":\n");}
        if(declear_flag) func_code.addCode("\tsubl\t$4, %esp\n");
        
    }
#line 1753 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 307 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]); (yyval)->addSibling((yyvsp[0]));}
#line 1759 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 310 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1765 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 311 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1771 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 312 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1777 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 313 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]); (yyval)->addSibling((yyvsp[0]));}
#line 1783 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 314 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]); (yyval)->addSibling((yyvsp[0]));}
#line 1789 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 315 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]); (yyval)->addSibling((yyvsp[0]));}
#line 1795 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 318 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_FUNC);
        node->addChild((yyvsp[-5]));
        node->addChild((yyvsp[-4]));
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
    }
#line 1808 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 326 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_FUNC);
        node->addChild((yyvsp[-4]));
        node->addChild((yyvsp[-3]));
        node->addChild((yyvsp[0]));
        func_code.set((yyvsp[-4])->varType, (yyvsp[-3])->varName);
        (yyval)=node;
    }
#line 1821 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 336 "main.y" /* yacc.c:1646  */
    {
        curlabel = label[if_lev-1];
        string lb1 = "IEL" + to_string(curlabel) + to_string(if_lev - 1);
        string lb2 = "IEL" + to_string(curlabel-1) + to_string(if_lev - 1);
        func_code.addCode("\tjmp\t" + lb1 + "\n");
        func_code.addCode(lb2 + ":\n");
        label.emplace_back(curlabel);
        curlabel = 0;
    }
#line 1835 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 347 "main.y" /* yacc.c:1646  */
    {
        func_code.addCode("\tpopl\t%eax\n");
        func_code.addCode("\tcmp\t$1, %eax\n");
        string lb = "IEL" + to_string(curlabel++) + to_string(if_lev++);
        func_code.addCode("\tjne\t"+lb+"\n");
        label.emplace_back(curlabel);
        curlabel = 0;
        (yyval)=(yyvsp[0]);
    }
#line 1849 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 358 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_IF;
        node->addChild((yyvsp[-1]));
        node->addChild((yyvsp[0]));
        curlabel = label[if_lev-1];
        string lb = "IEL" + to_string(curlabel-1) + to_string(--if_lev);
        func_code.addCode(lb + ":\n");
        label.pop_back();
        (yyval)=node;
    }
#line 1865 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 369 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_IF;
        node->addChild((yyvsp[-3]));
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        curlabel = label[if_lev-1];
        string lb = "IEL" + to_string(curlabel) + to_string(--if_lev);
        func_code.addCode(lb + ":\n");
        label.pop_back();
        (yyval)=node;
    }
#line 1882 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 384 "main.y" /* yacc.c:1646  */
    {
        while_flag = 1;
    }
#line 1890 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 389 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_WEXPR);
        node->int_val=whilectr;
        node->addChild((yyvsp[0]));
        func_code.addCode("WBG"+to_string(whilectr)+":\n");
        for(int i = 0;i < while_stmt_code.size();i++)
        {
            func_code.addCode(while_stmt_code[i]);
        }
        while_stmt_code.clear();
        func_code.addCode("\tpopl\t%eax\n");
        func_code.addCode("\tcmpl\t$1, %eax\n");
        func_code.addCode("\tjne\tWED"+to_string(whilectr++)+"\n");
        while_flag = 0;
        (yyval)=node;
    }
#line 1911 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 407 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_WHILE;
        node->addChild((yyvsp[-1]));
        node->addChild((yyvsp[0]));
        func_code.addCode("\tjmp\tWBG"+to_string((yyvsp[-1])->int_val)+"\n");
        func_code.addCode("WED"+to_string((yyvsp[-1])->int_val)+":\n");
        (yyval)=node;
    }
#line 1925 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 418 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_FOR;
        node->addChild((yyvsp[-1]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        while(for_temp_varlist[for_temp_varlist.size()-1].l == for_stmt_level)
        {
            work_layer.pop_back();
            for_temp_varlist.pop_back();
        }
        for_stmt_level--;

        for(int i = 0;i < for_stmt_code.size();i++)
        {
            func_code.addCode(for_stmt_code[i]);
        }
        for_stmt_code.clear();
        func_code.addCode("\tjmp\tFBG"+to_string((yyvsp[-1])->getChild(0)->int_val)+"\n");
        func_code.addCode("FED"+to_string((yyvsp[-1])->getChild(0)->int_val)+":\n");
    
    }
#line 1952 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 442 "main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[0]);
        for_flag = 1;
        for_flag_expr3 = 0;
    }
#line 1962 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 449 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_FEXPR);
        node->int_val = forctr;
        node->addChild((yyvsp[-1]));
        node->addChild((yyvsp[0]));
        (yyval) = node;
    }
#line 1974 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 458 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_FEXPR);
        node->int_val = forctr;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[-1]));
        for(int i = 0;i < for_stmt_code.size();i++)
        {
            func_code.addCode(for_stmt_code[i]);
        }
        for_stmt_code.clear();
        func_code.addCode("\tpopl\t%eax\n");
        func_code.addCode("\tcmpl\t$1, %eax\n");
        func_code.addCode("\tjne\tFED"+to_string(forctr)+"\n");
        for_flag_expr3 = 1;
        (yyval)=node;
    }
#line 1995 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 476 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_FEXPR);
        node->int_val = forctr++;
        node->addChild((yyvsp[-1]));
        for_flag_expr3 = 0;
        (yyval) = node;
        for_stmt_level++;
    }
#line 2008 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 485 "main.y" /* yacc.c:1646  */
    {
        if(while_flag)
        {
            for(int i=0;i<work_layer.size();i++)
            {
                while_stmt_code.emplace_back("\taddl\t$4,%esp\n");
            }
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebp\n");
            while_stmt_code.emplace_back("\tret\n");
        }
        else if(for_flag)
        {
            for(int i=0;i<work_layer.size();i++)
            {
                for_stmt_code.emplace_back("\taddl\t$4,%esp\n");
            }
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebp\n");
            for_stmt_code.emplace_back("\tret\n");
        }
        else
        {
            for(int i=0;i<work_layer.size();i++)
            {
                func_code.addCode("\taddl\t$4,%esp\n");
            }
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebp\n");
            func_code.addCode("\tret\n");
        }
        
    }
#line 2046 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 520 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2052 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 521 "main.y" /* yacc.c:1646  */
    {
        func_code.addCode("\tpopl\t%eax\n");
        func_code.addCode("\tmovl\t$0, %ebx\n");
        func_code.addCode("\tcmpl\t%ebx, %eax\n");
        func_code.addCode("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
        func_code.addCode("\tpushl\t$0\n");
        func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
        func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
        func_code.addCode("\tpushl\t$1\n");
        func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        (yyval) = (yyvsp[-1]);
    }
#line 2069 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 535 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_DECL;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[-1]));
        int vtype = (yyvsp[-2])->varType;
        (yyval)=node;
        int praseErr_flag = 0;
        vector<var> temp;
        if(!layers.empty())
        {
            temp = layers[layers.size()-1].var_list;
        }
        for(int i = 1;i < node->childNum();i++)
        {
            TreeNode* child = node->getChild(i);
            if(child->childNum() != 0 && child->getChild(1)->varType != vtype)
            {
                printf("Error : type invalid\n");
                exit(1);
            }
            for(int j = temp.size();j < work_layer.size();j++)
            {
                if(work_layer[j].name == (child->nodeType==NODE_ASSIGN?child->getChild(0)->varName:child->varName))
                {
                    printf("Error : var wrong\n");
                    layer(work_layer, layerid).output();
                    praseErr_flag = 1;
                    break;
                }
            }
            if(!praseErr_flag)
            {
                if(vtype == VAR_STR)
                {
                    if(child->childNum() == 0)
                    {
                        printf("Error : string wrong\n");
                        exit(1);
                    }
                    work_layer.emplace_back(var(child->getChild(0)->varName, rodata_code.size()));
                    rodata_code.emplace_back(child->getChild(1)->str_val);
                    if(for_flag) for_temp_varlist.emplace_back(temp_var(var(child->getChild(0)->varName, rodata_code.size()), for_stmt_level));
                    goto EA;
                }
                work_layer.emplace_back(var((yyvsp[-2])->varType, child->nodeType==NODE_ASSIGN?child->getChild(0)->varName:child->varName));
                if(for_flag) for_temp_varlist.emplace_back(temp_var(var((yyvsp[-2])->varType, child->nodeType==NODE_ASSIGN?child->getChild(0)->varName:child->varName), for_stmt_level));
            }
            EA:
                praseErr_flag = 0;
        }
        declear_flag = 0;
        for_flag = 0;
        temp_dec_size = work_layer.size() + 1;
    }
#line 2129 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 590 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_ASSIGN;
        node->addChild((yyvsp[-1]));
        for(int i = 0;i < node->childNum();i++)
        {
            TreeNode* child = node->getChild(i);
            if(child->getChild(0)->varType != child->getChild(1)->varType)
            {
                printf("Error : type invalid\n");
                exit(1);
            }
        }
        (yyval)=node;  
    }
#line 2149 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 605 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_DECL;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[-1]));
        (yyval)=node;
        int praseErr_flag = 0;
        vector<var> temp;
        if(!layers.empty())
        {
            temp = layers[layers.size()-1].var_list;
        }
        for(int i = 1;i < node->childNum();i++)
        {
            TreeNode* child = node->getChild(i);
            for(int j = temp.size();j < work_layer.size();j++)
            {
                if(work_layer[j].name == (child->nodeType==NODE_ASSIGN?child->getChild(0)->varName:child->varName))
                {
                    printf("Error : var wrong\n");
                    layer(work_layer, layerid).output();
                    praseErr_flag = 1;
                    break;
                }
            }
            if(!praseErr_flag)
            {
                work_layer.emplace_back(var((yyvsp[-3])->varType, child->nodeType==NODE_ASSIGN?child->getChild(0)->varName:child->varName));
                if(for_flag) for_temp_varlist.emplace_back(temp_var(var((yyvsp[-3])->varType, child->nodeType==NODE_ASSIGN?child->getChild(0)->varName:child->varName), for_stmt_level));
            }
            praseErr_flag = 0;
        }
        for_flag = 0;
        
    }
#line 2189 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 642 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_PRINTF;
        node->addChild((yyvsp[-3]));
        node->addChild((yyvsp[-1]));
        rodata_code.emplace_back((yyvsp[-3])->str_val);
        vector<int> q;
        string str = (yyvsp[-3])->str_val;
        for(int i = 0;i < str.length();i++)
        {
            if(str[i] == '%')
            {
                if(i+1 == str.length())
                {
                    printf("Error : control flag invalid\n");
                    exit(1);
                }
                switch(str[i+1])
                {
                    case 'd':
                        q.emplace_back(VAR_INTEGER);
                        break;
                    case 'c':
                        q.emplace_back(VAR_CHAR);
                        break;
                    case 's':
                        q.emplace_back(VAR_STR);
                        break;
                    default:
                        printf("Error : control flag invalid.\n");
                        exit(1);
                }
            }
        }
        if(q.size()+1 != node->childNum())
        {
            printf("Error : param invalid\n");
            exit(1);
        }
        vector<string> tmpv;
        for(int i = 0;i < q.size();i++)
        {
            TreeNode* child = node->getChild(i+1);
            if(q[i] != child->varType)
            {
                printf("Error : type invalid\n");
                exit(1);
            }
            tmpv.emplace_back(func_code.delCode());
        }
        for(int i = 0;i < tmpv.size();i++)
        {
            func_code.addCode(tmpv[i]);
        }
        func_code.addCode("\tsubl\t$"+to_string(work_layer.size()*4)+", %ebp\n");
        func_code.addCode("\tpushl\t$STR"+to_string(rodata_code.size()-1)+"\n");
        func_code.addCode("\tcall\tprintf\n");
        func_code.addCode("\taddl\t$"+to_string(work_layer.size()*4)+", %ebp\n");
        func_code.addCode("\taddl\t$"+to_string(q.size()*4+4)+", %esp\n");
        (yyval)=node;
    }
#line 2255 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 703 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_PRINTF;
        node->addChild((yyvsp[-1]));
        rodata_code.emplace_back((yyvsp[-1])->str_val);
        func_code.addCode("\tsubl\t$"+to_string(work_layer.size()*4)+", %ebp\n");
        func_code.addCode("\tpushl\t$STR"+to_string(rodata_code.size()-1)+"\n");
        func_code.addCode("\tcall\tprintf\n");
        func_code.addCode("\taddl\t$"+to_string(work_layer.size()*4)+", %ebp\n");
        func_code.addCode("\taddl\t$4, %esp\n");
        (yyval)=node;
    }
#line 2272 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 717 "main.y" /* yacc.c:1646  */
    {
        scan_flag = 1;
    }
#line 2280 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 722 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_SCANF;
        node->addChild((yyvsp[-3]));
        node->addChild((yyvsp[-1]));
        rodata_code.emplace_back((yyvsp[-3])->str_val);
        vector<int> q;
        string str = (yyvsp[-3])->str_val;
        for(int i = 0;i < str.length();i++)
        {
            if(str[i] == '%')
            {
                if(i+1 == str.length())
                {
                    printf("Error : control flag invalid\n");
                    exit(1);
                }
                switch(str[i+1])
                {
                    case 'd':
                        q.emplace_back(VAR_INTEGER);
                        break;
                    case 'c':
                        q.emplace_back(VAR_CHAR);
                        break;
                    case 's':
                        q.emplace_back(VAR_STR);
                        break;
                    default:
                        printf("Error : control flag invalid.\n");
                        exit(1);
                }
            }
        }
        if(q.size()+1 != node->childNum())
        {
            printf("Error : param invalid\n");
            exit(1);
        }
        vector<string> tmpv;
        for(int i = 0;i < q.size();i++)
        {
            TreeNode* child = node->getChild(i+1);
            if(q[i] != child->varType)
            {
                printf("Error : type invalid\n");
                exit(1);
            }
            tmpv.emplace_back(func_code.delCode());
        }
        for(int i = 0;i < tmpv.size();i++)
        {
            string str = tmpv[i].substr(7);
            str = "\tleal\t" + str.substr(0, str.find("\n")) + ", %eax\n";
            func_code.addCode(str);
            func_code.addCode("\tpushl\t%eax\n");
        }
        func_code.addCode("\tsubl\t$"+to_string(work_layer.size()*4)+", %ebp\n");
        func_code.addCode("\tpushl\t$STR"+to_string(rodata_code.size()-1)+"\n");
        func_code.addCode("\tcall\tscanf\n");
        func_code.addCode("\taddl\t$"+to_string(work_layer.size()*4)+", %ebp\n");
        func_code.addCode("\taddl\t$"+to_string(q.size()*4+4)+", %esp\n");
        (yyval)=node;
        scan_flag = 0;
    }
#line 2350 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 789 "main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[0]); 
        (yyval)->varType = VAR_BOOLEAN; 
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpushl\t$1\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpushl\t$1\n");
        }
        else
        {
            func_code.addCode("\tpushl\t$1\n");
        }
    }
#line 2371 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 805 "main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[0]); 
        (yyval)->varType = VAR_BOOLEAN; 
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpushl\t$0\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpushl\t$0\n");
        }
        else
        {
            func_code.addCode("\tpushl\t$0\n");
        }
    }
#line 2392 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 821 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_EQ;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_BOOLEAN;
        if((yyvsp[-2])->varType != (yyvsp[0])->varType)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tcmpl\t%eax, %ebx\n");
            func_code.addCode("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        (yyval)=node;
    }
#line 2446 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 870 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_NE;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_BOOLEAN;
        if((yyvsp[-2])->varType != (yyvsp[0])->varType)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tje\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tje\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tcmpl\t%eax, %ebx\n");
            func_code.addCode("\tje\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        (yyval)=node;
    }
#line 2500 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 919 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_GT;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_BOOLEAN;
        if((yyvsp[-2])->varType != VAR_INTEGER || (yyvsp[0])->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        (yyval)=node;
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tjle\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tjle\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tcmpl\t%eax, %ebx\n");
            func_code.addCode("\tjle\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
    }
#line 2554 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 968 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_GE;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_BOOLEAN;
        if((yyvsp[-2])->varType != VAR_INTEGER || (yyvsp[0])->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        (yyval)=node;
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tjl\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tjl\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tcmpl\t%eax, %ebx\n");
            func_code.addCode("\tjl\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
    }
#line 2608 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 1017 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_LT;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_BOOLEAN;
        if((yyvsp[-2])->varType != VAR_INTEGER || (yyvsp[0])->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tjge\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tjge\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tcmpl\t%eax, %ebx\n");
            func_code.addCode("\tjge\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        (yyval)=node;
    }
#line 2662 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 1066 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_LE;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_BOOLEAN;
        if((yyvsp[-2])->varType != VAR_INTEGER || (yyvsp[0])->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tjg\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tjg\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tcmpl\t%eax, %ebx\n");
            func_code.addCode("\tjg\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        (yyval)=node;
    }
#line 2716 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 1115 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_AND;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_BOOLEAN;
        if((yyvsp[-2])->varType != VAR_BOOLEAN || (yyvsp[0])->varType != VAR_BOOLEAN)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\taddl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tmovl\t$2, %eax\n");
            while_stmt_code.emplace_back("\tcmpl\t%ebx, %eax\n");
            while_stmt_code.emplace_back("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\taddl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tmovl\t$2, %eax\n");
            for_stmt_code.emplace_back("\tcmpl\t%ebx, %eax\n");
            for_stmt_code.emplace_back("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\taddl\t%eax, %ebx\n");
            func_code.addCode("\tmovl\t$2, %eax\n");
            func_code.addCode("\tcmpl\t%ebx, %eax\n");
            func_code.addCode("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        (yyval)=node;
    }
#line 2776 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 1170 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_OR;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_BOOLEAN;
        if((yyvsp[-2])->varType != VAR_BOOLEAN || (yyvsp[0])->varType != VAR_BOOLEAN)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\taddl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tmovl\t$0, %eax\n");
            while_stmt_code.emplace_back("\tcmpl\t%ebx, %eax\n");
            while_stmt_code.emplace_back("\tje\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
         else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\taddl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tmovl\t$0, %eax\n");
            for_stmt_code.emplace_back("\tcmpl\t%ebx, %eax\n");
            for_stmt_code.emplace_back("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\taddl\t%eax, %ebx\n");
            func_code.addCode("\tmovl\t$0, %eax\n");
            func_code.addCode("\tcmpl\t%ebx, %eax\n");
            func_code.addCode("\tje\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        (yyval)=node;
    }
#line 2836 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 1225 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_NOT;
        node->addChild((yyvsp[0]));
        node->varType=VAR_BOOLEAN;
        if((yyvsp[0])->varType != VAR_BOOLEAN)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tsubl\t$1, %eax\n");
            while_stmt_code.emplace_back("\tpushl\t%eax\n");
        }
         else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tsubl\t$1, %eax\n");
            for_stmt_code.emplace_back("\tpushl\t%eax\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tsubl\t$1, %eax\n");
            func_code.addCode("\tpushl\t%eax\n");
        }
        (yyval)=node;        
    }
#line 2871 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 1257 "main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[0]);
        vector<var>::reverse_iterator curr_var = work_layer.rbegin();
        int i = 0;
        while(curr_var != work_layer.rend())
        {
            if((*curr_var).name == (yyval)->varName)
            {
                string code = "\tpushl\t";
                if((yyval)->varType == VAR_STR)
                    code += "$STR" + to_string((yyval)->int_val) + "\n";
                else
                    code += "-" + to_string(4*(work_layer.size()-i)) + "(%ebp)\n";
                if(while_flag)
                {
                    while_stmt_code.emplace_back(code);
                }
                else if(for_flag_expr3)
                {
                    for_stmt_code.emplace_back(code);
                }
                else
                {
                    func_code.addCode(code);
                }
                break;
            }
            curr_var++;
            i++;
        }
    }
#line 2907 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 1288 "main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[0]);
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpushl\t$" + to_string((yyval)->int_val) + "\n");
        }
        else if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpushl\t$" + to_string((yyval)->int_val) + "\n");
        }
        else
        {
            func_code.addCode("\tpushl\t$" + to_string((yyval)->int_val) + "\n");
        }
    }
#line 2927 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 1303 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2933 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 1304 "main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2939 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 1305 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_ADD;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_INTEGER;
        if((yyvsp[-2])->varType != VAR_INTEGER || (yyvsp[0])->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\taddl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tpushl\t%ebx\n");
        }
        else if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\taddl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tpushl\t%ebx\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\taddl\t%eax, %ebx\n");
            func_code.addCode("\tpushl\t%ebx\n");
        }
        (yyval)=node;   
    }
#line 2978 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 1339 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_MINUS;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_INTEGER;
        if((yyvsp[-2])->varType != VAR_INTEGER || (yyvsp[0])->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tsubl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tpushl\t%ebx\n");
        }
        else if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tsubl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tpushl\t%ebx\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tsubl\t%eax, %ebx\n");
            func_code.addCode("\tpushl\t%ebx\n");
        }
        (yyval)=node;   
    }
#line 3017 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 1373 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_MULTI;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_INTEGER;
        if((yyvsp[-2])->varType != VAR_INTEGER || (yyvsp[0])->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\timull\t%ebx\n");
            while_stmt_code.emplace_back("\tpushl\t%eax\n");
        }
        else if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\timull\t%ebx\n");
            for_stmt_code.emplace_back("\tpushl\t%eax\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\timull\t%ebx\n");
            func_code.addCode("\tpushl\t%eax\n");
        }
        (yyval)=node;   
    }
#line 3056 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 1407 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_DIV;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_INTEGER;
        if((yyvsp[-2])->varType != VAR_INTEGER || (yyvsp[0])->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tcltd\n");
            while_stmt_code.emplace_back("\tidivl\t%ebx\n");
            while_stmt_code.emplace_back("\tpushl\t%eax\n");
        }
        else if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tcltd\n");
            for_stmt_code.emplace_back("\tidivl\t%ebx\n");
            for_stmt_code.emplace_back("\tpushl\t%eax\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tcltd\n");
            func_code.addCode("\tidivl\t%ebx\n");
            func_code.addCode("\tpushl\t%eax\n");
        }
        
        (yyval)=node;   
    }
#line 3099 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 1445 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_MOD;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        node->varType=VAR_INTEGER;
        if((yyvsp[-2])->varType != VAR_INTEGER || (yyvsp[0])->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tcltd\n");
            while_stmt_code.emplace_back("\tidivl\t%ebx\n");
            while_stmt_code.emplace_back("\tpushl\t%edx\n");
        }
        else if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tcltd\n");
            for_stmt_code.emplace_back("\tidivl\t%ebx\n");
            for_stmt_code.emplace_back("\tpushl\t%edx\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tcltd\n");
            func_code.addCode("\tidivl\t%ebx\n");
            func_code.addCode("\tpushl\t%edx\n");
        }
        (yyval)=node;   
    }
#line 3141 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 1482 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_NEG;
        node->addChild((yyvsp[0]));
        node->varType=VAR_INTEGER;
        if((yyvsp[0])->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        TreeNode* child = node->getChild(0);
        if(child->varName == "#")
        {
            func_code.resetCode("\tpushl\t$-" + to_string(child->int_val) + "\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tmovl\t$-1, %eax\n");
            func_code.addCode("\timull\t%ebx\n");
            func_code.addCode("\tpushl\t%eax\n");
        }
        (yyval)=node; 
    }
#line 3170 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 1507 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_POS;
        node->addChild((yyvsp[0]));
        node->varType=VAR_INTEGER;
        if((yyvsp[0])->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        TreeNode* child = node->getChild(0);
        if(child->varName == "#")
        {
            func_code.resetCode("\tpushl\t$" + to_string(child->int_val) + "\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tmovl\t$1, %eax\n");
            func_code.addCode("\timull\t%ebx\n");
            func_code.addCode("\tpushl\t%eax\n");
        }
        (yyval)=node; 
    }
#line 3199 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 1533 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_TYPE);
        node->varType=VAR_INTEGER;
        declear_flag = 1;
        (yyval)=node; 
    }
#line 3210 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 1539 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_TYPE);
        node->varType=VAR_VOID;
        declear_flag = 1;
        (yyval)=node;         
    }
#line 3221 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 1545 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_TYPE);
        node->varType=VAR_CHAR;
        declear_flag = 1;
        (yyval)=node;
    }
#line 3232 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 81:
#line 1551 "main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(NODE_TYPE);
        node->varType=VAR_STR;
        declear_flag = 1;
        (yyval)=node;
    }
#line 3243 "main.tab.cc" /* yacc.c:1646  */
    break;

  case 82:
#line 1560 "main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[0]);
        if((yyval)->int_val == -1)
        {
            vector<var>::reverse_iterator curr_var = work_layer.rbegin();
            int i = 0;
            while(curr_var != work_layer.rend())
            {
                if((*curr_var).name == (yyval)->varName)
                {
                    break;
                }
                curr_var++;
                i++;
            }
            if(!declear_flag) (yyval)->int_val = work_layer.size() - i;
            if((yyval)->varType == VAR_STR) (yyval)->int_val = (*curr_var).ro_index;
        }
    }
#line 3267 "main.tab.cc" /* yacc.c:1646  */
    break;


#line 3271 "main.tab.cc" /* yacc.c:1646  */
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
#line 1580 "main.y" /* yacc.c:1906  */

