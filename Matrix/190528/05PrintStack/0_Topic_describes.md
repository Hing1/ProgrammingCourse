# Function printStack

## Description

Rewrite the Stack class to add the printStack function as an instance function to display all the elements in the stack, as follows:

```cpp
template<typename T>
class Stack
{
public:
    Stack();
    bool empty();
    T peek();
    void push(T value);
    T pop();
    int getSize();
    void printStack();
};
```

The printStack() function output the elements in the stack from top to bottom, each element in one line. Just output the elements, don't erase the elements in the stack.</br>
The following codes:

```cpp
Stack<int> s;
for(int i=0;i<3;++i)
    s.push(i);
s.printStack();
s.push(3);
s.printStack();
```

Output:

```c
2
1
0
3
2
1
0
```
