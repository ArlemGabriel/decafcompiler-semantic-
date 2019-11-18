#ifndef ELEMENTSFORSCOPE_H_INCLUDED
#define ELEMENTSFORSCOPE_H_INCLUDED

#include <vector>

std::vector<string> elements;
//Función que agrega id, token, value a un vector de strings
void addElement(string id, string token, string value,string type){
    elements.clear();
    elements.push_back(id);
    elements.push_back(token);
    elements.push_back(value);
    elements.push_back(type);
}
//Función que retorna el vector de strings
vector<string> getElement(){
    return elements;
}

#endif // ELEMENTSFORSCOPE_H_INCLUDED
