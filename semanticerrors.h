#ifndef SEMANTICERRORS_H_INCLUDED
#define SEMANTICERRORS_H_INCLUDED

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "ElementSCH.h"

typedef ElementSCH * pElementSCH;

class SemanticError
{
private:
        string typeError;
        pElementSCH variableError;
public:
        SemanticError(){
          typeError ="";
          variableError = new ElementSCH;
        }
        //Funcion que hace push de un elemento en la pila
        SemanticError(string pTypeError,pElementSCH pVariableError)
      	{
      	   typeError = pTypeError;
           variableError = pVariableError;
      	}
        string GetTypeError(){
            return typeError;
        }
        string GetType(){
            return variableError->type;
        }
        string GetToken(){
            return variableError->tokenE;
        }
        string GetValue1(){
            return variableError->value1->value;
        }
        string GetValue2(){
            return variableError->value2->value;
        }
        string GetRow(){
            return to_string(variableError->rowE);
        }
        string GetColumn(){
            return to_string(variableError->columnE);
        }
        pElementSCH GetVariableError(){
            return variableError;
        }

};

#endif // SEMANTICERRORS_H_INCLUDED
