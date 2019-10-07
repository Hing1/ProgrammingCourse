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
[]	����ȡ�κα���
[&]	��ȡ�ⲿ�����������б���������Ϊ�����ں�������ʹ��
[=]	��ȡ�ⲿ�����������б�����������һ���ں�������ʹ��
[=, &foo] ��ȡ�ⲿ�����������б�����������һ���ں�������ʹ�ã����Ƕ�foo����ʹ������
[bar]	��ȡbar�������ҿ���һ���ں�������ʹ�ã�ͬʱ����ȡ��������
[this] ��ȡ��ǰ���е�thisָ�롣����Ѿ�ʹ����&����=��Ĭ����Ӵ�ѡ�
 */
