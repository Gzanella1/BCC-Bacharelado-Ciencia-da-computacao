#ta faltando verificar a diagonal
#ta faltando utilizar a verifica tabela vencedora pra dizer se é vencedora ou não 
#ta faltando faltando criar mais cartelas 
#ta faltando verificar as diagonais das tabelas 


import random

def gera_numeros_cartela_bingo():
    b="BINGO"
    start=1
    end=15
    cartela={}
    for letras in b:
        numerosAleatorios=random.sample(range(start, end), 5)
        cartela[letras]=numerosAleatorios
        start+=15
        end+=15
    return cartela
    

def sorterNum_verificaE_substitui_por_zero(cartela):
    sorteio = random.sample(range(1, 75), 5)
    #percore os valores do sorteio
    for numero_sorteado in sorteio:
        # percore os valores da tabela/chave
        for valores in cartela.values():
            #pegas os valores separados das chaves 
            for i in range(len(valores)):
                #verifica se esse valor é o numero do sorteio 
                if valores[i] == numero_sorteado:
                    valores[i]= 0
    print("numeros sorteados: ",sorteio)
    return cartela


# responsavel por verificar se ha colunas/linhas e diagonais com valores zero
def verifica_cartela_vencedora(cartela):
    # verificar linha
    for linha in cartela.values():
        if sum(linha) == 0:
            return(True)

    # verifica a coluna
    for chave in cartela:
        if sum(cartela[chave]) == 0:
            return(True)

    # verificar diagonal principal
    # verificar diagonal inversa
    

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



def main():
    imprime_cartela(sorterNum_verificaE_substitui_por_zero(gera_numeros_cartela_bingo()))


main()



