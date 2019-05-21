#include "User.hpp"
#include "Mediator.hpp" // 这个头文件的位置非常重要
#include <vector>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

int User::Count = 0;

// 成员函数分为主动和被动，用户主动发出到中介，再由中介找到一个被动的用户
User::User(const string &name, const int &money, const vector<pair<string, int>> &dresses) : name(name), money(money), id(Count++)
{
    for (auto c : dresses)
        this->dresses.push_back(Dress(c.first, c.second));
}

// 主动，买
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

// 主动，获取服装信息
void User::GetDressInfo(const int &id)
{
    cout << this->name << " : "
         << "I wanna see your beautiful suits!" << endl;
    Mediator::getInstance()->DressInfoHandler(id); // 巧妙调用
}
/*
    You need print this sentence at first
    cout << this->name << " : " << "I wanna see your beautiful suits!" << endl;
*/

// 被动，卖
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

// 主动，发信息
void User::SendMessage(const int &to, const string &msg)
{
    Mediator::getInstance()->ChatHandler(to, msg);
}

// 被动，接收信息
void User::GetMessage(const string &msg)
{
    cout << this->name << " : I got a Msg - " << msg << endl;
}
/*
    print like:
    cout << this->name <<" : I got a Msg - " << msg << endl;
*/

// 被动，给出服装信息
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