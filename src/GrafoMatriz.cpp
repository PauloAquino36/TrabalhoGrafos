#include "../include/GrafoMatriz.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> // Biblioteca necessária para setw()


using namespace std;

// Contrutor e Destrutor
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
    { // Verifica se há memória alocada
        for (int i = 0; i < numVertices; i++)
        {
            delete[] matrizAdj[i];
        }
        delete[] matrizAdj;
        matrizAdj = nullptr; // Evita ponteiro danificado
    }
}

// Funcoes auxiliares

void GrafoMatriz::atualiza_grafo(int numVertices)
{
    // Verifica se a matrizAdj já foi alocada antes de liberar a memória
    if (matrizAdj != nullptr)
    {
        for (int i = 0; i < this->tamanhoMatriz; i++)
        {
            delete[] matrizAdj[i]; // Libera cada linha da matriz
        }
        delete[] matrizAdj;  // Libera o array de ponteiros
        matrizAdj = nullptr; // Evita ponteiro danificado
    }

    // Aloca uma nova matriz de adjacência com o novo tamanho
    matrizAdj = new int *[tamanhoMatriz];
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        matrizAdj[i] = new int[tamanhoMatriz](); // Inicializa automaticamente com 0
    }
}

// Adiciona um vértice ao grafo
void GrafoMatriz::adicionar_vertice(int id, int peso)
{
    int novoNumVertices = numVertices + 1;
    numVertices = novoNumVertices;

    if (novoNumVertices > tamanhoMatriz)
    {
        cout << "Aumentando matriz de adjacência...\n";
        int antigoTamanhoMatriz = tamanhoMatriz;
        tamanhoMatriz = max(tamanhoMatriz * 2, novoNumVertices); // Expansão mais segura
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
        for (int i = 0; i < antigoTamanhoMatriz; i++) // Correção aqui
        {
            delete[] matrizAdj[i];
        }
        delete[] matrizAdj;

        matrizAdj = novaMatriz;
    }
}


