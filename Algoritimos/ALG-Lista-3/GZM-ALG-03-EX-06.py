l1=float(input("digite o primeiro lado:"))
l2=float(input("digite o segundo lado:"))
l3=float(input("digite o terceiro lado:"))

if(l1 == l2 and l2== l3):
    print("O triangulo é equilatero")
elif(l1 != l2 and l2 != l3):
    print("escaleno")
else:
    print("isosceles")