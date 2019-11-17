#ifndef STACKTABLES_H_INCLUDED
#define STACKTABLES_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

class TablesStack{
private:
        std::vector<vector<vector<string> > > tablestack;
        std::vector<vector<string> > globalscope;
        int stacksize = 0;
public:
        void Push(vector<vector<string> > ptable) {
            tablestack.push_back(ptable);
            stacksize=stacksize+1;
        }
        void Pop(){
            tablestack.pop_back();
            if(stacksize>0){
                stacksize=stacksize-1;
            }
        }
        int GetTableScopesSize(vector<vector<string> > ptable){
            int tempsize = ptable.size();
            return tempsize;
        }
        //Función: SearchVariableDecl
        //Descripción: Busca si una variable está declarada en algún scope.
        bool SearchVariableDecl(string token){
            //Variable: table
            //Descripción: Variable temporal que guardará las variables pertenecientes a un scope
            vector<vector<string> > table;
            bool result = false;
            if(!tablestack.empty()){
                int tempsizestack = stacksize-1;
                //cout << "Cantidad de Elementos en la Pila: " << stacksize;
                //Ciclo que recorre la pila(scopes)
                for(tempsizestack; tempsizestack>=0; tempsizestack--){
                    //cout << "\nScope # " << tempsizestack << "\n" ;
                    table = tablestack.at(tempsizestack);
                    int tablesize = GetTableScopesSize(table);
                    //cout << "\nSize Scope: " << tablesize << "\n" ;
                    //Ciclo que busca en un scope si existe una variable
                    for(int i =0;i<=tablesize-1;i++){
                        if(table.at(i).at(3)=="vardecl" && table.at(i).at(1)==token){
                            cout << "                 \n-------------------------------------------\n";
                            cout << "                  BUSQUEDA EN SCOPE LOCAL\n";
                            cout << "\nKeyword: " << table.at(i).at(0) << " Token: " << table.at(i).at(1) << " Value: " << table.at(i).at(2) <<" Tipo: " << table.at(i).at(3) <<"\n";
                            cout << "                 \n-------------------------------------------\n";
                            return true;
                        }else{
                            if(table.at(i).at(3)=="func"){
                                result = SearchVariableOnGlobalScope(token);
                                if(result==true){
                                    return true;
                                }else{
                                    return false;
                                }

                            }
                        }
                    }
                }
            }
        }
        int GetStackSize(){
            return stacksize;
        }
        vector<vector<string> > GetScope(int position){
            vector<vector<string> > scope;
            scope = tablestack.at(position);
            return scope;
        }
        void SetGlobalScope(){
            globalscope = tablestack.at(0);
        }
        bool SearchVariableOnGlobalScope(string token){
            for(int i=0;i<=globalscope.size()-1;i++){
                if(globalscope.at(i).at(1) == token){
                    cout << "                 \n-------------------------------------------\n";
                    cout << "                 BUSQUEDA EN SCOPE GLOBAL\n";
                    cout << "\n               Keyword: " << globalscope.at(i).at(0) << " Token: " << globalscope.at(i).at(1) << " Value: " << globalscope.at(i).at(2) <<" Tipo: " << globalscope.at(i).at(3) <<"\n";
                    cout << "                 -------------------------------------------\n";
                    return true;
                }else{
                    cout << "                 \n-------------------------------------------\n";
                    cout << "                 BUSQUEDA EN SCOPE GLOBAL\n";
                    cout << "\n               VARIABLE NO ENCONTRADA";
                    cout << "                 -------------------------------------------\n";
                    return false;
                }
            }
        }

};


#endif // STACKTABLES_H_INCLUDED
