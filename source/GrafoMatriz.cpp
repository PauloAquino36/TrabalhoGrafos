#include <iostream>
#include "./headers/Grafo.h"



class GrafoMatriz : public Grafo {
private:
    int **matrizAdj;
    int numVertices;
    bool direcionado;

public:
    GrafoMatriz(int nVertices, bool direcionado);
    ~GrafoMatriz();

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

    // Funções auxiliares para manipulação da matriz
    void adicionar_aresta(int verticeInicial, int verticeFim, int peso);
    void remover_aresta(int verticeInicial, int verticeFim);
    void imprimir();
};
