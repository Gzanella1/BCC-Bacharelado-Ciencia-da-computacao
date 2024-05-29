#include <stdio.h>
#include <stdlib.h> // necessário para a função exit()

// Função para calcular o número de dígitos de um número inteiro
int numDigitos(int n1) {
    // Caso base: quando o número tem apenas um dígito
    if (n1 >= -9 && n1 <= 9) {
        return 1;
    }
    // Caso recursivo: incrementa o contador e chama a função com o número dividido por 10
    return 1 + numDigitos(n1 / 10);
}

int main() {
    int num1;
    printf("Digite um número inteiro: ");
    // Lê a entrada do usuário
    if (scanf("%d", &num1) != 1) {
        printf("Entrada inválida. Por favor, insira um número inteiro.\n");
        exit(EXIT_FAILURE); // Encerra o programa com código de erro
    }

    int numDigitosResult = numDigitos(num1);
    printf("O número de dígitos de %d é: %d\n", num1, numDigitosResult);
    return 0;
}
