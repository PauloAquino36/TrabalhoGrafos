#include <iostream>
#include <fstream>
#include <vector>
#include <list>
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

bool Grafo::eh_bipartido() {
    int *color = new int[nVertices];
    for (int i = 0; i < nVertices; i++) {
        color[i] = -1; // Inicializa todos os elementos com -1
    }

    int *fila = new int[nVertices];
    int inicioFila = 0, fimFila = 0;

    for (int i = 0; i < nVertices; i++) {
        if (color[i] == -1) { // Vértice ainda não visitado
            fila[fimFila++] = i;
            color[i] = 0; // Começa colorindo com 0

            while (inicioFila < fimFila) {
                int v = fila[inicioFila++];
                //cout << "Visitando vertice: " << v << endl;
                
                // Iterar sobre todos os vizinhos de v
                Aresta* aresta = vertices[v].getArestas();
                while (aresta != nullptr) {
                    int j = aresta->getDestino();
                    //cout << "  Vertice vizinho: " << j << endl;
                    if (color[j] == -1) { // Se não foi colorido
                        color[j] = 1 - color[v]; // Colore com a cor oposta
                        fila[fimFila++] = j;
                    } else if (color[j] == color[v]) {
                        //cout << "  Conflito de cores encontrado entre " << v << " e " << j << endl;
                        delete[] color;
                        delete[] fila;
                        return false;
                    }
                    //aresta = aresta->getProx(); achar um jeito de implementar
                }
            }
        }
    }

    delete[] color;
    delete[] fila;
    return true; // Se passou por todos os vértices sem conflitos, é bipartido
}

int Grafo::get_ordem()
{
    return nVertices;
}

int Grafo::get_grau()
{
    return grau;
}