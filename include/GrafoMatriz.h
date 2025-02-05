#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include "Grafo.h"

class GrafoMatriz  : public Grafo {
protected:
    int** matrizAdj;  // Matriz de adjacência

public:
    // Contrutor e Destrutor
    GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~GrafoMatriz();

    // Funções auxiliares
    void atualiza_grafo(int numVertices) override; 
    int grauVertice(int vertice);                                //Retorna um vertice especifico do grafo
    void adicionar_aresta(int origem, int destino, int peso = 1) override;        //Adiciona uma aresta no grafo
    int get_num_vizinhos(int id) override;                                       //Retorna o numero de vizinhos de um vertice
    void dfs(int id, bool* visitado) override;                                   //Realiza a busca em profundidade
    // Funcoes de imprimir
    void imprimirMatrizAdj();                                           //Imprime a matriz de adjacência
    void imprimeGrafoMatriz();                                          //Imprime os atributos do grafo
};

#endif // GRAFOMATRIZ_H