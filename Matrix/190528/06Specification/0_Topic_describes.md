# Template Specification

## Description

给定一个函数声明如下

```CPP
bool cmp( T a, T b )。
```

该函数比较变量 a 和 b 大小，如果a等于b，返回true；否则返回false.

1. 如果a, b的类型是 int, float, double, char* 或 string 函数cmp 比较的是 a, b 值的大小；（注意char*字符串的比较请使用函数strcmp（头文件string.h））
2. 如果a, b的类型是指针，则比较的是其所指向的对象是否相等。

## Input

```CPP
int aInt = 1, bInt = 2 ;
double aDouble = 3.0, bDouble = 3.0 ;
char aChars[5] = "haha", bChars[5] ;
string aStr = "haha", bStr = "aha" ;
int* aIntPtr = &aInt, *bIntPtr = &bInt ;

cout << boolalpha << cmp( aInt, bInt ) << endl ;
cout << cmp( aDouble, bDouble ) << endl ;

strcpy( bChars, aChars ) ;
cout << cmp( aChars, bChars ) << endl ;
cout << cmp( aStr, bStr ) << endl ;
cout << cmp( aIntPtr, bIntPtr ) << endl ;
```

## Output

```CPP
false
true
true
false
false
```