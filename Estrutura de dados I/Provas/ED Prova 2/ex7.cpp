#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

// Estrutura para armazenar os dados do estudante
struct Estudante {
    int id; // ID do estudante
    std::string nome; // Nome do estudante
    std::string dataNascimento; // Data de nascimento do estudante
    std::string digitoIdentificador; // Digito identificador do estudante
};

// Estrutura para o nó da lista duplamente ligada
struct No {
    Estudante estudante; // Dados do estudante
    No* proximo; // Ponteiro para o próximo nó
    No* anterior; // Ponteiro para o nó anterior
};

// Estrutura para o nó da árvore AVL
struct NoAVL {
    int id; // ID do estudante
    No* estudanteNo; // Ponteiro para o nó da lista duplamente ligada
    NoAVL* esquerda; // Ponteiro para o filho à esquerda
    NoAVL* direita; // Ponteiro para o filho à direita
    int altura; // Altura do nó na árvore

    NoAVL(int i, No* no) : id(i), estudanteNo(no), esquerda(nullptr), direita(nullptr), altura(1) {}
};

// Classe para a lista duplamente ligada
class ListaDuplamenteLigada {
private:
    No* inicio; // Ponteiro para o início da lista
    No* fim; // Ponteiro para o fim da lista
    int proximoId; // ID do próximo estudante a ser adicionado

public:
    ListaDuplamenteLigada() : inicio(nullptr), fim(nullptr), proximoId(1) {}

    // Adiciona um estudante à lista
    void adicionarEstudante(const std::string& nome, const std::string& dataNascimento, const std::string& digitoIdentificador) {
        if (digitoIdentificador.length() < 9) {
            std::cerr << "Erro: o digito identificador deve ter até 9 caracteres." << std::endl;
            return;
        }

        Estudante estudante = { proximoId++, nome, dataNascimento, digitoIdentificador };
        No* novoNo = new No{ estudante, inicio, nullptr };

        if (inicio) {
            inicio->anterior = novoNo;
        } else {
            fim = novoNo;
        }

        inicio = novoNo;
    }

    // Busca um estudante pelo ID
    No* buscarPorId(int id) const {
        No* atual = inicio;
        while (atual) {
            if (atual->estudante.id == id) {
                return atual;
            }
            atual = atual->proximo;
        }
        return nullptr;
    }

    // Busca um estudante pelo nome
    No* buscarPorNome(const std::string& nome) const {
        No* atual = inicio;
        while (atual) {
            if (atual->estudante.nome == nome) {
                return atual;
            }
            atual = atual->proximo;
        }
        return nullptr;
    }

    // Lê estudantes de um arquivo CSV e adiciona à lista
    void lerArquivoCSV(const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
            return;
        }

        std::string linha;
        std::vector<std::string> dados;

        // Lê o arquivo CSV linha por linha
        while (std::getline(arquivo, linha)) {
            dados.push_back(linha);
        }

        arquivo.close();

        // Adiciona estudantes à lista com base nas linhas do CSV
        for (size_t i = 0; i < dados.size(); i += 3) {
            if (i + 2 < dados.size()) {
                std::string nome = dados[i];
                std::string dataNascimento = dados[i + 1];
                std::string digitoIdentificador = dados[i + 2];
                
                if (!nome.empty() && !dataNascimento.empty() && !digitoIdentificador.empty()) {
                    adicionarEstudante(nome, dataNascimento, digitoIdentificador);
                } else {
                    std::cerr << "Erro: Dados inválidos no arquivo CSV." << std::endl;
                }
            } else {
                std::cerr << "Erro: Dados insuficientes no arquivo CSV." << std::endl;
            }
        }
    }

    // Remove um estudante da lista pelo ID
    void removerPorId(int id) {
        No* noParaRemover = buscarPorId(id);
        if (!noParaRemover) {
            std::cerr << "Estudante com ID " << id << " não encontrado." << std::endl;
            return;
        }

        if (noParaRemover->anterior) {
            noParaRemover->anterior->proximo = noParaRemover->proximo;
        } else {
            inicio = noParaRemover->proximo;
        }

        if (noParaRemover->proximo) {
            noParaRemover->proximo->anterior = noParaRemover->anterior;
        } else {
            fim = noParaRemover->anterior;
        }

        delete noParaRemover;
    }

    // Remove um estudante da lista pelo nome
    void removerPorNome(const std::string& nome) {
        No* noParaRemover = buscarPorNome(nome);
        if (!noParaRemover) {
            std::cerr << "Estudante com nome " << nome << " não encontrado." << std::endl;
            return;
        }

        if (noParaRemover->anterior) {
            noParaRemover->anterior->proximo = noParaRemover->proximo;
        } else {
            inicio = noParaRemover->proximo;
        }

        if (noParaRemover->proximo) {
            noParaRemover->proximo->anterior = noParaRemover->anterior;
        } else {
            fim = noParaRemover->anterior;
        }

        delete noParaRemover;
    }

    ~ListaDuplamenteLigada() {
        No* atual = inicio;
        while (atual) {
            No* proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
    }

    // Método para obter o início da lista
    No* obterInicio() const { return inicio; }

    // Contar o número de nós na lista
    int contarNos() const {
        int contador = 0;
        No* atual = inicio;
        while (atual) {
            contador++;
            atual = atual->proximo;
        }
        return contador;
    }
};

