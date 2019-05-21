#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Person.h"

class Student : public Person
{
private:
    Date graduateDate;

public:
    using Person::set;
    Student(string name, int age, Date d) : Person(name, age), graduateDate(d)
    {
    }
    void set(Date d)
    {
        this->graduateDate = d;
    }
    void sayHi() const
    {
        Person::sayHi();
        Date today("2017-5-7");
        if (graduateDate > today)
            cout << "I will graduate on " << graduateDate.toString() << "." << endl;
        else if (graduateDate == today)
            cout << "I graduated today!" << endl;
        else
            cout << "I have graduated on " << graduateDate.toString() << "." << endl;
    }
};
#endif // STUDENT_H
