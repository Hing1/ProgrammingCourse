#include <iostream>
#include "mystack.h"

using namespace std;

int main() {
    MyStack ms;
    for (int i = 0; i < 5; i++) {
        ms.push(i);
    }
    while (!ms.empty()) {
        cout << ms.pop() << " ";
    }
    putchar(10);
    cout << "Hello World!" << endl;
    return 0;
}
