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

//vector<pElementSCH> undeclaredvariables;

void CreateInheritanceStructure(vector<vector<pElementSCH > > listmethods, vector<vector<pElementSCH > > listattributes){
    /*vector<pElementSCH > newclassmethods;
    int newclassmethossize;
    for(int i=0;i<listmethods.size();i++){
        newclassmethods = listmethods.at(i);
        if(!newclassmethods.empty()){
            newclass = new ClassStructure();
        }
        for(int y=0;y<newclassmethossize;y++){

        }
    }*/
}
vector<pClassStructure> GetInheritanceStructure(){
    return classeslist;
}
#endif // INHERITANCESTRUCTURE_H_INCLUDED
