#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "Vertice.h"

class GrafoMatriz {
private:
    Vertice* vertices; // Array de vértices
    int numVertices;   // Número de vértices
    bool direcionado;  // Indica se o grafo é direcionado

public:
    GrafoMatriz(int nVertices, bool direcionado);
    ~GrafoMatriz();

    void adicionarAresta(int origem, int destino, int peso = 0);
    void removerAresta(int origem, int destino);
    void imprimir();

    int obterPeso(int origem, int destino);
    bool existeAresta(int origem, int destino);

    int getNumVertices();
    bool ehDirecionado();
};

#endif
