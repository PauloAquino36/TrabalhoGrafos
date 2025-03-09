#include "../include/GrafoMatriz.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> // Biblioteca necessaria para setw()


using namespace std;

// #region Contrutor e Destrutor
GrafoMatriz::GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(numVertices, direcionado, ponderadoVertices, ponderadoArestas)
{
    tamanhoMatriz = 10;

    if (numVertices <= 0)
    {
        numVertices = 1;
    }

    while (tamanhoMatriz < numVertices)
    {
        tamanhoMatriz *= 2;
    }

    matrizAdj = new int *[tamanhoMatriz];
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        matrizAdj[i] = new int[tamanhoMatriz];
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            matrizAdj[i][j] = 0; // Inicializa com 0 (sem aresta)
        }
    }
}

GrafoMatriz::~GrafoMatriz()
{
    if (matrizAdj != nullptr)
    { // Verifica se ha memoria alocada
        for (int i = 0; i < numVertices; i++)
        {
            delete[] matrizAdj[i];
        }
        delete[] matrizAdj;
        matrizAdj = nullptr; // Evita ponteiro danificado
    }
}
// #endregion

// #region Funcoes auxiliares
// Adiciona um vértice ao grafo
void GrafoMatriz::adicionar_vertice(int id, float peso)
{
    int novoNumVertices = numVertices + 1;
    numVertices = novoNumVertices;

    if (novoNumVertices >= tamanhoMatriz)
    {
        cout << "Aumentando matriz de adjacencia...\n";
        int antigoTamanhoMatriz = tamanhoMatriz;
        tamanhoMatriz = max(tamanhoMatriz * 2, novoNumVertices); // Expansao mais segura
        int **novaMatriz = new int *[tamanhoMatriz];

        for (int i = 0; i < tamanhoMatriz; i++)
        {
            novaMatriz[i] = new int[tamanhoMatriz](); // Inicializa com 0
        }

        // Copia os valores da matriz antiga para a nova matriz
        for (int i = 0; i < antigoTamanhoMatriz; i++)
        {
            for (int j = 0; j < antigoTamanhoMatriz; j++)
            {
                novaMatriz[i][j] = matrizAdj[i][j];
            }
        }

        // Libera a matriz antiga corretamente
        for (int i = 0; i < antigoTamanhoMatriz; i++) // Correcao aqui
        {
            delete[] matrizAdj[i];
        }
        delete[] matrizAdj;

        matrizAdj = novaMatriz;
    }
}

// Remove um vertice do grafo
void GrafoMatriz::remover_vertice(int id)
{
    if (id < 0 || id >= numVertices)
    {
        cout << "Erro: indice de vertice invalido.\n";
        return;
    }
    // Atualiza o contador de arestas
    for (int i = 0; i < numVertices; i++)
    {
        if (matrizAdj[id][i] != 0)
        {
            decrementa_num_arestas_grafos();
            if (!direcionado)
            {
                decrementa_num_arestas_grafos();
            }
        }
        if (matrizAdj[i][id] != 0 && i != id)
        {
            decrementa_num_arestas_grafos();
        }
    }
    int novoNumVertices = numVertices - 1;
    int **novaMatriz = new int *[tamanhoMatriz];

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        novaMatriz[i] = new int[tamanhoMatriz]();
    }

    // Copia os valores da matriz antiga para a nova, excluindo o vertice removido
    for (int i = 0, ni = 0; i < tamanhoMatriz; i++)
    {
        if (i == id)
            continue;

        for (int j = 0, nj = 0; j < tamanhoMatriz; j++)
        {
            if (j == id)
                continue;

            novaMatriz[ni][nj] = matrizAdj[i][j];
            nj++;
        }
        ni++;
    }

    // Libera a matriz antiga
    for (int i = 0; i < numVertices; i++)
    {
        delete[] matrizAdj[i];
    }
    delete[] matrizAdj;

    matrizAdj = novaMatriz;
    numVertices = novoNumVertices;
}

void GrafoMatriz::remover_aresta(int origem, int destino)
{
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices)
    {
        cout << "Erro: indices de origem ou destino invalidos.\n";
        return;
    }

    matrizAdj[origem][destino] = 0;
    decrementa_num_arestas_grafos();
    if (!direcionado)
    {
        matrizAdj[destino][origem] = 0;
        decrementa_num_arestas_grafos();
    }
}

