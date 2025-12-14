#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class IdInfo {
    public:
    string type;
    string name;
    string category; // var /func / param / class
    vector<string> params; // for func only
   
    IdInfo() {}
    IdInfo(string* type, string* name, string* category) : type(*type), name(*name), category(*category) {}
};

class SymTable {
    SymTable* parent;
    map<string, IdInfo> ids;
    string name;
    public:
    SymTable(const char* name, SymTable* parent = NULL) :  name(name), parent(parent) {}
    bool existsId(string* s);
    void addSym(string* type, string* name, string* category);
    void printVars();
    SymTable* getParent() { return parent; }
    string getType(string* name);
    ~SymTable();
};






