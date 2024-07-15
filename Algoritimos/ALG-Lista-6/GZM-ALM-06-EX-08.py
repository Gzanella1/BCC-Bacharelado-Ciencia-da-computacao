def verifica(frase):
    # lista com o texto original sem os espacos
    lista1=frase.split()
    # lista resultante (sem os espacos e sem pontuacao)
    lista2 = []

    # para cada palavra na lista original
    for palavra in lista1:
        # cria uma palavra sem sinais de pontuacao
        nova_palavra = ""
        # para cada caractere da palavra original
        for caractere in palavra:
            # se o caractere for letra ou numero, copia para a nova palavra
            if caractere.isalpha():
                nova_palavra += caractere
        # insere a nova palavra na lista resultante
        lista2.append(nova_palavra)
    # retorna a lista resultante
    return lista2

def main():
    #frase=input("digite uma frase: ")
    frase =input("digite uma frase: ")
    verificar=verifica(frase)
    print(verificar)    

main()
