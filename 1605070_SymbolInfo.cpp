//
// Created by tushar on 5/8/19.
//

#include "1605070_SymbolInfo.h"

SymbolInfo::SymbolInfo(){
    name = "";
    type = "";
    code = "";
    category = "";
    next = nullptr;
    isDefined = false;
}

SymbolInfo::SymbolInfo(string name, string type) {
    this->name = name;
    this->type = type;
    next = nullptr;
    isDefined = false;
}

const string & SymbolInfo::getName() const {
    return name;
}

const string & SymbolInfo::getCode() const {
    return code;
}

const string & SymbolInfo::getCategory() const {
    return category;
}

const string & SymbolInfo::getSymbol() const {
    return symbol;
}

SymbolInfo * SymbolInfo::getNext() const {
    return next;
}

void SymbolInfo::setNext(SymbolInfo *next) {
    SymbolInfo::next = next;
}

void SymbolInfo::setName(const string &name) {
    SymbolInfo::name = name;
}

void SymbolInfo::setCode(const string &code) {
    SymbolInfo::code = code;
}

void SymbolInfo::setCategory(const string &category) {
    SymbolInfo::category = category;
}

const string &SymbolInfo::getType() const {
    return type;
}

void SymbolInfo::setType(const string &type) {
    // SymbolInfo::type = type;
    this->type = type;
}

void SymbolInfo::setSymbol(const string &symbol) {
    SymbolInfo::symbol = symbol;
}

SymbolInfo::~SymbolInfo() {

}
