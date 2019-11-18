#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include <stdio.h>
#include <vector>
#include "funcionesParser.h"

typedef NodeParseTree * pNodeParseTree;

class ElementSCH
{
public:
	ElementSCH()
	{
		type = "";
        tokenE = "";
        value1 = new NodeParseTree();
        value2 = new NodeParseTree();
        rowE = -1;
        columnE = -1;
	}

	ElementSCH(string pType, string pToken, pNodeParseTree pValue1, pNodeParseTree pValue2, int pRow, int pColumn)
	{ 
		type = pType;
        tokenE = pToken;
		value1 = pValue1;
        value2 = pValue2;
		rowE = pRow;
		columnE = pColumn;
	}    


	string type;
    string tokenE;
    pNodeParseTree value1;
    pNodeParseTree value2;

    int rowE;
    int columnE;    

};


#endif // ELEMENT_H_INCLUDED