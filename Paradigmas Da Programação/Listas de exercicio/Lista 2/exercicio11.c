#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Função para verificar se um número é primo
bool primo(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int qtde_primos = 0;
    int qtde_gerados = 0;
    int primos[25] = {0}; // Vetor para armazenar os números primos encontrados

    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    while (qtde_primos < 25) {
        int num = rand() % 100 + 1; // Gera um número aleatório entre 1 e 100
        if (primo(num)) {
            // Verifica se o número primo já foi encontrado
            bool encontrado = false;
            for (int i = 0; i < qtde_primos; i++) {
                if (primos[i] == num) {
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                primos[qtde_primos] = num;
                qtde_primos++;
                printf("Número primo encontrado: %d\n", num);
            }
        }
        qtde_gerados++;
    }

    printf("Quantidade de números gerados: %d\n", qtde_gerados);
    return 0;
}
