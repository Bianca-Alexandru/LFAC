/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 28 "language.y"

#include <iostream>
#include <vector>
#include "SymTable.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class SymTable* current;
int errorCount = 0;
vector<SymTable*> symTables;
string* tempClassName = NULL;

#line 86 "language.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "language.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OR = 3,                         /* OR  */
  YYSYMBOL_AND = 4,                        /* AND  */
  YYSYMBOL_5_ = 5,                         /* '<'  */
  YYSYMBOL_6_ = 6,                         /* '>'  */
  YYSYMBOL_LEQ = 7,                        /* LEQ  */
  YYSYMBOL_GEQ = 8,                        /* GEQ  */
  YYSYMBOL_EQ = 9,                         /* EQ  */
  YYSYMBOL_NEQ = 10,                       /* NEQ  */
  YYSYMBOL_11_ = 11,                       /* '+'  */
  YYSYMBOL_12_ = 12,                       /* '-'  */
  YYSYMBOL_13_ = 13,                       /* '*'  */
  YYSYMBOL_14_ = 14,                       /* '/'  */
  YYSYMBOL_15_ = 15,                       /* '%'  */
  YYSYMBOL_16_ = 16,                       /* '^'  */
  YYSYMBOL_17_ = 17,                       /* '!'  */
  YYSYMBOL_OF = 18,                        /* OF  */
  YYSYMBOL_UMINUS = 19,                    /* UMINUS  */
  YYSYMBOL_BEGIN_MAIN = 20,                /* BEGIN_MAIN  */
  YYSYMBOL_END_MAIN = 21,                  /* END_MAIN  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_AS = 23,                        /* AS  */
  YYSYMBOL_SUMMON = 24,                    /* SUMMON  */
  YYSYMBOL_ARISE = 25,                     /* ARISE  */
  YYSYMBOL_ZAT = 26,                       /* ZAT  */
  YYSYMBOL_BOOL = 27,                      /* BOOL  */
  YYSYMBOL_QAT = 28,                       /* QAT  */
  YYSYMBOL_CAT = 29,                       /* CAT  */
  YYSYMBOL_ID = 30,                        /* ID  */
  YYSYMBOL_TYPE = 31,                      /* TYPE  */
  YYSYMBOL_STRING = 32,                    /* STRING  */
  YYSYMBOL_ID_BOOL = 33,                   /* ID_BOOL  */
  YYSYMBOL_ID_COM = 34,                    /* ID_COM  */
  YYSYMBOL_ID_STR = 35,                    /* ID_STR  */
  YYSYMBOL_ID_INT = 36,                    /* ID_INT  */
  YYSYMBOL_ID_FLOAT = 37,                  /* ID_FLOAT  */
  YYSYMBOL_MAG = 38,                       /* MAG  */
  YYSYMBOL_REAL = 39,                      /* REAL  */
  YYSYMBOL_IMAG = 40,                      /* IMAG  */
  YYSYMBOL_IF = 41,                        /* IF  */
  YYSYMBOL_ELSE = 42,                      /* ELSE  */
  YYSYMBOL_WHILE = 43,                     /* WHILE  */
  YYSYMBOL_PRINT = 44,                     /* PRINT  */
  YYSYMBOL_45_ = 45,                       /* ';'  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_progr = 52,                     /* progr  */
  YYSYMBOL_declarations = 53,              /* declarations  */
  YYSYMBOL_TYPENAME = 54,                  /* TYPENAME  */
  YYSYMBOL_ANYID = 55,                     /* ANYID  */
  YYSYMBOL_decl = 56,                      /* decl  */
  YYSYMBOL_newscopefunc = 57,              /* newscopefunc  */
  YYSYMBOL_newscopeclass = 58,             /* newscopeclass  */
  YYSYMBOL_fundecl = 59,                   /* fundecl  */
  YYSYMBOL_60_1 = 60,                      /* $@1  */
  YYSYMBOL_61_2 = 61,                      /* $@2  */
  YYSYMBOL_62_3 = 62,                      /* $@3  */
  YYSYMBOL_63_4 = 63,                      /* $@4  */
  YYSYMBOL_insidefunc = 64,                /* insidefunc  */
  YYSYMBOL_classdecl = 65,                 /* classdecl  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_67_6 = 67,                      /* $@6  */
  YYSYMBOL_68_7 = 68,                      /* $@7  */
  YYSYMBOL_class_body = 69,                /* class_body  */
  YYSYMBOL_exp = 70,                       /* exp  */
  YYSYMBOL_bexp = 71,                      /* bexp  */
  YYSYMBOL_cexp = 72,                      /* cexp  */
  YYSYMBOL_stexp = 73,                     /* stexp  */
  YYSYMBOL_list_param = 74,                /* list_param  */
  YYSYMBOL_param = 75,                     /* param  */
  YYSYMBOL_main = 76,                      /* main  */
  YYSYMBOL_list = 77,                      /* list  */
  YYSYMBOL_statement = 78,                 /* statement  */
  YYSYMBOL_simple_statement = 79,          /* simple_statement  */
  YYSYMBOL_block = 80,                     /* block  */
  YYSYMBOL_if_statement = 81,              /* if_statement  */
  YYSYMBOL_while_statement = 82,           /* while_statement  */
  YYSYMBOL_call_list = 83                  /* call_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,     2,     2,    15,     2,     2,
      47,    48,    13,    11,    46,    12,     2,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       5,     2,     6,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    16,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
       7,     8,     9,    10,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,    79,    80,    81,    82,    85,    86,    89,
      90,    91,    92,    93,    94,    97,   112,   129,   135,   142,
     142,   172,   188,   204,   172,   208,   209,   210,   212,   227,
     239,   212,   242,   243,   244,   247,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   279,   296,   305,
     315,   316,   317,   320,   321,   330,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   358,   359,   368,   385,   386,
     387,   392,   397,   400,   401,   410,   427,   431,   434,   439,
     446,   456,   459,   460,   464,   465,   466,   470,   471,   472,
     473,   474,   480,   488,   510,   532,   533,   536,   540,   541,
     545,   549,   550,   551
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "OR", "AND", "'<'",
  "'>'", "LEQ", "GEQ", "EQ", "NEQ", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'^'", "'!'", "OF", "UMINUS", "BEGIN_MAIN", "END_MAIN", "ASSIGN", "AS",
  "SUMMON", "ARISE", "ZAT", "BOOL", "QAT", "CAT", "ID", "TYPE", "STRING",
  "ID_BOOL", "ID_COM", "ID_STR", "ID_INT", "ID_FLOAT", "MAG", "REAL",
  "IMAG", "IF", "ELSE", "WHILE", "PRINT", "';'", "','", "'('", "')'",
  "'{'", "'}'", "$accept", "progr", "declarations", "TYPENAME", "ANYID",
  "decl", "newscopefunc", "newscopeclass", "fundecl", "$@1", "$@2", "$@3",
  "$@4", "insidefunc", "classdecl", "$@5", "$@6", "$@7", "class_body",
  "exp", "bexp", "cexp", "stexp", "list_param", "param", "main", "list",
  "statement", "simple_statement", "block", "if_statement",
  "while_statement", "call_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -111,    54,    92,  -111,  -111,   204,     1,  -111,  -111,  -111,
    -111,   180,  -111,  -111,  -111,  -111,  -111,  -111,    33,  -111,
    -111,    23,    37,    56,    99,   101,   117,    87,    95,   104,
     122,  -111,   107,  -111,  -111,    38,  -111,   143,   121,    11,
      12,   143,   143,   121,   121,   138,   204,  -111,  -111,  -111,
     -17,   113,   143,  -111,  -111,   126,   128,   106,   109,   116,
     143,   245,    -7,   121,  -111,   147,   238,   111,  -111,   149,
      11,     4,  -111,   154,   173,   245,   245,    31,    34,    72,
      -5,   -15,  -111,   163,    38,  -111,  -111,   158,   159,    11,
      11,    11,    82,   143,   143,   143,   143,   143,   143,  -111,
     143,  -111,  -111,   161,   143,   143,   143,   143,   143,   143,
     121,   121,   164,     9,    11,    11,    11,    11,   170,    12,
     144,   144,  -111,  -111,   143,   143,   204,  -111,   204,     0,
    -111,  -111,  -111,  -111,    89,    93,    97,  -111,   112,   112,
     102,   102,   102,   185,   245,  -111,   245,   245,   245,   245,
     245,   245,   200,  -111,  -111,  -111,   118,   118,  -111,  -111,
    -111,  -111,  -111,   165,  -111,   245,     7,   186,  -111,    38,
     169,   -14,  -111,  -111,  -111,   192,   144,  -111,    38,  -111,
     166,  -111,  -111,  -111,  -111,  -111,  -111,    90,  -111,   171,
     174,  -111,  -111,  -111,   162,  -111,  -111,  -111,   187,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,    82,     0,     0,     4,     6,     5,
       2,     0,     9,    12,    13,    14,    10,    11,     0,    28,
      81,     9,    12,    13,    14,    10,    11,     0,     0,     0,
       0,    83,     0,    85,    86,     0,    18,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     8,     7,
       0,     0,     0,    45,    44,    48,    49,     0,     0,     0,
       0,   102,     0,     0,    53,    54,     0,    89,    65,    66,
       0,    91,    73,    74,    90,    87,    88,     0,     0,     0,
       0,     0,    15,     0,    77,    29,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,    92,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,     0,   101,     0,    16,     0,     0,
      78,    32,    46,    47,     0,     0,     0,    41,    35,    36,
      37,    38,    39,    40,   103,    55,    59,    60,    61,    62,
      63,    64,    57,    56,    67,    72,    68,    69,    70,    71,
      75,    76,    82,    98,   100,    93,     0,     0,    80,     0,
      19,     0,    50,    51,    52,     0,     0,    94,     0,    79,
       0,    17,    30,    33,    34,    97,    99,     0,    20,     0,
       0,    22,    31,    25,     0,    23,    26,    27,     0,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,   -35,    -4,   -81,  -111,  -111,    59,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,   -33,
     -30,   -65,   -42,  -111,    39,  -111,    69,    70,  -111,  -110,
    -111,  -111,   140
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   128,    30,     7,   189,    51,     8,   180,
     181,   193,   198,   194,     9,    36,   131,   190,   171,    66,
      67,    71,    74,   129,   130,    10,    11,    31,    32,   163,
      33,    34,    62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    18,   127,    80,    61,   113,   119,   124,    75,    76,
       5,   164,    79,    77,    78,   114,   115,   116,   117,    86,
     114,   115,   116,   117,   134,   135,   136,    92,    82,    83,
      84,    19,   125,   102,   110,   111,   182,   110,   111,   100,
      68,   101,    81,   123,    72,    69,   169,    73,   170,   156,
     157,   158,   159,   100,     3,   177,    35,   155,    70,    38,
     138,   139,   140,   141,   142,   143,   186,   144,    48,    49,
      37,   146,   147,   148,   149,   150,   151,   161,    39,   120,
     152,   153,   121,    93,    94,    95,    96,    97,    98,    99,
     183,   165,    61,    93,    94,    95,    96,    97,    98,    99,
     114,   115,   116,   117,   114,   115,   116,   117,   114,   115,
     116,   117,     4,   196,   110,   111,     5,     6,    98,    99,
     122,    40,   167,    41,   168,    95,    96,    97,    98,    99,
     137,   116,   117,    52,    43,    82,    83,   172,    63,    42,
      46,   173,    44,   187,    87,   174,    88,    53,    64,    54,
      52,    45,    47,    89,    65,    52,    90,    55,    56,    57,
      58,    59,    85,    91,    53,   103,    54,   112,    60,    53,
      72,    54,   118,    73,    55,    56,    57,    58,    59,    55,
      56,    57,    58,    59,   119,    60,   126,   126,   132,   133,
      60,   145,    21,   162,   154,    22,    23,    24,    25,    26,
     160,    20,    99,    27,   111,    28,    29,   176,   179,   178,
      21,   188,   195,    22,    23,    24,    25,    26,   -21,   192,
     191,    27,    21,    28,    29,    22,    23,    24,    25,    26,
     184,   175,   199,    27,    12,    28,    29,    13,    14,    15,
      16,    17,   185,   104,   105,   106,   107,   108,   109,    93,
      94,    95,    96,    97,    98,    99,    93,    94,    95,    96,
      97,    98,    99,     0,   197,   166
};

static const yytype_int16 yycheck[] =
{
      35,     5,    83,    45,    37,    70,    11,    22,    41,    42,
      24,   121,    45,    43,    44,    11,    12,    13,    14,    52,
      11,    12,    13,    14,    89,    90,    91,    60,    45,    46,
      47,    30,    47,    63,     3,     4,    50,     3,     4,    46,
      29,    48,    46,    48,    32,    34,    46,    35,    48,   114,
     115,   116,   117,    46,     0,    48,    23,    48,    47,    22,
      93,    94,    95,    96,    97,    98,   176,   100,    30,    31,
      47,   104,   105,   106,   107,   108,   109,   119,    22,    48,
     110,   111,    48,    11,    12,    13,    14,    15,    16,    17,
     171,   124,   125,    11,    12,    13,    14,    15,    16,    17,
      11,    12,    13,    14,    11,    12,    13,    14,    11,    12,
      13,    14,    20,   194,     3,     4,    24,    25,    16,    17,
      48,    22,   126,    22,   128,    13,    14,    15,    16,    17,
      48,    13,    14,    12,    47,    45,    46,    48,    17,    22,
      18,    48,    47,   178,    18,    48,    18,    26,    27,    28,
      12,    47,    45,    47,    33,    12,    47,    36,    37,    38,
      39,    40,    49,    47,    26,    18,    28,    18,    47,    26,
      32,    28,    18,    35,    36,    37,    38,    39,    40,    36,
      37,    38,    39,    40,    11,    47,    24,    24,    30,    30,
      47,    30,    30,    49,    30,    33,    34,    35,    36,    37,
      30,    21,    17,    41,     4,    43,    44,    42,   169,    23,
      30,    45,    50,    33,    34,    35,    36,    37,    49,    45,
      49,    41,    30,    43,    44,    33,    34,    35,    36,    37,
     171,   162,    45,    41,    30,    43,    44,    33,    34,    35,
      36,    37,    50,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    11,    12,    13,    14,
      15,    16,    17,    -1,   194,   125
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    52,    53,     0,    20,    24,    25,    56,    59,    65,
      76,    77,    30,    33,    34,    35,    36,    37,    55,    30,
      21,    30,    33,    34,    35,    36,    37,    41,    43,    44,
      55,    78,    79,    81,    82,    23,    66,    47,    22,    22,
      22,    22,    22,    47,    47,    47,    18,    45,    30,    31,
      54,    58,    12,    26,    28,    36,    37,    38,    39,    40,
      47,    70,    83,    17,    27,    33,    70,    71,    29,    34,
      47,    72,    32,    35,    73,    70,    70,    71,    71,    70,
      73,    55,    45,    46,    47,    49,    70,    18,    18,    47,
      47,    47,    70,    11,    12,    13,    14,    15,    16,    17,
      46,    48,    71,    18,     5,     6,     7,     8,     9,    10,
       3,     4,    18,    72,    11,    12,    13,    14,    18,    11,
      48,    48,    48,    48,    22,    47,    24,    56,    54,    74,
      75,    67,    30,    30,    72,    72,    72,    48,    70,    70,
      70,    70,    70,    70,    70,    30,    70,    70,    70,    70,
      70,    70,    71,    71,    30,    48,    72,    72,    72,    72,
      30,    73,    49,    80,    80,    70,    83,    55,    55,    46,
      48,    69,    48,    48,    48,    77,    42,    48,    23,    75,
      60,    61,    50,    56,    59,    50,    80,    54,    45,    57,
      68,    49,    45,    62,    64,    50,    56,    78,    63,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    58,    60,
      59,    61,    62,    63,    59,    64,    64,    64,    66,    67,
      68,    65,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    73,    74,    74,    74,
      75,    76,    77,    77,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    80,    81,    81,
      82,    83,    83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     6,     0,     0,     0,
       9,     0,     0,     0,    15,     0,     2,     2,     0,     0,
       0,    10,     0,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     3,     3,     1,     1,
       4,     4,     4,     1,     1,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     1,     1,     3,     3,     0,     1,     3,
       2,     3,     0,     2,     2,     1,     1,     3,     3,     3,
       3,     3,     4,     5,     6,     4,     4,     3,     5,     7,
       5,     0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* progr: declarations main  */
