#A tokenização foi a mesma função do exercicio 15 da lista atual        
def tokenizacao(esprecaoMatematica):
    lista=[]
    anterior=""
    numero=""
    for elemento in esprecaoMatematica:
        if((elemento =="(") or (elemento==")") or( elemento =="*") or (elemento=="/") or (elemento =="^"))    or   ((elemento=="+" or elemento=="-") and (anterior.isnumeric() or anterior==")")):
            
            if numero != "":
                lista.append(numero)
                numero=""
            lista.append(elemento)
        else:
            numero+=elemento
        anterior=elemento
    if numero != "":
        lista.append(numero)
        numero=""
    return lista

#infix_para_posfix foi a mesma do exercicio 16
def infix_para_posfix(infix):
    #infix=['(', '2', '+', '3', ')', '*', '2']
    operadores=[]
    postfix=[]
    precedenciaToken=""
    for token in infix:
        #verifica se o numero é inteiro
        #pq token[0:].isdigit -> o infix possui varias posições e essas possições podem possuir mais de um elemento 
        #ex: a posição 1  poderia ser um -2  ou 43 ambos contendo dois elementos
        #então se o (primeiro elemento for um numero) ou (um " - ") &  o resto do elemento for um numero entra nesse if
        #contamos  que o primeiro elemento fosse o ("4" -> 43) ou o - do exemplo e o resoto for um numero (-2 -> 2) ou  (43 -> 3)
        if  token[0:].isdigit() or (token[0] == "-" and token[1:].isdigit()):
            #adiciona na lista posfix
            postfix.append(token)
        #verifica se  for um operador 
        if (token =="*") or (token=="/") or (token =="^") or (token=="+") or (token =="-"):
            #enquandto a lista de operadores NÃO for vazia 
            #e a ultima posição for digerente de parentes aberto
            #e o antecedente do token atual for menor que a penultimo item dos operadores
            #achei confusa essa parte
            while len(operadores)>=1 and operadores[-1] != "(" and precedenciaToken < operadores[-2]:
                postfix.append(operadores[-1])
                operadores.remove(-1)
            operadores.append(token)
        #verifica se for um parentes aberto
        if token =="(":
            operadores.append(token)
        #verifica se for um parentes fechado  
        if token ==")":
            while operadores[-1] != "(":
                postfix.append(operadores[-1])
                operadores.remove(operadores[-1])
            #remova o parentes aberto
            operadores.remove("(")
        precedenciaToken=token

    #no final caso sobre algum operador na lista usamos esse lação pare remover de operadores e colocar na posfix
    #exemplo :['2', '3', '+', '2', '*']
    #nesse caso o * iria se perder, e estaria errado o posfix
    while len(operadores)>=1:
        postfix.append(operadores[-1])
        operadores.remove(operadores[-1])
        
    return postfix

#exercicio 17
def avaliar_posfix(listaPosfix):  
    valores=[]
    #listaPosfix=['2', '7', '+']
    #direita=""
    #esquerda=""
    resposta=""
    for token in listaPosfix:
        if token.isnumeric():
            valores.append(int(token))
        else:
            """
            impossiel de usar pois elas vão adicionando o valor e fica acumulado
            o que da erro no exercicio
            direita=valores[-1]
            valores.pop(-1)
            esquerda=valores[-1]
            valores.pop(-1)
            """
            #ex: ['2', '7', '+']
            #esse vai remover o 7 e vai acumular na direita temporariamente
            direita = valores.pop()
             #esse vai remover o 2 e vai acumular na esquerda temporariamente
            esquerda = valores.pop()
            
            if token == '-':
                resposta = esquerda - direita
            elif token == '+':
                resposta = esquerda + direita
            elif token == '/':
                resposta = esquerda / direita
            elif token == '*':
                resposta = esquerda * direita
            else:
                return "erro operador invalido"
            
            valores.append(resposta)
    return(valores)

def main():
    n=input("Digite uma expressão matematica: ")
    infix=tokenizacao(n)
    print(avaliar_posfix(infix_para_posfix(infix)))

main()
