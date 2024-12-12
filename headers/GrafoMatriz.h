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

    // Funções para o grafo
    bool eh_bipartido();
    int n_conexo();
    int get_grau();
    int get_ordem();
    bool eh_direcionado();
    bool vertice_ponderado();
    bool aresta_ponderada();
    bool eh_completo();
    bool eh_arvore();
    bool possui_articulacao();
    bool possui_ponte();

    // Funções auxiliares para manipulação da matriz de adjacência
    void adicionar_aresta(int vertice1, int vertice2, int peso);
    void remover_aresta(int vertice1, int vertice2);
    void imprimir() const;
};

#endif
