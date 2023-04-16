import math
l=float(input("Digite o comprimentos:"))
n=float(input("Digite o número de lado:"))

area=(n*(l**2))/4*math.tan(math.pi/n)

print("A area é:", area)