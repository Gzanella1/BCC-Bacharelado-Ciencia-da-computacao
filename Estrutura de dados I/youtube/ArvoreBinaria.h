#ifndef ARVOREY_H
#define ARVOREY_H

#include <iostream>
#include "Aluno.h"

struct No {
    Aluno aluno;
    No* esquerda;
    No* direita;
    No() : esquerda(nullptr), direita(nullptr) {}
    No(Aluno aluno) : aluno(aluno), esquerda(nullptr), direita(nullptr) {}
};

class ArvoreBinaria {
private:
    No* raiz;

public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void deleteArvore(No* noAtual);

    No* obterRaiz();
    bool estaVazio();
    bool estaCheio();
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void busca(Aluno& aluno, bool& busca);
    void imprimirPreOrdem(No* noAtual);
    void imprimirEmOrdem(No* noAtual);
    void imprimirPosOrdem(No* noAtual);
};

#endif // ARVOREY_H
