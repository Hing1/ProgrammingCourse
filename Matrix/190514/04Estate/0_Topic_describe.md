# Estate

## Description

Feng Gor�������ķ��ز��̣���ÿ�����Ҫ�������ǡ�����Ǯ���Ⲣ����һ�����׵��£�Feng Gor��ҪͶ������أ�һ����Բ�ģ�һ���Ƿ��ġ���������Ϊ���Ļ�ƣ���Ҫ������Ǯ��</br>
Circle���Square��̳���Land�࣬�ֱ����Բ�ĵغͷ��ĵأ����ݵ�λ����۸�(price)�͵ص����(���ݱ߳���뾶���)��</br>
Accountant�����ڼ���Feng Gor�������ַ��ز����������롣</br>
DevelopEstate��������һ��Land��ָ�룬���㿪����鷿�ز����������루�����õ��˶�̬��Ŷ����</br>
CheckMoney�������ص�ǰ�����롣

## Sample_Input

```cpp
//�������һ�����Ե�main����
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char *argv[]) {
  Accountant py;
  Circle *a = new Circle(100, 10000);
  Square *b = new Square(100, 50000);
  py.DevelopEstate(a);
  cout << setprecision(10) << py.CheckMoney() << endl;
  py.DevelopEstate(b);
  cout << setprecision(10) << py.CheckMoney() << endl;

  return 0;
}
```

## Sample_Ouput

```cpp
314159265.4
814159265.4
```

## Hint

Ϊ�˷�ֹ��ұ�����Բ���ʵ���Wrong Answer����������һ�£�pi������acos(-1)��ʾ��acos��cmath���