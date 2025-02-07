#include "../include/GrafoLista.h"

#include <iostream>
#include <fstream>

using namespace std;

// #region Contrutor e Destrutor
GrafoLista::GrafoLista(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(numVertices, direcionado, ponderadoVertices, ponderadoArestas)
{
    this->listaAdjVertices = new ListaAdjVertice[numVertices];          // Inicializa a lista de adjacência
}

GrafoLista::~GrafoLista()
{
    delete[] listaAdjVertices;          // Libera a memória alocada para os vértices
}

// #region Funcoes auxiliares
void GrafoLista::atualiza_grafo(int numVertices) {
    delete[] this->listaAdjVertices;                                    // Libera a memória antiga
    this->numVertices = numVertices;                                    // Atualiza o número de vértices
    this->listaAdjVertices = new ListaAdjVertice[numVertices];          // Aloca uma nova lista de adjacência com o novo tamanho
}

void GrafoLista::adicionar_vertice(int id, int peso) {
    // Verifica se o vertice ja existe
    if(listaAdjVertices->getVertice(id) != nullptr){
        cout << "Vertice " << id << " ja existe!" << endl;
        return;
    }

    // Adiciona o vertice
    listaAdjVertices->adicionar_vertice(id, peso);
}

void GrafoLista::adicionar_novo_vertice(int id, int peso) {
    // Verifica se o vertice ja existe
    if(listaAdjVertices->getVertice(id) != nullptr){
        cout << "Vertice " << id << " ja existe!" << endl;
        return;
    }

    // Adiciona o vertice
    listaAdjVertices->adicionar_vertice(id, peso);
    numVertices++;
}

void GrafoLista::adicionar_aresta(int origem, int destino, int peso) {
    // Verifica se o vertice de origem existe
    if(listaAdjVertices->getVertice(origem) == nullptr){
        cout << "Vertice " << origem << " nao existe!" << endl;
        return;
    }
    // Verifica se o vertice de destino existe
    if(listaAdjVertices->getVertice(destino) == nullptr){
        cout << "Vertice " << destino << " nao existe!" << endl;
        return;
    }
    // Verifica se a aresta eh um self-loop
    if(origem == destino){
        cout << "Nao e possivel adicionar aresta: Origem e destino iguais! " << endl;
        return;
    }

    // Adiciona a aresta
    listaAdjVertices->adicionar_aresta(origem, destino, peso);
    if(!direcionado){
        listaAdjVertices->adicionar_aresta(destino, origem, peso);
    }
}

void GrafoLista::remover_aresta(int origem, int destino) {
    // Verifica se o vertice de origem existe
    if(listaAdjVertices->getVertice(origem) == nullptr){
        cout << "Vertice " << origem << " nao existe!" << endl;
        return;
    }
    // Verifica se o vertice de destino existe
    if(listaAdjVertices->getVertice(destino) == nullptr){
        cout << "Vertice " << destino << " nao existe!" << endl;
        return;
    }

    // Remove a aresta
    listaAdjVertices->remover_aresta(origem, destino);
    if(!direcionado){
        listaAdjVertices->remover_aresta(destino, origem);
    }
}

ListaAdjAresta* GrafoLista::get_vizinhos(int id) {
    // Debug
    cout << "Vizinhos do vertice " << id << ": ";
    NoAresta* atual = listaAdjVertices->getVertice(id)->getArestas()->getCabeca();
    while(atual != nullptr){
        cout << atual->getDestino() << " " ;
        atual = atual->getProximo();
    }
    cout << endl;
    // Fim debug
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
    listaAdjVertices->imprimir();                                    // Imprime a lista de adjacência
}

void GrafoLista::imprimeGrafoLista(){
    cout << "__________________________________________________________________" << endl;
    cout << endl << "--- Grafo Lista ---" << endl;
    cout << "__________________________________________________________________" << endl << endl;
    imprime();                                                      // Imprime as informações do grafo
}
// #endregion