a=int(input("digite o primeiro numero: "))
b=int(input("digite o primeiro numero: "))
c=int(input("digite o primeiro numero: "))

min=min(a, b, c)
max=max(a, b, c)

print("o minimo é: ",min)
print("o valor intermediario é: ",(a+b+c)-min-max)
print("o maior é: ",max)

