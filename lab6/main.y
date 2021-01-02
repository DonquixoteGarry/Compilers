%{
    #include"common.h"
    #include<string>
    #include<queue>
    extern TreeNode * root;
    int yylex();
    int yyerror( char const * );

    extern vector<layer> layers;
    extern vector<var> work_layer;
    extern int layerid;
    extern rodata_part rodata_code;
    extern func_part func_code;
    
    int temp_dec_size = 1;
    vector<string> while_stmt_code,for_stmt_code;
    
    bool declear_flag = 0,scan_flag = 0,while_flag = 0;
    bool for_flag = 0,for_flag_expr3 = 0;
    
    int curlabel;
    vector<int> label;
    int if_lev = 0;
    int whilectr = 0;
    int forctr = 0;
    int if_asm_order = 0; //if汇编语句块编号
    vector<temp_var> for_temp_varlist;
    int for_stmt_level = 0;
%}
%defines

%start program

%token ID addr_id content_id INTEGER CHARACTER STRING
%token IF ELSE WHILE FOR RETURN
%token CONST
%token INT VOID CHAR STR
%token SLB SRB MLB MRB LLB LRB COMMA SEMICOLON
%token TRUE FALSE
%token ADD SUB MUL DIV MOD ANSC DESC NEG POS
%token ASSIGN ADD_ASS SUB_ASS MUL_ASS DIV_ASS MOD_ASS
%token EQ NEQ GT GE LT LE NOT AND OR
%token PRINTF SCANF
%token dot

%right ASSIGN ADD_ASS SUB_ASS MUL_ASS DIV_ASS MOD_ASS
%right ANSC DESC
%right OR
%left ADD SUB
%left MUL DIV MOD
%left EQ NEQ GT GE LT LE
%right AND
%right NOT
%right NEG 
%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE 
%%
program: statements
     {
        root=new TreeNode(NODE_PROG);
        root->addChild($1);
        printf("\n\t.text\n\t.section\t.rodata\n");
        rodata_code.output();
        func_code.output();
        printf("\t.section\t.note.GNU-stack,\"\",@progbits\n\n");
    }
    ;

statements: statement
     {$$=$1;}
    | statements statement{$$=$1;$$->addSibling($2);}
    ;

statement: instruction 
    {$$=$1;}
    | if_else {$$=$1;}
    | while {$$=$1;}
    | for {$$=$1;}
    | LLB statements LRB {
        $$=$2;    
        vector<var> var = layers[layers.size()-1].var_list;
        while(work_layer.size()!=var.size())
        {
            if(work_layer[work_layer.size()-1].type != 4) func_code.addCode("\taddl\t$4, %esp\n");
            work_layer.pop_back();
        }
        layers.pop_back();
        layerid--;
    }
    | funcs {$$=$1;}
    | printf SEMICOLON {$$=$1;}
    | scanf SEMICOLON {$$=$1;}
    | return_stmt
    ;

