#include <iostream>
#include "mylist.h"

using namespace std;

int staticAllocation(int n) {
    MyList ls;

    ls.push_front(n);
    cout << ls.front() << endl;

    return 0;
}
MyList * dynamicAllocation(int n) {
    MyList * pls = new MyList();

    pls->push_front(n);
    cout << pls->front() << endl;

    return pls;
}
void reverse(MyList & list) {
    MyList tmp;
    while (!list.empty()) {
        tmp.push_front(list.pop_front());
    }

    swap(list, tmp);
}
MyList initalize(int a, int b) {
    MyList list;

    for (int i = b; i >= a; i--) {
        list.push_front(i);
    }
    return list;
}


int main() {
    MyList vec = initalize(3, 6);
    cout << "Hello World!" << endl;
    return 0;
}
