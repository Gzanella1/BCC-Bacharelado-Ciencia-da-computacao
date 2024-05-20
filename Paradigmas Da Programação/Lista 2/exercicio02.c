#include <stdio.h>

int recursividadeFatorial(int n){
    if(n == 0){
        return 1 ;
    }
    else{
        return n * recursividadeFatorial(n-1);
    }
}

int main() {
    int num1;
    printf("Digite um número para saber o fatoraial: ");
    scanf("%d", &num1);

    int fat= recursividadeFatorial(num1);
    
    printf("o fatorial é: %d\n",fat );

}

