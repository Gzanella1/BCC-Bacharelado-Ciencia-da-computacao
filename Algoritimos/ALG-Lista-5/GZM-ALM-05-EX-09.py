#criar uma função isinteger 
    #que deve determinar se os caracteres em uma string representa ou não um inteiro valido 
    #retornando um valor lofico como resultado TRUE ou FALSE

    #ao determinar se uma string representa um inteiro , ignore os espaços 
    #assim que esses espaçõs são ignorados 
        #uma string representa 1 interiro 
            # se seu comprimento for pelo menos 1 e contiver apenas digitos
            #se seu primeiro caracter for + ou - e o primeiro caractere é seguido por um ou
                # mais caracteres todos os quais são digitos 

def isInteger(palavra):
    nova_palavra=palavra.strip()

    if ((len(nova_palavra)>=1) and (nova_palavra.isdigit())):
        return True
    elif((len(nova_palavra)>=2) and (nova_palavra[0]=="+" or nova_palavra[0]=="-") and(nova_palavra.isdigit())):
        return True
    else:
        return False



#escreva um programa principal que leia uma string e informe se ela representa ou não um numero inteiro 

def main():
    palavra=input("Digite uma palavra ou frase: ")   
    valor=isInteger(palavra)
    if(valor):
        print("Representa um valor inteiro!")
    else:
         print("Não representa um valor inteiro!")


main()

#A função rstrip() é um método utilizado em strings para remover caracteres específicos do lado direito (final) da string.
#O método lstrip() é um método de string em Python que remove os caracteres especificados à esquerda (início) da string.
#A função strip() serve para remover os espaços em branco no início e no final de uma string, 
    #retornando uma cópia formatada da string sem os espaços em branco do ínicio e final.