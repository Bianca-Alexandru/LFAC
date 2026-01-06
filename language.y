%code requires {
  #include <string>
  #include <cmath>
  #include <vector>
  #include "AST.h"
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
     class ASTNode* AST;
     vector<class ASTNode*>* ASTList;
     vector<string>* TypeList; //pentru lista de tipuri
}

//%destructor { delete $$; } <Str> 

%token  BEGIN_MAIN END_MAIN ASSIGN AS SUMMON ARISE
%token<Int> ZAT
%token<Bool> BOOL
%token<Float> QAT
%token<Comp> CAT
%token<Str> ID TYPE STRING ID_BOOL ID_COM ID_STR ID_INT ID_FLOAT
%token MAG REAL IMAG VISUALIZE FINAL
%token IF ELSE WHILE
%token PRINT

%type<AST> exp bexp cexp stexp typed_exp simple_statement statement block if_statement while_statement stmt_list
%type<ASTList> list
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
                         current->addSym($4, $2, s, paramTypes);
                         
                         SymTable* newScope = new SymTable($2->c_str(), current);
                         symTables.push_back(newScope);
                         current = newScope;

                         delete $4; delete $2; delete s;
                    } else {
                         errorCount++; 
                         yyerror("Function already defined");
                         delete $4; delete $2;
                    }
              }
              '{' 
              {
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
                      current->addSym(s, $2, s);
                      
                      SymTable* newScope = new SymTable($2->c_str(), current);
                      symTables.push_back(newScope);
                      
                      tempClassName = new string(*$2);
                      current = newScope;
                      
                      delete $2; delete s;
                 } else {
                       errorCount++; 
                       yyerror("Class already defined");
                       delete $2;
                 }
          }
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
          { current = current->getParent(); } ';'
          ;

class_body : 
           | class_body decl
           | class_body fundecl
           ;
           
