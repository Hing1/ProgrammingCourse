#include <iostream>

using namespace std;

void func(int a) throw(int, float, double) {
    if(a > 1)
        throw (int)a;
    else if(a < 1)
        throw (float)a;
    else
        throw (double)a;
}

int main() {
    try {
        func(1);
    } catch (int e) {
        cout << "int" << endl;
    } catch (float e) {
        cout << "float" << endl;
    } catch (double e) {
        cout << "double" << endl;
    }
    return 0;
}
