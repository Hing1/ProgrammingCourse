#ifndef MYLIST_H
#define MYLIST_H

class MyNode {
public:
    MyNode(int value= 0, MyNode * next= nullptr)
        :node_value(value),next_node(next){}
    int value() const {
        return node_value;
    }
    MyNode * next() const {
        return next_node;
    }
    friend class MyList;
private:
    int node_value;
    MyNode * next_node;
};

class MyList {
public:
    MyList();
    MyList(MyList const & list);
    ~MyList();

    bool empty() const;
    int size() const;
    int front() const;
    MyNode * begin() const;
    MyNode * end() const;
    int count(int )const;

    void push_front(int );
    int pop_front();
    int erase(int );
private:
    MyNode * list_head;
};

class underflow {

};

#endif // MYLIST_H