// Classe para a árvore AVL
class ArvoreAVL {
private:
    NoAVL* raiz; // Raiz da árvore AVL

    // Calcula a altura de um nó
    int altura(NoAVL* no) const {
        return no ? no->altura : 0;
    }

    // Calcula o fator de balanceamento de um nó
    int fatorBalanceamento(NoAVL* no) const {
        return no ? altura(no->esquerda) - altura(no->direita) : 0;
    }

    // Realiza uma rotação à direita para balancear a árvore
    NoAVL* rotacaoDireita(NoAVL* y) {
        NoAVL* x = y->esquerda;
        NoAVL* T2 = x->direita;

        x->direita = y;
        y->esquerda = T2;

        y->altura = std::max(altura(y->esquerda), altura(y->direita)) + 1;
        x->altura = std::max(altura(x->esquerda), altura(x->direita)) + 1;

        return x;
    }

    // Realiza uma rotação à esquerda para balancear a árvore
    NoAVL* rotacaoEsquerda(NoAVL* x) {
        NoAVL* y = x->direita;
        NoAVL* T2 = y->esquerda;

        y->esquerda = x;
        x->direita = T2;

        x->altura = std::max(altura(x->esquerda), altura(x->direita)) + 1;
        y->altura = std::max(altura(y->esquerda), altura(y->direita)) + 1;

        return y;
    }

    // Balanceia a árvore após inserção ou remoção
    NoAVL* balancear(NoAVL* no) {
        int balanceamento = fatorBalanceamento(no);

        // Rotação à direita
        if (balanceamento >= 1) {
            if (fatorBalanceamento(no->esquerda) < 0) {
                no->esquerda = rotacaoEsquerda(no->esquerda);
            }
            return rotacaoDireita(no);
        }

        // Rotação à esquerda
        if (balanceamento <= -1) {
            if (fatorBalanceamento(no->direita) > 0) {
                no->direita = rotacaoDireita(no->direita);
            }
            return rotacaoEsquerda(no);
        }

        return no;
    }

    // Insere um novo estudante na árvore AVL
    NoAVL* inserir(NoAVL* no, int id, No* estudanteNo) {
        if (!no) return new NoAVL(id, estudanteNo);

        if (id < no->id) {
            no->esquerda = inserir(no->esquerda, id, estudanteNo);
        } else if (id > no->id) {
            no->direita = inserir(no->direita, id, estudanteNo);
        } else {
            return no;
        }

        no->altura = std::max(altura(no->esquerda), altura(no->direita)) + 1;
        return balancear(no);
    }

    // Remove um estudante da árvore AVL
    NoAVL* remover(NoAVL* no, int id) {
        if (!no) return no;

        if (id < no->id) {
            no->esquerda = remover(no->esquerda, id);
        } else if (id > no->id) {
            no->direita = remover(no->direita, id);
        } else {
            if (!no->esquerda) {
                NoAVL* temp = no->direita;
                delete no;
                return temp;
            } else if (!no->direita) {
                NoAVL* temp = no->esquerda;
                delete no;
                return temp;
            }

            NoAVL* temp = no->direita;
            while (temp->esquerda) {
                temp = temp->esquerda;
            }

            no->id = temp->id;
            no->estudanteNo = temp->estudanteNo;
            no->direita = remover(no->direita, temp->id);
        }

        no->altura = std::max(altura(no->esquerda), altura(no->direita)) + 1;
        return balancear(no);
    }

    // Busca um estudante pelo ID
    NoAVL* buscar(NoAVL* no, int id) const {
        if (!no || no->id == id) return no;

        if (id < no->id) return buscar(no->esquerda, id);
        return buscar(no->direita, id);
    }

    // Imprime os dados da árvore em ordem
    void imprimirEmOrdem(NoAVL* no) const {
        if (no) {
            imprimirEmOrdem(no->esquerda);
            std::cout << "ID: " << no->id
                      << ", Nome: " << no->estudanteNo->estudante.nome
                      << ", Data de Nascimento: " << no->estudanteNo->estudante.dataNascimento
                      << ", Digito Identificador: " << no->estudanteNo->estudante.digitoIdentificador << std::endl;
            imprimirEmOrdem(no->direita);
        }
    }

