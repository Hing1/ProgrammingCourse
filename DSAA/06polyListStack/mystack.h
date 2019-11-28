#ifndef MYSTACK_H
#define MYSTACK_H

#include "polylist.h"

class MyStack
{
public:
    MyStack(int = 30);
    ~MyStack();
    bool empty() const;
    void push(PolyList const & obj);
    PolyList pop();
    PolyList top() const;
    void showMap() const;

private:
    int arrayCapacity;
    int stackSize;
    PolyList * array;
};

class overflow {};
class underflow {};

#endif // MYSTACK_H
