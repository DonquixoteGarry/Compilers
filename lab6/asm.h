#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"tree.h"
using namespace std;

class roda_part
{
public:
    vector<string> ro_data;
    void output();
    void emplace_back(string str);
    int size();
};

class func_part
{
public:
    int funcType;
    vector<string> code;
    string name;
    int ret;
    func_part(int ft, string fn);
    void set(int ft, string fn);
    void output();
    void addCode(string _code);
    string delCode();
    void resetCode(string _code);
};