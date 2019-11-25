%{
//----------------------------- Declaraciones -----------------------------
#include <iostream>
#include "funcionesParser.h"
#include "semanticCheck.h"
using namespace std;

typedef NodeParseTree * pNodeParseTree;
int contNodos=0;
bool flagSintaxError = false;


pNodeParseTree nodo = new NodeParseTree();

std::vector<pNodeParseTree> childsToAdd;

std::vector<std::vector<pNodeParseTree>> listChildsToAdd;

void createNewNode(string pToken, string pValue, int pRow, int pColumn);
void addBlankToChilds();
void createNewListaChilds();
void addNodeToChilds();
void addChildsToNode(int offset);
void printTree(pNodeParseTree root);
void printChilds(pNodeParseTree root, int tabs);
std::vector<string> treeToPrint;

extern void addError(int pRow,int pColumn,string pError);
extern void semanticCheck(pNodeParseTree root);
extern int yylex(void);
extern void printTable();
extern int yyparse();
extern FILE *yyin;
extern int yylineno;
extern int yycolumn;
extern bool flagLexicalError;

int yyerror(char *s);
%}

//----------------------------- Definiciones -----------------------------
//Palabras reservadas
%token CLASS TVOID STRING THIS WHILE BREAK READINTEGER INT EXTENDS IF NEW READLINE DOUBLE INTERFACE
%token IMPLEMENTS ELSE NEWARRAY TRUE BOOL TNULL FOR RETURN PRINT FALSE

//Operadores
//      +       -             *           /       %       <          <=            >           >=
%token SUM SUBTRACTION MULTIPLICATION DIVISION MODULE LESSTHAN LESSEQUALTHAN GREATERTHAN GREATEREQUALTHAN
//       =     ==       !=    && ||     !        ;       ,    .      [        ]       (     )
%token EQUAL EEQUAL DISTINCT AND OR NEGATION SEMICOLON COMMA DOT LBRACKET RBRACKET LPAREN RPAREN
//        {     }
%token LBRACE RBRACE

//Datos
%token <sval> ID
%token <sval> CONSINTEGERDEC
%token <sval> CONSINTEGERHEX
%token <sval> CONSDOUBLEDEC
%token <sval> CONSDOUBLECIEN
%token <sval> CONSSTRING
%token <sval> CONSBOOLEAN

%union {
    char* sval;
}

%left OR
%left AND
%left DISTINCT EEQUAL
%left SUM SUBTRACTION
%left MULTIPLICATION DIVISION MODULE
%left NEGATION
%left DOT LBRACKET

%nonassoc COMMA
%nonassoc LPAREN LBRACE
%nonassoc ID
%nonassoc EQUAL
%nonassoc LESSTHAN LESSEQUALTHAN GREATEREQUALTHAN GREATERTHAN
%nonassoc TVOID CLASS INTERFACE DOUBLE INT STRING BOOL


%%
//----------------------------- Producciones -----------------------------
Program			: Decl															{createNewListaChilds();	createNewNode("Decl","",yylineno,yycolumn);	addChildsToNode(0);}
				;

