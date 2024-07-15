
def precedencia(operador):
    if operador =="+" or operador=="-":
        return 1
    elif operador =="*" or operador=="/":
        return 2
    elif operador =="^":
        return 3
    else:
        return "Erro entrada invalida resultou em -1"

def main():
    operador=input("digite um operador: ")
    prece=precedencia(operador)
    print(prece)
    
main()
