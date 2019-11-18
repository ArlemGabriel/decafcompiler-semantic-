#ifndef AUXILIARYFUNCTIONS_H_INCLUDED
#define AUXILIARYFUNCTIONS_H_INCLUDED

#include <vector>
#include "stacktables.h"
#include <string>
#include <regex>

vector<string> semanticerrors;

bool SearchRepeats(string error){
    bool searchresult = false;
    if(!semanticerrors.empty()){
        for(int i=0;i<=semanticerrors.size()-1;i++){
            if(semanticerrors.at(i)==error){
                searchresult = true;
            }
        }
    }
    return searchresult;
}

void printErrors(){
    for(int i=0;i<=semanticerrors.size()-1;i++){
        cout << semanticerrors.at(i);
    }

}

void ScopeCheckingVariables(TablesStack tb){
//Desde aquí tengo que hacer pop
    int stackpositions = tb.GetStackSize()-1;
    vector<vector<string> > tempscope;
    bool searchresult = false;
    bool repeatsresult = false;
    for(stackpositions;stackpositions>=0;stackpositions--){
        tempscope = tb.GetScope(stackpositions);
        int scopepositions = tempscope.size()-1;
        for(int i =0;i<=scopepositions;i++){
            string token = tempscope.at(i).at(1);
            string type = tempscope.at(i).at(0);
            if(token == "="){
                cout << "Variable a buscar: " << type << "\n";
                searchresult = tb.SearchVariableDecl(type);
                if(searchresult == false){
                    string strerror = "\nERROR: Undeclared variable "+type+"\n";
                    repeatsresult = SearchRepeats(strerror);
                    if(repeatsresult==false){
                        semanticerrors.push_back(strerror);
                    }
                }
            }
        }
        //Aquí se puede poner la condición de que si existe un error entonces imprimirlo y no hacer pop
        tb.Pop();
    }
    if(!semanticerrors.empty()){
        printErrors();
    }
    /*cout << "\n------------------------------------------------------------------------------\n";
    cout << "\nCantidad de Scopes despues del scope checking: " << tb.GetStackSize() << "\n";
    cout << "\n------------------------------------------------------------------------------\n";*/

}
void isFloat(string str){
try {

    } catch(std::invalid_argument& e) {
        cout << " the integer exception was caught, with value: " << '\n';
    }
}
int isString(){
    /*string str = "5";
    regex reg ("([a-zA-Z]{1}[a-zA-Z|0-9|_]{0,30})");
    smatch matches;
    regex_search(str,matches,reg);
    cout << matches.ready();*/
}
void isDouble(){

}
void isInteger(){

}
void isBool(){

}

#endif // AUXILIARYFUNCTIONS_H_INCLUDED
