#include <stdio.h>

enum Day {
    Mon, Tue = 2, Wed, Thu = 100, Fri, Sat, Sun
};

int main()
{
    printf("Mon = %d\n", Mon);
    printf("Tue = %d\n", Tue);
    printf("Wed = %d\n", Wed);
    printf("Thu = %d\n", Thu);
    printf("Fri = %d\n", Fri);
    printf("Sat = %d\n", Sat);
    printf("Sun = %d\n", Sun);
    
    enum Day d;
    d = Mon;
    d = 1111;// ��C�����п��ԣ���C++�в�����
    return 0;
}
