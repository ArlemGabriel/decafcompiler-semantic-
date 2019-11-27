#ifndef SCOPECHECKINGVARIABLESCLASSES_H_INCLUDED
#define SCOPECHECKINGVARIABLESCLASSES_H_INCLUDED

#include <vector>
#include "stacktables.h"
#include "semanticerrors.h"
#include <algorithm>
typedef SemanticError * pSemanticError;

pSemanticError errorScopeClasses;
vector<pSemanticError> listsemanticerrorsscopeclasses;

vector<string> semanticerrorsclasses;
vector<pElementSCH> classattributes;
vector<vector<pElementSCH > > listofclasses;
vector<vector<pElementSCH > > classesattributes;
vector<vector<pElementSCH > > classesmethods;
vector<pElementSCH> assignsvariablestypes;


vector<pElementSCH> repeatdeclaredvariableseclasses;

void PrintErrorsScopeClasses(){
    if(!listsemanticerrorsscopeclasses.empty()){
        for(int i=0;i<listsemanticerrorsscopeclasses.size();i++){
            cout << listsemanticerrorsscopeclasses.at(i)->GetTypeError()<<" ";
            cout << listsemanticerrorsscopeclasses.at(i)->GetType()<<" ";
            cout << listsemanticerrorsscopeclasses.at(i)->GetToken()<<" ";
            cout << listsemanticerrorsscopeclasses.at(i)->GetValue1()<<" ";
            cout << listsemanticerrorsscopeclasses.at(i)->GetValue2()<<" ";
            cout << listsemanticerrorsscopeclasses.at(i)->GetColumn()<<" ";
            cout << listsemanticerrorsscopeclasses.at(i)->GetRow()<<"\n";
        }
    }
    if(!repeatdeclaredvariableseclasses.empty()){

      for(int i=0;i<repeatdeclaredvariableseclasses.size();i++){
          cout << "Redefinition Variable: ";
          cout << repeatdeclaredvariableseclasses.at(i)->type<<" ";
          cout << repeatdeclaredvariableseclasses.at(i)->tokenE<<" ";
          cout << repeatdeclaredvariableseclasses.at(i)->value1->value<<" ";
          cout << repeatdeclaredvariableseclasses.at(i)->value2->value<<" ";
          cout << repeatdeclaredvariableseclasses.at(i)->columnE<<" ";
          cout << repeatdeclaredvariableseclasses.at(i)->rowE<<"\n";
      }
    }
}
void GetSeparateClasses(TablesStack &tb){
    int stackpositions = tb.GetStackSize()-1;
    vector<pElementSCH> bracestoclose;
    vector<pElementSCH> newclass;
    int sizebracestoclose;
    for(stackpositions;stackpositions>=0;stackpositions--){
          if(tb.at(stackpositions)->tokenE == "RBRACE" && tb.at(stackpositions)->value1->value == "1"){
                tb.at(stackpositions)->tokenE = "LBRACE";
                bracestoclose.push_back(tb.at(stackpositions));
                tb.at(stackpositions)->tokenE = "RBRACE";
          }
          if(bracestoclose.empty() && tb.at(stackpositions)->type =="CLASS"){
                if(bracestoclose.empty() && tb.at(stackpositions)->type =="CLASS" && tb.at(stackpositions)->value1->value!="EXTENDS"){
                      newclass.push_back(tb.at(stackpositions));
                      listofclasses.push_back(newclass);
                      newclass.clear();
                }
                //AGREGA LAS CLASES EXTENDS
                if(bracestoclose.empty() && tb.at(stackpositions)->type =="CLASS" && tb.at(stackpositions)->value1->value=="EXTENDS"){
                      newclass.push_back(tb.at(stackpositions));
                }
          }
          if(!bracestoclose.empty() && tb.at(stackpositions)->tokenE !="LBRACE"|| (!bracestoclose.empty() && tb.at(stackpositions)->tokenE =="LBRACE" && tb.at(stackpositions)->value1->value != "1")){
                newclass.push_back(tb.at(stackpositions));

          }
          if(!bracestoclose.empty() && tb.at(stackpositions)->tokenE =="LBRACE" && tb.at(stackpositions)->value1->value == "1"){
                bracestoclose.pop_back();
                newclass.push_back(tb.at(stackpositions));

          }
    }


}
void CheckGlobalVariablesClass(vector<pElementSCH> aclass){
      int stackpositions = aclass.size();
      vector<pElementSCH> bracestoclose;
      vector<pElementSCH> classattributes;
      vector<pElementSCH> classmethods;
      pElementSCH classname = aclass.at(stackpositions-1);
      for(int i=0;i<stackpositions;i++){
        if(aclass.at(i)->tokenE == "LBRACE" && aclass.at(i)->value1->value=="1"){
            break;
        }
        if(aclass.at(i)->tokenE == "RBRACE" && aclass.at(i)->value1->value !="1"){
            aclass.at(i)->tokenE = "LBRACE";
            bracestoclose.push_back(aclass.at(i));
            aclass.at(i)->tokenE = "RBRACE";
        }
        if(!bracestoclose.empty() && aclass.at(i)->tokenE =="LBRACE"){
            int sizebracestoclose = bracestoclose.size()-1;
            if(aclass.at(i)->value1->value==bracestoclose.at(sizebracestoclose)->value1->value){
                bracestoclose.pop_back();
            }
        }
        if(bracestoclose.empty() && aclass.at(i)->tokenE=="Variable"){

            if(aclass.at(i)->value2->value!="Func" && aclass.at(i)->value2->value!="NewArray" && aclass.at(i)->value2->value!="NewClass"){

                classattributes.push_back(aclass.at(i));
            }
        }

        if(bracestoclose.empty() && aclass.at(i)->tokenE=="FunctionDecl"){

            classmethods.push_back(aclass.at(i));

        }
      }
      classattributes.push_back(classname);
      classesattributes.push_back(classattributes);
      classmethods.push_back(classname);
      classesmethods.push_back(classmethods);


}
vector<pElementSCH> SearchGlobalVariablesClasses(vector<pElementSCH> tb){
    int stackpositions = tb.size()-1;
    vector<pElementSCH> globaldecl;
    vector<pElementSCH> bracestoclose;
    for(stackpositions;stackpositions>=0;stackpositions--){
      /*cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
      cout<< "Type: " <<tb.at(stackpositions)->type<<"\n";
      cout<<"\tToken: " <<tb.at(stackpositions)->tokenE<<"\n";
      cout<< "\tValue 1: " <<tb.at(stackpositions)->value1->value<<"\n";
      cout<< "\tValue 2: " <<tb.at(stackpositions)->value2->value<<"\n";
      cout<< "\tLine: " <<tb.at(stackpositions)->rowE<<"\n";
      cout<< "\tColumn: " <<tb.at(stackpositions)->columnE<<"\n";
      cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";*/
          if(tb.at(stackpositions)->tokenE == "RBRACE"){
            /*cout << "            ///////////////////////////////////////\n";
            cout << "            DECICION TOMADA: AGREGAR SCOPE PARA IGNORAR\n";
            cout << "            ///////////////////////////////////////\n";*/
                tb.at(stackpositions)->tokenE = "LBRACE";
                bracestoclose.push_back(tb.at(stackpositions));
                tb.at(stackpositions)->tokenE = "RBRACE";
          }
          //AQUI ESTA LO DE LOS PARAMETROS
          if(bracestoclose.empty() && tb.at(stackpositions)->tokenE != "LBRACE" /*&& tb.at(stackpositions)->value2->value != "Func"*/){
            /*cout << "            ///////////////////////////////////////\n";
            cout << "            DECICION TOMADA: AGREGAR DECLARACION\n";
            cout << "            ///////////////////////////////////////\n";*/
                globaldecl.push_back(tb.at(stackpositions));
          }

          if(!bracestoclose.empty() && tb.at(stackpositions)->tokenE =="LBRACE"){
                int sizebracestoclose = bracestoclose.size()-1;
                /*cout << "            ///////////////////////////////////////\n";
                cout << "            DECICION TOMADA: QUITAR SCOPE PARA IGNORAR\n";
                cout << "            ///////////////////////////////////////\n";*/
                if(tb.at(stackpositions)->value1->value==bracestoclose.at(sizebracestoclose)->value1->value){
                      bracestoclose.pop_back();
                }
          }
    }
    return globaldecl;

}
vector<vector<pElementSCH> > SearchLocalVariablesClasses(TablesStack &tb, string scopevalue){
    int stackpositions = tb.GetStackSize()-1;
    int finalscopeposition;
    int newscopeglobalvalue;
    vector<vector<pElementSCH> > listscopes;
    vector<pElementSCH> localsassigns;
    vector<pElementSCH> localsdecls;
    vector<pElementSCH> globalsoflocals;
    vector<pElementSCH> bracestoclose;

    /*cout << "---------------ACLASS---------------\n";

    for(int y=0;y<tb.GetStackSize();y++){
        cout<< "Type: " <<tb.at(y)->type << "\tToken: " <<tb.at(y)->tokenE << "\tValue 1: " <<tb.at(y)->value1->value<< "\tValue 2: " <<tb.at(y)->value2->value<< "\tLine: " <<tb.at(y)->rowE<< "\tColumn: " <<tb.at(y)->columnE<<"\n";
    }

    cout << "-----------------------------------\n";*/

    for(stackpositions;stackpositions>=0;stackpositions--){
      /*cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
      cout<< "Type: " <<tb.at(stackpositions)->type<<"\n";
      cout<<"\tToken: " <<tb.at(stackpositions)->tokenE<<"\n";
      cout<< "\tValue 1: " <<tb.at(stackpositions)->value1->value<<"\n";
      cout<< "\tValue 2: " <<tb.at(stackpositions)->value2->value<<"\n";
      cout<< "\tLine: " <<tb.at(stackpositions)->rowE<<"\n";
      cout<< "\tColumn: " <<tb.at(stackpositions)->columnE<<"\n";
      cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";*/
        if(tb.at(stackpositions)->tokenE == "LBRACE" && tb.at(stackpositions)->value1->value==scopevalue){
            finalscopeposition = stackpositions-1;
            /*cout << "            ///////////////////////////////////////\n";
            cout << "            DECICION TOMADA: BREAK\n";
            cout << "            ///////////////////////////////////////\n";*/
            break;
        }
        if(tb.at(stackpositions)->tokenE == "RBRACE"){
          /*cout << "            ///////////////////////////////////////\n";
          cout << "            DECICION TOMADA: INGRESAR SCOPE PARA IGNORAR\n";
          cout << "            ///////////////////////////////////////\n";*/
            tb.at(stackpositions)->tokenE = "LBRACE";
            bracestoclose.push_back(tb.at(stackpositions));
            tb.at(stackpositions)->tokenE = "RBRACE";
        }
        if(!bracestoclose.empty() && tb.at(stackpositions)->tokenE =="LBRACE"){
          /*cout << "            ///////////////////////////////////////\n";
          cout << "            DECICION TOMADA: QUITAR SCOPE PARA IGNORAR\n";
          cout << "            ///////////////////////////////////////\n";*/
            int sizebracestoclose = bracestoclose.size()-1;
            if(tb.at(stackpositions)->value1->value==bracestoclose.at(sizebracestoclose)->value1->value){
                bracestoclose.pop_back();
            }
        }
        if(bracestoclose.empty() && tb.at(stackpositions)->tokenE=="Expr"){
          /*cout << "            ///////////////////////////////////////\n";
          cout << "            DECICION TOMADA: AGREGAR EXP\n";
          cout << "            ///////////////////////////////////////\n";*/

            if(tb.at(stackpositions)->value2->value!="Func" && tb.at(stackpositions)->value2->value!="NewArray" && tb.at(stackpositions)->value2->value!="NewClass"){
                localsassigns.push_back(tb.at(stackpositions));
            }
        }
        if(bracestoclose.empty() && tb.at(stackpositions)->tokenE=="Variable"){
        /*  cout << "            ///////////////////////////////////////\n";
          cout << "            DECICION TOMADA: AGREGAR VARIABLE\n";
          cout << "            ///////////////////////////////////////\n";*/
            localsdecls.push_back(tb.at(stackpositions));
        }
    }
    //locals: lista que guarda las asignaciones y declaraciones locales
    //listofscopes: lista que guarda las asignaciones y declaraciones tanto globales como locales.

    vector<pElementSCH> globalscopevariables = tb.GetStackFromValue(finalscopeposition);


    globalsoflocals = SearchGlobalVariablesClasses(globalscopevariables);


    listscopes.push_back(localsassigns);
    listscopes.push_back(localsdecls);
    listscopes.push_back(globalsoflocals);

    return listscopes;
}
vector<vector<pElementSCH> > DeleteOtherValuesClasses(vector<vector<pElementSCH> > listofscopes){
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
void ChekingVariablesClasses(vector<vector<pElementSCH> > listofscopes){
    int positions = listofscopes.size()-1;
    //En la posicion 0 asignaciones locales
    //En la posicion 1 declaraciones locales
    //En la posicion 2 declaraciones globales despues del scope
    vector<pElementSCH> localtogloblalscope;
    vector<pElementSCH> localsassigns;
    vector<pElementSCH> localsdecls;
    vector<pElementSCH> globalsoflocals;
    localsassigns = listofscopes.at(0);
    localsdecls = listofscopes.at(1);
    globalsoflocals = listofscopes.at(2);

    int localsassignssize = localsassigns.size()-1;
    int localsdeclssize = localsdecls.size()-1;
    int globalsoflocalssize = globalsoflocals.size()-1;

    if(!localsassigns.empty()){
        if(!localsdecls.empty()){
            bool variableonscope;
            for(int i=0;i<=localsassignssize;i++){
                variableonscope = false;
                for(int y=0;y<=localsdeclssize;y++){
                    if(localsassigns.at(i)->value1->value == localsdecls.at(y)->value1->value){
                        variableonscope = true;
                        if(localsdecls.at(y)->type != ""){
                            localsassigns.at(i)->value2->value = localsdecls.at(y)->type;
                            //DESCOMENTAR AQUI
                            assignsvariablestypes.push_back(localsassigns.at(i));
                            /*if (find(assignsvariablestypes.begin(), assignsvariablestypes.end(), localsassigns.at(i)) != assignsvariablestypes.end() ){
                                  //DONOTHING
                            }else{
                                  assignsvariablestypes.push_back(localsassigns.at(i));
                            }*/
                        }
                    }
                    if(localsassigns.at(i)->value1->value != localsdecls.at(y)->value1->value){
                        localtogloblalscope.push_back(localsassigns.at(i));
                    }

                }
            }
        }
        if(localsdecls.empty()){
            for(int i=0;i<localsassigns.size();i++){
                localtogloblalscope.push_back(localsassigns.at(i));
            }
        }

    }
    if(!localtogloblalscope.empty()){
        bool variableonscope;
        int localtogloblalscopesize = localtogloblalscope.size()-1;
        for(int i=0;i<=localtogloblalscopesize;i++){
            variableonscope = false;
            for(int y=0;y<=globalsoflocalssize;y++){
                if(localtogloblalscope.at(i)->value1->value==globalsoflocals.at(y)->value1->value){
                    if(globalsoflocals.at(y)->type!= ""){
                        localtogloblalscope.at(i)->value2->value = globalsoflocals.at(y)->type;
                        assignsvariablestypes.push_back(localtogloblalscope.at(i));
                    }
                    variableonscope=true;
                    break;
                }
            }
            if(variableonscope==false){
                errorScopeClasses = new SemanticError("UndeclaredClassVariable",localtogloblalscope.at(i));
                listsemanticerrorsscopeclasses.push_back(errorScopeClasses);
            }
        }
    }

}
/*vector<pElementSCH> SortDecl(vector<pElementSCH> declarations){
    vector<string> namevariables;
    vector<int> positions;
    vector<pElementSCH> declarationssort;
    for(int i=0;i<declarations.size();i++){
        namevariables.push_back(declarations.at(i)->value1->value);
    }
    sort(namevariables.begin(), namevariables.end());
    namevariables.erase(unique(namevariables.begin(), namevariables.end()), namevariables.end());
    for(int i=0;i<namevariables.size();i++){
        for(int y=0;y<declarations.size();y++){
            if(namevariables.at(i) == declarations.at(y)->value1->value){
                declarationssort.push_back(declarations.at(y));
            }
        }
    }
    return declarationssort;

}*/
void ChekingRepeatVariableDeclarationsClasses(vector<vector<pElementSCH> > listofscopes){
  vector<pElementSCH> globalsdecl = listofscopes.at(1);
  vector<pElementSCH> localsdecl = listofscopes.at(2);
  vector<pElementSCH> duplicates;
  int globalsdeclsize = globalsdecl.size()-1;
  pElementSCH element;
  if(!globalsdecl.empty()){
        globalsdecl=SortDecl(globalsdecl);
        for (int i = 1; i<globalsdecl.size(); i++){
            if (globalsdecl.at(i-1)->value1->value == globalsdecl.at(i)->value1->value) {
                    //cout << "-----ENTRE---\n";
                  repeatdeclaredvariableseclasses.push_back(globalsdecl[i-1]);
            }
        }

  }
  if(!localsdecl.empty()){
        localsdecl=SortDecl(localsdecl);

        for (int i = 1; i<localsdecl.size(); i++){
            if (localsdecl.at(i-1)->value1->value == localsdecl.at(i)->value1->value) {
                    //cout << "-----ENTRE---\n";
                  repeatdeclaredvariableseclasses.push_back(localsdecl[i-1]);
            }
        }
  }

}
void CheckVariables(vector<pElementSCH> aclass){

      CheckGlobalVariablesClass(aclass);


      vector<pElementSCH> aclasstemp;
      int aclasssize = aclass.size()-1;
      vector<vector<pElementSCH> > scopes;
      string scopevalue = " ";
      pElementSCH elements;

      TablesStack tb;
      TablesStack tbtemp;

      for(aclasssize;aclasssize>=0;aclasssize--){
          tb.Push(aclass.at(aclasssize));
          tbtemp.Push(aclass.at(aclasssize));
      }

      tbtemp.Pop();
      tb.Pop();
      int tbtempsize = tbtemp.GetStackSize()-1;

      for(tbtempsize;tbtempsize>=0;tbtempsize--){
          if(tbtemp.at(tbtempsize)->tokenE == "RBRACE"){
              scopevalue =tbtemp.at(tbtempsize)->value1->value;;
              tb.Pop();
              scopes = SearchLocalVariablesClasses(tb,scopevalue);
              scopes = DeleteOtherValuesClasses(scopes);
              ChekingVariablesClasses(scopes);
              ChekingRepeatVariableDeclarationsClasses(scopes);
          }else{
              if(tbtemp.at(tbtempsize)->tokenE != "RBRACE" && !tb.isEmpty()){
                  tb.Pop();
              }

          }
    }
}
//Valida las variables en scopes globales y locales
vector<pElementSCH > ScopeCheckingVariablesClasses(TablesStack &tb){
    vector<vector<pElementSCH> > scopes;
    int listofclassestempsize;
    string scopevalue = " ";
    pElementSCH elements;
    GetSeparateClasses(tb);
    vector<pElementSCH> listofclassestemp;
    for(int i=0;i<listofclasses.size();i++){
        listofclassestemp = listofclasses.at(i);
        CheckVariables(listofclassestemp);
    }
    PrintErrorsScopeClasses();
    assignsvariablestypes.erase(unique(assignsvariablestypes.begin(), assignsvariablestypes.end()), assignsvariablestypes.end());
    return assignsvariablestypes;
}

vector<vector<pElementSCH > > GetAllAttributes(){
    return classesattributes;
}
vector<vector<pElementSCH > > GetAllMethods(){
    return classesmethods;
}
//para imprimir

/*cout << "---------------ACLASS---------------\n";

for(int y=0;y<globalscopevariables.size();y++){
    cout<< "Type: " <<globalscopevariables.at(y)->type << "\tToken: " <<globalscopevariables.at(y)->tokenE << "\tValue 1: " <<globalscopevariables.at(y)->value1->value<< "\tValue 2: " <<globalscopevariables.at(y)->value2->value<< "\tLine: " <<globalscopevariables.at(y)->rowE<< "\tColumn: " <<globalscopevariables.at(y)->columnE<<"\n";
}*/

//cout << "-----------------------------------\n";

/*cout << "---------------ACLASS---------------\n";

for(int y=0;y<globalsoflocals.size();y++){
    cout<< "Type: " <<globalsoflocals.at(y)->type << "\tToken: " <<globalsoflocals.at(y)->tokenE << "\tValue 1: " <<globalsoflocals.at(y)->value1->value<< "\tValue 2: " <<globalsoflocals.at(y)->value2->value<< "\tLine: " <<globalsoflocals.at(y)->rowE<< "\tColumn: " <<globalsoflocals.at(y)->columnE<<"\n";
}

cout << "-----------------------------------\n";*/

/*for(int i=0;i<tb.GetStackSize();i++){
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  cout<< "Type: " <<tb.at(i)->type<<"\n";
  cout<<"\tToken: " <<tb.at(i)->tokenE<<"\n";
  cout<< "\tValue 1: " <<tb.at(i)->value1->value<<"\n";
  cout<< "\tValue 2: " <<tb.at(i)->value2->value<<"\n";
  cout<< "\tLine: " <<tb.at(i)->rowE<<"\n";
  cout<< "\tColumn: " <<tb.at(i)->columnE<<"\n";
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
}*/

/*for(int i=0;i<scopes.size();i++){
  if(i==0){
      cout << "///////LOCAL ASSIGN///////\n";
  }
  if(i==1){
      cout << "///////LOCAL DECL////////\n";
  }
  if(i==2){
      cout << "///////LOCAL GLOBALES////////\n";
  }
    for(int y=0;y<scopes.at(i).size();y++){
        cout<< "Type: " <<scopes.at(i).at(y)->type << "\tToken: " <<scopes.at(i).at(y)->tokenE << "\tValue 1: " <<scopes.at(i).at(y)->value1->value<< "\tValue 2: " <<scopes.at(i).at(y)->value2->value<< "\tLine: " <<scopes.at(i).at(y)->rowE<< "\tColumn: " <<scopes.at(i).at(y)->columnE<<"\n";
    }

}
cout << "//////////////////////////////////\n";
cout << "\n";*/
/*cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
cout<< "Type: " <<tb.at(stackpositions)->type<<"\n";
cout<<"\tToken: " <<tb.at(stackpositions)->tokenE<<"\n";
cout<< "\tValue 1: " <<tb.at(stackpositions)->value1->value<<"\n";
cout<< "\tValue 2: " <<tb.at(stackpositions)->value2->value<<"\n";
cout<< "\tLine: " <<tb.at(stackpositions)->rowE<<"\n";
cout<< "\tColumn: " <<tb.at(stackpositions)->columnE<<"\n";
cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";*/

/*for(int i=0;i<classesattributes.size();i++){
  int size = classesattributes.at(i).size();
  cout << "-------------ATTRIBUTES----------------------\n";
  for(int y=0;y<size;y++){
      cout<< "Type: " <<classesattributes.at(i).at(y)->type<<"\n";
      cout<<"\tToken: " <<classesattributes.at(i).at(y)->tokenE<<"\n";
      cout<< "\tValue 1: " <<classesattributes.at(i).at(y)->value1->value<<"\n";
      cout<< "\tValue 2: " <<classesattributes.at(i).at(y)->value2->value<<"\n";
      cout<< "\tLine: " <<classesattributes.at(i).at(y)->rowE<<"\n";
      cout<< "\tColumn: " <<classesattributes.at(i).at(y)->columnE<<"\n";
  }
  cout << "-----------------------------------\n";
}
for(int i=0;i<classesmethods.size();i++){
  int size = classesmethods.at(i).size();
  cout << "---------------METHODS------------------\n";
  for(int y=0;y<size;y++){
      cout<< "Type: " <<classesmethods.at(i).at(y)->type<<"\n";
      cout<<"\tToken: " <<classesmethods.at(i).at(y)->tokenE<<"\n";
      cout<< "\tValue 1: " <<classesmethods.at(i).at(y)->value1->value<<"\n";
      cout<< "\tValue 2: " <<classesmethods.at(i).at(y)->value2->value<<"\n";
      cout<< "\tLine: " <<classesmethods.at(i).at(y)->rowE<<"\n";
      cout<< "\tColumn: " <<classesmethods.at(i).at(y)->columnE<<"\n";
  }
  cout << "-----------------------------------\n";
}
cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";*/
/*cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
cout<< "Type: " <<classname->type<<"\n";
cout<<"\tToken: " <<classname->tokenE<<"\n";
cout<< "\tValue 1: " <<classname->value1->value<<"\n";
cout<< "\tValue 2: " <<classname->value2->value<<"\n";
cout<< "\tLine: " <<classname->rowE<<"\n";
cout<< "\tColumn: " <<classname->columnE<<"\n";
cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";*/
/*for(int i=0;i<listofclasses.size();i++){
    listofclasses.pop_back();
}
for(int i=0;i<listofclassestemp.size();i++){

        cout<< "Type: " <<listofclassestemp.at(i)->type<<"\n";
        cout<<"\tToken: " <<listofclassestemp.at(i)->tokenE<<"\n";
        cout<< "\tValue 1: " <<listofclassestemp.at(i)->value1->value<<"\n";
        cout<< "\tValue 2: " <<listofclassestemp.at(i)->value2->value<<"\n";
        cout<< "\tLine: " <<listofclassestemp.at(i)->rowE<<"\n";
        cout<< "\tColumn: " <<listofclassestemp.at(i)->columnE<<"\n";
    cout << "-----------------------------------\n";
}*/


/*for(int i=0;i<listofclasses.size();i++){
    listofclassessize = listofclasses.at(i).size();
    for(listofclassessize;listofclassessize>=0;listofclassessize--){
          //cout << "STACKPOSITIONS: \n"<<stackpositions<<"\n";
         if(list.at(stackpositions)->tokenE == "RBRACE"){
              scopevalue =tbtemp.at(stackpositions)->value1->value;;
              tb.Pop();
              //scopes = SearchLocalVariablesClasses(tb);
                //scopes = DeleteOtherValues(scopes);
                //scopes = DivideScopes(scopes);
                //ChekingVariables(scopes);
                //Validar si hay declaraciones repetidas en un scope
                //ChekingRepeatVariableDeclarations(scopes);
                //PrintSCSElements();
        }else{
              if(tbtemp.at(stackpositions)->tokenE != "RBRACE" && !tb.isEmpty()){
                  tb.Pop();
              }

        }
}*/
/*for(stackpositions;stackpositions>=0;stackpositions--){
      //cout << "STACKPOSITIONS: \n"<<stackpositions<<"\n";
     if(tbtemp.at(stackpositions)->tokenE == "RBRACE"){
          scopevalue =tbtemp.at(stackpositions)->value1->value;;
          tb.Pop();
          //scopes = SearchLocalVariablesClasses(tb);
            //scopes = DeleteOtherValues(scopes);
            //scopes = DivideScopes(scopes);
            //ChekingVariables(scopes);
            //Validar si hay declaraciones repetidas en un scope
            //ChekingRepeatVariableDeclarations(scopes);
            //PrintSCSElements();
    }else{
          if(tbtemp.at(stackpositions)->tokenE != "RBRACE" && !tb.isEmpty()){
              tb.Pop();
          }

    }
}*/

/*cout << "T1:"<<classesattributes.size()<<"\n";
cout << "T2:"<<classesmethods.size()<<"\n";
for(int i=0;i<classesattributes.size();i++){
  int size = classesattributes.at(i).size();
  cout << "-------------ATTRIBUTES----------------------\n";
  for(int y=0;y<size;y++){
      cout<< "Type: " <<classesattributes.at(i).at(y)->type<<"\n";
      cout<<"\tToken: " <<classesattributes.at(i).at(y)->tokenE<<"\n";
      cout<< "\tValue 1: " <<classesattributes.at(i).at(y)->value1->value<<"\n";
      cout<< "\tValue 2: " <<classesattributes.at(i).at(y)->value2->value<<"\n";
      cout<< "\tLine: " <<classesattributes.at(i).at(y)->rowE<<"\n";
      cout<< "\tColumn: " <<classesattributes.at(i).at(y)->columnE<<"\n";
  }
  cout << "-----------------------------------\n";
}
for(int i=0;i<classesmethods.size();i++){
  int size = classesmethods.at(i).size();
  cout << "---------------METHODS------------------\n";
  for(int y=0;y<size;y++){
      cout<< "Type: " <<classesmethods.at(i).at(y)->type<<"\n";
      cout<<"\tToken: " <<classesmethods.at(i).at(y)->tokenE<<"\n";
      cout<< "\tValue 1: " <<classesmethods.at(i).at(y)->value1->value<<"\n";
      cout<< "\tValue 2: " <<classesmethods.at(i).at(y)->value2->value<<"\n";
      cout<< "\tLine: " <<classesmethods.at(i).at(y)->rowE<<"\n";
      cout<< "\tColumn: " <<classesmethods.at(i).at(y)->columnE<<"\n";
  }
  cout << "-----------------------------------\n";
}
cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";*/
#endif // SCOPECHECKINGVARIABLESCLASSES_H_INCLUDED
