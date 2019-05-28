# typename! typename

## Description

Given the following two classes TypeA, and TypeB:

```cpp
class TypeA
{
public:
  class SubType
  {
  public:
    string toString() {return "subType in TypeA";};
  };
};

class TypeB
{
public:
  class SubType
  {
  public:
    string toString() {return "subType in TypeB";};
  };
};
```

Write a template class MyClass that has a public variable named subtypeobj with type T::SubType.

```cpp
template <class T>
class MyClass
{
public:
//add your public member here
}
```

The following codes:

```cpp

MyClass<TypeA> obj1;
cout << obj1.subtypeobj.toString() << endl;
MyClass<TypeB> obj2;
cout << obj2.subtypeobj.toString() << endl;
```

output:

```cpp
subType in TypeA
subType in TypeB
```