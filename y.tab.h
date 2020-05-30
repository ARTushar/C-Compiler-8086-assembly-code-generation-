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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    ASSIGNOP = 262,
    COMMA = 263,
    INCOP = 264,
    DECOP = 265,
    FLOAT = 266,
    CHAR = 267,
    INT = 268,
    LCURL = 269,
    LPAREN = 270,
    LTHIRD = 271,
    NOT = 272,
    PRINTLN = 273,
    RCURL = 274,
    RETURN = 275,
    SEMICOLON = 276,
    RTHIRD = 277,
    RPAREN = 278,
    VOID = 279,
    DOUBLE = 280,
    ADDOP = 281,
    CONST_FLOAT = 282,
    CONST_INT = 283,
    ID = 284,
    LOGICOP = 285,
    MULOP = 286,
    RELOP = 287,
    LOWER_THAN_ELSE = 288
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define ASSIGNOP 262
#define COMMA 263
#define INCOP 264
#define DECOP 265
#define FLOAT 266
#define CHAR 267
#define INT 268
#define LCURL 269
#define LPAREN 270
#define LTHIRD 271
#define NOT 272
#define PRINTLN 273
#define RCURL 274
#define RETURN 275
#define SEMICOLON 276
#define RTHIRD 277
#define RPAREN 278
#define VOID 279
#define DOUBLE 280
#define ADDOP 281
#define CONST_FLOAT 282
#define CONST_INT 283
#define ID 284
#define LOGICOP 285
#define MULOP 286
#define RELOP 287
#define LOWER_THAN_ELSE 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 57 "1605070.y" /* yacc.c:1909  */

	SymbolInfo* info;

#line 124 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
