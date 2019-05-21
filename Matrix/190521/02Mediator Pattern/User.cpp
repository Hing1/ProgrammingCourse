#include "User.hpp"
#include "Mediator.hpp" // ���ͷ�ļ���λ�÷ǳ���Ҫ
#include <vector>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

int User::Count = 0;

// ��Ա������Ϊ�����ͱ������û������������н飬�����н��ҵ�һ���������û�
User::User(const string &name, const int &money, const vector<pair<string, int>> &dresses) : name(name), money(money), id(Count++)
{
    for (auto c : dresses)
        this->dresses.push_back(Dress(c.first, c.second));
}

// ��������
void User::BuyBeautifulDress(const int &id, const int &pay, const string &name)
{
    if (pay > money)
    {
        cout << this->name << " : "
             << "Forget to Check Wallet!" << endl;
        return;
    }

    auto p = Mediator::getInstance()->TradeHandler(id, pay, name);

    if (p.first == -1)
        cout << this->name << " : "
             << "I'm so sorry maybe just because I love it so much." << endl;
    else if (p.first == -2)
        cout << this->name << " : "
             << "OMG! Why it is so Expensive!" << endl;

    else
    {
        cout << this->name << " : "
             << "So happy to get new Dress!" << endl;
        dresses.push_back(Dress(name, p.first));
        money -= pay;
    }
}
/*
    if pay > money
      cout << this->name << " : " << "Forget to Check Wallet!" << endl;
    if buy success
      cout << this->name << " : " << "So happy to get new Dress!" << endl;
    if No such a dress
      cout << this->name << " : " << "I'm so sorry maybe just because I love it so much." << endl;
    if Can't afford it
      cout << this->name << " : " <<  "OMG! Why it is so Expensive!" << endl;
*/

// ��������ȡ��װ��Ϣ
void User::GetDressInfo(const int &id)
{
    cout << this->name << " : "
         << "I wanna see your beautiful suits!" << endl;
    Mediator::getInstance()->DressInfoHandler(id); // �������
}
/*
    You need print this sentence at first
    cout << this->name << " : " << "I wanna see your beautiful suits!" << endl;
*/

// ��������
pair<int, string> User::SellBeautifulDress(const int &pay, const string &dname)
{
    auto it = std::find_if(dresses.begin(), dresses.end(), [dname](const Dress &d) { return d.getName() == dname; });
    if (it == dresses.end())
    {
        cout << this->name << " : "
             << "I never have this Dress stupid!" << endl;
        return make_pair(-1, dname);
    }

    else
    {
        if (it->getPrice() > pay)
        {
            cout << this->name << " : "
                 << "No money then no talking" << endl;
            return make_pair(-2, dname);
        }

        else
        {
            cout << this->name << " : "
                 << "What a good taste you have !" << endl;
            int s = it->getPrice();
            dresses.erase(it);
            money += pay;
            return make_pair(s, dname);
        }
    }
} // how to use to pair to represent diffierent information?
/*
    if Don't have that dress
    cout << this->name <<" : " << "I never have this Dress stupid!" << endl;
    if pay is lower than your price
    cout << this->name << " : " <<  "No money then no talking" << endl;
    if success
    cout << this->name << " : " << "What a good taste you have !" << endl;
*/

// ����������Ϣ
void User::SendMessage(const int &to, const string &msg)
{
    Mediator::getInstance()->ChatHandler(to, msg);
}

// ������������Ϣ
void User::GetMessage(const string &msg)
{
    cout << this->name << " : I got a Msg - " << msg << endl;
}
/*
    print like:
    cout << this->name <<" : I got a Msg - " << msg << endl;
*/

// ������������װ��Ϣ
void User::ShowMyCuteDresses()
{
    cout << this->name << " : ok,these are all I have : " << endl;
    for (int i = 0; i < dresses.size(); ++i)
        cout << dresses[i].getName() << "-" << dresses[i].getPrice() << endl;
}
/*
    print this at first:
    cout << this->name << " : ok,these are all I have : "<<endl;
    Then For each Dress
    cout << dresses[i].getName() << "-" << dresses[i].getPrice() << endl;
*/