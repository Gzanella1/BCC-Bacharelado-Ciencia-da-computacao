import string

def palindromo(palavra):
    p=palavra.lower().translate(str.maketrans('', '', string.punctuation)).replace(" ", "")
    if (len(p)==0):
        return False
    elif(len(p) ==1):
        return  True
    elif(p[0] != p[-1]):def palindromo(s):
    return True if len(s) <= 1 else s[0] == s[-1] and palindromo(s[1:-1])


print(palindromo("abcddcba"))

        return False
    else:
        return palindromo(p[1:-1])
        
    


def main():
    palavra=input("digite um numero para saber o fatorial: ")
    palindromos=palindromo(palavra)
    print(palindromos)

main()

#outra forma mais simples de fazer

def palindromo(s):
    return True if len(s) <= 1 else s[0] == s[-1] and palindromo(s[1:-1])

print(palindromo("abcddcba"))
