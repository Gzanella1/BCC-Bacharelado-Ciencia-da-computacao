def busca_por_valores(d1,n):
    lista=[]
    for x, y in d1.items():
        if y==n:
            lista.append(x)

    return(lista)


def main():
    d1={}
    while True:
        chave=input("digite uma chave: ")
        if chave =="":
            break
        valor=(input("digite um valor: "))
        d1[chave]=valor
    n=input("digite o valor para buscar as chaves: ")
    chaves=busca_por_valores(d1,n)
    print(chaves)

main()
