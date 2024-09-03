#include <iostream>
#include <cstddef>
#include "ArvoreBinaria.h"

// Constructor
ArvoreBinaria::ArvoreBinaria() : raiz(nullptr) {}

ArvoreBinaria::~ArvoreBinaria()
{
    deleteArvore(raiz);
}

No *ArvoreBinaria::obterRaiz()
{
    return raiz;
}

// Returns the minimum value in the binary tree starting from the given node.
No *ArvoreBinaria::valorMin(No *noX)
{
    while (noX->esquerda != nullptr)
    {
        noX = noX->esquerda;
    }
    return noX;
}


No *ArvoreBinaria::min(No *noX)
{
    No* aux= noX;
    while (aux->esquerda != nullptr)
    {
        aux = aux->esquerda;
    }
    return aux;
}





No *ArvoreBinaria::valorMax(No *noX)
{
    while (noX->direita != nullptr)
    {
        noX = noX->direita;
    }
    return noX;
}

No *ArvoreBinaria::sucessor(No *noX)
{
    if (noX->direita != nullptr)
    {
        return valorMin(noX->direita);
    }
    else
    {
        No *aux = noX->pai;
        while (aux != nullptr && noX == aux->direita)
        {
            noX = aux;
            aux = noX->pai;
        }
        return aux;
    }
}

void ArvoreBinaria::inserir(No *no)
{
    // ponteiro acompanhante  como pai de subTAux
    No *acom_PAI_ante = nullptr;
    // para percorer a arvore, e procura uma direção nula
    // ao final sub arvore fica null
    No *subArvore = raiz;

    // no while faz com que os dois ponteiros se desloquem para baixo da arvore
    // indo para esquerda ou direita ate subtAux ser igual a null
    // esse null vai ser onde o NO vai ser inserido, mas o subarvore não tem involvimento na inserção
    // subarvore so auxilia a procurar o lugar
    while (subArvore != nullptr)
    {
        // Atualiza o ponteiro acompanhante para o nó atual antes de descer na árvore

        // colocamos o acompanhante receber a subarvore pois quando a subarvore receber o null
        // o acompanhante vai ser o "pai" do suposto null exemplo:  no 15 aponta a esquerda para o nul
        // quero inserir o 13 então o 15 será o acompanhante e o 15.esquerda = null que será a subarvore
        acom_PAI_ante = subArvore;
        // verifica se é esquerda ou direita
        if (subArvore->chave > no->chave)
        {
            subArvore = subArvore->esquerda;
        }
        else
        {
            subArvore = subArvore->direita;
        }
    }
    // Define o pai do novo nó como o último nó não-nulo encontrado (acom_PAI_ante)
    // o no abaixo, ex "13" vai ser inserido em um dos lados do acompanhante ex:
    // acompanhante é 15 então 13 vai ser inserido a esquerda;
    no->pai = acom_PAI_ante;

    // se não tiver raiz, ou o pai desse no for null
    if (acom_PAI_ante == nullptr)
    {
        raiz = acom_PAI_ante;
    }
    // se não e null
    // então temos que inserir a esquerda ou a direita de acom_PAI_ante
    else if (acom_PAI_ante->chave > no->chave)
    {
        acom_PAI_ante->esquerda = no;
    }
    else
    {
        acom_PAI_ante->direita = no;
    }
}

void ArvoreBinaria::inserirREC(No *&sub, No *no)
{
    // Se o ponteiro sub é nullptr, significa que encontramos a posição para inserir o novo nó
    if (sub == nullptr)
    {
        // Definimos sub para apontar para o novo nó
        sub = no;
    }
    else
    {
        // Definimos o pai do novo nó para ser o nó atual (sub)
        no->pai = sub;
        // Se a chave do nó atual é maior que a chave do novo nó
        if (sub->chave > no->chave)
        {
            // Chamamos recursivamente para a subárvore esquerda
            inserirREC(sub->esquerda, no);
            // Se a chave do nó atual é menor ou igual à chave do novo nó
        }
        else
        {
            // Chamamos recursivamente para a subárvore direita
            inserirREC(sub->direita, no);
        }
    }
}

