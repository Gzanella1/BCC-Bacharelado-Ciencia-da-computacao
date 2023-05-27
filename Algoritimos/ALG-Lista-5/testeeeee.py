def hex2int(n):
    if n.isdigit():
        return int(n)
    else:
        if (ord(n.upper())-55) <= 15:
            return ord(n.upper())-55


def main():
    n = input("digite: ")
    converter = hex2int(n)
    print(converter)


main()
