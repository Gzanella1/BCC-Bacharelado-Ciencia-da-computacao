maior(elefante, cavalo).
maior(cavalo, orangotango).
maior(orangotango, cachorro).
maior(orangotango, macaco).

ehMaior(X, Y) :- maior(X, Y).
ehMaior(X, Y) :- maior(X, Z), ehMaior(Z, Y).
