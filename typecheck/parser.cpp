/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_comma = 258,
     T_assign = 259,
     T_or = 260,
     T_and = 261,
     T_isEq = 262,
     T_notEq = 263,
     T_less = 264,
     T_lessOrEq = 265,
     T_great = 266,
     T_greatOrEq = 267,
     T_minus = 268,
     T_plus = 269,
     T_mod = 270,
     T_divide = 271,
     T_times = 272,
     T_not = 273,
     T_deRef = 274,
     T_addr = 275,
     T_openCurly = 276,
     T_closeCurly = 277,
     T_openBracket = 278,
     T_closeBracket = 279,
     T_openParen = 280,
     T_closeParen = 281,
     T_true = 282,
     T_false = 283,
     T_string = 284,
     T_char = 285,
     T_num_oct = 286,
     T_num_bin = 287,
     T_num_hex = 288,
     T_num_dec = 289,
     T_null = 290,
     T_if = 291,
     T_else = 292,
     T_while = 293,
     T_bool_type = 294,
     T_char_type = 295,
     T_int_type = 296,
     T_string_type = 297,
     T_intptr_type = 298,
     T_charptr_type = 299,
     T_proc = 300,
     T_return = 301,
     T_var = 302,
     T_identifier = 303,
     T_col = 304,
     T_semiCol = 305,
     T_pipe = 306
   };
