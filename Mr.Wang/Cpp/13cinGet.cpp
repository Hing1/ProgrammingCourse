#include <iostream>

using namespace std;

int main()
{
    char ch;
    while ((ch = cin.get()) != EOF) //EOF Ϊ�ļ����������� ctrl+d ����
        cout.put(ch);
    return 0;
}