#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
class SymTable;

class Value {
public:
    string type;
    union {
        int intValue;
        float floatValue;
        bool boolValue;
    };
    struct { float real; float imag; } comValue; 
    string stringValue;

    Value() : type("void"), intValue(0) {}
    Value(int v) : type("int"), intValue(v) {}
    Value(float v) : type("float"), floatValue(v) {}
    Value(bool v) : type("bool"), boolValue(v) {}
    Value(float r, float i) : type("com") { comValue.real = r; comValue.imag = i; }
    Value(string v) : type("string"), stringValue(v) {}

    // Default value constructor
    Value(string t, bool isType) : type(t) {
        if (t == "int") intValue = 0;
        else if (t == "float") floatValue = 0.0f;
        else if (t == "bool") boolValue = false;
        else if (t == "com") { comValue.real = 0; comValue.imag = 0; }
        else if (t == "string") stringValue = "";
    }

    Value(const Value& other) {
        type = other.type;
        intValue = other.intValue;
        floatValue = other.floatValue;
        boolValue = other.boolValue;
        comValue = other.comValue;
        stringValue = other.stringValue;
    }

    Value& operator=(const Value& other) {
        if (this != &other) {
            type = other.type;
            intValue = other.intValue;
            floatValue = other.floatValue;
            boolValue = other.boolValue;
            comValue = other.comValue;
            stringValue = other.stringValue;
        }
        return *this;
    }

    string toString() const {
        if (type == "int") return to_string(intValue);
        if (type == "float") return to_string(floatValue);
        if (type == "bool") return boolValue ? "T" : "F";
        if (type == "com") return to_string(comValue.real) + " + " + to_string(comValue.imag) + "i";
        if (type == "string") return stringValue;
        return "";
    }
};

class IdInfo {
    public:
    string type;
    string name;
    string category; // var /func / param / class
    vector<string> params; // for func only
    SymTable* classScope; //pastreaza scopul functiei

    Value val;

    IdInfo() : classScope(NULL){}//adaugam pt initializare
    IdInfo(string* type, string* name, string* category) : type(*type), name(*name), category(*category), classScope(NULL) {
        val = Value(*type, true);
    }
};

class SymTable {
    SymTable* parent;
    map<string, IdInfo> ids;
    string name;

public:
    SymTable(const char* name, SymTable* parent = NULL) :  name(name), parent(parent) {}
    void printVars();
    bool existsId(string* s);
    bool existsIdLocal(string* s); 
    void addSym(string* type, string* name, string* category, vector<string> params = {});
    SymTable* getParent() { return parent; }
    string getType(string* name);
    string getName() {return name;}//name există, dar este privat
    IdInfo* getId(string* s);
    //vf daca field ul exista in clasa
    SymTable* getClassScope(string* className);//găsește scope-ul unei clase (unde sunt definite field-urile ei)
    
    string getFieldType(string* className, string* fieldName);//: returnează tipul unui field din clasă
    bool hasField(string* className, string* fieldName);//verifică dacă un field există în clasă
    
    void setClassScopeForId(string* idName, SymTable* scope);

    Value getValue(string name);
    void setValue(string name, Value v);
    
    ~SymTable();
};

#endif






