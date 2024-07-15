numero=int(input("digite um numero de três algorismos UDC: "))


cent=(numero//100)
#vai dividir o numero 150/10 = 15, depois vai pegar o resto da divisão 15%10 =5
dez=(numero//10)%10
#vai calcular o resto da divisão nesse caso va ser zero
uni=(numero%10)

print("Segue abaixo a unidade, dezena e centena separadamente: ")
print("centena: ",cent)
print("dezena: ",dez)
print("unidade: ",uni)


