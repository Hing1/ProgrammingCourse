#ifndef INSTANCE_H
#define INSTANCE_H

#include <iostream>

using namespace std;

class Object
{
public:
    virtual string name() = 0;
    virtual ~Object() {}
};
class Animal : public Object
{
public:
    virtual string name()
    {
        return "Animal";
    }
};
class Dog : public Animal
{
public:
    string name()
    {
        return "Dog";
    }
};
class Cat : public Animal
{
public:
    string name()
    {
        return "Cat";
    }
};
class Vehicle : public Object
{
public:
    virtual string name()
    {
        return "Vehicle";
    }
};
class Bus : public Vehicle
{
public:
    string name()
    {
        return "Bus";
    }
};
class Car : public Vehicle
{
public:
    string name()
    {
        return "Car";
    }
};
string instanceOf(Object *obj)
{
    if (obj)
        return obj->name();
    return "NULL";
}
#endif // INSTANCE_H
