// Bibliotecas utilizadas no código
#include <stdio.h>

// Função principal, agora com retorno inteiro
int main() {

	// Declaração da variável
	int numero;
	
	// Comandos de escrita (printf) e leitura (scanf)
	printf("Digite um número: ");
	scanf("%i", &numero);

	// Imprime a resposta no formato: <numero> [não ]é par.
	printf("%i ", numero);

	if (numero % 2)
		printf("não ");

	printf("é par\n");

	// retorno da função main
	return 0;
}