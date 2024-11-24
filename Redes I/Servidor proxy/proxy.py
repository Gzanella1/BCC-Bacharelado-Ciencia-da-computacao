import socket  # Biblioteca para comunicação em rede via sockets
from requisicao import processar_requisicao  # Importa a função que processa requisições de clientes

# Porta onde o servidor proxy vai escutar as conexões
# a porta 8888 como o ponto de entrada para o proxy 

# https://www.youtube.com/watch?v=dY1R92kXhVo 
# https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Access-Control-Request-Headers

PORTA_PROXY = 8888 
def iniciar_proxy():
    """
    Configura e inicia o servidor proxy para escutar conexões na porta especificada
    """
    # Criação de um socket do tipo TCP para o servidor proxy
    # AF_INET indica que estamos usando IPv4
    # SOCK_STREAM indica que o socket é do tipo TCP
    servidor_proxy = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Configuração adicional para reutilizar a mesma porta imediatamente após o término do processo
    # Isso evita problemas ao reiniciar o servidor rapidamente
    servidor_proxy.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    # Associação do socket à porta especificada (8888) no endereço localhost (127.0.0.1)
    servidor_proxy.bind(("localhost", PORTA_PROXY))

    # Coloca o socket em modo de escuta, permitindo aceitar conexões de clientes
    # O argumento 5 define o número máximo de conexões pendentes na fila de espera
    servidor_proxy.listen(5)
    print(f"Servidor proxy iniciado e aguardando conexões na porta {PORTA_PROXY}...")

    # Loop principal para aceitar conexões e processar requisições dos clientes
    while True:
        # Aceita uma nova conexão de um cliente
        # cliente_socket é o socket que representa a conexão com o cliente
        # endereco_cliente é uma tupla contendo o endereço IP e a porta do cliente
        cliente_socket, endereco_cliente = servidor_proxy.accept()
        print(f"Conexão estabelecida com {endereco_cliente}")

        # Chama a função para processar a requisição recebida do cliente
        # Passamos o socket e o endereço do cliente como argumentos
        processar_requisicao(cliente_socket, endereco_cliente)

# Verifica se o script está sendo executado diretamente
# Se for, chama a função iniciar_proxy para iniciar o servidor
if __name__ == "__main__":
    iniciar_proxy()
