
import math
t1=float(input("Digite a latitude do primeiro ponto: "))
g1=float(input("Digite a Longitude do primeiro ponto:"))

t2=float(input("Digite a latitude do segundo ponto:"))
g2=float(input("Digite a longitude do segundo ponto:"))

t1R=(math.pi * t1 )/180
g1R=(math.pi * g1 )/180

t2R=(math.pi * t2 )/180
g2R=(math.pi * g2 )/180
distancia= 6371.01 * math.acos(math.sin(t1R)* math.sin(t2R) + math.cos(t1R)* math.cos(t2R) * math.cos(g1R-g2R)  )

print("A distncias entre os dois pontos é de " , distancia) 