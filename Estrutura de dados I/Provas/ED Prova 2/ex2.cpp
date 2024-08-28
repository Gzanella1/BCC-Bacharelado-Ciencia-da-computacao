#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

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

// Classe para a lista duplamente ligada
class ListaDuplamenteLigada {
private:
    No* inicio;
    No* fim;
    int proximoId;

public:
    ListaDuplamenteLigada() : inicio(nullptr), fim(nullptr), proximoId(1) {}

    void adicionarEstudante(const std::string& nome, const std::string& dataNascimento, const std::string& digitoIdentificador) {
        if (digitoIdentificador.length() > 9) {
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

    void exibirEstudantes() const {
        No* atual = inicio;
        while (atual) {
            std::cout << "ID: " << atual->estudante.id
                      << ", Nome: " << atual->estudante.nome
                      << ", Data de Nascimento: " << atual->estudante.dataNascimento
                      << ", Digito Identificador: " << atual->estudante.digitoIdentificador << std::endl;
            atual = atual->proximo;
        }
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

    void removerNo(No* no) {
        if (!no) return;

        if (no->anterior) {
            no->anterior->proximo = no->proximo;
        } else {
            inicio = no->proximo;
        }

        if (no->proximo) {
            no->proximo->anterior = no->anterior;
        } else {
            fim = no->anterior;
        }

        delete no;
    }

    void lerArquivoCSV(const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
            return;
        }

        std::string linha;
        std::vector<std::string> dados;

        // Ler o arquivo e armazenar cada linha em um vetor
        while (std::getline(arquivo, linha)) {
            dados.push_back(linha);
        }

        arquivo.close();

        // Processar os dados para criar estudantes
        for (size_t i = 0; i < dados.size(); i += 3) {
            if (i + 2 < dados.size()) {  // Verificar se há pelo menos 3 linhas para formar um registro
                std::string nome = dados[i];
                std::string dataNascimento = dados[i + 1];
                std::string digitoIdentificador = dados[i + 2];
                
                // Adicionar estudante se todos os campos estiverem preenchidos corretamente
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
};




int main() {
    ListaDuplamenteLigada lista;

    // Exibir estudantes (não deve haver nenhum neste ponto)
    std::cout << "Estudantes cadastrados:" << std::endl;
    lista.exibirEstudantes();

    // Buscar estudante por ID (não deve haver nenhum neste ponto)
    int idBusca = 2;
    No* estudanteEncontrado = lista.buscarPorId(idBusca);
    if (estudanteEncontrado) {
        std::cout << "Estudante encontrado: ID: " << estudanteEncontrado->estudante.id
                  << ", Nome: " << estudanteEncontrado->estudante.nome << std::endl;
    } else {
        std::cout << "Estudante com ID " << idBusca << " não encontrado." << std::endl;
    }

    // Ler estudantes de um arquivo CSV e adicionar à lista
    lista.lerArquivoCSV("bla.csv");

    // Exibir estudantes após leitura do arquivo CSV
    std::cout << "Estudantes cadastrados após leitura do arquivo CSV:" << std::endl;
    lista.exibirEstudantes();

    return 0;
}
