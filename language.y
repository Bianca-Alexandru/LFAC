%code requires {
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
}
%define parse.error verbose

%left OR
%left AND
%left '<' '>' LEQ GEQ EQ NEQ
%left '+' '-' 
%left '*' '/' '%'
%left '^'
%left '!'
%left OF
%right UMINUS

%{
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
%}

%union {
     std::string* Str;
     int Int;
     float Float;
     bool Bool;
     char Char;
     struct Complex Comp;
     struct Param* Param;
     vector<struct Param*>* ParamList;
}

//%destructor { delete $$; } <Str> 

%token  BEGIN_MAIN END_MAIN ASSIGN AS SUMMON ARISE
%token<Int> ZAT
%token<Bool> BOOL
%token<Float> QAT
%token<Float> CAT
%token<Str> ID TYPE STRING ID_BOOL ID_COM ID_STR ID_INT ID_FLOAT
%token MAG REAL IMAG 

%token IF ELSE WHILE
%token PRINT

%type<Float> exp
%type<Bool> bexp
%type<Str> stexp
%type<Str> TYPENAME
%type<Comp> cexp
%type<Param> param
%type<ParamList> list_param
%type<Str> ANYID
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

ANYID : ID       { $$ = $1; }
      | ID_INT   { $$ = $1; }
      | ID_FLOAT { $$ = $1; }
      | ID_BOOL  { $$ = $1; }
      | ID_COM   { $$ = $1; }
      | ID_STR   { $$ = $1; }
      ;

decl       :  SUMMON ANYID AS TYPENAME ';' { 
                              if(!current->existsId($2)) {
                                   string* s = new string("var");
                                   current->addSym($4,$2, s);
                                   SymTable* classTable = current->getClassScope($4);
                                   if(classTable) {
                                        current->setClassScopeForId($2, classTable);
        }
                                    delete $4; delete $2; delete s;
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                                   delete $4; delete $2;
                              }
                          }
               | SUMMON ANYID AS TYPENAME ',' decl { 
                              if(!current->existsId($2)) {
                                   string* s = new string("var");
                                   current->addSym($4, $2, s);
                                   SymTable* classTable = current->getClassScope($4);
                                   if(classTable) {
                                         current->setClassScopeForId($2, classTable);
                                      }
        
                                   delete $4; delete $2; delete s;
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                                   delete $4; delete $2;
                              }
                          }
          ;    
newscopefunc:{
                    SymTable* newScope = new SymTable("func", current);
                    symTables.push_back(newScope);
                    current = newScope;
                 }
           ;
newscopeclass:{
                    SymTable* newScope = new SymTable("class", current);
                    symTables.push_back(newScope);
                    current = newScope;
                 }
           ;

