// Bibliotecas utilizadas no código
#include <stdio.h>

// Função principal, agora com retorno inteiro
int main() {

	// Declaração da variável
	short indice = 10;

	do {
		printf("%hi\n", indice--);
	} while (indice >= 0); // aqui é necessário ";"

	// retorno da função main
	return 0;
}