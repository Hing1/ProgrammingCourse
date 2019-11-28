#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdlib.h>

class MyNode {
public:
	int data;
	MyNode * next;
};

class MyStack
{
public:
    MyStack();
	~MyStack();

	bool empty();
	int top();
    void push(int const &);
	int pop();
private:
	MyNode * _head;
};

class underflow {};

#endif // MYSTACK_H
