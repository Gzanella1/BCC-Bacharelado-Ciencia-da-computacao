lista = []
while True:
    n = int(input("digite um numero:"))
    if (n==0):
        break
    else:
        lista.append(n)

novalista =sorted(lista)
for i in novalista:
    print(i)
