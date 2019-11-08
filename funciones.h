#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

std::vector<int> row;
std::vector<int> column;
std::vector<string> token;
std::vector<string> value;
std::vector<string> errors;
std::vector<int> columnerrors;
std::vector<int> rowerrors;
int errorssize;

void addRow(int prow,int pcolumn,string ptoken,string pvalue)
{
    row.push_back(prow);
    column.push_back(pcolumn);
    token.push_back(ptoken);
    value.push_back(pvalue);
}

void printErrors()
{
    for(int i=0;i<errorssize;i++)
    {
        std::cout << "ERROR: " << errors[i] << " on line:" << rowerrors[i] << " column:" << columnerrors[i]<<" \n";
    }
}

void printTable()
{
    int rowssize = row.size();
    int columnssize = column.size();
    int tokenssize = token.size();
    int valuessize = value.size();
    errorssize = errors.size();
    if(rowssize==columnssize && columnssize==tokenssize && tokenssize==valuessize){
        if(rowssize!=0){
          if(errorssize==0){
              printf("%-8s%-8s%-16s%-8s\n", "LINE", "COLUMN", "TOKEN", "VALUE");
              for(int i=0;i<row.size();i++)
              {
                  printf("%-8d%-8d%-16s%-8s\n",row[i],column[i],token[i].c_str(),value[i].c_str());
              }
          }else{
            printErrors();
          }

        }
    }else{
        std::cout << "ERROR: It doesnt exist the same size of rows and columns";
    }

}
void addError(int pRow,int pColumn,string pError){
    errors.push_back(pError);
    rowerrors.push_back(pRow);
    columnerrors.push_back(pColumn);
}





#endif // FUNCIONES_H_INCLUDED
