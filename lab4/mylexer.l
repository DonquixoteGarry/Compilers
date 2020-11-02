%option noyywrap
%top{
	#include <iostream>
	#include <fstream>
	#include <string.h>
	#include <iomanip>
	#include "idlist.h"
	#include "show.h"
	using namespace std;
}

%{
    idlist id_list;
%}


for			"for"
while		"while"
if			"if"
return		"return"
main		"main"
break		"break"
int			"int"
char		"char"
id			[A-Za-z_][A-Za-z0-9_]*
num			[0-9]+
add			"+"
sub			"-"
mul			"*"
div			"/"
mod			"%"
inc			"++"
dec			"--"
assign		"="
eq			"=="
noteq		"!="
geq			">="
leq			"<="
gt			\>
lt			\<
lbrace		\{
rbrace		\}
lbracket	\[
rbracket	\]
lpare		\(
rpare		\)
semi        \;
logicor     "|"
logicand    "&"
arithor     "||"
arithand    "&&"   
lineanno    \/\/[^\n]*
blockanno   \/\*(.|\n)*\*\/
backspace	[ ]
blank       [\t\n\f\v\r]
comma       ","

%%

{for}               {show("for",yytext);}
{while}             {show("while",yytext);}
{return}			{show("return",yytext);}
{if}                {show("if",yytext);}
{main}				{show("main",yytext);}
{break}             {show("break",yytext);}
{int}               {show("int",yytext);}
{char}              {show("char",yytext);}
{id}                {
                        //cout<<"OK"<<endl;
						if(id_list.in(string(yytext))==false)
                        {
							//cout<<"OK"<<endl;
                            id_list.append(string(yytext));
                        }
                        int idorder=id_list.search(string(yytext));
                        show("id",yytext,idorder);
                    }
{num}            	{show("num",yytext);}
{add}               {show("add",yytext);}
{sub}               {show("sub",yytext);}
{mul}               {show("mul",yytext);}
{div}               {show("div",yytext);}
{mod}               {show("mod",yytext);}
{inc}				{show("inc",yytext);}
{dec}				{show("dec",yytext);}
{assign}            {show("assign",yytext);}
{eq}                {show("eq",yytext);}
{noteq}             {show("noteq",yytext);}
{geq}               {show("geq",yytext);}
{leq}               {show("leq",yytext);}
{gt}                {show("gt",yytext);}
{lt}                {show("lt",yytext);}
{lbrace}            {show("lbrace",yytext);}
{rbrace}            {show("rbrace",yytext);}
{lbracket}          {show("lbracket",yytext);}
{rbracket}          {show("rbracket",yytext);}
{lpare}             {show("lpare",yytext);}
{rpare}             {show("rpare",yytext);}
{semi}				{show("semi",yytext);}
{logicor}           {show("logicor",yytext);}
{logicand}          {show("logicand",yytext);}
{arithor}           {show("arithor",yytext);}
{arithand}          {show("arithand",yytext);}
{lineanno}          {}
{blockanno}         {}
{space}				{}
{blank}             {}
{comma}             {show("comma",yytext);}               
            


%%

int main(void)
{
	yyFlexLexer lexer;
	cout<<left<<setw(15)<<"token"
        <<left<<setw(15)<<"lexeme"
        <<left<<setw(15)<<"value"
        <<std::endl
		<<std::endl;
	lexer.yylex();
	return 0;
}