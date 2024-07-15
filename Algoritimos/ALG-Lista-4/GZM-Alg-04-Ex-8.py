frase=input("digite uma frase: ")
distancia=int(input("digite a distancia: "))



for letra in frase:
    if(letra.isalpha()):
    #Converter a letra prara codigo ASCII
        codigoDaLetra=ord(letra)
        codigoDaLetra+=distancia
        
        if(codigoDaLetra >122):
            codigoDaLetra=97+codigoDaLetra%122
            
        elif(codigoDaLetra < 65):
            codigoDaLetra=codigoDaLetra+26
        
        elif(codigoDaLetra >90 and codigoDaLetra<= 96):
            codigoDaLetra=65+codigoDaLetra%90
        
        elif(codigoDaLetra <97):
            codigoDaLetra=codigoDaLetra+26
            
    #Converte o codigo para LETRAS NORMAL
    conversaoLetraNova=chr(codigoDaLetra)
    print(conversaoLetraNova)
        
    
    