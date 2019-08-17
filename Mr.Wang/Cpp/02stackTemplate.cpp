#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

template <typename T>
class Stack
{
public:
    Stack(int size)
    {
        space = new T[size];
        top = 0;
    }
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(T data);
    T pop();

private:
    T *space;
    int top;
};

template <typename T>
Stack<T>::~Stack()
{
    delete[] space;
}
template <typename T>
bool Stack<T>::isEmpty()
{
    return top == 0;
}
template <typename T>
bool Stack<T>::isFull()
{
    return top == 1024;
}
template <typename T>
void Stack<T>::push(T data)
{
    space[top++] = data;
}
template <typename T>
T Stack<T>::pop()
{
    return space[--top];
}

int main()
{
    Stack<double> s(100);
    if (!s.isFull())
        s.push(10.1);
    if (!s.isFull())
        s.push(20.2);
    if (!s.isFull())
        s.push(30.3);
    if (!s.isFull())
        s.push(40.4);
    if (!s.isFull())
        s.push(50.5);

    while (!s.isEmpty())
        cout << s.pop() << endl;
    return 0;
}
