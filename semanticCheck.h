#include "funcionesParser.h"
#include "ElementSCH.h"


typedef NodeParseTree * pNodeParseTree;
typedef ElementSCH * pElementSCH;
std::vector<pElementSCH> elementsForSemanticCheck;
std::vector<pElementSCH> globalElementsForSemanticCheck;


bool flagGlobalScope=true;
int elementValuePosition=0;
string type;
string tokenTMP;
pNodeParseTree value1;
pNodeParseTree value2;
int rowTMP;
int columnTMP;
pElementSCH newElement;

void restartVariables(){
    elementValuePosition=0;
    type="";
    tokenTMP="";
    value1= new NodeParseTree();
    value2= new NodeParseTree();
    rowTMP=-1;
    columnTMP=-1;
}

void searchRelevantNodes(pNodeParseTree root){
    
    for(int i=0;i<root->childs.size();i++)
    {		
		//Agarra en hijo del parametro nodo root
		pNodeParseTree child = root->childs.at(i);
		
        if(child->token=="FunctionDecl"){               
            tokenTMP=child->token;
            flagGlobalScope=false;
        }
        else if(child->token=="Variable"|| child->token=="Expr" || child->token=="DIVISION" || child->token=="MODULE" || child->token=="LESSTHAN" || child->token=="RBRACE" || child->token=="LBRACE" ||
                child->token=="LESSEQUALTHAN" || child->token=="GREATERTHAN" || child->token=="GREATEREQUALTHAN" || child->token=="SUM" || child->token=="SUBTRACTION" || child->token=="MULTIPLICATION" ||
                child->token=="RETURN" ||  child->token=="PRINT")
            tokenTMP=child->token;        
        else if(flagGlobalScope){            
            if((child->token=="ID" || child->token=="BOOL" || child->token=="VOID" ||  child->token=="STRING" ||  child->token=="INT" ||  child->token=="DOUBLE") && elementValuePosition==0 && tokenTMP=="Variable"){                
                if(child->token=="ID")
                    type=child->value;
                else
                    type=child->token;

                rowTMP=child->row;
                columnTMP=child->column;

                elementValuePosition=1;
            }   
            else if(tokenTMP=="Variable"){
                value1=child;                
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                globalElementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }
        }
        else if(child->token=="OtraDecl")
        {            
            flagGlobalScope=true;
        }
        else{               
            if((child->token=="Type") && elementValuePosition==0 && tokenTMP=="Variable"){                  
                if(child->childs.at(0)->token=="ID")
                    type=child->childs.at(0)->value;
                else
                    type=child->childs.at(0)->token;

                rowTMP=child->childs.at(0)->row;
                columnTMP=child->childs.at(0)->column;

                elementValuePosition=1;
            }   
            else if(tokenTMP=="Variable" && elementValuePosition==1 && child->token=="ID"){                                
                value1=child;                
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                elementsForSemanticCheck.push_back(newElement);
                restartVariables();
            } else if(child->token=="ID" && elementValuePosition==0 && tokenTMP=="Expr"){                         
                value1=child;
                rowTMP=child->row;
                columnTMP=child->column;
                elementValuePosition=1;
            }   
            else if((child->token=="EQUAL" || child->token=="EEQUAL" || child->token=="DISTINCT" ||  child->token=="AND" ||  child->token=="OR" ||  child->token=="NEGATION") && elementValuePosition==1 && tokenTMP=="Expr"){                                
                type=child->token;                               
                elementValuePosition=2;
            }
            else if(child->token=="RPAREN"  && elementValuePosition==1 && tokenTMP=="Expr"){ 
                type="Parameters";                                               
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                elementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }
            else if(elementValuePosition==2 && tokenTMP=="Expr"){                                
                value2=child;
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                elementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }
            else if(elementValuePosition==0 && (child->token=="CONSINTEGERDEC" || child->token=="CONSINTEGERHEX" || child->token=="CONSDOUBLEDEC" || child->token=="CONSDOUBLECIEN" || 
                    child->token=="CONSSTRING" || child->token=="CONSBOOLEAN"  ||
                    child->token=="DISTINCT" ||  child->token=="AND" ||  child->token=="OR" ||  child->token=="NEGATION" ||  
                    child->token=="TNULL")){                                
                type=child->token;          
                rowTMP=child->row;
                columnTMP=child->column;                     
                elementValuePosition=1;
            }else if(elementValuePosition==1 && tokenTMP=="Expr" && (type=="CONSINTEGERDEC" || type=="CONSINTEGERHEX" || type=="CONSDOUBLEDEC" || type=="CONSDOUBLECIEN" || 
                    type=="CONSSTRING" || type=="CONSBOOLEAN"  ||
                    type=="DISTINCT" ||  type=="AND" ||  type=="OR" ||  type=="NEGATION" ||  
                    type=="TNULL")){                                
                value1=child;                
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                elementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }
        }

        //Si tiene otros hijos los busca
		if(child->childs.size()>0)
			searchRelevantNodes(child);        
		
		/*if( child->token=="CONSINTEGERDEC" || child->token=="CONSINTEGERHEX" || child->token=="CONSDOUBLEDEC" || child->token=="CONSDOUBLECIEN" || 
            child->token=="CONSSTRING" || child->token=="CONSBOOLEAN"  ||
            child->token=="DISTINCT" ||  child->token=="AND" ||  child->token=="OR" ||  child->token=="NEGATION" ||  
            child->token=="TNULL" )	*/		
	}
}

void semanticCheck(pNodeParseTree root){    
    searchRelevantNodes(root);
    
    cout<<"Globals\n";
    for(int i=0; i<globalElementsForSemanticCheck.size();i++){
        cout<< "Type: " <<globalElementsForSemanticCheck.at(i)->type << "\tToken: " <<globalElementsForSemanticCheck.at(i)->tokenE << "\tValue1: " <<globalElementsForSemanticCheck.at(i)->value1->token<<"\n";
    }

    cout<<"\nOthers\n";
    for(int i=0; i<elementsForSemanticCheck.size();i++){
        cout<< "Type: " <<elementsForSemanticCheck.at(i)->type << "\tToken: " <<elementsForSemanticCheck.at(i)->tokenE << "\tValue1: " <<elementsForSemanticCheck.at(i)->value1->token<<"\n";
    }
    
    //TODO empezar a revisar los nodos de elementsForSemanticCheck, y utilizar la pila de tablas
    
}

