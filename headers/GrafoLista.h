#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "Vertice.h"

class GrafoLista {
private:
    Vertice* vertices; // Lista de vértices
    int numVertices;   // Número de vértices
    bool direcionado;  // Indica se o grafo é direcionado

public:
    GrafoLista(int nVertices, bool direcionado);
    ~GrafoLista();

    void adicionarAresta(int origem, int destino, int peso = 0);
    void removerAresta(int origem, int destino);
    void imprimir() const;

    bool existeAresta(int origem, int destino) const;
    int obterPeso(int origem, int destino) const;

    int getNumVertices() const;
    bool ehDirecionado() const;
};

#endif
