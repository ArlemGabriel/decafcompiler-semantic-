%option noyywrap
%option yylineno
%option yyalloc
%{
    #include "funciones.h"
    #include "parser.tab.h"
    int yycolumn = 1;
    bool flagLexicalError = false;
%}
ESCAPEERROR \"[^"\\\n]*((?:\\[^nt"][^"\\]*)|(?:\\\\[^"\\\n]*))*\"
LQUOTEERROR [^"\\]*((?:\\[nt"][^"\\]*)|(?:\\\\[^"\\]*))*\"$
RQUOTEERROR \"[^"\\]*((?:\\[nt"][^"\\]*)|(?:\\\\[^"\\]*))*$
CLASS class
TVOID void
STRING string
THIS this
WHILE while
BREAK break
READINTEGER ReadInteger
INT int
EXTENDS extends
IF if
NEW New
READLINE ReadLine
DOUBLE double
INTERFACE interface
IMPLEMENTS implements
ELSE else
NEWARRAY NewArray
TRUE true
BOOL bool
TNULL null
FOR for
RETURN return
PRINT Print
FALSE false
CONSBOOLEAN True|False
ID [a-zA-Z]{1}[a-zA-Z|0-9|_]{0,30}
INVALIDID [0-9|_]+[a-zA-Z|_]+[a-zA-Z|_|0-9]*
WRONGLONGID [a-zA-Z]{1}[a-zA-Z|0-9|_]{31,}
CONSINTEGERDEC [0-9]+
CONSINTEGERHEX 0[xX][a-fA-F0-9]+
CONSDOUBLEDEC [0-9]+[.][0-9]+
CONSDOUBLECIEN [0-9]+[.][0-9]*[Ee](([+]{0,1})|-)[0-9]+
CONSSTRING \"[^"\\\n]*((?:\\[nt"][^"\\]*)|(?:\\\\[^"\\\n]*))*\"
SINGLECOMMENT \\\\[^\n\\]+
MULTICOMMENT \/\*([^*]|(\*+[^*/]))*\*+\/
SUM "+"
SUBTRACTION "-"
MULTIPLICATION "*"
DIVISION "/"
MODULE "%"
LESSTHAN "<"
LESSEQUALTHAN "<="
GREATERTHAN ">"
GREATEREQUALTHAN ">="
EQUAL "="
EEQUAL "=="
DISTINCT "!="
AND "&&"
OR "||"
NEGATION "!"
SEMICOLON ";"
COMMA ","
DOT "."
LBRACKET "["
RBRACKET "]"
LPAREN "("
RPAREN ")"
LBRACE "{"
RBRACE "}"
BLANKSPACE [ ]+
LINEBREAK \n
TAB \t
INVALIDCHAR ['|`|@|#|^|&|"|"|\\|:|?|_|$|¡|¿|´]{1}|[;]{2,}

%%
{CLASS} {addRow(yylineno,yycolumn,"CLASS","");yycolumn+=yyleng;return CLASS;}
{TVOID} {addRow(yylineno,yycolumn,"VOID","");yycolumn+=yyleng;return TVOID;}
{STRING} {addRow(yylineno,yycolumn,"STRING","");yycolumn+=yyleng;return STRING;}
{THIS} {addRow(yylineno,yycolumn,"THIS","");yycolumn+=yyleng;return THIS;}
{WHILE} {addRow(yylineno,yycolumn,"WHILE","");yycolumn+=yyleng;return WHILE;}
{BREAK} {addRow(yylineno,yycolumn,"BREAK","");yycolumn+=yyleng;return BREAK;}
{READINTEGER} {addRow(yylineno,yycolumn,"READINTEGER","");yycolumn+=yyleng;return READINTEGER;}
{INT} {addRow(yylineno,yycolumn,"INT","");yycolumn+=yyleng;return INT;}
{EXTENDS} {addRow(yylineno,yycolumn,"EXTENDS","");yycolumn+=yyleng;return EXTENDS;}
{IF} {addRow(yylineno,yycolumn,"IF","");yycolumn+=yyleng;return IF;}
{NEW} {addRow(yylineno,yycolumn,"NEW","");yycolumn+=yyleng;return NEW;}
{READLINE} {addRow(yylineno,yycolumn,"READLINE","");yycolumn+=yyleng;return READLINE;}
{DOUBLE} {addRow(yylineno,yycolumn,"DOUBLE","");yycolumn+=yyleng;return DOUBLE;}
{INTERFACE} {addRow(yylineno,yycolumn,"INTERFACE","");yycolumn+=yyleng;return INTERFACE;}
{IMPLEMENTS} {addRow(yylineno,yycolumn,"IMPLEMENTS","");yycolumn+=yyleng;return IMPLEMENTS;}
{ELSE} {addRow(yylineno,yycolumn,"ELSE","");yycolumn+=yyleng;return ELSE;}
{NEWARRAY} {addRow(yylineno,yycolumn,"NEWARRAY","");yycolumn+=yyleng;return NEWARRAY;}
{TRUE} {addRow(yylineno,yycolumn,"TRUE","");yycolumn+=yyleng;return TRUE;}
{BOOL} {addRow(yylineno,yycolumn,"BOOL","");yycolumn+=yyleng;return BOOL;}
{TNULL} {addRow(yylineno,yycolumn,"NULL","");yycolumn+=yyleng;return TNULL;}
{FOR} {addRow(yylineno,yycolumn,"FOR","");yycolumn+=yyleng;return FOR;}
{RETURN} {addRow(yylineno,yycolumn,"RETURN","");yycolumn+=yyleng;return RETURN;}
{PRINT} {addRow(yylineno,yycolumn,"PRINT","");yycolumn+=yyleng;return PRINT;}
{FALSE} {addRow(yylineno,yycolumn,"FALSE","");yycolumn+=yyleng;return FALSE;}
{CONSBOOLEAN} {addRow(yylineno,yycolumn,"BOOLEAN",yytext);yycolumn+=yyleng;yylval.sval=strdup(yytext);return CONSBOOLEAN;}
{ID}    {addRow(yylineno,yycolumn,"ID",yytext);yycolumn+=yyleng;yylval.sval=strdup(yytext);return ID;}
{CONSINTEGERHEX}    {addRow(yylineno,yycolumn,"HINTEGER",yytext);yycolumn+=yyleng;yylval.sval=strdup(yytext);return CONSINTEGERHEX;}
{CONSINTEGERDEC}    {addRow(yylineno,yycolumn,"DINTEGER",yytext);yycolumn+=yyleng;yylval.sval=strdup(yytext);return CONSINTEGERDEC;}
{CONSDOUBLEDEC} {addRow(yylineno,yycolumn,"DDOUBLE",yytext);yycolumn+=yyleng;yylval.sval=strdup(yytext);return CONSDOUBLEDEC;}
{CONSDOUBLECIEN} {addRow(yylineno,yycolumn,"CDOUBLE",yytext);yycolumn+=yyleng;yylval.sval=strdup(yytext);return CONSDOUBLECIEN;}
{CONSSTRING} {addRow(yylineno,yycolumn,"CSTRING",yytext);yycolumn+=yyleng;yylval.sval=strdup(yytext);return CONSSTRING;}
{MULTICOMMENT} {addRow(yylineno,yycolumn,"MCOMMENT",yytext);yycolumn+=yyleng;}
{SINGLECOMMENT} {addRow(yylineno,yycolumn,"SCOMMENT",yytext);yycolumn+=yyleng;}
{SUM} {addRow(yylineno,yycolumn,"SUM","");yycolumn+=yyleng;return SUM;}
{SUBTRACTION} {addRow(yylineno,yycolumn,"SUBTRACTION","");yycolumn+=yyleng;return SUBTRACTION;}
{MULTIPLICATION} {addRow(yylineno,yycolumn,"MULTIPLICATION","");yycolumn+=yyleng;return MULTIPLICATION;}
{DIVISION} {addRow(yylineno,yycolumn,"DIVISION","");yycolumn+=yyleng;return DIVISION;}
{MODULE} {addRow(yylineno,yycolumn,"MODULE","");yycolumn+=yyleng;return MODULE;}
{LESSTHAN} {addRow(yylineno,yycolumn,"LESSTHAN","");yycolumn+=yyleng;return LESSTHAN;}
{LESSEQUALTHAN} {addRow(yylineno,yycolumn,"LESSEQTHAN","");yycolumn+=yyleng;return LESSEQUALTHAN;}
{GREATERTHAN} {addRow(yylineno,yycolumn,"GREATERTHAN","");yycolumn+=yyleng;return GREATERTHAN;}
{GREATEREQUALTHAN} {addRow(yylineno,yycolumn,"GREATEREQTHAN","");yycolumn+=yyleng;return GREATEREQUALTHAN;}
{EQUAL} {addRow(yylineno,yycolumn,"EQUAL","");yycolumn+=yyleng;return EQUAL;}
{EEQUAL} {addRow(yylineno,yycolumn,"EEQUAL","");yycolumn+=yyleng;return EEQUAL;}
{DISTINCT} {addRow(yylineno,yycolumn,"DISTINCT","");yycolumn+=yyleng;return DISTINCT;}
{AND} {addRow(yylineno,yycolumn,"AND","");yycolumn+=yyleng;return AND;}
{OR} {addRow(yylineno,yycolumn,"OR","");yycolumn+=yyleng;return OR;}
{NEGATION} {addRow(yylineno,yycolumn,"NEGATION","");yycolumn+=yyleng;return NEGATION;}
{SEMICOLON} {addRow(yylineno,yycolumn,"SEMICOLON","");yycolumn+=yyleng;return SEMICOLON;}
{COMMA} {addRow(yylineno,yycolumn,"COMMA","");yycolumn+=yyleng;return COMMA;}
{DOT} {addRow(yylineno,yycolumn,"DOT","");yycolumn+=yyleng;return DOT;}
{LBRACKET} {addRow(yylineno,yycolumn,"LBRACKET","");yycolumn+=yyleng;return LBRACKET;}
{RBRACKET} {addRow(yylineno,yycolumn,"RBRACKET","");yycolumn+=yyleng;return RBRACKET;}
{LPAREN} {addRow(yylineno,yycolumn,"LPAREN","");yycolumn+=yyleng;return LPAREN;}
{RPAREN} {addRow(yylineno,yycolumn,"RPAREN","");yycolumn+=yyleng;return RPAREN;}
{LBRACE} {addRow(yylineno,yycolumn,"LBRACE","");yycolumn+=yyleng;return LBRACE;}
{RBRACE} {addRow(yylineno,yycolumn,"RBRACE","");yycolumn+=yyleng;return RBRACE;}
{ESCAPEERROR} {addError(yylineno,yycolumn,"Invalid scape secuence");flagLexicalError = true;}
{LQUOTEERROR} {addError(yylineno,yycolumn,"Missing left quote");flagLexicalError = true;}
{RQUOTEERROR} {addError(yylineno,yycolumn,"Missing right quote");flagLexicalError = true;}
{LINEBREAK} {yycolumn=1;}
{BLANKSPACE} {yycolumn+=1;}
{TAB} {yycolumn+=1;}
{INVALIDCHAR}   {addError(yylineno,yycolumn,"Invalid character");flagLexicalError = true;}
{INVALIDID} {addError(yylineno,yycolumn,"Invalid Identifier");flagLexicalError = true;}
{WRONGLONGID} {addError(yylineno,yycolumn,"Invalid length of identifier");flagLexicalError = true;}

%%
