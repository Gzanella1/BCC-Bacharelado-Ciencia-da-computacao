import socket

# Configurações do servidor
HOST = '0.0.0.0'  # Escuta em qualquer endereço(endereço do servidor), o '0.0.0.0' ouve todas as placas de redes disponiveis
PORT = 1717       # Porta para escutar conexões

# Criar o socket

servidor_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
servidor_socket.bind((HOST, PORT))
servidor_socket.listen()  # Escutar uma conexão por vez

print(f"Servidor iniciado em {HOST}:{PORT}")

while True:
    
    cliente_conexao, cliente_endereco = servidor_socket.accept()
    print(f"Conexão de {cliente_endereco}")


    # Ler a requisição HTTP, resposta do servidor 
    # 1024 bites, tamano maximo de dados que vou receber 
    request = cliente_conexao.recv(1024).decode()
    print(f"Requisição recebida:\n{request}")

    # Processar o caminho solicitado
    try:
        path = request.split(' ')[1][1:]  # Extrair o caminho após "GET /"
        if not path:
            path = 'index.html'  # Padrão para index.html
        
        # Tentar abrir o arquivo solicitado
        with open(path, 'rb') as file:
            content = file.read()

        # Construir resposta HTTP
        response = (
            "HTTP/1.1 200 OK\r\n"
            f"Content-Length: {len(content)}\r\n"
            "Content-Type: text/html\r\n"
            "\r\n"
        ).encode() + content

    except FileNotFoundError:
        # Arquivo não encontrado, enviar erro 404
        response = (
            "HTTP/1.1 404 Not Found\r\n"
            "Content-Type: text/html\r\n"
            "\r\n"
            "<html><body><h1>404 Not Found</h1></body></html>"
        ).encode()

    # Enviar a resposta ao cliente
    cliente_conexao.sendall(response)
    cliente_conexao.close()
