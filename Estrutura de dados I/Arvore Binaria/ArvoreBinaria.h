#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include <iostream>

struct No {
    int chave;
    No* esquerda;
    No* direita;
    No* pai;

    No(int chave) : chave(chave), esquerda(nullptr), direita(nullptr), pai(nullptr) {}
};

class ArvoreBinaria {

public:
    
    No* raiz;

    ArvoreBinaria();
    ~ArvoreBinaria();

    No* obterRaiz();
    No* valorMin(No* noX);
    No* valorMax(No* noX);
    No* sucessor(No* noX);

    void imprimirEmOrdem(No* noAtual);
    void deleteArvore(No* noAtual);

    void inserir(No* no);
    void inserirREC(No*& sub, No* no);  // Certifique-se de que a assinatura está correta

    No* buscarNo(int chave);
    No* buscarDoLivro(int x);
    No* buscarRecursivo(No* sub,int x);
    
    void remover(int valor);
    void suc(int& teste, No* temp);

    void treeDelete(int chave);
    void transplant(No* no, No* aux);



    No* min(No *noX);


};
#endif // ARVOREBINARIA_H
