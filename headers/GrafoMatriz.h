#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "Vertice.h"
#include "Grafo.h"

class GrafoMatriz  : public Grafo {
private:

public:
    GrafoMatriz(int nVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas, int grau);
    ~GrafoMatriz();
    void imprimir();
};

#endif
