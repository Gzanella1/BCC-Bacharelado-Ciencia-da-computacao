#include <iostream>
#include <cstddef>
#include "ArvoreBinaria.h"

ArvoreBinaria::ArvoreBinaria(){
    raiz = nullptr;
}

ArvoreBinaria::~ArvoreBinaria(){
    deleteArvore(raiz);
}

void ArvoreBinaria::deleteArvore(No* noAtual){
    if (noAtual != nullptr) {
        deleteArvore(noAtual->esquerda);
        deleteArvore(noAtual->direita);
        delete noAtual;
    }
}

No* ArvoreBinaria::obterRaiz(){
    return raiz;
}

bool ArvoreBinaria::estaCheio(){
    try {
        No* temp = new No();
        delete temp;
        return false;
    } catch(std::bad_alloc& exception) {
        return true;
    }
}

bool ArvoreBinaria::estaVazio(){
    return (raiz == nullptr);
}

void ArvoreBinaria::inserir(Aluno alunoP){
    if (estaVazio()) {
        No* novo = new No(alunoP);
        raiz = novo;
    } else {
        if (estaCheio()) {
            std::cout << "Erro: a árvore está cheia." << std::endl;
        } else {
            No* subArTemp = raiz;
            No* novo = new No(alunoP);
            while (subArTemp != nullptr) {
                if (subArTemp->aluno.obterRa() < alunoP.obterRa()) {
                    if (subArTemp->direita == nullptr) {
                        subArTemp->direita = novo;
                        break;
                    } else {
                        subArTemp = subArTemp->direita;
                    }
                } else {
                    if (subArTemp->aluno.obterRa() > alunoP.obterRa()) {
                        if (subArTemp->esquerda == nullptr) {
                            subArTemp->esquerda = novo;
                            break;
                        } else {
                            subArTemp = subArTemp->esquerda;
                        }
                    }
                }
            }
        }
    }
}

void ArvoreBinaria::remover(Aluno aluno) {
    // Implementar remoção
}

void ArvoreBinaria::busca(Aluno& aluno, bool& busca) {
    // Implementar busca
}

void ArvoreBinaria::imprimirPreOrdem(No* noAtual) {
    // Implementar impressão pré-ordem
}

void ArvoreBinaria::imprimirEmOrdem(No* noAtual) {
    if (noAtual == nullptr) return;
    imprimirEmOrdem(noAtual->esquerda);
    std::cout << noAtual->aluno.obterNome() << std::endl;
    imprimirEmOrdem(noAtual->direita);
}

void ArvoreBinaria::imprimirPosOrdem(No* noAtual) {
    // Implementar impressão pós-ordem
}








/*


    void inserir(Aluno alunoP){
        if (estaCheio){
            cout << "arvore cheia \n";
        }
        else{
            //cria um novo no 
            No* noNovo = new No;
            // faz atrubuição ao novo no
            noNovo->aluno= alunoP;
            noNovo->direita = NULL;
            noNovo->esquerda = NULL;

            // O NÓ APONTA PRA QUEM ?
            // se está vazio, então é o primeiro nó logo é a RAIZ  
            if(estaVazio){
                raiz = noNovo;
            }
            // se ja tem nó, verificar onde incluir o no novo
            else{
                // variavel auxiliar, que recebe a raiz
                // essa variavel vai sendo atualizada com as SUBARVORES
               No* temp= raiz;
               // percore enquanto esse temp for diferente de null 
               while (temp != NULL){
                    // se o valor do rA do noNovo for menor qeu a o valor ra que ta na variavel temp, que percore as SUBARVORE
                    if(alunoP.obterRa() < temp->aluno.obterRa){
                        // como é menor trabalhamos com a direção esquerda
                        // se a variavel temp a esquerda for nula, então armazenamos o novo no ali 
                        if(temp->esquerda == null){
                            temp->esquerda= noNovo;
                            break;
                        }
                        else{
                            // se não for nulo, tem algum no, que pode ser uma subarvore 
                            // então atualizamos o valor de temp, pra o no de uma suposta subarvore
                            temp= temp->esquerda;
                        }
                    // se não for menor então ele vai para a direita     
                    }else{
                        //verifica se a direita for nulo, se sim ja armazena o novo nó
                        if(temp->direita == NULL){
                            temp->direita=noNovo;
                            break;
                        }else{
                            // se não for nulo, tem algum no, que pode ser uma subarvore 
                            // então atualizamos o valor de temp, pra o no de uma suposta subarvore,
                            // ate perocorer toda a arvore com o while
                            temp= temp->direita;
                        }
                    }
               }                
            }
        }
    }
    
    
     */