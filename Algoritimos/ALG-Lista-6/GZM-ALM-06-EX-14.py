def precedencia(operador):
    if operador =="+" or operador=="-":
        return 1
    elif operador =="*" or operador=="/":
        return 2
    elif operador =="^":
        return 3
    else:
        return -1


def main():
    operador=input("digite um numero: ")
    prece=precedencia(operador)
    print(prece)
    
main()
