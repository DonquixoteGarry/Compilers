#include"asm.h"
void rodata_part::output()
{
    //按句打印只读变量汇编代码块
    int i = 0;
    for (vector<string>::iterator it = ro_data.begin(); it != ro_data.end(); it++, i++)
    {
        printf("STR%d:\n\t.string \"%s\"\n", i, (*it).c_str());
    }
}
void rodata_part::emplace_back(string str)
{
    //在只读变量表的汇编代码块中增加一句代码
    //emplace_back是vector的原地构造函数
    ro_data.emplace_back(str);
}
int rodata_part::size()
{
    //返回只读变量表汇编代码块的句数
    return ro_data.size();
}

func_part::func_part(int ft, string fn)
{
    //构造默认函数代码块
    //基于函数名和返回值类型
    //最顶层函数为空函数名与无效返回值类型(-1)
    funcType = ft;
    name = fn;
    ret = 0;
}
void func_part::set(int ft, string fn)
{
    //函数代码块类型与函数名赋值
    funcType = ft;
    name = fn;
}
void func_part::output()
{   
    //函数开始的标签
    printf("\n\t.text\n");
    printf("\t.globl\t%s\n", name.c_str());
    printf("\t.type\t%s, @function\n", name.c_str());
    //函数初始化,压栈
    printf("%s:\n", name.c_str());
    printf("\tpushl\t%%ebp\n");
    printf("\tmovl\t%%esp, %%ebp\n");
    //函数代码块遍历输出
    for (vector<string>::iterator it = code.begin(); it != code.end(); it++)
    {
        printf("%s", (*it).c_str());
    }
    //函数结束,弹出堆栈
    printf("\tpopl\t%%ebp\n");
    printf("\tmovl\t$%d, %%eax\n", ret);
    printf("\tret\n");
}
void func_part::addCode(string _code)
{
    //函数代码块后加一句代码
    code.emplace_back(_code);
}
string func_part::delCode()
{
    //函数代码块删掉最后一句代码
    //返回被删掉的这句代码
    string str = code[code.size() - 1];
    code.pop_back();
    return str;
}
void func_part::resetCode(string _code)
{
    //修改函数代码块的最后一句代码
    code[code.size() - 1] = _code;
}