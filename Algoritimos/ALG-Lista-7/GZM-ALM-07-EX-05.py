def anagrama(p1,p2):
    dp1={}
    for chave in p1:
        dp1[chave]=p1.count(chave)
    #print(dp1)

    dp2={}
    for chave in p2:
        dp2[chave]=p2.count(chave)    
    #print(dp2)


    if len(dp1) != len(dp2):
        return False
    else:
        #conjentos de chave da palavra 1
        c1=set(dp1)
        #conjuntos da palavra 2
        c2=set(dp2)
        if c1==c2:
            if dp1[chave] == dp2[chave]:
                return True
        else:
            return  False


def main():
    p1=input("digite uma palavra: ")
    p2=input("digite uma palavra: ")
    print(anagrama(p1,p2))

main()