fundecl : SUMMON ANYID AS TYPENAME  '(' list_param ')'{
                    if(!current->existsId($2)) {
                         string* s = new string("func");
                         vector<string> paramTypes;
                         for(auto p : *$6) {
                             paramTypes.push_back(p->type);
                         }
                         current->addSym($4,$2, s, paramTypes);
                         delete $4; delete $2; delete s;
                    } else {
                         errorCount++; 
                         yyerror("Function already defined");
                         delete $4; delete $2;
                    }
                    //cleanup unused params
                    vector<Param*>* params = $6;
                    for(auto p : *params) delete p;
                    delete params;
          } ';'
          //above is simple func definition without body
          //below is func def with body and add params in scope
              | SUMMON ANYID AS TYPENAME  '(' list_param ')' {
                    if(!current->existsId($2)) {
                         string* s = new string("func");
                         vector<string> paramTypes;
                         for(auto p : *$6) {
                             paramTypes.push_back(p->type);
                         }
                         current->addSym($4,$2, s, paramTypes);
                         delete $4; delete $2; delete s;
                    } else {
                         errorCount++; 
                         yyerror("Function already defined");
                         delete $4; delete $2;
                    }
              }
              newscopefunc '{' 
              {
                    //add params in the func scope
                    vector<Param*>* params = $6;
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
              insidefunc '}' {current = current->getParent();}';'
          //without any extra code it would be 
          //SUMMON ID AS TYPENAME '(' list_param ')' '{' insidefunc '}' ';'
          ;
insidefunc : 
            | insidefunc decl
            | insidefunc statement
          ;
classdecl : ARISE ID {
                         if(!current->existsId($2)) {
                              string* s = new string("class");
                              current->addSym(s,$2, s);
                              tempClassName = new string(*$2);
                              delete $2; delete s;
                              
                         } else {
                               errorCount++; 
                               yyerror("Class already defined");
                               delete $2;
                         }
          }
          newscopeclass
          '{' 
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
           class_body '}' 
          {current = current->getParent();} ';'
          ;

class_body : 
           | class_body decl
           | class_body fundecl
           ;

exp :  exp '+' exp  {//NOT relevant WILL need to change later into smth like $$ = new ASTNode("+", $1, $3);
                    //not necessary to delete rn but will be deleted later for part4 
     $$ = $1 + $3; }
     | exp '-' exp {$$ = $1 - $3;}
     | exp '*' exp  {$$ = $1 * $3;}
     | exp '/' exp {$$ = $1 / $3;}
     | exp '%' exp {$$ = (int)$1 % (int)$3;}
     | exp '^' exp {$$ = pow($1,$3);}
     | '(' exp ')' { $$ = $2; }
     | exp'!' {$$ = 1; for(int i=1;i<=$1;i++) $$ *= i;}
     | '-' exp %prec UMINUS { $$ = -$2; }
     | QAT { $$ = $1; }
     | ZAT { $$ = $1; }
     | ID_INT OF ID { 
     // Verificăm că obiectul există
     if(!current->existsId($3)) {
        errorCount++;
        string msg = "Variable '" + *$3 + "' not defined";
        yyerror(msg.c_str());
     }
     // Verificăm că field-ul există în clasă
     else {
        IdInfo* objInfo = current->getId($3);
        if(objInfo && objInfo->classScope && !objInfo->classScope->existsId($1)) {
            errorCount++;
            string msg = "Field '" + *$1 + "' does not exist in class";
            yyerror(msg.c_str());
        }
     }
     $$ = 0; 
     delete $1; delete $3; 
     }
     | ID_FLOAT OF ID { 
     if(!current->existsId($3)) {
        errorCount++;
        string msg = "Variable '" + *$3 + "' not defined";
        yyerror(msg.c_str());
     }
     else {
        IdInfo* objInfo = current->getId($3);
        if(objInfo && objInfo->classScope && !objInfo->classScope->existsId($1)) {
            errorCount++;
            string msg = "Field '" + *$1 + "' does not exist in class";
            yyerror(msg.c_str());
        }
     }
     $$ = 0; 
     delete $1; delete $3; 
     }
     | ID_INT { 
     if(!current->existsId($1)) {
        errorCount++;
        string msg = "Variable '" + *$1 + "' not defined";
        yyerror(msg.c_str());
     }
     $$ = 0; 
     delete $1; 
     }
     | ID_FLOAT { 
     if(!current->existsId($1)) {
        errorCount++;
        string msg = "Variable '" + *$1 + "' not defined";
        yyerror(msg.c_str());
     }
     $$ = 0; 
     delete $1; 
     }

     | MAG '(' cexp ')'  { $$ = sqrt(pow($3.real, 2) + pow($3.imag, 2)); }
     | REAL '(' cexp ')' { $$ = $3.real; }
     | IMAG '(' cexp ')' { $$ = $3.imag; }
     ;

bexp : BOOL { $$ = $1; }
     | ID_BOOL {
     if(!current->existsId($1)) {
        errorCount++;
        string msg = "Variable '" + *$1 + "' not defined";
        yyerror(msg.c_str());
     }
     $$ = false; 
     delete $1; 
     }
     | ID_BOOL OF ID { 
     if(!current->existsId($3)) {
        errorCount++;
        string msg = "Variable '" + *$3 + "' not defined";
        yyerror(msg.c_str());
     }
     else {
        IdInfo* objInfo = current->getId($3);
        if(objInfo && objInfo->classScope && !objInfo->classScope->existsId($1)) {
            errorCount++;
            string msg = "Field '" + *$1 + "' does not exist in class";
            yyerror(msg.c_str());
        }
     }
     $$ = false; 
     delete $1; delete $3; 
     }
     | bexp AND bexp { $$ = $1 && $3; }
     | bexp OR bexp { $$ = $1 || $3; }
     | '!' bexp { $$ = !$2; }
     | exp '<' exp { $$ = $1 < $3; }
     | exp '>' exp { $$ = $1 > $3; }
     | exp LEQ exp { $$ = $1 <= $3; }
     | exp GEQ exp { $$ = $1 >= $3; }
     | exp EQ exp { $$ = $1 == $3; }
     | exp NEQ exp { $$ = $1 != $3; }
     ;

cexp : CAT { $$.real = 0; $$.imag = $1; } 
     | ID_COM { 
     if(!current->existsId($1)) {
        errorCount++;
        string msg = "Variable '" + *$1 + "' not defined";
        yyerror(msg.c_str());
     }
     $$.real = 0; $$.imag = 0; 
     delete $1; 
     }
     | ID_COM OF ID { 
     if(!current->existsId($3)) {
        errorCount++;
        string msg = "Variable '" + *$3 + "' not defined";
        yyerror(msg.c_str());
     }
     else {
        IdInfo* objInfo = current->getId($3);
        if(objInfo && objInfo->classScope && !objInfo->classScope->existsId($1)) {
            errorCount++;
            string msg = "Field '" + *$1 + "' does not exist in class";
            yyerror(msg.c_str());
        }
     }
     $$.real = 0; $$.imag = 0; 
     delete $1; delete $3; 
     }
     | cexp '+' cexp { $$.real = $1.real + $3.real; $$.imag = $1.imag + $3.imag; }
     | cexp '-' cexp { $$.real = $1.real - $3.real; $$.imag = $1.imag - $3.imag; }
     | cexp '*' cexp { //DOES NOT NEED  () 
          // 10+0i * 2+3i is accepted by this language as (10+0i)*(2+3i)
          $$.real = ($1.real * $3.real) - ($1.imag * $3.imag);
          $$.imag = ($1.real * $3.imag) + ($1.imag * $3.real);
     }
     | cexp '/' cexp { 
          float denom = ($3.real * $3.real) + ($3.imag * $3.imag);
          $$.real = (($1.real * $3.real) + ($1.imag * $3.imag)) / denom;
          $$.imag = (($1.imag * $3.real) - ($1.real * $3.imag)) / denom;
     }
     | '(' cexp ')' { $$.real = $2.real; $$.imag = $2.imag; }
     ;

stexp : STRING { $$ = $1; }
     | ID_STR { 
     if(!current->existsId($1)) {
        errorCount++;
        string msg = "Variable '" + *$1 + "' not defined";
        yyerror(msg.c_str());
     }     
     $$ = new string(""); 
     delete $1; 
     }
     | ID_STR OF ID { 
     if(!current->existsId($3)) {
        errorCount++;
        string msg = "Variable '" + *$3 + "' not defined";
        yyerror(msg.c_str());
     }
     else {
        IdInfo* objInfo = current->getId($3);
        if(objInfo && objInfo->classScope && !objInfo->classScope->existsId($1)) {
            errorCount++;
            string msg = "Field '" + *$1 + "' does not exist in class";
            yyerror(msg.c_str());
        }
     }
     $$ = new string(""); 
     delete $1; delete $3; 
     }
     | stexp '+' stexp { $$ = new string(*$1 + *$3); delete $1; delete $3; }
     ;

list_param : //empty
          {
          $$= new vector<Param*>();
          }
            |param
          {
               $$= new vector<Param*>();
               $$->push_back($1);
          }
            | list_param ','  param 
          {
               $$ = $1; //og vector and add new param to the end ($3)
               $$->push_back($3);
          }
            ;
            
param : TYPENAME ANYID 
     {
         $$ = new Param();
         $$->type = *$1;
         $$->name = *$2;
         delete $1; delete $2;
     }
      ; 
      

main : BEGIN_MAIN list END_MAIN  
     ;
     
list: //empty
    | list statement
    ;

statement
    : simple_statement ';'
    | if_statement
    | while_statement
    ;

simple_statement
    : ID_INT ASSIGN exp
    | ID_FLOAT ASSIGN exp
    | ID_BOOL ASSIGN bexp
    | ID_STR ASSIGN stexp
    | ID_COM ASSIGN cexp
    /*| ID ASSIGN exp
    | ID ASSIGN cexp
    | ID ASSIGN stexp
    | ID ASSIGN bexp*/ //not yet declared variables get generic id
    //can remove comment later after the semantic checks that the variable exists 
    | ID '(' call_list ')' { 
     if(!current->existsId($1)) {
        errorCount++;
        string msg = "Function '" + *$1 + "' not defined";
        yyerror(msg.c_str());
     }
     delete $1; 
     }
    | ANYID OF ANYID ASSIGN exp {
        // ANYID permite orice tip de ID (ID, ID_INT, ID_FLOAT, etc.)
        if(!current->existsId($3)) {
            errorCount++;
            yyerror("Object not defined");
        } else {
            IdInfo* info = current->getId($3);
            string objType = current->getType($3);
            
            if (!info->classScope) {
                errorCount++;
                string msg = "Variable '" + *$3 + "' is not a class instance";
                yyerror(msg.c_str());
            }
            else if (!info->classScope->existsId($1)) {
                errorCount++;
                string msg = "Field '" + *$1 + "' does not exist in class '" + objType + "'";
                yyerror(msg.c_str());
            }
        }
        delete $1; delete $3;
    }
    | ANYID OF ANYID '(' call_list ')' {
        if(!current->existsId($3)) {
            errorCount++;
            yyerror("Object not defined");
        } else {
            IdInfo* info = current->getId($3);
            string objType = current->getType($3);
            
            if (!info->classScope) {
                errorCount++;
                string msg = "Variable '" + *$3 + "' is not a class instance";
                yyerror(msg.c_str());
            }
            else if (!info->classScope->existsId($1)) {
                errorCount++;
                string msg = "Method '" + *$1 + "' does not exist in class '" + objType + "'";
                yyerror(msg.c_str());
            }
        }
        delete $1; delete $3;
    }

    | PRINT '(' exp ')'
    | PRINT '(' stexp ')';

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