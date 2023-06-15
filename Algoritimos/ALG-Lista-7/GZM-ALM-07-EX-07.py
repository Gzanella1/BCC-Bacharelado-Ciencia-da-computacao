import random

def sla():
    b="BINGO"

    start=1
    end=15
    dicionario={}
    for letras in b:
        numerosAleatorios=random.sample(range(start, end), 5)
        dicionario[letras]=numerosAleatorios
        start+=15
        end+=15
    cartela(dicionario)


#FALTA TERMINAR 
#FALTA TERMINAR 
#FALTA TERMINAR 
#FALTA TERMINAR 
#FALTA TERMINAR 

def cartela(cartela):
    for i in range(5):
        print(cartela["B"][i],"\t",
            cartela["I"][i],"\t",
            cartela["N"][i],"\t",
            cartela["G"][i],"\t",
            cartela["O"][i],"\t")

sla()
