#include "../include/Grafo.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

Grafo::Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas)
{
    this->numVertices = numVertices;
    this->direcionado = direcionado;
    this->ponderadoVertices = ponderadoVertices;
    this->ponderadoArestas = ponderadoArestas;
}

Grafo::~Grafo()
{
}

int Grafo::n_conexo()
{
    bool* visitado = new bool[numVertices];
    for (int i = 1; i <= numVertices; i++) {
        visitado[i] = false;
    }

    int numComponentes = 0;

    for (int i = 1; i <= numVertices; i++) {
        if (!visitado[i]) {
            dfs(i, visitado);
            numComponentes++;
        }
    }

    delete[] visitado;
    return numComponentes;
}

int Grafo::get_grau()
{
    int grauMax = 0;
    for (int i = 1 ; i <= numVertices; i++) {
        if (get_num_vizinhos(i) > grauMax) {
            grauMax = get_num_vizinhos(i);
        }
    }
    return grauMax;
}

int Grafo::get_ordem()
{
    return numVertices;
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
    for (int i = 1; i <= numVertices; i++) {
        int numVizinhos = get_num_vizinhos(i);
        if (numVizinhos != numVertices - 1) {
            return false;
        }
    }
    return true;
}

void Grafo::imprime()
{
    cout << "Grau: " << get_grau() << endl;
    cout << "Ordem: " << numVertices << endl;
    cout << "Direcionado: " << (eh_direcionado() ? "Sim" : "Nao") << endl;
    cout << "Componentes conexas: " << n_conexo() << endl;
    cout << "Vertices ponderados: " << (vertice_ponderado() ? "Sim" : "Nao") << endl;
    cout << "Arestas ponderadas: " << (aresta_ponderada() ? "Sim" : "Nao") << endl;
    cout << "Completo: " << (eh_completo() ? "Sim" : "Nao") << endl;
    cout << "__________________________________________________________________" << endl << endl;
}

void Grafo::carrega_grafo(Grafo* grafo, const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }
    int numVertices, direcionado, ponderadoVertices, ponderadoArestas;
    arquivo >> numVertices >> direcionado >> ponderadoVertices >> ponderadoArestas;

    grafo->direcionado = direcionado;
    grafo->ponderadoVertices = ponderadoVertices;
    grafo->ponderadoArestas = ponderadoArestas;

    grafo->atualiza_grafo(numVertices);

    for(int i = 1; i <= numVertices; i++) {
        if(ponderadoVertices == 1) {
            int peso;
            arquivo >> peso;
            grafo->adicionar_vertice(i, peso);
        } else {
            grafo->adicionar_vertice(i);
        }
        
    }
    
    int origem, destino;
    while (arquivo >> origem >> destino) {
        if (ponderadoArestas == 1) {
            int peso;
            arquivo >> peso;
            grafo->adicionar_aresta(origem, destino, peso);
        } else {
            grafo->adicionar_aresta(origem, destino);
        }
    }
    arquivo.close();
}