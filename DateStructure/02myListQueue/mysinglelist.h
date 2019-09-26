#ifndef MYSINGLELIST_H
#define MYSINGLELIST_H

#include <stdlib.h>

template <typename Type>
class MySingleNode {
public:
    Type data;
    MySingleNode * next;
};

template <typename Type>
class MySingleList {
public:
    MySingleList();
	~MySingleList();

	int size() const;
	bool empty() const;
	Type front() const;
	Type back() const;
	MySingleNode<Type> *head() const;
	MySingleNode<Type> *tail() const;
	int count(Type const &) const;

	void pushFront(Type const &);
	void pushBack(Type const &);
	Type popFront();
	int erase(Type const &);
private:
    MySingleNode<Type> * _head;
};

class mallocError {

};
class underflow {

};

#endif // MYSINGLELIST_H
