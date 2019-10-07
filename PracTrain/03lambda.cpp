#include <iostream>
#include <functional>

using namespace std;

class A {
public:
    int func(std::function<bool(int)> filter) {
        if(filter(12))
            cout << "true filter" << endl;
        else
            cout << "false filter" << endl;
        return 1234;
    }
};

int main() {
    A a_class;

    auto fun = [=](int n) -> bool{return (n == 5);};
    int temp = a_class.func(fun);

    cout << temp << endl;
    cout << "Hello World!" << endl;
    return 0;
}


/**
[]	不截取任何变量
[&]	截取外部作用域中所有变量，并作为引用在函数体中使用
[=]	截取外部作用域中所有变量，并拷贝一份在函数体中使用
[=, &foo] 截取外部作用域中所有变量，并拷贝一份在函数体中使用，但是对foo变量使用引用
[bar]	截取bar变量并且拷贝一份在函数体重使用，同时不截取其他变量
[this] 截取当前类中的this指针。如果已经使用了&或者=就默认添加此选项。
 */
