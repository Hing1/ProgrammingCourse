#include <iostream>

using namespace std;

int main()
{
    char ch;
    while ((ch = cin.get()) != EOF) //EOF 为文件结束符，按 ctrl+d 输入
        cout.put(ch);
    return 0;
}