Decl 			: VariableDecl OtraDecl											{createNewListaChilds();	createNewNode("VariableDecl","",yylineno,yycolumn);	addChildsToNode(1);	addNodeToChilds();
					createNewNode("OtraDecl","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				| FunctionDecl OtraDecl											{createNewListaChilds(); 	createNewNode("FunctionDecl","",yylineno,yycolumn);	addChildsToNode(1);	addNodeToChilds();
					createNewNode("OtraDecl","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				| ClassDecl OtraDecl											{createNewListaChilds(); 	createNewNode("ClassDecl","",yylineno,yycolumn);		addChildsToNode(1);	addNodeToChilds();
					createNewNode("OtraDecl","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				| InterfaceDecl OtraDecl										{createNewListaChilds(); 	createNewNode("InterfaceDecl","",yylineno,yycolumn);	addChildsToNode(1);	addNodeToChilds();
					createNewNode("OtraDecl","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				;

OtraDecl		: Decl OtraDecl													{createNewListaChilds();	createNewNode("OtraDecl","",yylineno,yycolumn);		addChildsToNode(1);	addNodeToChilds();
					createNewNode("OtraDecl","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

VariableDecl 	: Variable SEMICOLON											{createNewListaChilds(); 	createNewNode("Variable","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();
					createNewNode("SEMICOLON",";",yylineno,yycolumn);		addNodeToChilds();}
				;

Variable 		: Type ID														{createNewListaChilds();	createNewNode("Type","",yylineno,yycolumn); 			addChildsToNode(0);	addNodeToChilds();
					createNewNode("ID",$2,yylineno,yycolumn);				addNodeToChilds();}
				;

Type 			: INT															{createNewListaChilds();	createNewNode("INT","",yylineno,yycolumn);			addNodeToChilds();}
				| DOUBLE														{createNewListaChilds(); 	createNewNode("DOUBLE","",yylineno,yycolumn);			addNodeToChilds();}
				| BOOL															{createNewListaChilds(); 	createNewNode("BOOL","",yylineno,yycolumn);			addNodeToChilds();}
				| STRING														{createNewListaChilds();	createNewNode("STRING","",yylineno,yycolumn);			addNodeToChilds();}
				| ID															{createNewListaChilds(); 	createNewNode("ID",$1,yylineno,yycolumn);				addNodeToChilds();}
				| Type LBRACKET RBRACKET										{createNewListaChilds(); 	createNewNode("Type","",yylineno,yycolumn);			addChildsToNode(0);	addNodeToChilds();
						createNewNode("LBRACKET","",yylineno,yycolumn);	addNodeToChilds();
						createNewNode("RBRACKET","",yylineno,yycolumn);	addNodeToChilds();}
				;

FunctionDecl 	: Type ID LPAREN Formals RPAREN StmtBlock						{createNewListaChilds(); 	createNewNode("Type","",yylineno,yycolumn);			addChildsToNode(2); addNodeToChilds();
					createNewNode("ID",$2,yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Formals","",yylineno,yycolumn);		addChildsToNode(1);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("StmtBlock","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				| TVOID ID LPAREN Formals RPAREN StmtBlock						{createNewListaChilds(); 	createNewNode("TVOID","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",$2,yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Formals","",yylineno,yycolumn);		addChildsToNode(1);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("StmtBlock","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				;

Formals 		: Variable FormalsVars											{createNewListaChilds(); 	createNewNode("Variable","",yylineno,yycolumn);		addChildsToNode(1);	addNodeToChilds();
					createNewNode("FormalsVars","",yylineno,yycolumn);	addChildsToNode(0);		addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

FormalsVars		: COMMA Variable FormalsVars									{createNewListaChilds(); 	createNewNode("COMMA","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Variable","",yylineno,yycolumn);		addChildsToNode(1);		addNodeToChilds();
					createNewNode("FormalsVars","",yylineno,yycolumn);	addChildsToNode(0);		addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

ClassDecl 		: CLASS ID ExtendDecl ImplementsDecl LBRACE Field RBRACE		{createNewListaChilds(); 	createNewNode("CLASS","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",$2,yylineno,yycolumn);				addNodeToChilds();
					createNewNode("ExtendDecl","",yylineno,yycolumn);		addChildsToNode(2);		addNodeToChilds();
					createNewNode("ImplementsDecl","",yylineno,yycolumn);	addChildsToNode(1);		addNodeToChilds();
					createNewNode("LBRACE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Field","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();
					createNewNode("RBRACE","",yylineno,yycolumn);			addNodeToChilds();}
				;

ExtendDecl		: EXTENDS ID													{createNewListaChilds(); 	createNewNode("EXTENDS","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("ID",$2,yylineno,yycolumn);				addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

ImplementsDecl	: IMPLEMENTS ID OtroID											{createNewListaChilds(); 	createNewNode("IMPLEMENTS","",yylineno,yycolumn);		addNodeToChilds();
						createNewNode("ID",$2,yylineno,yycolumn);			addNodeToChilds();
						createNewNode("OtroID","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

OtroID			: COMMA ID OtroID												{createNewListaChilds(); 	createNewNode("COMMA","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",$2,yylineno,yycolumn);				addNodeToChilds();
					createNewNode("OtroID","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

Field 			: VariableDecl Field											{createNewListaChilds(); 	createNewNode("VariableDecl","",yylineno,yycolumn);	addChildsToNode(1);	addNodeToChilds();
					createNewNode("Field","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| FunctionDecl Field											{createNewListaChilds();	createNewNode("FunctionDecl","",yylineno,yycolumn);	addChildsToNode(1);	addNodeToChilds();
					createNewNode("Field","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

InterfaceDecl	: INTERFACE ID LBRACE Prototype RBRACE							{createNewListaChilds();	createNewNode("INTERFACE","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("ID",$2,yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LBRACE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Prototype","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();
					createNewNode("RBRACE","",yylineno,yycolumn);			addNodeToChilds();}
				;

Prototype 		: Type ID LPAREN Formals RPAREN SEMICOLON Prototype				{createNewListaChilds(); 	createNewNode("Type","",yylineno,yycolumn);			addChildsToNode(2);	addNodeToChilds();
					createNewNode("ID",$2,yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Formals","",yylineno,yycolumn);		addChildsToNode(1);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Prototype","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				| TVOID ID LPAREN Formals RPAREN SEMICOLON Prototype				{createNewListaChilds(); 	createNewNode("TVOID","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",$2,yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Formals","",yylineno,yycolumn);		addChildsToNode(1);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Prototype","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

StmtBlock 		: LBRACE BlockVariables BlockStmts RBRACE						{createNewListaChilds(); 	createNewNode("LBRACE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("BlockVariables","",yylineno,yycolumn);	addChildsToNode(1);		addNodeToChilds();
					createNewNode("BlockStmts","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();
					createNewNode("RBRACE","",yylineno,yycolumn);			addNodeToChilds();}
				;

BlockVariables	: VariableDecl BlockVariables									{createNewListaChilds();	createNewNode("VariableDecl","",yylineno,yycolumn);	addChildsToNode(1);	addNodeToChilds();
					createNewNode("BlockVariables","",yylineno,yycolumn);	addChildsToNode(0);		addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

BlockStmts		: Stmt BlockStmts												{createNewListaChilds(); 	createNewNode("Stmt","",yylineno,yycolumn);			addChildsToNode(1);	addNodeToChilds();
					createNewNode("BlockStmts","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

Stmt 			: ExprOpcional SEMICOLON										{createNewListaChilds(); 	createNewNode("ExprOpcional","",yylineno,yycolumn);	addChildsToNode(0);	addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();}
				| IfStmt														{createNewListaChilds(); 	createNewNode("IfStmt","",yylineno,yycolumn);			addChildsToNode(0);	addNodeToChilds();}
				| WhileStmt														{createNewListaChilds(); 	createNewNode("WhileStmt","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
				| ForStmt														{createNewListaChilds(); 	createNewNode("ForStmt","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
				| BreakStmt														{createNewListaChilds(); 	createNewNode("BreakStmt","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
				| ReturnStmt													{createNewListaChilds(); 	createNewNode("ReturnStmt","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
				| PrintStmt														{createNewListaChilds(); 	createNewNode("PrintStmt","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
				| StmtBlock														{createNewListaChilds(); 	createNewNode("StmtBlock","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
				;

IfStmt 			: IF LPAREN Expr RPAREN Stmt ElseStmt							{createNewListaChilds(); 	createNewNode("IF","",yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(2);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Stmt","",yylineno,yycolumn);			addChildsToNode(1);		addNodeToChilds();
					createNewNode("ElseStmt","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				;

ElseStmt		: ELSE Stmt														{createNewListaChilds(); 	createNewNode("ELSE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Stmt","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

WhileStmt 		: WHILE LPAREN Expr RPAREN Stmt									{createNewListaChilds(); 	createNewNode("WHILE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Stmt","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				;

ForStmt 		: FOR LPAREN ExprOpcional SEMICOLON ExprOpcional SEMICOLON ExprOpcional RPAREN Stmt	{createNewListaChilds(); createNewNode("FOR","",yylineno,yycolumn); addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn); 		addNodeToChilds();
					createNewNode("ExprOpcional","",yylineno,yycolumn); 	addChildsToNode(3);		addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn); 		addNodeToChilds();
					createNewNode("ExprOpcional","",yylineno,yycolumn);	addChildsToNode(2);		addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("ExprOpcional","",yylineno,yycolumn); 	addChildsToNode(1);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn); 		addNodeToChilds();
					createNewNode("Stmt","",yylineno,yycolumn); 			addChildsToNode(0);		addNodeToChilds();}
				;

ReturnStmt 		: RETURN ExprOpcional SEMICOLON									{createNewListaChilds();	createNewNode("RETURN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ExprOpcional","",yylineno,yycolumn);	addChildsToNode(0);		addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();}
				;

BreakStmt 		: BREAK SEMICOLON												{createNewListaChilds(); 	createNewNode("BREAK","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();}
				;

PrintStmt 		: PRINT LPAREN Expr OtraExpr RPAREN SEMICOLON					{createNewListaChilds();	createNewNode("PRINT","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);		addNodeToChilds();
					createNewNode("OtraExpr","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("SEMICOLON","",yylineno,yycolumn);		addNodeToChilds();}
				;

OtraExpr		: COMMA Expr OtraExpr											{createNewListaChilds(); 	createNewNode("COMMA","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);		addNodeToChilds();
					createNewNode("OtraExpr","",yylineno,yycolumn);		addChildsToNode(0);		addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

ExprOpcional	: Expr															{createNewListaChilds(); 	createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);	addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

Expr 			: LValue EQUAL Expr												{createNewListaChilds(); 	createNewNode("LValue","",yylineno,yycolumn);			addChildsToNode(1);	addNodeToChilds();
					createNewNode("EQUAL","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Constant														{createNewListaChilds();	createNewNode("Constant","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
				| LValue														{createNewListaChilds(); 	createNewNode("LValue","",yylineno,yycolumn);			addChildsToNode(0);	addNodeToChilds();}
				| THIS															{createNewListaChilds(); 	createNewNode("THIS","",yylineno,yycolumn);			addNodeToChilds();}
				| Call															{createNewListaChilds(); 	createNewNode("Call","",yylineno,yycolumn);			addChildsToNode(0);	addNodeToChilds();}
				| LPAREN Expr RPAREN											{createNewListaChilds(); 	createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
				| Expr SUM Expr													{createNewListaChilds(); 	createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);	addNodeToChilds();
					createNewNode("SUM","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Expr SUBTRACTION Expr											{createNewListaChilds(); 	createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);	addNodeToChilds();
					createNewNode("SUBTRACTION","",yylineno,yycolumn);							addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Expr MULTIPLICATION Expr										{createNewListaChilds(); 	createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);	addNodeToChilds();
					createNewNode("MULTIPLICATION","",yylineno,yycolumn);	addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Expr DIVISION Expr											{createNewListaChilds(); 	createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);	addNodeToChilds();
					createNewNode("DIVISION","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Expr MODULE Expr												{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("MODULE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| SUBTRACTION Expr	%prec NEGATION								{createNewListaChilds(); createNewNode("SUBTRACTION","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Expr LESSTHAN Expr											{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("LESSTHAN","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Expr LESSEQUALTHAN Expr										{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("LESSEQUALTHAN","",yylineno,yycolumn);	addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Expr GREATERTHAN Expr											{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("GREATERTHAN","",yylineno,yycolumn);						addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Expr GREATEREQUALTHAN Expr									{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("GREATEREQUALTHAN","",yylineno,yycolumn);					addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Expr EEQUAL Expr												{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("EEQUAL","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Expr DISTINCT Expr											{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("DISTINCT","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Expr AND Expr													{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("AND","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| Expr OR Expr													{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("OR","",yylineno,yycolumn);				addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| NEGATION Expr													{createNewListaChilds(); createNewNode("NEGATION","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();}
				| READINTEGER LPAREN RPAREN										{createNewListaChilds(); createNewNode("READINTEGER","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
				| READLINE LPAREN RPAREN										{createNewListaChilds(); createNewNode("READLINE","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
				| NEW LPAREN ID RPAREN											{createNewListaChilds(); createNewNode("NEW","",yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",$3,yylineno,yycolumn);				addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
				| NEWARRAY LPAREN Expr COMMA Type RPAREN						{createNewListaChilds(); createNewNode("NEWARRAY","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(1);		addNodeToChilds();
					createNewNode("COMMA","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Type","",yylineno,yycolumn);			addChildsToNode(0);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
				;

LValue 			: ID															{createNewListaChilds(); createNewNode("ID",$1,yylineno,yycolumn);				addNodeToChilds();}
				| Expr DOT ID 													{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(0);	addNodeToChilds();
					createNewNode("DOT","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",$3,yylineno,yycolumn);				addNodeToChilds();}
				| Expr LBRACKET Expr RBRACKET									{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("LBRACKET","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("Expr","",yylineno,yycolumn);			addChildsToNode(0);	addNodeToChilds();
					createNewNode("RBRACKET","",yylineno,yycolumn);		addNodeToChilds();}
				;

Call 			: ID LPAREN Actuals RPAREN										{createNewListaChilds(); createNewNode("ID",$1,yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Actuals","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
				| Expr DOT ID LPAREN Actuals RPAREN								{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(0);	addNodeToChilds();
					createNewNode("DOT","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("ID",$3,yylineno,yycolumn);				addNodeToChilds();
					createNewNode("LPAREN","",yylineno,yycolumn);			addNodeToChilds();
					createNewNode("Actuals","",yylineno,yycolumn);		addNodeToChilds();
					createNewNode("RPAREN","",yylineno,yycolumn);			addNodeToChilds();}
				;

Actuals 		: Expr OtraExpr													{createNewListaChilds(); createNewNode("Expr","",yylineno,yycolumn);				addChildsToNode(1);	addNodeToChilds();
					createNewNode("OtraExpr","",yylineno,yycolumn);		addChildsToNode(0);	addNodeToChilds();}
				|																%prec EQUAL {createNewListaChilds();addBlankToChilds();}
				;

Constant 		: CONSINTEGERDEC												{createNewListaChilds(); createNewNode("CONSINTEGERDEC",$1,yylineno,yycolumn);	addNodeToChilds();}
				| CONSINTEGERHEX												{createNewListaChilds(); createNewNode("CONSINTEGERHEX",$1,yylineno,yycolumn);	addNodeToChilds();}
				| CONSDOUBLEDEC													{createNewListaChilds(); createNewNode("CONSDOUBLEDEC",$1,yylineno,yycolumn);		addNodeToChilds();}
				| CONSDOUBLECIEN 												{createNewListaChilds(); createNewNode("CONSDOUBLECIEN",$1,yylineno,yycolumn);	addNodeToChilds();}
				| CONSBOOLEAN													{createNewListaChilds(); createNewNode("CONSBOOLEAN",$1,yylineno,yycolumn);		addNodeToChilds();}
				| CONSSTRING 													{createNewListaChilds(); createNewNode("CONSSTRING",$1,yylineno,yycolumn);		addNodeToChilds();}
				| TNULL															{createNewListaChilds(); createNewNode("TNULL","",yylineno,yycolumn);				addNodeToChilds();}
				;

%%

//----------------------------- Funciones -----------------------------

int yyerror(char *s){
	//printf("\nERROR\n");
	addError(yylineno,yycolumn,"Sintax error");
  flagSintaxError = true;
	return 1;
}

int main(int argcount, char **argvector)
{
    if (argcount == 2)
    {
        FILE *myfile = fopen(argvector[1], "r");
	    if (!myfile) {
		    cout << "No se puede leer el archivo con código o no existe" << endl;
		    return -1;
	    }
	    yyin = myfile;
    }
    else{
        yyin=stdin;
    }
	yyparse();
	if (flagLexicalError == false && flagSintaxError == false){
		//printTable();
		//printTree(nodo);
		semanticCheck(nodo);

	}else{
		printTable();
	}
}


void createNewListaChilds(){
	listChildsToAdd.push_back(childsToAdd);
}

void createNewNode(string pToken, string pValue, int pRow, int pColumn){
	nodo= newNode(pToken, pValue, pRow, pColumn);
}

void addBlankToChilds(){
	pNodeParseTree nodonull = new NodeParseTree("<Sin hijos>","",yylineno,yycolumn);
	listChildsToAdd.at(listChildsToAdd.size()-1).push_back(nodonull);
}

void addNodeToChilds(){
		listChildsToAdd.at(listChildsToAdd.size()-1).push_back(nodo);
}

void addChildsToNode(int offset){
	int position = (listChildsToAdd.size()-2)-offset;
	if(position>=0){
		for(int i=0;i<listChildsToAdd.at(position).size();i++)
		{
			pNodeParseTree child = listChildsToAdd.at(position).at(i);
			nodo->addChild(child);
		}
		listChildsToAdd.erase(listChildsToAdd.begin() + position);
	}
}


void printTree(pNodeParseTree root){
  if(flagSintaxError == false){
      cout << "Program" << "\n";
    	cout << " -" << root->token << "\n";

    	printChilds(root, 1);
    	for(int i=treeToPrint.size();i>0;i--){
    		cout<<treeToPrint[i];
    	}
  }
}

void printChilds(pNodeParseTree root, int tabs){
	for(int i=root->childs.size()-1;i>=0;i--)
    {
		//Agarra en hijo del parametro nodo root
		pNodeParseTree child = root->childs.at(i);

		//Si tiene otros hijos los imprime
		if(child->childs.size()>0)
			printChilds(child,tabs+1);

		string nodeToPrint="";
		//Se cuentan la cantidad de tabs necesarios
		int contHijos=0;
		for(int j=0;j<tabs;j++){
			if(j<15)
				nodeToPrint=nodeToPrint+" ";
			else
				contHijos++;
		}

		nodeToPrint=nodeToPrint+"-";
		//Por lo grande del arbol se muestra con numeros en lugar de tabs
		if(contHijos>0)
			nodeToPrint = nodeToPrint + "H(" + std::to_string(contHijos) + ") ";
			//cout << "H(" << contHijos << ") ";

		//Imprime el token del nodo actual y si tiene valor tambien lo imprime
		if(child->value == "")
			nodeToPrint = nodeToPrint + child->token /*+ " Linea: " + std::to_string(child->row) + " Columna: "+ std::to_string(child->column)*/+"\n";
			//cout << child->token << "\n";
		else
			nodeToPrint = nodeToPrint + child->token + " Valor: " + child->value /*+ " Linea: " + std::to_string(child->row) + " Columna: "+ std::to_string(child->column)*/+ "\n";
			//cout << child->token << "Valor: " << child->value << "\n";

		treeToPrint.push_back(nodeToPrint);
	}

}
