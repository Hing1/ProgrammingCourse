#include <vector>
#include <deque>
#include <iostream> // elementAccessDemo  8.4.cpp
using namespace std;

int main()
{
    vector<int> ivec;   // 创建空的vector容器，用于存放int型对象
    deque<string> sdeq; // 创建空的deque容器，用于存放string型对象
    int iarr[] = {100, 100, 100};

    for (int i = 1; i < 11; i++)
        ivec.push_back(i);

    ivec.insert(ivec.begin(), 20);
    ivec.insert(ivec.begin() + 4, 30);
    ivec.insert(ivec.begin() + 5, 30);

    ivec.insert(ivec.end(), iarr, iarr + 3);

    sdeq.push_back("is");
    sdeq.push_front("this");
    sdeq.insert(sdeq.end(), "an");
    sdeq.insert(sdeq.end(), "example");

    cout << "vector:" << endl;
    for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
        cout << *it << ' ';
    cout << endl;

    cout << "double-ended queue:" << endl;
    for (deque<string>::iterator it = sdeq.begin(); it != sdeq.end(); it++)
        cout << *it << ' ';

    return 0;
}