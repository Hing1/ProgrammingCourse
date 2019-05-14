#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
using namespace std;

class Shape
{
public:
    Shape() {}
    virtual double GetArea() {}
    virtual double GetPerim() {}
};

class Rectangle : public Shape
{
public:
    Rectangle(double l, double w)
        : _len(l), _wid(w) {}
    double GetArea()
    {
        return _len * _wid;
    }
    double GetPerim()
    {
        return 2 * (_len + _wid);
    }
    virtual ~Rectangle() {}

private:
    double _len;
    double _wid;
};

class Circle : public Shape
{
public:
    Circle(double r)
        : _r(r) {}
    double GetArea()
    {
        return _r * _r * 3.14;
    }
    double GetPerim()
    {
        return 2 * _r * 3.14;
    }
    virtual ~Circle() {}
private:
    double _r;
};
#endif // SOURCE_H
