#ifndef TABLESTACK_H_INCLUDED
#define TABLESTACK_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

class TablesStack{
    private:
        std::vector<vector<vector<string> > > tablestack;
    public:
        void Push(vector<vector<string> > ptable) {
            tablestack.push_back(ptable);
        }
        void Pop(){
            tablestack.pop_back();
        }

};

#endif // TABLESTACK_H_INCLUDED