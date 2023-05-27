
def data_magica(dia,mes,ano):
    ultimos_dois_digitos = str(ano)[-2:]
    if int(dia*mes) == int(ultimos_dois_digitos):
        return True
    return False

def main():
    diaInicio=1
    mesInico=1
    anoInico=1901
    diaFim=31
    mesFim=12
    anoFim=2000

    for ano in range(1901,2001):
        for mes in range(1,12):
            for dia in range(1,31):
                if data_magica(dia,mes,ano):
                    print(f"{dia}/{mes}/{ano}")



main()