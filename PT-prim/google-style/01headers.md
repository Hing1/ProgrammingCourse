# 头文件

## 1.1 Self-comtained

## 1.2 #define保护

所有头文件都应该使用#define来防止头文件被重包含</br>
命名格式：

```cpp
<PROJECT>_<PATH>_<FILE>_H_
```

头文件的命名应该基于所在项目源代码树的全路径。</br>
如

```cpp
#ifndef FOO_BAR_BAZ_H_
#define FOO_BAR_BAZ_H_
...
#endif // FOO_BAR_BAZ_H_
```

## 1.3 forward declaration前置声明

## 1.4 内联函数

在定义函数时，在返回值类型前加上inline关键字</br>
如：

```cpp
inline int Max (int a, int b)
```

只有当函数只有 10 行甚至更少时才将其定义为内联函数</br>
不要内联包含循环或switch语句的函数</br>

编译器会将其内联展开, 而不是按通常的函数调用机制进行调用</br>
调用内联函数的语句前必须已经出现内联函数的定义（即整个数体），而不能只出现内联函数的声明。</br>

## 1.5 #include的路径和顺序

### 顺序

1. 相关头文件
2. C库
3. C++库
4. 其他库的.h文件
5. 本项目的.h文件

相关头文件：指被本文件实现或测试的头文件

### 路径

从项目目录开始 -> project/src/aa.cpp</br>
避免使用UNIX特殊的快捷目录 . (当前目录)或 .. (上级目录)

### 例外

平台特定代码需要条件编译

```cpp
#include "foo/public/fooserver.h"

#include "base/port.h"  // For LANG_CXX11.

#ifdef LANG_CXX11
#include <initializer_list>
#endif  // LANG_CXX11
```

这些代码放在includes之后

## 译者笔记

1. 内联函数的合理使用可提高代码执行效率;
2. 前置声明的类是不完全类型（incomplete type），我们只能定义指向该类型的指针或引用，或者声明（但不能定义）以不完全类型作为参数或者返回类型的函数。</br>
我们不能创建其类的任何对象，也不能声明成类内部的数据成员。</br>
3. 在 #include 中插入空行以分割相关头文件, C 库, C++ 库, 其他库的 .h 和本项目内的 .h 是个好习惯
