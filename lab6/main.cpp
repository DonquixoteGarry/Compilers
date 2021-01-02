#include"main.tab.hh"
#include"common.h"
#include<iostream>
using std::cout;
using std::endl;
TreeNode *root=nullptr;
vector<layer> layers;
vector<variable> work_layer;
roda_part ro_data;
func_part func_code(-1, "");
int layerid = 0;
int main ()
{
    yyparse();
    if(root){
        root->getNodeID();
        root->printAST();
    }
}
int yyerror(char const* message)
{
  cout << message << endl;
  return -1;
}