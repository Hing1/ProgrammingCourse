#include "mystack.h"

MyStack::MyStack(int cpct)
    :stackSize(0),
    arrayCapacity(cpct) {
    array = (char*)malloc(cpct * sizeof(char));
}

MyStack::~MyStack() {
    stackSize = 0;
    free(array);
}

bool MyStack::empty() const {
    return stackSize == 0;
}

char MyStack::top() const {
    if(empty())
        throw underflow();
    return array[stackSize - 1];
}

void MyStack::push(char const & obj) {
    if(stackSize == arrayCapacity)
        throw overflow();
    array[stackSize++] = obj;
}

char MyStack::pop() {
    if(empty())
        throw underflow();
    return array[--stackSize];
}
