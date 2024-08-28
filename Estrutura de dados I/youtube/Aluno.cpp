#include "Aluno.h"

Aluno::Aluno() : ra(-1), nome("") {}

Aluno::Aluno(int ra, std::string nome) : ra(ra), nome(nome) {}

std::string Aluno::obterNome() {
    return nome;
}

int Aluno::obterRa() {
    return ra;
}
