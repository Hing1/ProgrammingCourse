#include<iostream>
#include<fstream>

using namespace std;
/*
fstream printf(fstream fs) {

};

friend ostream & operator<<(ostream &,)//必须传引用


void func(fstream a) {
    //不可以，只能传引用
}
*/
void func(fstream & a) {
    
}


int main() {
    fstream fs1,fs2;
    //fstream fs3(fs2);//不可以拷贝构造，构造器为private
    
    //fs1 = fs2;//不可以赋值重载，赋值重载为private"operator=()"

    
    return 0;
}
