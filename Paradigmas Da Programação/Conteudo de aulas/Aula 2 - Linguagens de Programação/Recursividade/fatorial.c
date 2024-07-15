#include <stdio.h>

unsigned int fatorial(unsigned int n) {
	if (n == 0) return 1;
	return n * fatorial(n-1);
}

void main() {
	unsigned int n;
	scanf("%i", &n);
	printf("%i\n", fatorial(n));
}
