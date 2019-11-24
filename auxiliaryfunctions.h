#ifndef AUXILIARYFUNCTIONS_H_INCLUDED
#define AUXILIARYFUNCTIONS_H_INCLUDED

#include <vector>
#include "stacktables.h"
#include "ElementSCH.h"


vector<string> semanticerrors;
vector<pElementSCH> undeclaredvariables;


vector<pElementSCH> SortErrors(vector<pElementSCH> scope)
{

    for (int i = 1; i < scope.size(); ++i){
        for (int j = 0; j < scope.size() - 1; ++j){
            if (scope.at(j)->rowE > scope.at(i)->rowE) std::swap(scope.at(j), scope.at(i));
        }
    }
    return scope;
}
vector<pElementSCH> PushErrors(vector<pElementSCH> scope)
{
    string error;
    string variable;
    string column;
    string row;
    for(int i=0;i<scope.size();i++){
      variable = scope.at(i)->value1->value;
      column = to_string(scope.at(i)->columnE);
      row = to_string(scope.at(i)->rowE);
      error = "Undeclared variable: "+ variable +" at column: "+ column +" on line: "+ row +"\n";
      semanticerrors.push_back(error);
    };
}
//Funcion que imprime los errores semanticos encontrados
void printSemanticErrors(){
    if(undeclaredvariables.empty()){
        cout << "No errors found\n";
    }
    else{
        undeclaredvariables=SortErrors(undeclaredvariables);
        PushErrors(undeclaredvariables);
        for(int i=0;i<=semanticerrors.size()-1;i++){
            cout << semanticerrors.at(i);
        }
    }


}

