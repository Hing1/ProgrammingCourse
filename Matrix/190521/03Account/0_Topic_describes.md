# Account

## һ���򵥵������˻��������

Account��һ�������˻���ʵ��ģ�ͣ�����һ������balance��ʾ��ǰ�Ĵ������һ������name��ʾ�˻�������ͬ���˻�name�ǲ�ͬ�ģ�������������Ϊ�ֱ��ʾ���deposit()��ȡ��withdraw()����ѯ���getBalance()�Ͳ�ѯ�û���getName()������ÿһ�����˻����������ڵ��κ�ʱ�̶������˻���С��0������ֹ�˻�͸֧����һԼ�����ر�أ�ȡ��ɹ���withdraw����true�����򷵻�false��</br>

���ڳ��򲻽���Ҫ����ĳһλ�˿͵��˻������һ������漰�����������˻���Ҫ�������Ի�Ӧ����һ����Ϊ���˻�����Ա����ʵ��ģ�ͣ�������ִ��ÿһ�˻��Ŀ��衢�����ͷ��ʵȲ�����</br>

�˻�����ԱAccountManager��һ����accountlist��¼��ǰ�ѿ���������˻���accountNumber��¼��ǰ�ѿ�����˻������������и������ֿ����˻���open�����������ֳ����˻���close���������û�����depositByName���������û���ȡ�withdrawByName���������û�����ѯ��getBalanceByName���������û�����ѯ�˻���getAccountByName��������Ϊ�� </br></br>
��ʵ������Account��AccountManager��Ķ��壬����ɸ��˻��������:</br>

```cpp
class Account
{
private:
         string name;
         double balance;
public:
         Account();
         Account(string,double);
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
         void depositByName(string,double);
         bool withdrawByName(string,double);
         double getBalanceByName(string);
         Account getAccountByName(string);
};
```

��������������е���ʽ���������main.cpp�� ֧�ֵ��������£������У�name��string��num��double����

```cpp
open name
close name
deposit name num
withdraw name num
check name
quit
```