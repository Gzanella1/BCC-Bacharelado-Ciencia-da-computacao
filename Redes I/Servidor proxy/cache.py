import os  # Biblioteca para manipulação de diretórios e arquivos

# Diretório onde os arquivos de cache serão armazenados
DIRETORIO_CACHE = "cache"

# Certifica-se de que o diretório de cache existe
# Se o diretório não existir, ele será criado
if not os.path.exists(DIRETORIO_CACHE):
    os.makedirs(DIRETORIO_CACHE)

def verificar_cache(host, caminho):
    """
    Verifica se uma resposta já está armazenada no cache.

    Este método busca no cache local (diretório `DIRETORIO_CACHE`) uma resposta associada
    ao host e ao caminho fornecidos. Caso o arquivo correspondente exista, seu conteúdo
    será retornado; caso contrário, a função retorna `None`.

    :param host: Nome do host remoto (ex.: www.exemplo.com).
    :param caminho: Caminho do recurso no servidor remoto (ex.: /index.html).
    :return: Dados armazenados em cache (em bytes), se existirem; caso contrário, None.
    """
    # Criação do nome do arquivo baseado no host e no caminho
    # Substitui barras no caminho por underscores para evitar problemas no sistema de arquivos
    nome_arquivo = os.path.join(DIRETORIO_CACHE, host + caminho.replace("/", "_"))

    # Verifica se o arquivo correspondente existe no cache
    if os.path.exists(nome_arquivo):
        # Caso o arquivo exista, ele é aberto no modo binário de leitura
        with open(nome_arquivo, "rb") as arquivo_cache:
            return arquivo_cache.read()  # Retorna o conteúdo do arquivo
    return None  # Retorna None caso o arquivo não exista

def salvar_no_cache(host, caminho, dados):
    """
    Salva dados no cache local.

    Este método cria um arquivo no diretório de cache para armazenar os dados
    recebidos de uma resposta do servidor remoto, associando-os ao host e caminho fornecidos.

    :param host: Nome do host remoto (ex.: www.exemplo.com).
    :param caminho: Caminho do recurso no servidor remoto (ex.: /index.html).
    :param dados: Dados a serem armazenados (em bytes).
    """
    # Criação do nome do arquivo baseado no host e no caminho
    # Substitui barras no caminho por underscores para evitar conflitos com o sistema de arquivos
    nome_arquivo = os.path.join(DIRETORIO_CACHE, host + caminho.replace("/", "_"))

    # Abre o arquivo no modo binário de escrita, criando-o se não existir
    # Os dados são escritos no arquivo
    with open(nome_arquivo, "wb") as arquivo_cache:
        arquivo_cache.write(dados)  # Escreve os dados recebidos no arquivo
