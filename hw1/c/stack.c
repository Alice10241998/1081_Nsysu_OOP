#include <stdlib.h>
#include "stack.h"

void push(struct stack* this, int x)
{
    struct node* tmp  = malloc(sizeof(struct node));
    if(this->top!=0)
    {
        tmp->data=x; //儲存值
        tmp->next=this->top; //top接在tmp後
        this->top=tmp; //top指向tmp指向的位置
    }
    else
    {
        this->top=tmp;
        tmp->data=x;
    }
}
int pop(struct stack* this)
{
    struct node* tmp; 
    int n;
    tmp=this->top; //tmp指向最上面的node
    n=tmp->data; //儲存原本top的值
    this->top=this->top->next; //top指向原本top的下一個node
    free(tmp); //刪除tmp
    return n;
}

struct stack* new_stack()
{
	struct stack* stk = malloc(sizeof(struct stack));
	return stk;
}

void delete_stack(struct stack* stk)
{
	free(stk);
}
