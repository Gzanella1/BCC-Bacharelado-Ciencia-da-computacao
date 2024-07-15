#GZM-ALM-05-EX-03.py
import math

# definicoes das funcoes
def comprimento_hipotenusa(L1,L2):
    calculo=math.sqrt((L1**2)+(L2**2))
    return calculo


# programa principal
def main():
    a=float(input("Digite o primeiro lado de triangulo retangulo: "))
    b=float(input("Digite o segundo lado de triangulo retangulo: "))
    hip = comprimento_hipotenusa(a,b)
    print("A hipotenusa é: ", hip)

# executando o programa principal
main()

