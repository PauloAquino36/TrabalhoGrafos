#include "../include/GrafoLista.h"

#include <iostream>
#include <fstream>
#include <cstdlib>  // Para a função rand()

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
    bool verticeEscolhido[numVertices + 1] = {false};
    bool arestaCoberta[numArestasGrafo] = {false};  // Marcar arestas cobertas
    int graus[numVertices + 1] = {0};
    int somaVizinhos[numVertices + 1] = {0};  // Soma dos graus dos vizinhos
    int arestasCobertas = 0;

    // Inicializa graus e soma dos vizinhos
    for (int i = 1; i <= numVertices; i++) {
        NoAresta* arestaAtual = listaAdjVertices->getVertice(i)->getArestas()->getCabeca();
        while (arestaAtual != nullptr) {
            graus[i]++;
            somaVizinhos[i] += graus[arestaAtual->getDestino()];
            arestaAtual = arestaAtual->getProximo();
        }
    }

    // Algoritmo guloso otimizado
    while (arestasCobertas < numArestasGrafo) {
        int melhorVertice = -1;
        int melhorSoma = -1;
        int melhorGrau = -1;

        // Escolhe o melhor vértice sem usar bibliotecas externas
        for (int i = 1; i <= numVertices; i++) {
            if (!verticeEscolhido[i]) {
                int somaAtual = somaVizinhos[i];
                int grauAtual = graus[i];

                // Critério de desempate
                if (somaAtual > melhorSoma || 
                   (somaAtual == melhorSoma && grauAtual > melhorGrau) ||
                   (somaAtual == melhorSoma && grauAtual == melhorGrau && i < melhorVertice)) {
                    melhorSoma = somaAtual;
                    melhorGrau = grauAtual;
                    melhorVertice = i;
                }
            }
        }

        if (melhorVertice == -1) break;

        verticeEscolhido[melhorVertice] = true;

        // Atualiza graus e arestas cobertas
        NoAresta* arestaAtual = listaAdjVertices->getVertice(melhorVertice)->getArestas()->getCabeca();
        while (arestaAtual != nullptr) {
            int destino = arestaAtual->getDestino();
            int idAresta = arestaAtual->getIdAresta();

            if (!arestaCoberta[idAresta]) {
                arestaCoberta[idAresta] = true;
                arestasCobertas++;

                if (!direcionado) {
                    // Marcar a aresta reversa como coberta
                    NoAresta* reversa = listaAdjVertices->getVertice(destino)->getArestas()->getCabeca();
                    while (reversa != nullptr) {
                        if (reversa->getDestino() == melhorVertice) {
                            arestaCoberta[reversa->getIdAresta()] = true;
                            arestasCobertas++;
                            break;
                        }
                        reversa = reversa->getProximo();
                    }
                }

                graus[destino]--;
                somaVizinhos[destino] -= graus[melhorVertice];  // Atualiza soma dos vizinhos
            }

            arestaAtual = arestaAtual->getProximo();
        }
    }

    // Imprime o conjunto solução
    cout << "Cobertura de Vertices: ";
    int qtdVerticesSolucao = 0;
    for (int i = 1; i <= numVertices; i++) {
        if (verticeEscolhido[i]) {
            qtdVerticesSolucao++;
            cout << i << " ";
        }
    }
    cout << endl << "Quantidade de Vertices na solucao: " << qtdVerticesSolucao << endl;
}

// Adicionar função randomizada
void GrafoLista::alg_randomizado_cobertura_vertice() {
    bool verticeEscolhido[numVertices + 1] = {false};
    bool arestaCoberta[numArestasGrafo] = {false};  // Marcar arestas cobertas
    int graus[numVertices + 1] = {0};
    int somaVizinhos[numVertices + 1] = {0};  // Soma dos graus dos vizinhos
    int arestasCobertas = 0;

    // Inicializa graus e soma dos vizinhos
    for (int i = 1; i <= numVertices; i++) {
        NoAresta* arestaAtual = listaAdjVertices->getVertice(i)->getArestas()->getCabeca();
        while (arestaAtual != nullptr) {
            graus[i]++;
            somaVizinhos[i] += graus[arestaAtual->getDestino()];
            arestaAtual = arestaAtual->getProximo();
        }
    }

    // Algoritmo guloso randomizado
    while (arestasCobertas < numArestasGrafo) {
        int candidatos[numVertices + 1];  // Array para armazenar vértices candidatos
        int numCandidatos = 0;
        int melhorSoma = -1;

        // Coleta os vértices com o maior valor de soma dos vizinhos
        for (int i = 1; i <= numVertices; i++) {
            if (!verticeEscolhido[i]) {
                int somaAtual = somaVizinhos[i];

                // Atualiza os candidatos
                if (somaAtual > melhorSoma) {
                    melhorSoma = somaAtual;
                    numCandidatos = 0;  // Limpa a lista de candidatos
                    candidatos[numCandidatos++] = i;
                }
                else if (somaAtual == melhorSoma) {
                    candidatos[numCandidatos++] = i;
                }
            }
        }

        // Se não há mais candidatos, termina o algoritmo
        if (numCandidatos == 0) break;

        // Escolhe aleatoriamente um vértice entre os candidatos
        int escolhido = candidatos[rand() % numCandidatos];

        verticeEscolhido[escolhido] = true;

        // Atualiza graus e arestas cobertas
        NoAresta* arestaAtual = listaAdjVertices->getVertice(escolhido)->getArestas()->getCabeca();
        while (arestaAtual != nullptr) {
            int destino = arestaAtual->getDestino();
            int idAresta = arestaAtual->getIdAresta();

            if (!arestaCoberta[idAresta]) {
                arestaCoberta[idAresta] = true;
                arestasCobertas++;

                if (!direcionado) {
                    // Marcar a aresta reversa como coberta
                    NoAresta* reversa = listaAdjVertices->getVertice(destino)->getArestas()->getCabeca();
                    while (reversa != nullptr) {
                        if (reversa->getDestino() == escolhido) {
                            arestaCoberta[reversa->getIdAresta()] = true;
                            arestasCobertas++;
                            break;
                        }
                        reversa = reversa->getProximo();
                    }
                }

                graus[destino]--;
                somaVizinhos[destino] -= graus[escolhido];  // Atualiza soma dos vizinhos
            }

            arestaAtual = arestaAtual->getProximo();
        }
    }

    // Imprime o conjunto solução
    cout << "Cobertura de Vertices Randomizada: ";
    int qtdVerticesSolucao = 0;
    for (int i = 1; i <= numVertices; i++) {
        if (verticeEscolhido[i]) {
            qtdVerticesSolucao++;
            cout << i << " ";
        }
    }
    cout << endl << "Quantidade de Vertices na solucao randomizada: " << qtdVerticesSolucao << endl;
}