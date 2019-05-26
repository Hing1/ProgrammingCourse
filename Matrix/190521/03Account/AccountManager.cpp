#include "AccountManager.hpp"

AccountManager::AccountManager()
    : accountNumber(0) {}
void AccountManager::open(string _name)
{
    Account temp(_name, 0);
    accountlist[accountNumber] = temp;
    accountNumber++;
}
void AccountManager::close(string _name)
{
    int i;
    for (i = 0; i < accountNumber; i++)
        if (accountlist[i].getName() == _name)
            break;
    for (; i < accountNumber - 1; i++)
    {
        accountlist[i] = accountlist[i + 1];
    }
    accountNumber--;
}
void AccountManager::depositByName(string _name, double _money)
{
    int i;
    for (i = 0; i < accountNumber; i++)
        if (accountlist[i].getName() == _name)
            break;
    accountlist[i].deposit(_money);
}
bool AccountManager::withdrawByName(string _name, double _money)
{
    int i;
    for (i = 0; i < accountNumber; i++)
        if (accountlist[i].getName() == _name)
            break;
    accountlist[i].withdraw(_money);
}
double AccountManager::getBalanceByName(string _name)
{
    int i;
    for (i = 0; i < accountNumber; i++)
        if (accountlist[i].getName() == _name)
            break;
    return accountlist[i].getBalance();
}
Account AccountManager::getAccountByName(string _name)
{
    int i;
    for (i = 0; i < accountNumber; i++)
        if (accountlist[i].getName() == _name)
            break;
    return accountlist[i];
}
