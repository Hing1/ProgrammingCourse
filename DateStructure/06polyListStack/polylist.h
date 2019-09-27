#ifndef POLYLIST_H
#define POLYLIST_H

#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

class MonoData {
public:
    int coefficient;
    int power;
};

class MonoNode {
public:
    MonoData data;
    MonoNode * next;
};

class PolyList {
public:
    PolyList();
    PolyList(void*);
    ~PolyList();
    MonoNode * getHead() const;
    void insertNode(int, int);
    PolyList & operator+=(const PolyList & another);
    void displayPoly() const;

private:
    MonoNode * _head;
};

class mallocError {};
class error_NullPoly {};

#endif // POLYLIST_H
