
def calculo_valor_frete(qtd_itens):
    soma=0
    for i in range(qtd_itens):
        if(i==1):
            soma+=10.95
        else:
            soma+=2.95
    return soma
    
def main():
    qtd_iten=int(input("Digite a quantidade de intes: "))
    valor_total=calculo_valor_frete(qtd_iten)
    print(f"O valor total é: {valor_total:.2f}")

main()