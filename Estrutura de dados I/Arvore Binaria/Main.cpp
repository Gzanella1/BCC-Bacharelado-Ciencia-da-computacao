#include <iostream>
#include "ArvoreBinaria.h"

using namespace std;
int main() {
    ArvoreBinaria arvore;

    // Criando alguns nós
    No* no1 = new No(10);
    No* no2 = new No(5);
    No* no3 = new No(15);
    No* no4 = new No(3);
    No* no5 = new No(14);

    // Inserindo os nós na árvore
    arvore.inserirREC(arvore.raiz, no1);
    arvore.inserirREC(arvore.raiz, no2);
    arvore.inserirREC(arvore.raiz, no3);
    arvore.inserirREC(arvore.raiz, no4);
    arvore.inserirREC(arvore.raiz, no5);

    std::cout << "buscando no ";
    

    std::cout << "subarvore valor: " << arvore.buscarNo(3) << "\n " ;
    std::cout << "----------------------------------------"  << "\n " ;
    std::cout << "bus : " << arvore.buscarDoLivro(3) << "\n " ;
    std::cout << "----------------------------------------"  << "\n " ;
    std::cout << "recursivo : " << arvore.buscarRecursivo(arvore.raiz, 3) << "\n " ;



    //arvore.inserir(no1);
    /*
    arvore.inserir(no2);
    arvore.inserir(no3);
    arvore.inserir(no4);
    arvore.inserir(no5);
*/
    // Imprimindo a árvore em ordem
    std::cout << "Árvore em ordem: \n";
    arvore.imprimirEmOrdem(arvore.obterRaiz());
    std::cout << std::endl;

    arvore.treeDelete(15);

    // Imprimindo a árvore em ordem
    std::cout << "Árvore em ordem: \n";
    arvore.imprimirEmOrdem(arvore.obterRaiz());
    std::cout << std::endl;


    std::cout << "----------------------------------------------- \n";
    std::cout << "livro : " << arvore.valorMin(no1)->chave<< "\n " ;

    std::cout << "minimo : " << arvore.min(no1)->chave << "\n " ;


    return 0;
}
