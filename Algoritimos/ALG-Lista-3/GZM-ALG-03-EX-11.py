a=int(input("digite o valor de A: "))
b=int(input("digite o valor de B: "))
c=int(input("digite o valor de C: "))

#Delta=b²-4.a.c
#x1= -b +(discriminante delta ** 0.5)/2.a
#x1= -b -(discriminante delta ** 0.5)/2.a
delta=(b**2)-(4*(a*c))
x1=((-b)+((delta**0.5)))/(2*a)
x2=((-b)-((delta**0.5)))/(2*a)
print(delta)

if(delta ==0):
    print("nossas raizes é: ")
    print("X1= ",x1)
    print("X2= ",x2)
elif(delta >0):
    print("nossas raizes é: ")
    print("X1= ",x1)
    print("X2= ",x2)
else:
    print("como o delta e < 0 não temos raizes reais!")