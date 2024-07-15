
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//faz a verificação do nosso 
int array_inteiros(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (!isdigit(array[i])) {
            return 0;
        }
    }
    return 1;
}

int igual(int array[], int tamanho) {
    // variavel auxiliar informando que os indices são iguais
    int indicesIguais= 1;
    // percore a array 
    for(int i=0; i< tamanho; i++){

        if(array[i] != array[0]){
            indicesIguais=0;
            break;
        }
    }
    return indicesIguais;
}




int valida_cpf(int cpF[], int tam) {
    //para fazer o calculo peguei um site na internte 
    //https://www.macoratti.net/alg_cpf.htm
    int soma = 0, digitoV1, digitoV2;


    // Verifica se todas as posições contêm um elemento do tipo int
    if (array_inteiros(cpF, tam)) {
        printf("Aviso: O CPF deve conter exatamente 11 dígitos inteiros.\n");
        return 0;
    }

    if(igual(cpF,tam)){
        printf("todos os valores são iguais\n");
        return 0;
    }

    // Calcula o primeiro dígito verificador
    for (int i = 1; i <= 9; i++) {
        // Começamos utilizando os 9 primeiros dígitos multiplicando-os
        // pela sequência decrescente de 10 à 2 e somamos esse resultado.
        soma += cpF[i - 1] * (11 - i);
    }

    if ((soma % 11) < 2) {
        digitoV1 = 0;
    } else {
        digitoV1 = 11 - (soma % 11);
    }

    // Calcula o segundo dígito verificador
    // antes fizemos o calculo ate os 9 primeiros digitos
    // agora vamos incluir o 10 digito pois ja validamos ele em digitoV1
    soma = 0;
    for (int i = 1; i <= 10; i++) {
        soma += cpF[i - 1] * (12 - i);
    }

    if ((soma % 11) < 2) {
        digitoV2 = 0;
    } else {
        digitoV2 = 11 - (soma % 11);
    }

    // Verifica se os dígitos verificadores estão corretos
    if (cpF[9] == digitoV1 && cpF[10] == digitoV2) {
        return 1;
    } else {
        return 0;
    }
}



int main() {
    char cpf_Char[12];
    int cpf[11];

    printf("Digite o CPF (somente números):");
    scanf("%11s", cpf_Char);
    //fgets(cpf_Char, sizeof(cpf_Char), stdin);

    // Converte os caracteres do CPF de string para inteiros
    for (int i = 0; i < 11; i++) {
        cpf[i] = cpf_Char[i] - '0';
    }

    int tam = sizeof(cpf) / sizeof(cpf[0]);
    if (valida_cpf(cpf, tam)) {
        printf("CPF válido.\n");    
    } else {
        printf("CPF inválido.\n");
    }

    return 0;
}

//metodo 