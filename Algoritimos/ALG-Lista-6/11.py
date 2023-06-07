import random
lista=[]
novaLista=[]
for i in range(6):
    lista.append(random.randint(1,60))
    for elemento in lista:
            if (novaLista.count(elemento)==0):
                novaLista.append(elemento)
                aleatoria=random.randint(elemento)
                novaLista.append(aleatoria)
novaLista.sort()
print(novaLista)


