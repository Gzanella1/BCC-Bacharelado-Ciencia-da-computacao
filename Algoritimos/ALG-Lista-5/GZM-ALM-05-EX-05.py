def main():
    n=int(input("Digite um numero para saber seu ordinal entre (1 e 12):"))  
    ordinal_correspondente=ordinal(n)
    print("O ordinal correspondente a ",n, " é ",ordinal_correspondente)

def ordinal(n):
    if (n==1):
        return "primeiro."
    elif(n==2):
        return "segundo."
    elif(n==3):
        return "terceiro."
    elif(n==4):
        return "quarto."
    elif(n==5):
        return "quinto."
    elif(n==6):
        return "sexto."
    elif(n==7):
        return "sétimo."
    elif(n==8):
        return "oitavo."
    elif(n==9):
        return "nono."
    elif(n==10):
        return "décimo."
    elif(n==11):
        return "décimo primeiro."
    elif(n==12):
        return "décimo segundo."
    else:
        return "Erro, digite um valor permitido entre 1 e 12"
    
main()