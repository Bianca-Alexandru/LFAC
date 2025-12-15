%{
#include <stdio.h>
#include <stdlib.h>
#include "language.tab.h"
#include <string>
#include "SymTable.h"
extern SymTable* current;
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

-?([0-9]*\.[0-9]+|[0-9]+)[ \t]*[+-][ \t]*([0-9]*\.[0-9]+|[0-9]+)"i" { 
    float rval, ival;
    char op;
    sscanf(yytext, "%f%*[ \t]%c%*[ \t]%f", &rval, &op, &ival);
    
    yylval.Comp.real = rval;
    yylval.Comp.imag = (op == '-') ? -ival : ival;
    return CAT; 
}
(0|[1-9][0-9]*)\.[0-9]+ {yylval.Float = atof(yytext); return QAT;}
0|[1-9][0-9]* {yylval.Int = atoi(yytext); return ZAT;}

\"[^"]*\"  { yylval.Str = new std::string(yytext+1, yyleng-2); return STRING; }

[a-zA-Z][a-zA-Z0-9]* {
    //separate to fix reduce reduce conflicts for id case in exp, bexp, cexp etc
    string name = yytext;
    if(current && current->existsId(&name)) {
        string type = current->getType(&name);
        yylval.Str = new std::string(yytext);//era inainte type dar am nevoie de nume nu de tip

        if (type == "bool") return ID_BOOL;
        else if (type == "int" ) return ID_INT;
        else if (type == "float") return ID_FLOAT;
        else if (type == "com") return ID_COM;
        else if (type == "string") return ID_STR;
        return ID;
    }
    yylval.Str = new std::string(yytext);
    return ID;
}

[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 

