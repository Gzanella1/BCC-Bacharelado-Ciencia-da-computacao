#include <stdio.h>

// Definição da macro QUADRADO
#define QUADRADO(n) ((n) * (n))

int main() {
    int n = 5;

    // Uso da macro definida
    int quadrado = QUADRADO(n);
    
    printf("%d ao quadrado é %d.\n", n, quadrado);
    
    // Emitindo um aviso durante a compilação
    #warning "Aviso de teste."
    
    return 0;
}