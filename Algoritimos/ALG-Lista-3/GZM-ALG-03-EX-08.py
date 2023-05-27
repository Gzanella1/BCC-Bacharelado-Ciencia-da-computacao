nome=input("digite o nome da nome: ")
oitavas=int(input("digite a oitavas: "))

if(nome == "c"):
    f=261.63
elif(nome == "d"):
    f=293.66
elif(nome == "e"):
     f=329.63
elif(nome == "f"):
     f=349.23
elif(nome == "g"):
     f=392.00
elif(nome == "a"):
     f=440.00
elif(nome == "b"):
     f=493.88

frequenciaFinal= f/(2**(4-oitavas))
print("a frequencia dessa nota é", frequenciaFinal)












