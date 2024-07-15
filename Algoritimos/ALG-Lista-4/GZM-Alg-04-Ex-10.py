palavra=input("digite uma palavra: ")
palavra_invertida = ""

n=len(palavra)

resposta = True
for i in range(n):
    if palavra[i] != palavra[n - i - 1]:
        resposta = False
        break
    
if resposta:
    print("É palindromo")
else:
    print("Não é palíndromo")
    
    



#TESTE
#palavra=input("digite uma palavra: ")
#palavra_invertida = ""

#n=len(palavra)


#for i in range(n):
    #palavra_invertida = palavra[i] + palavra_invertida
    #print(palavra_invertida)
#print("--------------------------------------------------")

#palavra_invertida = ""
#for i in range(n-1, -1, -1):
     #palavra_invertida = palavra_invertida + palavra[i] 
     #print(palavra_invertida)
     
#print("--------------------------------------------------")
     
#palavra_invertida = ""
#for i in range(n):
    #palavra_invertida = palavra_invertida + palavra[n-1-i]
    #print(palavra_invertida)
#print("--------------------------------------------------")
