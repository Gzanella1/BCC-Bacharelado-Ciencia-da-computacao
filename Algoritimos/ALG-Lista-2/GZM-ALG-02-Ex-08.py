n = int(input("digite um numero de três algorismos UDC: "))

c = (n//100)
d = (n // 10) % 10
u = (n % 10)

M = u * 100 + d * 10 + c

# print("---------------------------")
# print(u*100)=300
# print(d*10)=20
# print(c)=1
# soma=300+20+1=321
# print("---------------------------")

print()
print("A ordem inversa do numero ", n, " é ", M)
print("-------------------OU----------------------")
print("A ordem inversa do numero ", n, " é ", u, d, c)
