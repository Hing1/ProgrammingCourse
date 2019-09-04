#include <stdio.h>

int main() {
    int week = 4;
	int monthDay[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	
    for(int i = 0; i < 12; i++) {
    	printf("\n\nSun Mon Tue Wed Thu Fri Sat\n");
    	int temp = week;
        while (temp--) {
            printf("    ");
        }
    	for(int j = 1; j <= monthDay[i]; j++) {
			printf(" %2d ", j);
			if(week == 6)
				putchar(10);
			week = (week + 1) % 7;
		} 
	}
    return 0;
}