#ifndef STACKTABLES_H_INCLUDED
#define STACKTABLES_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "ElementSCH.h"

using namespace std;
typedef ElementSCH * pElementSCH;

class TablesStack{
private:
        std::vector<pElementSCH> tablestack;
        std::vector<pElementSCH> globalscope;
        int stacksize = 0;
        int scopescounter = 0;
public:
        void Push(pElementSCH pNode) {
            tablestack.push_back(pNode);
            stacksize=stacksize+1;
        }
        void printStack(){
          for(int i=0; i<tablestack.size();i++){
            cout<< "Type: " <<tablestack.at(i)->type << " Token: " <<tablestack.at(i)->tokenE << " Value1: " <<tablestack.at(i)->value1->value << " Value2: " <<tablestack.at(i)->value2->value << " Column: " <<tablestack.at(i)->columnE <<" Line: " <<tablestack.at(i)->rowE <<"\n";
          }
        }

        void Pop(){
            tablestack.pop_back();
            if(stacksize>0){
                stacksize=stacksize-1;
            }
        }
        /*
        vector<vector<string> > GetLastScope(){
            if(stacksize>0){
                vector<vector<string> > scope;
                scope = tablestack.at(stacksize-1);
                return scope;
            }
        }
        int GetTableScopesSize(vector<vector<string> > ptable){
            int tempsize = ptable.size();
            return tempsize;
        }

        int GetStackSize(){
            return stacksize;
        }
        vector<vector<string> > GetScope(int position){
            vector<vector<string> > scope;
            scope = tablestack.at(position);
            return scope;
        }
        vector<vector<vector<string> > > GetTableStack(){
            return tablestack;
        }
        void SetGlobalScope(){
            globalscope = tablestack.at(0);
        }
        void SetBracesIndex(){
            int stackindex = GetStackSize()-1;
            int scopecounter = 0;
            string strscopecounter;
            for(stackindex;stackindex>=0;stackindex--){
                vector<vector<string> > scope;
                scope = tablestack.at(stackindex);
                for(int i=0;i<=scope.size()-1;i++){
                    if(scope.at(i).at(1) == "RBRACE"){
                        scopecounter=scopecounter+1;
                        strscopecounter = to_string(scopecounter);
                        scope.at(i).at(2) = strscopecounter;
                        scopescounter = scopescounter+1;
                    }
                    if(scope.at(i).at(1) == "LBRACE"){
                        strscopecounter = to_string(scopecounter);
                        scopecounter=scopecounter-1;
                        scope.at(i).at(2) = strscopecounter;
                    }
                }
                tablestack.at(stackindex) = scope;

            }
        }
        void printStack(){
            int stackindex = GetStackSize()-1;
            for(stackindex;stackindex>=0;stackindex--){
                vector<vector<string> > scope;
                scope = tablestack.at(stackindex);
                for(int i=0;i<=scope.size()-1;i++){
                    cout << scope.at(i).at(1) << " Valor: "<< scope.at(i).at(2)<< "\n";
                }
            }
        }
        bool isEmpty(){
            if(GetStackSize()==0){
                return true;
            }else{
                return false;
            }
        }
        vector<vector<vector<string> > > GetStackFromValue(int positionfrom){
            vector<vector<vector<string> > > tempstacktable;
            vector<vector<vector<string> > > tempstacktable2;
            for(positionfrom;positionfrom>=0;positionfrom--){
                tempstacktable.push_back(tablestack.at(positionfrom));
            }
            int position = tempstacktable.size()-1;
            for(position;position>=0;position--){
                tempstacktable2.push_back(tempstacktable.at(position));
            }
            return tempstacktable2;
        }*/

};


#endif // STACKTABLES_H_INCLUDED
