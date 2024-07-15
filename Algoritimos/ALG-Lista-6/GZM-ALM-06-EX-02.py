
lista = []
while True:
    n = int(input("digite um numero:"))
    if (n == 0):
        break
    else:
        lista.append(n)
lista.sort(reverse=True)
for i in lista:
    print(i)

