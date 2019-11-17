#ifndef TABLESCOPE_H_INCLUDED
#define TABLESCOPE_H_INCLUDED

#include <vector>

std::vector<vector<string> > table;

void addList(vector<string> pList){
    table.push_back(pList);
}
void deleteTable(){
    table.clear();
}
vector<vector<string> > getTable(){
    return table;
}

#endif // TABLESCOPE_H_INCLUDED
