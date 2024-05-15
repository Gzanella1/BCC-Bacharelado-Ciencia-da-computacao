#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void calcularDigitosVerificadores(char cpf[], int *digito1, int *digito2) {
    int i, j;
    int digitos[11];

    // Remover caracteres não numéricos do CPF
    int tam = strlen(cpf);
    for (i = 0, j = 0; i < tam; i++) {
        if (isdigit(cpf[i])) {
            digitos[j++] = cpf[i] - '0';
        }
    }

    // Calcular primeiro dígito verificador
    int soma = 0;
    for (i = 0; i < 9; i++) {
        soma += digitos[i] * (10 - i);
    }
    *digito1 = 11 - (soma % 11);
    if (*digito1 >= 10) {
        *digito1 = 0;
    }

    // Calcular segundo dígito verificador
    soma = 0;
    for (i = 0; i < 10; i++) {
        soma += digitos[i] * (11 - i);
    }
    *digito2 = 11 - (soma % 11);
    if (*digito2 >= 10) {
        *digito2 = 0;
    }
}

int main() {
    char cpf[] = "102.461.259-57"; // Exemplo de CPF sem dígitos verificadores
    int digito1, digito2;

    calcularDigitosVerificadores(cpf, &digito1, &digito2);

    printf("Primeiro dígito verificador: %d\n", digito1);
    printf("Segundo dígito verificador: %d\n", digito2);

    return 0;
}

