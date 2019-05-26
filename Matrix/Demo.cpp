//This file is just a recycle bin

class Account
{
private:
    string name;
    double balance;

public:
    Account();
    Account(string, double);
    void deposit(double);
    bool withdraw(double);
    string getName();
    double getBalance();
};

class AccountManager
{
private:
    Account accountlist[100];
    int accountNumber;

public:
    AccountManager();
    void open(string);
    void close(string);
    void depositByName(string, double);
    bool withdrawByName(string, double);
    double getBalanceByName(string);
    Account getAccountByName(string);
};