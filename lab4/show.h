#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;

void show(const char* type,char* text,int extra=0)
{
    if(extra ==0)
    {
        cout<<left<<setw(15)<<type
            <<left<<setw(15)<<text
            <<std::endl;

    }
    else 
    {
        cout<<left<<setw(15)<<type
            <<left<<setw(15)<<text
            <<left<<setw(15)<<extra
            <<std::endl;
    }
}