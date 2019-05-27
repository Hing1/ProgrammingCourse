#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double d1 = 10 / 5, d2 = 22.0 / 7;
    cout << "显示小数点、尾和数符: " << endl;
    cout << d1 << endl;
    cout << setiosflags(ios::showpoint) << d1 << endl;
    cout << setiosflags(ios::showpos) << d2 << endl;

    double dd = 123.4567;
    cout << setprecision(2) << dd << endl;
    cout << setprecision(3) << dd << endl;
    cout << setprecision(4) << dd << endl;
    cout << setprecision(5) << dd << endl;

#if 0
setiosflags(ios::scientific)(科学记数法)，此时精度域表示小数位数
setiosflags(ios::fixed)(定点数)，此时精度域表示小数位数
setprecision(2)<<setiosflags(ios::fixed)设置小数的精度;
#endif
    double dd = 123.4567;
    cout << setiosflags(ios::scientific) << dd << endl;
    cout << resetiosflags(ios::scientific);
    cout << setiosflags(ios::fixed) << dd << endl;
    cout << setprecision(2) << setiosflags(ios::fixed) << dd << endl;
}