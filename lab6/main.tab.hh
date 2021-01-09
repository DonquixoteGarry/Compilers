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

#ifndef YY_YY_MAIN_TAB_HH_INCLUDED
# define YY_YY_MAIN_TAB_HH_INCLUDED
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
    ID = 258,
    addr_id = 259,
    content_id = 260,
    INTEGER = 261,
    CHARACTER = 262,
    STRING = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    FOR = 267,
    RETURN = 268,
    CONST = 269,
    INT = 270,
    VOID = 271,
    CHAR = 272,
    STR = 273,
    SLB = 274,
    SRB = 275,
    MLB = 276,
    MRB = 277,
    LLB = 278,
    LRB = 279,
    COMMA = 280,
    SEMICOLON = 281,
    TRUE = 282,
    FALSE = 283,
    ADD = 284,
    SUB = 285,
    MUL = 286,
    DIV = 287,
    MOD = 288,
    ANSC = 289,
    DESC = 290,
    NEG = 291,
    POS = 292,
    ASSIGN = 293,
    ADD_ASS = 294,
    SUB_ASS = 295,
    MUL_ASS = 296,
    DIV_ASS = 297,
    MOD_ASS = 298,
    EQ = 299,
    NEQ = 300,
    GT = 301,
    GE = 302,
    LT = 303,
    LE = 304,
    NOT = 305,
    AND = 306,
    OR = 307,
    PRINTF = 308,
    SCANF = 309,
    dot = 310,
    LOWER_THEN_ELSE = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MAIN_TAB_HH_INCLUDED  */
