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
    void atualiza_grafo(int numVertices) override;                              // Redimensiona o grafo
    ListaAdjAresta* get_vizinhos(int id) override;                              // Retorna os vertices vizinhos de um vertice
    int get_num_vizinhos(int id) override;                                      // Retorna o numero de vizinhos de um vertice
    void dfs(int id, bool* visitado) override;                                  // Realiza a busca em profundidade
    
    void adicionar_vertice(int id, int peso = 0) override;                      // Adiciona um vertice no grafo
    void adicionar_novo_vertice(int id, int peso = 0);                          // Adiciona um novo vertice no grafo
    void adicionar_aresta(int origem, int destino, int peso = 0) override;      // Adiciona uma aresta no grafo
    void remover_vertice(int id) override;                                    // Remove um vertice do grafo
    void remover_aresta(int origem, int destino) override;                      // Remove uma aresta do grafo

    //void calcula_menor_dist(int origem, int destino);                            // Calcula a menor distancia entre dois vertices

    // Funcoes imprime
    void imprimeGrafoLista();                                                   // Imprime as informacoes do grafo
    void imprimeListaAdj();                                                     // Imprime a lista de adjacência
};

#endif // GRAFOLISTA_H