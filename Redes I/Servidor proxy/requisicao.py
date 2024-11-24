import socket  # Biblioteca para comunicação via sockets
from urllib.parse import urlparse  # Para manipular e analisar URLs
from cache import verificar_cache, salvar_no_cache  # Funções para manipulação do cache

def processar_requisicao(socket_cliente, endereco_cliente):
    """
    Processa a requisição recebida de um cliente, realizando validação, consulta ao cache
    e, se necessário, comunicação com o servidor remoto para obter a resposta.

    :param socket_cliente: Socket da conexão estabelecida com o cliente.
    :param endereco_cliente: Endereço do cliente conectado.
    """
    try:
        # Recebe a requisição enviada pelo cliente no socket
        requisicao = socket_cliente.recv(4096).decode('utf-8')  # Decodifica os dados recebidos
        print(f"Requisição recebida de {endereco_cliente}:\n{requisicao}\n")

        # Extração da primeira linha da requisição HTTP (contém método e URL)
        linha_inicial = requisicao.split("\r\n")[0]
        metodo, caminho_completo, _ = linha_inicial.split()

        # Verifica se o método HTTP utilizado é suportado (apenas GET é aceito)
        if metodo != "GET":
            # Responde com erro 405 (Método não permitido) e encerra a conexão
            socket_cliente.sendall(b"HTTP/1.1 405 Method Not Allowed\r\n\r\n")
            socket_cliente.close()
            return

        # Remove o prefixo "/http://" ou "/https://" para extrair a URL completa
        if caminho_completo.startswith("/http://") or caminho_completo.startswith("/https://"):
            url_completa = caminho_completo[1:]  # Remove o primeiro caractere "/"
        else:
            # Caso a URL seja inválida, responde com erro 400 (Requisição inválida)
            socket_cliente.sendall(b"HTTP/1.1 400 Bad Request\r\n\r\n")
            socket_cliente.close()
            return

        # Analisa a URL completa para separar componentes como host e caminho
        url_analisada = urlparse(url_completa)
        nome_host = url_analisada.hostname  # Obtém o nome do host (exemplo: www.google.com)
        caminho = url_analisada.path if url_analisada.path else "/"  # Define o caminho da requisição

        # Verifica se a URL é válida, caso contrário responde com erro 400
        if not nome_host:
            socket_cliente.sendall(b"HTTP/1.1 400 Bad Request\r\n\r\n")
            socket_cliente.close()
            return

        # Verifica no cache se já existe uma resposta armazenada para essa requisição
        dados_cache = verificar_cache(nome_host, caminho)
        if dados_cache:
            print("Servindo conteúdo do cache.")  # Informa que está usando o cache
            socket_cliente.sendall(dados_cache)  # Envia os dados do cache ao cliente
            socket_cliente.close()  # Fecha a conexão com o cliente
            return

        # Caso não haja cache, conecta ao servidor remoto
        socket_servidor = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # Cria socket TCP para o servidor remoto
        socket_servidor.connect((nome_host, 80))  # Conecta na porta 80 (HTTP padrão)

        # Cria a requisição HTTP para o servidor remoto
        requisicao_servidor = f"GET {caminho} HTTP/1.1\r\nHost: {nome_host}\r\nConnection: close\r\n\r\n"
        socket_servidor.sendall(requisicao_servidor.encode('utf-8'))  # Envia a requisição ao servidor remoto

        # Recebe a resposta do servidor remoto em blocos (chunks)
        resposta_servidor = b""  # Variável para armazenar a resposta
        while True:
            dados = socket_servidor.recv(4096)  # Lê até 4096 bytes por vez
            if not dados:  # Se não houver mais dados, encerra a leitura
                break
            resposta_servidor += dados  # Acumula os dados recebidos

        socket_servidor.close()  # Fecha a conexão com o servidor remoto

        # Salva a resposta no cache para futuras requisições iguais
        salvar_no_cache(nome_host, caminho, resposta_servidor)

        # Envia a resposta recebida do servidor remoto ao cliente
        socket_cliente.sendall(resposta_servidor)
        socket_cliente.close()  # Encerra a conexão com o cliente

    except Exception as erro:
        # Em caso de erro, envia uma resposta de erro genérica ao cliente
        print(f"Erro ao processar requisição: {erro}")  # Log do erro no console
        socket_cliente.sendall(b"HTTP/1.1 500 Internal Server Error\r\n\r\n")  # Envia erro 500
        socket_cliente.close()  # Fecha a conexão com o cliente
