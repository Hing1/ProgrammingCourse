#include<iostream>

using namespace std;

int main() {
    int a = 0x12345678;
    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    cout<<a<<endl;
    cout.unsetf(ios::hex);
    cout.setf(ios::oct);
    cout<<a<<endl;
    return 0;
}