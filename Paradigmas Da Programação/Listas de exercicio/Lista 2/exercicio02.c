#include <stdio.h>
#include <limits.h>

// Função recursiva auxiliar para calcular o fatorial com verificação de overflow c/ tail recursion
int fatorialHelper(int n, int acumulador, int *overflowFlag)
{
    if (n == 0)
    {
        return acumulador;
    }
    if (acumulador > INT_MAX / n)
    {
        *overflowFlag = 1;
        return 0;
    }
    return fatorialHelper(n - 1, acumulador * n, overflowFlag);
}

// Função principal para calcular o fatorial
int fatorial(int n, int *overflowFlag)
{
    return fatorialHelper(n, 1, overflowFlag);
}

int main()
{
    int num1;
    printf("Digite um número para saber o fatorial: ");

    // se é um número inteiro
    if (scanf("%d", &num1) != 1)
    {
        printf("Entrada inválida. Por favor, insira um número inteiro.\n");
        return 1;
    }

    // se não é negativo
    if (num1 < 0)
    {
        printf("Número inválido. O fatorial não é definido para números negativos.\n");
        return 1;
    }

    // verifica o overflow
    int overflowFlag = 0;
    int fat = fatorial(num1, &overflowFlag);

    if (overflowFlag)
    {
        printf("Erro: o fatorial de %d causa overflow.\n", num1);
    }
    else
    {
        printf("O fatorial de %d é: %d\n", num1, fat);
    }

    return 0;
}
