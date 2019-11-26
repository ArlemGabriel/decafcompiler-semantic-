#ifndef INHERITANCESTRUCTURE_H_INCLUDED
#define INHERITANCESTRUCTURE_H_INCLUDED

#include <vector>
#include "stacktables.h"
#include "ElementSCH.h"
#include <algorithm>
#include "semanticerrors.h"
typedef ClassStructure * pClassStructure;

pClassStructure newclass;
vector<pClassStructure> classeslist;

vector<pElementSCH> undeclaredvariables;
vector<pElementSCH> repeatdeclaredvariables;

vector<pElementSCH> assignsvariables;
vector<pElementSCH> globalsassign;
vector<pElementSCH> localsassign;
vector<pElementSCH> localtogloblalscope;


void ChekingVariablesI(vector<vector<pElementSCH> > listofscopes){
    int positions = listofscopes.size()-1;
    vector<pElementSCH> globalsdecl = listofscopes.at(0);
    vector<pElementSCH> localsdecl = listofscopes.at(1);
    globalsassign = listofscopes.at(2);
    localsassign = listofscopes.at(3);


    int globalsdeclsize = globalsdecl.size()-1;
    int localsdeclsize = localsdecl.size()-1;
    int globalsassignsize = globalsassign.size()-1;
    int localsassignsize = localsassign.size()-1;
    if(!globalsassign.empty()){
        bool variableonscope;

        for(int i=0;i<=globalsassignsize;i++){
            variableonscope = false;

            for(int y=0;y<=globalsdeclsize;y++){
                if(globalsassign.at(i)->value1->value==globalsdecl.at(y)->value1->value){
                    variableonscope = true;
                    if(globalsdecl.at(y)->type!= ""){
                        globalsassign.at(i)->value2->value = globalsdecl.at(y)->type;
                        assignsvariables.push_back(globalsassign.at(i));
                    }
                }
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
                    if(localsdecl.at(y)->type!= ""){
                        localsassign.at(i)->value2->value = localsdecl.at(y)->type;
                        assignsvariables.push_back(localsassign.at(i));
                    }
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
                    if(globalsdecl.at(y)->type!= ""){
                        localtogloblalscope.at(i)->value2->value = globalsdecl.at(y)->type;
                        assignsvariables.push_back(localtogloblalscope.at(i));
                    }
                    variableonscope=true;
                    break;
                }
            }
            if(variableonscope==false){
                undeclaredvariables.push_back(localtogloblalscope.at(i));
            }
        }
    }

}
vector<vector<pElementSCH> > DivideScopesI (vector<vector<pElementSCH> > listofscopes){
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
                if(oldlist.at(i)->tokenE == "Variable" || oldlist.at(i)->tokenE == "FunctionDecl"){
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
vector<vector<pElementSCH> > DeleteOtherValuesI(vector<vector<pElementSCH> > listofscopes){
    int positions = listofscopes.size()-1;
    vector<vector<pElementSCH> > tempscopes;
    vector<pElementSCH> oldlist;
    vector<pElementSCH>  newlist;
    for(int y=0;y<=positions;y++){
        oldlist = listofscopes.at(y);
        int scopepositions = oldlist.size()-1;
        newlist.clear();
        for(int i =0;i<=scopepositions;i++){
            if(oldlist.at(i)->tokenE== "Expr" || oldlist.at(i)->tokenE == "Variable" || oldlist.at(i)->tokenE == "FunctionDecl"){
                newlist.push_back(oldlist.at(i));
            }

        }
        tempscopes.push_back(newlist);
    }
    return tempscopes;
}
vector<pElementSCH> SearchGlobalVariablesClassesI(vector<pElementSCH> tb,string scopevalue){
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
vector<vector<pElementSCH> > SearchLocalVariablesClassesI(TablesStack &tb, string scopevalue){
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
vector<pElementSCH> ScopeCheckingVariablesI(TablesStack &tb){
    vector<pElementSCH> tbtemp = tb.GetTableStack();
    vector<vector<pElementSCH> > scopes;
    int stackpositions = tbtemp.size()-1;
    string scopevalue = " ";
    pElementSCH elements;
    if(typeScope=="Classes"){
      for(stackpositions;stackpositions>=0;stackpositions--){
          if(tbtemp.at(stackpositions)->tokenE == "RBRACE"){
              scopevalue =tbtemp.at(stackpositions)->value1->value;;
              tb.Pop();
              scopes = SearchLocalVariablesClassesI(tb,scopevalue);
              scopes = DeleteOtherValuesI(scopes);
              scopes = DivideScopesI(scopes);
              ChekingVariablesI(scopes);
          }else{
            if(tbtemp.at(stackpositions)->tokenE != "RBRACE" && !tb.isEmpty()){
                tb.Pop();
            }

          }

      }
    }
}


#endif // INHERITANCESTRUCTURE_H_INCLUDED
