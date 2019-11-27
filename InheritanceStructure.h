#ifndef INHERITANCESTRUCTURE_H_INCLUDED
#define INHERITANCESTRUCTURE_H_INCLUDED

#include <vector>
#include "stacktables.h"
#include "ElementSCH.h"
#include <algorithm>
#include "semanticerrors.h"
#include "ClassStructure.h"
typedef ClassStructure * pClassStructure;

pClassStructure newclass;
vector<ClassStructure> classeslist;
vector<pElementSCH > repeatclasses;

//vector<pElementSCH> undeclaredvariables;

void CreateInheritanceStructure(vector<vector<pElementSCH > > listmethods, vector<vector<pElementSCH > > listattributes){
  vector<pElementSCH > newclassesfrommethods;
  vector<pElementSCH > newclassesfromattributes;
  vector<pElementSCH > tempmethod;
  vector<pElementSCH > withoutrepeats;
  vector<pElementSCH > finalwithoutrepeats;
  vector<pElementSCH > finalrepeats;
  //Obtiene las clases de la lista de metodos
  for(int i=0;i<listmethods.size();i++){
      tempmethod = listmethods.at(i);
      newclassesfrommethods.push_back(tempmethod.at(tempmethod.size()-1));
  }
  //Ordena las clases de la lista de clases para posteriormente sacar los repetidos
  newclassesfrommethods=SortDecl(newclassesfrommethods);

  //Si es mas de un elemento procede a sacar los repetidos
  if(newclassesfrommethods.size()>1){
      for (int i = 1; i<newclassesfrommethods.size(); i++){
          if (newclassesfrommethods.at(i-1)->value1->value == newclassesfrommethods.at(i)->value1->value) {
                repeatclasses.push_back(newclassesfrommethods[i-1]);
          }if(newclassesfrommethods.at(i-1)->value1->value != newclassesfrommethods.at(i)->value1->value){
                withoutrepeats.push_back(newclassesfrommethods[i-1]);
          }if(i==newclassesfrommethods.size()-1){
                withoutrepeats.push_back(newclassesfrommethods.at(i));
          }
      }
  }
  //Si es solamente un elemento entonces lo agrega a la lista de no repetidos
  if(newclassesfrommethods.size()==1){
      withoutrepeats.push_back(newclassesfrommethods.at(0));
  }

  //Mismo proceso pero con la lista de atributos
  for(int i=0;i<listattributes.size();i++){
      tempmethod = listattributes.at(i);
      newclassesfromattributes.push_back(tempmethod.at(tempmethod.size()-1));
  }
  newclassesfromattributes =SortDecl(newclassesfromattributes);
  if(newclassesfromattributes.size()>1){
      for (int i = 1; i<newclassesfromattributes.size(); i++){
          if (newclassesfromattributes.at(i-1)->value1->value == newclassesfromattributes.at(i)->value1->value) {
                repeatclasses.push_back(newclassesfromattributes[i-1]);
          }if(newclassesfromattributes.at(i-1)->value1->value != newclassesfromattributes.at(i)->value1->value){
                withoutrepeats.push_back(newclassesfromattributes[i-1]);
          }if(i==newclassesfrommethods.size()-1){
                withoutrepeats.push_back(newclassesfromattributes.at(i));
          }
      }
  }
  if(newclassesfromattributes.size()==1){
      withoutrepeats.push_back(newclassesfromattributes.at(0));;
  }


  repeatclasses =SortDecl(repeatclasses);
  if(repeatclasses.size()>1){
      for (int i = 1; i<repeatclasses.size(); i++){
          if (repeatclasses.at(i-1)->value1->value == repeatclasses.at(i)->value1->value) {
                //repeatclasses.push_back(newclassesfromattributes[i-1]);
          }if(repeatclasses.at(i-1)->value1->value != repeatclasses.at(i)->value1->value){
                finalrepeats.push_back(repeatclasses[i-1]);
          }if(i==repeatclasses.size()-1){
                finalrepeats.push_back(repeatclasses.at(i));
          }
      }
  }
  if(repeatclasses.size()==1){
      finalrepeats.push_back(repeatclasses.at(0));
  }


  withoutrepeats =SortDecl(withoutrepeats);
  if(withoutrepeats.size()>1){
      for (int i = 1; i<withoutrepeats.size(); i++){
          if (withoutrepeats.at(i-1)->value1->value == withoutrepeats.at(i)->value1->value) {
                //repeatclasses.push_back(newclassesfromattributes[i-1]);
          }if(withoutrepeats.at(i-1)->value1->value != withoutrepeats.at(i)->value1->value){
                finalwithoutrepeats.push_back(withoutrepeats[i-1]);
          }if(i==withoutrepeats.size()-1){
                finalwithoutrepeats.push_back(withoutrepeats.at(i));
          }
      }
  }
  if(withoutrepeats.size()==1){
      finalwithoutrepeats.push_back(withoutrepeats.at(0));
  }



  /*cout << "NEWCLASSSIZE:"<< finalrepeats.size()<<"\n";
  for (int i = 0; i<finalrepeats.size(); i++){
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<< "Type: " <<finalrepeats.at(i)->type<<"\n";
    cout<<"\tToken: " <<finalrepeats.at(i)->tokenE<<"\n";
    cout<< "\tValue 1: " <<finalrepeats.at(i)->value1->value<<"\n";
    cout<< "\tValue 2: " <<finalrepeats.at(i)->value2->value<<"\n";
    cout<< "\tLine: " <<finalrepeats.at(i)->rowE<<"\n";
    cout<< "\tColumn: " <<finalrepeats.at(i)->columnE<<"\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  }
  cout <<"WITHOUT"<<finalwithoutrepeats.size()<<"\n";
  for (int i = 0; i<finalwithoutrepeats.size(); i++){
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<< "Type: " <<finalwithoutrepeats.at(i)->type<<"\n";
    cout<<"\tToken: " <<finalwithoutrepeats.at(i)->tokenE<<"\n";
    cout<< "\tValue 1: " <<finalwithoutrepeats.at(i)->value1->value<<"\n";
    cout<< "\tValue 2: " <<finalwithoutrepeats.at(i)->value2->value<<"\n";
    cout<< "\tLine: " <<finalwithoutrepeats.at(i)->rowE<<"\n";
    cout<< "\tColumn: " <<finalwithoutrepeats.at(i)->columnE<<"\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  }*/
}
vector<ClassStructure> GetInheritanceStructure(){
    return classeslist;
}
#endif // INHERITANCESTRUCTURE_H_INCLUDED
