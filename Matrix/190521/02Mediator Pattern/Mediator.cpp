#include <list>
#include <iostream>
#include <algorithm>
#include "Mediator.hpp"
using std::find_if;
using std::list;

void Mediator::RegisterHandler(User *u)
{
    users.push_back(u);
}
void Mediator::ChatHandler(const int &to, const string &msg)
{
    auto it = find_if(users.begin(), users.end(), [to](User *u) { return u->getId() == to; });
    if (it == users.end())
        cout << "Are you kidding ? There is no such a guy!" << endl;
    else
        (*it)->GetMessage(msg); // 因为是指针的集合...
}
/*
    if No Such a User
    cout << "Are you kidding ? There is no such a guy!" << endl;
*/
pair<int, string> Mediator::TradeHandler(const int &to, const int &pay, const string &dressName)
{
    auto it = find_if(users.begin(), users.end(), [to](User *u) { return u->getId() == to; });
    if (it == users.end())
        cout << "Are you kidding ? There is no such a guy!" << endl;
    else
        return (*it)->SellBeautifulDress(pay, dressName);
}
/*
    if no such a User
    cout << "There is no Such a guy!" << endl;
*/
void Mediator::DressInfoHandler(const int &to)
{
    auto it = find_if(users.begin(), users.end(), [to](User *u) { return u->getId() == to; });
    if (it == users.end())
        cout << "Are you kidding ? There is no such a guy!" << endl;
    else
        (*it)->ShowMyCuteDresses();
}

Mediator *Mediator::Ins = NULL;
