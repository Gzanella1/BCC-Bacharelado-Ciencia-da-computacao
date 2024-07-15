#(0 °C × 9/5) + 32 = 32 °F
i=0
print("temperatura em °C \t temperatura em °F")
while i>=0 and i<=100:
    if(i %10==0):
        converção=((i)+9/5)+32
        print(i,"°C \t\t\t","A converção é ",converção,"°F")
    i=i+1
