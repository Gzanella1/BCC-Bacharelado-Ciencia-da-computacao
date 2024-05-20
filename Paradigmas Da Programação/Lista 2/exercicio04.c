#include <stdio.h>


int fibonacci(int num){
   if (num < 0) {
       return -1;
   } else if (num == 0 || num == 1){
       return 1;
   } else {
       return fibonacci(num -1) + fibonacci(num -2);
    }
}


int main() {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);

    int resultado = fibonacci(num);
    printf("O fibonacci de %d termos é %ld.\n", num, resultado);
    return 0;
}
