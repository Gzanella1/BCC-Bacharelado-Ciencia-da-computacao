def main():
    n=int(input("Digite um numero: "))
    nprimo=is_primo(n)
    if(nprimo):
        print("É primo!")
    else:
        print("Não é primo!")

def is_primo(n):
    if n<2:
        return False
    else:
        for i in range(2,n):
            if n%i==0:
                 return False
            if n%n==0 and n%1==0:
                    return True
       
            
main()