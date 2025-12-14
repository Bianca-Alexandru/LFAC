#include "SymTable.h"
using namespace std;

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

SymTable::~SymTable() {
    ids.clear();
}











