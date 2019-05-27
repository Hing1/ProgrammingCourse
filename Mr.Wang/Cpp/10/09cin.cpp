#include <iostream>

using namespace std;

int main()
{
    int a;
    double b;
    char buf[1024];//虽然是字符串，但是不能有空格

    cin>>a>>b>>buf;

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"buf = "<<buf<<endl;
}