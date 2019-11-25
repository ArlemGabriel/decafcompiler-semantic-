#ifndef STACKTABLES_H_INCLUDED
#define STACKTABLES_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "ElementSCH.h"

using namespace std;
typedef ElementSCH * pElementSCH;

class TablesStack
{
private:
        std::vector<pElementSCH> tablestack;
        std::vector<pElementSCH> globalscope;
        std::vector<int> bracestructurepos;
        int stacksize = 0;
        int scopescounter = 0;
public:
        //Funcion que hace push de un elemento en la pila
        void Push(pElementSCH pNode) {
            tablestack.push_back(pNode);
            stacksize=stacksize+1;
        }
        //Funcion que imprime todos los elementos que hay en la pila
        void printStack(){
          if(stacksize!=0){
              for(int i=0; i<tablestack.size();i++){
                cout<< "Type: " <<tablestack.at(i)->type << " Token: " <<tablestack.at(i)->tokenE << " Value1: " <<tablestack.at(i)->value1->value << " Value2: " <<tablestack.at(i)->value2->value << " Column: " <<tablestack.at(i)->columnE <<" Line: " <<tablestack.at(i)->rowE <<"\n";
              }
          }else{
            cout << "PILA VACIA\n";
          }
        }
        //Funcion que saca el ultimo elemento ingresado en la pila
        void Pop(){
            if(stacksize>0){
                tablestack.pop_back();
                stacksize=stacksize-1;
            }
        }
        //Funcion que obtiene el ultimo scope ingresado en la pila
        pElementSCH GetLastScope(){
            if(stacksize>0){
                pElementSCH scope;
                scope = tablestack.at(stacksize-1);
                return scope;
            }
        }
        //Funcion que obtiene el tamano actual de la pila
        int GetStackSize(){
            return stacksize;
        }


        //Funcion que obtiene un elemento de la pila dado un indice
        pElementSCH GetScope(int position){
            if(0<=position<stacksize){
                pElementSCH scope;
                scope = tablestack.at(position);
                return scope;
            }
        }
        //Funcion que obtiene la pila
        vector<pElementSCH> GetTableStack(){
            return tablestack;
        }
        //Funcion que obtiene un elemento de la pila dado un indice
        pElementSCH at(int position){
            if(0<=position<stacksize){
                pElementSCH scope;
                scope = tablestack.at(position);
                return scope;
            }
        }
        //Funcion que ordena la lista de braces a borrar
        void SortBraces(){

            for (int i = 1; i < bracestructurepos.size(); ++i){
                for (int j = 0; j < bracestructurepos.size() - 1; ++j){
                    if (bracestructurepos.at(j) > bracestructurepos.at(i)) std::swap(bracestructurepos.at(j), bracestructurepos.at(i));
                }
            }
        }
        //Funcion que borra un brace que es parte de una estructura IF,ELSE,WHILE,FOR
        void DeleteBrace(int index){
          tablestack.erase(tablestack.begin() + index);
          stacksize=stacksize-1;
        }
        //Funcion que borra los braces que son parte de una estructura IF,ELSE,WHILE,FOR
        void DeleteStructureBraces(){
            int bracestructurepossize = bracestructurepos.size()-1;
            SortBraces();
            for(bracestructurepossize;0<=bracestructurepossize;bracestructurepossize--){
                int value = bracestructurepos.at(bracestructurepossize);
                DeleteBrace(value);
            }
        }
        //FUncion que pone indices de los scopes a los BRACES
        void SetBracesIndex(){
            int stackindex = GetStackSize()-1;
            int scopecounter = 0;
            string strscopecounter;
            for(stackindex;stackindex>=0;stackindex--){
                if(tablestack.at(stackindex)->tokenE == "RBRACE"){
                    scopecounter=scopecounter+1;
                    strscopecounter = to_string(scopecounter);
                    tablestack.at(stackindex)->value1->value = strscopecounter;
                    scopescounter = scopescounter+1;
                }
                if(tablestack.at(stackindex)->tokenE == "LBRACE"){
                    strscopecounter = to_string(scopecounter);
                    scopecounter=scopecounter-1;
                    tablestack.at(stackindex)->value1->value = strscopecounter;
                }
            }
        }
        //Funcion que pone a los braces faltantes si son parte de una estructura IF,ELSE,WHILE,FOR
        void SetBracesOwner(){
          int stackpositions = GetStackSize()-1;
          int sizebracestoclose;
          int sizerbracepositions;
          vector<pElementSCH> bracestoclose;
          pElementSCH element;
          vector<int> rbracepositions;
          bool isIf;
          bool isElse;
          bool isWhile;
          bool isFor;
          bool isValueEqual;
          bool isStructure;
          for(stackpositions;stackpositions>=0;stackpositions--){
                if(tablestack.at(stackpositions)->tokenE == "RBRACE"){
                      element= new ElementSCH(tablestack.at(stackpositions)->type,tablestack.at(stackpositions)->tokenE, tablestack.at(stackpositions)->value1,tablestack.at(stackpositions)->value2,tablestack.at(stackpositions)->rowE,tablestack.at(stackpositions)->columnE);
                      element->tokenE = "LBRACE";
                      bracestoclose.push_back(element);
                      int pos = bracestoclose.size()-1;
                      rbracepositions.push_back(stackpositions);
                }
                if(!bracestoclose.empty() && tablestack.at(stackpositions)->tokenE =="LBRACE"){
                      sizebracestoclose = bracestoclose.size()-1;
                      sizerbracepositions = rbracepositions.size()-1;
                      isIf = tablestack.at(stackpositions)->type == "IF";
                      isElse = tablestack.at(stackpositions)->type == "ELSE";
                      isWhile = tablestack.at(stackpositions)->type == "WHILE";
                      isFor = tablestack.at(stackpositions)->type == "FOR";
                      isValueEqual = tablestack.at(stackpositions)->value1->value==bracestoclose.at(sizebracestoclose)->value1->value;
                      isStructure = (isIf || isElse || isWhile ||isFor);
                      if(isValueEqual && isStructure){
                            element= new ElementSCH(tablestack.at(stackpositions)->type,tablestack.at(stackpositions)->tokenE, tablestack.at(stackpositions)->value1,tablestack.at(stackpositions)->value2,tablestack.at(stackpositions)->rowE,tablestack.at(stackpositions)->columnE);
                            element->tokenE = "RBRACE";
                            tablestack.at(rbracepositions.at(sizerbracepositions)) = element;
                            bracestructurepos.push_back(stackpositions);
                            bracestructurepos.push_back(rbracepositions.at(sizerbracepositions));
                            bracestoclose.pop_back();
                            rbracepositions.pop_back();
                      }else{
                            bracestoclose.pop_back();
                            rbracepositions.pop_back();
                      }
                }
          }
        }
        //Funcion booleana que retorna si la pila esta vacia o no
        bool isEmpty(){
            if(GetStackSize()==0){
                return true;
            }else{
                return false;
            }
        }
        //Funcion que obtiene una subpila desde una posicion inicial
        vector<pElementSCH> GetStackFromValue(int positionfrom){
            vector<pElementSCH> tempstacktable;
            for(int i=0;i<=positionfrom;i++){
                tempstacktable.push_back(tablestack.at(i));
            }
            return tempstacktable;
        }

};


#endif // STACKTABLES_H_INCLUDED
