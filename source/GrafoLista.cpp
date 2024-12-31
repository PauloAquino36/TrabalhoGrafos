#include "../headers/GrafoLista.h"
#include <iostream>

using namespace std;

GrafoLista::GrafoLista(int nVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(nVertices, direcionado, ponderadoVertices, ponderadoArestas)
{

    // Inicializa os vértices com base nos atributos herdados
    vertices = new Vertice[nVertices]();

    for (int i = 0; i < nVertices; ++i)
    {
        // cout << "Inicializando vértice: " << i << endl;
        vertices[i].setId(i); // Configura o ID de cada vértice
    }
}

GrafoLista::~GrafoLista()
{
    delete[] vertices; // Libera a memória alocada para os vértices
}
