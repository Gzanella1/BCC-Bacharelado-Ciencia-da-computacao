l1=float(input("Digite o primeiro lado:"))
l2=float(input("Digite o segundo lado:"))
l3=float(input("Digite o terceiro lado:"))

lado=(l1+l2+l3)/2
area=(lado*(lado-l1)*(lado-l2)*(lado-l3)**(1/2))

print("Area é: ",area)