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

void SymTable::printVars() {
    for (const pair<string, IdInfo>& v : ids) {
        cout << "name: " << v.first << " type:" << v.second.type << endl; 
     }
}
string SymTable::getType(string* name) {
    if (ids.count(*name)) return ids[*name].type;
    if (parent) return parent->getType(name);
    return "";
}

SymTable::~SymTable() {
    ids.clear();
}