// Remove um vértice do grafo
void GrafoMatriz::remover_vertice(int id)
{
    if (id < 0 || id >= numVertices)
    {
        cout << "Erro: índice de vértice inválido.\n";
        return;
    }

    int novoNumVertices = numVertices - 1;
    int **novaMatriz = new int *[tamanhoMatriz];

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        novaMatriz[i] = new int[tamanhoMatriz]();
    }

    // Copia os valores da matriz antiga para a nova, excluindo o vértice removido
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
    if (!direcionado)
    {
        matrizAdj[destino][origem] = 0;
    }
}
// Adiciona uma aresta ao grafo
void GrafoMatriz::adicionar_aresta(int origem, int destino, int peso)
{
    // cout << "Num Vertices:" << numVertices << endl;
    // cout << "Origem: " << origem << " / Destino: " << destino << " / Num Vertices:" << numVertices << endl;

    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices)
    {
        cout << "Erro: indices de origem ou destino invalidos.\n";
        return;
    }

    // cout << "conluido: " <<  "Origem: " << origem << " / Destino: " << destino << endl;

    if (ponderadoArestas)
    {
        matrizAdj[origem][destino] = peso;
        if (!direcionado)
        {
            matrizAdj[destino][origem] = peso;
        }
    }
    else
    {
        matrizAdj[origem][destino] = 1;
        if (!direcionado)
        {
            matrizAdj[destino][origem] = 1;
        }
    }
}
// Calcula menor distancia entre dois vertices
int GrafoMatriz::calcula_menor_dist(int origem, int destino)
{
    const int INF = 1000000; // Valor grande para representar infinito
    int *dist = new int[numVertices];
    int *prev = new int[numVertices];
    bool *visitado = new bool[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        dist[i] = INF;
        prev[i] = -1;
        visitado[i] = false;
    }

    dist[origem] = 0;

    // Loop principal do algoritmo de Dijkstra
    for (int i = 0; i < numVertices; i++)
    {
        int u = -1;

        // Encontra o vértice não visitado com a menor distância
        for (int j = 0; j < numVertices; j++)
        {
            if (!visitado[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }

        // Se a menor distância é infinita, todos os vértices restantes são inacessíveis
        if (dist[u] == INF)
        {
            break;
        }

        visitado[u] = true;

        // Atualiza as distâncias dos vizinhos do vértice atual
        for (int v = 0; v < numVertices; v++)
        {
            if (matrizAdj[u][v] != 0 && dist[u] + matrizAdj[u][v] < dist[v])
            {
                dist[v] = dist[u] + matrizAdj[u][v];
                prev[v] = u;
            }
        }
    }

    int menorDist = dist[destino];
    // Verifica se há um caminho até o destino
    if (menorDist == INF)
    {
        // Não há caminho entre origem e destino
    }
    else
    {
        // Caminho encontrado
        int* caminho = new int[numVertices];
        int count = 0;
        for (int at = destino; at != -1; at = prev[at])
        {
            caminho[count++] = at;
        }

        // Imprime o caminho na ordem correta
        for (int i = count - 1; i >= 0; i--) {
            // std::cout << caminho[i] + 1;
            if (i > 0) {
                // std::cout << " -> ";
            }
        }
        // std::cout << std::endl;

        delete[] caminho;
    }

    delete[] dist;
    delete[] prev;
    delete[] visitado;

    return menorDist;
}

int GrafoMatriz::calcula_maior_menor_dist() {
    int maiorMenorDist = 0;
    int verticeOrigem = -1;
    int verticeDestino = -1;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i != j) {
                int menorDist = calcula_menor_dist(i, j);
                if (menorDist != 1000000 && menorDist > maiorMenorDist) {
                    maiorMenorDist = menorDist;
                    verticeOrigem = i;
                    verticeDestino = j;
                }
            }
        }
    }

    if (verticeOrigem != -1 && verticeDestino != -1) {
        std::cout << "Maior menor distância (" << verticeOrigem + 1 << "-" << verticeDestino + 1 << ") = " << maiorMenorDist << std::endl;
    } else {
        std::cout << "Não há caminhos válidos no grafo." << std::endl;
    }

    return maiorMenorDist;
}

int GrafoMatriz::get_num_vizinhos(int id)
{
    if (id < 0 || id >= numVertices)
    {
        return 0; // Retorna 0 se o ID do vértice for inválido
    }

    int contador = 0;
    for (int i = 0; i < numVertices; i++)
    {
        if (matrizAdj[id][i] != 0)
        { // Se houver uma aresta entre os vértices
            contador++;
        }
    }
    return contador;
}
void GrafoMatriz::dfs(int id, bool *visitado)
{
    if (id < 0 || id >= numVertices || visitado[id])
    {
        return; // Verifica se o vértice é válido ou já foi visitado
    }

    visitado[id] = true; // Marca o vértice como visitado

    for (int i = 0; i < numVertices; i++)
    {
        if (matrizAdj[id][i] != 0 && !visitado[i])
        { // Se houver uma aresta e o vértice não foi visitado
            dfs(i, visitado);
        }
    }
}

// Funcoes de imprimir
void GrafoMatriz::imprimirMatrizAdj()
{
    cout << "__________________________________________________________________" << endl;
    cout << endl << "--- Matriz de Adjacencia ---" << endl << endl;

    // Imprime o cabeçalho dos índices dos vértices
    cout << "  V";
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        cout << std::setw(3) << i << " ";
    }
    cout << endl;

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        // Imprime o índice do vértice na lateral esquerda
        cout << std::setw(3) << i;

        for (int j = 0; j < tamanhoMatriz; j++)
        {
            std::cout << std::setw(3) << matrizAdj[i][j] << " ";
        }
        std::cout << std::endl;
    }
    cout << "__________________________________________________________________" << endl;
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