/*bool SearchRepeats(string error){
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
vector<vector<string> > SearchGlobalVariablesClasses(vector<vector<vector<string> > > tb,string scopevalue){
    int stackpositions = tb.size()-1;
    vector<vector<string> > tempscope;
    vector<vector<string> > globaldecl;
    vector<vector<string> > bracestoclose;
    for(stackpositions;stackpositions>=0;stackpositions--){
        tempscope = tb.at(stackpositions);
        int scopepositions = tempscope.size()-1;
        bool searchEnded = false;

        for(int i =0;i<=scopepositions;i++){
                if(tempscope.at(i).at(1) == "LBRACE" && tempscope.at(i).at(2)==scopevalue){
                    searchEnded = true;
                }
                if(tempscope.at(i).at(1) == "RBRACE"){
                    tempscope.at(i).at(1) = "LBRACE";
                    bracestoclose.push_back(tempscope.at(i));
                    tempscope.at(i).at(1) = "RBRACE";
                }
                if(!bracestoclose.empty() && tempscope.at(i).at(1)=="LBRACE"){
                    int sizebracestoclose = bracestoclose.size()-1;
                    if(tempscope.at(i).at(2)==bracestoclose.at(sizebracestoclose).at(2)){
                        bracestoclose.pop_back();
                    }
                }
                if(bracestoclose.empty() && tempscope.at(i).at(1)=="Variable"){
                    globaldecl.push_back(tempscope.at(i));
                }
        }

    }
    return globaldecl;

}
vector<vector<vector<string> > > SearchLocalVariablesClasses(TablesStack tb, string scopevalue){
    int stackpositions = tb.GetStackSize()-1;
    int finalscopeposition;
    int newscopeglobalvalue;
    string finalscopevalue;
    vector<vector<vector<string> > > listscopes;
    vector<vector<string> > tempscope;
    vector<vector<string> > localdecl;
    vector<vector<string> > globaldecl;
    vector<vector<string> > bracestoclose;
    vector<vector<string> > intermediatescopes;
    vector<vector<vector<string> > > globalscopes;

    for(stackpositions;stackpositions>=0;stackpositions--){
        tempscope = tb.GetScope(stackpositions);
        int scopepositions = tempscope.size()-1;
        bool searchEnded = false;

        for(int i =0;i<=scopepositions;i++){
                if(tempscope.at(i).at(1) == "LBRACE" && tempscope.at(i).at(2)==scopevalue){
                    finalscopeposition = stackpositions-1;
                    newscopeglobalvalue = stoi(scopevalue)-1;
                    finalscopevalue = to_string(newscopeglobalvalue);
                    searchEnded = true;
                }
                if(tempscope.at(i).at(1) == "RBRACE"){
                    tempscope.at(i).at(1) = "LBRACE";
                    bracestoclose.push_back(tempscope.at(i));
                    tempscope.at(i).at(1) = "RBRACE";
                }
                if(!bracestoclose.empty() && tempscope.at(i).at(1)=="LBRACE"){
                    int sizebracestoclose = bracestoclose.size()-1;
                    if(tempscope.at(i).at(2)==bracestoclose.at(sizebracestoclose).at(2)){
                        bracestoclose.pop_back();
                    }
                }
                if(bracestoclose.empty() && tempscope.at(i).at(1)=="Exp"){
                    intermediatescopes.push_back(tempscope.at(i));
                }
                if(bracestoclose.empty() && tempscope.at(i).at(1)=="Variable"){
                    localdecl.push_back(tempscope.at(i));
                }
        }
        if(searchEnded==true){
            break;
        }
    }
    vector<vector<vector<string> > > globalscopevariables = tb.GetStackFromValue(finalscopeposition);
    globaldecl = SearchGlobalVariablesClasses(globalscopevariables,finalscopevalue);

    listscopes.push_back(localdecl);
    listscopes.push_back(globaldecl);
    listscopes.push_back(intermediatescopes);
    return listscopes;
}
*/
void ChekingVariables(vector<vector<pElementSCH> > listofscopes){
    int positions = listofscopes.size()-1;
    vector<pElementSCH> globalsdecl = listofscopes.at(0);
    vector<pElementSCH> localsdecl = listofscopes.at(1);
    vector<pElementSCH> globalsassign = listofscopes.at(2);
    vector<pElementSCH> localsassign = listofscopes.at(3);
    vector<pElementSCH> localtogloblalscope;

    int globalsdeclsize = globalsdecl.size()-1;
    int localsdeclsize = localsdecl.size()-1;
    int globalsassignsize = globalsassign.size()-1;
    int localsassignsize = localsassign.size()-1;
    //TODO: REVISAR ESTO
    if(!globalsassign.empty()){
        bool variableonscope;

        for(int i=0;i<=globalsassignsize;i++){
            variableonscope = false;

            for(int y=0;y<=globalsdeclsize;y++){
                if(globalsassign.at(i)->value1->value==globalsdecl.at(y)->value1->value){
                    variableonscope = true;
                }
            }
            if(variableonscope==false){
            }
        }
    }
    if(!localsassign.empty()){
        bool variableonscope;
        for(int i=0;i<=localsassignsize;i++){
            variableonscope = false;
            for(int y=0;y<=localsdeclsize;y++){
                if(localsassign.at(i)->value1->value==localsdecl.at(y)->value1->value){
                    variableonscope = true;
                }
            }
            if(variableonscope==false){
                localtogloblalscope.push_back(localsassign.at(i));
            }
        }
    }
    if(!localtogloblalscope.empty()){
        bool variableonscope;
        int localtogloblalscopesize = localtogloblalscope.size()-1;
        for(int i=0;i<=localtogloblalscopesize;i++){
            variableonscope = false;
            for(int y=0;y<=globalsdeclsize;y++){
                if(localtogloblalscope.at(i)->value1->value==globalsdecl.at(y)->value1->value){
                    variableonscope=true;
                    break;
                }
            }
            if(variableonscope==false){
                /*string error = " ";
                string variable = localtogloblalscope.at(i)->value1->value;
                string column = to_string(localtogloblalscope.at(i)->columnE);
                string row = to_string(localtogloblalscope.at(i)->rowE);
                error = "Undeclared variable: "+ variable +" at column: "+ column +" on line: "+ row +"\n";
                semanticerrors.push_back(error);*/
                undeclaredvariables.push_back(localtogloblalscope.at(i));
            }
        }
    }

}
vector<vector<pElementSCH> > DivideScopes (vector<vector<pElementSCH> > listofscopes){
    int positions = listofscopes.size()-1;
    vector<vector<pElementSCH> > tempscopes;
    vector<pElementSCH> oldlist;
    vector<pElementSCH> globalsdecl;
    vector<pElementSCH> localsdecl;
    vector<pElementSCH> globalsassign;
    vector<pElementSCH> localsassign;

    for(int y=0;y<=positions;y++){
        oldlist = listofscopes.at(y);
        int scopepositions = oldlist.size()-1;
        if(y==0){
            for(int i =0;i<=scopepositions;i++){
                if(oldlist.at(i)->tokenE== "Expr"){
                    localsassign.push_back(oldlist.at(i));
                }
                if(oldlist.at(i)->tokenE == "Variable"){
                    localsdecl.push_back(oldlist.at(i));
                }
            }
        }
        if(y==1){
            for(int i =0;i<=scopepositions;i++){
                if(oldlist.at(i)->tokenE== "Expr"){
                    globalsassign.push_back(oldlist.at(i));
                }
                if(oldlist.at(i)->tokenE == "Variable"){
                    globalsdecl.push_back(oldlist.at(i));
                }
            }
        }
    }
    tempscopes.push_back(globalsdecl);
    tempscopes.push_back(localsdecl);
    tempscopes.push_back(globalsassign);
    tempscopes.push_back(localsassign);
    return tempscopes;
}
//Elimina aquellos valores que no son asignaciones o expresiones (declaracion de funciones etc)
vector<vector<pElementSCH> > DeleteOtherValues(vector<vector<pElementSCH> > listofscopes){
    int positions = listofscopes.size()-1;
    vector<vector<pElementSCH> > tempscopes;
    vector<pElementSCH> oldlist;
    vector<pElementSCH>  newlist;
    for(int y=0;y<=positions;y++){
        oldlist = listofscopes.at(y);
        int scopepositions = oldlist.size()-1;
        newlist.clear();
        for(int i =0;i<=scopepositions;i++){
            if(oldlist.at(i)->tokenE== "Expr" || oldlist.at(i)->tokenE == "Variable"){
                newlist.push_back(oldlist.at(i));
            }

        }
        tempscopes.push_back(newlist);
    }
    return tempscopes;
}
vector<pElementSCH> SearchGlobalVariables(vector<pElementSCH> tb){
    int stackpositions = tb.size()-1;
    vector<pElementSCH> globaldecl;
    vector<pElementSCH> bracestoclose;
    for(stackpositions;stackpositions>=0;stackpositions--){
          if(tb.at(stackpositions)->tokenE == "RBRACE"){
                tb.at(stackpositions)->tokenE = "LBRACE";
                bracestoclose.push_back(tb.at(stackpositions));
                tb.at(stackpositions)->tokenE = "RBRACE";
          }
          if(!bracestoclose.empty() && tb.at(stackpositions)->tokenE =="LBRACE"){
                int sizebracestoclose = bracestoclose.size()-1;
                if(tb.at(stackpositions)->value1->value==bracestoclose.at(sizebracestoclose)->value1->value){
                      bracestoclose.pop_back();
                }
          }
          if(bracestoclose.empty()){
                globaldecl.push_back(tb.at(stackpositions));
          }
    }
    return globaldecl;

}
//Busca los scopes locales pertenecientes a un LBRACE y llama a SearchGlobalVariables
//para buscar las asignaciones y variables pertenecientes a los scopes globales
vector<vector<pElementSCH> > SearchLocalVariables(TablesStack &tb, string scopevalue){
    int stackpositions = tb.GetStackSize()-1;
    int finalscopeposition;
    int newscopeglobalvalue;
    vector<vector<pElementSCH> > listscopes;
    vector<pElementSCH> locals;
    vector<pElementSCH> globals;
    vector<pElementSCH> bracestoclose;

    for(stackpositions;stackpositions>=0;stackpositions--){
        if(tb.at(stackpositions)->tokenE == "LBRACE" && tb.at(stackpositions)->value1->value==scopevalue){
            finalscopeposition = stackpositions-1;
            break;
        }
        if(tb.at(stackpositions)->tokenE == "RBRACE"){
            tb.at(stackpositions)->tokenE = "LBRACE";
            bracestoclose.push_back(tb.at(stackpositions));
            tb.at(stackpositions)->tokenE = "RBRACE";
        }
        if(!bracestoclose.empty() && tb.at(stackpositions)->tokenE =="LBRACE"){
            int sizebracestoclose = bracestoclose.size()-1;
            if(tb.at(stackpositions)->value1->value==bracestoclose.at(sizebracestoclose)->value1->value){
                bracestoclose.pop_back();
            }
        }
        if(bracestoclose.empty() && tb.at(stackpositions)->tokenE=="Expr"){
            locals.push_back(tb.at(stackpositions));
        }
        if(bracestoclose.empty() && tb.at(stackpositions)->tokenE=="Variable"){
            locals.push_back(tb.at(stackpositions));
        }
    }
    //locals: lista que guarda las asignaciones y declaraciones locales
    //listofscopes: lista que guarda las asignaciones y declaraciones tanto globales como locales.

    vector<pElementSCH> globalscopevariables = tb.GetStackFromValue(finalscopeposition);
    globals = SearchGlobalVariables(globalscopevariables);
    listscopes.push_back(locals);
    listscopes.push_back(globals);
    return listscopes;
}
vector<pElementSCH> SearchGlobalVariablesClasses(vector<pElementSCH> tb,string scopevalue){
    int stackpositions = tb.size()-1;
    vector<pElementSCH> globaldecl;
    vector<pElementSCH> bracestoclose;
    for(stackpositions;stackpositions>=0;stackpositions--){
          if(tb.at(stackpositions)->tokenE == "LBRACE" && tb.at(stackpositions)->value1->value == scopevalue){
                break;
          }
          if(tb.at(stackpositions)->tokenE == "RBRACE"){
                tb.at(stackpositions)->tokenE = "LBRACE";
                bracestoclose.push_back(tb.at(stackpositions));
                tb.at(stackpositions)->tokenE = "RBRACE";
          }
          if(!bracestoclose.empty() && tb.at(stackpositions)->tokenE =="LBRACE"){
                int sizebracestoclose = bracestoclose.size()-1;
                if(tb.at(stackpositions)->value1->value==bracestoclose.at(sizebracestoclose)->value1->value){
                      bracestoclose.pop_back();
                }
          }
          if(bracestoclose.empty()){
                globaldecl.push_back(tb.at(stackpositions));
          }
    }
    return globaldecl;

}
//Busca los scopes locales pertenecientes a un LBRACE y llama a SearchGlobalVariablesClasses
//para buscar las asignaciones y variables pertenecientes a los scopes globales de clases
vector<vector<pElementSCH> > SearchLocalVariablesClasses(TablesStack &tb, string scopevalue){
    int stackpositions = tb.GetStackSize()-1;
    int finalscopeposition;
    int newscopeglobalvalue;
    string finalscopevalue;
    vector<vector<pElementSCH> > listscopes;
    vector<pElementSCH> locals;
    vector<pElementSCH> globals;
    vector<pElementSCH> bracestoclose;

    for(stackpositions;stackpositions>=0;stackpositions--){
        if(tb.at(stackpositions)->tokenE == "LBRACE" && tb.at(stackpositions)->value1->value==scopevalue){
            finalscopeposition = stackpositions-1;
            newscopeglobalvalue = stoi(scopevalue)-1;
            finalscopevalue = to_string(newscopeglobalvalue);
            break;
        }
        if(tb.at(stackpositions)->tokenE == "RBRACE"){
            tb.at(stackpositions)->tokenE = "LBRACE";
            bracestoclose.push_back(tb.at(stackpositions));
            tb.at(stackpositions)->tokenE = "RBRACE";
        }
        if(!bracestoclose.empty() && tb.at(stackpositions)->tokenE =="LBRACE"){
            int sizebracestoclose = bracestoclose.size()-1;
            if(tb.at(stackpositions)->value1->value==bracestoclose.at(sizebracestoclose)->value1->value){
                bracestoclose.pop_back();
            }
        }
        if(bracestoclose.empty() && tb.at(stackpositions)->tokenE=="Expr"){
            locals.push_back(tb.at(stackpositions));
        }
        if(bracestoclose.empty() && tb.at(stackpositions)->tokenE=="Variable"){
            locals.push_back(tb.at(stackpositions));
        }
    }
    //locals: lista que guarda las asignaciones y declaraciones locales
    //listofscopes: lista que guarda las asignaciones y declaraciones tanto globales como locales.

    vector<pElementSCH> globalscopevariables = tb.GetStackFromValue(finalscopeposition);
    globals = SearchGlobalVariablesClasses(globalscopevariables,finalscopevalue);
    listscopes.push_back(locals);
    listscopes.push_back(globals);
    return listscopes;
}
//Valida las variables en scopes globales y locales
void ScopeCheckingVariables(TablesStack &tb,string typeScope){
    vector<pElementSCH> tbtemp = tb.GetTableStack();
    vector<vector<pElementSCH> > scopes;
    int stackpositions = tbtemp.size()-1;
    string scopevalue = " ";
    pElementSCH elements;
    //tb.printStack();
    //1.vector<vector<vector<string> > > scopes;
    if(typeScope=="Functions"){
        for(stackpositions;stackpositions>=0;stackpositions--){
          //cout << "STACKPOSITIONS: \n"<<stackpositions<<"\n";
            if(tbtemp.at(stackpositions)->tokenE == "RBRACE"){
                scopevalue =tbtemp.at(stackpositions)->value1->value;;
                tb.Pop();
                scopes = SearchLocalVariables(tb,scopevalue);
                scopes = DeleteOtherValues(scopes);
                scopes = DivideScopes(scopes);
                ChekingVariables(scopes);
            }else{
              if(tbtemp.at(stackpositions)->tokenE != "RBRACE" && !tb.isEmpty()){
                  tb.Pop();
              }

            }

        }
    }
    if(typeScope=="Classes"){
      for(stackpositions;stackpositions>=0;stackpositions--){
        //cout << "STACKPOSITIONS: \n"<<stackpositions<<"\n";
          if(tbtemp.at(stackpositions)->tokenE == "RBRACE"){
              scopevalue =tbtemp.at(stackpositions)->value1->value;;
              tb.Pop();
              //TODO: Verificar que la validacion de variables en las clases funciona.
              //scopes = SearchLocalVariablesClasses(tb,scopevalue);
              //scopes = DeleteOtherValues(scopes);
              //scopes = DivideScopes(scopes);
              //ChekingVariables(scopes);
          }else{
            if(tbtemp.at(stackpositions)->tokenE != "RBRACE" && !tb.isEmpty()){
                tb.Pop();
            }

          }

      }
    }
    printSemanticErrors();
}
//Imprimir scopes
/*cout << "---------------DIVIDESCOPES---------------\n";
for(int i=0;i<scopes.size();i++){
    if(i==0){
        cout << "///////GLOBAL DECL///////\n";
    }
    if(i==1){
        cout << "///////LOCAL DECL////////\n";
    }
    if(i==2){
        cout << "///////GLOBAL ASSIGN////////\n";
    }
    if(i==3 ){
        cout << "///////LOCAL ASSIGN////////\n";
    }
    for(int y=0;y<scopes.at(i).size();y++){
        cout<< "Type: " <<scopes.at(i).at(y)->type << "\tToken: " <<scopes.at(i).at(y)->tokenE << "\tValue 1: " <<scopes.at(i).at(y)->value1->value<< "\tValue 2: " <<scopes.at(i).at(y)->value2->value<< "\tLine: " <<scopes.at(i).at(y)->rowE<< "\tColumn: " <<scopes.at(i).at(y)->columnE<<"\n";
    }
}
cout << "-----------------------------------\n";*/

#endif // AUXILIARYFUNCTIONS_H_INCLUDED
