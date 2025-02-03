#include "../include/GrafoMatriz.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// #region Contrutor e Destrutor
GrafoMatriz::GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(numVertices, direcionado, ponderadoVertices, ponderadoArestas)
{
    matrizAdj = new int *[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        matrizAdj[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++)
        {
            matrizAdj[i][j] = 0; // Inicializa com 0 (sem aresta)
        }
    }
}

GrafoMatriz::~GrafoMatriz()
{
    for (int i = 0; i < numVertices; i++)
    {
        delete[] matrizAdj[i];
    }
    delete[] matrizAdj;
}
// #endregion

// #region Funcoes auxiliares
// Vertice &GrafoMatriz::getVertice(int i)
// {
//     //return vertices[i];
// }

void GrafoMatriz::adicionar_aresta(int origem, int destino, int peso)
{
    // if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices)
    // {
    //     cout << "Origem: " << origem << " / Destino: " << destino << " / Num Vertices:" << numVertices << endl;
    //     cout << "Erro: indices de origem ou destino invalidos.\n";
    //     return;
    // }

    // matrizAdj[origem][destino] = peso;
    // vertices[origem].adicionarAresta(destino, peso);

    // if (!direcionado)
    // {
    //     matrizAdj[destino][origem] = peso;
    //     vertices[destino].adicionarAresta(origem, peso);
    // }
}

// #endregion

// #region Funcoes de imprimir
void GrafoMatriz::imprimirMatrizAdj()
{
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            std::cout << matrizAdj[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void GrafoMatriz::imprimeGrafoMatriz()
{
    cout << "__________________________________________________________________" << endl;
    cout << endl
         << "--- Grafo Matriz ---" << endl;
    cout << "__________________________________________________________________" << endl
         << endl;
    imprime();
}
// #endregion