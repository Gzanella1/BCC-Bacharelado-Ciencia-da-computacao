// Bibliotecas utilizadas no código
#include <stdio.h>

// Função principal, agora com retorno inteiro
int main() {

	// Declaração da variável
	unsigned short diaDaSemana;
	
	// Comandos de escrita (printf) e leitura (scanf). Rotulando o trecho com o identificador "INICIO"
	INICIO:
	printf("Digite o dia da semana em números (de 1 a 7): ");
	scanf("%hu", &diaDaSemana);

	if (diaDaSemana < 1 || diaDaSemana > 7) {
		printf("Erro. Você informou outro valor. Tente novamente.\n");
		goto INICIO; // Procura o rótulo INICIO e salta para este ponto do código.
	}

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
		default:
			printf("Sábado");
	}
	printf("\n");

	// retorno da função main
	return 0;
}