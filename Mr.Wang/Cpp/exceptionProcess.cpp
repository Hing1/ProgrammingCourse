#include <iostream>

using namespace std;

void g() {
    double a;
//    float a;
    try {
        throw a;
    } catch (double) {
        cout << "Catch g()" << endl;
    }
    cout << "End g()" << endl;
    return;
}
void h() {
    try {
        g();
    } catch (int) {
        cout << "Catch h()" << endl;
    }
    cout << "End h()" << endl;
}
void f() {
    try {
        h();
    } catch (char) {
        cout << "Catch f()" << endl;
    }
    cout << "End f()" << endl;
    return;
}

int main() {
    try {
        f();
    } catch (float) {
        cout << "Catch main()" << endl;
    }
    cout << "End main()" << endl;
    return 0;
    return 0;
}
