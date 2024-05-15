#include <stdio.h>

int somaDivisores(int n) {
    int soma = 0; 
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }
    return soma;
}


// metodo que faz as verificações chatas 
int ePerfeito(int num1) {
 if ((somaDivisores(num1) == num1 )) {
        printf("%d  É UM NUMERO PERFEITO!\n", num1);
    } else {
        printf("%d não É.\n", num1);
    }
}

int main() {
    int num1;
    printf("Digite UM número para saber se ele é perfeito: ");
    scanf("%d", &num1);
    ePerfeito(num1);
    return 0;
}
