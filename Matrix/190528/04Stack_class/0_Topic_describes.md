# The stack class

## Description

You are to implement the following Stack class template, using the nontype parameter capacity to allocate the capacity of the stack, i.e. maximum elements that can be stored in the stack.

```cpp
template<typename T, int capacity>
class Stack
{
public:
    Stack();              // Constructs an empty stack.
    bool empty();         // Returns true if the stack is empty.
    T peek();             // Returns the element at the top of the stack without removing it from the stack.
    void push(T value);   // Stores an element into the top of the stack.
    T pop();              // Removes the element at the top of the stack and returns it.
    int size();           // Returns the number of elements in the stack.
private:
    T* elements;          // Points to an array that stores elements in the stack.
    int num;              // The number of the elements in the stack.
};
```

Your submitted source code should only include the implementation of Stack class template, without the declaration above.</br>
No main() function should be included.