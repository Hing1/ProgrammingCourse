#include "Account.hpp"

Account::Account()
{
    name = "NULL";
    balance = 0;
}
Account::Account(string _name, double _balance)
    : name(_name), balance(_balance) {}
void Account::deposit(double money)
{
    balance += money;
}
bool Account::withdraw(double money)
{
    if (balance - money >= 0)
    {
        balance -= money;
        return true;
    }
    else
        return false;
}
string Account::getName()
{
    return name;
}
double Account::getBalance()
{
    return balance;
}
