#include "AST.h"

Value ASTNode::eval(SymTable* table) {
    if (isLiteral) {
        return val;
    }

    // Leaf node: variable lookup
    if (left == nullptr && right == nullptr) {
        return table->getValue(root);
    }

    // Assignment statement: ID := expr
    if (root == ":=") {
        Value rightVal = right->eval(table);
        // left->root contains the name of the identifier
        table->setValue(left->root, rightVal);
        return rightVal;
    }

    // Print statement: Print(expr)
    if (root == "Print") {
        Value v = left->eval(table);
        cout << v.toString() << endl;
        return v;
    }

    // Arithmetic Expressions
    if (root == "+") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int" && r.type == "int") 
            return Value(l.intValue + r.intValue);
        if (l.type == "float" && r.type == "float") 
            return Value(l.floatValue + r.floatValue);
        if (l.type == "string" && r.type == "string")
            return Value(l.stringValue + r.stringValue);
    }

    if (root == "-") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int") return Value(l.intValue - r.intValue);
        return Value(l.floatValue - r.floatValue);
    }

    if (root == "*") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int") return Value(l.intValue * r.intValue);
        return Value(l.floatValue * r.floatValue);
    }

    // Boolean Expressions
    if (root == "<") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int") return Value(l.intValue < r.intValue);
        return Value(l.floatValue < r.floatValue);
    }

    if (root == "&&") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        return Value(l.boolValue && r.boolValue);
    }

    if (root == "!") {
        Value l = left->eval(table);
        return Value(!l.boolValue);
    }

    // Dummy return for "OTHER" nodes (function calls, etc.)
    if (root == "OTHER") {
        return Value(this->type, true); // Returns default value for the return type
    }

    return Value();
}