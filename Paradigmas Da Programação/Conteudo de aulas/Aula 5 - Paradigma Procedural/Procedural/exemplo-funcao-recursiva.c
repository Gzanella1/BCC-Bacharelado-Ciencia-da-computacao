#include <stdio.h>

unsigned int somaValores(unsigned int n) {
	if (n == 0)
		return 0;
	return n + somaValores(n-1);
}

int main() {
	unsigned int numero;
	
	printf("Digite um número não negativo: ");
	scanf("%u", &numero);

	printf("A soma de valores de 0 até %u é %u\n", numero, somaValores(numero));

	return 0;
}