// Remove a primeira aresta de um vertice
void GrafoMatriz::remover_primeira_aresta(int id)
{
    if (id < 0 || id > numVertices)
    {
        cout << "Erro: indice de vertice invalido." << endl;
        return;
    }

    for (int i = 0; i <= numVertices; i++)
    {
        if (matrizAdj[id][i] != 0)
        {
            matrizAdj[id][i] = 0;
            decrementa_num_arestas_grafos();
            if (!direcionado)
            {
                matrizAdj[i][id] = 0;
                decrementa_num_arestas_grafos();
            }
            return;
        }
    }
}

void GrafoMatriz::adicionar_aresta(int origem, int destino, float peso)
{
    if (origem < 0 || origem > numVertices || destino < 0 || destino > numVertices)
    {
        cout << "Erro: indices de origem ou destino invalidos.\n";
        return;
    }

    if (ponderadoArestas)
    {
        matrizAdj[origem][destino] = peso;
        incrementa_num_arestas_grafos();
        if (!direcionado)
        {
            matrizAdj[destino][origem] = peso;
            incrementa_num_arestas_grafos();
        }
    }
    else
    {
        matrizAdj[origem][destino] = 1;
        incrementa_num_arestas_grafos();
        if (!direcionado)
        {
            matrizAdj[destino][origem] = 1;
            incrementa_num_arestas_grafos();
        }
    }
}

// Calcula menor distancia entre dois vertices
int GrafoMatriz::calcula_menor_dist(int origem, int destino)
{
    const int INF = 1000000; // Valor grande para representar infinito
    int *dist = new int[numVertices + 1];
    int *prev = new int[numVertices + 1];
    bool *visitado = new bool[numVertices + 1];

    for (int i = 1; i <= numVertices; i++)
    {
        dist[i] = INF;
        prev[i] = -1;
        visitado[i] = false;
    }

    dist[origem] = 0;

    // Loop principal do algoritmo de Dijkstra
    for (int i = 1; i <= numVertices; i++)
    {
        int u = -1;

        // Encontra o vertice nao visitado com a menor distancia
        for (int j = 1; j <= numVertices; j++)
        {
            if (!visitado[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }

        // Se a menor distancia e infinita, todos os vertices restantes sao inacessiveis
        if (dist[u] == INF)
        {
            break;
        }

        visitado[u] = true;

        // Atualiza as distancias dos vizinhos do vertice atual
        for (int v = 1; v <= numVertices; v++)
        {
            if (matrizAdj[u][v] != 0 && dist[u] + matrizAdj[u][v] < dist[v])
            {
                dist[v] = dist[u] + matrizAdj[u][v];
                prev[v] = u;
            }
        }
    }

    int menorDist = dist[destino];

    delete[] dist;
    delete[] prev;
    delete[] visitado;

    return menorDist;
}

// Retorna a quantidade de vizinhos de um vertice
int GrafoMatriz::get_num_vizinhos(int id)
{
    if (id < 0 || id > numVertices)
    {
        return 0; // Retorna 0 se o ID do vertice for invalido
    }

    int contador = 0;
    for (int i = 0; i <= numVertices; i++)
    {
        if (matrizAdj[id][i] != 0)
        { // Se houver uma aresta entre os vertices
            contador++;
        }
    }
    return contador;
}

// Funcao de busca em largura
void GrafoMatriz::dfs(int id, bool *visitado)
{
    if (id < 0 || id > numVertices || visitado[id])
    {
        return; // Verifica se o vertice eh valido ou ja foi visitado
    }

    visitado[id] = true; // Marca o vertice como visitado

    for (int i = 0; i <= numVertices; i++)
    {
        if (matrizAdj[id][i] != 0 && !visitado[i])
        { // Se houver uma aresta e o vertice nao foi visitado
            dfs(i, visitado);
        }
    }
}

// Verifica se o vertice existe no grafo
bool GrafoMatriz::existe_vertice(int id)
{
    return (id >= 0 && id <= numVertices);
}
// #endregion

// #region Funcoes de imprimir
// Imprime a matriz de adjacencia
void GrafoMatriz::imprimirMatrizAdj()
{
    cout << "__________________________________________________________________" << endl;
    cout << endl << "--- Matriz de Adjacencia ---" << endl << endl;

    // Imprime o cabecalho dos indices dos vertices
    cout << "  V";
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        cout << std::setw(3) << i << " ";
    }
    cout << endl;

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        // Imprime o indice do vertice na lateral esquerda
        cout << std::setw(3) << i;

        for (int j = 0; j < tamanhoMatriz; j++)
        {
            std::cout << std::setw(3) << matrizAdj[i][j] << " ";
        }
        std::cout << std::endl;
    }
    cout << "__________________________________________________________________" << endl;
}

// Imprime os atributos do grafo
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