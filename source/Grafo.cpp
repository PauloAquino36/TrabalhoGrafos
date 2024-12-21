#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cmath>
#include <string>
#include "../headers/Grafo.h"

using namespace std;

Grafo::Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas)
{
    this->nVertices = numVertices;
    this->direcionado = direcionado;
    this->ponderadoVertices = ponderadoVertices;
    this->ponderadoArestas = ponderadoArestas;
}

Grafo::~Grafo()
{
    
}

bool Grafo::eh_direcionado()
{
    return direcionado;
}

bool Grafo::vertice_ponderado()
{
    return ponderadoVertices;
}

bool Grafo::aresta_ponderada()
{
    return ponderadoArestas;
}

Vertice* Grafo::getVertices()
{
    return vertices;
}