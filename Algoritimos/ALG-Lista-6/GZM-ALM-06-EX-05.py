def organizando_negativos_zero_positivos(lista):
    menorQ1=[]
    zero=[]
    maiorQ1=[]
    for i in lista:
        if (i <0):
            menorQ1.append(i)
        elif(i>=1):
            maiorQ1.append(i)
        else:
            zero.append(i)
    return (menorQ1+zero+maiorQ1)


def main():
    lista = []
    while True:
        n = input("digite um numero (enter para finalizar):")
        if (n == ""):
            break
        else:
            lista.append(int(n))
    ogrganizado=organizando_negativos_zero_positivos(lista)
    print(ogrganizado)

main()
    
