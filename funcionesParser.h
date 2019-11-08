#ifndef FUNCIONES_PARSER_H_INCLUDED
#define FUNCIONES_PARSER_H_INCLUDED

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream> 


class NodeParseTree
{
public:
	NodeParseTree()
	{
		token = "";
        value = "";
        row = -1;
        column = -1;
	}

	NodeParseTree(string pToken, string pValue, int pRow, int pColumn)
	{ 
		token = pToken;
		value = pValue;
		row = pRow;
		column = pColumn;
	}    

    void addChild(NodeParseTree *pChild){
        childs.push_back(pChild);
    }

	string token;
    string value;

    int row;
    int column;    
	std::vector<NodeParseTree*> childs;

};

typedef NodeParseTree * pNodeParseTree;

pNodeParseTree newNode(string pToken, string pValue, int pRow, int pColumn){
    return new NodeParseTree(pToken, pValue, pRow, pColumn);	
}



#endif // FUNCIONES_PARSER_H_INCLUDED