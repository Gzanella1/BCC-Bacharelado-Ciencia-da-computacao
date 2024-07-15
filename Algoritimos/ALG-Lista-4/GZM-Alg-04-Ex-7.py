pi=3.0
n=2
sinal = 1
for i in range(50):
    print(pi)
    valor= 4/(n*(n+1)*(n+2))
    pi = pi + sinal*valor
    n+=2
    #print(sinal)
    sinal = -sinal

 #pi = 3 + (+1) * valor + (-1) * valor + (+1)*valor + (-1)*valor
 
 