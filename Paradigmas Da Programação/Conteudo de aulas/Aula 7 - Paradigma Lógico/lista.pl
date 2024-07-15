%questao1
pai(joao, maria).
pai(joao, pedro).
pai(joao, marcos).
pai(joao, joana).
pai(pedro, ricardo).
pai(pedro, bruno).
pai(bruno, victor).

%questao2
?- pai(X, ricardo).

%questao3
sexo(joao, masculino).
sexo(maria, feminino).
sexo(pedro, masculino).
sexo(marcos, masculino).
sexo(joana, feminino).
sexo(ricardo, masculino).
sexo(victor, masculino).
sexo(bruno, masculino).

irmao(X, Y) :- pai(Z, X), pai(Z, Y), X \== Y, sexo(X, masculino).
irma(X, Y) :- pai(Z, X), pai(Z, Y), X \== Y, sexo(X, feminino).

%questao4
?- irma(X, bruno).

%questao5
neto(X, Y) :- pai(Y, Z), pai(Z, X), sexo(X, masculino).
neta(X, Y) :- pai(Y, Z), pai(Z, X), sexo(X, feminino).

%questao6
bisneto(X, Y) :- pai(Y, Z), pai(Z, A), pai(A, X), sexo(X, masculino).

%questao7
aluno(roberto).
aluno(roberta).
aluno(anderson).
aluno(alana).

%questao 8
nota(roberto, 8).
nota(roberta, 5).
nota(anderson, 4).
nota(alana, 3).

%questao 9
passou(X) :- aluno(X), nota(X, Y), Y>=7.

%questao 10
frequencia(robeto, 70).
frequencia(roberta, 80).
frequencia(anderson, 100).
frequencia(alana, 99).

passou2(X) :- aluno(X), nota(X, Y), Y>=7, frequencia(X, Z), Z>=75.