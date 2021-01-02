#include"main.tab.hh"
#include"common.h"
#include<iostream>
using std::cout;
using std::endl;
TreeNode *root=nullptr;
vector<layer> layers;
vector<var> work_layer;
rodata_part rodata_code;
func_part func_code(-1, "");
int layerid = 0;
int main ()
{
    yyparse();
    if(root)
    {
        root->getNodeID();
        root->printAST();
    }
}
int yyerror(char const* message)
{
  cout << message << endl;
  return -1;
}