decimal =10
quociente = decimal
restos = []
binario=[]


while quociente > 0:
    resto = quociente % 2
    restos.append(resto)
    quociente = quociente // 2
    
    print("divisão: ",quociente, "/2", "\t \t \tResto: ", resto)
    
    
print(restos)


print("---------------------------------------------------------------------------------------------")
for i in range(len(restos)-1,-1,-1):
    binario.append(restos[i])
    
def main():
    print("Binario: ",binario)
    test=igual(restos)
    if test:l(restos)
    if test:
        print("são iguais")
    else:
        print("Não são iguais")

        print("Não são iguais")




def igual(restos):
    
    if restos==10101011110000010000:
        return True
    return False


main()