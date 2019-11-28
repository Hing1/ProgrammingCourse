#include <iostream>
#include "mystack.h"

using std::cout;
using std::endl;

int main() {
	MyStack ms(20);
    for(char i = 'a'; i <= 'd'; i++) {
		ms.push(i);
	}
	while(!ms.empty()) {
		cout << ms.pop() << " ";
	}
	putchar(10);
	cout << "Hello World!" << endl;
    return 0;
}
