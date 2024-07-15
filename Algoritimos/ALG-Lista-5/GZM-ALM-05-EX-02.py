valor_inicial=4.00
valor_adicional=0.25


def calculo_metros_percoridos(distancia_percorida):
    calculo= valor_adicional*((distancia_percorida*1000)/140)
    return calculo


def main():
    distancia_percorida=float(input("digite a distancia percorida em quilometro: "))
    calculo_tarifa=calculo_metros_percoridos(distancia_percorida)
    print("O valor total da corrida é ",  calculo_tarifa)

main()    