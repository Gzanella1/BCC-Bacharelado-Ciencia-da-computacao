#include <stdio.h>

int mult(int n1, int n2) {
    // Caso base de parada
    if (n2 == 0 || n1 == 0) {
        return 0;
    } else {
        // Caso recursivo
        return n1 + mult(n1, n2 - 1);
    }
}

int main() {
    int num1, num2;
    printf("Digite DOIS números inteiros: ");
    
    int result = scanf("%d %d", &num1, &num2);

    if (result != 2) {
        printf("Entrada inválida. Por favor, insira dois números inteiros separados por um espaço.\n");
        return 1; // Encerra o programa com código de erro
    }

    int resultado = mult(num1, num2);
    printf("O resultado da multiplicação é: %d\n", resultado);
    
    return 0;
}
