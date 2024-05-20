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

   while(numPrimosQuantidade < 25) {

       int num = rand()%101;
       if(primo(num)){
           numPrimosQuantidade++;
           printf("Número primo encontrado: %d\n", num);
       }
       numGeradoQuantidade++;
   }
   printf("Quantidade de números gerados: %d\n", numGeradoQuantidade);
   return 0;
}
