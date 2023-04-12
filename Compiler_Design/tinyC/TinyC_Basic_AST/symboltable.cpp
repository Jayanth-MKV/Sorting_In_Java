#include <iostream>
using namespace std;
#include "symboltable.hh"

SymbolTableEntry::SymbolTableEntry(){
	variablename="";
	variabledatatype=INT;
	scope=LOCAL;
	lineNumber=0;
}

SymbolTableEntry::SymbolTableEntry(string &s, DataType d, int a){
	variablename=s;
        variabledatatype=d;
        lineNumber=a;
}

int SymbolTableEntry::getLineNumber(){
	return lineNumber;
}

void SymbolTableEntry::setSymbolScope(TableScope sp){
	scope=sp;
}

 TableScope SymbolTableEntry :: getSymbolScope(){
 	return scope;
 }

 DataType  SymbolTableEntry :: getDataType(){
 	return variabledatatype;
 }

void SymbolTableEntry :: setDataType(DataType d){
	variabledatatype=d;
}

string  SymbolTableEntry :: getVariableName(){
	return variablename;
}




SymbolTable:: SymbolTable(){
	scope=LOCAL;
}

SymbolTable:: ~SymbolTable(){
	varTable.clear();
}

TableScope SymbolTable::  getTableScope(){
	return scope;
}

void SymbolTable :: setTableScope(TableScope s){
	scope=s;
}

void SymbolTable :: print(ostream &f){
	f<<"SymbolTableEntry - ";
	f<<"TableScope : "<<((scope)==LOCAL?"LOCAL":"")<<endl;
	list<SymbolTableEntry*>::iterator it;
        for(it=varTable.begin();it!=varTable.end();it++){
		f<<(*it)->getVariableName()<<" "<<(((*it)->getDataType())==INT?"INT":"")<<" "<<(((*it)->getSymbolScope())==LOCAL?"LOCAL":"")<<" "<<(*it)->getLineNumber()<<endl;
        }
	f<<endl;
}

void SymbolTable :: pushSymbol(SymbolTableEntry * se){
	varTable.push_back(se);
}

bool SymbolTable :: variableInSymbolListCheck(string s){
	list<SymbolTableEntry*>::iterator it;
	for(it=varTable.begin();it!=varTable.end();it++){
		if(!(s.compare((*it)->getVariableName())))
			return true;
	}
	return false;
}

SymbolTableEntry & SymbolTable ::  getSymbolTableEntry(string variablename){
	list<SymbolTableEntry*>::iterator it;
        SymbolTableEntry *ste=NULL;
	for(it=varTable.begin();it!=varTable.end();it++){
                if((*it)->getVariableName()==variablename)
                        return **it;
        }
	return *ste;
}
