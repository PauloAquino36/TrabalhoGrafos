#include "../include/GrafoLista.h"

#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief Construtor da classe GrafoLista.
 * @param numVertices Numero de vertices do grafo.
 * @param direcionado Indica se o grafo eh direcionado.
 * @param ponderadoVertices Indica se o grafo possui peso nos vertices.
 * @param ponderadoArestas Indica se o grafo possui peso nas arestas.
 */
GrafoLista::GrafoLista(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(numVertices, direcionado, ponderadoVertices, ponderadoArestas)
{
    // Inicializa a lista de adjacencia
    this->listaAdjVertices = new ListaAdjVertice();                 
}

/**
 * @brief Destrutor da classe GrafoLista.
 */
GrafoLista::~GrafoLista()
{
    // Libera a memoria alocada para os vertices
    delete this->listaAdjVertices;
}

/**
 * @brief Verifica se um vertice existe no grafo.
 * @param id Identificador do vertice.
 * @return True se o vertice existe, false caso contrario.
 */
bool GrafoLista::existe_vertice(int id) {
    return this->listaAdjVertices->getVertice(id) != nullptr;
}

/**
 * @brief Adiciona um vertice ao grafo.
 * @param id Identificador do vertice.
 * @param peso Peso do vertice (opcional).
 */
void GrafoLista::adicionar_vertice(int id, float peso) {
    // Verifica se o vertice ja existe
    if(existe_vertice(id)){
        cout << "Erro: Vertice " << id << " ja existe!" << endl;
        return;
    }

    // Adiciona o vertice
    this->listaAdjVertices->adicionar_vertice(id, peso);
    this->numVertices++;
}

/**
 * @brief Adiciona uma aresta ao grafo.
 * @param origem Identificador do vertice de origem.
 * @param destino Identificador do vertice de destino.
 * @param peso Peso da aresta (opcional).
 */
void GrafoLista::adicionar_aresta(int origem, int destino, float peso) {
    // Verifica se o vertice de origem existe
    if(!existe_vertice(origem)){
        cout << "Erro: Vertice " << origem << " nao existe!" << endl;
        return;
    }
    // Verifica se o vertice de destino existe
    if(!existe_vertice(destino)){
        cout << "Erro: Vertice " << destino << " nao existe!" << endl;
        return;
    }
    // Verifica se a aresta eh um self-loop
    if(origem == destino){
        cout << "Erro: Nao eh possivel adicionar aresta. Origem e destino iguais!" << endl;
        return;
    }

    // Adiciona a aresta
    this->listaAdjVertices->adicionar_aresta(origem, destino, peso);
    if(!direcionado){
        this->listaAdjVertices->adicionar_aresta(destino, origem, peso);
    }
}

/**
 * @brief Remove uma aresta do grafo.
 * @param origem Identificador do vertice de origem.
 * @param destino Identificador do vertice de destino.
 */
void GrafoLista::remover_aresta(int origem, int destino) {
    // Verifica se o vertice de origem existe
    if(listaAdjVertices->getVertice(origem) == nullptr){
        cout << "Erro: Vertice " << origem << " nao existe!" << endl;
        return;
    }
    // Verifica se o vertice de destino existe
    if(listaAdjVertices->getVertice(destino) == nullptr){
        cout << "Erro: Vertice " << destino << " nao existe!" << endl;
        return;
    }

    // Remove a aresta
    this->listaAdjVertices->remover_aresta(origem, destino);
    if(!direcionado){
        this->listaAdjVertices->remover_aresta(destino, origem);
    }
}

/**
 * @brief Remove a primeira aresta de um vertice.
 * @param id Identificador do vertice.
 */
void GrafoLista::remover_primeira_aresta(int id) {
    // Verifica se o vertice existe
    if(listaAdjVertices->getVertice(id) == nullptr){
        cout << "Erro: Vertice " << id << " nao existe!" << endl;
        return;
    }

    // Remove a primeira aresta
    this->listaAdjVertices->remover_primeira_aresta(id);
}

/**
 * @brief Remove um vertice do grafo.
 * @param id Identificador do vertice.
 */
void GrafoLista::remover_vertice(int id){
    // Verifica se o vertice existe
    if(!existe_vertice(id)){
        cout << "Erro: Vertice " << id << " nao existe!" << endl;
        return;
    }

    // Remove o vertice
    this->listaAdjVertices->remover_vertice(id);
    this->numVertices--;
}

/**
 * @brief Calcula a menor distancia entre dois vertices.
 * @param origem Identificador do vertice de origem.
 * @param destino Identificador do vertice de destino.
 * @return Menor distancia entre os vertices.
 */
int GrafoLista::calcula_menor_dist(int origem, int destino) {
    const int INF = 1000000;
    int dist[numVertices + 1];
    bool visitado[numVertices + 1];

    for (int i = 1; i <= numVertices; i++) {
        dist[i] = INF;
        visitado[i] = false;
    }

    dist[origem] = 0;

    for (int i = 1; i <= numVertices; i++) {
        int u = -1;
        for (int j = 1; j <= numVertices; j++) {
            if (!visitado[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) {
            break;
        }

        visitado[u] = true;
        NoAresta* atual = listaAdjVertices->getVertice(u)->getArestas()->getCabeca();
        while (atual != nullptr) {
            int v = atual->getDestino();
            float peso = atual->getPeso();
            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
            }
            atual = atual->getProximo();
        }
    }

    return (dist[destino] == INF) ? -1 : dist[destino];
}

/**
 * @brief Calcula a maior entre as menores distancias de um grafo.
 * @return Maior entre as menores distancias.
 */
int GrafoLista::calcula_maior_menor_dist() {
    int maiorMenorDist = 0;
    int verticeOrigem = -1, verticeDestino = -1;

    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            if (i != j) {
                int menorDist = calcula_menor_dist(i, j);
                if (menorDist != -1 && menorDist > maiorMenorDist) {
                    maiorMenorDist = menorDist;
                    verticeOrigem = i;
                    verticeDestino = j;
                }
            }
        }
    }

    if (verticeOrigem != -1 && verticeDestino != -1) {
        cout << "Maior menor distancia: (" << verticeOrigem << "-" << verticeDestino << ") = " << maiorMenorDist << endl;
    } else {
        cout << "Nao ha caminhos validos no grafo." << endl;
    }

    return maiorMenorDist;
}

/**
 * @brief Retorna a quantidade de vizinhos de um vertice.
 * @param id Identificador do vertice.
 * @return Numero de vizinhos do vertice.
 */
int GrafoLista::get_num_vizinhos(int id) {
    return this->listaAdjVertices->getVertice(id)->getNumVizinhos();
}

/**
 * @brief Realiza a busca em profundidade no grafo.
 * @param id Identificador do vertice inicial.
 * @param visitado Vetor de vertices visitados.
 */
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

/**
 * @brief Imprime a lista de adjacencia.
 */
void GrafoLista::imprimeListaAdj(){
    // Imprime a lista de adjacencia
    listaAdjVertices->imprimir();                                    
}

/**
 * @brief Imprime os atributos do grafo.
 */
void GrafoLista::imprimeGrafoLista(){
    cout << "__________________________________________________________________" << endl;
    cout << endl << "--- Grafo Lista ---" << endl;
    cout << "__________________________________________________________________" << endl << endl;
    // Imprime as informacoes do grafo
    imprime();                                                      
}