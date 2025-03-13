#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include "Grafo.h"
#include <vector>
class GrafoMatriz  : public Grafo {
protected:
    int** matrizAdj;                    // Matriz de adjacencia
    int tamanhoMatriz;                  // Numero MXM vertices

public:
    // Construtor e Destrutor
    GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~GrafoMatriz();

    // Funcoes auxiliares
    int grauVertice(int vertice);                                                   // Retorna um vertice especifico do grafo
    int get_num_vizinhos(int id) override;                                          // Retorna o numero de vizinhos de um vertice
    void dfs(int id, bool* visitado) override;                                      // Realiza a busca em profundidade no grafo  
    bool existe_vertice(int id) override;                                           // Verifica se um vertice existe no grafo

    // Funcoes de manipulacao de vertices e arestas
    void adicionar_vertice(int id, float peso = 0.0) override;                      // Adiciona um vertice no grafo
    void adicionar_aresta(int origem, int destino, float peso = 1.0) override;      // Adiciona uma aresta no grafo
    void remover_vertice(int id) override;                                          // Remove um vertice do grafo
    void remover_aresta(int origem, int destino) override;                          // Remove uma aresta do grafo
    void remover_primeira_aresta(int id) override;                                  // Remove a primeira aresta de um vertice

    int calcula_menor_dist(int origem, int destino)override;                        // Calcula a menor distancia entre dois vertices
    
    // Funcoes imprime
    void imprimirMatrizAdj();                                                       // Imprime a matriz de adjacencia
    void imprimeGrafoMatriz();                                                      // Imprime os atributos do grafo

    // Algoritmos Gulosos para cobertura de vertices
    void alg_guloso_cobertura_vertice() override;                                        // Algoritmo guloso para cobertura de vertices
    void alg_randomizado_cobertura_vertice() override;                                   // Algoritmo randomizado para cobertura de vertices
    void alg_reativo_cobertura_vertice() override;                                       // Algoritmo reativo para cobertura de vertices
};

#endif // GRAFOMATRIZ_H