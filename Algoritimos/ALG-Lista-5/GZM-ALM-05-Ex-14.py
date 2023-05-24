"""Datas mágicas. 
Uma “data mágica” é uma data na qual a multiplicação do dia pelo mês é
igual aos dois últimos dígitos do ano. Por exemplo, 10 de junho de 1960 é uma data mágica
porque 10 vezes 6 é igual a 60, que são os dois últimos dígitos do ano.

Escreva uma função
que determina se uma data é ou não mágica. A função deve receber 3 parâmetros inteiros
(dia, mês e ano), e retornar um valor lógico.

Escreva um programa main que utilize sua função
para determinar e imprimir todas as datas mágicas do século XX. O exercício anterior pode ser
útil para resolver este problema.
"""""



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

    for ano in range(1901,2000):
        for mes in range(1,12):
            for dia in range(1,31):
                if data_magica(dia,mes,ano):
                    print(f"{dia}/{mes}/{ano}")



main()
