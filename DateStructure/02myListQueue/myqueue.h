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

#endif // MYQUEUE_H
