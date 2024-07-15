numero=int(input("Digite um numero maior que 2:"))
fator=2

if (numero < 2):
    print("Erro")
        
while fator < numero:
    if ( numero%fator==0):
        print(fator)
        numero=numero/fator
    else:
        fator+=1
        


        