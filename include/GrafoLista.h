#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "Grafo.h"
#include "ListaAdjVertice.h"
#include "ListaAdjAresta.h"

class GrafoLista : public Grafo {
protected:
    ListaAdjVertice* listaAdjVertices;                                          // Lista encadeada de vertices
public:
    // Construtor e Destrutor
    GrafoLista(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~GrafoLista();

    // Funcoes auxiliares
    int get_num_vizinhos(int id) override;                                      // Retorna o numero de vizinhos de um vertice do grafo
    void dfs(int id, bool* visitado) override;                                  // Realiza a busca em profundidade no grafo
    bool existe_vertice(int id) override;                                       // Verifica se um vertice existe no grafo
    
    // Funcoes de maniplacao de vertices e arestas
    void adicionar_vertice(int id, float peso = 0.0) override;                  // Adiciona um vertice no grafo
    void adicionar_aresta(int origem, int destino, float peso = 1.0) override;  // Adiciona uma aresta no grafo
    void remover_vertice(int id) override;                                      // Remove um vertice do grafo
    void remover_aresta(int origem, int destino) override;                      // Remove uma aresta do grafo
    void remover_primeira_aresta(int id) override;                              // Remove a primeira aresta de um vertice

    int calcula_menor_dist(int origem, int destino);                            // Calcula a menor distancia entre dois vertices

    // Funcoes imprime
    void imprimeGrafoLista();                                                   // Imprime as informacoes do grafo
    void imprimeListaAdj();                                                     // Imprime a lista de adjacencia

    // Algoritmos Gulosos para cobertura de vertices
    int alg_guloso_cobertura_vertice() override;                                        // Algoritmo guloso para cobertura de vertices
    int alg_randomizado_cobertura_vertice() override;                                   // Algoritmo randomizado para cobertura de vertices
    int alg_reativo_cobertura_vertice() override;                                       // Algoritmo reativo para cobertura de vertices
};

#endif // GRAFOLISTA_H