typed_exp : exp { $$ = $1; }
          | bexp { $$ = $1; }
          | cexp { $$ = $1; }
          | stexp { $$ = $1; }
          | ID {
            $$ = new ASTNode(*$1, current->getType($1));
            delete $1;
             }
          | ID '(' call_list_typed ')' {
            string returnType = "void";
            if(!current->existsId($1)) {
                errorCount++;
                string msg = "Function '" + *$1 + "' not defined";
                yyerror(msg.c_str());
            } else {
                IdInfo* funcInfo = current->getId($1);
                if(funcInfo->category != "func") {
                    errorCount++;
                    string msg = "'" + *$1 + "' is not a function";
                    yyerror(msg.c_str());
                } else {
                    returnType = funcInfo->type;
                    if(funcInfo->params.size() != $3->size()) {
                        errorCount++;
                        yyerror("Wrong parameter count");
                    } else {
                        for(size_t i = 0; i < funcInfo->params.size(); i++) {
                            if(funcInfo->params[i] != $3->at(i)) {
                                errorCount++;
                                yyerror("Parameter type mismatch");
                            }
                        }
                    }
                }
            }
            delete $1; delete $3;
            $$ = new ASTNode("CALL", nullptr, nullptr);
            $$->type = returnType;
          }
          | ID_INT '(' call_list_typed ')' {
            string returnType = "int";
            if(current->existsId($1)) {
                IdInfo* funcInfo = current->getId($1);
                if(funcInfo->category == "func") {
                    returnType = funcInfo->type;
                    if(funcInfo->params.size() != $3->size()) {
                        errorCount++; yyerror("Wrong parameter count");
                    } else {
                        for(size_t i = 0; i < funcInfo->params.size(); i++) {
                            if(funcInfo->params[i] != $3->at(i)) {
                                errorCount++; yyerror("Parameter type mismatch");
                            }
                        }
                    }
                }
            }
            delete $1; delete $3;
            $$ = new ASTNode("CALL", nullptr, nullptr);
            $$->type = returnType;
          }
          | ID_FLOAT '(' call_list_typed ')' {
            string returnType = "float";
            if(current->existsId($1)) {
                IdInfo* funcInfo = current->getId($1);
                if(funcInfo->category == "func") {
                    returnType = funcInfo->type;
                    if(funcInfo->params.size() != $3->size()) {
                        errorCount++; yyerror("Wrong parameter count");
                    } else {
                        for(size_t i = 0; i < funcInfo->params.size(); i++) {
                            if(funcInfo->params[i] != $3->at(i)) {
                                errorCount++; yyerror("Parameter type mismatch");
                            }
                        }
                    }
                }
            }
            delete $1; delete $3;
            $$ = new ASTNode("CALL", nullptr, nullptr);
            $$->type = returnType;
          }
          | ID_BOOL '(' call_list_typed ')' {
            string returnType = "bool";
            if(current->existsId($1)) {
                IdInfo* funcInfo = current->getId($1);
                if(funcInfo->category == "func") {
                    returnType = funcInfo->type;
                    if(funcInfo->params.size() != $3->size()) {
                        errorCount++; yyerror("Wrong parameter count");
                    } else {
                        for(size_t i = 0; i < funcInfo->params.size(); i++) {
                            if(funcInfo->params[i] != $3->at(i)) {
                                errorCount++; yyerror("Parameter type mismatch");
                            }
                        }
                    }
                }
            }
            delete $1; delete $3;
            $$ = new ASTNode("CALL", nullptr, nullptr);
            $$->type = returnType;
          }
          | ID_COM '(' call_list_typed ')' {
            string returnType = "com";
            if(current->existsId($1)) {
                IdInfo* funcInfo = current->getId($1);
                if(funcInfo->category == "func") {
                    returnType = funcInfo->type;
                    if(funcInfo->params.size() != $3->size()) {
                        errorCount++; yyerror("Wrong parameter count");
                    } else {
                        for(size_t i = 0; i < funcInfo->params.size(); i++) {
                            if(funcInfo->params[i] != $3->at(i)) {
                                errorCount++; yyerror("Parameter type mismatch");
                            }
                        }
                    }
                }
            }
            delete $1; delete $3;
            $$ = new ASTNode("CALL", nullptr, nullptr);
            $$->type = returnType;
          }
          | ID_STR '(' call_list_typed ')' {
            string returnType = "string";
            if(current->existsId($1)) {
                IdInfo* funcInfo = current->getId($1);
                if(funcInfo->category == "func") {
                    returnType = funcInfo->type;
                    if(funcInfo->params.size() != $3->size()) {
                        errorCount++; yyerror("Wrong parameter count");
                    } else {
                        for(size_t i = 0; i < funcInfo->params.size(); i++) {
                            if(funcInfo->params[i] != $3->at(i)) {
                                errorCount++; yyerror("Parameter type mismatch");
                            }
                        }
                    }
                }
            }
            delete $1; delete $3;
            $$ = new ASTNode("CALL", nullptr, nullptr);
            $$->type = returnType;
          }
          | ID OF ID '(' call_list_typed ')' {
            string returnType = "void";
            if(current->existsId($3)) {
                IdInfo* info = current->getId($3);
                if(info->classScope && info->classScope->existsIdLocal($1)) {
                    IdInfo* methodInfo = info->classScope->getId($1);
                    if(methodInfo->category == "func") {
                        returnType = methodInfo->type;
                        if(methodInfo->params.size() != $5->size()) {
                            errorCount++; yyerror("Wrong parameter count");
                        } else {
                            for(size_t i = 0; i < methodInfo->params.size(); i++) {
                                if(methodInfo->params[i] != $5->at(i)) {
                                    errorCount++; yyerror("Parameter type mismatch");
                                }
                            }
                        }
                    }
                }
            }
            delete $1; delete $3; delete $5;
            $$ = new ASTNode("MCALL", nullptr, nullptr);
            $$->type = returnType;
          }
          | ID_INT OF ID '(' call_list_typed ')' {
            string returnType = "int";
            if(current->existsId($3)) {
                IdInfo* info = current->getId($3);
                if(info->classScope && info->classScope->existsIdLocal($1)) {
                    IdInfo* methodInfo = info->classScope->getId($1);
                    if(methodInfo->category == "func") {
                        returnType = methodInfo->type;
                        if(methodInfo->params.size() != $5->size()) {
                            errorCount++; yyerror("Wrong parameter count");
                        } else {
                            for(size_t i = 0; i < methodInfo->params.size(); i++) {
                                if(methodInfo->params[i] != $5->at(i)) {
                                    errorCount++; yyerror("Parameter type mismatch");
                                }
                            }
                        }
                    }
                }
            }
            delete $1; delete $3; delete $5;
            $$ = new ASTNode("MCALL", nullptr, nullptr);
            $$->type = returnType;
          }
          | ID_FLOAT OF ID '(' call_list_typed ')' {
            string returnType = "float";
            if(current->existsId($3)) {
                IdInfo* info = current->getId($3);
                if(info->classScope && info->classScope->existsIdLocal($1)) {
                    IdInfo* methodInfo = info->classScope->getId($1);
                    if(methodInfo->category == "func") {
                        returnType = methodInfo->type;
                        if(methodInfo->params.size() != $5->size()) {
                            errorCount++; yyerror("Wrong parameter count");
                        } else {
                            for(size_t i = 0; i < methodInfo->params.size(); i++) {
                                if(methodInfo->params[i] != $5->at(i)) {
                                    errorCount++; yyerror("Parameter type mismatch");
                                }
                            }
                        }
                    }
                }
            }
            delete $1; delete $3; delete $5;
            $$ = new ASTNode("MCALL", nullptr, nullptr);
            $$->type = returnType;
          }
          | ID_BOOL OF ID '(' call_list_typed ')' {
            string returnType = "bool";
            if(current->existsId($3)) {
                IdInfo* info = current->getId($3);
                if(info->classScope && info->classScope->existsIdLocal($1)) {
                    IdInfo* methodInfo = info->classScope->getId($1);
                    if(methodInfo->category == "func") {
                        returnType = methodInfo->type;
                        if(methodInfo->params.size() != $5->size()) {
                            errorCount++; yyerror("Wrong parameter count");
                        } else {
                            for(size_t i = 0; i < methodInfo->params.size(); i++) {
                                if(methodInfo->params[i] != $5->at(i)) {
                                    errorCount++; yyerror("Parameter type mismatch");
                                }
                            }
                        }
                    }
                }
            }
            delete $1; delete $3; delete $5;
            $$ = new ASTNode("MCALL", nullptr, nullptr);
            $$->type = returnType;
          }
          | ID_COM OF ID '(' call_list_typed ')' {
            string returnType = "com";
            if(current->existsId($3)) {
                IdInfo* info = current->getId($3);
                if(info->classScope && info->classScope->existsIdLocal($1)) {
                    IdInfo* methodInfo = info->classScope->getId($1);
                    if(methodInfo->category == "func") {
                        returnType = methodInfo->type;
                        if(methodInfo->params.size() != $5->size()) {
                            errorCount++; yyerror("Wrong parameter count");
                        } else {
                            for(size_t i = 0; i < methodInfo->params.size(); i++) {
                                if(methodInfo->params[i] != $5->at(i)) {
                                    errorCount++; yyerror("Parameter type mismatch");
                                }
                            }
                        }
                    }
                }
            }
            delete $1; delete $3; delete $5;
            $$ = new ASTNode("MCALL", nullptr, nullptr);
            $$->type = returnType;
          }
          | ID_STR OF ID '(' call_list_typed ')' {
            string returnType = "string";
            if(current->existsId($3)) {
                IdInfo* info = current->getId($3);
                if(info->classScope && info->classScope->existsIdLocal($1)) {
                    IdInfo* methodInfo = info->classScope->getId($1);
                    if(methodInfo->category == "func") {
                        returnType = methodInfo->type;
                        if(methodInfo->params.size() != $5->size()) {
                            errorCount++; yyerror("Wrong parameter count");
                        } else {
                            for(size_t i = 0; i < methodInfo->params.size(); i++) {
                                if(methodInfo->params[i] != $5->at(i)) {
                                    errorCount++; yyerror("Parameter type mismatch");
                                }
                            }
                        }
                    }
                }
            }
            delete $1; delete $3; delete $5;
            $$ = new ASTNode("MCALL", nullptr, nullptr);
            $$->type = returnType;
          }
          ;