#line 77 "language.y"
                           {if (errorCount == 0) cout<< "The program is correct!" << endl;}
#line 1571 "language.tab.c"
    break;

  case 7: /* TYPENAME: TYPE  */
#line 85 "language.y"
                { (yyval.Str) = (yyvsp[0].Str); }
#line 1577 "language.tab.c"
    break;

  case 8: /* TYPENAME: ID  */
#line 86 "language.y"
               { (yyval.Str) = (yyvsp[0].Str); }
#line 1583 "language.tab.c"
    break;

  case 9: /* ANYID: ID  */
#line 89 "language.y"
                 { (yyval.Str) = (yyvsp[0].Str); }
#line 1589 "language.tab.c"
    break;

  case 10: /* ANYID: ID_INT  */
#line 90 "language.y"
                 { (yyval.Str) = (yyvsp[0].Str); }
#line 1595 "language.tab.c"
    break;

  case 11: /* ANYID: ID_FLOAT  */
#line 91 "language.y"
                 { (yyval.Str) = (yyvsp[0].Str); }
#line 1601 "language.tab.c"
    break;

  case 12: /* ANYID: ID_BOOL  */
#line 92 "language.y"
                 { (yyval.Str) = (yyvsp[0].Str); }
#line 1607 "language.tab.c"
    break;

  case 13: /* ANYID: ID_COM  */
