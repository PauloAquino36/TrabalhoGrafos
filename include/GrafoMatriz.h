#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include "Grafo.h"

class GrafoMatriz  : public Grafo {
protected:
    int** matrizAdj;  // Matriz de adjacencia
    int tamanhoMatriz;  // Numero MXM vertices

public:
    // Construtor e Destrutor
    GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~GrafoMatriz();

    // Funcoes auxiliares
    void atualiza_grafo(int numVertices) override;                              // Redimensiona o grafo
    int grauVertice(int vertice);                                               // Retorna um vertice especifico do grafo
    int get_num_vizinhos(int id) override;                                      // Retorna o numero de vizinhos de um vertice
    void dfs(int id, bool* visitado) override;   
    bool existe_vertice(int id) override;                                       // Verifica se um vertice existe no grafo

    void adicionar_vertice(int id, int peso = 0) override;                      // Adiciona um vertice no grafo
    void adicionar_aresta(int origem, int destino, int peso = 1) override;      // Adiciona uma aresta no grafo
    void remover_vertice(int id) override;                                      // Remove um vertice do grafo
    void remover_aresta(int origem, int destino) override;                      // Remove uma aresta do grafo

    int calcula_menor_dist(int origem, int destino)override;                            // Calcula a menor distancia entre dois vertices
    int calcula_maior_menor_dist()override;                                            // Calcula a maior menor distancia entre dois vertices
    
    // Funcoes de imprimir
    void imprimirMatrizAdj();                                                   // Imprime a matriz de adjacencia
    void imprimeGrafoMatriz();                                                  // Imprime os atributos do grafo
};

#endif // GRAFOMATRIZ_H