%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
int lineno=1;
%}

BLOCKCOMMENT \/\*([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*\*\/
LINECOMMENT \/\/[^\n]*
EOL	(\r\n|\r|\n)
WHITESPACE [[:blank:]]

INTEGER [0-9]+
CHAR \'.?\'
STRING \".+\"
BOOL [0|1]
IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*
%%

{BLOCKCOMMENT}  /* do nothing */
{LINECOMMENT}  /* do nothing */

"if" return IF;
"else" return ELSE;
"return" return RETURN;
"while" return WHILE ;
"for" return FOR ;
"printf"  return PRINTF;
"scanf"  return SCANF;

"{" return LBRACE;
"}" return RBRACE;

"(" return LPARE;
")" return RPARE;

"int" return T_INT;
"bool" return T_BOOL;
"char" return T_CHAR;
"string" return T_STRING;
"void"   return T_VOID;

"&&"  return AND;
"||"  return OR;
"!"  return NOT;


">"  return MORE;
"<"  return LESS;
">="  return MORE_EQ;
"<="  return LESS_EQ;
"!=" return NEQ;
"==" return EQ;

"=" return ASSIGN;

"+" return ADD;
"-" return MINUS;
"*" return MUL;
"/" return DIV;
"%" return MOD;
";" return SEMICOLON;
"," return COMMA; 
"&" return ADDR;
"++" return PLUS;
"--" return DESC;
{INTEGER} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    //change1
    const char*val=yytext;
    node->int_val = atoi(val);
    yylval = node;
    return INTEGER;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_CHAR;
    node->ch_val = yytext[1]; 
    yylval = node;
    return CHAR;
}
{STRING} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_STRING;
    const char*val=yytext;
    node->str_val=val;
    yylval = node;
    return STRING;
}
{BOOL} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_BOOL;
    const char*val=yytext;
    node->b_val=bool(atoi(val));
    yylval = node;
    return BOOL;
}
{IDENTIFIER} {
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->var_name = string(yytext);
    yylval = node;
    return IDENTIFIER;
}

{WHITESPACE} /* do nothing */

{EOL} lineno++;

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%