#include <iostream>
#include "mystack.h"

using std::cout;
using std::endl;

void testPolyList();
void testMyStack();

int main() {
//    testPolyList();
    testMyStack();
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
