#include <iostream>
#include <iomanip>

using namespace std;

class MyIOS {
    enum {
        DEC = 0001,
        HEX = 0010,
        OCT = 0100
    };
};

void oldWay();
void newWay();
void showIOSflag();
void precision();
void scientific();
void lowercaseToUppercase();
void coutPut();

int main() {
    fputs("abcdefg", stdout);

    oldWay();
    newWay();

    showIOSflag();
    precision();
    scientific();
    lowercaseToUppercase();
    coutPut();
    return 0;
}

void oldWay() {
    int a = 0x12345678;

    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    cout << a << endl;

    cout.unsetf(ios::hex);
    cout.setf(ios::dec);
    cout << a << endl;
}
void newWay() {
    int a = 0x12345678;

    cout << hex << a << endl;
    cout << dec << a << endl;
    cout << oct << a << endl;
}
void showIOSflag() {
    double d1 = 10 / 5;
    double d2 = 22.0 / 7;

    cout << d1 << endl;
    cout << setiosflags(ios::showpoint) << d1 << endl;
    cout << setiosflags(ios::showpos) << d2 << endl;
}
void precision() {
    double dd = 123.45678;
    cout << setprecision(2) << dd << endl;
    cout << setprecision(3) << dd << endl;
    cout << setprecision(4) << dd << endl;
    cout << setprecision(5) << dd << endl;
}
void scientific() {
    double dd = 123.45678;

    cout << setiosflags(ios::scientific) << dd << endl;

    cout << resetiosflags(ios::scientific);
    cout << setiosflags(ios::fixed) << dd << endl;

    cout << setprecision(2) << setiosflags(ios::fixed) << dd << endl;
}
void lowercaseToUppercase() {
    int n = 0xabcd;
    cout << hex << n << endl;
    cout << setiosflags(ios::uppercase) << hex << n << endl;
    cout << resetiosflags(ios::uppercase) << hex << n << endl;
}
void coutPut() {
    char str[] = "Programming with C++";

    for (int i = sizeof(str) / sizeof(*str); i >= 0; i--)
        cout.put(*(str + i));

    cout.put(10);
}
