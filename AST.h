#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "SymTable.h"

using namespace std;

class SymTable;

class ASTNode {
public:
    ASTNode *left, *right;
    string root;
    string type;
    Value val;
    bool isLiteral;

    ASTNode(string op, ASTNode* l, ASTNode* r) : root(op), left(l), right(r), isLiteral(false) {}
    ASTNode(Value v) : root(""), left(nullptr), right(nullptr), val(v), type(v.type), isLiteral(true) {}
    ASTNode(string name, string t) : root(name), left(nullptr), right(nullptr), type(t), isLiteral(false) {}

    virtual ~ASTNode() {
        if (left) delete left;
        if (right) delete right;
    }

    Value eval(SymTable* table); 
};

#endif