#include <stdio.h>

int numDigitos(int n1) {
    //verificando a unidade 
    if (n1 >= -9 && n1<=9) {
        return 1;
    }else{
        //n1=350
        // n1/10 =35
        // removemos um elemento então +1, da errado se não adicionar
        return numDigitos(n1/10) + 1;
    }
    
    /*tirar duvida com professor:
     se colocar um numero negativo o sinal não conta, ver se é necessario
     pq n foi expecificado na questão 
     */
}


int main() {
    int num1;
    printf("Digite um número: ");
    // esse scanf peguei na net pois não sabia como solicitar info do usuário em "C";
    scanf("%d", &num1);

    int a = numDigitos(num1);
    printf("%d\n",a);
    return 0;
}

