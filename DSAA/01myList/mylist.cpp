#include "mylist.h"


MyList::MyList()
    :list_head(nullptr){}
MyList::MyList(MyList const & anotherList)
    :list_head(nullptr) {
    if(anotherList.empty())
        return;

    push_front(anotherList.front());

    MyNode * original = anotherList.begin()->next();
    MyNode * copy = begin();

    while (original != anotherList.end()) {
        copy->next_node = new MyNode(original->value(), nullptr);
        original = original->next();
        copy = copy->next();
    }
}
MyList::~MyList(){}

bool MyList::empty() const {
    return (list_head == nullptr);
}
int MyList::size() const {
    int node_count = 0;

    for(MyNode * ptr = begin(); ptr != end(); ptr = ptr->next(),node_count++);

    int list_size = node_count * sizeof (MyNode);
    return list_size;
}
int MyList::front() const {
    if(empty())
        throw underflow();
    return begin()->value();
}
MyNode * MyList::begin() const {
    return list_head;
}
MyNode * MyList::end() const {
    return nullptr;
}
int MyList::count(int n)const {
	int node_count = 0;
	for(MyNode * ptr = begin(); ptr != end(); ptr = ptr->next()) {
		if(ptr->value() == n)
			node_count++;
	}
	return node_count;
}

void MyList::push_front(int n) {
    list_head = new MyNode(n, list_head);
}
int MyList::pop_front() {
	if(empty())
		throw underflow();

	int e = front();
	MyNode * ptr = list_head;
	list_head = list_head->next();
	delete ptr;
	return e;
}
int MyList::erase(int n) {
	int node_count = 0;

	for(MyNode * ptr = begin(); ptr != end(); ptr = ptr->next()) {
		if(ptr->node_value == n) {
			ptr->next_node = ptr->next()->next();
			node_count++;
		}
	}
	return node_count;
}
