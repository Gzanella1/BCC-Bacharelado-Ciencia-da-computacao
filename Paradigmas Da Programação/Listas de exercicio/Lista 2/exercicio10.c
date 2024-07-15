#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um valor pertence a um array
bool pertence(int array[], int valor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == valor) {
            return true;
        }
    }
    return false;
}

int main() {
    int num1;
    int array[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Digite um número: ");
    if (scanf("%d", &num1) != 1) {
        printf("Entrada inválida. Por favor, insira um número inteiro.\n");
        return 1; // Encerra o programa com código de erro
    }

    if (pertence(array, num1, tamanho)) {
        printf("O número pertence à estrutura.\n");
    } else {
        printf("O número NÃO pertence à estrutura.\n");
    }

    return 0;
}
