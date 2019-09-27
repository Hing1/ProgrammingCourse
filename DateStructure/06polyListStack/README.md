# 实验报告

## 数据结构实现

该项目包含了两个类，一个为PolyList，另一个为MyStack

### PolyList

一个List表示一个多项式</br>
一个Node表示一个单项</br>
其中单项的data包括系数coefficient和次数power</br>

### MyStack

用Array实现Stack</br>
Array的每给元素的内容为PolyList</br>
Array默认初始化30个元素</br>

## 测试

### 函数testMyStack()

开始时

```c
LP = x + 2x^2 + 3x^3 + 4x^4
LQ = x + 2x^2 + 3x^3 + 4x^4
LPQ = 0
```

向LP中插入-6x^3,得

```c
LP = x + 2x^2 + (-3)x^3 + 4x^4
LQ = x + 2x^2 + 3x^3 + 4x^4
LPQ = 0
```

此过程证明了插入函数的正确性</br>
将他们相加，并将结果保存在LPQ中

```c
LP = x + 2x^2 + (-3)x^3 + 4x^4
LQ = x + 2x^2 + 3x^3 + 4x^4
LPQ = 2x + 4x^2 + 8x^4
```

此过程完成了作业项目要求的测试

### 函数testPolyList()

开始时

```c
LP = x + 2x^2 + 3x^3 + 4x^4
LQ = -3x^3
```

进行+=运算后

```c
LP = x + 2x^2 + 4x^4
LQ = -3x^3
```

此过程证明了PolyList class的正确性

## 复杂度分析

### 类PolyList

| 函数                                             | 复杂度 |
| ------------------------------------------------ | ------ |
| PolyList();                                      | O(1)   |
| ~PolyList();                                     | O(n)   |
| MonoNode * getHead() const;                      | O(1)   |
| void insertNode(int, int);                       | O(n)   |
| PolyList & operator+=(const PolyList & another); | O(n^2) |
| void displayPoly() const;                        | O(n)   |

### 类MyStack

| 函数                             | 复杂度 |
| -------------------------------- | ------ |
| MyStack(int = 30);               | O(1)   |
| ~MyStack();                      | O(1)   |
| bool empty() const;              | O(1)   |
| void push(PolyList const & obj); | O(1)   |
| PolyList pop();                  | O(1)   |
| PolyList top() const;            | O(1)   |
| void showMap() const;            | O(n^2) |
