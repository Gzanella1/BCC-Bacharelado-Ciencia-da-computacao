#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool primo(int num) {
   if (num <= 1) {
       return false;
   }
   if (num <= 3) {
       return true;
   }
   for (int i = 2; i * i <= num; i++) {
       if (num % i == 0)
           return false;
   }
   return true;
}

int main() {
   int numPrimosQuantidade = 0;
   int numGeradoQuantidade = 0;
   int limiteTentativas = 1000000; // Limite de tentativas para evitar loops infinitos

   while(numPrimosQuantidade < 25 && numGeradoQuantidade < limiteTentativas) {

       int num = rand()%101;
       if(primo(num)){
           numPrimosQuantidade++;
           printf("Número primo encontrado: %d\n", num);
       }
       numGeradoQuantidade++;
   }

   if (numPrimosQuantidade < 25) {
       printf("Não foi possível encontrar 25 números primos dentro do limite de tentativas.\n");
   } else {
       printf("Quantidade de números primos encontrados: %d\n", numPrimosQuantidade);
   }
   printf("Quantidade total de números gerados: %d\n", numGeradoQuantidade);
   return 0;
}
