#include <iostream>
#include "a.h"

using namespace std;

void fun(const int & a) {
    cout << a << endl;
}

int main() {
    A<int> a;
    for (int i = 0; i < 5; i++) {
        a.func(i);
    }
    cout << "Hello World!" << endl;
    return 0;
}
