#include <stdio.h>
#include <stdlib.h> // necessário para a função exit()

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





// Função para verificar se dois números são amigos
int saoAmigos(int num1, int num2) {
    if (num1 <= 0 || num2 <= 0) {
        printf("Por favor, insira números positivos.\n");
        return -1; // Retorna -1 para indicar erro
    }
    
    if (somaDivisores(num1) == num2 && somaDivisores(num2) == num1) {
        printf("%d e %d são amigos!\n", num1, num2);
        return 1; // Retorna 1 para indicar que são amigos
    } else {
        printf("%d e %d não são amigos.\n", num1, num2);
        return 0; // Retorna 0 para indicar que não são amigos
    }
}

int main() {
    int num1, num2;
    printf("Digite DOIS números: ");
    int result = scanf("%d %d", &num1, &num2);

    // Verifica se a entrada foi inválida (por exemplo, letras)
    if (result != 2) {
        printf("Entrada inválida. Por favor, insira dois números inteiros.\n");
        exit(EXIT_FAILURE); // Encerra o programa com código de erro
    }

    int resultado = saoAmigos(num1, num2);

    if (resultado == -1) {
        return 1; // Encerra o programa com código de erro se os números forem negativos
    }

    return 0;
}
