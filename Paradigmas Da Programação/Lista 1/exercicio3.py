from dataclasses import dataclass


@dataclass
class Pessoa:
    nome: str
    idade: int


pessoa1 = Pessoa("João", 30)
match pessoa1:
    case Pessoa(nome="Admin", idade=idade):
        print(f"Admin com idade {idade}")
    case Pessoa(nome=nome, idade=idade):
        print(f"{nome} tem {idade} anos")




