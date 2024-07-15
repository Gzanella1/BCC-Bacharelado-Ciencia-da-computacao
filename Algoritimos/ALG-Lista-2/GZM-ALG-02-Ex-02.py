segundos=int(input("digite um valor em segundos: "))

dia=segundos//86400
sobra=segundos%86400

hora=sobra//3600
sobra=sobra%3600

minutos=sobra//60
sobra=sobra%60

print("Segue a tabela de conversão de minutos:")
print("Dia(s): ",dia)
print("Hora(s): ",hora)
print("minuto(s): ",minutos)
print("segundo(s): ",sobra)












