def totalValores():
    #pede numero para o usuario
    n=input("digite um numero: ")
    #se o numero for diferente de espaço em branco
    if (n != ""):
        #retorna a soma do numero atual + o proximo valor que o usuario inserir
        return float(n)+totalValores()
    #se não retorna zero
    else:
        return 0.0
    

print(totalValores())
