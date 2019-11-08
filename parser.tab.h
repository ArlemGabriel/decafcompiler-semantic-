/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    VOID = 259,
    STRING = 260,
    THIS = 261,
    WHILE = 262,
    BREAK = 263,
    READINTEGER = 264,
    INT = 265,
    EXTENDS = 266,
    IF = 267,
    NEW = 268,
    READLINE = 269,
    DOUBLE = 270,
    INTERFACE = 271,
    IMPLEMENTS = 272,
    ELSE = 273,
    NEWARRAY = 274,
    TRUE = 275,
    BOOL = 276,
    TNULL = 277,
    FOR = 278,
    RETURN = 279,
    PRINT = 280,
    FALSE = 281,
    SUM = 282,
    SUBTRACTION = 283,
    MULTIPLICATION = 284,
    DIVISION = 285,
    MODULE = 286,
    LESSTHAN = 287,
    LESSEQUALTHAN = 288,
    GREATERTHAN = 289,
    GREATEREQUALTHAN = 290,
    EQUAL = 291,
    EEQUAL = 292,
    DISTINCT = 293,
    AND = 294,
    OR = 295,
    NEGATION = 296,
    SEMICOLON = 297,
    COMMA = 298,
    DOT = 299,
    LBRACKET = 300,
    RBRACKET = 301,
    LPAREN = 302,
    RPAREN = 303,
    LBRACE = 304,
    RBRACE = 305,
    ID = 306,
    CONSINTEGERDEC = 307,
    CONSINTEGERHEX = 308,
    CONSDOUBLEDEC = 309,
    CONSDOUBLECIEN = 310,
    CONSSTRING = 311,
    CONSBOOLEAN = 312
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 61 "parser.y" /* yacc.c:1909  */

    char* sval;

#line 116 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