#endif
/* Tokens.  */
#define T_comma 258
#define T_assign 259
#define T_or 260
#define T_and 261
#define T_isEq 262
#define T_notEq 263
#define T_less 264
#define T_lessOrEq 265
#define T_great 266
#define T_greatOrEq 267
#define T_minus 268
#define T_plus 269
#define T_mod 270
#define T_divide 271
#define T_times 272
#define T_not 273
#define T_deRef 274
#define T_addr 275
#define T_openCurly 276
#define T_closeCurly 277
#define T_openBracket 278
#define T_closeBracket 279
#define T_openParen 280
#define T_closeParen 281
#define T_true 282
#define T_false 283
#define T_string 284
#define T_char 285
#define T_num_oct 286
#define T_num_bin 287
#define T_num_hex 288
#define T_num_dec 289
#define T_null 290
#define T_if 291
#define T_else 292
#define T_while 293
#define T_bool_type 294
#define T_char_type 295
#define T_int_type 296
#define T_string_type 297
#define T_intptr_type 298
#define T_charptr_type 299
#define T_proc 300
#define T_return 301
#define T_var 302
#define T_identifier 303
#define T_col 304
#define T_semiCol 305
#define T_pipe 306




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp"


    /*

    ulimit -c unlimited
    >> make
    >> ./csimple <test
    >> ls
    >> ls -la core

    >>gdb csimple
    >> r < test
    >> y
    >> bt //back trace the crash.
    >> print m_type
    >>
    */
    #include <cstdio>
    #include <cstdlib>

    #include "ast.hpp"
    #include "primitive.hpp"
    #include "symtab.hpp"

    #define YYDEBUG 1

    extern Program_ptr ast;
    int yylex(void);
    void yyerror(const char *);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 239 "parser.cpp"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  159

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
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    17,    18,    20,    22,    24,    26,
      28,    33,    39,    40,    44,    45,    48,    50,    53,    54,
      58,    59,    64,    68,    76,    77,    81,    82,    88,    94,
     100,   110,   125,   135,   144,   145,   147,   152,   155,   159,
     163,   167,   171,   175,   179,   183,   187,   191,   195,   199,
     203,   207,   211,   214,   217,   220,   223,   226,   228,   233,
     235,   237,   239,   241,   243,   245,   247,   249
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    -1,    45,    48,    25,    56,    26,
      46,    55,    21,    61,    22,    54,    -1,    -1,    39,    -1,
      41,    -1,    43,    -1,    44,    -1,    40,    -1,    42,    23,
      68,    24,    -1,    48,    57,    49,    55,    58,    -1,    -1,
       3,    48,    57,    -1,    -1,    50,    56,    -1,    56,    -1,
      67,    60,    -1,    -1,     3,    67,    60,    -1,    -1,    54,
      63,    65,    62,    -1,    46,    67,    50,    -1,    47,    48,
      64,    49,    55,    50,    63,    -1,    -1,     3,    48,    64,
      -1,    -1,    66,     4,    67,    50,    65,    -1,    66,     4,
      29,    50,    65,    -1,    21,    63,    65,    22,    65,    -1,
      36,    25,    67,    26,    21,    63,    65,    22,    65,    -1,
      36,    25,    67,    26,    21,    63,    65,    22,    37,    21,
      63,    65,    22,    65,    -1,    38,    25,    67,    26,    21,
      63,    65,    22,    65,    -1,    66,     4,    48,    25,    59,
      26,    50,    65,    -1,    -1,    48,    -1,    48,    23,    67,
      24,    -1,    19,    48,    -1,    51,    67,    51,    -1,    67,
       9,    67,    -1,    67,    10,    67,    -1,    67,    11,    67,
      -1,    67,    12,    67,    -1,    67,     7,    67,    -1,    67,
       8,    67,    -1,    67,     6,    67,    -1,    67,     5,    67,
      -1,    67,    17,    67,    -1,    67,    16,    67,    -1,    67,
      14,    67,    -1,    67,    13,    67,    -1,    25,    67,    26,
      -1,    18,    67,    -1,    13,    67,    -1,    14,    67,    -1,
      20,    66,    -1,    19,    67,    -1,    48,    -1,    48,    23,
      67,    24,    -1,    68,    -1,    27,    -1,    28,    -1,    30,
      -1,    35,    -1,    34,    -1,    31,    -1,    32,    -1,    33,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   108,   108,   115,   117,   121,   122,   123,   124,   125,
     126,   131,   134,   136,   138,   140,   142,   146,   148,   150,
     151,   155,   159,   163,   166,   170,   172,   177,   180,   183,
     186,   189,   191,   195,   197,   201,   202,   203,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   222,   223,   224,   225,   226,   228,   229,   231,
     232,   233,   234,   235,   240,   241,   242,   243
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_comma", "T_assign", "T_or", "T_and",
  "T_isEq", "T_notEq", "T_less", "T_lessOrEq", "T_great", "T_greatOrEq",
  "T_minus", "T_plus", "T_mod", "T_divide", "T_times", "T_not", "T_deRef",
  "T_addr", "T_openCurly", "T_closeCurly", "T_openBracket",
  "T_closeBracket", "T_openParen", "T_closeParen", "T_true", "T_false",
  "T_string", "T_char", "T_num_oct", "T_num_bin", "T_num_hex", "T_num_dec",
  "T_null", "T_if", "T_else", "T_while", "T_bool_type", "T_char_type",
  "T_int_type", "T_string_type", "T_intptr_type", "T_charptr_type",
  "T_proc", "T_return", "T_var", "T_identifier", "T_col", "T_semiCol",
  "T_pipe", "$accept", "Main", "Procedure", "Type", "ParamList",
  "ParamListSameType", "ParamListNewType", "Params", "ParamsMore",
  "BodyProc", "Return", "BodyVar", "BodyVarSameType", "BodyState", "Lhs",
  "Expr", "Num", 0
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
       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,    11,     0,     1,     1,     1,     1,     1,
       4,     5,     0,     3,     0,     2,     1,     2,     0,     3,
       0,     4,     3,     7,     0,     3,     0,     5,     5,     5,
       9,    14,     9,     8,     0,     1,     4,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     0,     1,    12,    14,     0,     0,
       0,     0,    14,     0,     0,    13,     5,     9,     6,     0,
       7,     8,    12,     0,     0,    12,    16,    11,     4,    65,
      66,    67,    64,     0,    15,    24,     0,    10,     0,    34,
       4,    26,     0,    24,     0,     0,    35,     0,     0,     3,
       0,     0,    37,    34,     0,     0,     0,     0,    21,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    57,     0,     0,    59,     0,     0,     0,
       0,    57,     0,    25,     0,    34,    53,    54,    52,    56,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    22,
      34,    18,    34,    24,    29,    51,     0,    38,    46,    45,
      43,    44,    39,    40,    41,    42,    50,    49,    48,    47,
      24,    24,    28,     0,    20,    27,    23,    58,    34,    34,
       0,     0,    17,     0,     0,    34,    20,    34,    34,    33,
      19,     0,    30,    32,    24,    34,     0,    34,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    22,     8,    10,    27,   133,   142,    36,
      58,    39,    51,    47,    48,    75,    76
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yytype_int16 yypact[] =
{
     -34,   -33,    20,   -50,     7,   -50,   -13,    39,    33,    -2,
      13,    23,    39,   105,   105,   -50,   -50,   -50,   -50,    58,
     -50,   -50,   -17,    64,    34,   -13,   -50,   -50,   -34,   -50,
     -50,   -50,   -50,    71,   -50,    45,    75,   -50,    52,    65,
     -34,    99,    59,    45,    84,    85,    89,    69,   110,   -50,
      80,    67,   -50,    65,   164,   164,   164,   164,   -50,   137,
      99,   105,   119,   164,   164,   164,   164,   -18,   164,   -50,
     -50,   -50,   -50,   129,   164,   197,   -50,   219,   263,   113,
     103,    68,   126,   -50,   104,    65,    88,    88,   -50,   -50,
     -50,   241,   164,    66,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   138,   139,   -50,   -50,
      65,   164,    65,    45,   -50,   -50,   283,   -50,   315,   326,
     336,   345,    27,   205,   225,    12,    88,    88,   -50,   -50,
      45,    45,   -50,   132,   303,   -50,   -50,   -50,    65,    65,
     111,   164,   -50,   151,   152,    65,   303,   -14,    65,   -50,
     -50,   154,   -50,   -50,    45,    65,   157,    65,   -50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,   -26,    -1,   -19,   168,   -50,   -50,    35,   -50,
     -50,   -43,   127,   -49,   123,   -47,   162
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      53,    42,    35,    26,    62,    42,    34,    43,    77,    78,
      79,     1,    82,    23,    49,     4,    86,    87,    88,    89,
       5,    91,    44,   151,    45,   102,   103,    93,   104,   105,
      46,     7,     6,    25,    46,     7,   114,    99,   100,   101,
     102,   103,     9,   104,   105,   116,    12,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    11,
      84,   132,    13,   135,   134,    29,    30,    31,    32,    14,
     136,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    24,   104,   105,    42,    28,    43,   138,   139,   143,
     144,    92,    38,   111,   146,    37,   149,    40,   152,   153,
      41,    44,    50,    45,   104,   105,   156,    52,   158,    54,
      55,   155,    56,    46,    59,    57,    61,   117,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    60,   104,
     105,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    85,   104,   105,    16,    17,    18,    19,    20,    21,
      63,    64,    92,   110,   113,    65,    66,    67,   140,   130,
     131,   145,    68,   109,    69,    70,    80,    71,    29,    30,
      31,    32,    72,   147,   148,   154,   112,    63,    64,   157,
      15,   150,    65,    66,    67,    81,    33,    83,    74,    68,
      90,    69,    70,     0,    71,    29,    30,    31,    32,    72,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    73,   104,   105,    74,   100,   101,   102,   103,
       0,   104,   105,   106,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,   104,   105,   101,   102,   103,
       0,   104,   105,     0,     0,   107,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,   115,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   104,
     105,     0,     0,     0,     0,     0,     0,   108,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   104,
     105,     0,     0,     0,     0,     0,   141,   137,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   104,
     105,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,   104,   105,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,    98,    99,   100,   101,   102,   103,
       0,   104,   105
};

