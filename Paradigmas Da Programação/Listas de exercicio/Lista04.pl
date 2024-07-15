pai (joao, maria).
pai(joao, pedro) .
pai (joao, marcos).
pai(joao, joana).
pai (pedro, ricardo).
pal (pedro, bruno ).
pai (bruno, victor).

% Exercicio 02

?- pai(X, ricardo).


% Exercicio 03

sexo (joao, masculino).
sexo (pedro, masculino).
sexo (marcos, masculino).
sexo (ricardo, masculino).
sexo (bruno, masculino).
sexo (victor, masculino).
sexo (maria, feminino).
sexo (joana, feminino).

irmao(X,Y) :-
    pai (Z,X) ,
    pai (Z,X) ,
    X \== Y,       % PARA OS CASOS ONDE X E IGUAL A Y 
    sexo (X, masculino).


irma(X,Y) : -
    pai (Z,X) ,
    pai (Z,X) ,
    X \== Y,
    sexo(X,feminino).


% Exercicio 04

? - irmao(X, bruno).


% Exercicio 05

neto(X, Y):-
    pai (Y,Z),
    pai (Z,X),
    X \== Y,
    sexo (X, masculino).

neta(X, Y): -
    pai (Y,Z),
    pai (Z,X)
    X \== Y,
    sexo (X, feminino) .


% Exercicio 06

bisneto(X, Y)
    pai (Y,Z),
    pal (Z,T) ,
    pai (T,X),
    sexo (X, masculino) .


% Exercicio 07

aluno(giovani). 
aluno(sofia).
aluno(pedro) .
aluno(matheus) .


% Exercicio 08

nota(giovani, 10).
nota(sofia, 0). 
nota(pedro, 2) . 
nota(matheus, 3) .


% Exercicio 09

passou(X) :-
    aluno(X),
    nota(X,Y) ,
    Y >= 7.

% Exercicio 10

frequencia(giovani, 100).
frequencia (sofia, 0).
frequencia (pedro, 75) .
frequencia (matheus, 50) .

passou2(X) :-
    passou(X) ,
    frequencia(X,Y),
    Y>=75.






