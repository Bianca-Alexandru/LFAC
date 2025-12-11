%code requires {
  #include <string>
  #include <cmath>
  using namespace std;

  struct Complex {
      float real;
      float imag;
  };
}
%left OR
%left AND
%left '<' '>' LEQ GEQ EQ NEQ
%left '+' '-' 
%left '*' '/' '%'
%left '^'
%left '!'
%left OF

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
     struct Complex Comp;
}

//%destructor { delete $$; } <Str> 

%token  BEGIN_MAIN END_MAIN ASSIGN AS SUMMON ARISE
%token<Int> NAT ZAT
%token<Bool> BOOL
%token<Float> QAT
%token<Float> CAT
%token<Str> ID TYPE STRING
%token<Char> CHAR
%token MAG REAL IMAG 

%token IF ELSE WHILE
%token PRINT

%type<Float> exp
%type<Char> ch
%type<Bool> bexp
%type<Str> stexp
%type<Str> TYPENAME
%type<Comp> cexp
%start progr
%%
progr :  declarations main {if (errorCount == 0) cout<< "The program is correct!" << endl;}
      ;
declarations : //includes class declarations so that you cant make a class inside another class
                 | declarations decl
                 | declarations classdecl
                 | declarations fundecl
                 ;

TYPENAME : TYPE { $$ = $1; }
          | ID { $$ = $1; }
          ;

decl       :  SUMMON ID AS TYPENAME ';' { 
                              if(!current->existsId($2)) {
                                    current->addVar($4,$2);
                                    delete $4;
                                    delete $2;
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                                   delete $4; delete $2;
                              }
                          }
               | SUMMON ID AS TYPENAME ',' decl { 
                              if(!current->existsId($2)) {
                                    current->addVar($4,$2);
                                    delete $4;
                                    delete $2;
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                                   delete $4; delete $2;
                              }
                          }
          ;    
fundecl : SUMMON ID AS TYPENAME  '(' list_param ')' ';'
              | SUMMON ID AS TYPENAME  '(' list_param ')' '{' insidefunc '}' ';'
          ;
insidefunc : 
            | insidefunc decl
            | insidefunc statement
          ;
classdecl : ARISE ID '{' class_body '}' ';'
          ;

class_body : 
           | class_body decl
           | class_body fundecl
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
     |  ch { $$ = (int)$1; }
     |  ID { $$ = 0; delete $1; }
     |  ID OF ID { $$ = 0; delete $1; delete $3; }
     | MAG '(' cexp ')'  { $$ = sqrt(pow($3.real, 2) + pow($3.imag, 2)); }
     | REAL '(' cexp ')' { $$ = $3.real; }
     | IMAG '(' cexp ')' { $$ = $3.imag; }
     ;

bexp :  BOOL { $$ = $1; }
     |  bexp AND bexp { $$ = $1 && $3; }
     |  bexp OR bexp { $$ = $1 || $3; }
     |  '!' bexp { $$ = !$2; }
     |  exp '<' exp { $$ = $1 < $3; }
     |  exp '>' exp { $$ = $1 > $3; }
     |  exp LEQ exp { $$ = $1 <= $3; }
     |  exp GEQ exp { $$ = $1 >= $3; }
     |  exp EQ exp { $$ = $1 == $3; }
     |  exp NEQ exp { $$ = $1 != $3; }
     ;

cexp : CAT { $$.real = 0; $$.imag = $1; } 
     | cexp '+' cexp { $$.real = $1.real + $3.real; $$.imag = $1.imag + $3.imag; }
     | cexp '-' cexp { $$.real = $1.real - $3.real; $$.imag = $1.imag - $3.imag; }
     | cexp '*' cexp { 
          $$.real = ($1.real * $3.real) - ($1.imag * $3.imag);
          $$.imag = ($1.real * $3.imag) + ($1.imag * $3.real);
     }
     | cexp '/' cexp { 
          float denom = ($3.real * $3.real) + ($3.imag * $3.imag);
          $$.real = (($1.real * $3.real) + ($1.imag * $3.imag)) / denom;
          $$.imag = (($1.imag * $3.real) - ($1.real * $3.imag)) / denom;
     }
     | exp '+' cexp  { $$.real = $1 + $3.real; $$.imag = $3.imag; }
     | cexp '+' exp  { $$.real = $1.real + $3; $$.imag = $1.imag; }
     | '(' cexp ')' { $$.real = $2.real; $$.imag = $2.imag; }
     | exp '-' cexp  { $$.real = $1 - $3.real; $$.imag = -$3.imag; }
     | cexp '-' exp  { $$.real = $1.real - $3; $$.imag = $1.imag; }
     | cexp '*' exp { $$.real = $1.real * $3; $$.imag = $1.imag * $3; }
     | exp '*' cexp { $$.real = $1 * $3.real; $$.imag = $1 * $3.imag; }
     | cexp '/' exp { $$.real = $1.real / $3; $$.imag = $1.imag / $3; }
     ;

ch : CHAR { $$ = $1; }
   ;

 stexp : STRING { $$ = $1; }
     | stexp '+' stexp { $$ = new string(*$1 + *$3); delete $1; delete $3; }
     ;

list_param : 
            |param
            | list_param ','  param 
            ;
            
param : TYPENAME ID 
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
    : ID ASSIGN exp
    | ID ASSIGN cexp
    | ID ASSIGN bexp //union?
    | ID '(' call_list ')'
    | ID OF ID ASSIGN exp
    | ID OF ID '(' call_list ')'
    | PRINT '(' exp ')'
    | PRINT '(' stexp ')'
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


call_list : 
           |exp
           | call_list ',' exp
           ;
%%
void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     current = new SymTable("global");
     yyparse();
     //deallocate memory symtable vector
     cout << "Variables:" <<endl;
     current->printVars();
     delete current;
}