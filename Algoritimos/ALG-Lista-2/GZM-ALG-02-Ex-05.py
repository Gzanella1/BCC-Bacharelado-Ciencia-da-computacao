centavos = int(input("Digite: "))


m = [50, 25, 10, 5, 1]
calculo = 0

print("---------------------------------------------")
print("------------TABELA DE TROCO -----------------")
print("---------------------------------------------")
# vai ver quantas vezes o 50 cabe dentro do numero informado
calculo = centavos//m[0]
# vai ser o resto que sobra do calculo acima ex: o numero informado foi 60 então 50 so cabe uma vez vai sobrar 10
sobra = centavos % m[0]
print("Quantidade de moedas de 50 centavos: ", calculo)

print("---------------------------------------------")
# vai ver quantas vezes a sobra de cima cabe dentro do numero 25 se nenhuma o valor aque sera 0
calculo = sobra//m[1]
# então aqui ainda ira sobrar 10
sobra = sobra % m[1] 

print("Quantidade de moedas de 24 centavos: ", calculo)

print("---------------------------------------------")
# se o numero da sobra anterior for igual a moeda então sera 1modeda de 10 centavos
calculo = sobra//m[2]
# não ira sobrar nada para dar sequencia no calculo então sera ZERO
sobra = sobra % m[2]
print("Quantidade de moedas de 10 centavos: ", calculo)

print("---------------------------------------------")
# não ira sobrar nada para dar sequencia no calculo então sera ZERO
calculo = sobra//m[3]
# não ira sobrar nada para dar sequencia no calculo então sera ZERO
sobra = sobra % m[3]
print("Quantidade de moedas de 5 centavos: ", calculo)

print("---------------------------------------------")
# não ira sobrar nada para dar sequencia no calculo então sera ZERO
calculo = sobra//m[4]
# não ira sobrar nada para dar sequencia no calculo então sera ZERO
sobra = sobra % m[4]
print("Quantidade de moedas de 1 centavos: ", calculo)

print("---------------------------------------------")