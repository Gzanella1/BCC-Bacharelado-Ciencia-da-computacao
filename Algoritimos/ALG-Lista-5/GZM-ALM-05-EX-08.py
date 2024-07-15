def main():
    s1="bom dia. tudo bem? como voce esta! bem"
    reescrever=reescrevendo_a_frase(s1)


def reescrevendo_a_frase(s1):
    s2=""
    primeira_letra_maiuscula = True

    for letra in range(len(s1)):
        #para pegar 1 letra antes
        uma_Letra_antes=s1[letra-1]
        #para pegar 2 letra antes
        duas_Letras_antes=s1[letra-2]
        #para pegar a letra atual
        s1[letra]

        #se a primeira letra for maiuscula, entra no if
        #coloca a primeira letra em maiuscula
        # depois ela recebe o valor de falso, para não entrar mais nesse if
        if (primeira_letra_maiuscula):
            s2 += s1[letra].upper()
            proxima_letra_maiuscula = False
        elif(uma_Letra_antes ==" " and (duas_Letras_antes == "." or duas_Letras_antes == "?" or duas_Letras_antes == "!")):
            s2=s2+s1[letra].upper()
        else:
            s2=s2+s1[letra]
            
    return s2

        