assign: _ID ASSIGN expr
    {
        string offset;
        TreeNode* node=new TreeNode(NODE_ASSIGN);
        node->addChild($1);
        node->addChild($3);
        if($1->varType != -1 && $1->varType != $3->varType)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if($3->varType == VAR_STR)
            goto STREND;
        if($1->int_val == -1)
        {
            offset = to_string(-(4*(temp_dec_size)));
            temp_dec_size++;
        }
        else
            offset = to_string(-(4*$1->int_val));
        func_code.addCode("\tpopl\t%eax\n");
        func_code.addCode("\tmovl\t%eax, " + offset + "(%ebp)\n");
        if(for_flag){func_code.addCode("FBG"+to_string(forctr)+":\n");}
        if(declear_flag) func_code.addCode("\tsubl\t$4, %esp\n");
       
    STREND:
        $$=node;
    }
    | _ID ADD_ASS expr{
        TreeNode* node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_ADD;
        node->addChild($1);
        node->addChild($3);
        if($1->varType != -1 && $1->varType != $3->varType)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\taddl\t%ebx,-"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\taddl\t%ebx,-"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
        $$=node;
    }
    | _ID SUB_ASS expr{
        TreeNode* node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_MINUS;
        node->addChild($1);
        node->addChild($3);
        if($1->varType != -1 && $1->varType != $3->varType)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tsubl\t%ebx,-"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
        else{
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tsubl\t%ebx,-"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
        $$=node;
        
    }
    | _ID MUL_ASS expr{
        TreeNode* node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_MULTI;
        node->addChild($1);
        node->addChild($3);
        if($1->varType != -1 && !($1->varType == $3->varType == VAR_INTEGER))
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tmovl\t-" + to_string(4*$1->int_val) + "(%ebp), %eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tmovl\t%eax, -"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
        else{
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tmovl\t-" + to_string(4*$1->int_val) + "(%ebp), %eax\n");
            func_code.addCode("\timull\t%ebx\n");
            func_code.addCode("\tmovl\t%eax, -"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
        $$=node;
    }
    | _ID DIV_ASS expr{
        TreeNode* node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_DIV;
        node->addChild($1);
        node->addChild($3);
        if($1->varType != -1 && !($1->varType == $3->varType == VAR_INTEGER))
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tmovl\t-" + to_string(4*$1->int_val) + "(%ebp), %eax\n");
            for_stmt_code.emplace_back("\tcltd\n");
            for_stmt_code.emplace_back("\tidivl\t%ebx\n");
            for_stmt_code.emplace_back("\tmovl\t%eax, -"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
        else{
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tmovl\t-" + to_string(4*$1->int_val) + "(%ebp), %eax\n");
            func_code.addCode("\tcltd\n");
            func_code.addCode("\tidivl\t%ebx\n");
            func_code.addCode("\tmovl\t%eax, -"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
        $$=node;
    }
    | _ID MOD_ASS expr{
        TreeNode* node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_MOD;
        node->addChild($1);
        node->addChild($3);
        if($1->varType != -1 && $1->varType != $3->varType)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tmovl\t-" + to_string(4*$1->int_val) + "(%ebp), %eax\n");
            for_stmt_code.emplace_back("\tcltd\n");
            for_stmt_code.emplace_back("\tidivl\t%ebx\n");
            for_stmt_code.emplace_back("\tmovl\t%edx, -"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
        else{
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tmovl\t-" + to_string(4*$1->int_val) + "(%ebp), %eax\n");
            func_code.addCode("\tcltd\n");
            func_code.addCode("\tidivl\t%ebx\n");
            func_code.addCode("\tmovl\t%edx, -"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
        $$=node;
    }
    | _ID ANSC {
        TreeNode *node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_SADD;
        node->addChild($1);
        $$=node; 
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\taddl\t$1,-"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
        else{
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\taddl\t$1,-"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
    }
    | _ID DESC {
        TreeNode *node=new TreeNode(NODE_ASSIGN);
        node->opType=OP_SMIN;
        node->addChild($1);
        $$=node; 
        if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tsubl\t$1,-"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tsubl\t$1,-"+to_string(4*$1->int_val)+"(%ebp)\n");
        }
    }
    ;
params: _ID 
    {
        $$=$1; 
        string index;
        if($1->int_val == -1)
            index = to_string(4*(temp_dec_size++));
        else
            index = to_string(4*$1->int_val);
        func_code.addCode("\tmovl\t$0, -"+index+"(%ebp)\n"); 
        if(for_flag){func_code.addCode("FBG"+to_string(forctr)+":\n");}
        if(declear_flag) func_code.addCode("\tsubl\t$4, %esp\n");
        
        
    }
    | assign {$$=$1;}
    | params COMMA _ID {
        $$=$1;
        $$->addSibling($3);
        string index;
        if($1->int_val == -1)
            index = to_string(4*(temp_dec_size++));
        else
            index = to_string(4*$3->int_val);
        func_code.addCode("\tmovl\t$0, -"+index+"(%ebp)\n"); 
        if(for_flag){func_code.addCode("FBG"+to_string(forctr)+":\n");}
        if(declear_flag) func_code.addCode("\tsubl\t$4, %esp\n");
        
    }
    | params COMMA assign {$$=$1; $$->addSibling($3);}
    ;
args: expr
     {$$=$1;}
    | addr_id {$$=$1;}
    | content_id {$$=$1;}
    | args COMMA expr {$$=$1; $$->addSibling($3);}
    | args COMMA addr_id {$$=$1; $$->addSibling($3);}
    | args COMMA content_id {$$=$1; $$->addSibling($3);}
    ;
funcs: type ID SLB args SRB statement
     {
        TreeNode *node=new TreeNode(NODE_FUNC);
        node->addChild($1);
        node->addChild($2);
        node->addChild($4);
        node->addChild($6);
        $$=node;
    }
    | type ID SLB SRB statement {
        TreeNode *node=new TreeNode(NODE_FUNC);
        node->addChild($1);
        node->addChild($2);
        node->addChild($5);
        func_code.set($1->varType, $2->varName);
        $$=node;
    }
    ;
_else: ELSE
    {
        curlabel = label[if_lev-1];
        string lb1 = "IEL" + to_string(curlabel) + to_string(if_lev - 1);
        string lb2 = "IEL" + to_string(curlabel-1) + to_string(if_lev - 1);
        func_code.addCode("\tjmp\t" + lb1 + "\n");
        func_code.addCode(lb2 + ":\n");
        label.emplace_back(curlabel);
        curlabel = 0;
    }
    ;
if_condi: IF bool_statment
    {
        func_code.addCode("\tpopl\t%eax\n");
        func_code.addCode("\tcmp\t$1, %eax\n");
        string lb = "IEL" + to_string(curlabel++) + to_string(if_lev++);
        func_code.addCode("\tjne\t"+lb+"\n");
        label.emplace_back(curlabel);
        curlabel = 0;
        $$=$2;
    }
    ;
if_else: if_condi statement %prec LOWER_THEN_ELSE
     {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_IF;
        node->addChild($1);
        node->addChild($2);
        curlabel = label[if_lev-1];
        string lb = "IEL" + to_string(curlabel-1) + to_string(--if_lev);
        func_code.addCode(lb + ":\n");
        label.pop_back();
        $$=node;
    }
    | if_condi statement _else statement {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_IF;
        node->addChild($1);
        node->addChild($2);
        node->addChild($4);
        curlabel = label[if_lev-1];
        string lb = "IEL" + to_string(curlabel) + to_string(--if_lev);
        func_code.addCode(lb + ":\n");
        label.pop_back();
        $$=node;
    }

    ;
_while: WHILE 
    {
        while_flag = 1;
    }
    ;
while_condi: _while bool_statment 
    {
        TreeNode *node=new TreeNode(NODE_WEXPR);
        node->int_val=whilectr;
        node->addChild($2);
        func_code.addCode("WBG"+to_string(whilectr)+":\n");
        for(int i = 0;i < while_stmt_code.size();i++)
        {
            func_code.addCode(while_stmt_code[i]);
        }
        while_stmt_code.clear();
        func_code.addCode("\tpopl\t%eax\n");
        func_code.addCode("\tcmpl\t$1, %eax\n");
        func_code.addCode("\tjne\tWED"+to_string(whilectr++)+"\n");
        while_flag = 0;
        $$=node;
    }
    ;
while: while_condi statement 
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_WHILE;
        node->addChild($1);
        node->addChild($2);
        func_code.addCode("\tjmp\tWBG"+to_string($1->int_val)+"\n");
        func_code.addCode("WED"+to_string($1->int_val)+":\n");
        $$=node;
    }
    ;
for: _for for_condi statement
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_FOR;
        node->addChild($2);
        node->addChild($3);
        $$=node;
        while(for_temp_varlist[for_temp_varlist.size()-1].l == for_stmt_level)
        {
            work_layer.pop_back();
            for_temp_varlist.pop_back();
        }
        for_stmt_level--;

        for(int i = 0;i < for_stmt_code.size();i++)
        {
            func_code.addCode(for_stmt_code[i]);
        }
        for_stmt_code.clear();
        func_code.addCode("\tjmp\tFBG"+to_string($2->getChild(0)->int_val)+"\n");
        func_code.addCode("FED"+to_string($2->getChild(0)->int_val)+":\n");
    
    }
    ;
_for: FOR
    {
        $$=$1;
        for_flag = 1;
        for_flag_expr3 = 0;
    }
    ;
for_condi: for_expr12 for_expr3
    {
        TreeNode *node=new TreeNode(NODE_FEXPR);
        node->int_val = forctr;
        node->addChild($1);
        node->addChild($2);
        $$ = node;
    } 
    ;
for_expr12: SLB instruction bool_expr SEMICOLON
    {
        TreeNode *node=new TreeNode(NODE_FEXPR);
        node->int_val = forctr;
        node->addChild($2);
        node->addChild($3);
        for(int i = 0;i < for_stmt_code.size();i++)
        {
            func_code.addCode(for_stmt_code[i]);
        }
        for_stmt_code.clear();
        func_code.addCode("\tpopl\t%eax\n");
        func_code.addCode("\tcmpl\t$1, %eax\n");
        func_code.addCode("\tjne\tFED"+to_string(forctr)+"\n");
        for_flag_expr3 = 1;
        $$=node;
    }
    ;
for_expr3: assign SRB
    {
        TreeNode *node=new TreeNode(NODE_FEXPR);
        node->int_val = forctr++;
        node->addChild($1);
        for_flag_expr3 = 0;
        $$ = node;
        for_stmt_level++;
    }
    ;    
return_stmt: RETURN expr SEMICOLON{
        if(while_flag)
        {
            for(int i=0;i<work_layer.size();i++)
            {
                while_stmt_code.emplace_back("\taddl\t$4,%esp\n");
            }
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebp\n");
            while_stmt_code.emplace_back("\tret\n");
        }
        else if(for_flag)
        {
            for(int i=0;i<work_layer.size();i++)
            {
                for_stmt_code.emplace_back("\taddl\t$4,%esp\n");
            }
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebp\n");
            for_stmt_code.emplace_back("\tret\n");
        }
        else
        {
            for(int i=0;i<work_layer.size();i++)
            {
                func_code.addCode("\taddl\t$4,%esp\n");
            }
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebp\n");
            func_code.addCode("\tret\n");
        }
        
    }
    ;
bool_statment: SLB bool_expr SRB
    {$$=$2;}
    | SLB expr SRB{
        func_code.addCode("\tpopl\t%eax\n");
        func_code.addCode("\tmovl\t$0, %ebx\n");
        func_code.addCode("\tcmpl\t%ebx, %eax\n");
        func_code.addCode("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
        func_code.addCode("\tpushl\t$0\n");
        func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
        func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
        func_code.addCode("\tpushl\t$1\n");
        func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        $$ = $2;
    }
    ;
instruction: type params SEMICOLON 
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_DECL;
        node->addChild($1);
        node->addChild($2);
        int vtype = $1->varType;
        $$=node;
        int praseErr_flag = 0;
        vector<var> temp;
        if(!layers.empty())
        {
            temp = layers[layers.size()-1].var_list;
        }
        for(int i = 1;i < node->childNum();i++)
        {
            TreeNode* child = node->getChild(i);
            if(child->childNum() != 0 && child->getChild(1)->varType != vtype)
            {
                printf("Error : type invalid\n");
                exit(1);
            }
            for(int j = temp.size();j < work_layer.size();j++)
            {
                if(work_layer[j].name == (child->nodeType==NODE_ASSIGN?child->getChild(0)->varName:child->varName))
                {
                    printf("Error : var wrong\n");
                    layer(work_layer, layerid).output();
                    praseErr_flag = 1;
                    break;
                }
            }
            if(!praseErr_flag)
            {
                if(vtype == VAR_STR)
                {
                    if(child->childNum() == 0)
                    {
                        printf("Error : string wrong\n");
                        exit(1);
                    }
                    work_layer.emplace_back(var(child->getChild(0)->varName, rodata_code.size()));
                    rodata_code.emplace_back(child->getChild(1)->str_val);
                    if(for_flag) for_temp_varlist.emplace_back(temp_var(var(child->getChild(0)->varName, rodata_code.size()), for_stmt_level));
                    goto EA;
                }
                work_layer.emplace_back(var($1->varType, child->nodeType==NODE_ASSIGN?child->getChild(0)->varName:child->varName));
                if(for_flag) for_temp_varlist.emplace_back(temp_var(var($1->varType, child->nodeType==NODE_ASSIGN?child->getChild(0)->varName:child->varName), for_stmt_level));
            }
            EA:
                praseErr_flag = 0;
        }
        declear_flag = 0;
        for_flag = 0;
        temp_dec_size = work_layer.size() + 1;
    }
    | params SEMICOLON {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_ASSIGN;
        node->addChild($1);
        for(int i = 0;i < node->childNum();i++)
        {
            TreeNode* child = node->getChild(i);
            if(child->getChild(0)->varType != child->getChild(1)->varType)
            {
                printf("Error : type invalid\n");
                exit(1);
            }
        }
        $$=node;  
    }
    | CONST type params SEMICOLON {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_DECL;
        node->addChild($2);
        node->addChild($3);
        $$=node;
        int praseErr_flag = 0;
        vector<var> temp;
        if(!layers.empty())
        {
            temp = layers[layers.size()-1].var_list;
        }
        for(int i = 1;i < node->childNum();i++)
        {
            TreeNode* child = node->getChild(i);
            for(int j = temp.size();j < work_layer.size();j++)
            {
                if(work_layer[j].name == (child->nodeType==NODE_ASSIGN?child->getChild(0)->varName:child->varName))
                {
                    printf("Error : var wrong\n");
                    layer(work_layer, layerid).output();
                    praseErr_flag = 1;
                    break;
                }
            }
            if(!praseErr_flag)
            {
                work_layer.emplace_back(var($1->varType, child->nodeType==NODE_ASSIGN?child->getChild(0)->varName:child->varName));
                if(for_flag) for_temp_varlist.emplace_back(temp_var(var($1->varType, child->nodeType==NODE_ASSIGN?child->getChild(0)->varName:child->varName), for_stmt_level));
            }
            praseErr_flag = 0;
        }
        for_flag = 0;
        
    }
    ;
printf: PRINTF SLB STRING COMMA args SRB 
    {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_PRINTF;
        node->addChild($3);
        node->addChild($5);
        rodata_code.emplace_back($3->str_val);
        vector<int> q;
        string str = $3->str_val;
        for(int i = 0;i < str.length();i++)
        {
            if(str[i] == '%')
            {
                if(i+1 == str.length())
                {
                    printf("Error : control flag invalid\n");
                    exit(1);
                }
                switch(str[i+1])
                {
                    case 'd':
                        q.emplace_back(VAR_INTEGER);
                        break;
                    case 'c':
                        q.emplace_back(VAR_CHAR);
                        break;
                    case 's':
                        q.emplace_back(VAR_STR);
                        break;
                    default:
                        printf("Error : control flag invalid.\n");
                        exit(1);
                }
            }
        }
        if(q.size()+1 != node->childNum())
        {
            printf("Error : param invalid\n");
            exit(1);
        }
        vector<string> tmpv;
        for(int i = 0;i < q.size();i++)
        {
            TreeNode* child = node->getChild(i+1);
            if(q[i] != child->varType)
            {
                printf("Error : type invalid\n");
                exit(1);
            }
            tmpv.emplace_back(func_code.delCode());
        }
        for(int i = 0;i < tmpv.size();i++)
        {
            func_code.addCode(tmpv[i]);
        }
        func_code.addCode("\tsubl\t$"+to_string(work_layer.size()*4)+", %ebp\n");
        func_code.addCode("\tpushl\t$STR"+to_string(rodata_code.size()-1)+"\n");
        func_code.addCode("\tcall\tprintf\n");
        func_code.addCode("\taddl\t$"+to_string(work_layer.size()*4)+", %ebp\n");
        func_code.addCode("\taddl\t$"+to_string(q.size()*4+4)+", %esp\n");
        $$=node;
    }
    | PRINTF SLB STRING SRB{
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_PRINTF;
        node->addChild($3);
        rodata_code.emplace_back($3->str_val);
        func_code.addCode("\tsubl\t$"+to_string(work_layer.size()*4)+", %ebp\n");
        func_code.addCode("\tpushl\t$STR"+to_string(rodata_code.size()-1)+"\n");
        func_code.addCode("\tcall\tprintf\n");
        func_code.addCode("\taddl\t$"+to_string(work_layer.size()*4)+", %ebp\n");
        func_code.addCode("\taddl\t$4, %esp\n");
        $$=node;
    }
    ;
_SCANF: SCANF
    {
        scan_flag = 1;
    }
    ;
scanf: _SCANF SLB STRING COMMA args SRB
     {
        TreeNode *node=new TreeNode(NODE_STMT);
        node->stmtType=STMT_SCANF;
        node->addChild($3);
        node->addChild($5);
        rodata_code.emplace_back($3->str_val);
        vector<int> q;
        string str = $3->str_val;
        for(int i = 0;i < str.length();i++)
        {
            if(str[i] == '%')
            {
                if(i+1 == str.length())
                {
                    printf("Error : control flag invalid\n");
                    exit(1);
                }
                switch(str[i+1])
                {
                    case 'd':
                        q.emplace_back(VAR_INTEGER);
                        break;
                    case 'c':
                        q.emplace_back(VAR_CHAR);
                        break;
                    case 's':
                        q.emplace_back(VAR_STR);
                        break;
                    default:
                        printf("Error : control flag invalid.\n");
                        exit(1);
                }
            }
        }
        if(q.size()+1 != node->childNum())
        {
            printf("Error : param invalid\n");
            exit(1);
        }
        vector<string> tmpv;
        for(int i = 0;i < q.size();i++)
        {
            TreeNode* child = node->getChild(i+1);
            if(q[i] != child->varType)
            {
                printf("Error : type invalid\n");
                exit(1);
            }
            tmpv.emplace_back(func_code.delCode());
        }
        for(int i = 0;i < tmpv.size();i++)
        {
            string str = tmpv[i].substr(7);
            str = "\tleal\t" + str.substr(0, str.find("\n")) + ", %eax\n";
            func_code.addCode(str);
            func_code.addCode("\tpushl\t%eax\n");
        }
        func_code.addCode("\tsubl\t$"+to_string(work_layer.size()*4)+", %ebp\n");
        func_code.addCode("\tpushl\t$STR"+to_string(rodata_code.size()-1)+"\n");
        func_code.addCode("\tcall\tscanf\n");
        func_code.addCode("\taddl\t$"+to_string(work_layer.size()*4)+", %ebp\n");
        func_code.addCode("\taddl\t$"+to_string(q.size()*4+4)+", %esp\n");
        $$=node;
        scan_flag = 0;
    }
    ;
bool_expr: TRUE
     {
        $$=$1; 
        $$->varType = VAR_BOOLEAN; 
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpushl\t$1\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpushl\t$1\n");
        }
        else
        {
            func_code.addCode("\tpushl\t$1\n");
        }
    }
    | FALSE {
        $$=$1; 
        $$->varType = VAR_BOOLEAN; 
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpushl\t$0\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpushl\t$0\n");
        }
        else
        {
            func_code.addCode("\tpushl\t$0\n");
        }
    }
    | expr EQ expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_EQ;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_BOOLEAN;
        if($1->varType != $3->varType)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tcmpl\t%eax, %ebx\n");
            func_code.addCode("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        $$=node;
    }
    | expr NEQ expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_NE;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_BOOLEAN;
        if($1->varType != $3->varType)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tje\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tje\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tcmpl\t%eax, %ebx\n");
            func_code.addCode("\tje\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        $$=node;
    }
    | expr GT expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_GT;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_BOOLEAN;
        if($1->varType != VAR_INTEGER || $3->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        $$=node;
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tjle\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tjle\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tcmpl\t%eax, %ebx\n");
            func_code.addCode("\tjle\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
    }
    | expr GE expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_GE;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_BOOLEAN;
        if($1->varType != VAR_INTEGER || $3->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        $$=node;
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tjl\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tjl\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tcmpl\t%eax, %ebx\n");
            func_code.addCode("\tjl\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
    }
    | expr LT expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_LT;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_BOOLEAN;
        if($1->varType != VAR_INTEGER || $3->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tjge\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tjge\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tcmpl\t%eax, %ebx\n");
            func_code.addCode("\tjge\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        $$=node;
    }
    | expr LE expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_LE;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_BOOLEAN;
        if($1->varType != VAR_INTEGER || $3->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tjg\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tcmpl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tjg\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tcmpl\t%eax, %ebx\n");
            func_code.addCode("\tjg\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        $$=node;
    }
    | bool_expr AND bool_expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_AND;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_BOOLEAN;
        if($1->varType != VAR_BOOLEAN || $3->varType != VAR_BOOLEAN)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\taddl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tmovl\t$2, %eax\n");
            while_stmt_code.emplace_back("\tcmpl\t%ebx, %eax\n");
            while_stmt_code.emplace_back("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\taddl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tmovl\t$2, %eax\n");
            for_stmt_code.emplace_back("\tcmpl\t%ebx, %eax\n");
            for_stmt_code.emplace_back("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\taddl\t%eax, %ebx\n");
            func_code.addCode("\tmovl\t$2, %eax\n");
            func_code.addCode("\tcmpl\t%ebx, %eax\n");
            func_code.addCode("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        $$=node;
    }
    | bool_expr OR bool_expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_OR;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_BOOLEAN;
        if($1->varType != VAR_BOOLEAN || $3->varType != VAR_BOOLEAN)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\taddl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tmovl\t$0, %eax\n");
            while_stmt_code.emplace_back("\tcmpl\t%ebx, %eax\n");
            while_stmt_code.emplace_back("\tje\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("\tpushl\t$1\n");
            while_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            while_stmt_code.emplace_back("\tpushl\t$0\n");
            while_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
         else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\taddl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tmovl\t$0, %eax\n");
            for_stmt_code.emplace_back("\tcmpl\t%ebx, %eax\n");
            for_stmt_code.emplace_back("\tjne\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("\tpushl\t$1\n");
            for_stmt_code.emplace_back("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-2) + ":\n");
            for_stmt_code.emplace_back("\tpushl\t$0\n");
            for_stmt_code.emplace_back("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\taddl\t%eax, %ebx\n");
            func_code.addCode("\tmovl\t$0, %eax\n");
            func_code.addCode("\tcmpl\t%ebx, %eax\n");
            func_code.addCode("\tje\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("\tpushl\t$1\n");
            func_code.addCode("\tjmp\tIFL" + to_string(if_asm_order++) + "\n");
            func_code.addCode("IFL" + to_string(if_asm_order-2) + ":\n");
            func_code.addCode("\tpushl\t$0\n");
            func_code.addCode("IFL" + to_string(if_asm_order-1) + ":\n");
        }
        $$=node;
    }
    | NOT bool_expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_NOT;
        node->addChild($2);
        node->varType=VAR_BOOLEAN;
        if($2->varType != VAR_BOOLEAN)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tsubl\t$1, %eax\n");
            while_stmt_code.emplace_back("\tpushl\t%eax\n");
        }
         else if(for_flag)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tsubl\t$1, %eax\n");
            for_stmt_code.emplace_back("\tpushl\t%eax\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tsubl\t$1, %eax\n");
            func_code.addCode("\tpushl\t%eax\n");
        }
        $$=node;        
    }
    ;
expr: _ID 
    {
        $$=$1;
        vector<var>::reverse_iterator curr_var = work_layer.rbegin();
        int i = 0;
        while(curr_var != work_layer.rend())
        {
            if((*curr_var).name == $$->varName)
            {
                string code = "\tpushl\t";
                if($$->varType == VAR_STR)
                    code += "$STR" + to_string($$->int_val) + "\n";
                else
                    code += "-" + to_string(4*(work_layer.size()-i)) + "(%ebp)\n";
                if(while_flag)
                {
                    while_stmt_code.emplace_back(code);
                }
                else if(for_flag_expr3)
                {
                    for_stmt_code.emplace_back(code);
                }
                else
                {
                    func_code.addCode(code);
                }
                break;
            }
            curr_var++;
            i++;
        }
    }
    | INTEGER {
        $$=$1;
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpushl\t$" + to_string($$->int_val) + "\n");
        }
        else if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpushl\t$" + to_string($$->int_val) + "\n");
        }
        else
        {
            func_code.addCode("\tpushl\t$" + to_string($$->int_val) + "\n");
        }
    }
    | CHARACTER {$$=$1;}
    | STRING {$$=$1;}
    | expr ADD expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_ADD;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_INTEGER;
        if($1->varType != VAR_INTEGER || $3->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\taddl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tpushl\t%ebx\n");
        }
        else if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\taddl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tpushl\t%ebx\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\taddl\t%eax, %ebx\n");
            func_code.addCode("\tpushl\t%ebx\n");
        }
        $$=node;   
    }
    | expr SUB expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_MINUS;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_INTEGER;
        if($1->varType != VAR_INTEGER || $3->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tsubl\t%eax, %ebx\n");
            while_stmt_code.emplace_back("\tpushl\t%ebx\n");
        }
        else if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tsubl\t%eax, %ebx\n");
            for_stmt_code.emplace_back("\tpushl\t%ebx\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tsubl\t%eax, %ebx\n");
            func_code.addCode("\tpushl\t%ebx\n");
        }
        $$=node;   
    }
    | expr MUL expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_MULTI;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_INTEGER;
        if($1->varType != VAR_INTEGER || $3->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\timull\t%ebx\n");
            while_stmt_code.emplace_back("\tpushl\t%eax\n");
        }
        else if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\timull\t%ebx\n");
            for_stmt_code.emplace_back("\tpushl\t%eax\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\timull\t%ebx\n");
            func_code.addCode("\tpushl\t%eax\n");
        }
        $$=node;   
    }
    | expr DIV expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_DIV;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_INTEGER;
        if($1->varType != VAR_INTEGER || $3->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tcltd\n");
            while_stmt_code.emplace_back("\tidivl\t%ebx\n");
            while_stmt_code.emplace_back("\tpushl\t%eax\n");
        }
        else if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tcltd\n");
            for_stmt_code.emplace_back("\tidivl\t%ebx\n");
            for_stmt_code.emplace_back("\tpushl\t%eax\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tcltd\n");
            func_code.addCode("\tidivl\t%ebx\n");
            func_code.addCode("\tpushl\t%eax\n");
        }
        
        $$=node;   
    }
    | expr MOD expr {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_MOD;
        node->addChild($1);
        node->addChild($3);
        node->varType=VAR_INTEGER;
        if($1->varType != VAR_INTEGER || $3->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        if(while_flag)
        {
            while_stmt_code.emplace_back("\tpopl\t%ebx\n");
            while_stmt_code.emplace_back("\tpopl\t%eax\n");
            while_stmt_code.emplace_back("\tcltd\n");
            while_stmt_code.emplace_back("\tidivl\t%ebx\n");
            while_stmt_code.emplace_back("\tpushl\t%edx\n");
        }
        else if(for_flag_expr3)
        {
            for_stmt_code.emplace_back("\tpopl\t%ebx\n");
            for_stmt_code.emplace_back("\tpopl\t%eax\n");
            for_stmt_code.emplace_back("\tcltd\n");
            for_stmt_code.emplace_back("\tidivl\t%ebx\n");
            for_stmt_code.emplace_back("\tpushl\t%edx\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tpopl\t%eax\n");
            func_code.addCode("\tcltd\n");
            func_code.addCode("\tidivl\t%ebx\n");
            func_code.addCode("\tpushl\t%edx\n");
        }
        $$=node;   
    }
    | SUB expr %prec NEG {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_NEG;
        node->addChild($2);
        node->varType=VAR_INTEGER;
        if($2->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        TreeNode* child = node->getChild(0);
        if(child->varName == "#")
        {
            func_code.resetCode("\tpushl\t$-" + to_string(child->int_val) + "\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tmovl\t$-1, %eax\n");
            func_code.addCode("\timull\t%ebx\n");
            func_code.addCode("\tpushl\t%eax\n");
        }
        $$=node; 
    }
    | ADD expr %prec POS
    {
        TreeNode *node=new TreeNode(NODE_OP);
        node->opType=OP_POS;
        node->addChild($2);
        node->varType=VAR_INTEGER;
        if($2->varType != VAR_INTEGER)
        {
            printf("Error : type invalid\n");
            exit(1);
        }
        TreeNode* child = node->getChild(0);
        if(child->varName == "#")
        {
            func_code.resetCode("\tpushl\t$" + to_string(child->int_val) + "\n");
        }
        else
        {
            func_code.addCode("\tpopl\t%ebx\n");
            func_code.addCode("\tmovl\t$1, %eax\n");
            func_code.addCode("\timull\t%ebx\n");
            func_code.addCode("\tpushl\t%eax\n");
        }
        $$=node; 
    }
    ;
type: INT 
    {
        TreeNode *node=new TreeNode(NODE_TYPE);
        node->varType=VAR_INTEGER;
        declear_flag = 1;
        $$=node; 
    }
    | VOID {
        TreeNode *node=new TreeNode(NODE_TYPE);
        node->varType=VAR_VOID;
        declear_flag = 1;
        $$=node;         
    }
    | CHAR {
        TreeNode *node=new TreeNode(NODE_TYPE);
        node->varType=VAR_CHAR;
        declear_flag = 1;
        $$=node;
    }
    | STR {
        TreeNode *node=new TreeNode(NODE_TYPE);
        node->varType=VAR_STR;
        declear_flag = 1;
        $$=node;
    }
    ;

_ID: ID 
    {
        $$=$1;
        if($$->int_val == -1)
        {
            vector<var>::reverse_iterator curr_var = work_layer.rbegin();
            int i = 0;
            while(curr_var != work_layer.rend())
            {
                if((*curr_var).name == $$->varName)
                {
                    break;
                }
                curr_var++;
                i++;
            }
            if(!declear_flag) $$->int_val = work_layer.size() - i;
            if($$->varType == VAR_STR) $$->int_val = (*curr_var).ro_index;
        }
    }
    ;
%%
