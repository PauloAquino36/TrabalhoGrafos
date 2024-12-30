#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "../headers/Grafo.h"

using namespace std;

Grafo::Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas, int grau)
{
    this->nVertices = numVertices;
    this->direcionado = direcionado;
    this->ponderadoVertices = ponderadoVertices;
    this->ponderadoArestas = ponderadoArestas;
    this->grau = grau;
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

int Grafo::get_ordem()
{
    return nVertices;
}

int Grafo::get_grau()
{
    return grau;
}

bool Grafo::eh_bipartido() {
    int ordem = this->get_ordem(); // Número de vértices no grafo
    int cor[ordem]; // Array para armazenar a cor dos vértices (-1: não colorido, 0 ou 1)
    int fila[ordem]; // Fila para BFS
    int inicio = 0, fim = 0; // Índices da fila

    // Inicializa todas as cores como não coloridas (-1)
    for (int i = 0; i < ordem; i++) {
        cor[i] = -1;
    }

    // Verificar todos os componentes do grafo
    for (int start = 0; start < ordem; start++) {
        if (cor[start] == -1) { // Se o vértice não foi visitado
            cor[start] = 0; // Colorir com 0
            fila[fim++] = start; // Adicionar o vértice à fila

            // BFS
            while (inicio < fim) {
                int u = fila[inicio++]; // Remove da fila

                // Iterar sobre as arestas do vértice u
                Vertice* vertices = this->getVertices();
                for (int i = 0; i < vertices[u].getGrau(); i++) {
                    int v = vertices[u].getArestas()[i].getDestino(); // Destino da aresta

                    if (cor[v] == -1) { // Se v não foi colorido
                        cor[v] = 1 - cor[u]; // Colorir com a cor oposta
                        fila[fim++] = v; // Adicionar à fila
                    } else if (cor[v] == cor[u]) {
                        // Dois vértices adjacentes com a mesma cor
                        return false;
                    }
                }
            }
        }
    }

    return true; // O grafo é bipartido
}
