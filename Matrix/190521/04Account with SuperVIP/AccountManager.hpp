#ifndef _ACCOUNT_MANAGER_HPP_
#define _ACCOUNT_MANAGER_HPP_
#include "Account.hpp"
#include <string>
using std::string;

class AccountManager
{
public:
    AccountManager();
    AccountManager(const AccountManager &); //�������캯��
    void open(string);
    void close(string);
    void depositByName(string, double);
    bool withdrawByName(string, double);
    double getBalanceByName(string);
    Account getAccountByName(string);
    void openSuperVipAccount(Account &); //���賬��Vip�˻�
    void closeSuperVipAccount();         //�رճ���Vip�˻�
    bool getBalanceOfSuperVipAccount(double &) const;
    int getAccountNumber() const;
    int getManagerNumber() const;
    ~AccountManager(); //��������
private:
    Account accountlist[100];
    int *accountNumber;       //��¼��ǰ������˻�����
    Account *SuperVipAccount; //��¼����Vip�˻�
    static int ManagerNumber; //static��Ա����¼���й���Ա����
};

#endif
