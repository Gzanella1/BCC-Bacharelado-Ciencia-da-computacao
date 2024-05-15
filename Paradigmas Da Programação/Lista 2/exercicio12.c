#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int valida_cpf(char *cpf) {
    int soma = 0, digitoV1, digitoV2;
    int cpF[11];

    // Verifica se o CPF tem 11 dígitos
    if (strlen(cpf) != 11) {
        return 0;
    }

    // Calcula o primeiro dígito verificador
    for(int i=0; i < 9;i++){
        // Começamos utilizando os 9 primeiros dígitos multiplicando-os 
        // pela sequência decrescente de 10 à 2 e somamos esse resultado.
        soma += cpF[i] * (10-i);
    }
    
    if((soma % 11) < 2){
        digitoV1= 0;
    }
    digitoV1= 11 - (soma % 11);


    // Calcula o segundo dígito verificador
    // antes fizemos o calculo ate os 9 primeiros digitos 
    // agora vamos incluir o 10 digito pois ja validamos ele em digitoV1
    soma =0;
    for(int i=0; i <10 ;i++){
        soma += cpF[i] * (11-i);
    }
      if((soma % 11) < 2){
        digitoV2= 0;
    }
    digitoV2= 11 - (soma % 11);



    // Verifica se os dígitos verificadores estão corretos
    if (cpF[09] == digitoV1 && cpF[10] == digitoV2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // sites que ensinam o calculo matematico pra verificar a validade;
    // https://www.macoratti.net/alg_cpf.htm
    // https://www.campuscode.com.br/conteudos/o-calculo-do-digito-verificador-do-cpf-e-do-cnpj
    char cpf[12];
    printf("Digite o CPF (somente números): ");
    scanf("%s", cpf);

    if (valida_cpf(cpf)) {
        printf("CPF válido.\n");
    } else {
        printf("CPF inválido.\n");
    }

    return 0;
}