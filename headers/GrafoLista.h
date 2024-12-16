#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "Grafo.h"
#include "Aresta.h"

class GrafoLista : public Grafo {
private:
    int numVertices;                               // Número de vértices no grafo
    bool direcionado;                              // Flag para indicar se o grafo é direcionado ou não

public:
    GrafoLista(int nVertices, bool direcionado);
    ~GrafoLista() = default;

    // Funções auxiliares
    void adicionar_aresta(int origem, int destino, int peso = 1);
    void remover_aresta(int origem, int destino);
    void imprimir() const;
};

#endif
