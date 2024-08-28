#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <memory>

// Estrutura para armazenar os dados do estudante
struct Estudante {
    int id;
    std::string nome;
    std::string dataNascimento;
    std::string digitoIdentificador;
};

// Estrutura para o nó da lista duplamente ligada
struct No {
    Estudante estudante;
    No* proximo;
    No* anterior;
};

// Estrutura para o nó da árvore binária de busca (BST)
struct NoBST {
    std::string nome;
    No* estudanteNo;
    NoBST* esquerda;
    NoBST* direita;

    NoBST(const std::string& n, No* no) : nome(n), estudanteNo(no), esquerda(nullptr), direita(nullptr) {}
};

// Classe para a lista duplamente ligada
class ListaDuplamenteLigada {
private:
    No* inicio;
    No* fim;
    int proximoId;

public:
    ListaDuplamenteLigada() : inicio(nullptr), fim(nullptr), proximoId(1) {}

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

    void lerArquivoCSV(const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
            return;
        }

        std::string linha;
        std::vector<std::string> dados;

        while (std::getline(arquivo, linha)) {
            dados.push_back(linha);
        }

        arquivo.close();

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
};

///---------------------------------------------------------------------------------------------------------------------------------------------
// Classe para a árvore binária de busca (BST) para indexação
class ArvoreBinariaBusca {
private:
    NoBST* raiz;

    NoBST* inserir(NoBST* no, const std::string& nome, No* estudanteNo) {
        if (!no) {
            return new NoBST(nome, estudanteNo);
        }
        if (nome < no->nome) {
            no->esquerda = inserir(no->esquerda, nome, estudanteNo);
        } else if (nome > no->nome) {
            no->direita = inserir(no->direita, nome, estudanteNo);
        }
        return no;
    }

    NoBST* buscar(NoBST* no, const std::string& nome) const {
        if (!no || no->nome == nome) {
            return no;
        }
        if (nome < no->nome) {
            return buscar(no->esquerda, nome);
        }
        return buscar(no->direita, nome);
    }

    void liberar(NoBST* no) {
        if (no) {
            liberar(no->esquerda);
            liberar(no->direita);
            delete no;
        }
    }

public:
    ArvoreBinariaBusca() : raiz(nullptr) {}

    void inserir(const std::string& nome, No* estudanteNo) {
        raiz = inserir(raiz, nome, estudanteNo);
    }

    No* buscar(const std::string& nome) const {
        NoBST* no = buscar(raiz, nome);
        return no ? no->estudanteNo : nullptr;
    }

    ~ArvoreBinariaBusca() {
        liberar(raiz);
    }
};

// Função para testar a busca
void testeBusca(ArvoreBinariaBusca& arvore, ListaDuplamenteLigada& lista) {
    std::string nomeBusca;
    std::cout << "Digite o nome do estudante para busca: ";
    std::getline(std::cin, nomeBusca);

    No* estudanteEncontrado = arvore.buscar(nomeBusca);
    if (estudanteEncontrado) {
        std::cout << "Estudante encontrado: ID: " << estudanteEncontrado->estudante.id
                  << ", Nome: " << estudanteEncontrado->estudante.nome
                  << ", Data de Nascimento: " << estudanteEncontrado->estudante.dataNascimento
                  << ", Digito Identificador: " << estudanteEncontrado->estudante.digitoIdentificador << std::endl;
    } else {
        std::cout << "Estudante com o nome \"" << nomeBusca << "\" não encontrado." << std::endl;
    }
}

int main() {
    ListaDuplamenteLigada lista;
    ArvoreBinariaBusca arvore;

    // Ler estudantes de um arquivo CSV e adicionar à lista
    lista.lerArquivoCSV("bla.csv");

    // Indexar os estudantes na árvore binária de busca
    No* atual = lista.obterInicio();
    while (atual) {
        arvore.inserir(atual->estudante.nome, atual);
        atual = atual->proximo;
    }

    // Testar a busca por nome
    testeBusca(arvore, lista);

    return 0;
}