static const yytype_int16 yycheck[] =
{
      43,    19,    28,    22,    53,    19,    25,    21,    55,    56,
      57,    45,    59,    14,    40,    48,    63,    64,    65,    66,
       0,    68,    36,    37,    38,    13,    14,    74,    16,    17,
      48,    48,    25,    50,    48,    48,    85,    10,    11,    12,
      13,    14,     3,    16,    17,    92,    48,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    26,
      61,   110,    49,   112,   111,    31,    32,    33,    34,    46,
     113,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    23,    16,    17,    19,    21,    21,   130,   131,   138,
     139,    23,    47,    25,   141,    24,   145,    22,   147,   148,
      48,    36,     3,    38,    16,    17,   155,    48,   157,    25,
      25,   154,    23,    48,     4,    46,    49,    51,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    48,    16,
      17,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    22,    16,    17,    39,    40,    41,    42,    43,    44,
      13,    14,    23,    50,    50,    18,    19,    20,    26,    21,
      21,    50,    25,    50,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    22,    22,    21,    50,    13,    14,    22,
      12,   146,    18,    19,    20,    48,    24,    60,    51,    25,
      67,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    48,    16,    17,    51,    11,    12,    13,    14,
      -1,    16,    17,    26,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    12,    13,    14,
      -1,    16,    17,    -1,    -1,    26,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    -1,    -1,    -1,    -1,    -1,     3,    24,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    17,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    17,     9,    10,    11,    12,    13,    14,
      -1,    16,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    53,    54,    48,     0,    25,    48,    56,     3,
      57,    26,    48,    49,    46,    57,    39,    40,    41,    42,
      43,    44,    55,    55,    23,    50,    56,    58,    21,    31,
      32,    33,    34,    68,    56,    54,    61,    24,    47,    63,
      22,    48,    19,    21,    36,    38,    48,    65,    66,    54,
       3,    64,    48,    63,    25,    25,    23,    46,    62,     4,
      48,    49,    65,    13,    14,    18,    19,    20,    25,    27,
      28,    30,    35,    48,    51,    67,    68,    67,    67,    67,
      29,    48,    67,    64,    55,    22,    67,    67,    67,    67,
      66,    67,    23,    67,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    16,    17,    26,    26,    24,    50,
      50,    25,    50,    50,    65,    26,    67,    51,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      21,    21,    65,    59,    67,    65,    63,    24,    63,    63,
      26,     3,    60,    65,    65,    50,    67,    22,    22,    65,
      60,    37,    65,    65,    21,    63,    65,    22,    65
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 109 "parser.ypp"
    {
                ast = new ProgramImpl((yyvsp[(1) - (1)]).u_proc_list);
            ;}
    break;

  case 3:
#line 115 "parser.ypp"
    {
                ((yyvsp[(11) - (11)]).u_proc_list)->push_front(new ProcImpl( new SymName((yyvsp[(2) - (11)]).u_base_charptr), (yyvsp[(4) - (11)]).u_decl_list, (yyvsp[(7) - (11)]).u_type, (yyvsp[(9) - (11)]).u_procedure_block)); (yyval) = (yyvsp[(11) - (11)]);;}
    break;

  case 4:
#line 117 "parser.ypp"
    {(yyval).u_proc_list = new std::list<Proc_ptr>();;}
    break;

  case 5:
#line 121 "parser.ypp"
    {(yyval).u_type = new TBoolean();;}
    break;

  case 6:
#line 122 "parser.ypp"
    {(yyval).u_type = new TInteger();;}
    break;

  case 7:
#line 123 "parser.ypp"
    {(yyval).u_type = new TIntPtr();;}
    break;

  case 8:
#line 124 "parser.ypp"
    {(yyval).u_type = new TCharPtr();;}
    break;

  case 9:
#line 125 "parser.ypp"
    {(yyval).u_type = new TCharacter();;}
    break;

  case 10:
#line 126 "parser.ypp"
    {(yyval).u_type = new TString((yyvsp[(3) - (4)]).u_primitive);;}
    break;

  case 11:
#line 131 "parser.ypp"
    { // first param in procedure def
                        ((yyvsp[(2) - (5)]).u_symname_list)->push_front(new SymName((yyvsp[(1) - (5)]).u_base_charptr));
                        ((yyvsp[(5) - (5)]).u_decl_list)->push_front(new DeclImpl((yyvsp[(2) - (5)]).u_symname_list, (yyvsp[(4) - (5)]).u_type)); (yyval) = (yyvsp[(5) - (5)]);;}
    break;

  case 12:
#line 134 "parser.ypp"
    {(yyval).u_decl_list = new std::list<Decl_ptr>(); ;}
    break;

  case 13:
#line 136 "parser.ypp"
    { //add more to list of params and reset current pointer, to where the list will be built.
                        ((yyvsp[(3) - (3)]).u_symname_list)->push_front(new SymName((yyvsp[(2) - (3)]).u_base_charptr)); (yyval) = (yyvsp[(3) - (3)]);;}
    break;

  case 14:
#line 138 "parser.ypp"
    {(yyval).u_symname_list = new std::list<SymName_ptr>();;}
    break;

  case 15:
#line 140 "parser.ypp"
    { //add an identifier with a different type for the params
                        /*($2.u_symname_list)->push_front(new SymName($2.u_base_charptr));*/ (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 16:
#line 142 "parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 17:
#line 146 "parser.ypp"
    {
                        ((yyvsp[(2) - (2)]).u_expr_list)->push_front((yyvsp[(1) - (2)]).u_expr); (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 18:
#line 148 "parser.ypp"
    {(yyval).u_expr_list = new std::list<Expr_ptr>();;}
    break;

  case 19:
#line 150 "parser.ypp"
    { ((yyvsp[(3) - (3)]).u_expr_list)->push_front((yyvsp[(2) - (3)]).u_expr); (yyval) = (yyvsp[(3) - (3)]);;}
    break;

  case 20:
#line 151 "parser.ypp"
    {(yyval).u_expr_list = new std::list<Expr_ptr>();;}
    break;

  case 21:
#line 155 "parser.ypp"
    {
                    (yyval).u_procedure_block =  new Procedure_blockImpl((yyvsp[(1) - (4)]).u_proc_list, (yyvsp[(2) - (4)]).u_decl_list, (yyvsp[(3) - (4)]).u_stat_list, (yyvsp[(4) - (4)]).u_return_stat);;}
    break;

  case 22:
#line 159 "parser.ypp"
    { (yyval).u_return_stat = new Return((yyvsp[(2) - (3)]).u_expr); ;}
    break;

  case 23:
#line 163 "parser.ypp"
    { //push back current identifier to
                    ((yyvsp[(3) - (7)]).u_symname_list)->push_front(new SymName((yyvsp[(2) - (7)]).u_base_charptr));
                    ((yyvsp[(7) - (7)]).u_decl_list)->push_front(new DeclImpl((yyvsp[(3) - (7)]).u_symname_list, (yyvsp[(5) - (7)]).u_type)); (yyval) = (yyvsp[(7) - (7)]);;}
    break;

  case 24:
#line 166 "parser.ypp"
    {   //finish declaration of variables, so construct the list, of lists of variables with the same type.
                    (yyval).u_decl_list = new std::list<Decl_ptr>();;}
    break;

  case 25:
#line 170 "parser.ypp"
    { // add more variables with same type.
                    ((yyvsp[(3) - (3)]).u_symname_list)->push_front(new SymName((yyvsp[(2) - (3)]).u_base_charptr)); (yyval) = (yyvsp[(3) - (3)]);;}
    break;

  case 26:
#line 172 "parser.ypp"
    { //Construct a List where all variables of the same type will be placed.
                    (yyval).u_symname_list = new std::list<SymName_ptr>();;}
    break;

  case 27:
#line 177 "parser.ypp"
    {//assign a value from lhs to rhs
                ((yyvsp[(5) - (5)]).u_stat_list)->push_front(new Assignment((yyvsp[(1) - (5)]).u_lhs, (yyvsp[(3) - (5)]).u_expr));  (yyval) = (yyvsp[(5) - (5)]);;}
    break;

  case 28:
#line 180 "parser.ypp"
    {
                ((yyvsp[(5) - (5)]).u_stat_list)->push_front(new StringAssignment((yyvsp[(1) - (5)]).u_lhs, new StringPrimitive((yyvsp[(3) - (5)]).u_base_charptr))); (yyval) = (yyvsp[(5) - (5)]);;}
    break;

  case 29:
#line 183 "parser.ypp"
    {
                ((yyvsp[(5) - (5)]).u_stat_list)->push_front( new CodeBlock(new Nested_blockImpl((yyvsp[(2) - (5)]).u_decl_list, (yyvsp[(3) - (5)]).u_stat_list)));  (yyval) = (yyvsp[(5) - (5)]);;}
    break;

  case 30:
#line 186 "parser.ypp"
    {
                ((yyvsp[(9) - (9)]).u_stat_list)->push_front(new IfNoElse((yyvsp[(3) - (9)]).u_expr, new Nested_blockImpl((yyvsp[(6) - (9)]).u_decl_list, (yyvsp[(7) - (9)]).u_stat_list))); (yyval) = (yyvsp[(9) - (9)]);;}
    break;

  case 31:
#line 189 "parser.ypp"
    {
                ((yyvsp[(14) - (14)]).u_stat_list)->push_front(new IfWithElse((yyvsp[(3) - (14)]).u_expr, new Nested_blockImpl((yyvsp[(6) - (14)]).u_decl_list, (yyvsp[(7) - (14)]).u_stat_list), new Nested_blockImpl((yyvsp[(11) - (14)]).u_decl_list, (yyvsp[(12) - (14)]).u_stat_list)));(yyval) =(yyvsp[(14) - (14)]);;}
    break;

  case 32:
#line 191 "parser.ypp"
    {   //whiles can happen at beggining of block

                ((yyvsp[(9) - (9)]).u_stat_list)->push_front(new WhileLoop((yyvsp[(3) - (9)]).u_expr, new Nested_blockImpl((yyvsp[(6) - (9)]).u_decl_list, (yyvsp[(7) - (9)]).u_stat_list))); (yyval) = (yyvsp[(9) - (9)]);;}
    break;

  case 33:
#line 195 "parser.ypp"
    {
                ((yyvsp[(8) - (8)]).u_stat_list)->push_front(new Call((yyvsp[(1) - (8)]).u_lhs, new SymName((yyvsp[(3) - (8)]).u_base_charptr), (yyvsp[(5) - (8)]).u_expr_list)); (yyval)=(yyvsp[(8) - (8)]);;}
    break;

  case 34:
#line 197 "parser.ypp"
    { (yyval).u_stat_list = new std::list<Stat_ptr>();;}
    break;

  case 35:
#line 201 "parser.ypp"
    { (yyval).u_lhs = new Variable(new SymName((yyvsp[(1) - (1)]).u_base_charptr));;}
    break;

  case 36:
#line 202 "parser.ypp"
    { (yyval).u_lhs = new ArrayElement(new SymName((yyvsp[(1) - (4)]).u_base_charptr), (yyvsp[(3) - (4)]).u_expr);;}
    break;

  case 37:
#line 203 "parser.ypp"
    { (yyval).u_lhs = new DerefVariable(new SymName((yyvsp[(2) - (2)]).u_base_charptr));;}
    break;

  case 38:
#line 207 "parser.ypp"
    { (yyval).u_expr = new AbsoluteValue((yyvsp[(2) - (3)]).u_expr);;}
    break;

  case 39:
#line 208 "parser.ypp"
    { (yyval).u_expr = new Lt((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 40:
#line 209 "parser.ypp"
    { (yyval).u_expr = new Lteq((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 41:
#line 210 "parser.ypp"
    { (yyval).u_expr = new Gt((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 42:
#line 211 "parser.ypp"
    { (yyval).u_expr = new Gteq((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 43:
#line 212 "parser.ypp"
    { (yyval).u_expr = new Compare((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 44:
#line 213 "parser.ypp"
    { (yyval).u_expr = new Noteq((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 45:
#line 214 "parser.ypp"
    { (yyval).u_expr = new And((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 46:
#line 215 "parser.ypp"
    { (yyval).u_expr = new Or((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 47:
#line 216 "parser.ypp"
    { (yyval).u_expr = new Times((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 48:
#line 217 "parser.ypp"
    { (yyval).u_expr = new Div((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 49:
#line 218 "parser.ypp"
    { (yyval).u_expr = new Plus((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 50:
#line 219 "parser.ypp"
    { (yyval).u_expr = new Minus((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);;}
    break;

  case 51:
#line 220 "parser.ypp"
    { (yyval).u_expr = (yyvsp[(2) - (3)]).u_expr; ;}
    break;

  case 52:
#line 222 "parser.ypp"
    { (yyval).u_expr = new Not((yyvsp[(2) - (2)]).u_expr);;}
    break;

  case 53:
#line 223 "parser.ypp"
    {(yyval).u_expr = new Uminus((yyvsp[(2) - (2)]).u_expr);;}
    break;

  case 54:
#line 224 "parser.ypp"
    {(yyval).u_expr = (yyvsp[(2) - (2)]).u_expr;;}
    break;

  case 55:
#line 225 "parser.ypp"
    {(yyval).u_expr = new AddressOf((yyvsp[(2) - (2)]).u_lhs);;}
    break;

  case 56:
#line 226 "parser.ypp"
    { (yyval).u_expr = new Deref((yyvsp[(2) - (2)]).u_expr);;}
    break;

  case 57:
#line 228 "parser.ypp"
    {(yyval).u_expr = new Ident(new SymName((yyvsp[(1) - (1)]).u_base_charptr));;}
    break;

  case 58:
#line 229 "parser.ypp"
    { (yyval).u_expr = new ArrayAccess(new SymName((yyvsp[(1) - (4)]).u_base_charptr), (yyvsp[(3) - (4)]).u_expr);;}
    break;

  case 59:
#line 231 "parser.ypp"
    { (yyval).u_expr = new IntLit((yyvsp[(1) - (1)]).u_primitive);;}
    break;

  case 60:
#line 232 "parser.ypp"
    {(yyval).u_expr = new BoolLit(new Primitive((yyvsp[(1) - (1)]).u_base_int));;}
    break;

  case 61:
#line 233 "parser.ypp"
    {(yyval).u_expr = new BoolLit(new Primitive((yyvsp[(1) - (1)]).u_base_int));;}
    break;

  case 62:
#line 234 "parser.ypp"
    {(yyval).u_expr = new CharLit(new Primitive((yyvsp[(1) - (1)]).u_base_int));;}
    break;

  case 63:
#line 235 "parser.ypp"
    {(yyval).u_expr = new IntLit(new Primitive((yyvsp[(1) - (1)]).u_base_int));;}
    break;

  case 64:
#line 240 "parser.ypp"
    {(yyval).u_primitive =  new Primitive((yyvsp[(1) - (1)]).u_base_int);;}
    break;

  case 65:
#line 241 "parser.ypp"
    {(yyval).u_primitive =  new Primitive((yyvsp[(1) - (1)]).u_base_int);;}
    break;

  case 66:
#line 242 "parser.ypp"
    {(yyval).u_primitive =  new Primitive((yyvsp[(1) - (1)]).u_base_int);;}
    break;

  case 67:
#line 243 "parser.ypp"
    {(yyval).u_primitive =  new Primitive((yyvsp[(1) - (1)]).u_base_int);;}
    break;


/* Line 1267 of yacc.c.  */
#line 1959 "parser.cpp"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 244 "parser.ypp"


/** You shall not pass!
 *  You should not  have to do or edit anything past this.
 */

extern int yylineno;

void yyerror(const char *s)
{
    fprintf(stderr, "%s at line %d\n", s, yylineno);
    return;
}

