#ifndef __STACK_H__
#define __STACK_H__

class node //表node
{
	public:
	friend class Stack;
    	node(int x){data=x;}

	private:
	int data; //值
	node* next; //下一個node
};

class Stack //記錄stack最上面的node
{
	public:
	Stack();
	void push(int x);
	int pop();
	~Stack();

	private:
	node *top; //第一個node
};

#endif
