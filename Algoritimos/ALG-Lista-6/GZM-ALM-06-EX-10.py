

def lista_de_itens(lista):
    n = len(lista)
    if n == 1:
        return str(lista)
    elif n == 2:
        return str(lista[0]) + " e " + str(lista[1])
    else:
        frase=""
        for i in range(n):
            if i < n-2:
                frase = frase + lista[i] + ", "
            if i == (n-2):
                frase = frase + lista[i] + " e "
            else:
                frase = frase + lista[i]
        return frase
    
lista=["maça","laranja","banana","limão", "uva"]
print(lista_de_itens(lista))


"""str=""
for indice in lista:
    str=str+indice+","
print(str)


"""



