def hex2int(n):

    if len(n)>1:
        return None

    if n.isdigit():
        return int(n)
    else:
        if(ord(n.upper())-55)<=15:
            return ord(n.upper())-55
    return None
        
#def int2hex():


def int2hex(n):
    if int(n)<= 9:
        return str(n)
    elif n>=10 and n<= 15:
         return chr(n - 10 + ord('A'))
    else:
        return ("Número inteiro fora do intervalo (0 a 15).")



def main():
    n=int(input("digite:"))
    inteiroPhexa=int2hex(n)
    print(inteiroPhexa)


main()




def main():
    n=input("digite>:")
    hex=hex2int(n)
    print(hex)

main()



