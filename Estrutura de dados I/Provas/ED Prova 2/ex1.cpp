 #include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void ler_e_exibir_arquivo_csv(const std::string& nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << nome_arquivo << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string coluna;
        bool primeira_coluna = true;
        while (std::getline(ss, coluna, ',')) {
            if (!primeira_coluna) {
                std::cout << ", ";
            }
            std::cout << coluna;
            primeira_coluna = false;
        }
        std::cout << std::endl;
    }

    arquivo.close();
}

int main() {
    std::string nome_arquivo = "bla.csv";
    ler_e_exibir_arquivo_csv(nome_arquivo);
    return 0;
}
pessoa