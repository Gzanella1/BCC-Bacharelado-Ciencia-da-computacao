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
        if (balanceamento < -1) {
            if (fatorBalanceamento(no->direita) > 0) {
                no->direita = rotacaoDireita(no->direita);
            }
            return rotacaoEsquerda(no);
        }

        return no;
    }

    // Insere um novo nó na árvore
    NoAVL* inserir(NoAVL* no, int id, No* estudanteNo) {
        if (!no) {
            return new NoAVL(id, estudanteNo);
        }

        if (id < no->id) {
            no->esquerda = inserir(no->esquerda, id, estudanteNo);
        } else if (id > no->id) {
            no->direita = inserir(no->direita, id, estudanteNo);
        } else {
            return no; // IDs duplicados não são permitidos
        }

        no->altura = std::max(altura(no->esquerda), altura(no->direita)) + 1;

        return balancear(no);
    }

    // Busca um nó na árvore
    NoAVL* buscar(NoAVL* no, int id) const {
        if (!no || no->id == id) {
            return no;
        }

        if (id < no->id) {
            return buscar(no->esquerda, id);
        }
        return buscar(no->direita, id);
    }

    // Libera a memória da árvore
    void liberar(NoAVL* no) {
        if (no) {
            liberar(no->esquerda);
            liberar(no->direita);
            delete no;
        }
    }

    // Função para contar o número de nós na árvore
    int contarNos(NoAVL* no) const {
        if (!no) {
            return 0;
        }
        return 1 + contarNos(no->esquerda) + contarNos(no->direita);
    }

    // Função para imprimir a árvore em ordem
    void imprimirEmOrdem(NoAVL* no) const { // Questão 5
        if (no) {
            imprimirEmOrdem(no->esquerda); // Visita o filho à esquerda
            std::cout << "ID: " << no->id
                      << ", Nome: " << no->estudanteNo->estudante.nome
                      << ", Data de Nascimento: " << no->estudanteNo->estudante.dataNascimento
                      << ", Digito Identificador: " << no->estudanteNo->estudante.digitoIdentificador << std::endl; // Exibe o estudante
            imprimirEmOrdem(no->direita); // Visita o filho à direita
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

public:
    ArvoreAVL() : raiz(nullptr) {}

    // Insere um novo estudante na árvore
    void inserir(int id, No* estudanteNo) {
        raiz = inserir(raiz, id, estudanteNo);
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
    void imprimirEmOrdem() const { // Questão 5
        imprimirEmOrdem(raiz); // Chama a função de impressão em ordem
    }

    // Função pública para contar o número de nós
    int contarNos() const {
        return contarNos(raiz);
    }

    ~ArvoreAVL() {
        liberar(raiz);
    }
};

// Função para testar a busca por ID
void testeBusca(ArvoreAVL& arvore, ListaDuplamenteLigada& lista) {
    int idBusca;
    std::cout << "Digite o ID do estudante para busca: ";
    std::cin >> idBusca;
    std::cin.ignore(); // Ignorar o caractere de nova linha após a entrada do ID

    No* estudanteEncontrado = arvore.buscar(idBusca); // Letra A: Busca pelo ID
    if (estudanteEncontrado) {
        std::cout << "Estudante encontrado: ID: " << estudanteEncontrado->estudante.id
                  << ", Nome: " << estudanteEncontrado->estudante.nome
                  << ", Data de Nascimento: " << estudanteEncontrado->estudante.dataNascimento
                  << ", Digito Identificador: " << estudanteEncontrado->estudante.digitoIdentificador << std::endl;
    } else {
        std::cout << "Estudante com ID " << idBusca << " não encontrado." << std::endl;
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
        arvore.inserir(atual->estudante.id, atual); // Letra A: Indexa o estudante na árvore AVL
        atual = atual->proximo;
    }

    // Verificar se a árvore está balanceada
    if (arvore.verificarBalanceamento()) { // Letra B: Verifica o balanceamento da árvore
        std::cout << "A árvore AVL está balanceada." << std::endl;
    } else {
        std::cout << "A árvore AVL NÃO está balanceada." << std::endl;
    }

    // Testar a busca por ID
    testeBusca(arvore, lista);

    // Imprimir o cadastro dos estudantes em ordem
    std::cout << "Cadastro dos estudantes em ordem:" << std::endl;
    arvore.imprimirEmOrdem(); // Questão 5

    // Contar e exibir o número de nós
    std::cout << "Número de nós na lista duplamente ligada: " << lista.contarNos() << std::endl;
    std::cout << "Número de nós na árvore AVL (por ID): " << arvore.contarNos() << std::endl;

    return 0;
}
