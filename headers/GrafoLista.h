#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "Vertice.h"
#include "Grafo.h"

class GrafoLista : public Grafo {

public:
    GrafoLista(int nVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas, int grau);
    ~GrafoLista();
};

#endif
