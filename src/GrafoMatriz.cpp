#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include "../include/GrafoMatriz.h"

using namespace std;

// #region Contrutor e Destrutor
GrafoMatriz::GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(numVertices, direcionado, ponderadoVertices, ponderadoArestas)
{
    matrizAdj = new int *[nVertices];
    for (int i = 0; i < nVertices; i++)
    {
        matrizAdj[i] = new int[nVertices];
        for (int j = 0; j < nVertices; j++)
        {
            matrizAdj[i][j] = 0; // Inicializa com 0 (sem aresta)
        }
    }
}

GrafoMatriz::~GrafoMatriz()
{
    for (int i = 0; i < nVertices; i++)
    {
        delete[] matrizAdj[i];
    }
    delete[] matrizAdj;
}
// #endregion

// #region Funcoes principais
bool GrafoMatriz::eh_bipartido()
{
    int *subconjunto = new int[nVertices];
    for (int i = 0; i < nVertices; i++)
    {
        subconjunto[i] = -1; // Inicializa todos os vértices como não atribuídos a um conjunto
    }

    bool resultado = verificarParticaoBipartida(0, subconjunto);

    delete[] subconjunto;
    return resultado;
}

bool GrafoMatriz::eh_arvore() {
    // Verifica se o grafo é conexo
    if (!ehConexo()) {
        return false;
    }

    // Verifica se o grafo possui ciclos
    bool* visitado = new bool[nVertices];
    for (int i = 0; i < nVertices; i++) {
        visitado[i] = false;
    }

    bool temCiclo = temCicloDFS(0, visitado, -1);

    delete[] visitado;

    // Um grafo é uma árvore se for conexo e não tiver ciclos
    return !temCiclo;
}

bool GrafoMatriz::possui_articulacao() {
    bool* visitado = new bool[nVertices];
    int* discovery = new int[nVertices];
    int* low = new int[nVertices];
    int* parent = new int[nVertices];
    bool articulacaoEncontrada = false;

    for (int i = 0; i < nVertices; i++) {
        visitado[i] = false;
        parent[i] = -1;
    }

    for (int i = 0; i < nVertices; i++) {
        if (!visitado[i]) {
            DFSArticulacao(i, visitado, discovery, low, parent, articulacaoEncontrada);
        }
    }

    delete[] visitado;
    delete[] discovery;
    delete[] low;
    delete[] parent;

    return articulacaoEncontrada;
}

bool GrafoMatriz::possui_ponte()
{
    bool *visitado = new bool[nVertices];
    int *discovery = new int[nVertices];
    int *low = new int[nVertices];
    int *parent = new int[nVertices];
    bool ponteEncontrada = false;

    for (int i = 0; i < nVertices; i++)
    {
        visitado[i] = false;
        parent[i] = -1;
    }

    for (int i = 0; i < nVertices; i++)
    {
        if (!visitado[i])
        {
            DFSPonte(i, visitado, discovery, low, parent, ponteEncontrada);
        }
    }

    delete[] visitado;
    delete[] discovery;
    delete[] low;
    delete[] parent;

    return ponteEncontrada;
}
// #endregion

// #region Funcoes auxiliares
Vertice &GrafoMatriz::getVertice(int i)
{
    return vertices[i];
}

void GrafoMatriz::adicionarAresta(int origem, int destino, int peso)
{
    if (origem < 0 || origem >= nVertices || destino < 0 || destino >= nVertices)
    {
        cout << "Origem: " << origem << " / Destino: " << destino << " / Num Vertices:" << nVertices << endl;
        cout << "Erro: indices de origem ou destino invalidos.\n";
        return;
    }

    matrizAdj[origem][destino] = peso;
    vertices[origem].adicionarAresta(destino, peso);

    if (!direcionado)
    {
        matrizAdj[destino][origem] = peso;
        vertices[destino].adicionarAresta(origem, peso);
    }
}

