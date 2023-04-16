dia=int(input("informe um dia: "))
hora=int(input("informe um hora: "))
minuto=int(input("informe um minuto: "))
segundos=int(input("informe um segundo: "))

s=((minuto*60)+(hora*60)+(dia*((60*60)*24)))


print("o valor total de segundos é: ",s)