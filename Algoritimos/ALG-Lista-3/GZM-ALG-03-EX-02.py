anos=int(input("digite o ano: "))

if(anos <0):
    print("erro")
elif(anos >= 0 and anos <=2):
    icanina= anos *10.5
    print("a idade canina é ", icanina)
else:
    icanina= 21 + ((anos-2)*4)
    print("a idade canina é", icanina)

