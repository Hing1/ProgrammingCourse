# element insertion in a sequential container _from lecture 8

## Description

Implement the following operations:

```cpp
#include <vector>
#include <deque>
#include <iostream>          // elementAccessDemo  8.4.cpp
using namespace std;

int main() {
    vector<int> ivec;         // �����յ�vector���������ڴ��int�Ͷ���
    deque<string> sdeq;       // �����յ�deque���������ڴ��string�Ͷ���
    int iarr[] = {100, 100, 100};

    // ��vector����������Ԫ�أ���β������10��Ԫ�أ�ֵΪ1~10
    // your code

    // ��vector����ͷ��������һ��Ԫ�أ�ֵΪ20
    // your code

    // ��vector�����ĵ��ĸ�Ԫ�غ�����������Ԫ�أ�ֵ��Ϊ30
    // your code

    //������iarr�е�Ԫ�����ӵ�vector����β�ˡ�ע�⣺�������Ԫ�ز�����
    //������������ָ���Ԫ����ˣ�Ҫ����iarr�е�����Ԫ�أ�����������Ӧ
    //��Ϊiarr��3
    //your code

    // ��deque����������Ԫ��
    sdeq.push_back("is");
    sdeq.push_front("this");
    sdeq.insert(sdeq.end(), "an");
    sdeq.insert(sdeq.end(), "example");

    // ���vector�����е�Ԫ��
    cout << "vector:" << endl;
    for(vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
        cout << *it << ' ';
    cout << endl;

    // ���deque�����е�Ԫ��
    cout << "double-ended queue:" << endl;
    for(deque<string>::iterator it = sdeq.begin(); it != sdeq.end(); it++)
        cout << *it << ' ';

    return 0;
}
```

## Output

```cpp
vector:
20 1 2 3 30 30 4 5 6 7 8 9 10 100 100 100 
double-ended queue:
this is an example
```
