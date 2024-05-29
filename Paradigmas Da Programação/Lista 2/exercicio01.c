#include <stdio.h>
#include <limits.h>

int main()
{
    int num1;
    printf("Digite um número para saber o fatorial: ");

    // Se é um número
    if (scanf("%d", &num1) != 1)
    {
        printf("Entrada inválida. Por favor, insira um número inteiro.\n");
        return 1;
    }

    // Se não é negativo
    if (num1 < 0)
    {
        printf("Número inválido. O fatorial não é definido para números negativos.\n");
        return 1;
    }

    int fatorial = 1;
    for (int i = 1; i <= num1; i++)
    {
        if (fatorial > INT_MAX / i)
        { // overflow
            printf("Erro: o fatorial de %d causa overflow.\n", num1);
            return 1;
        }
        fatorial *= i;
    }

    printf("O fatorial de %d é: %d\n", num1, fatorial);
    return 0;
}
