#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"tree.h"
using namespace std;
class rodata
{
public:
    vector<string> _rodata;
    void output();
    void push_back(string str);
    int size();
};

class function
{
public:
    int funcType;
    bool buf;
    vector<string> code;
    vector<string> codebuf;
    string name;
    int ret;
    function(int _funcType, string _name);
    void set(int _funcType, string _name);
    void output();
    void addCode(string _code);
    string delCode();
    void resetCode(string _code);
    void ASM_Expr_erg(TreeNode *node);
    void ASM_Expr(TreeNode* node);
};