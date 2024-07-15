def verifica_palavra(s):
    conjuntos= set()
    for carater in s:
        conjuntos.add(carater)
    if len(conjuntos)== len(s):
        return True
    return False

def main():
    s=input("digite uma palavra: ")
    print(verifica_palavra(s))


main()
