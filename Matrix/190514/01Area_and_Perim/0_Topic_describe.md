# Area and Perim

## Description

����һ��Shape�����࣬�ڴ˻�����������Rectangle���Circle�࣬���߶���GetArea������GetPerim������������������������ܳ����鷳��װ���ϸ��࣬��д������Ҫ�ύ��shape��Rectangle��Cricle��</br>
��������

```cpp
int main()
{
    double n, a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Shape *s;
        cin >> a >> b >> c;
        s = new Rectangle(a, b);
        cout << s->GetArea() << " " << s->GetPerim() << endl;
        delete s;
        s = new Circle(c);
        cout << s->GetArea() << " " << s->GetPerim() << endl;
        delete s;
    }
    return 0;
}
```

## Input

��һ������n����ʾn���������ӣ���������n�У�ÿһ����������a��b��c����ʾ���εĿ������Լ�Բ�εİ뾶

## Output

��Ӧÿһ�����룺</br>
��һ��������ε�������ܳ�</br>
�ڶ������Բ�ε�������ܳ�</br>

## Sample_Input

```cpp
1
2 2 3
```

## Sample_Ouput

```cpp
4 8
28.26 18.84
```

## Hint

```cpp
const double PI = 3.14�� (Already defined)
```