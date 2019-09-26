#include <iostream>
#include "myqueue.h"

using namespace std;

int main() {
    MyQueue<int> mq(5);
    for (int i = 0; i < 5; i++) {
        mq.push(i);
    }
    for (int i = 0; i < 5; i++) {
        cout << mq.pop() << " ";
    }
    putchar(10);
#if 0
    mq.increaseCpct(5);
    for (int i = 0; i < 6; i++) {
        mq.push(i);
    }
    for (int i = 0; i < 6; i++) {
        cout << mq.pop() << " ";
    }
#endif
    cout << "Hello World!" << endl;
    return 0;
}
