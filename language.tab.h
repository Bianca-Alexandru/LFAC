/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LANGUAGE_TAB_H_INCLUDED
# define YY_YY_LANGUAGE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "language.y"

  #include <string>
  #include <cmath>
  #include <vector>
  using namespace std;

  struct Complex {
      float real;
      float imag;
  };
  struct Param {
      string type;
      string name;
  };

#line 65 "language.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    OR = 258,                      /* OR  */
    AND = 259,                     /* AND  */
    LEQ = 260,                     /* LEQ  */
    GEQ = 261,                     /* GEQ  */
    EQ = 262,                      /* EQ  */
    NEQ = 263,                     /* NEQ  */
    OF = 264,                      /* OF  */
    UMINUS = 265,                  /* UMINUS  */
    BEGIN_MAIN = 266,              /* BEGIN_MAIN  */
    END_MAIN = 267,                /* END_MAIN  */
    ASSIGN = 268,                  /* ASSIGN  */
    AS = 269,                      /* AS  */
    SUMMON = 270,                  /* SUMMON  */
    ARISE = 271,                   /* ARISE  */
    ZAT = 272,                     /* ZAT  */
    BOOL = 273,                    /* BOOL  */
    QAT = 274,                     /* QAT  */
    CAT = 275,                     /* CAT  */
    ID = 276,                      /* ID  */
    TYPE = 277,                    /* TYPE  */
    STRING = 278,                  /* STRING  */
    ID_BOOL = 279,                 /* ID_BOOL  */
    ID_COM = 280,                  /* ID_COM  */
    ID_STR = 281,                  /* ID_STR  */
    ID_INT = 282,                  /* ID_INT  */
    ID_FLOAT = 283,                /* ID_FLOAT  */
    MAG = 284,                     /* MAG  */
    REAL = 285,                    /* REAL  */
    IMAG = 286,                    /* IMAG  */
    IF = 287,                      /* IF  */
    ELSE = 288,                    /* ELSE  */
    WHILE = 289,                   /* WHILE  */
    PRINT = 290                    /* PRINT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 43 "language.y"

     std::string* Str;
     int Int;
     float Float;
     bool Bool;
     char Char;
     struct Complex Comp;
     struct Param* Param;
     vector<struct Param*>* ParamList;

#line 128 "language.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LANGUAGE_TAB_H_INCLUDED  */
