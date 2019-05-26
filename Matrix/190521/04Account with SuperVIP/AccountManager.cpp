#include "AccountManager.hpp"

AccountManager::AccountManager()
{
    Account Temp("NULL", 0);
    SuperVipAccount = &Temp;
    *accountNumber = 0;
}
AccountManager::AccountManager(const AccountManager &another) //拷贝构造函数
{
    this->accountNumber = another.accountNumber;
    //    this->ManagerNumber = another.ManagerNumber;
    for (int i = 0; i < *this->accountNumber; i++)
    {
        this->accountlist[i] = another.accountlist[i];
    }
    this->SuperVipAccount = another.SuperVipAccount;
}

void AccountManager::open(string _name)
{
    Account temp(_name, 0);
    accountlist[*accountNumber] = temp;
    *accountNumber = *accountNumber + 1;
}
void AccountManager::close(string _name)
{
    int i;
    for (i = 0; i < *accountNumber; i++)
        if (accountlist[i].getName() == _name)
            break;
    for (; i < *accountNumber - 1; i++)
    {
        accountlist[i] = accountlist[i + 1];
    }
    *accountNumber = *accountNumber - 1;
}
void AccountManager::depositByName(string _name, double _money)
{
    int i;
    for (i = 0; i < *accountNumber; i++)
        if (accountlist[i].getName() == _name)
            break;
    accountlist[i].deposit(_money);
}
bool AccountManager::withdrawByName(string _name, double _money)
{
    int i;
    for (i = 0; i < *accountNumber; i++)
        if (accountlist[i].getName() == _name)
            break;
    return accountlist[i].withdraw(_money);
}
double AccountManager::getBalanceByName(string _name)
{
    int i;
    for (i = 0; i < *accountNumber; i++)
        if (accountlist[i].getName() == _name)
            break;
    return accountlist[i].getBalance();
}
Account AccountManager::getAccountByName(string _name)
{
    int i;
    for (i = 0; i < *accountNumber; i++)
        if (accountlist[i].getName() == _name)
            break;
    return accountlist[i];
}

void AccountManager::openSuperVipAccount(Account &act) //开设超级Vip账户
{
    *SuperVipAccount = act;
}
void AccountManager::closeSuperVipAccount() //关闭超级Vip账户
{
    Account Temp("NULL", 0);
    *SuperVipAccount = Temp;
}
bool AccountManager::getBalanceOfSuperVipAccount(double &) const
{
    return SuperVipAccount->getBalance();
}
int AccountManager::getAccountNumber() const
{
    return *accountNumber;
}
int AccountManager::getManagerNumber() const
{
    //    return ManagerNumber;
}
AccountManager::~AccountManager() //析构函数
{
    delete[] SuperVipAccount;
}