No *ArvoreBinaria::buscarNo(int chave)
{

    No *subArvore = raiz;

    while (subArvore != nullptr)
    {
        if (subArvore->chave == chave)
        {
            return subArvore;
        }
        else
        {
            if (subArvore->chave > chave)
            {
                subArvore = subArvore->esquerda;
            }
            else
            {
                subArvore = subArvore->direita;
            }
        }
    }
    return subArvore;
}

No *ArvoreBinaria::buscarDoLivro(int x)
{
    No *raiz = this->raiz;
    while (raiz != NULL && x != raiz->chave)
    {
        if (x < raiz->chave)
        {
            raiz = raiz->esquerda;
        }
        else
        {
            raiz = raiz->direita;
        }
    }
    return raiz;
}

No *ArvoreBinaria::buscarRecursivo(No *sub, int x)
{
    // Caso base - caso de "parada"
    if (sub == NULL || sub->chave == x)
    {
        return sub;
    }
    // caso não encontre null ou o valor x, desce a arvore
    if (sub->chave > x)
    {
        return buscarRecursivo(sub->esquerda, x);
    }
    else
    {
        return buscarRecursivo(sub->esquerda, x);
    }
}

void ArvoreBinaria::imprimirEmOrdem(No *noAtual)
{
   
}

void ArvoreBinaria::deleteArvore(No *noAtual)
{
    if (noAtual != nullptr)
    {
        deleteArvore(noAtual->esquerda);
        deleteArvore(noAtual->direita);
        delete noAtual;
    }
}

// Método para deletar um nó com uma chave específica em uma árvore binária de busca
void ArvoreBinaria::treeDelete(int chave)
{
    // Encontrar o nó com a chave fornecida
    No *no = buscarNo(chave);

    // Se o filho esquerdo do nó for nulo, substitua o nó pelo seu filho direito
    if (no->esquerda == NULL)
    {
        transplant(no, no->direita);
    }
    // Se o filho direito do nó for nulo, substitua o nó pelo seu filho esquerdo
    else if (no->direita == NULL)
    {
        transplant(no, no->esquerda);
    }
    // Se o nó tiver ambos os filhos (esquerdo e direito)
    else
    {
        // Encontrar o nó mínimo na subárvore direita
        No *y = sucessor(no->direita);

        if (y->pai != no)
        {
            // Substituir o nó mínimo pelo seu filho direito
            // Transplanta o nó `y` (17) pelo seu filho direito (18)
            transplant(y, y->direita);

            // Definir o filho direito do nó mínimo como o filho direito do nó a ser deletado
            // Faz `y->direita` (que era 17) apontar para o antigo filho direito de `no` (que é 20)
            y->direita = no->direita;
            // Definir o pai do filho direito como o nó mínimo
            // Faz o pai de `y->direita` (20) ser `y` (17)
            y->direita->pai = y;
        }

        // Substituir o nó a ser deletado pelo nó mínimo
        transplant(no, y);
        // Definir o filho esquerdo do nó mínimo como o filho esquerdo do nó a ser deletado
        y->esquerda = no->esquerda;
        // Definir o pai do filho esquerdo como o nó mínimo
        y->esquerda->pai = y;
    }
}

// Método para substituir uma subárvore por outra em uma árvore binária de busca
void ArvoreBinaria::transplant(No *no, No *subArvore)
{
    // Se o nó a ser substituído for a raiz, definir a raiz como o novo nó
    if (no->pai == NULL)
    {
        raiz = subArvore;
    }
    // Se o nó a ser substituído for o filho esquerdo de seu pai, definir o filho esquerdo do pai como o novo nó
    else if (no == no->pai->esquerda)
    {
        no->pai->esquerda = subArvore;
    }
    // Se o nó a ser substituído for o filho direito de seu pai, definir o filho direito do pai como o novo nó
    else
    {
        no->pai->direita = subArvore;
    }

    // Se o novo nó não for nulo, definir seu pai como o pai do nó a ser substituído
    if (subArvore != nullptr)
    {
        subArvore->pai = no->pai;
    }
}
