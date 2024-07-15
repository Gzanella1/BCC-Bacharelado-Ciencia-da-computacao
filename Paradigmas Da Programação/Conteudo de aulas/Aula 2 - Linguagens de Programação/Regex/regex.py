import re

# Exemplo de uso de regex para encontrar o padrão de um endereço de e-mail
padrao = r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,7}\b'

# Frase utilizada como exemplo
frase = "Anota aí o meu contato! É ricardo.ladeira@ifc.edu.br"

# Cria uma lista contendo os e-mails encontrados
email = re.search(padrao, frase)

# Imprime o primeiro resultado dessa lista
print(email.group(0))