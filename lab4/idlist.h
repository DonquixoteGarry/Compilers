#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct idnode
{
    int order;
    string value;
    idnode* next;
    idnode* last;
    
    idnode()
    {
        order=0;
        next=NULL;
        last=NULL;
        //std::cout<<"node ok"<<std::endl;
    }
    
    void setorder(int ordernum)
    {
        order=ordernum;
        //std::cout<<"node set order "<<order<<std::endl;
    }
    
    void setval(string val)
    {
        value=val;
        //std::cout<<"node set value "<<value<<std::endl;
    }
};

struct idlist
{
    idnode* head;
    int len;
    
    idlist()
    {
        len=0;
        head=NULL;
    }
    
    void append(string val)
    {
        if(len==0)
        {
            head=new idnode;
            head->setval(val);
            head->setorder(1);
            len++;
        }
        else
        {
            idnode* curr=head;
            while(1)
            {
                if(curr->next==NULL)
                {   
                    idnode* temp=new idnode;
                    temp->setval(val);
                    temp->setorder(len+1);
                    curr->next=temp;
                    temp->last=curr;
                    len++;
                    return;
                }
                else curr=curr->next;
            }
            
            
        }
    }
    
    int search(string val)
    {
        if(head==NULL)return 0;
        idnode* curr=head;
        while(1)
        {
            if(curr->value==val)
            {
                return curr->order;
            }
            if(curr->order==len)return 0;
            else curr=curr->next;
        }
    }
    



    bool in(string val)
    {
        if(head==NULL)return false;
        idnode* curr=head;
        while(1)
        {
            if(curr->value==val)
            {
                return true;
            }
            if(curr->order==len)return false;
            else curr=curr->next;
        }
    }
    
    void sort(){}
};