def verifica_palavra_repetida(lista):
    novaLista=[]
    for elemento in lista:
            if (novaLista.count(elemento)==0):
                novaLista.append(elemento)
    return novaLista

def main():
    lista = []
    while True:
        n = input("digite uma palavra e (enter para finalizar): ")
        if (n == ""):
            break
        else:
            lista.append(n)

    verificacao=verifica_palavra_repetida(lista)
    print(verificacao)

main()
        
