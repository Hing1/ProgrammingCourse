#include "mysinglelist.h"

template <typename Type>
MySingleList<Type> ::MySingleList() {
    _head = (MySingleNode<Type>*)malloc(sizeof(MySingleNode<Type>));
    if(nullptr == _head)
        throw mallocError();
    _head->next = nullptr;
}
template <typename Type>
MySingleList<Type> ::~MySingleList() {
    while (_head) {
        MySingleNode<Type> temp = _head;
        _head = _head->next;
        free(temp);
    }
}

template <typename Type>
int MySingleList<Type> ::size() const{
    if(empty())
        return 0;

    int num = 0;
    MySingleNode<Type> * myHead = (MySingleNode<Type>*)malloc(sizeof(MySingleNode<Type>));
    myHead = _head;
    while (myHead) {
        myHead = myHead->next;
        num++;
    }
    return num;
}
template <typename Type>
bool MySingleList<Type> ::empty() const{
    return !(_head->next);
}
template <typename Type>
Type MySingleList<Type> ::front() const{
    if(empty())
        throw underflow();
    return _head->next->data;
}
template <typename Type>
Type MySingleList<Type> ::back() const{
    if(empty())
        throw underflow();

    MySingleNode<Type> * myHead = (MySingleNode<Type>*)malloc(sizeof(MySingleNode<Type>));
    myHead = _head;
    while (!myHead->next)
        myHead = myHead->next;
    return myHead->data;
}
template <typename Type>
MySingleNode<Type> * MySingleList<Type> ::head() const{
    if(empty())
        throw underflow();
    return _head;
}
template <typename Type>
MySingleNode<Type> * MySingleList<Type> ::tail() const{
    if(empty())
        throw underflow();

    MySingleNode<Type> * myHead = (MySingleNode<Type>*)malloc(sizeof(MySingleNode<Type>));
    myHead = _head;
    while (!myHead->next)
        myHead = myHead->next;
    return myHead;
}
template <typename Type>
int MySingleList<Type> ::count(Type const & key) const{
    if(empty())
        throw underflow();

    MySingleNode<Type> * myHead = (MySingleNode<Type>*)malloc(sizeof(MySingleNode<Type>));
    myHead = _head;
    int cou = 0;
    while (myHead->next) {
        cou++;
        myHead = myHead->next;
        if(myHead->data == key)
            return cou;
    }
    return -1;
}

template <typename Type>
void MySingleList<Type> ::pushFront(Type const & newData) {
    MySingleNode<Type> * temp = (MySingleNode<Type>*)malloc(sizeof(MySingleNode<Type>));
    temp->data = newData;
    temp->next = _head->next;
    _head->next = temp;
}
template <typename Type>
void MySingleList<Type> ::pushBack(Type const & newData) {
    MySingleNode<Type> * temp = (MySingleNode<Type>*)malloc(sizeof(MySingleNode<Type>));
    MySingleNode<Type> * myHead = (MySingleNode<Type>*)malloc(sizeof(MySingleNode<Type>));
    myHead = _head;

    temp->data = newData;
    while (myHead->next)
        myHead = myHead->next;
    temp->next = myHead->next;
    myHead->next = temp;
}
template <typename Type>
Type MySingleList<Type> ::popFront() {
    if(empty())
        throw underflow();
    Type temp = _head->next->data;
    _head = _head->next;
    return temp;
}
template <typename Type>
int MySingleList<Type> ::erase(Type const & key) {
    if(empty())
        throw underflow();

    int cou = 1;
    MySingleNode<Type> * myHead = (MySingleNode<Type>*)malloc(sizeof(MySingleNode<Type>));
    myHead = _head;
    if(myHead->next->data == key) {
        popFront();
        return cou;
    }
    while (myHead->next->next) {
        cou++;
        myHead = myHead->next;
        if(myHead->next->data == key) {
            MySingleNode<Type> * temp = (MySingleNode<Type>*)malloc(sizeof(MySingleNode<Type>));
            temp = myHead->next;
            myHead->next = temp->next;
            free(myHead);
            return cou;
        }
    }
    return -1;
}
