class Pessoa:
    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

pessoa = Pessoa("João", 30)
pessoa = Pessoa("aaa", 30)

# Obtendo os atributos e seus valores
# pelo que entendi como a classe ta "analizando" os atributos 
# se engloba como reflexão
for atributo, valor in pessoa.__dict__.items():
    print(f"Atributo: {atributo}, Valor: {valor}")
