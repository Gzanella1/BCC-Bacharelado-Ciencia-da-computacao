n="(23-45)/2"
lista=[]
for elemento in (n):
    if elemento.isalpha() and elemento[elemento+1].isalpha():
        lista.append(elemento)
    if elemento.isalpha():
        lista.append(str(elemento))
    else:
        lista.append(str(elemento))
    

print(lista)
