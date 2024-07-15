volume=int(input("digite um numero de decibes: "))

if(volume <= 40):
    print("sala silenciosa")
elif(volume == 70):
     print("despertador")
elif(volume == 106):
    print("cortador de grama")
elif(volume == 130):
    print("bateria")
elif(volume >40 and volume <=70):
    print("o volume esta entre sala silenciosa e Despertador")
elif(volume >70 and volume <=106):
    print("o volume esta entre Despertador e cortador de grama")
elif(volume >106 and volume <=130):
    print("o volume esta entre cortador de grama e britadeira")
else:
    print("o barulho esta muito alto")







