%{
    #include "common.h"
    #define YYSTYPE TreeNode *  //此处定义了$$的类型
    TreeNode* root;
    extern int lineno;
    // extern vector<layer> layers;        //作用域
    // extern vector<variable> curlayer;   //当前作用域
    int yylex();
    int yyerror( char const * );
    
%}

%token T_CHAR T_INT T_STRING T_BOOL 
%token IDENTIFIER INTEGER CHAR BOOL STRING
%token ASSIGN 

%token SEMICOLON
%token ADD MINUS MUL DIV MOD PLUS DESC
%token ADDR COMMA ELSE FOR WHILE IF 
%token LBRACE RBRACE LPARE RPARE  
%token PRINTF SCANF RETURN
%token AND OR NOT 
%token EQ NEQ MORE_EQ LESS_EQ MORE LESS
//SELFADD SELFMIN NEG

%left EQ NEQ MORE_EQ LESS_EQ MORE LESS
%left ADD MINUS
%left MUL DIV


%%

program
:   statements {root = new TreeNode(0, NODE_PROG); root->addChild($1);}
;
statements
:   statement {$$=$1;}
|   statements statement {$$=$1;$$->addSibling($2);}
;

statement
:   SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;}//分号-STMT_SKIP
|   declaration SEMICOLON {$$ = $1;}
|   assign_stmt SEMICOLON {$$ = $1;}
|   if_stmt {$$ = $1;}
|   loop_stmt {$$ = $1;}
|   return_stmt SEMICOLON {$$ = $1;}
|   io_stmt SEMICOLON {$$ = $1;}
;

declaration
: T IDENTIFIER ASSIGN expr{  // declare and init
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_DECL;
        node->addChild($1);
        node->addChild($2);
        node->addChild($4);
        $$ = node;   
} 
| T IDENTIFIER_LIST {                // declare
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_DECL;
        node->addChild($1);
        node->addChild($2);
        $$ = node;   
}
;

assign_stmt 
:   IDENTIFIER ASSIGN expr {
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_ASSIGN;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   IDENTIFIER ADD ASSIGN expr {
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_ASSIGN;
        node->addChild($1);
        node->addChild($4);
        $$ = node;    
}
|   IDENTIFIER MINUS ASSIGN expr {
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_ASSIGN;
        node->addChild($1);
        node->addChild($4);
        $$ = node;    
}
|   IDENTIFIER MUL ASSIGN expr {
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_ASSIGN;
        node->addChild($1);
        node->addChild($4);
        $$ = node;    
}
|   IDENTIFIER DIV ASSIGN expr {
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_ASSIGN;
        node->addChild($1);
        node->addChild($4);
        $$ = node;    
}
;

if_stmt
:   IF expr statement {
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_IF;
        node->addChild($2);
        node->addChild($3);
        $$ = node;
}
|   IF expr LBRACE statements RBRACE{
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_IF;
        node->addChild($2);
        node->addChild($4);
        $$ = node;
}    
|   IF expr statement ELSE statement{
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_IF;
        node->addChild($2);
        node->addChild($3);
        node->addChild($5);
        $$ = node;
}
|   IF expr LBRACE statements RBRACE ELSE statement{
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_IF;
        node->addChild($2);
        node->addChild($4);
        node->addChild($7);
        $$ = node;
}
|   IF expr LBRACE statements RBRACE ELSE LBRACE statements RBRACE{
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_IF;
        node->addChild($2);
        node->addChild($4);
        node->addChild($8);
        $$ = node;
}
|   IF expr statement ELSE LBRACE statements RBRACE{
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_IF;
        node->addChild($2);
        node->addChild($3);
        node->addChild($6);
        $$ = node;
}
;

loop_stmt
:   WHILE expr statement {
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_LOOP;
        node->addChild($2);
        node->addChild($3);
        $$ = node;
}
|   WHILE expr LBRACE statements RBRACE {
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_LOOP;
        node->addChild($2);
        node->addChild($4);
        $$ = node;
}
|   FOR LPARE statement expr SEMICOLON expr RPARE statement{
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_LOOP;
        node->addChild($3);
        node->addChild($4);
        node->addChild($6);
        node->addChild($8);
        $$ = node;
}
|   FOR LPARE statement expr SEMICOLON expr RPARE LBRACE statements RBRACE{
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_LOOP;
        node->addChild($3);
        node->addChild($4);
        node->addChild($6);
        node->addChild($9);
        $$ = node;
}
;

return_stmt
:    RETURN expr {
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_RETURN;
        node->addChild($2);
        $$ = node;
}
;

io_stmt
:  PRINTF LPARE STRING COMMA IDENTIFIER_LIST RPARE{
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_PRINTF;
        node->addChild($3);
        node->addChild($5);
        $$ = node;
}
|  PRINTF LPARE IDENTIFIER_LIST RPARE{
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_PRINTF;
        node->addChild($3);
        $$ = node;
} 
|  SCANF LPARE STRING COMMA IDENTIFIER_LIST RPARE{
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_SCANF;
        node->addChild($3);
        node->addChild($5);
        $$ = node;
}
;

IDENTIFIER_LIST
:  IDENTIFIER_LIST COMMA IDENTIFIER {$$=$1;$$->addSibling($3);}
|  IDENTIFIER {$$=$1;}
|  IDENTIFIER_LIST COMMA ADDR IDENTIFIER {$$=$1;$$->addSibling($4);}
|  ADDR IDENTIFIER {$$=$2;}
;

expr
:   IDENTIFIER {
        $$ = $1;
}
|   INTEGER {
        $$ = $1;
}
|   CHAR {
        $$ = $1;
}
|   STRING {
        $$ = $1;
}
|   expr ADD expr{
        TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
        node->optype = OP_ADD;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   expr MINUS expr{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_MINUS;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   expr MUL expr{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_MUL;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   expr DIV expr{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_DIV;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   expr MOD expr{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_MOD;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   expr EQ expr{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_COMP;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   expr NEQ expr{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_COMP;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   expr OR expr{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_OR;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   expr AND expr{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_AND;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   expr LESS expr{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_COMP;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   expr MORE expr{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_COMP;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   expr LESS_EQ expr{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_COMP;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   expr MORE_EQ expr{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_COMP;
        node->addChild($1);
        node->addChild($3);
        $$ = node;
}
|   LPARE expr RPARE{
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_NONE;
        node->addChild($2);
        $$ = node;
}
|   ADD expr {
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_ADD;
        node->addChild($2);
        $$ = node;
}
|   MINUS expr {
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_MINUS;
        node->addChild($2);
        $$ = node;
}
|   ADDR expr {
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_ADDR;
        node->addChild($2);
        $$ = node;
}
|   NOT expr {
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_NOT;
        node->addChild($2);
        $$ = node;
}
|   expr PLUS {
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_PLUS;
        node->addChild($1);
        $$ = node;
}
|   expr DESC {
        TreeNode*node = new TreeNode($1->lineno,NODE_EXPR);
        node->optype = OP_DESC;
        node->addChild($1);
        $$ = node;
}
;

T
:   T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;} 
|   T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
|   T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;}
|   T_STRING {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_STRING;}
;

%%


int yyerror(char const* message)
{

  cout << message << " at line " << lineno << endl;
  return -1;
}