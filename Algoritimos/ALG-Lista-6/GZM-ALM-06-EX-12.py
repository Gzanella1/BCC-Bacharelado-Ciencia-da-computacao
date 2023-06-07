def verifica_lista(lista):
    if (lista=="") or (len(lista)==1):
        return False
    else:
        lista_ordenada=[]
        lista_ordenada=sorted(lista)
        if lista_ordenada == lista:
            return True
        else:
            return False


def main():
    lista=[]
    while True:
        n=input("digite um numero: ")
        if (n==""):
            break
        lista.append(n)
    verifica_se_lista_ordenada=verifica_lista(lista)
    if verifica_se_lista_ordenada:
        print("A lista está ordenada")
    else:
        print("A lista não está ordenada!")


main()
