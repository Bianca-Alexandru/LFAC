%code requires {
  #include <string>
  #include <cmath>
  using namespace std;
}
%left OR
%left AND
%left '!'
%left '+' '-' 
%left '*' '/' '%'
%left '^'

%{
#include <iostream>
#include "SymTable.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class SymTable* current;
int errorCount = 0;
%}

%union {
     std::string* Str;
     int Int;
     float Float;
     bool Bool;
     char Char;
}

//%destructor { delete $$; } <Str> 

%token  BEGIN_MAIN END_MAIN ASSIGN 
%token LEQ GEQ EQ NEQ
%token<Int> NAT ZAT
%token<Bool> BOOL
%token<Float> QAT
%token<Str> ID TYPE STRING
%token<Char> CHAR

%token IF ELSE WHILE
%token PRINT

%type<Float> exp
%type<Bool> bexp
%type<Char> ch
%type<Str> stexp
%start progr
%%
progr :  declarations main {if (errorCount == 0) cout<< "The program is correct!" << endl;}
      ;

declarations : decl           
	      |  declarations decl    
	      ;

decl       :  TYPE ID ';' { 
                              if(!current->existsId($2)) {
                                    current->addVar($1,$2);
                                    delete $1;
                                    delete $2;
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
              | TYPE ID  '(' list_param ')' ';'
           ;

exp :  exp '+' exp  {$$ = $1 + $3; }
  |  exp '-' exp {$$ = $1 - $3;}
  |  exp '*' exp  {$$ = $1 * $3;}
  |  exp '/' exp {$$ = $1 / $3;}
  |  exp '%' exp {$$ = (int)$1 % (int)$3;}
  |  exp '^' exp {$$ = pow($1,$3);}
  |  '(' exp ')' { $$ = $2; }
  |  exp'!' {$$ = 1; for(int i=1;i<=$1;i++) $$ *= i;}
  |  QAT { $$ = $1; }
  |  NAT { $$ = $1; }
  |  ZAT { $$ = $1; }
  |  CHAR { $$ = (int)$1; }
  |  ID 
  ;

bexp:  bexp AND bexp { $$ = ($1 != 0 && $3 != 0) ? true : false; }
 |  bexp OR bexp { $$ = ($1 != 0 || $3 != 0) ? true : false; }
 |  '!' bexp { $$ = ($2 == 0) ? true : false; }
 |  '(' bexp ')' { $$ = $2; }
 |  exp '<' exp { $$ = ($1 < $3) ? true : false; }
 |  exp '>' exp { $$ = ($1 > $3) ? true : false; }
 |  exp LEQ exp { $$ = ($1 <= $3) ? true : false; }
 |  exp GEQ exp { $$ = ($1 >= $3) ? true : false; }
 |  exp EQ exp { $$ = ($1 == $3) ? true : false; }
 |  exp NEQ exp { $$ = ($1 != $3) ? true : false; }
 |  BOOL { $$ = $1 ? true : false; }
 |  exp { $$ = $1; }
 ;

 stexp : STRING { $$ = $1; }
     | stexp '+' stexp { $$ = new string(*$1 + *$3); delete $1; delete $3; }
     | stexp '+' STRING { $$ = new string(*$1 + *$3); delete $1; delete $3; }
     | STRING '+' stexp { $$ = new string(*$1 + *$3); delete $1; delete $3; }
     | stexp '+' ch { $$ = new string(*$1 + string(1,$3)); delete $1; }
     | ch '+' stexp { $$ = new string(string(1,$1) + *$2); delete $2; }
     | ch '+' STRING { $$ = new string(string(1,$1) + *$3); delete $3; }
     | STRING '+' ch { $$ = new string(*$1 + string(1,$3)); delete $1; }
     | ID { $$ = new string("undefined"); /* Placeholder: needs symbol table lookup */ }
     ;

list_param : param
            | list_param ','  param 
            ;
            
param : TYPE ID 
      ; 
      

main : BEGIN_MAIN list END_MAIN  
     ;
     
list
    : 
    | list statement
    ;

statement
    : simple_statement ';'
    | if_statement
    | while_statement
    ;

simple_statement
    : ID ASSIGN bexp
    | ID '(' call_list ')'
    | PRINT '(' exp ')'
    ;

block
    : '{' list '}'
    ;

if_statement
    : IF '(' bexp ')' block
    | IF '(' bexp ')' block ELSE block
    ;

while_statement
    : WHILE '(' bexp ')' block
    ;


call_list : bexp
           | call_list ',' bexp
           ;
%%
void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     current = new SymTable("global");
     yyparse();
     cout << "Variables:" <<endl;
     current->printVars();
     delete current;
}