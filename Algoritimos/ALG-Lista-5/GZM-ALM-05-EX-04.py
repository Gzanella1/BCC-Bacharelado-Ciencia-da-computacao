def main():
    n1=int(input("Digite o primeiro número: "))
    n2=int(input("Digite o segundo número: "))
    n3=int(input("Digite o terceiro número: "))
    mediano=calculo_mediano(n1,n2,n3)
    print("o mediano é: ",mediano)

def calculo_mediano(n1,n2,n3):
    minimo=min(n1,n2,n3)
    maximo=max(n1,n2,n3)
    return (n1+n2+n3)-maximo-minimo


main()