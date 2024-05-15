#include <stdio.h>

int mult(int n1, int n2) {
    // caso base de parada
    if(n2 == 0 || n1==0){
        return 0;
    }
    else{
        // caso recursivo- logica para tentar fazer
        // 2 * 3 é equivalente a : 3+3 =6
        // n2 é a quantidade de vezes que n1 vai repetir 
        return n1+mult(n1,n2-1);
    }
}


int main() {
    int num1, num2;
    printf("Digite DOIS números: ");
    // esse scanf peguei na net pois não sabia como solicitar info do usuário em "C";
    scanf("%d %d", &num1, &num2);

    int a= mult(num1,num2);
    printf("%d\n",a);
    return 0;
}
