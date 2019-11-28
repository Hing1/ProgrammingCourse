#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdlib.h>

class MyStack {
private:
	int stackSize;
	int arrayCapacity;
	char * array;
public:
    MyStack(int = 10);
	~MyStack();
	bool empty() const;
	char top() const;
	void push(char const &);
	char pop();
};

class underflow {};
class overflow {};

#endif // MYSTACK_H
