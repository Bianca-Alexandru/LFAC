%{
#include <stdio.h>
#include <stdlib.h>
#include "language.tab.h"
#include <string>
%}
%option noyywrap
%%
"int"|"float"|"char"|"string"|"bool"|"void"|"com" {yylval.Str = new std::string(yytext); return TYPE;}
"Hello, world!" {return BEGIN_MAIN;}
"Goodbye, world!" {return END_MAIN;}
"summon" {return SUMMON;}
"as" {return AS;}
"of" {return OF;}
"arise" {return ARISE;}
"Print" {return PRINT;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"=" {return ASSIGN;}
"mag"  {return MAG;}
"real" {return REAL;}
"imag" {return IMAG;}


"T" {yylval.Bool = true; return BOOL;}
"F" {yylval.Bool = false; return BOOL;}

"&&" {return AND;}
"||" {return OR;}
"<=" {return LEQ;}
">=" {return GEQ;}
"==" {return EQ;}
"=/=" {return NEQ;}

-?[0-9]+\.[0-9]+ {yylval.Float = atof(yytext); return QAT;}
[0-9]+ {yylval.Int = atoi(yytext); return NAT;}
-?[0-9]+ {yylval.Int = atoi(yytext); return ZAT;}

-?([0-9]*\.[0-9]+|[0-9]+)"i" { yylval.Float = atof(yytext); return CAT; /*complex*/}

'.'    { yylval.Char = yytext[1]; return CHAR; }
\"[^"]*\"  { yylval.Str = new std::string(yytext+1, yyleng-2); return STRING; }

[a-zA-Z][a-zA-Z0-9]* {yylval.Str = new std::string(yytext); return ID;}

[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 

