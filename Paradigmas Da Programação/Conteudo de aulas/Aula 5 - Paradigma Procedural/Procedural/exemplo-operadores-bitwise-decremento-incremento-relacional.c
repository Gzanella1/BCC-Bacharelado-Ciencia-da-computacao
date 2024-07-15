#include <stdio.h>

int main() {
	int n = 19;
	int r = (n >= 18) ? n-- : n++;

	printf("r = %d.\n", r);
	printf("n = %d.\n", n);
	printf("O valor atual de n é ");

	if (n & 1)
		printf("ím");

	printf("par.\n");

	return 0;
}