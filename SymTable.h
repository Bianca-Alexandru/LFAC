#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
class SymTable;
class IdInfo {
    public:
    string type;
    string name;
    string category; // var /func / param / class
    vector<string> params; // for func only
    SymTable* classScope; //pastreaza scopul functiei
    IdInfo() : classScope(NULL){}//adaugam pt initializare
    IdInfo(string* type, string* name, string* category) : type(*type), name(*name), category(*category) {}
};

class SymTable {
    SymTable* parent;
    map<string, IdInfo> ids;
    string name;
    public:
    SymTable(const char* name, SymTable* parent = NULL) :  name(name), parent(parent) {}
    bool existsId(string* s);
    void addSym(string* type, string* name, string* category, vector<string> params = {});
    void printVars();
    SymTable* getParent() { return parent; }
    string getType(string* name);
    //vf daca field ul exista in clasa
     SymTable* getClassScope(string* className);//găsește scope-ul unei clase (unde sunt definite field-urile ei)
    bool hasField(string* className, string* fieldName);//verifică dacă un field există în clasă
    string getFieldType(string* className, string* fieldName);//: returnează tipul unui field din clasă
    void setClassScopeForId(string* idName, SymTable* scope);
    string getName() {return name;}//name există, dar este privat
    IdInfo* getId(string* s);
    ~SymTable();
};






