#include <stdio.h>

// Diretivas define aproveitadas para definir valores
#define TAM 256
#define AULAS 4
#define ALUNOS 2

int main() {

	char nome[ALUNOS][TAM];
	int presencas[ALUNOS][AULAS];
	int indiceLinha;
	int indiceColuna;
	int contadorDeFaltas;

	for (indiceLinha = 0; indiceLinha < ALUNOS; indiceLinha++) {

		printf("Informe seu nome: ");
		scanf("%s", nome[indiceLinha]);

		for (indiceColuna = 0, contadorDeFaltas = 0; indiceColuna < AULAS; indiceColuna++) {

			printf("Presença (0) ou Ausência (1) na aula %i? ", indiceColuna + 1);
			scanf("%i", &presencas[indiceLinha][indiceColuna]);

			contadorDeFaltas += presencas[indiceLinha][indiceColuna];
		}

		printf("%s teve %i falta(s).\n", nome[indiceLinha], contadorDeFaltas);
	}

	return 0;
}