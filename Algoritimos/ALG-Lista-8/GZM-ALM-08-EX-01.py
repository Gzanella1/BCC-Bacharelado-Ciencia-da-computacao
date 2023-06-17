# fatorial é um  n  vezes todos os numeros menores que ele
#n=10 então fatorial=10*9*8*7.....
def fatorial(n):
    if n>=0:
        if n==1:
            return n 
        else:
            fatorial=1
            i=1
            while i <=n:
                fatorial=fatorial*(n-i)
                i+=1
            return fatorial
    else:
        return "numero invalido"



def main():
    n=int(input("digite um numero para saber o fatorial: "))
    fatorial=fatorial(n)
    print(fatorial)

main()
