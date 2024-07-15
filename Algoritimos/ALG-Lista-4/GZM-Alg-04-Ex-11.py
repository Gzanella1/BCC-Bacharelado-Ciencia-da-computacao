frase=input("digite uma frase: ")
palavra_invertida = ""
n=len(frase)


resposta = True
for i in range(n):
    if frase.lower()[i] == " ":
        "".join(frase)
        break
    
    if frase.lower()[i]!= frase.lower()[n - i - 1]:
        resposta = False
        break
    
if resposta:
    print("É palindromo")
else:
    print("Não é palíndromo")
    
    