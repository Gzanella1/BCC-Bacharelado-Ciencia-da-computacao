#include <stdio.h>
#include <stdlib.h>

int main() {
	char* nome;
	// Aloca espaço para 99 caracteres, mais um para o caractere nulo de terminação
	nome = (char *)malloc(100 * sizeof(char));
	// A declaração abaixo é equivalente às duas linhas acima e não exige o uso de stdlib.h (pois não usa malloc):
	// char nome[100];
	int idade;
	
	// Comandos de saída e entrada
	// %s = string
	// %i = inteiro
	// %*c = ponteiro para caractere(s)

	printf("Digite seu nome: ");
	// Se o nome não tiver espaço, a leitura pode ser feita com esse comando:
	//scanf("%s", nome);
	// %s lê uma sequência de caracteres até encontrar um espaço em branco, tabulação ou nova linha.
	// %[^\n] lê todos os caracteres da entrada até encontrar um caractere de nova linha (\n).
	scanf ("%[^\n]%*c", nome);

	printf("Digite sua idade: ");
	scanf("%i", &idade);

	printf("%s tem %i anos!\n", nome, idade);
	return 0;
}