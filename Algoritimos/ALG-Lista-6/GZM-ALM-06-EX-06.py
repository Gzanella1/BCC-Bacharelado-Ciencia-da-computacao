def divizores(n):
    lista=[]
    for i in range(1,n):
        if(n%i==0):
            lista.append(i)
        
    return lista


def main():
    n=int(input("Digite um número para saber seus divisores: "))
    divizor=divizores(n)
    print(divizor)


main()
