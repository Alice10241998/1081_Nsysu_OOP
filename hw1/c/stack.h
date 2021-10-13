#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE 100

struct node //表node
{
    int data; //值
    struct node *next; //下一個node
};

struct stack //記錄stack最上面的node
{
    struct node *top; //第一個node
};

extern void push(struct stack* this, int x);
extern int pop(struct stack* this);
extern struct stack* new_stack();
extern void delete_stack(struct stack* stk);

#endif

