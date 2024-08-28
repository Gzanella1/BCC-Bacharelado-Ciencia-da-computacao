#include "ArvoreBinaria.h"
#include "Aluno.h"

int main() {
    ArvoreBinaria arvore;

    Aluno a(15, "a");
    Aluno b(20, "b");
    Aluno c(2, "c");
    Aluno d(10, "d");

    arvore.inserir(a);
    arvore.inserir(b);
    arvore.inserir(c);
    arvore.inserir(d);

    arvore.imprimirEmOrdem(arvore.obterRaiz());

    return 0;
}
