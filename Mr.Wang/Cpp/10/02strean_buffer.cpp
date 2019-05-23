#include<iostream>
#include<unistd.h>

using namespace std;

#if 0
io对象是有缓冲的
先到缓冲区中，等其满了，在到屏幕上


endl可以刷掉缓冲

#endif

int main() {
    for(int i = 0;i < 1000;i++) {
        cout<<"lkljhghjkl";
        sleep(1);
    }
    cout<<"asdfasg";
    while(1);
    return 0;
}
