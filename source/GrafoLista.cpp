#include "../headers/GrafoLista.h"
#include <iostream>

using namespace std;

GrafoLista::GrafoLista(int nVertices, bool direcionado)
    : numVertices(nVertices), direcionado(direcionado)
{
    cout << "0" << endl;
    vertices = new Vertice[numVertices];
    for (int i = 0; i < numVertices; ++i)
    {
        cout << "Inicializando vertice: " << i << endl;
        vertices[i] = Vertice(i);
    }
    cout << "1" << endl;
}

GrafoLista::~GrafoLista()
{
    delete[] vertices; // Libera a memória alocada para os vértices
}

void GrafoLista::adicionarAresta(int origem, int destino, int peso)
{
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices)
    {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return;
    }

    vertices[origem].adicionarAresta(destino, peso);

    if (!direcionado)
    {
        vertices[destino].adicionarAresta(origem, peso);
    }
}

void GrafoLista::removerAresta(int origem, int destino)
{
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices)
    {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return;
    }

    vertices[origem].removerAresta(destino);

    if (!direcionado)
    {
        vertices[destino].removerAresta(origem);
    }
}

void GrafoLista::imprimir() const
{
    for (int i = 0; i < numVertices; ++i)
    {
        cout << "Vertice " << i << ": ";
        vertices[i].imprimirArestas();
    }
}

bool GrafoLista::existeAresta(int origem, int destino) const
{
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices)
    {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return false;
    }

    return vertices[origem].existeAresta(destino);
}

int GrafoLista::obterPeso(int origem, int destino) const
{
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices)
    {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return 0;
    }

    for (int i = 0; i < numVertices; ++i)
    {
        if (vertices[origem].existeAresta(destino))
        {
            return vertices[origem].getPeso();
        }
    }
    return 0;
}

int GrafoLista::getNumVertices() const
{
    return numVertices;
}

bool GrafoLista::ehDirecionado() const
{
    return direcionado;
}
