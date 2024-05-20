#include "Item.hpp"

// Classe Pilha
class Pilha {
public:
    Item* topo;  // Ponteiro para o topo da pilha
    int tamanho;  // Número de elementos na pilha

    void push(int valor); 
    
    void pop();
    
    int top() const ;
        
    bool isEmpty();
    
    int size() const ;
    
};