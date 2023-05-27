def main():
    palavra=input("digite uma palavra: ")
    espaco=int(input("digite uma valor em numero: "))
    comprimento=len(palavra)
    sla=centralizar_string(comprimento,espaco)

    print(sla,palavra)

def centralizar_string (comprmento, espaco):
    calcula_os_espacos_antes=espaco-comprmento/2
    s=" "*int(calcula_os_espacos_antes)
    return s

main()