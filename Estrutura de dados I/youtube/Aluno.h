#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    int ra;
    std::string nome;

public:
    Aluno();
    Aluno(int ra, std::string nome);
    std::string obterNome();
    int obterRa();
};

#endif // ALUNO_H
