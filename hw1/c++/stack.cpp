#include "stack.h"

Stack::Stack() //初始化，一開始stack為空
{
	top=0;
}

void Stack::push(int x)
{
    node *newnode =new node(x); //newnode為新增的節點，配置新的位置
    if(top!=0) //stack有東西
    {
        newnode->next=top; //top接在newnode後
        top=newnode; //top指向newnode指向的位置
    }
    else top=newnode;
}

int Stack::pop()
{
    node *pre,*cur; //pre為前一個node，cur為目前的node
    cur=top; //cur指向top
    pre=top->next; //pre指向top的前一個push的node
    int x=top->data; //儲存值
    delete cur; //刪除最上面的node
    top=pre; //更改top
    return x;
}

Stack::~Stack() //清除整個linked list
{
	while(top!=0) //直到stack空才停止
    {
        node *cur=top; //cur指向top
        top=top->next; //top更改下一個node
        delete cur;
    }
}
