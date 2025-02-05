#include "../include/GrafoLista.h"

#include <iostream>
#include <fstream>

using namespace std;

// #region Contrutor e Destrutor
GrafoLista::GrafoLista(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(numVertices, direcionado, ponderadoVertices, ponderadoArestas)
{
    this->listaAdjVertices = new ListaAdjVertice[numVertices];    // Inicializa a lista de adjacência
}

GrafoLista::~GrafoLista()
{
    delete[] listaAdjVertices; // Libera a memória alocada para os vértices
}

// #region Funcoes auxiliares
void GrafoLista::atualiza_grafo(int numVertices) {
    // Libera a memória antiga
    delete[] this->listaAdjVertices;

    // Atualiza o número de vértices
    this->numVertices = numVertices;

    // Aloca uma nova lista de adjacência com o novo tamanho
    this->listaAdjVertices = new ListaAdjVertice[numVertices];
}

void GrafoLista::adicionar_vertice(int id, int peso) {
    listaAdjVertices->adicionar_vertice(id, peso);
}

void GrafoLista::adicionar_aresta(int origem, int destino, int peso) {
    listaAdjVertices->adicionar_aresta(origem, destino, peso);
}

ListaAdjAresta* GrafoLista::get_vizinhos(int id) {
    cout << "Vizinhos do vertice " << id << ": ";
    NoAresta* atual = listaAdjVertices->getVertice(id)->getArestas()->getCabeca();
    while(atual != nullptr){
        cout << atual->getDestino() << " " ;
        atual = atual->getProximo();
    }
    cout << endl;
    return listaAdjVertices->getVertice(id)->getArestas();
}

int GrafoLista::get_num_vizinhos(int id) {
    return listaAdjVertices->getVertice(id)->getNumVizinhos();
}

void GrafoLista::dfs(int id, bool* visitado) {
    visitado[id] = true;
    NoAresta* atual = listaAdjVertices->getVertice(id)->getArestas()->getCabeca();
    while(atual != nullptr){
        if(!visitado[atual->getDestino()]){
            dfs(atual->getDestino(), visitado);
        }
        atual = atual->getProximo();
    }
}
// #endregion

// #region Funcoes imprime
void GrafoLista::imprimeListaAdj(){
    listaAdjVertices->imprimir();
}

void GrafoLista::imprimeGrafoLista(){
    cout << "__________________________________________________________________" << endl;
    cout << endl << "--- Grafo Lista ---" << endl;
    cout << "__________________________________________________________________" << endl << endl;
    imprime();
}
// #endregion