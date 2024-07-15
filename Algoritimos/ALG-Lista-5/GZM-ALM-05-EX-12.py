def main():
    senha=input("Digite uma senha para saber se ela é valida: ")
    if(senha_valida(senha)):
        print("A senha é valida!")
    else:
        print("A senha NÃO é valida!")
    

def senha_valida(senha):
    return mais_de_oito_caracteres(senha) and possui_letras_maiuscula(senha) and possui_letras_minuscula(senha) and possui_numero(senha)


def mais_de_oito_caracteres(senha):
    if(len(senha) >=8):
        return True
    return False

def possui_letras_maiuscula(senha):
    for i in senha:
        if(i.isupper()):
            return True
    return False

def possui_letras_minuscula(senha):
    for i in senha:
        if (i.islower()):
            return True
    return False

def possui_numero(senha):
    for i in senha:
        if(i.isdigit()):
            return True
    return False


    

main()

"""def has_length(password):
    return len(password) > 8

def has_lowercase(password):
    return any(char.islower() for char in password)

def has_uppercase(password):
    return any(char.isupper() for char in password)

def has_number(password):
    return any(char.isdigit() for char in password)

def is_valid_password(password):
    return has_length(password) and has_lowercase(password) and has_uppercase(password) and has_number(password)
"""