#line 93 "language.y"
                 { (yyval.Str) = (yyvsp[0].Str); }
#line 1613 "language.tab.c"
    break;

  case 14: /* ANYID: ID_STR  */
#line 94 "language.y"
                 { (yyval.Str) = (yyvsp[0].Str); }
#line 1619 "language.tab.c"
    break;

  case 15: /* decl: SUMMON ANYID AS TYPENAME ';'  */
#line 97 "language.y"
                                           { 
                              if(!current->existsId((yyvsp[-3].Str))) {
                                   string* s = new string("var");
                                   current->addSym((yyvsp[-1].Str),(yyvsp[-3].Str), s);
                                   SymTable* classTable = current->getClassScope((yyvsp[-1].Str));
                                   if(classTable) {
                                        current->setClassScopeForId((yyvsp[-3].Str), classTable);
        }
                                    delete (yyvsp[-1].Str); delete (yyvsp[-3].Str); delete s;
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                                   delete (yyvsp[-1].Str); delete (yyvsp[-3].Str);
                              }
                          }
#line 1639 "language.tab.c"
    break;

  case 16: /* decl: SUMMON ANYID AS TYPENAME ',' decl  */
#line 112 "language.y"
                                                   { 
                              if(!current->existsId((yyvsp[-4].Str))) {
                                   string* s = new string("var");
                                   current->addSym((yyvsp[-2].Str), (yyvsp[-4].Str), s);
                                   SymTable* classTable = current->getClassScope((yyvsp[-2].Str));
                                   if(classTable) {
                                         current->setClassScopeForId((yyvsp[-4].Str), classTable);
                                      }
        
                                   delete (yyvsp[-2].Str); delete (yyvsp[-4].Str); delete s;
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                                   delete (yyvsp[-2].Str); delete (yyvsp[-4].Str);
                              }
                          }
