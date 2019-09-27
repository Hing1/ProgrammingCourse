#include "mystack.h"

MyStack::MyStack(int cpct)
    :arrayCapacity(cpct),
    stackSize(0) {
    array = (PolyList*)malloc(cpct * sizeof(PolyList));
//   how to initialize it to bull
}
MyStack::~MyStack() {
    stackSize = 0;
    free(array);// Do I need to free the node in the list?
}
bool MyStack::empty() const {
    return !stackSize;
}
void MyStack::push(PolyList const & obj) {
    if(stackSize == arrayCapacity)
        throw overflow();
    array[stackSize++] = obj;
}
PolyList MyStack::pop() {
    if(empty())
        throw underflow();
    return array[--stackSize];
}
PolyList MyStack::top() const {
    if(empty())
        throw underflow();
    return array[stackSize - 1];
}
void MyStack::showMap() const {
    for (int i = 0; i < stackSize; i++) {
        cout << "array[" << i << "] = ";
        array[i].displayPoly();
    }
}
