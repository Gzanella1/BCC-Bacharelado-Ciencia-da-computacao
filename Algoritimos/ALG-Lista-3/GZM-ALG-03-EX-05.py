mes=input("digite o nome de um mes:")

if (mes == "fevereiro"):
    print("O mês possui 28 dias")
elif(mes =="abril" or mes == "junho" or mes=="setembro" or mes =="novembro"):
    print("O mês possui 30 dias")
else:
    print("O mês possui 31 dias")
