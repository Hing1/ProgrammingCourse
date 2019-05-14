#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n - 1; i++)
    {
        double a;
        cin >> a;
        cout << a << endl;
        cout.setf(ios::fixed);
        cout << a << endl;
        cout.unsetf(ios::fixed);
    }
}