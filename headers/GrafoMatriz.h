#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "Grafo.h"
#include "Aresta.h"

class GrafoMatriz : public Grafo {
private:
    Aresta ***matrizAdj; // Matriz de ponteiros para objetos Aresta
    int numVertices;     // Número de vértices no grafo
    bool direcionado;    // Flag para indicar se o grafo é direcionado ou não

public:
    GrafoMatriz(int nVertices, bool direcionado);
    ~GrafoMatriz();

    void adicionarAresta(int vertice1, int vertice2, int peso);
    void removerAresta(int vertice1, int vertice2);
    void imprimir() const;

    // Métodos para acessar propriedades específicas
    int obterPeso(int vertice1, int vertice2) const;
    bool existeAresta(int vertice1, int vertice2) const;
};

#endif
