#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

class Stack
{
public:
    Stack(int size = 1024);
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(int data);
    int pop();

private:
    int *space;
    int top;
};

Stack::Stack(int size)
{
    space = new int[size];
    top = 0;
}
Stack::~Stack()
{
    delete[] space;
}
bool Stack::isEmpty()
{
    return top == 0;
}
bool Stack::isFull()
{
    return top == 1024;
}
void Stack::push(int data)
{
    space[top++] = data;
}
int Stack::pop()
{
    return space[--top];
}

int main()
{
    Stack s(100);
    if (!s.isFull())
        s.push(10);
    if (!s.isFull())
        s.push(20);
    if (!s.isFull())
        s.push(30);
    if (!s.isFull())
        s.push(40);
    if (!s.isFull())
        s.push(50);

    while (!s.isEmpty())
        cout << s.pop() << endl;
    return 0;
}
