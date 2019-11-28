#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>

template <typename Type>
class MyQueue {
private:
    int queueSize;
    int ifront;   // index of the front entry
    int iback;    // index of the back entry
    int arrayCapacity;
    Type * array;
public:
    MyQueue(int = 10);
    ~MyQueue();
    bool empty() const;
    bool full() const;
    Type front() const;
    Type back() const;
    void push(Type const &);
    Type pop();
    void increaseCpct(int );
};

class underflow {};
class overflow {};

template <typename Type>
MyQueue<Type>::MyQueue(int n)
    :queueSize(0),
    ifront(0),
    iback(-1),
    arrayCapacity(std::max(1, n)),
    array(new Type[arrayCapacity]) {}

template <typename Type>
MyQueue<Type>::~MyQueue() {
    delete [] array;
}

template <typename Type>
bool MyQueue<Type>::empty() const {
    return !queueSize;
}

template <typename Type>
bool MyQueue<Type>::full() const {
    return (queueSize == arrayCapacity);
}

template <typename Type>
Type MyQueue<Type>::front() const {
    if(empty())
        throw underflow();
    return array[ifront];
}

template <typename Type>
Type MyQueue<Type>::back() const {
    if(empty())
        throw underflow();
    return array[iback];
}

template <typename Type>
void MyQueue<Type>::push(Type const & obj) {
    if(full())
        throw overflow();
    if(++iback == arrayCapacity)
        iback = 0;
    array[iback] = obj;
    queueSize++;
}

template <typename Type>
Type MyQueue<Type>::pop() {
    if(empty())
        throw underflow();
    queueSize--;
    if(ifront + 1 == arrayCapacity) {
        ifront = 0;
        return array[arrayCapacity - 1];
    } else {
        ifront++;
        return array[ifront - 1];
    }
}

template <typename Type>
void MyQueue<Type>::increaseCpct(int addCpct) {
#if 0
//    There is an error in this function.
    int newCpct = this->arrayCapacity + addCpct;
    MyQueue<Type> temp(newCpct);
    while(!this->empty())
        temp.push(this->pop());
    delete [] array;
    array = new Type[newCpct];
    while(!temp.empty())
        this->push(temp.pop());
    arrayCapacity = newCpct;
#endif
}

#endif // MYQUEUE_H
