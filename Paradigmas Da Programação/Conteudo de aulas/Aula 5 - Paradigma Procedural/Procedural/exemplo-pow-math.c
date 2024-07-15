// Bibliotecas utilizadas no código. Neste caso, não esquecer de compilar com -lm
#include <stdio.h>
#include <math.h>

int main() {

	double n;
	
	// Comandos de escrita e leitura
	printf("Digite o número: ");
	scanf("%lf", &n);

	// Imprime a saída formatada com .2lf, assim serão exibidos somente dois dígitos após o ponto (a vírgula).
	printf("O quadrado de %.2lf é %.2lf\n", n, pow(n, 2));

	return 0;
}