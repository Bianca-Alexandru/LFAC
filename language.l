%{
#include <stdio.h>
#include <stdlib.h>
#include "language.tab.h"
#include <string>
%}
%option noyywrap
%%
"int"|"float"|"char"|"string"|"bool" {yylval.Str = new std::string(yytext); return TYPE;}
"Hello, world!" {return BEGIN_MAIN;}
"Goodbye, world!" {return END_MAIN;}
"=" {return ASSIGN;}

"Print"     return PRINT;

"T" {yylval.Bool = true; return BOOL;}
"F" {yylval.Bool = false; return BOOL;}

[a-zA-Z][a-zA-Z0-9]* {yylval.Str = new std::string(yytext); return ID;}

-?[0-9]+\.[0-9]+ {yylval.Float = atof(yytext); return QAT;}
[0-9]+ {yylval.Int = atoi(yytext); return NAT;}
-[0-9]+ {yylval.Int = atoi(yytext); return ZAT;}

"&&" {return AND;}
"||" {return OR;}
"<=" {return LEQ;}
">=" {return GEQ;}
"==" {return EQ;}
"=/=" {return NEQ;}

'.'    { yylval.Char = yytext[1]; return CHAR; }
\"[^"]*\"  { yylval.Str = new std::string(yytext+1, yyleng-2); return STRING; }

[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 
