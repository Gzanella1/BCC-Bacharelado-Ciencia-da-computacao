#include <stdio.h>

unsigned int somaValores(unsigned int n) {
	int resposta = 0;
	while (n > 0) {
		resposta = resposta + n;
		n--;
	}

	return resposta;
}

int main() {
	unsigned int numero;
	
	printf("Digite um número não negativo: ");
	scanf("%u", &numero);

	printf("A soma de valores de 0 até %u é %u\n", numero, somaValores(numero));

	return 0;
}