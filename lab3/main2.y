%{
/*************************
main2.y
YACC FILE
Date: 2020-10-16
Ji Zheng <zhengji1205@qq.com>
*************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#ifndef YYSTYPE
#define YYSTYPE double
#endif 
int yylex(); 
extern int yyparse();
FILE* yyin;
void yyerror(const char*s );
%}

%token ADD
%token SUB
%token MUL
%token DIV
%token LBRACKET
%token RBRACKET
%token DIGIT

%left ADD SUB
%left MUL DIV
%right UMINUS

%%


lines   :   lines expr '\n' { printf("%f\n", $2); }
        |   lines '\n'
        |
        ;

expr    :   expr ADD expr               { $$ = $1 + $3; } 
        |   expr SUB expr               { $$ = $1 - $3; }
        |   expr MUL expr               { $$ = $1 * $3; }
        |   expr DIV expr               { $$ = $1 / $3; }
        |   LBRACKET expr RBRACKET      { $$ = $2;      }
        |   SUB expr %prec UMINUS       { $$ =-$2;      } 
        |   DIGIT
        ;

%%


int yylex()
{ 
    int t;
    while(1)
    {
        t = getchar();
        if (t == ' ' || t == '\t');
        else if (t == '+')return ADD;        
        else if (t == '-')return SUB;
        else if (t == '*')return MUL;
        else if (t == '/')return DIV;
        else if (t == '(')return LBRACKET;
        else if (t == ')')return RBRACKET;
        else if (t == 'q')exit(0);
        else if (isdigit(t))
        {
            yylval = 0;
            while(isdigit(t))
            {
                yylval = yylval * 10 + t - '0';
                t = getchar();
            }
            ungetc(t,stdin);
            return DIGIT;
        }
        else return t;
    }
}

int main(void)
{
    yyin = stdin ; 
    do {
            yyparse();
    } while (! feof(yyin)); 
    return 0;
}
void yyerror(const char* s) { 
    fprintf(stderr,"Parse error: %s\n",s);
    exit(1);
}