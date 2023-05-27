def remove_extremos(lista, n):
    # criar uma nova lista sem o n maiores
    # e sem os n menores numeros da lista original
    # exemplo: lista_original = [1, 2, 3, 4, 5, 6,7, 8, 9, 10]
    # n = 2
    nova_lista=sorted(lista)
    for i in nova_lista(-n):
            # nova_lista = [3, 4, 5, 6, 7,8]
   

    return nova_lista

def main():
    lista = []
    while True:
        n = input("digite um numero (enter para finalizar):")
        if (n == ""):
            break
        else:
            lista.append(int(n)

                        )
    
    for i in lista:
        print(i)