#line 1660 "language.tab.c"
    break;

  case 17: /* newscopefunc: %empty  */
#line 129 "language.y"
             {
                    SymTable* newScope = new SymTable("func", current);
                    symTables.push_back(newScope);
                    current = newScope;
                 }
#line 1670 "language.tab.c"
    break;

  case 18: /* newscopeclass: %empty  */
#line 135 "language.y"
              {
                    SymTable* newScope = new SymTable("class", current);
                    symTables.push_back(newScope);
                    current = newScope;
                 }
#line 1680 "language.tab.c"
    break;

  case 19: /* $@1: %empty  */
#line 142 "language.y"
                                                      {
                    if(!current->existsId((yyvsp[-5].Str))) {
                         string* s = new string("func");
                         vector<string> paramTypes;
                         for(auto p : *(yyvsp[-1].ParamList)) {
                             paramTypes.push_back(p->type);
                         }
                         current->addSym((yyvsp[-3].Str),(yyvsp[-5].Str), s, paramTypes);
                         delete (yyvsp[-3].Str); delete (yyvsp[-5].Str); delete s;
                    } else {
                         errorCount++; 
                         yyerror("Function already defined");
                         delete (yyvsp[-3].Str); delete (yyvsp[-5].Str);
                    }
                    //cleanup unused params
                    vector<Param*>* params = (yyvsp[-1].ParamList);
                    for(size_t i = 0; i < params->size(); i++) {
                        for(size_t j = i + 1; j < params->size(); j++) {
                            if(params->at(i)->name == params->at(j)->name) {
                                errorCount++;
                                string msg = "Duplicate parameter '" + params->at(i)->name + "' in function declaration";
                                yyerror(msg.c_str());
                            }
                        }
                    }
                    for(auto p : *params) delete p;
                    delete params;
          }