bool GrafoMatriz::verificarParticaoBipartida(int v, int subconjunto[])
{
    if (v == nVertices)
    {
        // Verifica se a partição atual é válida
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                if (matrizAdj[i][j] != 0 && subconjunto[i] == subconjunto[j])
                {
                    return false; // Encontrou uma aresta entre vértices do mesmo conjunto
                }
            }
        }
        return true; // Partição válida
    }

    // Tenta atribuir o vértice v ao conjunto 0
    subconjunto[v] = 0;
    if (verificarParticaoBipartida(v + 1, subconjunto))
    {
        return true;
    }

    // Tenta atribuir o vértice v ao conjunto 1
    subconjunto[v] = 1;
    if (verificarParticaoBipartida(v + 1, subconjunto))
    {
        return true;
    }

    // Nenhuma partição válida encontrada
    subconjunto[v] = -1;
    return false;
}

bool GrafoMatriz::ehConexo()
{
    bool *visitado = new bool[nVertices]{false};
    DFS(0, visitado);

    for (int i = 0; i < nVertices; i++)
    {
        if (!visitado[i])
        {
            delete[] visitado;
            return false;
        }
    }

    delete[] visitado;
    return true;
}

void GrafoMatriz::DFS(int v, bool visitado[])
{
    visitado[v] = true;
    for (int i = 0; i < nVertices; i++)
    {
        if (matrizAdj[v][i] != 0 && !visitado[i])
        {
            DFS(i, visitado);
        }
    }
}

bool GrafoMatriz::temCicloDFS(int v, bool visitado[], int pai)
{
    visitado[v] = true;
    for (int i = 0; i < nVertices; i++)
    {
        if (matrizAdj[v][i] != 0)
        {
            if (!visitado[i])
            {
                if (temCicloDFS(i, visitado, v))
                {
                    return true;
                }
            }
            else if (i != pai)
            {
                return true;
            }
        }
    }
    return false;
}
// #endregion

// #region Funcoes de imprimir
void GrafoMatriz::imprimirMatrizAdj()
{
    for (int i = 0; i < nVertices; i++)
    {
        for (int j = 0; j < nVertices; j++)
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

// Verifica funçao ponte
void GrafoMatriz::DFSPonte(int v, bool visitado[], int discovery[], int low[], int parent[], bool &ponteEncontrada)
{
    static int tempo = 0;
    visitado[v] = true;
    discovery[v] = low[v] = ++tempo;

    for (int i = 0; i < nVertices; i++)
    {
        if (matrizAdj[v][i] != 0)
        {
            int u = i;
            if (!visitado[u])
            {
                parent[u] = v;
                DFSPonte(u, visitado, discovery, low, parent, ponteEncontrada);

                low[v] = min(low[v], low[u]);

                if (low[u] > discovery[v])
                {
                    ponteEncontrada = true;
                }
            }
            else if (u != parent[v])
            {
                low[v] = min(low[v], discovery[u]);
            }
        }
    }
}

//verifica funçao articulaçao
void GrafoMatriz::DFSArticulacao(int v, bool visitado[], int discovery[], int low[], int parent[], bool& articulacaoEncontrada) {
    static int tempo = 0;
    int filhos = 0;
    visitado[v] = true;
    discovery[v] = low[v] = ++tempo;

    for (int i = 0; i < nVertices; i++) {
        if (matrizAdj[v][i] != 0) {
            int u = i;
            if (!visitado[u]) {
                filhos++;
                parent[u] = v;
                DFSArticulacao(u, visitado, discovery, low, parent, articulacaoEncontrada);

                low[v] = min(low[v], low[u]);

                if (parent[v] == -1 && filhos > 1) {
                    articulacaoEncontrada = true;
                }

                if (parent[v] != -1 && low[u] >= discovery[v]) {
                    articulacaoEncontrada = true;
                }
            } else if (u != parent[v]) {
                low[v] = min(low[v], discovery[u]);
            }
        }
    }
}