exp : exp '+' exp {
        if($1->type != $3->type) {
            errorCount++;
            string msg = "Type mismatch in addition: " + $1->type + " + " + $3->type;
            yyerror(msg.c_str());
        }
        $$ = new ASTNode("+", $1, $3);
        $$->type = $1->type;
    }
    | exp '-' exp {
        if($1->type != $3->type) {
            errorCount++;
            string msg = "Type mismatch in subtraction: " + $1->type + " - " + $3->type;
            yyerror(msg.c_str());
        }
        $$ = new ASTNode("-", $1, $3);
        $$->type = $1->type;
    }
    | exp '*' exp {
        if($1->type != $3->type) {
            errorCount++;
            string msg = "Type mismatch in multiplication: " + $1->type + " * " + $3->type;
            yyerror(msg.c_str());
        }
        $$ = new ASTNode("*", $1, $3);
        $$->type = $1->type;
    }
    | exp '/' exp {
        if($1->type != $3->type) {
            errorCount++;
            string msg = "Type mismatch in division: " + $1->type + " / " + $3->type;
            yyerror(msg.c_str());
        }
        $$ = new ASTNode("/", $1, $3);
        $$->type = $1->type;
    }
    | '(' exp ')' { $$ = $2; }
    | '-' exp %prec UMINUS {
        $$ = new ASTNode("UMINUS", $2, nullptr);
        $$->type = $2->type;
    }
    | QAT {
        $$ = new ASTNode(Value($1));
    }
    | ZAT {
        $$ = new ASTNode(Value($1));
    }
    | ID_INT {
        if(!current->existsId($1)) {
            errorCount++;
            string msg = "Variable '" + *$1 + "' not defined";
            yyerror(msg.c_str());
        }
        $$ = new ASTNode(*$1, "int");
        delete $1;
    }
    | ID_FLOAT {
        if(!current->existsId($1)) {
            errorCount++;
            string msg = "Variable '" + *$1 + "' not defined";
            yyerror(msg.c_str());
        }
        $$ = new ASTNode(*$1, "float");
        delete $1;
    }
    | ID_INT OF ID {
        string fieldType = "int";
        if(!current->existsId($3)) {
            errorCount++;
            string msg = "Variable '" + *$3 + "' not defined";
            yyerror(msg.c_str());
        } else {
            IdInfo* objInfo = current->getId($3);
            if(objInfo && objInfo->classScope) {
                if (objInfo->classScope->existsIdLocal($1)) {
                    fieldType = objInfo->classScope->getType($1);
                } else {
                    errorCount++;
                    string msg = "Field '" + *$1 + "' does not exist in class";
                    yyerror(msg.c_str());
                }
            }
        }
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = fieldType;
        delete $1; delete $3;
    }
    | ID_FLOAT OF ID {
        string fieldType = "float";
        if(!current->existsId($3)) {
            errorCount++;
            string msg = "Variable '" + *$3 + "' not defined";
            yyerror(msg.c_str());
        } else {
            IdInfo* objInfo = current->getId($3);
            if(objInfo && objInfo->classScope) {
                if (objInfo->classScope->existsIdLocal($1)) {
                    fieldType = objInfo->classScope->getType($1);
                } else {
                    errorCount++;
                    string msg = "Field '" + *$1 + "' does not exist in class";
                    yyerror(msg.c_str());
                }
            }
        }
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = fieldType;
        delete $1; delete $3;
    }
    | MAG '(' cexp ')' {
        $$ = new ASTNode("MAG", $3, nullptr);
        $$->type = "float";
    }
    | REAL '(' cexp ')' {
        $$ = new ASTNode("REAL", $3, nullptr);
        $$->type = "float";
    }
    | IMAG '(' cexp ')' {
        $$ = new ASTNode("IMAG", $3, nullptr);
        $$->type = "float";
    }
    ;
    ;