#line 1713 "language.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 172 "language.y"
                                                             {
                    if(!current->existsId((yyvsp[-5].Str))) {
                         string* s = new string("func");
                         vector<string> paramTypes;
                         for(auto p : *(yyvsp[-1].ParamList)) {
                             paramTypes.push_back(p->type);
                         }
                         current->addSym((yyvsp[-3].Str),(yyvsp[-5].Str), s, paramTypes);
                         delete (yyvsp[-3].Str); delete (yyvsp[-5].Str); delete s;
                    } else {
                         errorCount++; 
                         yyerror("Function already defined");
                         delete (yyvsp[-3].Str); delete (yyvsp[-5].Str);
                    }
              }
#line 1733 "language.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 188 "language.y"
              {
                    //add params in the func scope
                    vector<Param*>* params = (yyvsp[-4].ParamList);
                    for(auto p : *params) {
                        if(!current->existsId(&p->name)) {
                            string* s = new string("param");
                            current->addSym(&p->type, &p->name, s);
                            delete s;
                        } else {
                            errorCount++; 
                            yyerror("Parameter already defined in function scope");     
                        }
                        delete p;
                    }
                    delete params;
              }
#line 1754 "language.tab.c"
    break;

  case 23: /* $@4: %empty  */
#line 204 "language.y"
                             {current = current->getParent();}
#line 1760 "language.tab.c"
    break;

  case 28: /* $@5: %empty  */
#line 212 "language.y"
                     {
                         if(!current->existsId((yyvsp[0].Str))) {
                              string* s = new string("class");
                              current->addSym(s,(yyvsp[0].Str), s);
                              tempClassName = new string(*(yyvsp[0].Str));
                              delete (yyvsp[0].Str); delete s;
                              
                         } else {
                               errorCount++; 
                               yyerror("Class already defined");
                               delete (yyvsp[0].Str);
                         }
          }
#line 1778 "language.tab.c"
    break;

  case 29: /* $@6: %empty  */
#line 227 "language.y"
          {
                  if(tempClassName) {
                  SymTable* parentScope = current->getParent();
                  if(parentScope) {
                      parentScope->setClassScopeForId(tempClassName, current);
                  }
                  delete tempClassName;
                  tempClassName = NULL;
              }

          }
#line 1794 "language.tab.c"
    break;

  case 30: /* $@7: %empty  */
#line 239 "language.y"
          {current = current->getParent();}
#line 1800 "language.tab.c"
    break;

  case 35: /* exp: exp '+' exp  */
#line 247 "language.y"
                    {//NOT relevant WILL need to change later into smth like $$ = new ASTNode("+", $1, $3);
                    //not necessary to delete rn but will be deleted later for part4 
     (yyval.Float) = (yyvsp[-2].Float) + (yyvsp[0].Float); }
#line 1808 "language.tab.c"
    break;

  case 36: /* exp: exp '-' exp  */
#line 250 "language.y"
                   {(yyval.Float) = (yyvsp[-2].Float) - (yyvsp[0].Float);}
#line 1814 "language.tab.c"
    break;

  case 37: /* exp: exp '*' exp  */
#line 251 "language.y"
                    {(yyval.Float) = (yyvsp[-2].Float) * (yyvsp[0].Float);}
#line 1820 "language.tab.c"
    break;

  case 38: /* exp: exp '/' exp  */
#line 252 "language.y"
                   {(yyval.Float) = (yyvsp[-2].Float) / (yyvsp[0].Float);}
#line 1826 "language.tab.c"
    break;

  case 39: /* exp: exp '%' exp  */
#line 253 "language.y"
                   {(yyval.Float) = (int)(yyvsp[-2].Float) % (int)(yyvsp[0].Float);}
#line 1832 "language.tab.c"
    break;

  case 40: /* exp: exp '^' exp  */
#line 254 "language.y"
                   {(yyval.Float) = pow((yyvsp[-2].Float),(yyvsp[0].Float));}
#line 1838 "language.tab.c"
    break;

  case 41: /* exp: '(' exp ')'  */
#line 255 "language.y"
                   { (yyval.Float) = (yyvsp[-1].Float); }
#line 1844 "language.tab.c"
    break;

  case 42: /* exp: exp '!'  */
#line 256 "language.y"
              {(yyval.Float) = 1; for(int i=1;i<=(yyvsp[-1].Float);i++) (yyval.Float) *= i;}
#line 1850 "language.tab.c"
    break;

  case 43: /* exp: '-' exp  */
#line 257 "language.y"
                            { (yyval.Float) = -(yyvsp[0].Float); }
#line 1856 "language.tab.c"
    break;

  case 44: /* exp: QAT  */
#line 258 "language.y"
           { (yyval.Float) = (yyvsp[0].Float); }
#line 1862 "language.tab.c"
    break;

  case 45: /* exp: ZAT  */
