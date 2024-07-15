#include <stdio.h>

// Função para calcular a soma dos divisores de um número
int somaDivisores(int n) {
    int soma = 0; 
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }
    return soma;
}

// Função para verificar se um número é perfeito
int ePerfeito(int num1) {
    if (num1 <= 0) {
        printf("Por favor, insira um número positivo.\n");
        return -1; // Retorna -1 para indicar erro
    }

    if (somaDivisores(num1) == num1) {
        printf("%d é um número perfeito!\n", num1);
        return 1; // Retorna 1 para indicar que é perfeito
    } else {
        printf("%d não é um número perfeito.\n", num1);
        return 0; // Retorna 0 para indicar que não é perfeito
    }
}

int main() {
    int num1;
    printf("Digite um número para saber se ele é perfeito: ");
    if (scanf("%d", &num1) != 1) {
        printf("Entrada inválida. Por favor, insira um número inteiro.\n");
        return 1; // Encerra o programa com código de erro
    }

    ePerfeito(num1);

    return 0;
}
