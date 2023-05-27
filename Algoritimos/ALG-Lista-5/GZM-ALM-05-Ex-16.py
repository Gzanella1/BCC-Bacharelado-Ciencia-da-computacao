def hex2int(n):
    if n.isdigit():
        return int(n)
    else:
        if (ord(n.upper())-55) <= 15:
            return ord(n.upper())-55


def int2hex(numero):
    numero = int(numero)
    if int(numero) <= 9:
        return str(numero)
    elif numero >= 10 and numero <= 15:
        return chr(numero - 10 + ord('A'))
    else:
        return ("Número inteiro fora do intervalo (0 a 15).")


def converter_para_base_10(numero_string, base):
    potencia = 0
    n = str(numero_string)[::-1]
    numero_decimal = 0
    for i in n:
        numero_decimal += hex2int(i)*(base**potencia)
        potencia += 1
    return numero_decimal


def converter_10_paraB(numero_decimal, base):
    divizao = numero_decimal
    converete = ""
    while divizao > 0:
        resto = divizao % base
        divizao = divizao // base
        converete = int2hex(resto) + converete
    return converete


def converter_numero_baseA_baseB(numero_string, baseA, baseB):
    # converter numero da base A para base 10
    numero_decimal = converter_para_base_10(numero_string, baseA)
    # converter o resultado da base 10 para base B
    resultado = converter_10_paraB(numero_decimal, baseB)
    # retornaro resultado
    return resultado



def main():
    numero_string = input("digite a o numero em qualquer base de 2 a 16: ")
    baseA = int(input("digite a base de origem: "))
    baseB = int(input("digite a base de destino: "))
    print(converter_numero_baseA_baseB(numero_string, baseA, baseB))

main()
