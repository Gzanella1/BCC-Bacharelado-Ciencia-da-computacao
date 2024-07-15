import random

def gera_numeros_cartela_bingo():
    b="BINGO"
    start=1
    end=15
    dicionario={}
    for letras in b:
        numerosAleatorios=random.sample(range(start, end), 5)
        dicionario[letras]=numerosAleatorios
        start+=15
        end+=15
    imprime_cartela(dicionario)
    
def imprime_cartela(cartela):
    print("------------------------------------------")
    print("|   B","       I","      N","      G","      O   |",)
    print("------------------------------------------")
    for i in range(5):
        print("| ",cartela["B"][i],"\t",
            "| ",cartela["I"][i],"\t",
           "| ", cartela["N"][i],"\t",
           "| ", cartela["G"][i],"\t",
           "| ", cartela["O"][i],"\t","|",)
    print("------------------------------------------")

gera_numeros_cartela_bingo()
