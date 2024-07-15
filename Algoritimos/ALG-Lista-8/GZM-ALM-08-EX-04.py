
def fibonacci(n):
    dicionario={}
    if n<=0:
        return 0
    if n==1 :
        return 1 
    else:
       return memorização_de_resultado(n, dicionario)
   

def memorização_de_resultado(n,dicionario):
    if n in dicionario:
        return dicionario[n]
    else:
        resposta=fibonacci(n-1)+fibonacci(n-2)
        dicionario[n]=resposta
        return resposta


def main():
    n=int(input("digite um numero para saber o fatorial: "))
    fibonaci=fibonacci(n)
    print(fibonaci)

main()
