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
#line 42 "language.y"

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
  YYSYMBOL_fundecl = 57,                   /* fundecl  */
  YYSYMBOL_58_1 = 58,                      /* $@1  */
  YYSYMBOL_59_2 = 59,                      /* $@2  */
  YYSYMBOL_60_3 = 60,                      /* $@3  */
  YYSYMBOL_61_4 = 61,                      /* $@4  */
  YYSYMBOL_insidefunc = 62,                /* insidefunc  */
  YYSYMBOL_classdecl = 63,                 /* classdecl  */
  YYSYMBOL_64_5 = 64,                      /* $@5  */
  YYSYMBOL_65_6 = 65,                      /* $@6  */
  YYSYMBOL_66_7 = 66,                      /* $@7  */
  YYSYMBOL_class_body = 67,                /* class_body  */
  YYSYMBOL_typed_exp = 68,                 /* typed_exp  */
  YYSYMBOL_exp = 69,                       /* exp  */
  YYSYMBOL_bexp = 70,                      /* bexp  */
  YYSYMBOL_cexp = 71,                      /* cexp  */
  YYSYMBOL_stexp = 72,                     /* stexp  */
  YYSYMBOL_list_param = 73,                /* list_param  */
  YYSYMBOL_param = 74,                     /* param  */
  YYSYMBOL_main = 75,                      /* main  */
  YYSYMBOL_list = 76,                      /* list  */
  YYSYMBOL_statement = 77,                 /* statement  */
  YYSYMBOL_simple_statement = 78,          /* simple_statement  */
  YYSYMBOL_block = 79,                     /* block  */
  YYSYMBOL_if_statement = 80,              /* if_statement  */
  YYSYMBOL_while_statement = 81,           /* while_statement  */
  YYSYMBOL_call_list_typed = 82            /* call_list_typed  */
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
#define YYLAST   362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

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
       0,    93,    93,    95,    96,    97,    98,   101,   102,   105,
     106,   107,   108,   109,   110,   113,   128,   146,   146,   176,
     197,   212,   176,   216,   217,   218,   220,   239,   250,   220,
     253,   254,   255,   258,   259,   260,   261,   262,   269,   284,
     299,   314,   329,   330,   340,   345,   350,   361,   372,   390,
     408,   414,   420,   428,   433,   444,   454,   464,   474,   490,
     502,   514,   526,   539,   552,   556,   561,   573,   580,   587,
     596,   612,   617,   622,   633,   642,   645,   650,   657,   667,
     670,   671,   675,   676,   677,   681,   689,   697,   705,   714,
     722,   739,   756,   773,   790,   807,   830,   867,   887,   907,
     927,   947,   967,   988,   989,   990,   991,   995,   999,  1000,
    1004,  1007,  1010,  1015
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
  "decl", "fundecl", "$@1", "$@2", "$@3", "$@4", "insidefunc", "classdecl",
  "$@5", "$@6", "$@7", "class_body", "typed_exp", "exp", "bexp", "cexp",
  "stexp", "list_param", "param", "main", "list", "statement",
  "simple_statement", "block", "if_statement", "while_statement",
  "call_list_typed", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-142)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-20)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -142,    33,   152,  -142,  -142,   174,    29,  -142,  -142,  -142,
    -142,   290,  -142,  -142,  -142,  -142,  -142,  -142,    51,  -142,
    -142,     2,    -3,    48,   156,   215,   216,    60,    63,    70,
    -142,    83,  -142,  -142,    -8,    98,   120,   158,   190,   236,
     219,   111,   220,     3,   230,   254,   237,   254,   236,   236,
     189,  -142,  -142,  -142,   167,  -142,    20,   254,   236,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,   153,   164,
     172,   196,   224,   218,  -142,   348,    61,   228,   267,     8,
      40,   236,   348,    61,    46,   111,   228,    94,   267,    96,
     254,   273,   134,   273,     0,     5,    71,    10,   101,    -4,
    -142,   257,    -8,  -142,   158,   158,  -142,  -142,   258,   259,
     111,   111,   111,   125,    13,   109,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   236,   236,   111,   111,
     111,   111,     3,   158,  -142,   158,   158,   158,   158,   158,
     158,   158,   158,   113,   158,   158,   250,   250,  -142,  -142,
    -142,  -142,   174,  -142,   174,   154,  -142,     1,  -142,   213,
    -142,  -142,   141,   151,   155,  -142,  -142,  -142,   273,   273,
     273,   273,   273,   273,   146,   146,  -142,  -142,   299,  -142,
     166,   166,  -142,  -142,  -142,  -142,  -142,   222,  -142,   231,
    -142,   249,  -142,   252,  -142,   264,  -142,   262,  -142,   291,
    -142,    -8,   268,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,   302,   250,    -8,  -142,   274,
     269,   276,  -142,  -142,   186,  -142,  -142,  -142,  -142,   272,
    -142,  -142,  -142,   283,  -142
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,    80,     0,     0,     4,     6,     5,
       2,     0,     9,    12,    13,    14,    10,    11,     0,    26,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,    83,    84,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     8,     7,     0,    27,     0,     0,     0,    45,
      53,    44,    65,    37,    72,    54,    66,    73,    46,    47,
       0,     0,     0,     0,   112,    33,    34,    35,    36,     0,
       0,     0,     0,    87,     0,     0,    89,     0,    88,     0,
       0,    85,     0,    86,     0,     0,     0,     0,     0,     0,
      15,     0,    75,    30,     0,   111,    43,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,     0,   111,     0,   111,     0,
     111,     0,   111,     0,     0,   111,     0,     0,   103,   106,
     105,   104,     0,    16,     0,     0,    76,     0,    90,     0,
      48,    49,     0,     0,     0,    42,    64,    71,    58,    59,
      60,    61,    62,    63,    38,    39,    40,    41,    56,    55,
      67,    68,    69,    70,    74,   113,    93,     0,    94,     0,
      95,     0,    91,     0,    92,     0,    80,   108,   110,     0,
      78,     0,    17,    28,    31,    32,    97,    50,    51,    52,
     100,   101,   102,    98,    99,     0,     0,     0,    77,     0,
       0,     0,   107,   109,     0,    18,    20,    29,    23,     0,
      21,    24,    25,     0,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,  -142,   -34,   -66,  -100,   173,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,   -94,   -21,   -18,
     -39,   -38,  -142,   128,  -142,   144,   112,  -142,  -141,  -142,
    -142,     6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   154,    18,     7,     8,   219,   220,   228,
     233,   229,     9,    35,   103,   221,   157,    74,    75,    76,
      77,    78,   155,   156,    10,    11,    30,    31,   197,    32,
      33,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   153,    86,   126,   127,    88,   198,   132,   126,   127,
     158,    98,    99,   126,   127,    38,   126,   127,    82,    39,
      36,    83,    52,    53,    91,     5,    93,    82,    82,    96,
      94,    95,    97,     3,   115,    64,   106,    82,    67,   185,
     107,   186,   104,   188,   151,   190,   115,   192,   146,    37,
     194,   203,   113,   147,   133,   114,   134,   204,   149,    19,
     113,   166,   135,   114,   126,   127,    40,   105,   137,   143,
      41,   162,   163,   164,    34,   223,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   199,   136,   200,   180,
     181,   182,   183,   138,   184,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,    82,    82,    48,   178,   179,
      49,   159,   128,   129,   130,   131,   139,    50,   141,   148,
     128,   129,   130,   131,   122,   123,   124,   125,    51,   231,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      62,   140,   187,   142,   189,    66,   191,    55,   193,   150,
      56,   195,   128,   129,   130,   131,   144,   167,    85,   124,
     125,   165,   128,   129,   130,   131,   128,   129,   130,   131,
      57,   108,     4,   165,    42,    58,     5,     6,    43,   130,
     131,   145,   109,   224,    59,    60,    61,    62,    63,   207,
      64,    65,    66,    67,    68,    69,    70,    71,    72,   208,
     201,    57,   202,   209,    12,    73,    58,    13,    14,    15,
      16,    17,   100,   101,   102,    59,    60,    61,    62,   110,
      80,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      57,   100,   101,    44,    46,    58,    73,    45,    47,   128,
     129,   130,   131,   111,    59,    60,    61,    62,    57,    84,
      87,    65,    66,    58,    68,    69,    70,    71,    72,   133,
      89,   206,    59,    60,    61,    73,    57,    92,   133,    65,
     210,   112,    68,    69,    70,    71,    72,   133,   132,   211,
      59,   152,    61,    81,   122,   123,   124,   125,   160,   161,
      68,    69,    70,    71,    72,   133,   152,   212,   133,   196,
     213,    90,    21,   127,   216,    22,    23,    24,    25,    26,
     133,    20,   214,    27,   217,    28,    29,   -19,   226,   225,
      21,   227,   230,    22,    23,    24,    25,    26,   234,   218,
     205,    27,    21,    28,    29,    22,    23,    24,    25,    26,
     215,   232,     0,    27,     0,    28,    29,     0,     0,     0,
       0,     0,   222,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125
};

