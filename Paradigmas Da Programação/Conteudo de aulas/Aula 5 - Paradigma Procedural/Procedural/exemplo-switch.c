// Bibliotecas utilizadas no código
#include <stdio.h>

// Função principal, agora com retorno inteiro
int main() {

	// Declaração da variável
	unsigned short diaDaSemana;
	
	// Comandos de escrita (printf) e leitura (scanf)
	printf("Digite o dia da semana em números (de 1 a 7): ");
	scanf("%hu", &diaDaSemana);

	switch (diaDaSemana) {
		case 1:
			printf("Domingo");
			break;
		case 2:
			printf("Segunda");
			break;
		case 3:
			printf("Terça");
			break;
		case 4:
			printf("Quarta");
			break;
		case 5:
			printf("Quinta");
			break;
		case 6:
			printf("Sexta");
			break;
		case 7:
			printf("Sábado");
			break;
		default:
			printf("Erro. Você informou outro valor");
	}
	printf("\n");

	// retorno da função main
	return 0;
}