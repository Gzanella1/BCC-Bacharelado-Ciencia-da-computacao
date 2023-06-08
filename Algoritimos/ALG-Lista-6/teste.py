n="(23-45)/2"

numero=[]
principal=[]


for elemento in (n):
    if elemento.isdigit():
        numero.append(str(elemento))

    if(not elemento.isdigit()):
            principal.append(numero)
            principal.append(elemento)




print(principal)
print("--------")
print(numero)

