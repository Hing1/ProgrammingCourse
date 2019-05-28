#include "AccountManager.hpp"
#include <cstdlib>

using namespace std;

int AccountManager::ManagerNumber = 0;

AccountManager::AccountManager()
{
    accountNumber = new int;
    *accountNumber = 0;
    SuperVipAccount = NULL;
    ManagerNumber++;
}
AccountManager::AccountManager(const AccountManager &x)
{
    int num;
    num = *x.accountNumber;

    for (int i = 0; i < num; ++i)
        accountlist[i] = x.accountlist[i];

    accountNumber = new int;
    *accountNumber = num;

    if (x.SuperVipAccount != NULL)
    {
        SuperVipAccount = new Account;
        *SuperVipAccount = *(x.SuperVipAccount);
    }

    ManagerNumber++;
}

void AccountManager::open(string n)
{
    for (int i = 0; i < *accountNumber; ++i)
    {
        if (accountlist[i].getName() == "" && accountlist[i].getBalance() == 0)
        {
            Account newa(n, 0);
            accountlist[i] = newa;
            return;
        }
    }

    (*accountNumber)++;
    Account newa(n, 0);
    accountlist[(*accountNumber) - 1] = newa;
}
void AccountManager::close(string n)
{
    for (int i = 0; i < *accountNumber; ++i)
    {
        if (accountlist[i].getName() == n)
        {
            Account newa("", 0);
            accountlist[i] = newa;
            return;
        }
    }
}

void AccountManager::depositByName(string n, double b)
{
    for (int i = 0; i < *accountNumber; ++i)
        if (accountlist[i].getName() == n)
        {
            accountlist[i].deposit(b);
            return;
        }
}
bool AccountManager::withdrawByName(string n, double b)
{
    for (int i = 0; i < *accountNumber; ++i)
    {
        if (accountlist[i].getName() == n)
        {
            if (accountlist[i].getBalance() < b)
                return false;
            else
            {
                accountlist[i].withdraw(b);
                return true;
            }
        }
    }
}

double AccountManager::getBalanceByName(string n)
{
    for (int i = 0; i < *accountNumber; ++i)
        if (accountlist[i].getName() == n)
            return accountlist[i].getBalance();
    return -1;
}
Account AccountManager::getAccountByName(string n)
{
    for (int i = 0; i < *accountNumber; ++i)
        if (accountlist[i].getName() == n)
            return accountlist[i];

    Account a("", -1);
    return a;
}

void AccountManager::openSuperVipAccount(Account &a)
{
    SuperVipAccount = new Account;
    *SuperVipAccount = a;
}
void AccountManager::closeSuperVipAccount()
{
    delete SuperVipAccount;
}
bool AccountManager::getBalanceOfSuperVipAccount(double &b) const
{
    if (SuperVipAccount == NULL)
        return false;

    b = (*SuperVipAccount).getBalance();
    return true;
}
int AccountManager::getAccountNumber() const
{
    return *accountNumber;
}
int AccountManager::getManagerNumber() const
{
    return ManagerNumber;
}
AccountManager::~AccountManager()
{
    delete accountNumber;
    if (SuperVipAccount != NULL)
        delete SuperVipAccount;
}
