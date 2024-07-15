def tokenizacao(n):
    lista=[]
    anterior=""
    numero=""

    #FTQ significa foto do quadro 
    #FTQ - 1)varer a string  elemento por elemento 
    #"((23-45)/2)+34" usei como base para realizar o exercicio
    for elemento in n:
        #FTQ - 2) se o elemento não fizer parete de um numero ou seja se o elemento não for um numero insere na lista
        #se (o elemento for um {operador(ou parentes)})   OU  ( (elemento for um -+)  E ( (anterior é um numero) OU  (anterior é um parentes ))
        # tomar cuidado com os sinais + e -
        # ha casos especiais como 2-2 e (2*8)-2 quando chegar no menos ele so vai ter dois casos possivei
        if((elemento =="(") or (elemento==")") or( elemento =="*") or (elemento=="/") or (elemento =="^"))    or   ((elemento=="+" or elemento=="-") and (anterior.isnumeric() or anterior==")")):
            #temso que verificar se chegamos ao final do numero
            #como os numeros não entram nesse if eles entram no else, então segue exemplo:
            #apos o parentes entrar e ser adicionado na lista, o 2 entra no else e a variavel numero recebe o 2, no proximo elemento que é o 3 ocorre o mesmo processo, 
            #ja no quarto elemento "-" entra no if  e entra no segundo if e se a variavel numero for vazia ele pula o segundo if se não adiciona o numero na lista
            #nesse caso tem o 23 então a var numero não esta vazia e o 23 é adicionado na lista e a variavel numero tem que ser vazia 
            if numero != "":
                lista.append(numero)
                numero=""
            #adiciona o elemento na lista
            lista.append(elemento)
        #FTQ - 3)caso contrario concatene o elemento na variavel temporaria/auxiliar 
        else:
            numero+=elemento

        #importante lembrar que a variavel anterior deve ficar fora do if/else
        anterior=elemento

    #este if serve para verificar se ha algum numero na variavel numero
    #como nos testes os ultimos numeros não apareciam na tela 
    #exemplo:"((23-45)/2)+34" o 34 não aparecia na tela 
    #pois ele não entrava no if principal para adicionar a lista 
    if numero != "":
        lista.append(numero)
        #apos adicionarmos na lista esvaziamos a variavel
        numero=""

    return lista

def main():
    n=input("Digite uma expressão matematica: ")
    token=tokenizacao(n)
    print(token)

main()

