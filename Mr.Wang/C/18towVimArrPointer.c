#include <stdio.h>

void func(int (*p)[4], int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%3d",p[i][j]);
        }
        putchar(10);
    }
}

int main() {
    int arr[3][4] = {{1},{2,3},{4,5,6}};
    func(arr, 3);
    return 0;
}