    // Verifica se a árvore está balanceada
    bool verificarBalanceamento(NoAVL* no) const {
        if (!no) {
            return true;
        }

        int fator = fatorBalanceamento(no);
        return (fator >= -1 && fator <= 1) &&
               verificarBalanceamento(no->esquerda) &&
               verificarBalanceamento(no->direita);
    }

    // Conta o número de nós na árvore
    int contarNos(NoAVL* no) const {
        if (!no) return 0;
        return 1 + contarNos(no->esquerda) + contarNos(no->direita);
    }

    // Libera a memória alocada para a árvore
    void liberar(NoAVL* no) {
        if (no) {
            liberar(no->esquerda);
            liberar(no->direita);
            delete no;
        }
    }

public:
    ArvoreAVL() : raiz(nullptr) {}

    // Insere um novo estudante na árvore
    void inserir(int id, No* estudanteNo) {
        raiz = inserir(raiz, id, estudanteNo);
    }

    // Remove um estudante da árvore pelo ID
    void remover(int id) {
        raiz = remover(raiz, id);
    }

    // Busca um estudante pelo ID
    No* buscar(int id) const {
        NoAVL* no = buscar(raiz, id);
        return no ? no->estudanteNo : nullptr;
    }

    // Verifica se a árvore está balanceada
    bool verificarBalanceamento() const {
        return verificarBalanceamento(raiz);
    }

    // Função pública para impressão em ordem
    void imprimirEmOrdem() const {
        imprimirEmOrdem(raiz);
    }

    // Função pública para contar o número de nós
    int contarNos() const {
        return contarNos(raiz);
    }

    ~ArvoreAVL() {
        liberar(raiz);
    }
};

// Função para testar a remoção por ID
void testeRemocaoPorId(ArvoreAVL& arvore, ListaDuplamenteLigada& lista) {
    int idRemocao;
    std::cout << "Digite o ID do estudante para remoção: ";
    std::cin >> idRemocao;
    std::cin.ignore(); // Ignorar o caractere de nova linha após a entrada do ID

    No* estudanteParaRemover = arvore.buscar(idRemocao);
    if (estudanteParaRemover) {
        // Remove o estudante da árvore AVL
        arvore.remover(idRemocao);
        // Remove o estudante da lista duplamente ligada
        lista.removerPorId(idRemocao);
        std::cout << "Estudante com ID " << idRemocao << " removido com sucesso." << std::endl;
    } else {
        std::cout << "Estudante com ID " << idRemocao << " não encontrado." << std::endl;
    }
}

// Função para testar a remoção por nome
void testeRemocaoPorNome(ArvoreAVL& arvore, ListaDuplamenteLigada& lista) {
    std::string nomeRemocao;
    std::cout << "Digite o nome do estudante para remoção: ";
    std::getline(std::cin, nomeRemocao);

    No* estudanteParaRemover = lista.buscarPorNome(nomeRemocao);
    if (estudanteParaRemover) {
        // Remove o estudante da árvore AVL pelo ID
        arvore.remover(estudanteParaRemover->estudante.id);
        // Remove o estudante da lista duplamente ligada
        lista.removerPorNome(nomeRemocao);
        std::cout << "Estudante com nome " << nomeRemocao << " removido com sucesso." << std::endl;
    } else {
        std::cout << "Estudante com nome " << nomeRemocao << " não encontrado." << std::endl;
    }
}

int main() {
    ListaDuplamenteLigada lista;
    ArvoreAVL arvore;

    // Ler estudantes de um arquivo CSV e adicionar à lista
    lista.lerArquivoCSV("bla.csv");

    // Indexar os estudantes na árvore AVL
    No* atual = lista.obterInicio();
    while (atual) {
        arvore.inserir(atual->estudante.id, atual); // Indexa o estudante na árvore AVL
        atual = atual->proximo;
    }

    // Verificar se a árvore está balanceada
    if (arvore.verificarBalanceamento()) {
        std::cout << "A árvore AVL está balanceada." << std::endl;
    } else {
        std::cout << "A árvore AVL NÃO está balanceada." << std::endl;
    }

    // Testar a remoção por ID
    testeRemocaoPorId(arvore, lista);

    // Testar a remoção por Nome
    testeRemocaoPorNome(arvore, lista);

    // Imprimir o cadastro dos estudantes em ordem
    std::cout << "Cadastro dos estudantes em ordem:" << std::endl;
    arvore.imprimirEmOrdem();

    // Contar e exibir o número de nós
    std::cout << "Número de nós na lista duplamente ligada: " << lista.contarNos() << std::endl;
    std::cout << "Número de nós na árvore AVL (por ID): " << arvore.contarNos() << std::endl;

    return 0;
}
