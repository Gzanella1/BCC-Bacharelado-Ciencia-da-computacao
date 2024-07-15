#include <stdio.h>

double leNota(unsigned int indice, unsigned int nota) {
	double v;

	do {
		printf("Informe a nota %u do aluno %u: ", nota, indice + 1);
		scanf("%lf", &v);
	} while (v < 0.0 || v > 10.0);

	return v;
}

double calculaMediaFinal(unsigned int n1, unsigned int n2) {
	// Se colocar "2", e não "2.0", deve haver problema na precisão!
	return (n1 + n2) / 2.0;
}

int main() {
	unsigned int quantidadeDeAlunos;
	unsigned int indice;
	
	// Comando de saída e entrada de dados
	printf("São quantos alunos? ");
	scanf("%u", &quantidadeDeAlunos);

	// Declaração de um array cujo tamanho é o dobro da quantidade de alunos
	double notas[quantidadeDeAlunos * 2];

	// Lê as duas notas e cada aluno dentro da repetição
	for (indice = 0; indice < quantidadeDeAlunos; indice++) {
		notas[indice * 2] = leNota(indice, 1);
		notas[indice * 2 + 1] = leNota(indice, 2);
		
		printf("Média final: %.2lf\n", calculaMediaFinal(notas[indice * 2], notas[indice * 2 + 1]));
	}

	return 0;
}