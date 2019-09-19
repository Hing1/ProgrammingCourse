#include <iostream>
#include <string.h>

using namespace std;

#if 0
void func(char & ch) {

}
int main() {
    char ch;
	func(ch);

    while ((ch = cin.get()) != EOF) //EOF  input Ctrl + c
        cout.put(ch);
    return 0;
}
#endif

#if 0
int main() {
	char ch;

// The value of the comma expression depends on the last one.
	while(cin.get(ch), !cin.eof())
		cout.put(ch);
	return 0;
}
#endif

#if 0
int main() {
	char a, b, c, d;

	cin.get(a).get(b).get(c).get(d);
	cout << a << b << c << d << endl;

	return 0;
}
#endif

int main() {
	char buf[1024];
//	cin >> buf;
//	cout << buf << endl;

	cin.get(buf, 1024, 'i');
//	cin.get(buf, 1024, '\n');
	cout << "111" << buf << endl;
	
	cin.ignore(1); // Otherwise, the next input cannot be read.
	memset(buf, 0, 1024);
//	cin.get(buf, 10, 'i');  // 9
	cin.get(buf, 1024, 'i');
	cout << "222" << buf << endl;
}

