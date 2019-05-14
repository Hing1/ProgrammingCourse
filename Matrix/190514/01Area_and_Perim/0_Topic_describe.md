# Area and Perim

## Description

声明一个Shape抽象类，在此基础上派生出Rectangle类和Circle类，两者都有GetArea（）和GetPerim（）函数，用来计算面积和周长，麻烦封装以上各类，编写程序。需要提交类shape、Rectangle、Cricle类</br>
主函数：

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

第一行输入n，表示n个测试例子；接下来有n行，每一行输入数，a、b、c，表示矩形的宽、长，以及圆形的半径

## Output

对应每一行输入：</br>
第一行输出矩形的面积、周长</br>
第二行输出圆形的面积、周长</br>

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
const double PI = 3.14； (Already defined)
```