#include <iostream>
#include <cstdlib>

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
    ~PolyList();
    MonoNode * getHead() const;
    void insertNode(int, int);
    PolyList & operator+=(const PolyList & another);
    void displayPoly() const;
private:
    MonoNode * _head;
};

class MyStack {
public:
    MyStack(int = 30);
    ~MyStack();
    bool empty() const;
    void push(PolyList const & obj);
    PolyList pop();
    PolyList top() const;
    void showMap() const;
private:
    int arrayCapacity;
    int stackSize;
    PolyList * array;
};

class mallocError {};
class error_NullPoly {};
class overflow {};
class underflow {};

void testPolyList();
void testMyStack();

int main() {
//    testPolyList();
    testMyStack();

    putchar(10);
    cout << "successfully end main()" << endl;
    return 0;
}

void testMyStack() {
    MyStack ms(30);
    PolyList LP;
    PolyList LQ;
    PolyList LPQ;

    for (int i = 1; i < 5; i++) {
        LP.insertNode(i, i);
    }
    for (int i = 1; i < 5; i++) {
        LQ.insertNode(i, i);
    }
    LP.insertNode(-6, 3);

    ms.push(LP);
    ms.push(LQ);
    ms.push(LPQ);

    cout << endl << "Before add: ms.showMap()" << endl;
    ms.showMap();

    LPQ += LP;
    LPQ += LQ;

    cout << endl << "After add: ms.showMap()" << endl;
    ms.showMap();

    while(ms.empty()) {
        ms.pop();
    }
}

void testPolyList() {
    PolyList LP;
    PolyList LQ;
    PolyList LPQ;

    for (int i = 1; i < 5; i++) {
        LP.insertNode(i, i);
    }
    LQ.insertNode(-3, 3);

    cout << "Before +=" << endl;
    LP.displayPoly();
    LQ.displayPoly();

    LP += LQ;

    cout << "After +=" << endl;
    LP.displayPoly();
    LQ.displayPoly();
}

PolyList::PolyList() {
    _head = (MonoNode*)malloc(sizeof(MonoNode));
    if(NULL == _head)
        throw mallocError();
    _head->next = NULL;
}

PolyList::~PolyList() {
    MonoNode * temp;
    while (_head->next) {
        temp = _head;
        _head = _head->next;
        free(temp);
    }
    free(_head);
}

MonoNode * PolyList::getHead() const {
    return _head;
}

void PolyList::insertNode(int co, int po) {
    MonoNode * tNode = (MonoNode*)malloc(sizeof(MonoNode));
    if(NULL == tNode)
        throw mallocError();
    tNode->data.power = po;
    tNode->data.coefficient = co;

    MonoNode * tHead = getHead();
    while (tHead->next && tHead->next->data.power <= tNode->data.power) {
        if(tHead->next->data.power == tNode->data.power) {
            if(tHead->next->data.coefficient + tNode->data.coefficient != 0) {
                tHead->next->data.coefficient += tNode->data.coefficient;
            }else {
                MonoNode * temp = tHead->next;
                tHead->next = temp->next;
                free(temp);
            }
            return;
        }
        tHead = tHead->next;
    }
    tNode->next = tHead->next;
    tHead->next = tNode;
}

PolyList & PolyList::operator+=(const PolyList & another) {
    MonoNode * anoHead = another.getHead();
    while (anoHead->next) {
        insertNode(anoHead->next->data.coefficient, anoHead->next->data.power);
        anoHead = anoHead->next;
    }
    return *this;
}

void PolyList::displayPoly() const{
    if(!getHead())
        throw error_NullPoly();
    if(!getHead()->next) {
        cout << 0 << endl;
        return;
    }
    MonoNode * tHead = getHead()->next;
    while (tHead->next) {
        if(tHead->data.power == 1 && tHead->data.coefficient == 1)
            cout << "x + ";
        else if(tHead->data.power == 1)
            cout << tHead->data.coefficient << "x" << " + ";
        else if(tHead->data.coefficient  == 1)
            cout << "x^" << tHead->data.power << " + ";
        else
            cout << tHead->data.coefficient << "x^" << tHead->data.power << " + ";
        tHead = tHead->next;
    }
    if(tHead->data.power == 1 && tHead->data.coefficient == 1)
        cout << "x" << endl;
    else if(tHead->data.power == 1)
        cout << tHead->data.coefficient << "x" << endl;
    else if(tHead->data.coefficient  == 1)
        cout << "x^" << tHead->data.power << endl;
    else
        cout << tHead->data.coefficient << "x^" << tHead->data.power << endl;
    return;
}

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
