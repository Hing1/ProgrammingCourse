# Destructor

## Description

下面是不完整的继承类定义:

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

试完成其定义(你可以根据需要增加必要的构造函数、析构函数 ),使得主函数main运行后能得到其后结果：

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

运行结果：

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