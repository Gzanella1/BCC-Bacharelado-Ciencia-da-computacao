#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Classe para representar um grafo usando unordered_map
class Grafo {
private:
    int numVertices;
    unordered_map<int, vector<int>> adj; // Hashmap para lista de adjacência

public:
    // Adiciona um vértice ao grafo
    void adicionarVertice(int vertice) {
        // Não exibe mensagem se o vértice já existir
        if (adj.find(vertice) == adj.end()) {
            adj[vertice] = {}; // Cria um vértice sem conexões
        }
    }

    // Adiciona uma aresta ao grafo
    void adicionarAresta(int origem, int destino) {
        // Adiciona os vértices caso não existam
        adicionarVertice(origem);
        adicionarVertice(destino);

        // Adiciona a conexão (não direcionado)
        adj[origem].push_back(destino);
        adj[destino].push_back(origem);
    }

    // Exibe o grafo
    void exibirGrafo() {
        for (const auto& [vertice, vizinhos] : adj) {
            cout << "Vértice " << vertice << ":";
            if (!vizinhos.empty()) {
                for (int vizinho : vizinhos) {
                    cout << " " << vizinho;
                }
            } else {
                cout << " Nenhum vizinho";
            }
            cout << endl;
        }
    }
};


//estrutura do meu grafo 
    unordered_map<int, vector<int>> adj; // Hashmap para lista de adjacência

int bfs(Grafo& grafo, int vertice) {
    for (grafo g : grafo) {
        printf("BFS: "+g);
    }

}



int main() {
    Grafo grafo;

    // Adicionando vértices sem conexões
    grafo.adicionarVertice(0);
    grafo.adicionarVertice(1);

    // Adicionando arestas
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(2, 3);
    grafo.adicionarAresta(3, 4);

    // Adicionando outro vértice isolado
    grafo.adicionarVertice(5);

    // Exibe o grafo
    grafo.exibirGrafo();

    return 0;
}
