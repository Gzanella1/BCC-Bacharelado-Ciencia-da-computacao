#include <stdio.h>

int main() {

	unsigned int quantidadeDeAlunos;
	unsigned int indice;
	
	printf("São quantos alunos? ");
	scanf("%u", &quantidadeDeAlunos);

	// Declaração do array notas, cujo tamanho é o dobro da quantidade de alunos
	double notas[quantidadeDeAlunos * 2];
	// Declaração do array mediaFinal, cujo tamanho é a quantidade de alunos
	double mediaFinal[quantidadeDeAlunos];

	// Lê as duas notas e cada aluno dentro da repetição
	for (indice = 0; indice < quantidadeDeAlunos; indice++) {
		printf("Informe a nota 1 do aluno %u: ", indice + 1);
		scanf("%lf", &notas[indice * 2]);
		printf("Informe a nota 2 do aluno %u: ", indice + 1);
		scanf("%lf", &notas[indice * 2 + 1]);
		mediaFinal[indice] = (notas[indice * 2] + notas[indice * 2 + 1]) / 2.0;
		printf("Média final: %.2lf\n", mediaFinal[indice]);
	}

	return 0;
}