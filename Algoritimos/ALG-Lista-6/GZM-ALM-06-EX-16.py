def precedencia(operador):
    if operador =="+" or operador=="-":
        return 1
    elif operador =="*" or operador=="/":
        return 2
    elif operador =="^":
        return 3
    else:
        return -1

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
        if  token[0:].isdigit() or (token[0] == "-" and token[1:].isdigit()) or (token[0] == "+" and token[1:].isdigit()):
            #adiciona na lista posfix
            postfix.append(token)
        #verifica se  for um operador 
        if (token =="*") or (token=="/") or (token =="^") or (token=="+") or (token =="-"):
            #enquandto a lista de operadores NÃO for vazia 
            #e a ultima posição for digerente de parentes aberto
            #e o antecedente do token atual for menor que a penultimo item dos operadores
            #achei confusa essa parte
            while len(operadores)>0 and operadores[-1] != "(" and precedencia(token) < precedencia(operadores[-1]):
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
        

    #no final caso sobre algum operador na lista usamos esse lação pare remover de operadores e colocar na posfix
    #exemplo :['2', '3', '+', '2', '*']
    #nesse caso o * iria se perder, e estaria errado o posfix
    while len(operadores)>=1:
        postfix.append(operadores[-1])
        operadores.remove(operadores[-1])
        
    return postfix

#A tokenização foi a mesma função do exercicio 15 da lista atual        
def tokenizacao(n):
    lista=[]
    anterior=""
    numero=""
    for elemento in n:
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

def main():
    n=input("Digite uma expressão matematica: ")
    infix=tokenizacao(n)
    print(infix_para_posfix(infix))

main()
