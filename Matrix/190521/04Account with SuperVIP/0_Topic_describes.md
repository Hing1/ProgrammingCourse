# Account with SuperVIP

## �����˻���������Vip�˻�

Account��һ�������˻���ʵ��ģ�ͣ�����һ������balance��ʾ��ǰ�Ĵ������һ������name��ʾ�˻�������ͬ���˻�name�ǲ�ͬ�ģ�������������Ϊ�ֱ��ʾ�����˻���setName���������setBalance����ѯ���getBalance�Ͳ�ѯ�û���getName����.</br>
���ڳ��򲻽���Ҫ����ĳһλ�˿͵��˻������һ������漰�����������˻���Ҫ�������Ի�Ӧ����һ����Ϊ���˻�����Ա����ʵ��ģ�ͣ�������ִ��ÿһ�˻��Ŀ��衢�����ͷ��ʵȲ�����ÿ���˻�����Ա�������ɸ��˻����˻������ɶ���˻�����Աͬʱ����</br></br>
�˻�����ԱAccountManager��һ����accountlist��¼��ǰ�ѿ���������˻���accountNumberΪָ�룬��ָ���ֵ��¼��ǰ�ѿ�����˻�������SuperVipAccountΪ����ָ�룬��ָ���ֵΪ����Vip�˻���������Ա������˻���û�п��賬��Vip�˻�ʱ��ָ��ָ��NULL���˻������ڲ�ͬ���п��裬������Ҫ�������캯��AccountManager(const AccountManager&)����������Ϣ��ֲ������Ĺ���Ա��ע�������ǳ���Ƶ����⡣����Ա���п����˻�open�����賬��Vip�˻�openSuperVipAccount���رճ���Vip�˻�closeSuperVipAccount����ȡ����Vip�˻����getBalanceOfSuperVip����ȡ�˻�����getAccountNumber����ȡ����Ա����getManagerNumber��Щ��Ϊ��</br>
�ر�ģ�getBalanceOfSuperVip�и�double���͵����ò���������Ѿ����賬��Vip������ֵ���˲��������Һ�������true�����������ֵ���ı䣬��������false��</br>
����Vip�Ƕ������ڵģ�����͹رճ���Vip��ʱ����Ҫ�ı�Manager���accountlist��accountNumber��</br></br>
��ʵ������Account��AccountManager��Ķ��壬����ɸ��˻��������:</br>

```cpp
class Account
{
private:
    string name;
    double balance;

public:
    Account();
    Account(string, double);
    void setName(string);      //�����˻���
    void setBalance(double);   //�������
    string getName() const;    //const��Ա��������ȡ�˻���
    double getBalance() const; //const��Ա��������ȡ�˻����
};

class AccountManager
{
private:
    Account accountlist[100];
    int *accountNumber;       //��¼��ǰ������˻�����
    Account *SuperVipAccount; //��¼����Vip�˻�
    static int ManagerNumber; //static��Ա����¼���й���Ա����
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
};
```