data = int(input("Digite a data no formato DDMMAA: "))

dia = data // 10000
mes = (data % 10000) // 100
#resto da divisão 2288//100==22
ano = data % 100

#30*10000 =210.000 + 12*100 =1200 +17 = 211217
dataN= (ano * 10000) + (mes * 100) + dia

print("A data invertida é:", dataN)




