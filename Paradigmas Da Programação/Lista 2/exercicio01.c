#include <stdio.h>

int main() {
    int num1;
    printf("Digite um número para saber o fatoraial: ");
    scanf("%d", &num1);

    int fatorial=1;
    int i=1;

    while (i <= num1) {
      fatorial *=i;
      i++;
    }
    
    printf("o fatorial é: %d", fatorial);

}

