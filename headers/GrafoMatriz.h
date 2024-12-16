#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "Grafo.h"

class GrafoMatriz : public Grafo {
private:
    int **matrizAdj;  // Matriz de adjacência para representar o grafo
    int numVertices;  // Número de vértices no grafo
    bool direcionado; // Flag para indicar se o grafo é direcionado ou não

public:
    // Construtor e destruidor
    GrafoMatriz(int nVertices, bool direcionado);
    ~GrafoMatriz();

    // Funções auxiliares para manipulação da matriz de adjacência
    void adicionar_aresta(int vertice1, int vertice2, int peso);
    void remover_aresta(int vertice1, int vertice2);
    void imprimir() const;
};

#endif
