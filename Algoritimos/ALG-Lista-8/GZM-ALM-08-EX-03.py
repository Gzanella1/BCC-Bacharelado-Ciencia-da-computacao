import string

def palindromo(palavra):
    p=palavra.lower().translate(str.maketrans('', '', string.punctuation)).replace(" ", "")
    if (len(p)==0):
        return False
    elif(len(p) ==1):
        return  True
    elif(p[0] != p[-1]):
        return False
    else:
        return palindromo(p[1:-1])
        
    


def main():
    palavra=input("digite um numero para saber o fatorial: ")
    palindromos=palindromo(palavra)
    print(palindromos)

main()
