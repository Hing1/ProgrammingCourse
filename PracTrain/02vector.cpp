#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<char> a;
    a.insert(a.begin(),'a');
    a.insert(a.begin(),'b');
    a.insert(a.begin(),'c');
    a.insert(a.begin(),'d');

    for (int i = 0; i < a.size(); i++) {
        if(a.at(i) == 'c')
            cout << "CCC" << endl;
    }

    for (int i = 0; i < a.size(); i++) {
        if(a.at(i) == 'c') {
            a.erase(std::begin(a) + i);
            cout << "ddd" << endl;
        }
    }
    for (int i = 0; i < a.size(); i++) {
        if(a.at(i) == 'c')
            cout << "CCC" << endl;
    }

    cout << "end" << endl;
    return 0;
}
