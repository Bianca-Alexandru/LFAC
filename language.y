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

  struct TypedValue {
      string type;  // "int", "float", "bool", "com", "string"
      float floatVal;
      int intVal;
      bool boolVal;
      Complex compVal;
      string* strVal;
      
      TypedValue() : type(""), floatVal(0), intVal(0), boolVal(false), strVal(nullptr) {
          compVal.real = 0;
          compVal.imag = 0;
      }
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
     struct TypedValue* TypedVal;//adaugam un nou tip pt expresii
     vector<string>* TypeList; //pentru lista de tipuri
}

//%destructor { delete $$; } <Str> 

%token  BEGIN_MAIN END_MAIN ASSIGN AS SUMMON ARISE
%token<Int> ZAT
%token<Bool> BOOL
%token<Float> QAT
%token<Comp> CAT
%token<Str> ID TYPE STRING ID_BOOL ID_COM ID_STR ID_INT ID_FLOAT
%token MAG REAL IMAG 

%token IF ELSE WHILE
%token PRINT

%type<TypedVal> exp bexp cexp stexp typed_exp
%type<Str> TYPENAME
%type<Param> param
%type<ParamList> list_param
%type<Str> ANYID
%type<TypeList> call_list_typed


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

decl    : SUMMON ANYID AS TYPENAME ';' { 
                            if(!current->existsIdLocal($2)) {
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
                            if(!current->existsIdLocal($2)) {
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
                    if(!current->existsIdLocal($2)) {
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
          } ';'
          //above is simple func definition without body
          //below is func def with body and add params in scope
              | SUMMON ANYID AS TYPENAME  '(' list_param ')' {
                    if(!current->existsIdLocal($2)) {
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
           
typed_exp : exp { $$ = $1; }
          | bexp { $$ = $1; }
          | cexp { $$ = $1; }
          | stexp { $$ = $1; }
          ;

exp : exp '+' exp {
        if($1->type != $3->type) {
            errorCount++;
            string msg = "Type mismatch in addition: " + $1->type + " + " + $3->type;
            yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = $1->type;
        if($1->type == "int") {
            $$->intVal = $1->intVal + $3->intVal;
        } else if($1->type == "float") {
            $$->floatVal = $1->floatVal + $3->floatVal;
        }
        delete $1; delete $3;
    }
    | exp '-' exp {
        if($1->type != $3->type) {
            errorCount++;
            string msg = "Type mismatch in subtraction: " + $1->type + " - " + $3->type;
            yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = $1->type;
        if($1->type == "int") {
            $$->intVal = $1->intVal - $3->intVal;
        } else if($1->type == "float") {
            $$->floatVal = $1->floatVal - $3->floatVal;
        }
        delete $1; delete $3;
    }
    | exp '*' exp {
        if($1->type != $3->type) {
            errorCount++;
            string msg = "Type mismatch in multiplication: " + $1->type + " * " + $3->type;
            yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = $1->type;
        if($1->type == "int") {
            $$->intVal = $1->intVal * $3->intVal;
        } else if($1->type == "float") {
            $$->floatVal = $1->floatVal * $3->floatVal;
        }
        delete $1; delete $3;
    }
    | exp '/' exp {
        if($1->type != $3->type) {
            errorCount++;
            string msg = "Type mismatch in division: " + $1->type + " / " + $3->type;
            yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = $1->type;
        if($1->type == "int") {
            $$->intVal = ($3->intVal != 0) ? $1->intVal / $3->intVal : 0;
        } else if($1->type == "float") {
            $$->floatVal = ($3->floatVal != 0) ? $1->floatVal / $3->floatVal : 0;
        }
        delete $1; delete $3;
    }
    | '(' exp ')' { $$ = $2; }
    | '-' exp %prec UMINUS {
        $$ = new TypedValue();
        $$->type = $2->type;
        if($2->type == "int") {
            $$->intVal = -$2->intVal;
        } else if($2->type == "float") {
            $$->floatVal = -$2->floatVal;
        }
        delete $2;
    }
    | QAT {
        $$ = new TypedValue();
        $$->type = "float";
        $$->floatVal = $1;
    }
    | ZAT {
        $$ = new TypedValue();
        $$->type = "int";
        $$->intVal = $1;
    }
    | ID_INT {
        if(!current->existsId($1)) {
            errorCount++;
            string msg = "Variable '" + *$1 + "' not defined";
            yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = "int";
        $$->intVal = 0;
        delete $1;
    }
    | ID_FLOAT {
        if(!current->existsId($1)) {
            errorCount++;
            string msg = "Variable '" + *$1 + "' not defined";
            yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = "float";
        $$->floatVal = 0;
        delete $1;
    }
    | ID_INT OF ID {
        if(!current->existsId($3)) {
            errorCount++;
            string msg = "Variable '" + *$3 + "' not defined";
            yyerror(msg.c_str());
        } else {
            IdInfo* objInfo = current->getId($3);
            if(objInfo && objInfo->classScope && !objInfo->classScope->existsId($1)) {
                errorCount++;
                string msg = "Field '" + *$1 + "' does not exist in class";
                yyerror(msg.c_str());
            }
        }
        $$ = new TypedValue();
        $$->type = "int";
        $$->intVal = 0;
        delete $1; delete $3;
    }
    | ID_FLOAT OF ID {
        if(!current->existsId($3)) {
            errorCount++;
            string msg = "Variable '" + *$3 + "' not defined";
            yyerror(msg.c_str());
        } else {
            IdInfo* objInfo = current->getId($3);
            if(objInfo && objInfo->classScope && !objInfo->classScope->existsId($1)) {
                errorCount++;
                string msg = "Field '" + *$1 + "' does not exist in class";
                yyerror(msg.c_str());
            }
        }
        $$ = new TypedValue();
        $$->type = "float";
        $$->floatVal = 0;
        delete $1; delete $3;
    }
    | MAG '(' cexp ')' {
        $$ = new TypedValue();
        $$->type = "float";
        $$->floatVal = sqrt(pow($3->compVal.real, 2) + pow($3->compVal.imag, 2));
        delete $3;
    }
    | REAL '(' cexp ')' {
        $$ = new TypedValue();
        $$->type = "float";
        $$->floatVal = $3->compVal.real;
        delete $3;
    }
    | IMAG '(' cexp ')' {
        $$ = new TypedValue();
        $$->type = "float";
        $$->floatVal = $3->compVal.imag;
        delete $3;
    }
    ;

bexp : BOOL {
        $$ = new TypedValue();
        $$->type = "bool";
        $$->boolVal = $1;
    }
    | ID_BOOL {
        if(!current->existsId($1)) {
            errorCount++;
            string msg = "Variable '" + *$1 + "' not defined";
            yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = "bool";
        $$->boolVal = false;
        delete $1;
    }
    | bexp AND bexp {
        if($1->type != "bool" || $3->type != "bool") {
            errorCount++;
            yyerror("Operands of AND must be boolean");
        }
        $$ = new TypedValue();
        $$->type = "bool";
        $$->boolVal = $1->boolVal && $3->boolVal;
        delete $1; delete $3;
    }
    | bexp OR bexp {
        if($1->type != "bool" || $3->type != "bool") {
            errorCount++;
            yyerror("Operands of OR must be boolean");
        }
        $$ = new TypedValue();
        $$->type = "bool";
        $$->boolVal = $1->boolVal || $3->boolVal;
        delete $1; delete $3;
    }
    | '!' bexp {
        if($2->type != "bool") {
            errorCount++;
            yyerror("Operand of NOT must be boolean");
        }
        $$ = new TypedValue();
        $$->type = "bool";
        $$->boolVal = !$2->boolVal;
        delete $2;
    }
    | exp '<' exp {
        if($1->type != $3->type) {
            errorCount++;
            string msg = "Type mismatch in comparison: " + $1->type + " < " + $3->type;
            yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = "bool";
        if($1->type == "int") {
            $$->boolVal = $1->intVal < $3->intVal;
        } else if($1->type == "float") {
            $$->boolVal = $1->floatVal < $3->floatVal;
        }
        delete $1; delete $3;
    }
    
   | exp '>' exp { 
        if($1->type != $3->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + $1->type + " > " + $3->type;
             yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = "bool";
        if($1->type == "int") $$->boolVal = $1->intVal > $3->intVal;
        else if($1->type == "float") $$->boolVal = $1->floatVal > $3->floatVal;
        delete $1; delete $3;
     }
     | exp LEQ exp { 
        if($1->type != $3->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + $1->type + " <= " + $3->type;
             yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = "bool";
        if($1->type == "int") $$->boolVal = $1->intVal <= $3->intVal;
        else if($1->type == "float") $$->boolVal = $1->floatVal <= $3->floatVal;
        delete $1; delete $3;
     }
     | exp GEQ exp { 
        if($1->type != $3->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + $1->type + " >= " + $3->type;
             yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = "bool";
        if($1->type == "int") $$->boolVal = $1->intVal >= $3->intVal;
        else if($1->type == "float") $$->boolVal = $1->floatVal >= $3->floatVal;
        delete $1; delete $3;
     }
     | exp EQ exp { 
        if($1->type != $3->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + $1->type + " == " + $3->type;
             yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = "bool";
        if($1->type == "int") $$->boolVal = $1->intVal == $3->intVal;
        else if($1->type == "float") $$->boolVal = $1->floatVal == $3->floatVal;
        else if($1->type == "bool") $$->boolVal = $1->boolVal == $3->boolVal;
        delete $1; delete $3;
     }
     | exp NEQ exp { 
        if($1->type != $3->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + $1->type + " != " + $3->type;
             yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = "bool";
        if($1->type == "int") $$->boolVal = $1->intVal != $3->intVal;
        else if($1->type == "float") $$->boolVal = $1->floatVal != $3->floatVal;
        else if($1->type == "bool") $$->boolVal = $1->boolVal != $3->boolVal;
        delete $1; delete $3;
     }
     | '(' bexp ')' { $$ = $2; }
     ;


cexp :  CAT {
        $$ = new TypedValue();
        $$->type = "com";
        $$->compVal = $1;
    }
        | ID_COM {
        if(!current->existsId($1)) {
            errorCount++;
            string msg = "Variable '" + *$1 + "' not defined";
            yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = "com";
        $$->compVal.real = 0;
        $$->compVal.imag = 0;
        delete $1;
    }
    | cexp '+' cexp {
        $$ = new TypedValue();
        $$->type = "com";
        $$->compVal.real = $1->compVal.real + $3->compVal.real;
        $$->compVal.imag = $1->compVal.imag + $3->compVal.imag;
        delete $1; delete $3;
    }
    | cexp '-' cexp { 
        $$ = new TypedValue();
        $$->type = "com";
        $$->compVal.real = $1->compVal.real - $3->compVal.real;
        $$->compVal.imag = $1->compVal.imag - $3->compVal.imag;
        delete $1; delete $3;
     }
     | cexp '*' cexp { //DOES NOT NEED  () 
          // 10+0i * 2+3i is accepted by this language as (10+0i)*(2+3i)
        $$ = new TypedValue();
        $$->type = "com";
        // Formula înmulțirii: (a+bi)(c+di) = (ac-bd) + (ad+bc)i
        $$->compVal.real = ($1->compVal.real * $3->compVal.real) - ($1->compVal.imag * $3->compVal.imag);
        $$->compVal.imag = ($1->compVal.real * $3->compVal.imag) + ($1->compVal.imag * $3->compVal.real);
        delete $1; delete $3;
     }
    | cexp '/' cexp { 
        $$ = new TypedValue();
        $$->type = "com";
        // Formula împărțirii numerelor complexe
        float denom = ($3->compVal.real * $3->compVal.real) + ($3->compVal.imag * $3->compVal.imag);
        if (denom == 0) {
            // Putem semnala o eroare la runtime/compile time pt impartire la zero
             // errorCount++; yyerror("Division by zero in complex number");
             $$->compVal.real = 0;
             $$->compVal.imag = 0;
        } else {
            $$->compVal.real = (($1->compVal.real * $3->compVal.real) + ($1->compVal.imag * $3->compVal.imag)) / denom;
            $$->compVal.imag = (($1->compVal.imag * $3->compVal.real) - ($1->compVal.real * $3->compVal.imag)) / denom;
        }
        delete $1; delete $3;
     }
     | '(' cexp ')' { 
        $$ = $2; 
     }
     ;

stexp : STRING {
        $$ = new TypedValue();
        $$->type = "string";
        $$->strVal = $1;
    }
    | ID_STR {
        if(!current->existsId($1)) {
            errorCount++;
            string msg = "Variable '" + *$1 + "' not defined";
            yyerror(msg.c_str());
        }
        $$ = new TypedValue();
        $$->type = "string";
        $$->strVal = new string("");
        delete $1;
    }
    | stexp '+' stexp {
        $$ = new TypedValue();
        $$->type = "string";
        $$->strVal = new string(*($1->strVal) + *($3->strVal));
        delete $1->strVal; delete $3->strVal;
        delete $1; delete $3;
    }
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
   : ID_INT ASSIGN exp {
        if($3->type != "int") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + $3->type + " to int variable";
            yyerror(msg.c_str());
        }
        delete $3;
    }
    | ID_FLOAT ASSIGN exp {
        if($3->type != "float") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + $3->type + " to float variable";
            yyerror(msg.c_str());
        }
        delete $3;
    }
    | ID_BOOL ASSIGN bexp {
        if($3->type != "bool") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + $3->type + " to bool variable";
            yyerror(msg.c_str());
        }
        delete $3;
    }
    | ID_STR ASSIGN stexp {
        if($3->type != "string") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + $3->type + " to string variable";
            yyerror(msg.c_str());
        }
        delete $3->strVal;
        delete $3;
    }
    | ID_COM ASSIGN cexp {
        if($3->type != "com") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + $3->type + " to com variable";
            yyerror(msg.c_str());
        }
        delete $3;
    }
    | ID OF ID ASSIGN typed_exp {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
            else {
                string fieldType = info->classScope->getType($1);
                if (fieldType != $5->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + $5->type + " to " + fieldType + " field '" + *$1 + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete $1; delete $3; delete $5;
    }
    | ID_INT OF ID ASSIGN typed_exp {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
            else {
                string fieldType = info->classScope->getType($1);
                if (fieldType != $5->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + $5->type + " to " + fieldType + " field '" + *$1 + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete $1; delete $3; delete $5;
    }
    | ID_FLOAT OF ID ASSIGN typed_exp {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
            else {
                string fieldType = info->classScope->getType($1);
                if (fieldType != $5->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + $5->type + " to " + fieldType + " field '" + *$1 + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete $1; delete $3; delete $5;
    }
    | ID_BOOL OF ID ASSIGN typed_exp {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
            else {
                string fieldType = info->classScope->getType($1);
                if (fieldType != $5->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + $5->type + " to " + fieldType + " field '" + *$1 + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete $1; delete $3; delete $5;
    }
    | ID_COM OF ID ASSIGN typed_exp {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
            else {
                string fieldType = info->classScope->getType($1);
                if (fieldType != $5->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + $5->type + " to " + fieldType + " field '" + *$1 + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete $1; delete $3; delete $5;
    }
    | ID_STR OF ID ASSIGN typed_exp {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
            else {
                string fieldType = info->classScope->getType($1);
                if (fieldType != $5->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + $5->type + " to " + fieldType + " field '" + *$1 + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete $1; delete $3; delete $5;
    }

    /*| ID ASSIGN exp
    | ID ASSIGN cexp
    | ID ASSIGN stexp
    | ID ASSIGN bexp*/ //not yet declared variables get generic id
    //can remove comment later after the semantic checks that the variable exists 
    | ID '(' call_list_typed ')' { 
        if(!current->existsId($1)) {
            errorCount++;
            string msg = "Function '" + *$1 + "' not defined";
            yyerror(msg.c_str());
        } else {
            // Verifică tipurile parametrilor
            IdInfo* funcInfo = current->getId($1);
            if(funcInfo && funcInfo->category == "func") {
                vector<string>& expectedTypes = funcInfo->params;
                vector<string>& actualTypes = *$3;
                
                if(expectedTypes.size() != actualTypes.size()) {
                    errorCount++;
                    string msg = "Function '" + *$1 + "' expects " + 
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
        delete $1;
        delete $3;
    }
    
    /* --- INCEPUT BLOC NOU PENTRU METODE --- */
    | ID OF ID '(' call_list_typed ')' {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            string objType = current->getType($3);
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; string msg="Method '"+*$1+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId($1);
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else if(methodInfo->params.size() != $5->size()) { errorCount++; yyerror("Wrong parameter count"); }
                else {
                    for(size_t i=0; i<methodInfo->params.size(); i++) {
                        if(methodInfo->params[i] != $5->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                    }
                }
            }
        }
        delete $1; delete $3; delete $5;
    }
    | ID_INT OF ID '(' call_list_typed ')' {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            string objType = current->getType($3);
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; string msg="Method '"+*$1+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId($1);
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else if(methodInfo->params.size() != $5->size()) { errorCount++; yyerror("Wrong parameter count"); }
                else {
                    for(size_t i=0; i<methodInfo->params.size(); i++) {
                        if(methodInfo->params[i] != $5->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                    }
                }
            }
        }
        delete $1; delete $3; delete $5;
    }
    | ID_FLOAT OF ID '(' call_list_typed ')' {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            string objType = current->getType($3);
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; string msg="Method '"+*$1+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId($1);
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else if(methodInfo->params.size() != $5->size()) { errorCount++; yyerror("Wrong parameter count"); }
                else {
                    for(size_t i=0; i<methodInfo->params.size(); i++) {
                        if(methodInfo->params[i] != $5->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                    }
                }
            }
        }
        delete $1; delete $3; delete $5;
    }
    | ID_BOOL OF ID '(' call_list_typed ')' {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            string objType = current->getType($3);
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; string msg="Method '"+*$1+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId($1);
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else if(methodInfo->params.size() != $5->size()) { errorCount++; yyerror("Wrong parameter count"); }
                else {
                    for(size_t i=0; i<methodInfo->params.size(); i++) {
                        if(methodInfo->params[i] != $5->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                    }
                }
            }
        }
        delete $1; delete $3; delete $5;
    }
    | ID_COM OF ID '(' call_list_typed ')' {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            string objType = current->getType($3);
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; string msg="Method '"+*$1+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId($1);
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else if(methodInfo->params.size() != $5->size()) { errorCount++; yyerror("Wrong parameter count"); }
                else {
                    for(size_t i=0; i<methodInfo->params.size(); i++) {
                        if(methodInfo->params[i] != $5->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                    }
                }
            }
        }
        delete $1; delete $3; delete $5;
    }
    | ID_STR OF ID '(' call_list_typed ')' {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            string objType = current->getType($3);
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; string msg="Method '"+*$1+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId($1);
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else if(methodInfo->params.size() != $5->size()) { errorCount++; yyerror("Wrong parameter count"); }
                else {
                    for(size_t i=0; i<methodInfo->params.size(); i++) {
                        if(methodInfo->params[i] != $5->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                    }
                }
            }
        }
        delete $1; delete $3; delete $5;
    }
    
    | PRINT '(' exp ')' { delete $3; }
    | PRINT '(' stexp ')' { delete $3->strVal; delete $3; }
    | PRINT '(' cexp ')' { delete $3; }
    | PRINT '(' bexp ')' { delete $3; }
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

call_list_typed : /* empty */ {
                    $$ = new vector<string>();
                }
                | typed_exp { 
                    $$ = new vector<string>();
                    $$->push_back($1->type);
                    delete $1;
                }
                | call_list_typed ',' typed_exp { 
                    $$ = $1;
                    $$->push_back($3->type);
                    delete $3;
                }
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
     freopen("tables.txt", "w", stdout);//sends stdout to tables.txt
     cout << "Variables:" <<endl;
     //current->printVars(); change here
     //delete current;
     for(auto table : symTables){
         table->printVars();
         delete table;
     }
}