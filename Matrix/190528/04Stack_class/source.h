#ifndef SOURCE_H
#define SOURCE_H

#include<deque>

using namespace std;

template<typename T,int capacity>
class Stack
{
public:
    deque<T> d;
    Stack();
    bool empty() const;
    T peek() const;
    void push(T value);
    T pop();
    int size() const;

private:
    T* elements;          // Points to an array that stores elements in the stack.
    int num;
};

template<typename T,int capacity>
Stack<T,capacity>::Stack()
{
    d.clear();
    num = 0;
}
template<typename T,int capacity>
bool Stack<T,capacity>::empty() const
{
    return d.empty();
}
template<typename T,int capacity>
T Stack<T,capacity>::peek() const
{
    return d[0];
}
template<typename T,int capacity>
void Stack<T,capacity>::push(T value)
{
    d.push_front(value);
}
template<typename T,int capacity>
T Stack<T,capacity>::pop()
{
    T temp = d[0];
    d.pop_front();
    return temp;
}
template<typename T,int capacity>
int Stack<T,capacity>::size() const
{
    return d.size();
}

#endif // SOURCE_H
