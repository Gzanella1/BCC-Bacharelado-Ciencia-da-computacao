""" 
#ESSA FUNÇÃO RETORNA OS ULTIMOS N NUMEROS MAIORES/MENORES QUE O USUARIO DIGITAR

def remove_extremos(lista, x):
    nova_lista_ordenada=sorted(lista)
    n = len(lista)
    nova=nova_lista_ordenada[x : n-x]
   for i in range(-x,0):
        nova.append(nova_lista_ordenada[i])
    for i in range(0,x):
        nova.append(nova_lista_ordenada[i])

        

    #PEGA OS VALORES NO INTERVALO QUE O USUARIO DIGITAR 
    lista = [0,1,2,3,4,5,6,7,8,9]
    n = len(lista)
    for i in range(x, n-x):
        nova.append(nova_lista_ordenada[i])
"""
def remove_extremos(lista, x):
        return lista[x: -x]


def main():
    lista = []
    while True:
        n = input("digite um numero (enter para finalizar):")
        if (n == ""):
            x=int(input("Digite a quantidade de N maiores/menores que você quer: "))
            break
        else:
            lista.append(int(n))

    rm=remove_extremos(lista,x)
    print(rm)

main()
