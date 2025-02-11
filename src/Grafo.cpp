#include "../include/Grafo.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

// #region Contrutor e Destrutor
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
// #endregion

// Retorna a quantidade de componentes conexas do grafo
int Grafo::n_conexo()
{
    bool* visitado = new bool[numVertices];

    for (int i = 1; i <= numVertices; i++) {
        visitado[i] = false;
    }

    int numComponentes = 0;

    for (int i = 1; i <= numVertices; i++) {
        if (!visitado[i] && this->existe_vertice(i)) {
            dfs(i, visitado);
            numComponentes++;
        }
    }

    delete[] visitado;
    return numComponentes;
}

// Retorna o grau do grafo
int Grafo::get_grau()
{
    int grauMax = 0;
    for (int i = 1 ; i <= numVertices; i++) {
        if (get_num_vizinhos(i) > grauMax && existe_vertice(i)) {
            grauMax = get_num_vizinhos(i);
        }
    }
    return grauMax;
}

// Retorna a ordem do grafo (numero de vertices do grafo)
int Grafo::get_ordem()
{
    return numVertices;
}


// Retorna se o grafo eh direcionado
bool Grafo::eh_direcionado()
{
    return direcionado;
}

// Retorna se o grafo possui vertices ponderados (peso nos vertices)
bool Grafo::vertice_ponderado()
{
    return ponderadoVertices;
}

// Retorna se o grafo possui arestas ponderadas (peso nas arestas)
bool Grafo::aresta_ponderada()
{
    return ponderadoArestas;
}

// Retorna se o grafo eh completo
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

// Imprime os atributos do grafo
void Grafo::imprime()
{
    cout << "Excluindo Noh 1..." << endl;
    this->remover_vertice(1);
    cout << "Excluindo primeira aresta do Noh 2..." << endl << endl;
    this->remover_primeira_aresta(2);
    cout << "Grau: " << get_grau() << endl;
    cout << "Ordem: " << numVertices << endl;
    cout << "Direcionado: " << (eh_direcionado() ? "Sim" : "Nao") << endl;
    cout << "Componentes conexas: " << n_conexo() << endl;
    cout << "Vertices ponderados: " << (vertice_ponderado() ? "Sim" : "Nao") << endl;
    cout << "Arestas ponderadas: " << (aresta_ponderada() ? "Sim" : "Nao") << endl;
    cout << "Completo: " << (eh_completo() ? "Sim" : "Nao") << endl;
    this->calcula_maior_menor_dist();
    cout << "__________________________________________________________________" << endl << endl;
}

// Carrega o grafo a partir de um arquivo txt
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

    for(int i = 1; i <= numVertices; i++) {
        if(ponderadoVertices == 1) {
            float peso;
            arquivo >> peso;
            grafo->adicionar_vertice(i, peso);
        } else {
            grafo->adicionar_vertice(i);
        }
        
    }
    
    int origem, destino;
    while (arquivo >> origem >> destino) {
        if (ponderadoArestas == 1) {
            float peso;
            arquivo >> peso;
            grafo->adicionar_aresta(origem, destino, peso);
        } else {
            grafo->adicionar_aresta(origem, destino);
        }
    }
    arquivo.close();
}