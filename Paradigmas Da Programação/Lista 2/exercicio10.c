#include <stdio.h>
#include <stdbool.h>

bool pertence(int array[], int valor,int tamanho) {

    for(int i=0; i< tamanho ; i++){
        if(array[i] == valor){
            return 1;
        }
    }
    return 0;
}

int main() {
    int num1;
    int array[] = {1, 2, 3, 4, 5};
     
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Digite um número: ");
    // esse scanf peguei na net pois não sabia como solicitar info do usuário em "C";
    scanf("%d", &num1);

    if(pertence(array ,num1, tamanho)){
        printf("pertence a estrutura\n");
    }
    else{
        printf("NÃO pertence a estrutura\n");
    }
    return 0;
}
