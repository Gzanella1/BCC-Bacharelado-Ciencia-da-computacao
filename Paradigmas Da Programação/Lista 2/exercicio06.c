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
int saoAmigos(int num1, int num2) {
 if ((somaDivisores(num1) == num2 && somaDivisores(num2) == num1)) {
        printf("%d e %d são amigos!\n", num1, num2);
    } else {
        printf("%d e %d não são amigos.\n", num1, num2);
    }
}

int main() {
    int num1, num2;
    printf("Digite DOIS números: ");
    scanf("%d %d", &num1, &num2);

    saoAmigos(num1,num2);

    return 0;
}
