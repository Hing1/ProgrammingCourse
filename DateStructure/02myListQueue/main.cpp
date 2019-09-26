#include <iostream>
#include "myqueue.h"

using namespace std;

int main() {
    MyQueue<int> mq;
    for (int i = 0;i < 10; i++) {
        mq.push(i);
    }
    for (int i = 0;i < 10; i++) {
        cout << mq.pop() << " ";
    }
    putchar(10);
    return 0;
}