#line 259 "language.y"
           { (yyval.Float) = (yyvsp[0].Int); }
#line 1868 "language.tab.c"
    break;

  case 46: /* exp: ID_INT OF ID  */
#line 260 "language.y"
                    { 
     // Verificăm că obiectul există
     if(!current->existsId((yyvsp[0].Str))) {
        errorCount++;
        string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
        yyerror(msg.c_str());
     }
     // Verificăm că field-ul există în clasă
     else {
        IdInfo* objInfo = current->getId((yyvsp[0].Str));
        if(objInfo && objInfo->classScope && !objInfo->classScope->existsId((yyvsp[-2].Str))) {
            errorCount++;
            string msg = "Field '" + *(yyvsp[-2].Str) + "' does not exist in class";
            yyerror(msg.c_str());
        }
     }
     (yyval.Float) = 0; 
     delete (yyvsp[-2].Str); delete (yyvsp[0].Str); 
     }
#line 1892 "language.tab.c"
    break;

  case 47: /* exp: ID_FLOAT OF ID  */
#line 279 "language.y"
                      { 
     if(!current->existsId((yyvsp[0].Str))) {
        errorCount++;
        string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
        yyerror(msg.c_str());
     }
     else {
        IdInfo* objInfo = current->getId((yyvsp[0].Str));
        if(objInfo && objInfo->classScope && !objInfo->classScope->existsId((yyvsp[-2].Str))) {
            errorCount++;
            string msg = "Field '" + *(yyvsp[-2].Str) + "' does not exist in class";
            yyerror(msg.c_str());
        }
     }
     (yyval.Float) = 0; 
     delete (yyvsp[-2].Str); delete (yyvsp[0].Str); 
     }
#line 1914 "language.tab.c"
    break;

  case 48: /* exp: ID_INT  */
#line 296 "language.y"
              { 
     if(!current->existsId((yyvsp[0].Str))) {
        errorCount++;
        string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
        yyerror(msg.c_str());
     }
     (yyval.Float) = 0; 
     delete (yyvsp[0].Str); 
     }
#line 1928 "language.tab.c"
    break;

  case 49: /* exp: ID_FLOAT  */
#line 305 "language.y"
                { 
     if(!current->existsId((yyvsp[0].Str))) {
        errorCount++;
        string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
        yyerror(msg.c_str());
     }
     (yyval.Float) = 0; 
     delete (yyvsp[0].Str); 
     }
#line 1942 "language.tab.c"
    break;

  case 50: /* exp: MAG '(' cexp ')'  */
#line 315 "language.y"
                         { (yyval.Float) = sqrt(pow((yyvsp[-1].Comp).real, 2) + pow((yyvsp[-1].Comp).imag, 2)); }
#line 1948 "language.tab.c"
    break;

  case 51: /* exp: REAL '(' cexp ')'  */
#line 316 "language.y"
                         { (yyval.Float) = (yyvsp[-1].Comp).real; }
#line 1954 "language.tab.c"
    break;

  case 52: /* exp: IMAG '(' cexp ')'  */
#line 317 "language.y"
                         { (yyval.Float) = (yyvsp[-1].Comp).imag; }
#line 1960 "language.tab.c"
    break;

  case 53: /* bexp: BOOL  */
#line 320 "language.y"
            { (yyval.Bool) = (yyvsp[0].Bool); }
#line 1966 "language.tab.c"
    break;

  case 54: /* bexp: ID_BOOL  */
#line 321 "language.y"
               {
     if(!current->existsId((yyvsp[0].Str))) {
        errorCount++;
        string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
        yyerror(msg.c_str());
     }
     (yyval.Bool) = false; 
     delete (yyvsp[0].Str); 
     }
#line 1980 "language.tab.c"
    break;

  case 55: /* bexp: ID_BOOL OF ID  */
#line 330 "language.y"
                     { 
     if(!current->existsId((yyvsp[0].Str))) {
        errorCount++;
        string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
        yyerror(msg.c_str());
     }
     else {
        IdInfo* objInfo = current->getId((yyvsp[0].Str));
        if(objInfo && objInfo->classScope && !objInfo->classScope->existsId((yyvsp[-2].Str))) {
            errorCount++;
            string msg = "Field '" + *(yyvsp[-2].Str) + "' does not exist in class";
            yyerror(msg.c_str());
        }
     }
     (yyval.Bool) = false; 
     delete (yyvsp[-2].Str); delete (yyvsp[0].Str); 
     }
#line 2002 "language.tab.c"
    break;

  case 56: /* bexp: bexp AND bexp  */
#line 347 "language.y"
                     { (yyval.Bool) = (yyvsp[-2].Bool) && (yyvsp[0].Bool); }
#line 2008 "language.tab.c"
    break;

  case 57: /* bexp: bexp OR bexp  */
#line 348 "language.y"
                    { (yyval.Bool) = (yyvsp[-2].Bool) || (yyvsp[0].Bool); }
#line 2014 "language.tab.c"
    break;

  case 58: /* bexp: '!' bexp  */
#line 349 "language.y"
                { (yyval.Bool) = !(yyvsp[0].Bool); }
#line 2020 "language.tab.c"
    break;

  case 59: /* bexp: exp '<' exp  */
#line 350 "language.y"
                   { (yyval.Bool) = (yyvsp[-2].Float) < (yyvsp[0].Float); }
