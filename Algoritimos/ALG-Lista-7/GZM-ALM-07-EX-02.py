def diferenca_simetrica(m,n):
    c1 = m.union(n)
    c2 = m.intersection(n)

    return c1.difference(c2)

def main():
    m={1,2,3,4,5,6}
    n={1,2,7,8,9,10}
    print(diferenca_simetrica(m,n))


main()
