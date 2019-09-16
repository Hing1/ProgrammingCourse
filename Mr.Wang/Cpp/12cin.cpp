#include <iostream>
#include <fstream>

using namespace std;

void cinBr();
void fstreamInBr();

int main() {
    cinBr();
    fstreamInBr();
    return 0;
}

void cinBr() {
    int a;
    double b;
    char buf[1024];

    cin>>a>>b>>buf; // 1 2.3 abcd efg

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"buf = "<<buf<<endl;
}
void fstreamInBr() {
    fstream fs("abc.txt", ios::in|ios::out|ios::trunc);
    fs << 1 << 2 << 3 << endl;

    fs.seekg(0, ios::beg);

    int a, b, c;
    fs >> a >> b >> c;

    cout<< "a = " << a <<endl;
    cout<< "b = " << b <<endl;
    cout<< "c = " << c <<endl;
}
