#include <stdio.h>

int main() {
	FILE * fp = fopen("01data.csv", "w");
	fputs("name ID score", fp);
	fclose(fp);
	return 0;
}