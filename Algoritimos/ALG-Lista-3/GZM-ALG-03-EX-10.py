coluna=input("Digite a coluna: ")
linha=int(input("Digite a linha: "))

if(coluna == "a" or coluna == "c" or coluna == "e"or coluna == "g"):
   print("coluna começa com quadrado preto")
   if(linha %2==1):
        print("quadrado preto")
   else:
       print("quadrado branco")

elif (coluna == "b" or coluna == "d" or coluna == "f" or coluna == "h"):
    print("coluna começa com quadrado branco")
    if(linha %2==1):
        print("quadrado branco")
    else:
        print("quadrado preto")
        
else:
    print("valor invalido")