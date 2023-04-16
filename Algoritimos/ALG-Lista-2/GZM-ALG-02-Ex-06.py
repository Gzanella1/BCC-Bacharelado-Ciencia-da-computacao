num = int(input("Digite um número inteiro de 4 dígitos: "))

dig1 = (num) % 10
print("resto da divisão por 10: ")
print(dig1)
dig2 = ((num) // 10) % 10
print(dig2)
dig3 = ((num) // 100) % 10
print(dig3)
dig4 = ((num) // 1000) % 10
print(dig4)

soma = dig1 + dig2 + dig3 + dig4

print("A soma dos dígitos do número " , num , " é " , (soma))


