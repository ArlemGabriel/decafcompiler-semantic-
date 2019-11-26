#include "funcionesParser.h"
#include "ElementSCH.h"
#include "stacktables.h"
#include "auxiliaryfunctions.h"
#include "typesprimitivevalidation.h"


typedef NodeParseTree * pNodeParseTree;
typedef ElementSCH * pElementSCH;
std::vector<pElementSCH> elementsForSemanticCheck;
std::vector<pElementSCH> globalElementsForSemanticCheck;
std::vector<pElementSCH> classElementsForSemanticCheck;
std::vector<pElementSCH> assigns;


bool flagGlobalScope=true;
bool flagClassScope=false;
int elementValuePosition=0;
string type;
string tokenTMP;
string tokenToAdd=" ";
pNodeParseTree value1 = new NodeParseTree();;
pNodeParseTree value2 = new NodeParseTree();;
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
        //cout<<flagClassScope;
		//Agarra en hijo del parametro nodo root
		pNodeParseTree child = root->childs.at(i);

        if(child->token=="FunctionDecl" && !flagClassScope){
            tokenTMP=child->token;
            flagGlobalScope=false;
        }        
        else if(child->token=="CLASS"){
            flagGlobalScope=false;
            flagClassScope=true;
            tokenTMP=child->token;            
        }
        else if(flagClassScope==true && tokenTMP=="CLASS"){
            newElement= new ElementSCH(tokenTMP,child->token, child,value2,child->row,child->column);
            classElementsForSemanticCheck.push_back(newElement);            
            restartVariables();
        }
        else if(child->token=="Variable"|| child->token=="Expr"  || child->token=="RETURN" || child->token=="Constant")
            tokenTMP=child->token;
        else if((child->token=="RBRACE" || child->token=="LBRACE") && !flagClassScope){
            newElement= new ElementSCH(tokenToAdd,child->token, value1,value2,child->row,child->column);
            elementsForSemanticCheck.push_back(newElement);
            tokenToAdd="";
            restartVariables();
        }else if(child->token=="RBRACE" || child->token=="LBRACE"){
            newElement= new ElementSCH(tokenToAdd,child->token, value1,value2,child->row,child->column);
            classElementsForSemanticCheck.push_back(newElement);
            tokenToAdd="";
            restartVariables();
        }else if(child->token=="RETURN" || child->token=="PRINT" || child->token=="IF" || child->token=="FOR" || child->token=="WHILE"){
            tokenToAdd=child->token;
        }
        else if(flagClassScope){
            if((child->token=="Type" || child->token=="TVOID") && elementValuePosition==0 && (tokenTMP=="Variable" || tokenTMP=="FunctionDecl")){             
                if(child->token!= "TVOID"){                    
                    if(child->childs.at(0)->token=="ID")
                        type=child->childs.at(0)->value;
                    else
                        type=child->childs.at(0)->token;

                    rowTMP=child->childs.at(0)->row;
                    columnTMP=child->childs.at(0)->column;
                }
                else{
                    type="VOID";
                    rowTMP=child->row;
                    columnTMP=child->column;
                }


                elementValuePosition=1;
            }
            else if((tokenTMP=="Variable" || tokenTMP=="FunctionDecl")  && elementValuePosition==1 && child->token=="ID"){                
                value1=child;
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                classElementsForSemanticCheck.push_back(newElement);

                /*if(child->value=="main" && tokenTMP=="FunctionDecl"){
                    std::vector<pElementSCH> tempElements;
                    tempElements.push_back(newElement);
                    classElementsForSemanticCheck.insert(classElementsForSemanticCheck.begin(), tempElements.begin(), tempElements.end());
                }else{
                    classElementsForSemanticCheck.push_back(newElement);
                }//*/
                restartVariables();
            } else if(((child->token=="ID" && tokenTMP=="Expr") || tokenTMP=="Constant") && elementValuePosition==0 ){
                //cout<< "CCCCCCCCCCCCCCC\n";
                pNodeParseTree childTMP= new NodeParseTree();
                if(i+1!=root->childs.size())
                    childTMP = root->childs.at(i+1);
                if(childTMP->token=="EQUAL"){
                    value1=child;
                    rowTMP=child->row;
                    columnTMP=child->column;

                    type=childTMP->token;
                    newElement= new ElementSCH(type,"Expr", value1,value2,rowTMP,columnTMP);
                    classElementsForSemanticCheck.push_back(newElement);
                    restartVariables();

                    i++;
                    //elementValuePosition=1;
                } else{
                    value1=child;
                    rowTMP=child->row;
                    columnTMP=child->column;

                    type=child->token;
                    newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                    classElementsForSemanticCheck.push_back(newElement);
                    restartVariables();
                }

            }
            /*else if((child->token=="EQUAL" || child->token=="EEQUAL" || child->token=="DISTINCT" ||  child->token=="AND" ||  child->token=="OR" ||  child->token=="NEGATION") && elementValuePosition==1){            
                type=child->token;
                newElement= new ElementSCH(type,"Expr", value1,value2,rowTMP,columnTMP);
                classElementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }//*/
            else if(child->token=="RPAREN"  && elementValuePosition==1 && tokenTMP=="Expr"){
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                classElementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }
            else if (elementValuePosition==0 && child->token=="DIVISION" || child->token=="MODULE" || child->token=="LESSTHAN" || child->token=="LESSEQUALTHAN" || child->token=="GREATERTHAN" ||
                        child->token=="GREATEREQUALTHAN" || child->token=="SUM" || child->token=="SUBTRACTION" || child->token=="MULTIPLICATION" || child->token=="EEQUAL" ||
                        child->token=="DISTINCT" ||  child->token=="AND" ||  child->token=="OR" ||  child->token=="NEGATION"){                
                tokenTMP=child->token;
                rowTMP=child->row;
                columnTMP=child->column;
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                classElementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }
            /*else if(elementValuePosition==1 && tokenToAdd=="DIVISION" || tokenToAdd=="MODULE" || tokenToAdd=="LESSTHAN" || tokenToAdd=="LESSEQUALTHAN" || tokenToAdd=="GREATERTHAN" ||
                        tokenToAdd=="GREATEREQUALTHAN" || tokenToAdd=="SUM" || tokenToAdd=="SUBTRACTION" || tokenToAdd=="MULTIPLICATION"){
                //cout<< "OK\n";
                value1=child;
                type=child->token;
                newElement= new ElementSCH(type,tokenToAdd, value1,value2,rowTMP,columnTMP);
                classElementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }//*/
            else if(elementValuePosition==0 && (child->token=="CONSINTEGERDEC" || child->token=="CONSINTEGERHEX" || child->token=="CONSDOUBLEDEC" || child->token=="CONSDOUBLECIEN" ||
                    child->token=="CONSSTRING" || child->token=="CONSBOOLEAN"  || child->token=="DISTINCT" ||  child->token=="AND" ||  child->token=="OR" ||  child->token=="NEGATION" ||
                    child->token=="TNULL")){                
                value1=child;
                type=child->token;
                rowTMP=child->row;
                columnTMP=child->column;
                elementValuePosition=1;
            } else if(child->token=="RPAREN"  && elementValuePosition==1 && tokenTMP=="Constant"){                
                newElement= new ElementSCH(type,tokenToAdd, value1,value2,rowTMP,columnTMP);
                classElementsForSemanticCheck.push_back(newElement);
                tokenToAdd="";
                restartVariables();
            }else if(elementValuePosition==1 && tokenTMP=="Expr" && (type=="CONSINTEGERDEC" || type=="CONSINTEGERHEX" || type=="CONSDOUBLEDEC" || type=="CONSDOUBLECIEN" ||
                    type=="CONSSTRING" || type=="CONSBOOLEAN"  ||  type=="DISTINCT" ||  type=="AND" ||  type=="OR" ||  type=="NEGATION" ||   type=="TNULL")){                
                value1=child;
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                classElementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }
        }
         else if(flagGlobalScope){
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
                globalElementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }
        }
        else if(child->token=="OtraDecl")
        {
            flagGlobalScope=true;
        }
        else{            
            if((child->token=="Type" || child->token=="TVOID") && elementValuePosition==0 && (tokenTMP=="Variable" || tokenTMP=="FunctionDecl")){             
                if(child->token!= "TVOID"){                    
                    if(child->childs.at(0)->token=="ID")
                        type=child->childs.at(0)->value;
                    else
                        type=child->childs.at(0)->token;

                    rowTMP=child->childs.at(0)->row;
                    columnTMP=child->childs.at(0)->column;
                }
                else{
                    type="VOID";
                    rowTMP=child->row;
                    columnTMP=child->column;
                }


                elementValuePosition=1;
            }
            else if((tokenTMP=="Variable" || tokenTMP=="FunctionDecl")  && elementValuePosition==1 && child->token=="ID"){                
                value1=child;
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                elementsForSemanticCheck.push_back(newElement);

                /*if(child->value=="main" && tokenTMP=="FunctionDecl"){
                    std::vector<pElementSCH> tempElements;
                    tempElements.push_back(newElement);
                    elementsForSemanticCheck.insert(elementsForSemanticCheck.begin(), tempElements.begin(), tempElements.end());
                }else{
                    elementsForSemanticCheck.push_back(newElement);
                }//*/
                restartVariables();
            } else if(((child->token=="ID" && tokenTMP=="Expr") || tokenTMP=="Constant") && elementValuePosition==0 ){
                //cout<< "CCCCCCCCCCCCCCC\n";
                pNodeParseTree childTMP= new NodeParseTree();
                if(i+1!=root->childs.size())
                    childTMP = root->childs.at(i+1);
                if(childTMP->token=="EQUAL"){
                    value1=child;
                    rowTMP=child->row;
                    columnTMP=child->column;

                    type=childTMP->token;
                    newElement= new ElementSCH(type,"Expr", value1,value2,rowTMP,columnTMP);
                    elementsForSemanticCheck.push_back(newElement);
                    restartVariables();

                    i++;
                    //elementValuePosition=1;
                } else{
                    value1=child;
                    rowTMP=child->row;
                    columnTMP=child->column;

                    type=child->token;
                    newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                    elementsForSemanticCheck.push_back(newElement);
                    restartVariables();
                }

            }
            /*else if((child->token=="EQUAL" || child->token=="EEQUAL" || child->token=="DISTINCT" ||  child->token=="AND" ||  child->token=="OR" ||  child->token=="NEGATION") && elementValuePosition==1){            
                type=child->token;
                newElement= new ElementSCH(type,"Expr", value1,value2,rowTMP,columnTMP);
                elementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }//*/
            else if(child->token=="RPAREN"  && elementValuePosition==1 && tokenTMP=="Expr"){
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                elementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }
            else if (elementValuePosition==0 && child->token=="DIVISION" || child->token=="MODULE" || child->token=="LESSTHAN" || child->token=="LESSEQUALTHAN" || child->token=="GREATERTHAN" ||
                        child->token=="GREATEREQUALTHAN" || child->token=="SUM" || child->token=="SUBTRACTION" || child->token=="MULTIPLICATION" || child->token=="EEQUAL" ||
                        child->token=="DISTINCT" ||  child->token=="AND" ||  child->token=="OR" ||  child->token=="NEGATION"){                
                tokenTMP=child->token;
                rowTMP=child->row;
                columnTMP=child->column;
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                elementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }
            /*else if(elementValuePosition==1 && tokenToAdd=="DIVISION" || tokenToAdd=="MODULE" || tokenToAdd=="LESSTHAN" || tokenToAdd=="LESSEQUALTHAN" || tokenToAdd=="GREATERTHAN" ||
                        tokenToAdd=="GREATEREQUALTHAN" || tokenToAdd=="SUM" || tokenToAdd=="SUBTRACTION" || tokenToAdd=="MULTIPLICATION"){
                //cout<< "OK\n";
                value1=child;
                type=child->token;
                newElement= new ElementSCH(type,tokenToAdd, value1,value2,rowTMP,columnTMP);
                elementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }//*/
            else if(elementValuePosition==0 && (child->token=="CONSINTEGERDEC" || child->token=="CONSINTEGERHEX" || child->token=="CONSDOUBLEDEC" || child->token=="CONSDOUBLECIEN" ||
                    child->token=="CONSSTRING" || child->token=="CONSBOOLEAN"  || child->token=="DISTINCT" ||  child->token=="AND" ||  child->token=="OR" ||  child->token=="NEGATION" ||
                    child->token=="TNULL")){                
                value1=child;
                type=child->token;
                rowTMP=child->row;
                columnTMP=child->column;
                elementValuePosition=1;
            } else if(child->token=="RPAREN"  && elementValuePosition==1 && tokenTMP=="Constant"){                
                newElement= new ElementSCH(type,tokenToAdd, value1,value2,rowTMP,columnTMP);
                elementsForSemanticCheck.push_back(newElement);
                tokenToAdd="";
                restartVariables();
            }else if(elementValuePosition==1 && tokenTMP=="Expr" && (type=="CONSINTEGERDEC" || type=="CONSINTEGERHEX" || type=="CONSDOUBLEDEC" || type=="CONSDOUBLECIEN" ||
                    type=="CONSSTRING" || type=="CONSBOOLEAN"  ||  type=="DISTINCT" ||  type=="AND" ||  type=="OR" ||  type=="NEGATION" ||   type=="TNULL")){                
                value1=child;
                newElement= new ElementSCH(type,tokenTMP, value1,value2,rowTMP,columnTMP);
                elementsForSemanticCheck.push_back(newElement);
                restartVariables();
            }
        }

        //Si tiene otros hijos los busca
		if(child->childs.size()>0)
			searchRelevantNodes(child);

	}
}
//Inserta en la pila los elementos para validar los scopes
void InsertScopesOnStack(string typeValidation,TablesStack &tb){
    //Inserta en la pila los scopes para validar variables locales y globales
    if(typeValidation=="Functions"){
        for(int i=0; i<globalElementsForSemanticCheck.size();i++){
            tb.Push(globalElementsForSemanticCheck.at(i));
        }

        for(int i=0; i<elementsForSemanticCheck.size();i++){
            tb.Push(elementsForSemanticCheck.at(i));
        }
    }
    //Inserta en la pila los scopes para validar los scopes de clases
    if(typeValidation=="Classes"){
        /*
        for(int i=0; i<clases.size();i++){
            tb.Push(clases.at(i));
        }*/
    }
}
void ValidateScopeFunctions(string typescope){
    TablesStack tb;
    InsertScopesOnStack(typescope,tb);
    tb.SetBracesIndex();
    tb.SetBracesOwner();
    /*tb.printStack();
    cout << "--------------------------------------------------------------\n";
    cout << "--------------------------------------------------------------\n";*/
    tb.DeleteStructureBraces();
    assigns = ScopeCheckingVariables(tb,typescope);
    //tb.printStack();
}
void ValidateTypes(){
    TablesStack tb;
    InsertScopesOnStack("Functions",tb);
    tb.SetBracesIndex();
    tb.SetBracesOwner();
    tb.DeleteStructureBraces();
    TypesCheckingPrimitiveVariables(tb,assigns);
}
void ValidateScopeClasses(string typescope){
    TablesStack tb;
    InsertScopesOnStack(typescope,tb);
    tb.SetBracesIndex();
    ScopeCheckingVariables(tb,typescope);
}
void semanticCheck(pNodeParseTree root){
    searchRelevantNodes(root);
    cout << "\n\nOtros\n";
    for(int i=0;i<elementsForSemanticCheck.size();i++){
        cout<< "Type: " <<elementsForSemanticCheck.at(i)->type << "\tToken: " <<elementsForSemanticCheck.at(i)->tokenE << "\tValue 1: " <<elementsForSemanticCheck.at(i)->value1->value<< "\tValue 2: " <<elementsForSemanticCheck.at(i)->value2->value<< "\tLine: " <<elementsForSemanticCheck.at(i)->rowE<< "\tColumn: " <<elementsForSemanticCheck.at(i)->columnE<<"\n";
    }
    cout << "\n\nGlobal\n";
    for(int i=0;i<globalElementsForSemanticCheck.size();i++){
        cout<< "Type: " <<globalElementsForSemanticCheck.at(i)->type << "\tToken: " <<globalElementsForSemanticCheck.at(i)->tokenE << "\tValue 1: " <<globalElementsForSemanticCheck.at(i)->value1->value<< "\tValue 2: " <<globalElementsForSemanticCheck.at(i)->value2->value<< "\tLine: " <<globalElementsForSemanticCheck.at(i)->rowE<< "\tColumn: " <<globalElementsForSemanticCheck.at(i)->columnE<<"\n";
    }
    cout << "\n\nClases\n";
    for(int i=0;i<classElementsForSemanticCheck.size();i++){
        cout<< "Type: " <<classElementsForSemanticCheck.at(i)->type << "\tToken: " <<classElementsForSemanticCheck.at(i)->tokenE << "\tValue 1: " <<classElementsForSemanticCheck.at(i)->value1->value<< "\tValue 2: " <<classElementsForSemanticCheck.at(i)->value2->value<< "\tLine: " <<classElementsForSemanticCheck.at(i)->rowE<< "\tColumn: " <<classElementsForSemanticCheck.at(i)->columnE<<"\n";
    }

    //Llamada para validar scopes en funciones y variables
    //ValidateScopeFunctions("Functions");
    //ValidateTypes();
    //ValidateScopeClasses("Classes");

    //TODO empezar a revisar los nodos de globalElementsForSemanticCheck y elementsForSemanticCheck, y utilizar la pila de tablas

}
