#include <iostream>
#include<fstream>

using namespace std;

int main()
{
    fstream fs("abc.txt",ios::in|ios::out|ios::trunc);

    fs<<1<<2<<3<<endl;

    fs.seekg(0,ios::beg);

    int a,b,c;
    fs>>a>>b>>c;

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
}