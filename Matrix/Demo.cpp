#include <iostream>
#include "alphastring.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
/*
下次任务：

5.delete命令
6.添加其他字母
7. 设计其他更复杂的形状（如矩形，三角形，圆形）。
8. 实现字母大小的控制；
*/
void instructions();

int main()
{
    AlphaString alp_str;
    string command;
    system("color f3");
    instructions();
    while (1)
    {
        cin >> command;
        if (command == "add")
        {
            char alp;
            cin >> alp;
            alp_str.add(alp);
        }
        else if (command == "stat")
        {
            alp_str.dis_place();
        }
        else if (command == "show")
        {
            system("cls");
            alp_str.show();
            break;
        }
        else if (command == "delete")
        {
            alp_str._delete();
        }

        else
        {
            cout << "This command does not exist" << endl;
            cout << "Please re-enter the command" << endl;
        }
    }
}

void instructions()
{
    cout << "Welcome to the Alphabet Sketchpad System" << endl;
    cout << "There are the following commands:" << endl
         << "	add:add a alpha" << endl
         << "	delete:delete a alpha" << endl
         << "	stat:display location information" << endl
         << "	show:display alpha" << endl;
    cout << "The system has entered the following alphas : a y s u" << endl;
    cout << "Please enter the command:" << endl;
}
