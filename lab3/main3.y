%{
/*************************
main3.y
YACC FILE
Date: 2020-10-16
Ji Zheng <zhengji1205@qq.com>
*************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef YYSTYPE
#define YYSTYPE char* //定义yystype为字符数组指针,表示不计算仅得到后缀式
#endif 
char id_buff[50];
char number_buff[50];
int yylex();
extern int yyparse();
FILE* yyin;
void yyerror(const char*s );
%}

%token DIGIT
%token ID
%token ADD
%token SUB
%token MUL
%token DIV
%token LBRACKET
%token RBRACKET


%left ADD SUB
%left MUL DIV
%%


lines   :   lines expr '\n' { printf("%s\n", $2); }
        |   lines '\n'
        |
        ;

expr    :   expr ADD expr               { $$ = (char *)malloc(50*sizeof(char)); strcpy($$,$1); strcat($$,$3); strcat($$,"+ ");  } 
        |   expr SUB expr               { $$ = (char *)malloc(50*sizeof(char)); strcpy($$,$1); strcat($$,$3); strcat($$,"- ");  }
        |   expr MUL expr               { $$ = (char *)malloc(50*sizeof(char)); strcpy($$,$1); strcat($$,$3); strcat($$,"* ");  }
        |   expr DIV expr               { $$ = (char *)malloc(50*sizeof(char)); strcpy($$,$1); strcat($$,$3); strcat($$,"/ ");  }
        |   LBRACKET expr RBRACKET      { $$ = (char *)malloc(50*sizeof(char)); strcpy($$,$2);                                  }
        |   DIGIT                       { $$ = (char *)malloc(50*sizeof(char)); strcpy($$,$1); strcat($$," ");                 }
        |   ID                          { $$ = (char *)malloc(50*sizeof(char)); strcpy($$,$1); strcat($$," ");                 }
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
        else if (t == '=')exit(0);//means 'quit'
        else if ((t >= '0' &&  t <= '9'))
        {
            int order=0;
            while((t >= '0' &&  t <= '9'))
            {
                number_buff[order]=t;
                t = getchar();
                order++;
            }
            number_buff[order]='\0';
            yylval=number_buff;
            ungetc(t,stdin);
            return DIGIT;
        }
        else if (( t >= 'a' && t <= 'z' )||( t >= 'A' && t <= 'Z' )||(t == '_'))
        {
            int order=0;
            while(( t >= 'a' && t <= 'z' )||( t >= 'A' && t <= 'Z' )||(t == '_')||(t >= '0' &&  t <= '9'))
            {
                id_buff[order]=t;
                order++;
                t = getchar();
            }
            id_buff[order]='\0';
            yylval=id_buff;
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