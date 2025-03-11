#include "../include/GrafoLista.h"

#include <iostream>
#include <fstream>

using namespace std;

// #region Contrutor e Destrutor
GrafoLista::GrafoLista(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(numVertices, direcionado, ponderadoVertices, ponderadoArestas)
{
    // Inicializa a lista de adjacencia
    this->listaAdjVertices = new ListaAdjVertice(this);                 
}

GrafoLista::~GrafoLista()
{
    // Libera a memoria alocada para os vertices
    delete this->listaAdjVertices;
}
// #endregion

// #region Funcoes auxiliares
bool GrafoLista::existe_vertice(int id) {
    return this->listaAdjVertices->getVertice(id) != nullptr;
}

// Adiciona um vertice ao grafo
void GrafoLista::adicionar_vertice(int id, float peso) {
    // Verifica se o vertice ja existe
    if(existe_vertice(id)){
        cout << "Erro: Vertice " << id << " ja existe!" << endl;                                      /* { DEBUG } */
        return;
    }

    // Adiciona o vertice
    this->listaAdjVertices->adicionar_vertice(id, peso);
}

// Adiciona uma aresta ao grafo
void GrafoLista::adicionar_aresta(int origem, int destino, float peso) {
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

// Remove uma aresta do grafo
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

// Remove a primeira aresta de um vertice
void GrafoLista::remover_primeira_aresta(int id) {
    // Verifica se o vertice existe
    if(listaAdjVertices->getVertice(id) == nullptr){
        cout << "Erro: Vertice " << id << " nao existe!" << endl;                                     /* { DEBUG } */
        return;
    }

    // Remove a primeira aresta
    this->listaAdjVertices->remover_primeira_aresta(id);
}

// Remove um vertice do grafo
void GrafoLista::remover_vertice(int id){
    // Verifica se o vertice existe
    if(!existe_vertice(id)){
        cout << "Erro: Vertice " << id << " nao existe!" << endl;                                     /* { DEBUG } */
        return;
    }

    // Remove o vertice
    this->listaAdjVertices->remover_vertice(id);
}

// Calcula a menor distancia entre dois vertices
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

// Retorna a quantidade de vizinhos de um vertice
int GrafoLista::get_num_vizinhos(int id) {
    return this->listaAdjVertices->getVertice(id)->getNumVizinhos();
}

// Funcao de busca em largura
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
// Imprime a lista de adjacencia
void GrafoLista::imprimeListaAdj(){
    // Imprime a lista de adjacencia
    listaAdjVertices->imprimir();                                    
}

// Imprime  os atributos do grafo
void GrafoLista::imprimeGrafoLista(){
    cout << "__________________________________________________________________" << endl;
    cout << endl << "--- Grafo Lista ---" << endl;
    cout << "__________________________________________________________________" << endl << endl;
    // Imprime as informacoes do grafo
    imprime();                                                      
}
// #endregion


void GrafoLista::alg_guloso_cobertura_vertice() {
    bool* arestasCobertas = new bool[numArestasGrafo + 1];      // Armazenar as arestas cobertas
    for (int i = 1; i <= numArestasGrafo; i++) {
        arestasCobertas[i] = false;
    }

    int* impacto = new int[numVertices + 1];                    // Armazenar o impacto de cada vértice
    for (int i = 1; i <= numVertices; i++) {
        impacto[i] = 0;
    }

    int* qtdArestasCobertasVertice = new int[numVertices + 1];   // Armazenar a quantidade de arestas cobertas por cada vertice
    for (int i = 1; i <= numVertices; i++) {
        qtdArestasCobertasVertice[i] = 0;
    }

    int* conjuntoSolucao = new int[numVertices + 1];            // Armazenar os vértices que fazem parte da solução
    int tamanhoSolucao = 0;                                     // Tamanho atual do conjunto de solução

    while (true) {
        // Calcular impacto de cada vértice
        int maxImpacto = -1;
        int verticeMaxImpacto = -1;
        for (int i = 1; i <= numVertices; i++) {
            if (!existe_vertice(i)) continue;
            impacto[i] = 0;
            NoAresta* atual = listaAdjVertices->getVertice(i)->getArestas()->getCabeca();
            while (atual != nullptr) {
                if (! arestasCobertas[atual->getIdAresta()]) {
                    impacto[i]++;
                }
                //cout << "Vertice (" << i << ") Impacto: " << impacto[i] << endl;              /* { DEBUG } */
                atual = atual->getProximo();
            }
            // Armazena o vértice com maior impacto
            if (impacto[i] > maxImpacto) {
                maxImpacto = impacto[i];
                verticeMaxImpacto = i;
            }
        }

    
        if (maxImpacto == 0) break;  // Todas as arestas estão cobertas

        // Adicionar o vértice com maior impacto ao conjunto de solução
        cout << "Vertice de maior impacto: " << verticeMaxImpacto << " / " << maxImpacto << endl;                    /* { DEBUG } */
        conjuntoSolucao[tamanhoSolucao++] = verticeMaxImpacto;

        // Marcar as arestas conectadas ao vértice de maior impacto como cobertas
        NoAresta* atual = listaAdjVertices->getVertice(verticeMaxImpacto)->getArestas()->getCabeca();
        while (atual != nullptr) {
            if(!(arestasCobertas[atual->getIdAresta()])){
                arestasCobertas[atual->getIdAresta()] = true;
                qtdArestasCobertasVertice[atual->getOrigem()]++;
                cout << "Aresta (" << atual->getIdAresta() << ") coberta por vertice (" << atual->getOrigem() << ")" << endl;  /* { DEBUG } */
                if(!direcionado){
                    NoAresta* atualContraria = listaAdjVertices->getVertice(atual->getDestino())->getArestas()->getCabeca();
                    while(atualContraria != nullptr){
                        if(atualContraria->getDestino() == verticeMaxImpacto && !arestasCobertas[atualContraria->getIdAresta()]){
                            if(!arestasCobertas[atualContraria->getIdAresta()]){
                                arestasCobertas[atualContraria->getIdAresta()] = true;
                                qtdArestasCobertasVertice[atualContraria->getDestino()]++;
                                cout << "Aresta (" << atualContraria->getIdAresta() << ") coberta por vertice (" << atualContraria->getDestino() << ")" << endl;  /* { DEBUG } */
                            }
                            break;
                        }
                        atualContraria = atualContraria->getProximo();
                    }
                }
            }
            atual = atual->getProximo();
        }
    }

    // Imprimir o conjunto de cobertura (solução)
    cout << "Conjunto de cobertura (solucao): ";
    int totalArestasCobertas = 0;
    for (int i = 0; i < tamanhoSolucao; i++) {
        cout << conjuntoSolucao[i] << "(" << qtdArestasCobertasVertice[conjuntoSolucao[i]] << ") " << "  ";
        totalArestasCobertas += qtdArestasCobertasVertice[conjuntoSolucao[i]];
    }
    cout << endl;

    // Imprimir a quantidade de vértices selecionados
    cout << "Quantidade de vertices selecionados: " << tamanhoSolucao << endl;
    cout << "Total de arestas cobertas: " << totalArestasCobertas << endl;
    cout << "Total arestas do grafo: " << numArestasGrafo << endl;

    delete[] arestasCobertas;
    delete[] impacto;
    delete[] conjuntoSolucao;
}