// Bibliotecas utilizadas no código
#include <stdio.h>

// Função principal, agora com retorno inteiro
int main() {

	// Variável
	unsigned int numeroSemSinal = 9000000;
	int numeroComSinal = -8000000;
	short valor = 3;
	float salario = 1.79769e+308; // Não cabe, pois excede o limite do tipo float! Troque por 1.175
	double precisao = 1.79769e+308;
	char caractere = 'L';

	// Comandos de escrita, imprimindo o valor de cada variável.
	// O especificador de cada formato é escrito com %[letra]:
	// %u para inteiro sem sinal
	// %i para inteiro
	// %hi para inteiro pequeno
	// %f para número real de ponto flutuante
	// %lf para número real de ponto flutuante longo ou com dupla precisão
	// %c pra caractere
	printf("Valor: %u\n", numeroSemSinal);
	printf("Valor: %i\n", numeroComSinal);
	printf("Valor: %hi\n", valor);
	printf("Valor: %f\n", salario);
	printf("Valor: %lf\n", precisao);
	printf("Caractere: %c\n", caractere);
	
	return 0;
}