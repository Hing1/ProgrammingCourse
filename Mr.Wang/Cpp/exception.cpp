#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

#if 0
int alloc(char * &p) {
//    C语言中的异常
    p = (void*)malloc(100);
    if(p != nullptr)
        return 1;
    else
        return 0;
}

int main() {
    char * p;
    alloc(p);
    return 0;
}
#endif

class A {
public:
    A(int a, int b, int c)
        :x(a), y(b), z(c){}
    int x;
    int y;
    int z;
};

double triangle(double x, double y, double z) {
    double area;
    double s = (x + y + z) / 2;
    if(x + y > z && x + z > y && y + z > x)
        area = sqrt(s * (s - x) * (s - y) * (s - z));
    else
        throw A(x, y, z);
    return area;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    try {
        while (a > 0 && b > 0 && c > 0) {
            cout << triangle(a, b, c) << endl;
            cin >> a >> b >> c;
        }
    } catch (int e) {
        cout << "Catch a exception. " << e << endl;
    } catch (float e) {
        cout << "Catch a exception. " << e << endl;
    } catch (char e) {
        cout << "Catch a exception. " << e << endl;
    } catch (double e) {
        cout << "Catch a exception. " << e << endl;
    } catch (A e) {
        cout << "Catch a exception. " << endl;
        cout << e.x << e.y << e.z << endl;
    } catch (...) {
        cout << "Catch default. " << endl;
    }
}
