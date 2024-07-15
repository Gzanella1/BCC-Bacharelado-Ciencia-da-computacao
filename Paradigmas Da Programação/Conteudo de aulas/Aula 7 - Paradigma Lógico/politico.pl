cidade(blumenau).
cidade(pelotas).
cidade(riogrande).
cidade(fimdomundo).
cidade(indaial)

prefeito(joao, blumenau).
prefeito(jose, riogrande).
prefeito(ana, pelotas).
prefeito(maria, fimdomundo).
prefeito(ariel, indaial).

partido(jose, pa).
partido(joao, pb).
partido(ana, pc).
partido(maria, pd).
partido(ariel, pc).

amigo(X,Y) :- prefeito(X, A),
    prefeito(Y, B),
    not(B==A),
    not(Y==X),
    partido(X, C),
    partido(Y, C).

inimigo(X,Y) :- not(amigo(X,Y)).
