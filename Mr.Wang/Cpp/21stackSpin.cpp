#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "A constructor" << endl;
    }
	A(const A & other) {
		cout << "A (const A & other)" << endl;
	}
    ~A() {
        cout << "~A destructor" << endl;
    }
};
int divide(int x, int y) {
	A * pa = new A;
    //A a;
    if(y == 0)
        throw A();
    return x / y;
}
int myDivide(int x, int y) {
	//A * pb = new A;
    A b;
    divide(x, y);
}

int main() {
    try {
        myDivide(4, 0);
    } catch (int x) {
        cout << "int" << x << endl;
    } catch (double y) {
		cout << "double" << y << endl;
    } catch (A a) {
		cout << "A a" << endl;
	} catch(...) {
		cout << "No " << endl;
	}
    return 0;
}
