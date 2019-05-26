# Account with SuperVIP

## 银行账户管理（超级Vip账户

Account是一个银行账户的实体模型，它有一个属性balance表示当前的存款余额，有一个属性name表示账户名（不同的账户name是不同的），另有三个行为分别表示设置账户名setName、设置余额setBalance、查询余额getBalance和查询用户名getName操作.</br>
由于程序不仅需要管理某一位顾客的账户，而且还可能涉及大量的银行账户需要处理，所以还应建立一个名为“账户管理员”的实体模型，它负责执行每一账户的开设、撤销和访问等操作。每个账户管理员管理若干个账户，账户可能由多个账户管理员同时管理。</br></br>
账户管理员AccountManager有一属性accountlist记录当前已开设的所有账户，accountNumber为指针，其指向的值记录当前已开设的账户个数，SuperVipAccount为对象指针，其指向的值为超级Vip账户，当管理员管理的账户里没有开设超级Vip账户时，指针指向NULL。账户可以在不同银行开设，所以需要拷贝构造函数AccountManager(const AccountManager&)，将所有信息移植给另外的管理员，注意深复制与浅复制的问题。管理员还有开设账户open、开设超级Vip账户openSuperVipAccount、关闭超级Vip账户closeSuperVipAccount、获取超级Vip账户余额getBalanceOfSuperVip、获取账户总数getAccountNumber、获取管理员总数getManagerNumber这些行为。</br>
特别的，getBalanceOfSuperVip有个double类型的引用参数，如果已经开设超级Vip则将其余额赋值给此参数，并且函数返回true；否则参数的值不改变，函数返回false。</br>
超级Vip是独立存在的，开设和关闭超级Vip的时候不需要改变Manager里的accountlist和accountNumber。</br></br>
请实现如下Account和AccountManager类的定义，以完成该账户管理程序:</br>

```cpp
class Account
{
private:
    string name;
    double balance;

public:
    Account();
    Account(string, double);
    void setName(string);      //设置账户名
    void setBalance(double);   //设置余额
    string getName() const;    //const成员函数，获取账户名
    double getBalance() const; //const成员函数，获取账户余额
};

class AccountManager
{
private:
    Account accountlist[100];
    int *accountNumber;       //记录当前开设的账户总数
    Account *SuperVipAccount; //记录超级Vip账户
    static int ManagerNumber; //static成员，记录所有管理员总数
public:
    AccountManager();
    AccountManager(const AccountManager &); //拷贝构造函数
    void open(string);
    void close(string);
    void depositByName(string, double);
    bool withdrawByName(string, double);
    double getBalanceByName(string);
    Account getAccountByName(string);
    void openSuperVipAccount(Account &); //开设超级Vip账户
    void closeSuperVipAccount();         //关闭超级Vip账户
    bool getBalanceOfSuperVipAccount(double &) const;
    int getAccountNumber() const;
    int getManagerNumber() const;
    ~AccountManager(); //析构函数
};
```