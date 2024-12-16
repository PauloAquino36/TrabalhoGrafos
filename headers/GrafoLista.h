#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "Grafo.h"
#include "Aresta.h"

class GrafoLista : public Grafo {
private:
    int numVertices;                               // Número de vértices no grafo
    bool direcionado;                              // Flag para indicar se o grafo é direcionado ou não
    Aresta*** listaAdj;                            // Lista de adjacência como matriz de ponteiros para arestas

public:
    GrafoLista(int nVertices, bool direcionado);
    ~GrafoLista();

    // Funções auxiliares
    void adicionarAresta(int origem, int destino, int peso = 1);
    void removerAresta(int origem, int destino);
    void imprimir() const;

    // Funções extras
    bool existeAresta(int origem, int destino) const; // Verifica se uma aresta existe
    int obterPeso(int origem, int destino) const;     // Retorna o peso de uma aresta
};

#endif
