//
// Created by tushar on 5/8/19.
//

#ifndef SYMBOL_TABLE_SYMBOLINFO_H
#define SYMBOL_TABLE_SYMBOLINFO_H

#include <string>
#include <vector>
using namespace std;

class SymbolInfo {
private:
    string name;
    string type;
    string category;
    string symbol;
    SymbolInfo *next;

public:
    string code;
    vector<string> parameterList;
    bool isDefined;

    SymbolInfo();

    SymbolInfo(string name, string type);

    const string &getName() const;

    const string &getCode() const;

    const string &getCategory() const;

    const string &getSymbol() const;

    SymbolInfo *getNext() const;

    void setNext(SymbolInfo *next);

    void setName(const string &name);

    void setCode(const string &code);

    void setCategory(const string &category);

    const string &getType() const;

    void setType(const string &type);

    void setSymbol(const string &symbol);

    ~SymbolInfo();

};


#endif //SYMBOL_TABLE_SYMBOLINFO_H
