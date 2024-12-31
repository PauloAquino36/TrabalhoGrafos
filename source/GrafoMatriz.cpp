#include "../headers/GrafoMatriz.h"
#include <iostream>

using namespace std;

GrafoMatriz::GrafoMatriz(int nVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(nVertices, direcionado, ponderadoVertices, ponderadoArestas) // Chama o construtor da classe pai
{
    vertices = new Vertice[nVertices];
    for (int i = 0; i < nVertices; ++i) {
        vertices[i].setId(i);
    }
}


GrafoMatriz::~GrafoMatriz() {
    delete[] vertices; // Libera a memória alocada para os vértices
}