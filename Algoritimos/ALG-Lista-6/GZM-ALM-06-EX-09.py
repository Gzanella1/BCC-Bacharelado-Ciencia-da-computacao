def calcula_media(lista):
    soma=0
    #soma todos os numeros da lista
    for numero in lista:
        soma+=numero  
    #calcula a media
    comprimentoLista=len(lista)
    media=soma / comprimentoLista
    return media

def avalia_media(lista):
    media = calcula_media(lista)
    #organiza os numeros inserido pelo usuario em listas
    numeroNaMedia=[]
    acimaMedia=[]
    abaixoMedia=[]
    #verifica se o numero é acima ou a baixo da media
    for numero in lista:
        if numero < media:
            abaixoMedia.append(numero)
        elif numero > media:
            acimaMedia.append(numero) 
        else:
            numeroNaMedia.append(numero)
    return media, numeroNaMedia,  abaixoMedia, acimaMedia

def main():
    #lista de numeros que o usuario informou
    lista=[]
    while(True):
        numero_string=input("digite um número: ")
        if(numero_string==""):
            break
        numero = float(numero_string)
        lista.append(numero)

    #isso é uma tupla com varos valores numeros lists etc
    #ela vem do metodo avalia_media que retorna mais de um valor
    resposta = avalia_media(lista)
    #printando a tupla nas posições 0,1,2,3  e ela completa
    print(resposta)
    print("A media é:",resposta[0])
    print("Números na média:",resposta[1])
    print("Abaixo da media :",resposta[2])
    print("Acima da media é:",resposta[3])


main()
