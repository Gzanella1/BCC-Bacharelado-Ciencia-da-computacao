#include <iostream>
#include <stdexcept>
#include "Item.hpp"

// Classe Pilha
class Pilha {
private:
    Item* topo;  // Ponteiro para o topo da pilha
    int tamanho;  // Número de elementos na pilha

public:
    Pilha() : topo(nullptr), tamanho(0) {}  // Construtor
    ~Pilha() {  // Destrutor para liberar a memória
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int valor) {
       topo= new Item(valor);
       tamanho++;
    }

    void pop() {
        if (isEmpty) {
            cout << "pilha vazia";
        }
        Item* auxiliar= topo;
        topo=topo->proximo;
        delete auxiliar;
        
    }

    int top() const {
        
    }

    bool isEmpty(){
        return topo == 0;
    }

    int size() const {
    }
};


