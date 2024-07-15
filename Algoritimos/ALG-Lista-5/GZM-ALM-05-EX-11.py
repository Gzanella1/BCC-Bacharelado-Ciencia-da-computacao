import random

def geradorDeSenhas():
    #definir o tamanho da senha, de forma aleatoriamente nos intevalos 
    temanhoSenha=random.randint(7,10)
    #variavel para armazenar os caracteres gerado no FOR
    senha=""
    #percore o tamanho da senha gerado automaticamente
    for i in range(temanhoSenha):
        #gera um numeros aleatorios a cada rodada entre 33-126 e o chr e responsavel por converter para o caracteres ta tabela ascii
        #o chr pega um numero e colocar no seu caracter corespondente da tabela ascii
        geraUMcaracter=chr(random.randint(33,126))
        #a cada rodada adiciona um caracre por vez na strig senha
        senha+=geraUMcaracter
    return senha


def main():
    senhaAleatoria=geradorDeSenhas()
    print("--GERADOR DE SENHAS---")
    print("Senha: ", senhaAleatoria)


main()