#line 2026 "language.tab.c"
    break;

  case 60: /* bexp: exp '>' exp  */
#line 351 "language.y"
                   { (yyval.Bool) = (yyvsp[-2].Float) > (yyvsp[0].Float); }
#line 2032 "language.tab.c"
    break;

  case 61: /* bexp: exp LEQ exp  */
#line 352 "language.y"
                   { (yyval.Bool) = (yyvsp[-2].Float) <= (yyvsp[0].Float); }
#line 2038 "language.tab.c"
    break;

  case 62: /* bexp: exp GEQ exp  */
#line 353 "language.y"
                   { (yyval.Bool) = (yyvsp[-2].Float) >= (yyvsp[0].Float); }
#line 2044 "language.tab.c"
    break;

  case 63: /* bexp: exp EQ exp  */
#line 354 "language.y"
                  { (yyval.Bool) = (yyvsp[-2].Float) == (yyvsp[0].Float); }
#line 2050 "language.tab.c"
    break;

  case 64: /* bexp: exp NEQ exp  */
#line 355 "language.y"
                   { (yyval.Bool) = (yyvsp[-2].Float) != (yyvsp[0].Float); }
#line 2056 "language.tab.c"
    break;

  case 65: /* cexp: CAT  */
#line 358 "language.y"
           { (yyval.Comp).real = 0; (yyval.Comp).imag = (yyvsp[0].Float); }
#line 2062 "language.tab.c"
    break;

  case 66: /* cexp: ID_COM  */
#line 359 "language.y"
              { 
     if(!current->existsId((yyvsp[0].Str))) {
        errorCount++;
        string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
        yyerror(msg.c_str());
     }
     (yyval.Comp).real = 0; (yyval.Comp).imag = 0; 
     delete (yyvsp[0].Str); 
     }
#line 2076 "language.tab.c"
    break;

  case 67: /* cexp: ID_COM OF ID  */
#line 368 "language.y"
                    { 
     if(!current->existsId((yyvsp[0].Str))) {
        errorCount++;
        string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
        yyerror(msg.c_str());
     }
     else {
        IdInfo* objInfo = current->getId((yyvsp[0].Str));
        if(objInfo && objInfo->classScope && !objInfo->classScope->existsId((yyvsp[-2].Str))) {
            errorCount++;
            string msg = "Field '" + *(yyvsp[-2].Str) + "' does not exist in class";
            yyerror(msg.c_str());
        }
     }
     (yyval.Comp).real = 0; (yyval.Comp).imag = 0; 
     delete (yyvsp[-2].Str); delete (yyvsp[0].Str); 
     }
#line 2098 "language.tab.c"
    break;

  case 68: /* cexp: cexp '+' cexp  */
#line 385 "language.y"
                     { (yyval.Comp).real = (yyvsp[-2].Comp).real + (yyvsp[0].Comp).real; (yyval.Comp).imag = (yyvsp[-2].Comp).imag + (yyvsp[0].Comp).imag; }
#line 2104 "language.tab.c"
    break;

  case 69: /* cexp: cexp '-' cexp  */
#line 386 "language.y"
                     { (yyval.Comp).real = (yyvsp[-2].Comp).real - (yyvsp[0].Comp).real; (yyval.Comp).imag = (yyvsp[-2].Comp).imag - (yyvsp[0].Comp).imag; }
#line 2110 "language.tab.c"
    break;

  case 70: /* cexp: cexp '*' cexp  */
#line 387 "language.y"
                     { //DOES NOT NEED  () 
          // 10+0i * 2+3i is accepted by this language as (10+0i)*(2+3i)
          (yyval.Comp).real = ((yyvsp[-2].Comp).real * (yyvsp[0].Comp).real) - ((yyvsp[-2].Comp).imag * (yyvsp[0].Comp).imag);
          (yyval.Comp).imag = ((yyvsp[-2].Comp).real * (yyvsp[0].Comp).imag) + ((yyvsp[-2].Comp).imag * (yyvsp[0].Comp).real);
     }
#line 2120 "language.tab.c"
    break;

  case 71: /* cexp: cexp '/' cexp  */
#line 392 "language.y"
                     { 
          float denom = ((yyvsp[0].Comp).real * (yyvsp[0].Comp).real) + ((yyvsp[0].Comp).imag * (yyvsp[0].Comp).imag);
          (yyval.Comp).real = (((yyvsp[-2].Comp).real * (yyvsp[0].Comp).real) + ((yyvsp[-2].Comp).imag * (yyvsp[0].Comp).imag)) / denom;
          (yyval.Comp).imag = (((yyvsp[-2].Comp).imag * (yyvsp[0].Comp).real) - ((yyvsp[-2].Comp).real * (yyvsp[0].Comp).imag)) / denom;
     }
#line 2130 "language.tab.c"
    break;

  case 72: /* cexp: '(' cexp ')'  */
#line 397 "language.y"
                    { (yyval.Comp).real = (yyvsp[-1].Comp).real; (yyval.Comp).imag = (yyvsp[-1].Comp).imag; }
#line 2136 "language.tab.c"
    break;

  case 73: /* stexp: STRING  */
#line 400 "language.y"
               { (yyval.Str) = (yyvsp[0].Str); }
#line 2142 "language.tab.c"
    break;

  case 74: /* stexp: ID_STR  */
