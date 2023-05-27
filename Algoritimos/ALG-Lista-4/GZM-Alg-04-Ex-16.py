import random

NUM_SIMULACOES = 10  
resultados = []  
total_sorteios = 0  

for i in range(NUM_SIMULACOES):
    sequencia = ""  
    sorteios = 0  
    while "AAA" not in sequencia and "OOO" not in sequencia:  
        resultado = random.choice(["A", "O"])  
        sequencia += resultado  
        sorteios += 1  
    print(sequencia, f"({sorteios} sorteios)")  
    resultados.append(sorteios)  
    total_sorteios += sorteios  

media_sorteios = total_sorteios / NUM_SIMULACOES  
print(f"\nNa média, foram necessários {media_sorteios:.1f} sorteios.")