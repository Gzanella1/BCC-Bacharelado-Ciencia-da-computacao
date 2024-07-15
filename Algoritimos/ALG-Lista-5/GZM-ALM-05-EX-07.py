def main():
    l1=float(input("Digite o primeiro comprimento: "))
    l2=float(input("Digite o segundo comprimento: "))
    l3=float(input("Digite o terceiro comprimento: "))
    calculo=determinar_triangulo(l1,l2,l3)
    if(calculo):
        print("Pode formar um triangulo")
    else:
        print("Não pode formar um triangulo")

def determinar_triangulo(l1,l2,l3):
    if (l1+l2)>l3:
        return False
    if(l2+l3)>l1:
        return False
    if(l1+l3)>l2:
        return False
    return True

main()