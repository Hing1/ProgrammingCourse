#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double d1 = 10 / 5, d2 = 22.0 / 7;
    cout << "��ʾС���㡢β������: " << endl;
    cout << d1 << endl;
    cout << setiosflags(ios::showpoint) << d1 << endl;
    cout << setiosflags(ios::showpos) << d2 << endl;

    double dd = 123.4567;
    cout << setprecision(2) << dd << endl;
    cout << setprecision(3) << dd << endl;
    cout << setprecision(4) << dd << endl;
    cout << setprecision(5) << dd << endl;

#if 0
setiosflags(ios::scientific)(��ѧ������)����ʱ�������ʾС��λ��
setiosflags(ios::fixed)(������)����ʱ�������ʾС��λ��
setprecision(2)<<setiosflags(ios::fixed)����С���ľ���;
#endif
    double dd = 123.4567;
    cout << setiosflags(ios::scientific) << dd << endl;
    cout << resetiosflags(ios::scientific);
    cout << setiosflags(ios::fixed) << dd << endl;
    cout << setprecision(2) << setiosflags(ios::fixed) << dd << endl;
}