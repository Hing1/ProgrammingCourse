#ifndef INSERVICE_H
#define INSERVICE_H

#include <iostream>
using namespace std;

class Person
{
public:
    Person(string name, int sex)
        : _name(name), _sex(sex)
    {
        cout << "Construct Person" << endl;
    }
    string getName()
    {
        return _name;
    }
    int getSex()
    {
        return _sex;
    }
    ~Person()
    {
        cout << "Destruct Person" << endl;
    }

private:
    string _name;
    int _sex;
};

class Student : virtual public Person
{
public:
    Student(string name, int sex, string sno)
        : Person(name, sex), _sno(sno)
    {
        cout << "Construct Student" << endl;
    }
    string getSno()
    {
        return _sno;
    }
    ~Student()
    {
        cout << "Destruct Student" << endl;
    }

private:
    string _sno;
};
class Worker : virtual public Person
{
public:
    Worker(string name, int sex, string wno)
        : Person(name, sex), _wno(wno)
    {
        cout << "Construct Worker" << endl;
    }
    string getWno()
    {
        return _wno;
    }
    ~Worker()
    {
        cout << "Destruct Worker" << endl;
    }

private:
    string _wno;
};
class InService : public Student, public Worker
{
public:
    InService(string name, int sex, string sno, string wno)
        : Student(name, sex, sno), Worker(name, sex, wno), Person(name, sex)
    {
        cout << "Construct InService" << endl;
    }
    ~InService()
    {
        cout << "Destruct InService" << endl;
    }
};

#endif // INSERVICE_H
