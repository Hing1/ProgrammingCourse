# Template Specification

## Description

����һ��������������

```CPP
bool cmp( T a, T b )��
```

�ú����Ƚϱ��� a �� b ��С�����a����b������true�����򷵻�false.

1. ���a, b�������� int, float, double, char* �� string ����cmp �Ƚϵ��� a, b ֵ�Ĵ�С����ע��char*�ַ����ıȽ���ʹ�ú���strcmp��ͷ�ļ�string.h����
2. ���a, b��������ָ�룬��Ƚϵ�������ָ��Ķ����Ƿ���ȡ�

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