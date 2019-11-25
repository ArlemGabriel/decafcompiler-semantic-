#ifndef TYPESPRIMITIVEVALIDATION_H_INCLUDED
#define TYPESPRIMITIVEVALIDATION_H_INCLUDED

#include <vector>
#include "stacktables.h"
#include "ElementSCH.h"
#include <algorithm>
#include "semanticerrors.h"
typedef SemanticError * pSemanticError;

pSemanticError error;
vector<pElementSCH> onlyFuncRet;
vector<pElementSCH> sublist;
vector<vector<pElementSCH> > functionslist;
vector<pSemanticError> listsemanticerrors;
//Llenar este vector con los objetos tambien
//Para ello recorrer las clases y obtener las clases que hay
//Meterlas en una lista y mandarlas a este .h
//vector<string> validobjecttypes;
vector<string> validprimitivetypes{"VOID","INT","BOOL","DOUBLE","STRING"};




//Funcion que agrega los elementos con sus respectivos tipos a la PILA
void PutTypesOnSTack(TablesStack &tb,vector<pElementSCH> assignsvariables){
    string type;
    string token;
    string value1;
    int row;
    int column;
    for(int i=0;i<assignsvariables.size();i++){
        for(int y=0;y<tb.GetStackSize();y++){
            type = tb.at(y)->type;
            token = tb.at(y)->tokenE;
            value1 = tb.at(y)->value1->value;
            row = tb.at(y)->rowE;
            column = tb.at(y)->columnE;
            if(assignsvariables.at(i)->type ==type && assignsvariables.at(i)->tokenE == token &&
            assignsvariables.at(i)->value1->value == value1 && assignsvariables.at(i)->rowE == row &&
            assignsvariables.at(i)->columnE == column){

                 tb.at(y)->value2->value = assignsvariables.at(i)->value2->value;

            }
        }
    }
    //tb.printStack();
}
void GetFunctionsAndReturn(TablesStack &tb){
    int tbsize = tb.GetStackSize()-1;
    for(tbsize;tbsize>=0;tbsize--){
        if(tb.at(tbsize)->tokenE == "FunctionDecl"){
            onlyFuncRet.push_back(tb.at(tbsize));
        }
        if(tb.at(tbsize)->tokenE == "Return"){
            onlyFuncRet.push_back(tb.at(tbsize));
            if(tbsize>0){
                if(tb.at(tbsize)->tokenE == "Variable"){
                    onlyFuncRet.push_back(tb.at(tbsize-1));
                }
            }
        }
    }
}
void CreateSublists(){
    int counter = onlyFuncRet.size()-1;
    vector<pElementSCH> sublist;
    while(!onlyFuncRet.empty()){
        if(counter == 0){
            if(onlyFuncRet.at(counter)->tokenE == "FunctionDecl"){
                sublist.push_back(onlyFuncRet.at(counter));
            }
            if(onlyFuncRet.at(counter)->tokenE == "Return"){
                sublist.push_back(onlyFuncRet.at(counter));
            }
            if(onlyFuncRet.at(counter)->tokenE == "Variable"){
                sublist.push_back(onlyFuncRet.at(counter));
            }
            onlyFuncRet.pop_back();

        }else{
            if(onlyFuncRet.at(counter)->tokenE == "FunctionDecl"){
                sublist.push_back(onlyFuncRet.at(counter));
                onlyFuncRet.pop_back();
                counter=counter-1;
            }
            if(onlyFuncRet.at(counter)->tokenE == "Return"){
                sublist.push_back(onlyFuncRet.at(counter));
                onlyFuncRet.pop_back();
                counter=counter-1;
            }
            if(onlyFuncRet.at(counter)->tokenE == "Variable"){
                sublist.push_back(onlyFuncRet.at(counter));
                onlyFuncRet.pop_back();
                counter=counter-1;
            }
        }
        functionslist.push_back(sublist);
        sublist.clear();
    }
}
void SwapVector(){
    int size = onlyFuncRet.size()-1;
    vector<pElementSCH> onlyFuncRetTemp;
    for(size;size>=0;size--){
        onlyFuncRetTemp.push_back(onlyFuncRet.at(size));
    }
    onlyFuncRet = onlyFuncRetTemp;
}
void ValidateReturnTypes(){
    for(int i=0;i<functionslist.size();i++){
        //int sizesublist = functionslist.at(i).size()-1;
        //element = functionslist.at(i).at(0);
        if(functionslist.at(i).size()==1){
              //cout << "----------------1-------------------\n";
              if(functionslist.at(i).at(0)->type !="VOID"){
                   error = new SemanticError("MissingReturn",functionslist.at(i).at(0));
                   listsemanticerrors.push_back(error);

              }
                //Agregar error de funcion sin retorno si tiene tipo diferente a void
        }
        if(functionslist.at(i).size()==2){
            //cout << "----------------2-------------------\n";
                //Agregar error de funcion si el retorno es diferente de void
            if(functionslist.at(i).at(0)->type !="VOID"){
                  error = new SemanticError("MissingReturnType",functionslist.at(i).at(0));
                  listsemanticerrors.push_back(error);
            }
        }
        if(functionslist.at(i).size()==3){
            //cout << "----------------3-------------------\n";
              //Agregar error de funcion si el tipo de la funcion no coincide con el tipo de retorno
            if(functionslist.at(i).at(0)->type != functionslist.at(i).at(2)->type){
                  error = new SemanticError("WrongReturnType",functionslist.at(i).at(2));
                  listsemanticerrors.push_back(error);
            }
        }
      }

}
void ValidateCorrectTypes(){
    //TODO
}
void PrintErrors(){
    if(!listsemanticerrors.empty()){
        for(int i=0;i<listsemanticerrors.size();i++){
            cout << listsemanticerrors.at(i)->GetTypeError()<<" ";
            cout << listsemanticerrors.at(i)->GetType()<<" ";
            cout << listsemanticerrors.at(i)->GetToken()<<" ";
            cout << listsemanticerrors.at(i)->GetValue1()<<" ";
            cout << listsemanticerrors.at(i)->GetValue2()<<" ";
            cout << listsemanticerrors.at(i)->GetColumn()<<" ";
            cout << listsemanticerrors.at(i)->GetRow()<<"\n";
        }
    }
}
void TypesCheckingPrimitiveVariables(TablesStack &tb,vector<pElementSCH> assignsvariables){
        //Funcion para agregar los elementos con sus respectivos tipos a la PILA
        PutTypesOnSTack(tb,assignsvariables);
        //tb.printStack();
        //Funcion para sacar solamente las funciones y sus respectivos ReturnStmt
        GetFunctionsAndReturn(tb);
        /*for(int i=0;i<onlyFuncRet.size();i++){
            cout<< "Type: " <<onlyFuncRet.at(i)->type << "\tToken: " <<onlyFuncRet.at(i)->tokenE << "\tValue 1: " <<onlyFuncRet.at(i)->value1->value<< "\tValue 2: " <<onlyFuncRet.at(i)->value2->value<< "\tLine: " <<onlyFuncRet.at(i)->rowE<< "\tColumn: " <<onlyFuncRet.at(i)->columnE<<"\n";

        }
        cout << "                     \n";*/
        SwapVector();
        /*for(int i=0;i<onlyFuncRet.size();i++){
            cout<< "Type: " <<onlyFuncRet.at(i)->type << "\tToken: " <<onlyFuncRet.at(i)->tokenE << "\tValue 1: " <<onlyFuncRet.at(i)->value1->value<< "\tValue 2: " <<onlyFuncRet.at(i)->value2->value<< "\tLine: " <<onlyFuncRet.at(i)->rowE<< "\tColumn: " <<onlyFuncRet.at(i)->columnE<<"\n";

        }*/
        //Funcion para crear sublistas con funcion,return y variable [F1,R1,V1] o [F1,R1] o [F1]
        CreateSublists();
        /*for(int y=0;y<functionslist.size();y++){
            int sizesublist = functionslist.at(y).size()-1;
            cout << "SIZE:" << sizesublist;
            for(int i=0;i<=sizesublist;i++){
                cout<< "Type: " <<functionslist.at(y).at(i)->type << "\tToken: " <<functionslist.at(y).at(i)->tokenE << "\tValue 1: " <<functionslist.at(y).at(i)->value1->value<< "\tValue 2: " <<functionslist.at(y).at(i)->value2->value<< "\tLine: " <<functionslist.at(y).at(i)->rowE<< "\tColumn: " <<functionslist.at(y).at(i)->columnE<<"\n";
            }
        }*/
        //FUncion que valida si los tipos de las funciones y retorno son validos
        //Usando el vector de tipos primitivos y el vector de objetos.
        ValidateCorrectTypes();
        //Funcion que una funcion retorne el tipo del que fue declarado.
        ValidateReturnTypes();
        //PrintErrors();



}

#endif // TYPESPRIMITIVEVALIDATION_H_INCLUDED
