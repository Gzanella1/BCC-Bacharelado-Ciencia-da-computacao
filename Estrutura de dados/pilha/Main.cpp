#include "Pilha.hpp"
#include <iostream>

int main() {
    Pilha pilha;

    // Testando as operações da pilha
    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    std::cout << "Elemento do topo: " << pilha.top() << std::endl;

    pilha.pop();
    std::cout << "Elemento do topo após desempilhar: " << pilha.top() << std::endl;

    std::cout << "Tamanho da pilha: " << pilha.size() << std::endl;

    while (!pilha.isEmpty()) {
        std::cout << "Desempilhando: " << pilha.top() << std::endl;
        pilha.pop();
    }

    return 0;
}