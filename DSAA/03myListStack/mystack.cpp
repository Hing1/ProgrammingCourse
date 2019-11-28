#include "mystack.h"

MyStack::MyStack() {
    _head = (MyNode*)malloc(sizeof(MyNode));
    _head->next = nullptr;
}
MyStack::~MyStack() {
    MyNode * temp;
    while (_head->next) {
        temp = _head;
        _head = _head->next;
        free(temp);
    }
}

bool MyStack::empty() {
    return !_head->next;
}
int MyStack::top() {
    return _head->next->data;
}
void MyStack::push(int const & obj) {
    MyNode * temp = (MyNode*)malloc(sizeof(MyNode));
    temp->data = obj;
    temp->next = _head->next;
    _head->next = temp;
}

int MyStack::pop() {
    if(empty())
        throw underflow();
    int tdata;
    tdata = _head->next->data;
    MyNode * tNode = _head->next;
    _head->next = tNode->next;
    free(tNode);
    return tdata;
}

#if 0
// this is queue pop.
int MyStack::pop() {
    MyNode * tHead;
    tHead = _head;
    while (tHead->next->next) {
        tHead = tHead->next;
    }
    int tdata;
    tdata = tHead->next->data;
    MyNode * tNode = tHead->next;
    free(tNode);
    tHead->next = nullptr;
    return tdata;
}
#endif
