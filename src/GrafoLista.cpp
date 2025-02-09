#include "../include/GrafoLista.h"

#include <iostream>
#include <fstream>

using namespace std;

// #region Contrutor e Destrutor
GrafoLista::GrafoLista(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(numVertices, direcionado, ponderadoVertices, ponderadoArestas)
{
    // Inicializa a lista de adjacência
    this->listaAdjVertices = new ListaAdjVertice();                 
}

GrafoLista::~GrafoLista()
{
    // Libera a memória alocada para os vértices
    delete this->listaAdjVertices;
}

// #region Funcoes auxiliares

bool GrafoLista::existe_vertice(int id) {
    return this->listaAdjVertices->getVertice(id) != nullptr;
}

void GrafoLista::adicionar_vertice(int id, int peso) {
    // Verifica se o vertice ja existe
    if(existe_vertice(id)){
        cout << "Erro: Vertice " << id << " ja existe!" << endl;                                      /* { DEBUG } */
        return;
    }

    // Adiciona o vertice
    this->listaAdjVertices->adicionar_vertice(id, peso);
    this->numVertices++;
}

void GrafoLista::adicionar_aresta(int origem, int destino, int peso) {
    // Verifica se o vertice de origem existe
    if(!existe_vertice(origem)){
        cout << "Erro: Vertice " << origem << " nao existe!" << endl;                                 /* { DEBUG } */
        return;
    }
    // Verifica se o vertice de destino existe
    if(!existe_vertice(destino)){
        cout << "Erro: Vertice " << destino << " nao existe!" << endl;                                /* { DEBUG } */
        return;
    }
    // Verifica se a aresta eh um self-loop
    if(origem == destino){
        cout << "Erro: Nao eh possivel adicionar aresta. Origem e destino iguais! " << endl;           /* { DEBUG } */
        return;
    }

    // Adiciona a aresta
    this->listaAdjVertices->adicionar_aresta(origem, destino, peso);
    if(!direcionado){
        this->listaAdjVertices->adicionar_aresta(destino, origem, peso);
    }
}

void GrafoLista::remover_aresta(int origem, int destino) {
    // Verifica se o vertice de origem existe
    if(listaAdjVertices->getVertice(origem) == nullptr){
        cout << "Erro: Vertice " << origem << " nao existe!" << endl;                                 /* { DEBUG } */
        return;
    }
    // Verifica se o vertice de destino existe
    if(listaAdjVertices->getVertice(destino) == nullptr){
        cout << "Erro: Vertice " << destino << " nao existe!" << endl;                                /* { DEBUG } */
        return;
    }

    // Remove a aresta
    this->listaAdjVertices->remover_aresta(origem, destino);
    if(!direcionado){
        this->listaAdjVertices->remover_aresta(destino, origem);
    }
}

void GrafoLista::remover_vertice(int id){
    // Verifica se o vertice existe
    if(!existe_vertice(id)){
        cout << "Erro: Vertice " << id << " nao existe!" << endl;                                     /* { DEBUG } */
        return;
    }

    // Remove o vertice
    this->listaAdjVertices->remover_vertice(id);
    this->numVertices--;
}

int GrafoLista::get_num_vizinhos(int id) {
    return this->listaAdjVertices->getVertice(id)->getNumVizinhos();
}

void GrafoLista::dfs(int id, bool* visitado) {
    if(listaAdjVertices->getVertice(id) == nullptr){
        return;
    }
    visitado[id] = true;
    NoAresta* atual = this->listaAdjVertices->getVertice(id)->getArestas()->getCabeca();
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
    // Imprime a lista de adjacência
    listaAdjVertices->imprimir();                                    
}

void GrafoLista::imprimeGrafoLista(){
    cout << "__________________________________________________________________" << endl;
    cout << endl << "--- Grafo Lista ---" << endl;
    cout << "__________________________________________________________________" << endl << endl;
    // Imprime as informações do grafo
    imprime();                                                      
}
// #endregion