static const yytype_int16 yycheck[] =
{
      34,   101,    41,     3,     4,    43,   147,    11,     3,     4,
     104,    50,    50,     3,     4,    18,     3,     4,    39,    22,
      18,    39,    30,    31,    45,    24,    47,    48,    49,    50,
      48,    49,    50,     0,    73,    32,    57,    58,    35,   133,
      58,   135,    22,   137,    48,   139,    85,   141,    48,    47,
     144,    50,    73,    48,    46,    73,    48,   157,    48,    30,
      81,    48,    22,    81,     3,     4,    18,    47,    22,    90,
      22,   110,   111,   112,    23,   216,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,   152,    47,   154,   128,
     129,   130,   131,    47,   132,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    47,   126,   127,
      47,   105,    11,    12,    13,    14,    22,    47,    22,    48,
      11,    12,    13,    14,    11,    12,    13,    14,    45,   229,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      29,    47,   136,    47,   138,    34,   140,    49,   142,    48,
      30,   145,    11,    12,    13,    14,    22,    48,    47,    13,
      14,    48,    11,    12,    13,    14,    11,    12,    13,    14,
      12,    18,    20,    48,    18,    17,    24,    25,    22,    13,
      14,    47,    18,   217,    26,    27,    28,    29,    30,    48,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    48,
      46,    12,    48,    48,    30,    47,    17,    33,    34,    35,
      36,    37,    45,    46,    47,    26,    27,    28,    29,    47,
      30,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      12,    45,    46,    18,    18,    17,    47,    22,    22,    11,
      12,    13,    14,    47,    26,    27,    28,    29,    12,    30,
      30,    33,    34,    17,    36,    37,    38,    39,    40,    46,
      30,    48,    26,    27,    28,    47,    12,    30,    46,    33,
      48,    47,    36,    37,    38,    39,    40,    46,    11,    48,
      26,    24,    28,    47,    11,    12,    13,    14,    30,    30,
      36,    37,    38,    39,    40,    46,    24,    48,    46,    49,
      48,    47,    30,     4,    42,    33,    34,    35,    36,    37,
      46,    21,    48,    41,    23,    43,    44,    49,    49,    45,
      30,    45,    50,    33,    34,    35,    36,    37,    45,   201,
     157,    41,    30,    43,    44,    33,    34,    35,    36,    37,
     196,   229,    -1,    41,    -1,    43,    44,    -1,    -1,    -1,
      -1,    -1,    50,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    52,    53,     0,    20,    24,    25,    56,    57,    63,
      75,    76,    30,    33,    34,    35,    36,    37,    55,    30,
      21,    30,    33,    34,    35,    36,    37,    41,    43,    44,
      77,    78,    80,    81,    23,    64,    18,    47,    18,    22,
      18,    22,    18,    22,    18,    22,    18,    22,    47,    47,
      47,    45,    30,    31,    54,    49,    30,    12,    17,    26,
      27,    28,    29,    30,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    47,    68,    69,    70,    71,    72,    82,
      30,    47,    69,    70,    30,    47,    71,    30,    72,    30,
      47,    69,    30,    69,    70,    70,    69,    70,    71,    72,
      45,    46,    47,    65,    22,    47,    69,    70,    18,    18,
      47,    47,    47,    69,    70,    71,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     3,     4,    11,    12,
      13,    14,    11,    46,    48,    22,    47,    22,    47,    22,
      47,    22,    47,    69,    22,    47,    48,    48,    48,    48,
      48,    48,    24,    56,    54,    73,    74,    67,    68,    82,
      30,    30,    71,    71,    71,    48,    48,    48,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    71,    71,    72,    68,    68,    82,    68,    82,
      68,    82,    68,    82,    68,    82,    49,    79,    79,    55,
      55,    46,    48,    50,    56,    57,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    76,    42,    23,    74,    58,
      59,    66,    50,    79,    54,    45,    49,    45,    60,    62,
      50,    56,    77,    61,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    56,    56,    58,    57,    59,
      60,    61,    57,    62,    62,    62,    64,    65,    66,    63,
      67,    67,    67,    68,    68,    68,    68,    68,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    71,    71,    71,    71,
      71,    71,    72,    72,    72,    73,    73,    73,    74,    75,
      76,    76,    77,    77,    77,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    80,    80,
      81,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     6,     0,     9,     0,
       0,     0,    14,     0,     2,     2,     0,     0,     0,     9,
       0,     2,     2,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     2,     1,     1,     1,     1,     3,     3,
       4,     4,     4,     1,     1,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     1,     1,     3,     0,     1,     3,     2,     3,
       0,     2,     2,     1,     1,     3,     3,     3,     3,     3,
       5,     5,     5,     5,     5,     5,     4,     6,     6,     6,
       6,     6,     6,     4,     4,     4,     4,     3,     5,     7,
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
#line 93 "language.y"
                           {if (errorCount == 0) cout<< "The program is correct!" << endl;}
#line 1605 "language.tab.c"
    break;

  case 7: /* TYPENAME: TYPE  */
#line 101 "language.y"
                { (yyval.Str) = (yyvsp[0].Str); }
#line 1611 "language.tab.c"
    break;

  case 8: /* TYPENAME: ID  */
#line 102 "language.y"
               { (yyval.Str) = (yyvsp[0].Str); }
#line 1617 "language.tab.c"
    break;

  case 9: /* ANYID: ID  */
#line 105 "language.y"
                 { (yyval.Str) = (yyvsp[0].Str); }
#line 1623 "language.tab.c"
    break;

  case 10: /* ANYID: ID_INT  */
#line 106 "language.y"
                 { (yyval.Str) = (yyvsp[0].Str); }
#line 1629 "language.tab.c"
    break;

  case 11: /* ANYID: ID_FLOAT  */
#line 107 "language.y"
                 { (yyval.Str) = (yyvsp[0].Str); }
#line 1635 "language.tab.c"
    break;

  case 12: /* ANYID: ID_BOOL  */
#line 108 "language.y"
                 { (yyval.Str) = (yyvsp[0].Str); }
#line 1641 "language.tab.c"
    break;

  case 13: /* ANYID: ID_COM  */
#line 109 "language.y"
                 { (yyval.Str) = (yyvsp[0].Str); }
#line 1647 "language.tab.c"
    break;

  case 14: /* ANYID: ID_STR  */
#line 110 "language.y"
                 { (yyval.Str) = (yyvsp[0].Str); }
#line 1653 "language.tab.c"
    break;

  case 15: /* decl: SUMMON ANYID AS TYPENAME ';'  */
#line 113 "language.y"
                                       { 
                            if(!current->existsIdLocal((yyvsp[-3].Str))) {
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
#line 1673 "language.tab.c"
    break;

  case 16: /* decl: SUMMON ANYID AS TYPENAME ',' decl  */
#line 128 "language.y"
                                            { 
                            if(!current->existsIdLocal((yyvsp[-4].Str))) {
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
#line 1694 "language.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 146 "language.y"
                                                      {
                    if(!current->existsIdLocal((yyvsp[-5].Str))) {
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
#line 1727 "language.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 176 "language.y"
                                                             {
                    if(!current->existsIdLocal((yyvsp[-5].Str))) {
                         string* s = new string("func");
                         vector<string> paramTypes;
                         for(auto p : *(yyvsp[-1].ParamList)) {
                             paramTypes.push_back(p->type);
                         }
                         current->addSym((yyvsp[-3].Str), (yyvsp[-5].Str), s, paramTypes);
                         
                         SymTable* newScope = new SymTable((yyvsp[-5].Str)->c_str(), current);
                         symTables.push_back(newScope);
                         current = newScope;

                         delete (yyvsp[-3].Str); delete (yyvsp[-5].Str); delete s;
                    } else {
                         errorCount++; 
                         yyerror("Function already defined");
                         delete (yyvsp[-3].Str); delete (yyvsp[-5].Str);
                    }
              }
#line 1752 "language.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 197 "language.y"
              {
                    vector<Param*>* params = (yyvsp[-3].ParamList);
                    for(auto p : *params) {
                        if(!current->existsIdLocal(&p->name)) {
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
#line 1772 "language.tab.c"
    break;

  case 21: /* $@4: %empty  */
#line 212 "language.y"
                             {current = current->getParent();}
#line 1778 "language.tab.c"
    break;

  case 26: /* $@5: %empty  */
#line 220 "language.y"
                     {
                 if(!current->existsId((yyvsp[0].Str))) {
                      string* s = new string("class");
                      current->addSym(s, (yyvsp[0].Str), s);
                      
                      SymTable* newScope = new SymTable((yyvsp[0].Str)->c_str(), current);
                      symTables.push_back(newScope);
                      
                      tempClassName = new string(*(yyvsp[0].Str));
                      current = newScope;
                      
                      delete (yyvsp[0].Str); delete s;
                 } else {
                       errorCount++; 
                       yyerror("Class already defined");
                       delete (yyvsp[0].Str);
                 }
          }
#line 1801 "language.tab.c"
    break;

  case 27: /* $@6: %empty  */
#line 239 "language.y"
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
#line 1816 "language.tab.c"
    break;

  case 28: /* $@7: %empty  */
#line 250 "language.y"
          { current = current->getParent(); }
#line 1822 "language.tab.c"
    break;

  case 33: /* typed_exp: exp  */
#line 258 "language.y"
                { (yyval.TypedVal) = (yyvsp[0].TypedVal); }
#line 1828 "language.tab.c"
    break;

  case 34: /* typed_exp: bexp  */
#line 259 "language.y"
                 { (yyval.TypedVal) = (yyvsp[0].TypedVal); }
#line 1834 "language.tab.c"
    break;

  case 35: /* typed_exp: cexp  */
#line 260 "language.y"
                 { (yyval.TypedVal) = (yyvsp[0].TypedVal); }
#line 1840 "language.tab.c"
    break;

  case 36: /* typed_exp: stexp  */
#line 261 "language.y"
                  { (yyval.TypedVal) = (yyvsp[0].TypedVal); }
#line 1846 "language.tab.c"
    break;

  case 37: /* typed_exp: ID  */
#line 262 "language.y"
               {
            (yyval.TypedVal)= new TypedValue();
            (yyval.TypedVal)->type = current->getType((yyvsp[0].Str));
            delete (yyvsp[0].Str);
             }
#line 1856 "language.tab.c"
    break;

  case 38: /* exp: exp '+' exp  */
#line 269 "language.y"
                  {
        if((yyvsp[-2].TypedVal)->type != (yyvsp[0].TypedVal)->type) {
            errorCount++;
            string msg = "Type mismatch in addition: " + (yyvsp[-2].TypedVal)->type + " + " + (yyvsp[0].TypedVal)->type;
            yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = (yyvsp[-2].TypedVal)->type;
        if((yyvsp[-2].TypedVal)->type == "int") {
            (yyval.TypedVal)->intVal = (yyvsp[-2].TypedVal)->intVal + (yyvsp[0].TypedVal)->intVal;
        } else if((yyvsp[-2].TypedVal)->type == "float") {
            (yyval.TypedVal)->floatVal = (yyvsp[-2].TypedVal)->floatVal + (yyvsp[0].TypedVal)->floatVal;
        }
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
    }
#line 1876 "language.tab.c"
    break;

  case 39: /* exp: exp '-' exp  */
#line 284 "language.y"
                  {
        if((yyvsp[-2].TypedVal)->type != (yyvsp[0].TypedVal)->type) {
            errorCount++;
            string msg = "Type mismatch in subtraction: " + (yyvsp[-2].TypedVal)->type + " - " + (yyvsp[0].TypedVal)->type;
            yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = (yyvsp[-2].TypedVal)->type;
        if((yyvsp[-2].TypedVal)->type == "int") {
            (yyval.TypedVal)->intVal = (yyvsp[-2].TypedVal)->intVal - (yyvsp[0].TypedVal)->intVal;
        } else if((yyvsp[-2].TypedVal)->type == "float") {
            (yyval.TypedVal)->floatVal = (yyvsp[-2].TypedVal)->floatVal - (yyvsp[0].TypedVal)->floatVal;
        }
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
    }
#line 1896 "language.tab.c"
    break;

  case 40: /* exp: exp '*' exp  */
#line 299 "language.y"
                  {
        if((yyvsp[-2].TypedVal)->type != (yyvsp[0].TypedVal)->type) {
            errorCount++;
            string msg = "Type mismatch in multiplication: " + (yyvsp[-2].TypedVal)->type + " * " + (yyvsp[0].TypedVal)->type;
            yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = (yyvsp[-2].TypedVal)->type;
        if((yyvsp[-2].TypedVal)->type == "int") {
            (yyval.TypedVal)->intVal = (yyvsp[-2].TypedVal)->intVal * (yyvsp[0].TypedVal)->intVal;
        } else if((yyvsp[-2].TypedVal)->type == "float") {
            (yyval.TypedVal)->floatVal = (yyvsp[-2].TypedVal)->floatVal * (yyvsp[0].TypedVal)->floatVal;
        }
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
    }
#line 1916 "language.tab.c"
    break;

  case 41: /* exp: exp '/' exp  */
#line 314 "language.y"
                  {
        if((yyvsp[-2].TypedVal)->type != (yyvsp[0].TypedVal)->type) {
            errorCount++;
            string msg = "Type mismatch in division: " + (yyvsp[-2].TypedVal)->type + " / " + (yyvsp[0].TypedVal)->type;
            yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = (yyvsp[-2].TypedVal)->type;
        if((yyvsp[-2].TypedVal)->type == "int") {
            (yyval.TypedVal)->intVal = ((yyvsp[0].TypedVal)->intVal != 0) ? (yyvsp[-2].TypedVal)->intVal / (yyvsp[0].TypedVal)->intVal : 0;
        } else if((yyvsp[-2].TypedVal)->type == "float") {
            (yyval.TypedVal)->floatVal = ((yyvsp[0].TypedVal)->floatVal != 0) ? (yyvsp[-2].TypedVal)->floatVal / (yyvsp[0].TypedVal)->floatVal : 0;
        }
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
    }
#line 1936 "language.tab.c"
    break;

  case 42: /* exp: '(' exp ')'  */
#line 329 "language.y"
                  { (yyval.TypedVal) = (yyvsp[-1].TypedVal); }
#line 1942 "language.tab.c"
    break;

  case 43: /* exp: '-' exp  */
#line 330 "language.y"
                           {
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = (yyvsp[0].TypedVal)->type;
        if((yyvsp[0].TypedVal)->type == "int") {
            (yyval.TypedVal)->intVal = -(yyvsp[0].TypedVal)->intVal;
        } else if((yyvsp[0].TypedVal)->type == "float") {
            (yyval.TypedVal)->floatVal = -(yyvsp[0].TypedVal)->floatVal;
        }
        delete (yyvsp[0].TypedVal);
    }
#line 1957 "language.tab.c"
    break;

  case 44: /* exp: QAT  */
#line 340 "language.y"
          {
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "float";
        (yyval.TypedVal)->floatVal = (yyvsp[0].Float);
    }
#line 1967 "language.tab.c"
    break;

  case 45: /* exp: ZAT  */
#line 345 "language.y"
          {
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "int";
        (yyval.TypedVal)->intVal = (yyvsp[0].Int);
    }
#line 1977 "language.tab.c"
    break;

  case 46: /* exp: ID_INT  */
#line 350 "language.y"
             {
        if(!current->existsId((yyvsp[0].Str))) {
            errorCount++;
            string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
            yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "int";
        (yyval.TypedVal)->intVal = 0;
        delete (yyvsp[0].Str);
    }
#line 1993 "language.tab.c"
    break;

  case 47: /* exp: ID_FLOAT  */
#line 361 "language.y"
               {
        if(!current->existsId((yyvsp[0].Str))) {
            errorCount++;
            string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
            yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "float";
        (yyval.TypedVal)->floatVal = 0;
        delete (yyvsp[0].Str);
    }
#line 2009 "language.tab.c"
    break;

  case 48: /* exp: ID_INT OF ID  */
#line 372 "language.y"
                   {
        if(!current->existsId((yyvsp[0].Str))) {
            errorCount++;
            string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
            yyerror(msg.c_str());
        } else {
            IdInfo* objInfo = current->getId((yyvsp[0].Str));
            if(objInfo && objInfo->classScope && !objInfo->classScope->existsId((yyvsp[-2].Str))) {
                errorCount++;
                string msg = "Field '" + *(yyvsp[-2].Str) + "' does not exist in class";
                yyerror(msg.c_str());
            }
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "int";
        (yyval.TypedVal)->intVal = 0;
        delete (yyvsp[-2].Str); delete (yyvsp[0].Str);
    }
#line 2032 "language.tab.c"
    break;

  case 49: /* exp: ID_FLOAT OF ID  */
#line 390 "language.y"
                     {
        if(!current->existsId((yyvsp[0].Str))) {
            errorCount++;
            string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
            yyerror(msg.c_str());
        } else {
            IdInfo* objInfo = current->getId((yyvsp[0].Str));
            if(objInfo && objInfo->classScope && !objInfo->classScope->existsId((yyvsp[-2].Str))) {
                errorCount++;
                string msg = "Field '" + *(yyvsp[-2].Str) + "' does not exist in class";
                yyerror(msg.c_str());
            }
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "float";
        (yyval.TypedVal)->floatVal = 0;
        delete (yyvsp[-2].Str); delete (yyvsp[0].Str);
    }
#line 2055 "language.tab.c"
    break;

  case 50: /* exp: MAG '(' cexp ')'  */
#line 408 "language.y"
                       {
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "float";
        (yyval.TypedVal)->floatVal = sqrt(pow((yyvsp[-1].TypedVal)->compVal.real, 2) + pow((yyvsp[-1].TypedVal)->compVal.imag, 2));
        delete (yyvsp[-1].TypedVal);
    }
#line 2066 "language.tab.c"
    break;

  case 51: /* exp: REAL '(' cexp ')'  */
#line 414 "language.y"
                        {
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "float";
        (yyval.TypedVal)->floatVal = (yyvsp[-1].TypedVal)->compVal.real;
        delete (yyvsp[-1].TypedVal);
    }
#line 2077 "language.tab.c"
    break;

  case 52: /* exp: IMAG '(' cexp ')'  */
#line 420 "language.y"
                        {
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "float";
        (yyval.TypedVal)->floatVal = (yyvsp[-1].TypedVal)->compVal.imag;
        delete (yyvsp[-1].TypedVal);
    }
#line 2088 "language.tab.c"
    break;

  case 53: /* bexp: BOOL  */
#line 428 "language.y"
            {
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "bool";
        (yyval.TypedVal)->boolVal = (yyvsp[0].Bool);
    }
#line 2098 "language.tab.c"
    break;

  case 54: /* bexp: ID_BOOL  */
#line 433 "language.y"
              {
        if(!current->existsId((yyvsp[0].Str))) {
            errorCount++;
            string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
            yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "bool";
        (yyval.TypedVal)->boolVal = false;
        delete (yyvsp[0].Str);
    }
#line 2114 "language.tab.c"
    break;

  case 55: /* bexp: bexp AND bexp  */
#line 444 "language.y"
                    {
        if((yyvsp[-2].TypedVal)->type != "bool" || (yyvsp[0].TypedVal)->type != "bool") {
            errorCount++;
            yyerror("Operands of AND must be boolean");
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "bool";
        (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->boolVal && (yyvsp[0].TypedVal)->boolVal;
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
    }
#line 2129 "language.tab.c"
    break;

  case 56: /* bexp: bexp OR bexp  */
#line 454 "language.y"
                   {
        if((yyvsp[-2].TypedVal)->type != "bool" || (yyvsp[0].TypedVal)->type != "bool") {
            errorCount++;
            yyerror("Operands of OR must be boolean");
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "bool";
        (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->boolVal || (yyvsp[0].TypedVal)->boolVal;
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
    }
#line 2144 "language.tab.c"
    break;

  case 57: /* bexp: '!' bexp  */
#line 464 "language.y"
               {
        if((yyvsp[0].TypedVal)->type != "bool") {
            errorCount++;
            yyerror("Operand of NOT must be boolean");
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "bool";
        (yyval.TypedVal)->boolVal = !(yyvsp[0].TypedVal)->boolVal;
        delete (yyvsp[0].TypedVal);
    }
#line 2159 "language.tab.c"
    break;

  case 58: /* bexp: exp '<' exp  */
#line 474 "language.y"
                  {
        if((yyvsp[-2].TypedVal)->type != (yyvsp[0].TypedVal)->type) {
            errorCount++;
            string msg = "Type mismatch in comparison: " + (yyvsp[-2].TypedVal)->type + " < " + (yyvsp[0].TypedVal)->type;
            yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "bool";
        if((yyvsp[-2].TypedVal)->type == "int") {
            (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->intVal < (yyvsp[0].TypedVal)->intVal;
        } else if((yyvsp[-2].TypedVal)->type == "float") {
            (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->floatVal < (yyvsp[0].TypedVal)->floatVal;
        }
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
    }
#line 2179 "language.tab.c"
    break;

  case 59: /* bexp: exp '>' exp  */
#line 490 "language.y"
                 { 
        if((yyvsp[-2].TypedVal)->type != (yyvsp[0].TypedVal)->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + (yyvsp[-2].TypedVal)->type + " > " + (yyvsp[0].TypedVal)->type;
             yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "bool";
        if((yyvsp[-2].TypedVal)->type == "int") (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->intVal > (yyvsp[0].TypedVal)->intVal;
        else if((yyvsp[-2].TypedVal)->type == "float") (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->floatVal > (yyvsp[0].TypedVal)->floatVal;
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
     }
#line 2196 "language.tab.c"
    break;

  case 60: /* bexp: exp LEQ exp  */
#line 502 "language.y"
                   { 
        if((yyvsp[-2].TypedVal)->type != (yyvsp[0].TypedVal)->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + (yyvsp[-2].TypedVal)->type + " <= " + (yyvsp[0].TypedVal)->type;
             yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "bool";
        if((yyvsp[-2].TypedVal)->type == "int") (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->intVal <= (yyvsp[0].TypedVal)->intVal;
        else if((yyvsp[-2].TypedVal)->type == "float") (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->floatVal <= (yyvsp[0].TypedVal)->floatVal;
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
     }
#line 2213 "language.tab.c"
    break;

  case 61: /* bexp: exp GEQ exp  */
#line 514 "language.y"
                   { 
        if((yyvsp[-2].TypedVal)->type != (yyvsp[0].TypedVal)->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + (yyvsp[-2].TypedVal)->type + " >= " + (yyvsp[0].TypedVal)->type;
             yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "bool";
        if((yyvsp[-2].TypedVal)->type == "int") (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->intVal >= (yyvsp[0].TypedVal)->intVal;
        else if((yyvsp[-2].TypedVal)->type == "float") (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->floatVal >= (yyvsp[0].TypedVal)->floatVal;
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
     }
#line 2230 "language.tab.c"
    break;

  case 62: /* bexp: exp EQ exp  */
#line 526 "language.y"
                  { 
        if((yyvsp[-2].TypedVal)->type != (yyvsp[0].TypedVal)->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + (yyvsp[-2].TypedVal)->type + " == " + (yyvsp[0].TypedVal)->type;
             yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "bool";
        if((yyvsp[-2].TypedVal)->type == "int") (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->intVal == (yyvsp[0].TypedVal)->intVal;
        else if((yyvsp[-2].TypedVal)->type == "float") (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->floatVal == (yyvsp[0].TypedVal)->floatVal;
        else if((yyvsp[-2].TypedVal)->type == "bool") (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->boolVal == (yyvsp[0].TypedVal)->boolVal;
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
     }
#line 2248 "language.tab.c"
    break;

  case 63: /* bexp: exp NEQ exp  */
#line 539 "language.y"
                   { 
        if((yyvsp[-2].TypedVal)->type != (yyvsp[0].TypedVal)->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + (yyvsp[-2].TypedVal)->type + " != " + (yyvsp[0].TypedVal)->type;
             yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "bool";
        if((yyvsp[-2].TypedVal)->type == "int") (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->intVal != (yyvsp[0].TypedVal)->intVal;
        else if((yyvsp[-2].TypedVal)->type == "float") (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->floatVal != (yyvsp[0].TypedVal)->floatVal;
        else if((yyvsp[-2].TypedVal)->type == "bool") (yyval.TypedVal)->boolVal = (yyvsp[-2].TypedVal)->boolVal != (yyvsp[0].TypedVal)->boolVal;
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
     }
#line 2266 "language.tab.c"
    break;

  case 64: /* bexp: '(' bexp ')'  */
#line 552 "language.y"
                    { (yyval.TypedVal) = (yyvsp[-1].TypedVal); }
#line 2272 "language.tab.c"
    break;

  case 65: /* cexp: CAT  */
#line 556 "language.y"
            {
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "com";
        (yyval.TypedVal)->compVal = (yyvsp[0].Comp);
    }
#line 2282 "language.tab.c"
    break;

  case 66: /* cexp: ID_COM  */
#line 561 "language.y"
                 {
        if(!current->existsId((yyvsp[0].Str))) {
            errorCount++;
            string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
            yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "com";
        (yyval.TypedVal)->compVal.real = 0;
        (yyval.TypedVal)->compVal.imag = 0;
        delete (yyvsp[0].Str);
    }
#line 2299 "language.tab.c"
    break;

  case 67: /* cexp: cexp '+' cexp  */
#line 573 "language.y"
                    {
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "com";
        (yyval.TypedVal)->compVal.real = (yyvsp[-2].TypedVal)->compVal.real + (yyvsp[0].TypedVal)->compVal.real;
        (yyval.TypedVal)->compVal.imag = (yyvsp[-2].TypedVal)->compVal.imag + (yyvsp[0].TypedVal)->compVal.imag;
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
    }
#line 2311 "language.tab.c"
    break;

  case 68: /* cexp: cexp '-' cexp  */
#line 580 "language.y"
                    { 
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "com";
        (yyval.TypedVal)->compVal.real = (yyvsp[-2].TypedVal)->compVal.real - (yyvsp[0].TypedVal)->compVal.real;
        (yyval.TypedVal)->compVal.imag = (yyvsp[-2].TypedVal)->compVal.imag - (yyvsp[0].TypedVal)->compVal.imag;
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
     }
#line 2323 "language.tab.c"
    break;

  case 69: /* cexp: cexp '*' cexp  */
#line 587 "language.y"
                     { //DOES NOT NEED  () 
          // 10+0i * 2+3i is accepted by this language as (10+0i)*(2+3i)
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "com";
        // Formula înmulțirii: (a+bi)(c+di) = (ac-bd) + (ad+bc)i
        (yyval.TypedVal)->compVal.real = ((yyvsp[-2].TypedVal)->compVal.real * (yyvsp[0].TypedVal)->compVal.real) - ((yyvsp[-2].TypedVal)->compVal.imag * (yyvsp[0].TypedVal)->compVal.imag);
        (yyval.TypedVal)->compVal.imag = ((yyvsp[-2].TypedVal)->compVal.real * (yyvsp[0].TypedVal)->compVal.imag) + ((yyvsp[-2].TypedVal)->compVal.imag * (yyvsp[0].TypedVal)->compVal.real);
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
     }
#line 2337 "language.tab.c"
    break;

  case 70: /* cexp: cexp '/' cexp  */
#line 596 "language.y"
                    { 
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "com";
        // Formula împărțirii numerelor complexe
        float denom = ((yyvsp[0].TypedVal)->compVal.real * (yyvsp[0].TypedVal)->compVal.real) + ((yyvsp[0].TypedVal)->compVal.imag * (yyvsp[0].TypedVal)->compVal.imag);
        if (denom == 0) {
            // Putem semnala o eroare la runtime/compile time pt impartire la zero
             // errorCount++; yyerror("Division by zero in complex number");
             (yyval.TypedVal)->compVal.real = 0;
             (yyval.TypedVal)->compVal.imag = 0;
        } else {
            (yyval.TypedVal)->compVal.real = (((yyvsp[-2].TypedVal)->compVal.real * (yyvsp[0].TypedVal)->compVal.real) + ((yyvsp[-2].TypedVal)->compVal.imag * (yyvsp[0].TypedVal)->compVal.imag)) / denom;
            (yyval.TypedVal)->compVal.imag = (((yyvsp[-2].TypedVal)->compVal.imag * (yyvsp[0].TypedVal)->compVal.real) - ((yyvsp[-2].TypedVal)->compVal.real * (yyvsp[0].TypedVal)->compVal.imag)) / denom;
        }
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
     }
#line 2358 "language.tab.c"
    break;

  case 71: /* cexp: '(' cexp ')'  */
#line 612 "language.y"
                    { 
        (yyval.TypedVal) = (yyvsp[-1].TypedVal); 
     }
#line 2366 "language.tab.c"
    break;

  case 72: /* stexp: STRING  */
#line 617 "language.y"
               {
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "string";
        (yyval.TypedVal)->strVal = (yyvsp[0].Str);
    }
#line 2376 "language.tab.c"
    break;

  case 73: /* stexp: ID_STR  */
#line 622 "language.y"
             {
        if(!current->existsId((yyvsp[0].Str))) {
            errorCount++;
            string msg = "Variable '" + *(yyvsp[0].Str) + "' not defined";
            yyerror(msg.c_str());
        }
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "string";
        (yyval.TypedVal)->strVal = new string("");
        delete (yyvsp[0].Str);
    }
#line 2392 "language.tab.c"
    break;

  case 74: /* stexp: stexp '+' stexp  */
#line 633 "language.y"
                      {
        (yyval.TypedVal) = new TypedValue();
        (yyval.TypedVal)->type = "string";
        (yyval.TypedVal)->strVal = new string(*((yyvsp[-2].TypedVal)->strVal) + *((yyvsp[0].TypedVal)->strVal));
        delete (yyvsp[-2].TypedVal)->strVal; delete (yyvsp[0].TypedVal)->strVal;
        delete (yyvsp[-2].TypedVal); delete (yyvsp[0].TypedVal);
    }
#line 2404 "language.tab.c"
    break;

  case 75: /* list_param: %empty  */
#line 642 "language.y"
                {
                (yyval.ParamList)= new vector<Param*>();
                }
#line 2412 "language.tab.c"
    break;

  case 76: /* list_param: param  */
#line 646 "language.y"
                {
                    (yyval.ParamList)= new vector<Param*>();
                    (yyval.ParamList)->push_back((yyvsp[0].Param));
                }
#line 2421 "language.tab.c"
    break;

  case 77: /* list_param: list_param ',' param  */
#line 651 "language.y"
                {
                    (yyval.ParamList) = (yyvsp[-2].ParamList); //og vector and add new param to the end ($3)
                    (yyval.ParamList)->push_back((yyvsp[0].Param));
                }
#line 2430 "language.tab.c"
    break;

  case 78: /* param: TYPENAME ANYID  */
#line 658 "language.y"
     {
         (yyval.Param) = new Param();
         (yyval.Param)->type = *(yyvsp[-1].Str);
         (yyval.Param)->name = *(yyvsp[0].Str);
         delete (yyvsp[-1].Str); delete (yyvsp[0].Str);
     }
#line 2441 "language.tab.c"
    break;

  case 85: /* simple_statement: ID_INT ASSIGN exp  */
#line 681 "language.y"
                       {
        if((yyvsp[0].TypedVal)->type != "int") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + (yyvsp[0].TypedVal)->type + " to int variable";
            yyerror(msg.c_str());
        }
        delete (yyvsp[0].TypedVal);
    }
#line 2454 "language.tab.c"
    break;

  case 86: /* simple_statement: ID_FLOAT ASSIGN exp  */
#line 689 "language.y"
                          {
        if((yyvsp[0].TypedVal)->type != "float") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + (yyvsp[0].TypedVal)->type + " to float variable";
            yyerror(msg.c_str());
        }
        delete (yyvsp[0].TypedVal);
    }
#line 2467 "language.tab.c"
    break;

  case 87: /* simple_statement: ID_BOOL ASSIGN bexp  */
#line 697 "language.y"
                          {
        if((yyvsp[0].TypedVal)->type != "bool") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + (yyvsp[0].TypedVal)->type + " to bool variable";
            yyerror(msg.c_str());
        }
        delete (yyvsp[0].TypedVal);
    }
#line 2480 "language.tab.c"
    break;

  case 88: /* simple_statement: ID_STR ASSIGN stexp  */
#line 705 "language.y"
                          {
        if((yyvsp[0].TypedVal)->type != "string") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + (yyvsp[0].TypedVal)->type + " to string variable";
            yyerror(msg.c_str());
        }
        delete (yyvsp[0].TypedVal)->strVal;
        delete (yyvsp[0].TypedVal);
    }
#line 2494 "language.tab.c"
    break;

  case 89: /* simple_statement: ID_COM ASSIGN cexp  */
#line 714 "language.y"
                         {
        if((yyvsp[0].TypedVal)->type != "com") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + (yyvsp[0].TypedVal)->type + " to com variable";
            yyerror(msg.c_str());
        }
        delete (yyvsp[0].TypedVal);
    }
#line 2507 "language.tab.c"
    break;

  case 90: /* simple_statement: ID OF ID ASSIGN typed_exp  */
#line 722 "language.y"
                                {
        if(!current->existsId((yyvsp[-2].Str))) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId((yyvsp[-2].Str));
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal((yyvsp[-4].Str))) { errorCount++; yyerror("Field does not exist"); }
            else {
                string fieldType = info->classScope->getType((yyvsp[-4].Str));
                if (fieldType != (yyvsp[0].TypedVal)->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + (yyvsp[0].TypedVal)->type + " to " + fieldType + " field '" + *(yyvsp[-4].Str) + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete (yyvsp[-4].Str); delete (yyvsp[-2].Str); delete (yyvsp[0].TypedVal);
    }
#line 2529 "language.tab.c"
    break;

  case 91: /* simple_statement: ID_INT OF ID ASSIGN typed_exp  */
#line 739 "language.y"
                                    {
        if(!current->existsId((yyvsp[-2].Str))) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId((yyvsp[-2].Str));
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal((yyvsp[-4].Str))) { errorCount++; yyerror("Field does not exist"); }
            else {
                string fieldType = info->classScope->getType((yyvsp[-4].Str));
                if (fieldType != (yyvsp[0].TypedVal)->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + (yyvsp[0].TypedVal)->type + " to " + fieldType + " field '" + *(yyvsp[-4].Str) + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete (yyvsp[-4].Str); delete (yyvsp[-2].Str); delete (yyvsp[0].TypedVal);
    }
#line 2551 "language.tab.c"
    break;

  case 92: /* simple_statement: ID_FLOAT OF ID ASSIGN typed_exp  */
#line 756 "language.y"
                                      {
        if(!current->existsId((yyvsp[-2].Str))) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId((yyvsp[-2].Str));
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal((yyvsp[-4].Str))) { errorCount++; yyerror("Field does not exist"); }
            else {
                string fieldType = info->classScope->getType((yyvsp[-4].Str));
                if (fieldType != (yyvsp[0].TypedVal)->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + (yyvsp[0].TypedVal)->type + " to " + fieldType + " field '" + *(yyvsp[-4].Str) + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete (yyvsp[-4].Str); delete (yyvsp[-2].Str); delete (yyvsp[0].TypedVal);
    }
#line 2573 "language.tab.c"
    break;

  case 93: /* simple_statement: ID_BOOL OF ID ASSIGN typed_exp  */
#line 773 "language.y"
                                     {
        if(!current->existsId((yyvsp[-2].Str))) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId((yyvsp[-2].Str));
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal((yyvsp[-4].Str))) { errorCount++; yyerror("Field does not exist"); }
            else {
                string fieldType = info->classScope->getType((yyvsp[-4].Str));
                if (fieldType != (yyvsp[0].TypedVal)->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + (yyvsp[0].TypedVal)->type + " to " + fieldType + " field '" + *(yyvsp[-4].Str) + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete (yyvsp[-4].Str); delete (yyvsp[-2].Str); delete (yyvsp[0].TypedVal);
    }
#line 2595 "language.tab.c"
    break;

  case 94: /* simple_statement: ID_COM OF ID ASSIGN typed_exp  */
#line 790 "language.y"
                                    {
        if(!current->existsId((yyvsp[-2].Str))) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId((yyvsp[-2].Str));
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal((yyvsp[-4].Str))) { errorCount++; yyerror("Field does not exist"); }
            else {
                string fieldType = info->classScope->getType((yyvsp[-4].Str));
                if (fieldType != (yyvsp[0].TypedVal)->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + (yyvsp[0].TypedVal)->type + " to " + fieldType + " field '" + *(yyvsp[-4].Str) + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete (yyvsp[-4].Str); delete (yyvsp[-2].Str); delete (yyvsp[0].TypedVal);
    }
#line 2617 "language.tab.c"
    break;

  case 95: /* simple_statement: ID_STR OF ID ASSIGN typed_exp  */
#line 807 "language.y"
                                    {
        if(!current->existsId((yyvsp[-2].Str))) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId((yyvsp[-2].Str));
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal((yyvsp[-4].Str))) { errorCount++; yyerror("Field does not exist"); }
            else {
                string fieldType = info->classScope->getType((yyvsp[-4].Str));
                if (fieldType != (yyvsp[0].TypedVal)->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + (yyvsp[0].TypedVal)->type + " to " + fieldType + " field '" + *(yyvsp[-4].Str) + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete (yyvsp[-4].Str); delete (yyvsp[-2].Str); delete (yyvsp[0].TypedVal);
    }
#line 2639 "language.tab.c"
    break;

  case 96: /* simple_statement: ID '(' call_list_typed ')'  */
#line 830 "language.y"
                                 { 
        if(!current->existsId((yyvsp[-3].Str))) {
            errorCount++;
            string msg = "Function '" + *(yyvsp[-3].Str) + "' not defined";
            yyerror(msg.c_str());
        } else {
            // Verifică tipurile parametrilor
            IdInfo* funcInfo = current->getId((yyvsp[-3].Str));
            if(funcInfo && funcInfo->category == "func") {
                vector<string>& expectedTypes = funcInfo->params;
                vector<string>& actualTypes = *(yyvsp[-1].TypeList);
                
                if(expectedTypes.size() != actualTypes.size()) {
                    errorCount++;
                    string msg = "Function '" + *(yyvsp[-3].Str) + "' expects " + 
                                to_string(expectedTypes.size()) + " parameters, but " +
                                to_string(actualTypes.size()) + " were provided";
                    yyerror(msg.c_str());
                } else {
                    // Verifică fiecare parametru
                    for(size_t i = 0; i < expectedTypes.size(); i++) {
                        if(expectedTypes[i] != actualTypes[i]) {
                            errorCount++;
                            string msg = "Parameter " + to_string(i+1) + 
                                        " type mismatch: expected " + expectedTypes[i] +
                                        ", got " + actualTypes[i];
                            yyerror(msg.c_str());
                        }
                    }
                }
            }
        }
        delete (yyvsp[-3].Str);
        delete (yyvsp[-1].TypeList);
    }
#line 2679 "language.tab.c"
    break;

  case 97: /* simple_statement: ID OF ID '(' call_list_typed ')'  */
#line 867 "language.y"
                                       {
        if(!current->existsId((yyvsp[-3].Str))) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId((yyvsp[-3].Str));
            string objType = current->getType((yyvsp[-3].Str));
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal((yyvsp[-5].Str))) { errorCount++; string msg="Method '"+*(yyvsp[-5].Str)+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId((yyvsp[-5].Str));
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else if(methodInfo->params.size() != (yyvsp[-1].TypeList)->size()) { errorCount++; yyerror("Wrong parameter count"); }
                else {
                    for(size_t i=0; i<methodInfo->params.size(); i++) {
                        if(methodInfo->params[i] != (yyvsp[-1].TypeList)->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                    }
                }
            }
        }
        delete (yyvsp[-5].Str); delete (yyvsp[-3].Str); delete (yyvsp[-1].TypeList);
    }
#line 2704 "language.tab.c"
    break;

  case 98: /* simple_statement: ID_INT OF ID '(' call_list_typed ')'  */
#line 887 "language.y"
                                           {
        if(!current->existsId((yyvsp[-3].Str))) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId((yyvsp[-3].Str));
            string objType = current->getType((yyvsp[-3].Str));
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal((yyvsp[-5].Str))) { errorCount++; string msg="Method '"+*(yyvsp[-5].Str)+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId((yyvsp[-5].Str));
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else if(methodInfo->params.size() != (yyvsp[-1].TypeList)->size()) { errorCount++; yyerror("Wrong parameter count"); }
                else {
                    for(size_t i=0; i<methodInfo->params.size(); i++) {
                        if(methodInfo->params[i] != (yyvsp[-1].TypeList)->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                    }
                }
            }
        }
        delete (yyvsp[-5].Str); delete (yyvsp[-3].Str); delete (yyvsp[-1].TypeList);
    }
#line 2729 "language.tab.c"
    break;

  case 99: /* simple_statement: ID_FLOAT OF ID '(' call_list_typed ')'  */
#line 907 "language.y"
                                             {
        if(!current->existsId((yyvsp[-3].Str))) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId((yyvsp[-3].Str));
            string objType = current->getType((yyvsp[-3].Str));
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal((yyvsp[-5].Str))) { errorCount++; string msg="Method '"+*(yyvsp[-5].Str)+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId((yyvsp[-5].Str));
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else if(methodInfo->params.size() != (yyvsp[-1].TypeList)->size()) { errorCount++; yyerror("Wrong parameter count"); }
                else {
                    for(size_t i=0; i<methodInfo->params.size(); i++) {
                        if(methodInfo->params[i] != (yyvsp[-1].TypeList)->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                    }
                }
            }
        }
        delete (yyvsp[-5].Str); delete (yyvsp[-3].Str); delete (yyvsp[-1].TypeList);
    }
#line 2754 "language.tab.c"
    break;

  case 100: /* simple_statement: ID_BOOL OF ID '(' call_list_typed ')'  */
#line 927 "language.y"
                                            {
        if(!current->existsId((yyvsp[-3].Str))) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId((yyvsp[-3].Str));
            string objType = current->getType((yyvsp[-3].Str));
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal((yyvsp[-5].Str))) { errorCount++; string msg="Method '"+*(yyvsp[-5].Str)+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId((yyvsp[-5].Str));
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else if(methodInfo->params.size() != (yyvsp[-1].TypeList)->size()) { errorCount++; yyerror("Wrong parameter count"); }
                else {
                    for(size_t i=0; i<methodInfo->params.size(); i++) {
                        if(methodInfo->params[i] != (yyvsp[-1].TypeList)->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                    }
                }
            }
        }
        delete (yyvsp[-5].Str); delete (yyvsp[-3].Str); delete (yyvsp[-1].TypeList);
    }
#line 2779 "language.tab.c"
    break;

  case 101: /* simple_statement: ID_COM OF ID '(' call_list_typed ')'  */
#line 947 "language.y"
                                           {
        if(!current->existsId((yyvsp[-3].Str))) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId((yyvsp[-3].Str));
            string objType = current->getType((yyvsp[-3].Str));
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal((yyvsp[-5].Str))) { errorCount++; string msg="Method '"+*(yyvsp[-5].Str)+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId((yyvsp[-5].Str));
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else if(methodInfo->params.size() != (yyvsp[-1].TypeList)->size()) { errorCount++; yyerror("Wrong parameter count"); }
                else {
                    for(size_t i=0; i<methodInfo->params.size(); i++) {
                        if(methodInfo->params[i] != (yyvsp[-1].TypeList)->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                    }
                }
            }
        }
        delete (yyvsp[-5].Str); delete (yyvsp[-3].Str); delete (yyvsp[-1].TypeList);
    }
#line 2804 "language.tab.c"
    break;

  case 102: /* simple_statement: ID_STR OF ID '(' call_list_typed ')'  */
#line 967 "language.y"
                                           {
        if(!current->existsId((yyvsp[-3].Str))) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId((yyvsp[-3].Str));
            string objType = current->getType((yyvsp[-3].Str));
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal((yyvsp[-5].Str))) { errorCount++; string msg="Method '"+*(yyvsp[-5].Str)+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId((yyvsp[-5].Str));
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else if(methodInfo->params.size() != (yyvsp[-1].TypeList)->size()) { errorCount++; yyerror("Wrong parameter count"); }
                else {
                    for(size_t i=0; i<methodInfo->params.size(); i++) {
                        if(methodInfo->params[i] != (yyvsp[-1].TypeList)->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                    }
                }
            }
        }
        delete (yyvsp[-5].Str); delete (yyvsp[-3].Str); delete (yyvsp[-1].TypeList);
    }
#line 2829 "language.tab.c"
    break;

  case 103: /* simple_statement: PRINT '(' exp ')'  */
#line 988 "language.y"
                        { delete (yyvsp[-1].TypedVal); }
#line 2835 "language.tab.c"
    break;

  case 104: /* simple_statement: PRINT '(' stexp ')'  */
#line 989 "language.y"
                          { delete (yyvsp[-1].TypedVal)->strVal; delete (yyvsp[-1].TypedVal); }
#line 2841 "language.tab.c"
    break;

  case 105: /* simple_statement: PRINT '(' cexp ')'  */
#line 990 "language.y"
                         { delete (yyvsp[-1].TypedVal); }
#line 2847 "language.tab.c"
    break;

  case 106: /* simple_statement: PRINT '(' bexp ')'  */
#line 991 "language.y"
                         { delete (yyvsp[-1].TypedVal); }
#line 2853 "language.tab.c"
    break;

  case 111: /* call_list_typed: %empty  */
#line 1007 "language.y"
                              {
                    (yyval.TypeList) = new vector<string>();
                }
#line 2861 "language.tab.c"
    break;

  case 112: /* call_list_typed: typed_exp  */
#line 1010 "language.y"
                            { 
                    (yyval.TypeList) = new vector<string>();
                    (yyval.TypeList)->push_back((yyvsp[0].TypedVal)->type);
                    delete (yyvsp[0].TypedVal);
                }
#line 2871 "language.tab.c"
    break;

  case 113: /* call_list_typed: call_list_typed ',' typed_exp  */
#line 1015 "language.y"
                                                { 
                    (yyval.TypeList) = (yyvsp[-2].TypeList);
                    (yyval.TypeList)->push_back((yyvsp[0].TypedVal)->type);
                    delete (yyvsp[0].TypedVal);
                }
#line 2881 "language.tab.c"
    break;


#line 2885 "language.tab.c"

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

#line 1022 "language.y"

void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     current = new SymTable("global");

     symTables.push_back(current); //new here
     yyparse();
     //deallocate memory symtable vector
     freopen("tables.txt", "w", stdout);//sends stdout to tables.txt
     cout << "Variables:" <<endl;
     //current->printVars(); change here
     //delete current;
     for(auto table : symTables){
         table->printVars();
         delete table;
     }
}
