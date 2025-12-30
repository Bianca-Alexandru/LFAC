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
        if (l.type == "com" && r.type == "com")
            return Value(l.comValue.real + r.comValue.real, l.comValue.imag + r.comValue.imag);
    }

    if (root == "-") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int") return Value(l.intValue - r.intValue);
        if (l.type == "float") return Value(l.floatValue - r.floatValue);
        if (l.type == "com") return Value(l.comValue.real - r.comValue.real, l.comValue.imag - r.comValue.imag);
    }

    if (root == "*") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int") return Value(l.intValue * r.intValue);
        if (l.type == "float") return Value(l.floatValue * r.floatValue);
        if (l.type == "com") {
            float real = (l.comValue.real * r.comValue.real) - (l.comValue.imag * r.comValue.imag);
            float imag = (l.comValue.real * r.comValue.imag) + (l.comValue.imag * r.comValue.real);
            return Value(real, imag);
        }
    }

    if (root == "/") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int") {
            if (r.intValue == 0) { cout << "Runtime Error: Division by zero" << endl; return Value(0); }
            return Value(l.intValue / r.intValue);
        }
        if (l.type == "float") {
            if (r.floatValue == 0) { cout << "Runtime Error: Division by zero" << endl; return Value(0.0f); }
            return Value(l.floatValue / r.floatValue);
        }
        if (l.type == "com") {
            float denom = (r.comValue.real * r.comValue.real) + (r.comValue.imag * r.comValue.imag);
            if (denom == 0) { cout << "Runtime Error: Division by zero" << endl; return Value(0.0f, 0.0f); }
            float real = ((l.comValue.real * r.comValue.real) + (l.comValue.imag * r.comValue.imag)) / denom;
            float imag = ((l.comValue.imag * r.comValue.real) - (l.comValue.real * r.comValue.imag)) / denom;
            return Value(real, imag);
        }
    }

    // Boolean Expressions
    if (root == "<") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int") return Value(l.intValue < r.intValue);
        return Value(l.floatValue < r.floatValue);
    }
    if (root == ">") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int") return Value(l.intValue > r.intValue);
        return Value(l.floatValue > r.floatValue);
    }
    if (root == "<=") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int") return Value(l.intValue <= r.intValue);
        return Value(l.floatValue <= r.floatValue);
    }
    if (root == ">=") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int") return Value(l.intValue >= r.intValue);
        return Value(l.floatValue >= r.floatValue);
    }
    if (root == "==") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int") return Value(l.intValue == r.intValue);
        if (l.type == "float") return Value(l.floatValue == r.floatValue);
        if (l.type == "bool") return Value(l.boolValue == r.boolValue);
        if (l.type == "string") return Value(l.stringValue == r.stringValue);
        if (l.type == "com") return Value(l.comValue.real == r.comValue.real && l.comValue.imag == r.comValue.imag);
    }
    if (root == "!=") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        if (l.type == "int") return Value(l.intValue != r.intValue);
        if (l.type == "float") return Value(l.floatValue != r.floatValue);
        if (l.type == "bool") return Value(l.boolValue != r.boolValue);
        if (l.type == "string") return Value(l.stringValue != r.stringValue);
        if (l.type == "com") return Value(l.comValue.real != r.comValue.real || l.comValue.imag != r.comValue.imag);
    }

    if (root == "&&") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        return Value(l.boolValue && r.boolValue);
    }
    if (root == "||") {
        Value l = left->eval(table);
        Value r = right->eval(table);
        return Value(l.boolValue || r.boolValue);
    }

    if (root == "!") {
        Value l = left->eval(table);
        return Value(!l.boolValue);
    }

    if (root == "UMINUS") {
        Value l = left->eval(table);
        if (l.type == "int") return Value(-l.intValue);
        if (l.type == "float") return Value(-l.floatValue);
        return l;
    }

    if (root == "MAG") {
        Value l = left->eval(table);
        return Value((float)sqrt(pow(l.comValue.real, 2) + pow(l.comValue.imag, 2)));
    }
    if (root == "REAL") {
        Value l = left->eval(table);
        return Value(l.comValue.real);
    }
    if (root == "IMAG") {
        Value l = left->eval(table);
        return Value(l.comValue.imag);
    }

    // Dummy return for "OTHER" nodes (function calls, etc.)
    if (root == "OTHER") {
        return Value(this->type, true); // Returns default value for the return type
    }

    return Value();
}