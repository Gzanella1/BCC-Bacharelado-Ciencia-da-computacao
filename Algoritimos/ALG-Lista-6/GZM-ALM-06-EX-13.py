def countRange(lista, minimo, maximo):
    quantidade = 0
    for x in lista:
        if x>=minimo and x<maximo:
            quantidade += 1
    return quantidade


def main():
    lista=[]
    while True:
        n=input("digite um numero: ")
        if (n==""):
            break
        lista.append(n)
    minimo=input("digite o valor minimo: ")
    maximo=input("digite o valor maximo: ") 
    cont=countRange(lista,minimo,maximo)
    print(cont)
   
    #lista = [1,2,3,4,5,6,7,8,9,10]
    #print(countRange(lista, 3, 6))
    
main()
