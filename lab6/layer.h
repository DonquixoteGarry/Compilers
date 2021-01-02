#pragma once
#include<string>
#include<vector>
using namespace std;
class var
{
public:
    int type;
    string name;
    int ro_index;
    vector<int> dim;
    var()
    {
        this->type = 0;
        this->name = "";
    }
    var(const var& v)
    {
        this->type = v.type;
        this->name = v.name;
    }
    var(int type, string name)
    {
        this->type = type;
        this->name = name;
    }
    var(string name, int ro_index)
    {
        this->type = 4;
        this->ro_index = ro_index;
        this->name = name;
    }
};
class temp_var
{
public:
    var v;
    int l;
    temp_var(var v, int l)
    {
        this->v = var(v.type, v.name);
        this->l = l;
    }
};
class layer
{
public:
    vector<var> var_list;
    int index;
    void output()
    {
        for(int i = 0;i < var_list.size();i++)
        {
            printf("%s  %d\n", var_list[i].name.c_str(), index);
        }
    }
    layer(vector<var> var_list, int index)
    {
        this->var_list = var_list;
        this->index = index;
    }
};
