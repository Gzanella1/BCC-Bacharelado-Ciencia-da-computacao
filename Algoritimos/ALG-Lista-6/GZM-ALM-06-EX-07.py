def divisores(n):
    lista=[]
    for i in range(1,n):
        if(n%i==0):
            lista.append(i)
    return lista
    


def numero_perfeito(n):
    listaDeDivisores=divisores(n)
    somaDosNumeros=0
    for i in listaDeDivisores:
        somaDosNumeros+=i

    if somaDosNumeros== n:
        return True
    return False

def main():
    for i in range(1, 10000):
        if numero_perfeito(i):
            print(i)
        

main()
