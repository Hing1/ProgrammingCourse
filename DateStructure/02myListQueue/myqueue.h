#ifndef MYQUEUE_H
#define MYQUEUE_H

#include "mysinglelist.h"

template <typename Type>
class MyQueue {
public:
	bool empty() const;
	Type front() const;
	void push(Type const &);
	Type pop();
private:
	MySingleList<Type> list;
};

template <typename Type>
bool MyQueue<Type>::empty() const {
    return list.empty();
}

template <typename Type>
void MyQueue<Type>::push(Type const & obj) {
    list.pushBack(obj);
}

template <typename Type>
Type MyQueue<Type>::front() const {
    if(empty())
        throw underflow();
    return list.front();
}

template <typename Type>
Type MyQueue<Type>::pop() {
    if(empty())
        throw underflow();
    return list.popFront();
}

#endif // MYQUEUE_H
