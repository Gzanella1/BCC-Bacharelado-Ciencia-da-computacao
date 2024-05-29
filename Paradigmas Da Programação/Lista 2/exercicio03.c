#include <stdio.h>
#include <stdlib.h> // Para exit() e EXIT_FAILURE

// Função para imprimir a sequência de Fibonacci
void fibonacci(int n) {
    if (n == 0) {
        printf("0\n");
        return;
    }
    unsigned long long int termo_atual = 0, proximo_termo = 1;

    for (int i = 0; i < n; i++) {
        printf("%llu ", termo_atual);
        unsigned long long int temp = proximo_termo;
        proximo_termo = termo_atual + proximo_termo;
        termo_atual = temp;
    }
    printf("\n");
}

int main() {
    int n;

    // Solicita ao usuário o número de termos da sequência de Fibonacci
    printf("Digite o número de termos da sequência de Fibonacci: ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada inválida. Por favor, insira um número inteiro.\n");
        exit(EXIT_FAILURE); // Encerra o programa com código de erro
    }

    // Verifica se o número de termos é positivo
    if (n < 0) {
        printf("Por favor, insira um número inteiro não negativo.\n");
        return 1; // Encerra o programa com código de erro
    }

    // Define um limite superior razoável para evitar longas execuções
    if (n > 93) {
        printf("Número de termos muito grande. O máximo suportado é 93 para evitar overflow.\n");
        return 1; // Encerra o programa com código de erro
    }

    // Imprime a sequência de Fibonacci com n termos
    printf("Sequência de Fibonacci com %d termos:\n", n);
    fibonacci(n);

    return 0;
}
