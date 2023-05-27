import math

# le as coordenadas x e y do primeiro ponto
xinicial=float(input("Digite a cordenada X de um aponto: "))
yinicial=float(input("Digite a cordenada y de um aponto: "))

# salva as coordenadas do 1o ponto como ponto " anterior"
xant = xinicial
yant = yinicial

# inicializa valor do peímetro do poligono
perimetro = 0

# faz a leitura de novos lados do poligono
while True:
    # le o valor x do novo ponto
    resposta=input("Digite a coordenada x de um ponto (enter para sair): ")
    if resposta == "":
        break
    xatual = float(resposta)
    
    # le o valor y do novo ponto (ponto atual)
    yatual=float(input("Digite a cordenada y de um aponto: "))

    # calcula o comprimento do novo lado (ponto anterior até o ponto atual)
    distancia= math.sqrt(((xatual-xant)**2)+((yatual-yant)**2))

    # acumula o comprimento do lado atual no perimetro total do poligono
    perimetro = perimetro + distancia

    # o ponto atual passa a ser ponto anterior, para a proxima iteracao-*/
    xant = xatual

    
    yant = yatual



