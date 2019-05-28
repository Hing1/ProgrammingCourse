#include "Account.hpp"

using namespace std;

Account::Account()
{
    name = "";
    balance = 0;
}
Account::Account(string n, double b)
{
    name = n;
    balance = b;
}
void Account::deposit(double n) { balance += n; }
bool Account::withdraw(double n)
{
    if (balance < n)
        return false;
    balance = balance - n;
    return true;
}
string Account::getName() const { return name; }
double Account::getBalance() const { return balance; }
