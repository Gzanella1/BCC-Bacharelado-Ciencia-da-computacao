binario = input("Digite o número em binário: ")
bin_original = binario
n = -1
decimal = 0
binario = binario[::-1]

for i in binario:
    i = int(i)
    print("Processando o dígito", i)
    decimal = decimal + (i*(2**(n+1)))
    print("Decimal equivalente ao dígito:", decimal)
    n = n + 1

print("A conversação do número em binário",bin_original, " para decimal é", decimal, "na base 10.")