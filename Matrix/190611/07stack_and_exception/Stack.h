#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

const int MAX_LEN = 5;

template <class T>
class Stack
{
public:
    explicit Stack()
    {
        stack_size = 0;
    }
    bool empty() const
    {
        return (stack_size == 0);
    }
    int size() const
    {
        return stack_size;
    }
    T &top()
    {
        if (stack_size < 1)
            throw(int) - 1;
        return data[stack_size - 1];
    }
    void push(const T &x)
    {
        if (stack_size < MAX_LEN)
        {
            data[stack_size] = x;
            stack_size++;
        }
        else if (x > data[stack_size - 1])
            data[stack_size - 1] = x;
        else
            return;
    }
    void pop()
    {
        if (stack_size < 1)
            throw(double) - 1;
        stack_size--;
        //cout << data[stack_size] << endl;
    }

private:
    T data[MAX_LEN];
    int stack_size;
};

#endif // STACK_H
