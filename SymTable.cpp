#include "SymTable.h"
#include "AST.h"
using namespace std;

IdInfo* SymTable::getId(string* s) {
    if (ids.count(*s))
        return &ids[*s];
    return NULL;
}

void SymTable::addSym(string* type, string*name, string* category, vector<string> params) {
    IdInfo var(type, name, category);
    var.params = params;
    ids[*name] = var; 
}

bool SymTable::existsId(string* var) {
    if(ids.count(*var)) return true;
    if (parent) return parent->existsId(var);
    return false;
}
bool SymTable::existsIdLocal(string* var) {
    return ids.count(*var) > 0;
}
void SymTable::setClassScopeForId(string* idName, SymTable* scope) {
    if(ids.count(*idName)) {
        ids[*idName].classScope = scope;
    }
}

void printSpaces(int n) {
    if (n < 1) n = 0; 
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}

void SymTable::printVars() {
    cout << "Scope: " << name;
    if (parent) {
        cout << " (Parent: " << parent->name << ")";
    } else {
        cout << " (Root)";
    }
    cout << endl;

    for (const pair<string, IdInfo>& v : ids) {
        const IdInfo& info = v.second;

        cout << "   Symbol: " << info.name;
        printSpaces(15 - info.name.length());
        cout << "| Category: " << info.category;
        printSpaces(5 - info.category.length());
        cout << "| Type: " << info.type;
        printSpaces(5 - info.type.length());

        if (!info.params.empty()) {
            cout << " | Param Types: [";
            for (size_t i = 0; i < info.params.size(); ++i) {
                cout << info.params[i];
                if (i < info.params.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "]";
        }
        cout << endl;
    }
    cout << endl; 
}
string SymTable::getType(string* name) {
    if (ids.count(*name)) return ids[*name].type;
    if (parent) return parent->getType(name);
    return "";
}

SymTable* SymTable::getClassScope(string* className) {
    // Căutăm clasa în scope-ul curent
    if(ids.count(*className) && ids[*className].category == "class") {
        return ids[*className].classScope;
    }
    // Dacă nu e în scope-ul curent, căutăm în parent
    if(parent) return parent->getClassScope(className);
    return NULL;
}

bool SymTable::hasField(string* className, string* fieldName) {
    SymTable* classTable = getClassScope(className);
    if(classTable) {
        return classTable->existsId(fieldName);
    }
    return false;
}

string SymTable::getFieldType(string* className, string* fieldName) {
    SymTable* classTable = getClassScope(className);
    if(classTable) {
        return classTable->getType(fieldName);
    }
    return "";
}
SymTable::~SymTable() {//dadea eroare ca e declarat si nefolosit
    // nimic de eliberat explicit
}

Value SymTable::getValue(string name) {
    if (ids.count(name)) {
        return ids[name].val; 
    }
    if (parent) return parent->getValue(name);
    
    return Value(); 
}

void SymTable::setValue(string name, Value v) {
    if (ids.count(name)) {
        ids[name].val = v;
    } else if (parent) {
        parent->setValue(name, v); 
    }
}











