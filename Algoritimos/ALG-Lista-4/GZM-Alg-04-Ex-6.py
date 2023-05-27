while True:
    palavra=input("digite 8 bits entre (0 e 1): ")
    if (palavra == " "):
        break
    
    if(len(palavra) != 8):
      continue

    
    qtd=palavra.count("1")
    if(qtd %2 ==0):
        print("O bit de paridade é 1")
    else:
        print("O bit de paridade é 0")