bexp : BOOL {
        $$ = new ASTNode(Value($1));
    }
    | ID_BOOL {
        if(!current->existsId($1)) {
            errorCount++;
            string msg = "Variable '" + *$1 + "' not defined";
            yyerror(msg.c_str());
        }
        $$ = new ASTNode(*$1, "bool");
        delete $1;
    }
    | bexp AND bexp {
        if($1->type != "bool" || $3->type != "bool") {
            errorCount++;
            yyerror("Operands of AND must be boolean");
        }
        $$ = new ASTNode("&&", $1, $3);
        $$->type = "bool";
    }
    | bexp OR bexp {
        if($1->type != "bool" || $3->type != "bool") {
            errorCount++;
            yyerror("Operands of OR must be boolean");
        }
        $$ = new ASTNode("||", $1, $3);
        $$->type = "bool";
    }
    | '!' bexp {
        if($2->type != "bool") {
            errorCount++;
            yyerror("Operand of NOT must be boolean");
        }
        $$ = new ASTNode("!", $2, nullptr);
        $$->type = "bool";
    }
    | exp '<' exp {
        if($1->type != $3->type) {
            errorCount++;
            string msg = "Type mismatch in comparison: " + $1->type + " < " + $3->type;
            yyerror(msg.c_str());
        }
        $$ = new ASTNode("<", $1, $3);
        $$->type = "bool";
    }
    
   | exp '>' exp { 
        if($1->type != $3->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + $1->type + " > " + $3->type;
             yyerror(msg.c_str());
        }
        $$ = new ASTNode(">", $1, $3);
        $$->type = "bool";
     }
     | exp LEQ exp { 
        if($1->type != $3->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + $1->type + " <= " + $3->type;
             yyerror(msg.c_str());
        }
        $$ = new ASTNode("<=", $1, $3);
        $$->type = "bool";
     }
     | exp GEQ exp { 
        if($1->type != $3->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + $1->type + " >= " + $3->type;
             yyerror(msg.c_str());
        }
        $$ = new ASTNode(">=", $1, $3);
        $$->type = "bool";
     }
     | exp EQ exp { 
        if($1->type != $3->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + $1->type + " == " + $3->type;
             yyerror(msg.c_str());
        }
        $$ = new ASTNode("==", $1, $3);
        $$->type = "bool";
     }
     | exp NEQ exp { 
        if($1->type != $3->type) {
             errorCount++;
             string msg = "Comparison type mismatch: " + $1->type + " != " + $3->type;
             yyerror(msg.c_str());
        }
        $$ = new ASTNode("!=", $1, $3);
        $$->type = "bool";
     }
     | '(' bexp ')' { $$ = $2; }
     | ID_BOOL OF ID {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
        }
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = "bool";
        delete $1; delete $3;
    }
     ;


