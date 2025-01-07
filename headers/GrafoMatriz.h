#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include <iostream>
#include "Grafo.h"

class GrafoMatriz  : public Grafo {
protected:
    int** matrizAdj;  // Matriz de adjacência
    //int nVertices;    // Número de vértices
    //int grau;
    //bool direcionado; // Indica se o grafo é direcionado        // Grau do grafo
    //bool ponderadoVertices;
    //bool ponderadoArestas;

public:
    GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas);
    ~GrafoMatriz();


    // Funções auxiliares
    void adicionarAresta(int origem, int destino, int peso = 1);
    void imprimirMatrizAdj();
    bool ehConexo();
    bool temCicloDFS(int v, bool visitado[], int pai);
    static GrafoMatriz* carrega_grafo(const std::string& nomeArquivo);
    int get_grau();


private:
    void DFS(int v, bool visitado[]);
};

#endif
