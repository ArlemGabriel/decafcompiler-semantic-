#ifndef CLASSSTRUCTURE_H_INCLUDED
#define CLASSSTRUCTURE_H_INCLUDED

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "ElementSCH.h"

typedef ElementSCH * pElementSCH;

class ClassStructure
{
private:
        pElementSCH classname;
        pElementSCH superclass;
        vector<pElementSCH> classattributes;
        vector<pElementSCH> classmethods;
public:
        ClassStructure(){
            classname = new ElementSCH;
            superclass = new ElementSCH;
        }
        void SetClassName(pElementSCH pClassname;){
            classname = pClassname;
        }
        void SetSUperClass(pElementSCH pSuperClass;){
            superclass = pSuperClass;
        }
        void SetClassAttributes(vector<pElementSCH> pClassattributes;){
            classattributes = pClassattributes;
        }
        void SetClassMetjods(vector<pElementSCH> pClassMethods;){
            classMethods = pClassMethods;
        }
        pElementSCH GetClassName(){
            return classname;
        }
        pElementSCH GetSuperClass(){
            return superclass;
        }
        vector<pElementSCH> GetClassAttributes(){
            return classattributes;
        }
        vector<pElementSCH> GetClassMethods(){
            return classmethods;
        }

};

#endif // CLASSSTRUCTURE_H_INCLUDED
