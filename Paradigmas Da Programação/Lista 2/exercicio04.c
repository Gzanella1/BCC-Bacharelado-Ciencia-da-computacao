#include <stdio.h>
#include <limits.h>

// Função auxiliar recursiva de cauda com verificação de overflow
unsigned long int fibonacciRecursivo(int termosRestantes, unsigned long int atual, unsigned long int proximo, int* overflowFlag) {
    if (termosRestantes == 0) {
        return atual;
    }
    if (proximo > ULONG_MAX - atual) {
        *overflowFlag = 1;
        return 0;
    }
    return fibonacciRecursivo(termosRestantes - 1, proximo, atual + proximo, overflowFlag);
}

// Função principal recursiva para calcular Fibonacci
unsigned long int calcularFibonacci(int numTermos, int* overflowFlag) {
    return fibonacciRecursivo(numTermos, 0, 1, overflowFlag);
}

int main() {
    int num;
    printf("Digite um número: ");
    
    // Verificação de entrada
    if (scanf("%d", &num) != 1) {
        printf("Entrada inválida. Por favor, insira um número inteiro.\n");
        return 1;
    }

    if (num < 0) {
        printf("Número inválido. Por favor, insira um número inteiro não negativo.\n");
        return 1;
    }

    int overflowFlag = 0;
    unsigned long int resultado = calcularFibonacci(num, &overflowFlag);
    
    if (overflowFlag) {
        printf("Erro: o cálculo de Fibonacci para %d causa overflow.\n", num);
    } else {
        printf("O Fibonacci de %d é %lu.\n", num, resultado);
    }

    return 0;
}
