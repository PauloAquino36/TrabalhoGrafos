#include <iostream>
#include <fstream>
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
    vertices = new Vertice[nVertices];
}

Grafo::~Grafo()
{
    
}

int Grafo::get_ordem()
{
    return nVertices;
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

bool Grafo::eh_bipartido()
{
    return false;
}

int Grafo::n_conexo()
{
    return 0;
}

int Grafo::get_grau()
{
    return 0;
}

bool Grafo::eh_completo()
{
    return false;
}

bool Grafo::eh_arvore()
{
    return false;
}

bool Grafo::possui_ponte()
{
    return false;
}

bool Grafo::possui_articulacao()
{
    return false;
}

void Grafo::imprime()
{
    cout << "Grau: " << get_grau() << endl;
    cout << "Ordem: " << nVertices << endl;
    cout << "Direcionado: " << (eh_direcionado() ? "Sim" : "Nao") << endl;
    cout << "Componentes conexas: " << n_conexo() << endl;
    cout << "Vertices ponderados: " << (vertice_ponderado() ? "Sim" : "Nao") << endl;
    cout << "Arestas ponderadas: " << (aresta_ponderada() ? "Sim" : "Nao") << endl;
    cout << "Completo: " << (eh_completo() ? "Sim" : "Nao") << endl;
    cout << "Bipartido: " << (eh_bipartido() ? "Sim" : "Nao") << endl;
    cout << "Arvore: " << (eh_arvore() ? "Sim" : "Nao") << endl;
    cout << "Aresta Ponte: " << (possui_ponte() ? "Sim" : "Nao") << endl;
    cout << "Vertice de Articulacao: " << (possui_articulacao() ? "Sim" : "Nao") << endl;
    cout << "__________________________________________________________________" << endl << endl;
}