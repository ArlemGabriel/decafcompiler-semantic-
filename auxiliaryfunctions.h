#ifndef AUXILIARYFUNCTIONS_H_INCLUDED
#define AUXILIARYFUNCTIONS_H_INCLUDED

#include <vector>
#include "stacktables.h"
#include "ElementSCH.h"


vector<string> semanticerrors;

//Funcion que imprime los errores semanticos encontrados
void printSemanticErrors(){
    if(semanticerrors.empty()){
        cout << "Non errors found\n";
    }
    else{
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

void PrintScopes(vector<vector<vector<string> > > listofscopes){
    int positions = listofscopes.size()-1;
    vector<vector<string> > templist;
    for(int y=0;y<=positions;y++){
        templist = listofscopes.at(y);
        int scopepositions = templist.size()-1;
        for(int i =0;i<=scopepositions;i++){
            cout << "Type: " << templist.at(i).at(0)<<"\n";
            cout << "Token: " << templist.at(i).at(1)<<"\n";
            cout << "Value1: " << templist.at(i).at(2)<<"\n";
            cout << "Value2: " << templist.at(i).at(3)<<"\n";
            cout << "_________________________________________________\n";
        }
        cout << "_________________________________________________\n";
    }
    cout << "\n \n";
}
vector<vector<string> > SearchGlobalVariables(vector<vector<vector<string> > > tb){
    int stackpositions = tb.size()-1;
    vector<vector<string> > tempscope;
    vector<vector<string> > globaldecl;
    vector<vector<string> > bracestoclose;
    for(stackpositions;stackpositions>=0;stackpositions--){
        tempscope = tb.at(stackpositions);
        int scopepositions = tempscope.size()-1;
        bool searchEnded = false;

        for(int i =0;i<=scopepositions;i++){
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
//Busca los scopes globales y locales pertenecientes a un LBRACE
vector<vector<vector<string> > > SearchLocalVariables(TablesStack tb, string scopevalue){
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
    globaldecl = SearchGlobalVariables(globalscopevariables);

    listscopes.push_back(localdecl);
    listscopes.push_back(globaldecl);
    listscopes.push_back(intermediatescopes);
    return listscopes;
}
//Elimina aquellos valores que no son asignaciones o expresiones (declaracion de funciones etc)
vector<vector<vector<string> > > DeleteOtherValues(vector<vector<vector<string> > > listofscopes){
    int positions = listofscopes.size()-1;
    vector<vector<vector<string> > > tempscopes;
    vector<vector<string> > oldlist;
    vector<vector<string> > newlist;
    for(int y=0;y<=positions;y++){
        oldlist = listofscopes.at(y);
        int scopepositions = oldlist.size()-1;
        newlist.clear();
        for(int i =0;i<=scopepositions;i++){
            if(oldlist.at(i).at(1)== "Exp" || oldlist.at(i).at(1) == "Variable"){
                newlist.push_back(oldlist.at(i));
            }

        }
        tempscopes.push_back(newlist);
    }
    return tempscopes;
}
vector<vector<vector<string> > > DivideScopes (vector<vector<vector<string> > > listofscopes){
    int positions = listofscopes.size()-1;
    vector<vector<vector<string> > > tempscopes;
    vector<vector<string> > oldlist;
    vector<vector<string> > globalsdecl;
    vector<vector<string> > localsdecl;
    vector<vector<string> > globalsassign;
    vector<vector<string> > localsassign;

    for(int y=0;y<=positions;y++){
        oldlist = listofscopes.at(y);
        int scopepositions = oldlist.size()-1;
        if(y==0){
            for(int i =0;i<=scopepositions;i++){
                if(oldlist.at(i).at(1)== "Exp"){
                    localsassign.push_back(oldlist.at(i));
                }
                if(oldlist.at(i).at(1) == "Variable"){
                    localsdecl.push_back(oldlist.at(i));
                }
            }
        }
        if(y==1){
            for(int i =0;i<=scopepositions;i++){
                if(oldlist.at(i).at(1)== "Exp"){
                    globalsassign.push_back(oldlist.at(i));
                }
                if(oldlist.at(i).at(1) == "Variable"){
                    globalsdecl.push_back(oldlist.at(i));
                }
            }
        }
        if(y==2){
            for(int i =0;i<=scopepositions;i++){
                localsassign.push_back(oldlist.at(i));
            }
        }
    }
    tempscopes.push_back(globalsdecl);
    tempscopes.push_back(localsdecl);
    tempscopes.push_back(globalsassign);
    tempscopes.push_back(localsassign);
    return tempscopes;
}
bool ChekingVariables(vector<vector<vector<string> > > listofscopes){
    int positions = listofscopes.size()-1;
    bool checkingresult = false;
    vector<vector<string> > globalsdecl = listofscopes.at(0);
    vector<vector<string> > localsdecl = listofscopes.at(1);
    vector<vector<string> > globalsassign = listofscopes.at(2);
    vector<vector<string> > localsassign = listofscopes.at(3);
    vector<vector<string> > localtogloblalscope;
    int globalsdeclsize = globalsdecl.size()-1;
    int localsdeclsize = localsdecl.size()-1;
    int globalsassignsize = globalsassign.size()-1;
    int localsassignsize = localsassign.size()-1;
    if(!globalsassign.empty()){
        bool variableonscope;

        for(int i=0;i<=globalsassignsize;i++){
            variableonscope = false;

            for(int y=0;y<=globalsdeclsize;y++){
                if(globalsassign.at(i).at(2)==globalsdecl.at(y).at(2)){
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
                if(localsassign.at(i).at(2)==localsdecl.at(y).at(2)){
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
                if(localtogloblalscope.at(i).at(2)==globalsdecl.at(y).at(2)){
                    variableonscope=true;
                    break;
                }
            }
            if(variableonscope==false){
                string error = " ";
                error = "Undeclared variable: "+ localtogloblalscope.at(i).at(2)+" at column: "+localtogloblalscope.at(i).at(4)+" on line: "+localtogloblalscope.at(i).at(5)+"\n";
                semanticerrors.push_back(error);
            }
        }
    }

}*/
//Valida las variables en scopes globales y locales
void ScopeCheckingVariables(TablesStack &tb,string typeScope){
    vector<pElementSCH> tbtemp = tb.GetTableStack();
    int stackpositions = tbtemp.size()-1;
    string scopevalue = " ";
    pElementSCH elements;

    //1.vector<vector<vector<string> > > scopes;
    if(typeScope=="Functions"){
        for(stackpositions;stackpositions>=0;stackpositions--){
            if(tbtemp.at(stackpositions)->type == "RBRACE"){
                scopevalue =tbtemp.at(stackpositions)->value1->value;
                /*elements = tb.GetLastScope();
                cout<< "Type: " <<elements->type << "\tToken: " <<elements->tokenE <<"\n";*/

                tb.Pop();
                //scopes = SearchLocalVariables(tb,scopevalue);
                /*elements = tb.GetLastScope();
                cout << "ENTRE 1\n";
                cout<< "Type: " <<elements->type << "\tToken: " <<elements->tokenE <<"\n";*/
                //1.scopes = SearchLocalVariables(tb,scopevalue);
                //1.scopes = DeleteOtherValues(scopes);
                //1.scopes = DivideScopes(scopes);
                //1.ChekingVariables(scopes);
            }
            if(tbtemp.at(stackpositions)->type != "RBRACE" && !tb.isEmpty()){
                tb.Pop();
                break;
            }

        }
    }
    /*if(typeScope=="Classes"){
        for(stackpositions;stackpositions>=0;stackpositions--){
            tempscope = tbtemp.at(stackpositions);
            int scopepositions = tempscope.size()-1;
            for(int i =0;i<=scopepositions;i++){
                if(tempscope.at(i).at(1) == "RBRACE"){
                    scopevalue =tempscope.at(i).at(2);
                    tb.Pop();
                    scopes = SearchLocalVariablesClasses(tb,scopevalue);
                    scopes = DeleteOtherValues(scopes);
                    scopes = DivideScopes(scopes);
                    ChekingVariables(scopes);
                }
                if(tempscope.at(i).at(1) != "RBRACE" && !tb.isEmpty()){
                    tb.Pop();
                    break;
                }
            }
        }
    }*/

    printSemanticErrors();
}


#endif // AUXILIARYFUNCTIONS_H_INCLUDED