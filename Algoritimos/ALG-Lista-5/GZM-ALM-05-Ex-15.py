def hex2int(n):
    if len(n)>1:
        return None

    if n.isdigit():
        return int(n)
    else:
        if(ord(n.upper())-55)<=15:
            return ord(n.upper())-55
    return None   

def int2hex(n):
    numero=int(n)
    if int(numero)<= 9:
        return str(numero)
    elif numero>=10 and numero<= 15:
         return chr(numero - 10 + ord('A'))
    else:
        return ("Número inteiro fora do intervalo (0 a 15).")

def main():
    n=input("digite um valor de base 16 ou 10:")
    base=input("Menu:  1-)str para int e 2-)int para str: ")
    if base=="2":
        inteirostring=int2hex(n)
        print(f"a converção de int para str é {inteirostring}")
    elif base=="1":
        hex=hex2int(n)
        print(f"a conversão de str para int é {hex}")
    else:
        print("Erro!")
main()

