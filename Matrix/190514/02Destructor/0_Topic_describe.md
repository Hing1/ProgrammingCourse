# Destructor

## Description

�����ǲ������ļ̳��ඨ��:

```cpp
class A
{
public:
    virtual void Prin()
    {
        cout << "Prin come form class A" << endl;
    }
};
class B
{
    char *buf;
public:
    void Prin()
    {
        cout << "Prin come from class B" << endl;
    }
};
```

������䶨��(����Ը�����Ҫ���ӱ�Ҫ�Ĺ��캯������������ ),ʹ��������main���к��ܵõ��������

```cpp
void fun(A *a)
{
    delete a;
}
int main()
{
    A *a = new B(10);
    a->Prin();
    fun(a);
    B *b = new B(20);
    fun(b);
    return 0;
}
```

���н����

```cpp
Prin come from class B
B::~B()called
A::~A()called
B::~B()called
A::~A()called
```

## Hint

virtual destructor!</br>
only need to submit class A, B and main()</br>