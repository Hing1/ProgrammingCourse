# Modify Date class

## Description

```cpp
class Date
{
public:
    Date(int y = 0, int m = 1, int d = 1);
    static bool leapyear(int year);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    bool operator<(Date &d);
    bool operator<=(Date &d);
    bool operator==(Date &d);
    bool operator!=(Date &d);
    bool operator>(Date &d);
    bool operator>=(Date &d);
    int &operator[](const string &s);

    // add any member you need here
};
```

You implementation should enable the usage like this:

```cpp
    Date date(2011,4,1);
    cout << date["year"] << endl; // output 2011
    cout << date["month"] << endl;// output 4
    cout << date["day"] << endl; // output 1
    date["year"] = 2007;
    date["month"] = 11;
    date["day"] = 11;
    cout << date["year"] << endl; // output 2007
    cout << date["month"] << endl;// output 11
    cout << date["day"] << endl; // output 11
```

What to do if the subscript is not one of "year", "month" or "day"?</br>
Define a custom exception class named IllegalSubscriptException and let the function operator [] throw an IllegalSubscriptException if the subscript is not one of "year", "month" or "day".</br>
The test function f():

```cpp
void f()
{
    Date date1(2011, 4, 1);
    try
    {
        cout << date1["abc"] << endl;
    }
    catch (IllegalSubscriptException ex)
    {
        cout << "Illegal Subscript Exception" << endl;
    }

    try
    {
        date1["abc"] = 2000;
    }
    catch (IllegalSubscriptException ex)
    {
        cout << "Illegal Subscript Exception" << endl;
    }
}
```

should output:

```cpp

Illegal Subscript Exception
Illegal Subscript Exception
```
