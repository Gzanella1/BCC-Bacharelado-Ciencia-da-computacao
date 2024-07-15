#2 anos não precisa pagar
#3 e 12 pagam 14
#65 ou mais pagam 18
#todos os de mais pagam 23

valor=0
while True:
    resposta=input("Digite a idade (digite enter para sai): ")
    
    if(resposta == ""):
        break


    idade = int(resposta)
    if(idade >= 0 and idade <=2 ):
        valor+=00.0
    elif(idade >=3 and idade <=12):
        valor+=12
    elif(idade > 65):
        valor+=18.0
    else:
        valor+=23.0

print("o valor total a pagar é ", valor)