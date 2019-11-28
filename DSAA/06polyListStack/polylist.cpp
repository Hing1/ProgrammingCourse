#include "polylist.h"

PolyList::PolyList() {
    _head = (MonoNode*)malloc(sizeof(MonoNode));
    if(nullptr == _head)
        throw mallocError();
    _head->next = nullptr;
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
    if(nullptr == tNode)
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
