#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "../include/Grafo.h"
#include "../include/GrafoMatriz.h"
#include "../include/GrafoLista.h"
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
    delete[] vertices;
}

int Grafo::n_conexo()
{
    bool *visitado = new bool[nVertices];
    for (int i = 0; i < nVertices; i++)
    {
        visitado[i] = false; // Inicializa todos os vértices como não visitados
    }

    int count = 0;
    for (int v = 0; v < nVertices; v++)
    {
        if (!visitado[v])
        {
            DFS(v, visitado); // Realiza uma DFS a partir do vértice não visitado
            count++;          // Incrementa o contador de componentes conexas
        }
    }

    delete[] visitado; // Libera a memória alocada para o array visitado
    return count;
}

int Grafo::get_grau()
{
    int grauMaximo = 0;
    for (int i = 0; i < nVertices; i++)
    {
        int grauVertice = vertices[i].getGrauVertice();
        if (grauVertice > grauMaximo)
        {
            grauMaximo = grauVertice;
        }
    }
    return grauMaximo;
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

bool Grafo::eh_completo()
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

void Grafo::carrega_grafo(Grafo* grafo, const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }
    int nVertices, direcionado, ponderadoVertices, ponderadoArestas;
    arquivo >> nVertices >> direcionado >> ponderadoVertices >> ponderadoArestas;

    grafo->nVertices = nVertices;
    grafo->direcionado = direcionado;
    grafo->ponderadoVertices = ponderadoVertices;
    grafo->ponderadoArestas = ponderadoArestas;

    if (ponderadoVertices == 1) {
        for (int i = 0; i < nVertices; ++i) {
            int peso;
            arquivo >> peso;
            grafo->vertices[i].setPeso(peso);
        }
    }
    int origem, destino;
    while (arquivo >> origem >> destino) {
        if (ponderadoArestas == 1) {
            int peso;
            arquivo >> peso;
            grafo->adicionarAresta(origem, destino, peso);
        } else {
            grafo->adicionarAresta(origem, destino);
        }
    }

    arquivo.close();
}