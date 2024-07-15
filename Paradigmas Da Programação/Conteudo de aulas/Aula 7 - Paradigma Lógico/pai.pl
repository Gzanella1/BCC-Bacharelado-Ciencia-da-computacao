pai(joão, otavio).
pai(joão, ricardo).
pai(otavio, pedro).
pai(otavio, rubens).
pai(ricardo, victor).
pai(ricardo, bruno).
avo(X, Z) :- pai(X, Y), pai(Y, Z).
neto(X, Z) :- pai(Z, Y), pai(Y, X).
