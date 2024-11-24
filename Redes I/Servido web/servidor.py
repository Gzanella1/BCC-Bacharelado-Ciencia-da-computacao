import socket  # Biblioteca para trabalhar com conexões de rede (sockets)
import os  # Biblioteca para interagir com o sistema de arquivos

# Configurações do servidor
# Escuta em qualquer endereço(endereço do servidor), o '0.0.0.0' ouve todas as placas de redes disponiveis
host = 'localhost'  # Define que o servidor escuta em todas as interfaces de rede
porta = 6789  # Porta na qual o servidor estará escutando

# Criar o socket para comunicação

# AF_INET para IPv4, SOCK_STREAM para TCP
# AF_INET : informa que vou trabalhar com iP
# SOCK_STREAM: informa que vou trabalhar com tcp 
# Associa o socket ao endereço e porta definidos
servidor_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
# o objeto não sabe quem é o servidor e nem quem é a porta que ele tem que escutar 
servidor_socket.bind((host, porta)) 
# Coloca o servidor em modo de escuta para aceitar conexões
# listen é usado para indicar que ele esta pronto para aceitar conexẽos de dispositivos clientes 
servidor_socket.listen() 

print(f"Servidor iniciado em {host}:{porta}")  

while True:
    # Aceitar conexão de um cliente
    # accept : vai retornar 2 informações: retorna o endereço ip e o segundo é a porta de origem do cliente
    cliente_socket, endereco_cliente = servidor_socket.accept()  
    print(f"Conexão recebida de {endereco_cliente}")  

    # Receber a requisição HTTP do cliente

    # Ler a requisição HTTP, resposta do servidor 
    # 1024 bites, tamano maximo de dados que vou receber 
    requisicao = cliente_socket.recv(1024).decode()  
    print(f"Requisição recebida:\n{requisicao}")  # Exibe a requisição para debug

    # Processar a requisição HTTP
    
    # dvide o texto da requisição em linhas
    linhas = requisicao.split("\r\n") 
    # A primeira linha contém o método, caminho e versão do HTTP
    linha_requisicao = linhas[0] 
    # As demais linhas são os cabeçalhos da requisição
    # voce pode controlar a quantidade de linhas no cabeçalho
    cabecalhos = linhas[1:]  


    # uso isso para separar o metodo eo caminho 
    # para q o if abaixo identifique qual condição seguir 
    metodo, caminho, _ = linha_requisicao.split()  


    if metodo == "GET":  
        # Processar requisição GET
        # Remove a barra inicial e define o arquivo padrão como index.html
        caminho = caminho[1:] or 'index.html'  
        
        # Verifica se o arquivo solicitado existe
        if os.path.isfile(caminho):  
            # Abre o arquivo em modo de leitura binária
            with open(caminho, 'rb') as arquivo:  
                # Lê o conteúdo do arquivo
                conteudo = arquivo.read() 
            # Cria a resposta HTTP para sucesso 
            resposta = (  
                "HTTP/1.1 200 OK\r\n"
                f"Content-Length: {len(conteudo)}\r\n"  # Define o tamanho do conteúdo
                "Content-Type: text/html\r\n"  # Define o tipo de conteúdo como HTML
                "\r\n"
            ).encode() + conteudo  # Anexa o conteúdo do arquivo à resposta
        else:
            # Responde com erro 404 se o arquivo não existir
            resposta = (
                "HTTP/1.1 404 Not Found\r\n"
                "Content-Type: text/html\r\n"
                "\r\n"
                "<html><body><h1>404 Arquivo Não Encontrado</h1></body></html>"
            ).encode()


    # NÃO FOI PEDIDO PARA FAZER O METODO POST ( FIZ POR CURIOSIDADE )
    elif metodo == "POST":  
        # Processar requisição POST
        # Inicializa o tamanho do conteúdo como zero
        tamanho_conteudo = 0  

        # Percorre os cabeçalhos para encontrar "Content-Length"

        # quando o cliente realiza a requi http em um forms, o servidor precisa saber o tamanho do corpo da requisição para porcessar corretamente 
        # essa info ta no cabeçalho  como"Content-Length".
        # Este código percorre os cabeçalhos para encontrar esse valor
        for cabecalho in cabecalhos: 
            if cabecalho.lower().startswith("content-length:"):
                tamanho_conteudo = int(cabecalho.split(":")[1].strip())  # Obtém o valor do tamanho
                break

        # Lê o corpo da requisição com base no tamanho encontrado
        corpo = requisicao.split("\r\n\r\n", 1)[1][:tamanho_conteudo]

        print(f"Dados recebidos no POST: {corpo}")  

        # Cria uma resposta de sucesso ao cliente
        resposta = (
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "\r\n"
            f"<html><body><h1>Dados recebidos:</h1><pre>{corpo}</pre></body></html>"
        ).encode()



    # Enviar a resposta HTTP ao cliente
    cliente_socket.sendall(resposta)  # Envia a resposta completa ao cliente
    cliente_socket.close()  # Fecha a conexão com o cliente
