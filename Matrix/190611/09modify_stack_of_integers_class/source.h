#ifndef SOURCE_H
#define SOURCE_H

#define MAX_LEN 100

class EmptyStackException
{
};

class StackOfIntegers
{
public:
    StackOfIntegers()
    {
        stack_size = 0;
    }
    bool empty() const
    {
        return (stack_size == 0);
    }
    int getSize() const
    {
        return stack_size;
    }
    int &peek()
    {
        if (stack_size < 1)
            throw EmptyStackException();
        return data[stack_size - 1];
    }
    void push(const int &x)
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
    int pop()
    {
        if (stack_size < 1)
            throw EmptyStackException();
        stack_size--;
        return data[stack_size];
    }

private:
    int data[MAX_LEN];
    int stack_size;
};

#endif // SOURCE_H