cexp :  CAT {
        $$ = new ASTNode(Value($1.real, $1.imag));
    }
        | ID_COM {
        if(!current->existsId($1)) {
            errorCount++;
            string msg = "Variable '" + *$1 + "' not defined";
            yyerror(msg.c_str());
        }
        $$ = new ASTNode(*$1, "com");
        delete $1;
    }
    | ID_COM OF ID {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
        }
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = "com";
        delete $1; delete $3;
    }
    | cexp '+' cexp {
        $$ = new ASTNode("+", $1, $3);
        $$->type = "com";
    }
    | cexp '-' cexp { 
        $$ = new ASTNode("-", $1, $3);
        $$->type = "com";
     }
     | cexp '*' cexp { //DOES NOT NEED  () 
          // 10+0i * 2+3i is accepted by this language as (10+0i)*(2+3i)
        $$ = new ASTNode("*", $1, $3);
        $$->type = "com";
     }
    | cexp '/' cexp { 
        $$ = new ASTNode("/", $1, $3);
        $$->type = "com";
     }
     | '(' cexp ')' { 
        $$ = $2; 
     }
     ;

stexp : STRING {
        $$ = new ASTNode(Value(*$1));
        delete $1;
    }
    | ID_STR {
        if(!current->existsId($1)) {
            errorCount++;
            string msg = "Variable '" + *$1 + "' not defined";
            yyerror(msg.c_str());
        }
        $$ = new ASTNode(*$1, "string");
        delete $1;
    }
    | ID_STR OF ID {
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
        }
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = "string";
        delete $1; delete $3;
    }
    | stexp '+' stexp {
        $$ = new ASTNode("+", $1, $3);
        $$->type = "string";
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
    {
        if (errorCount == 0) {
            cout << "--- Starting Execution ---" << endl;
            // Execute main block by evaluating all binary trees
            for (ASTNode* node : *$2) {
                if (node != nullptr) {
                    node->eval(current); 
                }
            }
            cout << "--- Execution Finished ---" << endl;
        }
    }
    ;
     
list: // empty  
    {
        $$ = new vector<ASTNode*>(); // Initialize list of ast
    }
    | list statement 
    {
        $$ = $1;
        if ($2 != nullptr) {
            $$->push_back($2); // get non-null ASTs 
        }
    }
    ;

stmt_list: /* empty */ 
    {
        $$ = nullptr;
    }
    | statement stmt_list 
    {
        $$ = new ASTNode("BLOCK", $1, $2);
    }
    ;

statement
    : simple_statement ';' { $$ = $1; } 
    | if_statement { $$ = $1; } 
    | while_statement { $$ = $1; } 
    ;

simple_statement
   : ID_INT ASSIGN exp {
        if($3->type != "int") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + $3->type + " to int variable";
            yyerror(msg.c_str());
        }
        ASTNode* leftVar = new ASTNode(*$1, "int");
        $$ = new ASTNode(":=", leftVar, $3);
        delete $1;
    }
    | ID_FLOAT ASSIGN exp {
        if($3->type != "float") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + $3->type + " to float variable";
            yyerror(msg.c_str());
        }
        ASTNode* leftVar = new ASTNode(*$1, "float");
        $$ = new ASTNode(":=", leftVar, $3);
        delete $1;
    }
    | ID_BOOL ASSIGN bexp {
        if($3->type != "bool") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + $3->type + " to bool variable";
            yyerror(msg.c_str());
        }
        ASTNode* leftVar = new ASTNode(*$1, "bool");
        $$ = new ASTNode(":=", leftVar, $3);
        delete $1;
    }
    | ID_STR ASSIGN stexp {
        if($3->type != "string") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + $3->type + " to string variable";
            yyerror(msg.c_str());
        }
        ASTNode* leftVar = new ASTNode(*$1, "string");
        $$ = new ASTNode(":=", leftVar, $3);
        delete $1;
    }
    | ID_COM ASSIGN cexp {
        if($3->type != "com") {
            errorCount++;
            string msg = "Type mismatch in assignment: cannot assign " + $3->type + " to com variable";
            yyerror(msg.c_str());
        }
        ASTNode* leftVar = new ASTNode(*$1, "com");
        $$ = new ASTNode(":=", leftVar, $3);
        delete $1;
    }
    | ID OF ID ASSIGN typed_exp {
        string fieldType = "void";
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
            else {
                fieldType = info->classScope->getType($1);
                if (fieldType != $5->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + $5->type + " to " + fieldType + " field '" + *$1 + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete $1; delete $3;
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = fieldType;
    }
    | ID_INT OF ID ASSIGN typed_exp {
        string fieldType = "void";
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
            else {
                fieldType = info->classScope->getType($1);
                if (fieldType != $5->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + $5->type + " to " + fieldType + " field '" + *$1 + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete $1; delete $3;
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = fieldType;
    }
    | ID_FLOAT OF ID ASSIGN typed_exp {
        string fieldType = "void";
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
            else {
                fieldType = info->classScope->getType($1);
                if (fieldType != $5->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + $5->type + " to " + fieldType + " field '" + *$1 + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete $1; delete $3;
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = fieldType;
    }
    | ID_BOOL OF ID ASSIGN typed_exp {
        string fieldType = "void";
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
            else {
                fieldType = info->classScope->getType($1);
                if (fieldType != $5->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + $5->type + " to " + fieldType + " field '" + *$1 + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete $1; delete $3;
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = fieldType;
    }
    | ID_COM OF ID ASSIGN typed_exp {
        string fieldType = "void";
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
            else {
                fieldType = info->classScope->getType($1);
                if (fieldType != $5->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + $5->type + " to " + fieldType + " field '" + *$1 + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete $1; delete $3;
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = fieldType;
    }
    | ID_STR OF ID ASSIGN typed_exp {
        string fieldType = "void";
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; yyerror("Field does not exist"); }
            else {
                fieldType = info->classScope->getType($1);
                if (fieldType != $5->type) {
                     errorCount++;
                     string msg = "Field assignment type mismatch: cannot assign " + $5->type + " to " + fieldType + " field '" + *$1 + "'";
                     yyerror(msg.c_str());
                }
            }
        }
        delete $1; delete $3;
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = fieldType;
    }

    /*| ID ASSIGN exp
    | ID ASSIGN cexp
    | ID ASSIGN stexp
    | ID ASSIGN bexp*/ //not yet declared variables get generic id
    //can remove comment later after the semantic checks that the variable exists 
    | ID '(' call_list_typed ')' { 
        string funcType = "void";
        if(!current->existsId($1)) {
            errorCount++;
            string msg = "Function '" + *$1 + "' not defined";
            yyerror(msg.c_str());
        } else {
            // Verifică tipurile parametrilor
            IdInfo* funcInfo = current->getId($1);
            if(funcInfo && funcInfo->category == "func") {
                funcType = funcInfo->type;
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
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = funcType;
    }
    
    /* --- INCEPUT BLOC NOU PENTRU METODE --- */
    | ID OF ID '(' call_list_typed ')' {
        string methodType = "void";
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; string msg="Method '"+*$1+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId($1);
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else {
                    methodType = methodInfo->type;
                    if(methodInfo->params.size() != $5->size()) { errorCount++; yyerror("Wrong parameter count"); }
                    else {
                        for(size_t i=0; i<methodInfo->params.size(); i++) {
                            if(methodInfo->params[i] != $5->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                        }
                    }
                }
            }
        }
        delete $1; delete $3; delete $5;
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = methodType;
    }
    | ID_INT OF ID '(' call_list_typed ')' {
        string methodType = "void";
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; string msg="Method '"+*$1+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId($1);
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else {
                    methodType = methodInfo->type;
                    if(methodInfo->params.size() != $5->size()) { errorCount++; yyerror("Wrong parameter count"); }
                    else {
                        for(size_t i=0; i<methodInfo->params.size(); i++) {
                            if(methodInfo->params[i] != $5->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                        }
                    }
                }
            }
        }
        delete $1; delete $3; delete $5;
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = methodType;
    }
    | ID_FLOAT OF ID '(' call_list_typed ')' {
        string methodType = "void";
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; string msg="Method '"+*$1+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId($1);
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else {
                    methodType = methodInfo->type;
                    if(methodInfo->params.size() != $5->size()) { errorCount++; yyerror("Wrong parameter count"); }
                    else {
                        for(size_t i=0; i<methodInfo->params.size(); i++) {
                            if(methodInfo->params[i] != $5->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                        }
                    }
                }
            }
        }
        delete $1; delete $3; delete $5;
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = methodType;
    }
    | ID_BOOL OF ID '(' call_list_typed ')' {
        string methodType = "void";
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; string msg="Method '"+*$1+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId($1);
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else {
                    methodType = methodInfo->type;
                    if(methodInfo->params.size() != $5->size()) { errorCount++; yyerror("Wrong parameter count"); }
                    else {
                        for(size_t i=0; i<methodInfo->params.size(); i++) {
                            if(methodInfo->params[i] != $5->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                        }
                    }
                }
            }
        }
        delete $1; delete $3; delete $5;
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = methodType;
    }
    | ID_COM OF ID '(' call_list_typed ')' {
        string methodType = "void";
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; string msg="Method '"+*$1+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId($1);
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else {
                    methodType = methodInfo->type;
                    if(methodInfo->params.size() != $5->size()) { errorCount++; yyerror("Wrong parameter count"); }
                    else {
                        for(size_t i=0; i<methodInfo->params.size(); i++) {
                            if(methodInfo->params[i] != $5->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                        }
                    }
                }
            }
        }
        delete $1; delete $3; delete $5;
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = methodType;
    }
    | ID_STR OF ID '(' call_list_typed ')' {
        string methodType = "void";
        if(!current->existsId($3)) { errorCount++; yyerror("Object not defined"); }
        else {
            IdInfo* info = current->getId($3);
            if (!info->classScope) { errorCount++; yyerror("Variable is not a class instance"); }
            else if (!info->classScope->existsIdLocal($1)) { errorCount++; string msg="Method '"+*$1+"' does not exist"; yyerror(msg.c_str()); }
            else {
                IdInfo* methodInfo = info->classScope->getId($1);
                if(methodInfo->category != "func") { errorCount++; yyerror("Not a function"); }
                else {
                    methodType = methodInfo->type;
                    if(methodInfo->params.size() != $5->size()) { errorCount++; yyerror("Wrong parameter count"); }
                    else {
                        for(size_t i=0; i<methodInfo->params.size(); i++) {
                            if(methodInfo->params[i] != $5->at(i)) { errorCount++; yyerror("Parameter type mismatch"); }
                        }
                    }
                }
            }
        }
        delete $1; delete $3; delete $5;
        $$ = new ASTNode("OTHER", nullptr, nullptr);
        $$->type = methodType;
    }
    
    | PRINT '(' typed_exp ')' { $$ = new ASTNode("Print", $3, nullptr); }
    | VISUALIZE '(' cexp ')' { 
        $$ = new ASTNode("VisualizePoint", $3, nullptr); 
    }
    | VISUALIZE '(' FINAL ')' { 
        $$ = new ASTNode("VisualizeFinal", nullptr, nullptr); 
    }
    ;

block
    : '{' stmt_list '}' { $$ = $2; }
    ;

if_statement
    : IF '(' bexp ')' block { $$ = new ASTNode("IF", $3, $5); }
    | IF '(' bexp ')' block ELSE block { $$ = new ASTNode("IF", $3, $5); /* Simplified for now */ }
    ;

while_statement
    : WHILE '(' bexp ')' block { $$ = new ASTNode("WHILE", $3, $5); }
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