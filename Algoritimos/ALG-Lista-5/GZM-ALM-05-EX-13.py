def main():
    mes=int(input("Informe o mês como um número inteiro enter 1-12: "))
    ano=int(input("Informe o ano como um número inteiro de quatro digitos: "))
    print(dias_em_um_mes(mes,ano))


def dias_em_um_mes(mes,ano):
    mes30dias=[1,3,5,7,8,10,12]
    mes31dias=[4,6,9,11]

    if mes ==2: 
        if((ano%400==0) or (ano%4==0)):
            return 29
        else:
            return 28
    elif(mes in mes30dias):
        return 30
    elif(mes in mes31dias):
        return 31
    else:
        return "Mês invalido"
    

main()