#line 401 "language.y"
              { 
     if(!current->existsId((yyvsp[0].Str))) {
        errorCount++;
        string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
        yyerror(msg.c_str());
     }     
     (yyval.Str) = new string(""); 
     delete (yyvsp[0].Str); 
     }
#line 2156 "language.tab.c"
    break;

  case 75: /* stexp: ID_STR OF ID  */
#line 410 "language.y"
                    { 
     if(!current->existsId((yyvsp[0].Str))) {
        errorCount++;
        string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
        yyerror(msg.c_str());
     }
     else {
        IdInfo* objInfo = current->getId((yyvsp[0].Str));
        if(objInfo && objInfo->classScope && !objInfo->classScope->existsId((yyvsp[-2].Str))) {
            errorCount++;
            string msg = "Field '" + *(yyvsp[-2].Str) + "' does not exist in class";
            yyerror(msg.c_str());
        }
     }
     (yyval.Str) = new string(""); 
     delete (yyvsp[-2].Str); delete (yyvsp[0].Str); 
     }
#line 2178 "language.tab.c"
    break;

  case 76: /* stexp: stexp '+' stexp  */
#line 427 "language.y"
                       { (yyval.Str) = new string(*(yyvsp[-2].Str) + *(yyvsp[0].Str)); delete (yyvsp[-2].Str); delete (yyvsp[0].Str); }
#line 2184 "language.tab.c"
    break;

  case 77: /* list_param: %empty  */
#line 431 "language.y"
          {
          (yyval.ParamList)= new vector<Param*>();
          }
#line 2192 "language.tab.c"
    break;

  case 78: /* list_param: param  */
#line 435 "language.y"
          {
               (yyval.ParamList)= new vector<Param*>();
               (yyval.ParamList)->push_back((yyvsp[0].Param));
          }
#line 2201 "language.tab.c"
    break;

  case 79: /* list_param: list_param ',' param  */
#line 440 "language.y"
          {
               (yyval.ParamList) = (yyvsp[-2].ParamList); //og vector and add new param to the end ($3)
               (yyval.ParamList)->push_back((yyvsp[0].Param));
          }
#line 2210 "language.tab.c"
    break;

  case 80: /* param: TYPENAME ANYID  */
#line 447 "language.y"
     {
         (yyval.Param) = new Param();
         (yyval.Param)->type = *(yyvsp[-1].Str);
         (yyval.Param)->name = *(yyvsp[0].Str);
         delete (yyvsp[-1].Str); delete (yyvsp[0].Str);
     }
#line 2221 "language.tab.c"
    break;

  case 92: /* simple_statement: ID '(' call_list ')'  */
#line 480 "language.y"
                           { 
     if(!current->existsId((yyvsp[-3].Str))) {
        errorCount++;
        string msg = "Function '" + *(yyvsp[-3].Str) + "' not defined";
        yyerror(msg.c_str());
     }
     delete (yyvsp[-3].Str); 
     }
#line 2234 "language.tab.c"
    break;

  case 93: /* simple_statement: ANYID OF ANYID ASSIGN exp  */
#line 488 "language.y"
                                {
        // ANYID permite orice tip de ID (ID, ID_INT, ID_FLOAT, etc.)
        if(!current->existsId((yyvsp[-2].Str))) {
            errorCount++;
            yyerror("Object not defined");
        } else {
            IdInfo* info = current->getId((yyvsp[-2].Str));
            string objType = current->getType((yyvsp[-2].Str));
            
            if (!info->classScope) {
                errorCount++;
                string msg = "Variable '" + *(yyvsp[-2].Str) + "' is not a class instance";
                yyerror(msg.c_str());
            }
            else if (!info->classScope->existsId((yyvsp[-4].Str))) {
                errorCount++;
                string msg = "Field '" + *(yyvsp[-4].Str) + "' does not exist in class '" + objType + "'";
                yyerror(msg.c_str());
            }
        }
        delete (yyvsp[-4].Str); delete (yyvsp[-2].Str);
    }
#line 2261 "language.tab.c"
    break;

  case 94: /* simple_statement: ANYID OF ANYID '(' call_list ')'  */
#line 510 "language.y"
                                       {
        if(!current->existsId((yyvsp[-3].Str))) {
            errorCount++;
            yyerror("Object not defined");
        } else {
            IdInfo* info = current->getId((yyvsp[-3].Str));
            string objType = current->getType((yyvsp[-3].Str));
            
            if (!info->classScope) {
                errorCount++;
                string msg = "Variable '" + *(yyvsp[-3].Str) + "' is not a class instance";
                yyerror(msg.c_str());
            }
            else if (!info->classScope->existsId((yyvsp[-5].Str))) {
                errorCount++;
                string msg = "Method '" + *(yyvsp[-5].Str) + "' does not exist in class '" + objType + "'";
                yyerror(msg.c_str());
            }
        }
        delete (yyvsp[-5].Str); delete (yyvsp[-3].Str);
    }
#line 2287 "language.tab.c"
    break;


#line 2291 "language.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 553 "language.y"

void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     current = new SymTable("global");

     symTables.push_back(current); //new here
     yyparse();
     //deallocate memory symtable vector
     freopen("tables.txt", "w", stdout);
     cout << "Variables:" <<endl;
     //current->printVars(); change here
     //delete current;
     for(auto table : symTables){
         table->printVars();
         delete table;
     }
}
