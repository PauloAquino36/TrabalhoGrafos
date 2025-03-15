#include "../include/GrafoLista.h"

#include <iostream>
#include <fstream>
#include <cstdlib>  // Para a função rand()
#include <ctime>    // Para a função time()

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
        cout << "Erro: Vertice " << destino <<" nao existe!" << endl;                                /* { DEBUG } */
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
    imprimir_descricao();                                                      
}
// #endregion

// #region Algoritmos gulosos

// Algoritmo guloso para cobertura de vertices
int GrafoLista::alg_guloso_cobertura_vertice() {
    clock_t start = clock();

    // Inicializa estruturas
    bool verticeEscolhido[numVertices + 1] = {false};
    bool arestaCoberta[numArestasGrafo + 1] = {false};
    int graus[numVertices + 1] = {0};
    int somaGraus[numVertices + 1] = {0};
    int heap[numVertices + 1]; 
    int heapPos[numVertices + 1]; 
    int qtdVerticesSolucao = 0;
    int arestasCobertas = 0;
    int heapSize = numVertices;

    // Função para trocar dois valores manualmente
    auto swap = [](int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    };

    // Inicializa graus e heap
    for (int i = 1; i <= numVertices; i++) {
        graus[i] = listaAdjVertices->getVertice(i)->getNumVizinhos();
        heap[i] = i;  
        heapPos[i] = i; 
    }

    // Calcula soma dos graus dos vizinhos
    for (int i = 1; i <= numVertices; i++) {
        NoAresta* arestaAtual = listaAdjVertices->getVertice(i)->getArestas()->getCabeca();
        while (arestaAtual != nullptr) {
            somaGraus[i] += graus[arestaAtual->getDestino()];
            arestaAtual = arestaAtual->getProximo();
        }
    }

    // Função para reorganizar heap (Max Heap)
    auto heapify_down = [&](int idx) {
        while (true) {
            int maior = idx;
            int esq = 2 * idx;
            int dir = 2 * idx + 1;

            if (esq <= heapSize && somaGraus[heap[esq]] > somaGraus[heap[maior]]) maior = esq;
            if (dir <= heapSize && somaGraus[heap[dir]] > somaGraus[heap[maior]]) maior = dir;

            if (maior == idx) break;
            
            swap(heapPos[heap[idx]], heapPos[heap[maior]]);
            swap(heap[idx], heap[maior]);
            idx = maior;
        }
    };

    // Função para remover o melhor vértice do heap
    auto extrai_melhor = [&]() -> int {
        int melhorVertice = heap[1];
        heap[1] = heap[heapSize--];
        heapPos[heap[1]] = 1;
        heapify_down(1);
        return melhorVertice;
    };

    // Constrói heap inicial
    for (int i = heapSize / 2; i > 0; i--) {
        heapify_down(i);
    }

    // Loop principal do algoritmo guloso
    while (arestasCobertas < numArestasGrafo) {
        int melhorVertice = extrai_melhor();
        if (somaGraus[melhorVertice] == 0) break;

        verticeEscolhido[melhorVertice] = true;
        qtdVerticesSolucao++;

        // Marca as arestas cobertas e atualiza somaGraus
        NoAresta* arestaAtual = listaAdjVertices->getVertice(melhorVertice)->getArestas()->getCabeca();
        while (arestaAtual != nullptr) {
            int u = arestaAtual->getDestino();
            int idAresta = arestaAtual->getIdAresta();

            if (!arestaCoberta[idAresta]) {
                arestaCoberta[idAresta] = true;
                arestasCobertas++;

                // Atualiza somaGraus para os vizinhos
                NoAresta* vizinho = listaAdjVertices->getVertice(u)->getArestas()->getCabeca();
                while (vizinho != nullptr) {
                    somaGraus[vizinho->getDestino()] -= graus[u];
                    vizinho = vizinho->getProximo();
                }
            }
            arestaAtual = arestaAtual->getProximo();
        }

        // Reorganiza heap após atualização dos graus
        for (int i = heapSize / 2; i > 0; i--) {
            heapify_down(i);
        }
    }
    // Imprime a solucao do problema de cobertura de vertices
    cout << endl << "*** Algoritmo Guloso Randomizado para Cobertura de Vertices ***" << endl;
    cout << "Quantidade de Vertices na solucao: " << qtdVerticesSolucao << endl;

    /* Comentando a impressão do conjunto solução para evitar que o console trave
    cout << "Conjunto solucao: { ";
    for (int i = 1; i <= numVertices; i++) {
        if (verticeEscolhido[i]) {
            cout << i << " ";
        }
    }
    cout << "}" << endl;
    cout << "Quantidade de Arestas cobertas: " << arestasCobertas << endl;
    cout << "Quantidade de Arestas do grafo: " << numArestasGrafo << endl;
    */

    // Calcula e imprime o tempo de execução
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de execucao de alg_randomizado_cobertura_vertices: " << duration << " segundos" << endl;
    return qtdVerticesSolucao;
}




// Algoritmo guloso randomizado para cobertura de vertices
int GrafoLista::alg_randomizado_cobertura_vertice() {
    // Inicializa o tempo de execução
    clock_t start = clock();

    bool verticeEscolhido[numVertices + 1] = {false};       // Marcar vertices escolhidos
    bool arestaCoberta[numArestasGrafo + 1] = {false};      // Marcar arestas cobertas
    int graus[numVertices + 1] = {0};                       // Armazena o grau de cada vertice
    int somaVizinhos[numVertices + 1] = {0};                // Armazena a soma dos graus dos vizinhos de cada vertice
    int arestasCobertas = 0;                                // Contador de arestas cobertas    
    int qtdVerticesSolucao = 0;                             // Contador de vertices na solucao

    // Inicializa graus e soma dos vizinhos
    for (int i = 1; i <= numVertices; i++) {
        graus[i] = listaAdjVertices->getVertice(i)->getNumVizinhos();
        NoAresta* arestaAtual = listaAdjVertices->getVertice(i)->getArestas()->getCabeca();
        while (arestaAtual != nullptr) {
            somaVizinhos[i] += listaAdjVertices->getVertice(arestaAtual->getDestino())->getNumVizinhos();
            arestaAtual = arestaAtual->getProximo();
        }
    }

    // Algoritmo guloso randomizado
    while (arestasCobertas < numArestasGrafo) {
        int candidatos[numVertices + 1];  // Array para armazenar vértices candidatos
        int numCandidatos = 0;
        int melhorSoma = 0;
        int melhorGrau = 0;

        // Coleta os vértices com o maior valor de soma dos vizinhos
        for (int i = 1; i <= numVertices; i++) {
            if (!verticeEscolhido[i]) {
                int somaAtual = somaVizinhos[i];
                int grauAtual = graus[i];

                // Atualiza os candidatos
                if ( (somaAtual > melhorSoma) || (somaAtual == melhorSoma && grauAtual > melhorGrau) ) {
                    melhorSoma = somaAtual;
                    melhorGrau = grauAtual;
                    numCandidatos = 0;  // Limpa a lista de candidatos
                    candidatos[numCandidatos++] = i;
                }
                else if (somaAtual == melhorSoma && grauAtual == melhorGrau) {
                    candidatos[numCandidatos++] = i;
                }
            }
        }

        // Se não há mais candidatos, termina o algoritmo
        if (numCandidatos == 0) break;

        // Escolhe aleatoriamente um vértice entre os candidatos
        int escolhido = candidatos[rand() % numCandidatos];

        verticeEscolhido[escolhido] = true;
        qtdVerticesSolucao++;

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
                            graus[destino]--;
                            somaVizinhos[destino] -= graus[escolhido];  // Atualiza soma dos vizinhos
                            break;
                        }
                        reversa = reversa->getProximo();
                    }
                }
            }

            arestaAtual = arestaAtual->getProximo();
        }
    }

    // Imprime a solucao do problema de cobertura de vertices
    cout << endl << "*** Algoritmo Guloso Randomizado para Cobertura de Vertices ***" << endl;
    cout << "Quantidade de Vertices na solucao: " << qtdVerticesSolucao << endl;

    /* Comentando a impressão do conjunto solução para evitar que o console trave
    cout << "Conjunto solucao: { ";
    for (int i = 1; i <= numVertices; i++) {
        if (verticeEscolhido[i]) {
            cout << i << " ";
        }
    }
    cout << "}" << endl;
    cout << "Quantidade de Arestas cobertas: " << arestasCobertas << endl;
    cout << "Quantidade de Arestas do grafo: " << numArestasGrafo << endl;
    */

    // Calcula e imprime o tempo de execução
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de execucao de alg_randomizado_cobertura_vertices: " << duration << " segundos" << endl;
    return qtdVerticesSolucao;
}

// Algortimo guloso reativo para cobertura de vertices
int GrafoLista::alg_reativo_cobertura_vertice() {
    // Inicializa o tempo de execução
    clock_t start = clock();

    srand(42); // Inicializa a semente do gerador de números aleatórios

    const int numAlphas = 3;
    float probabilidades[numAlphas] = {1.0 / numAlphas, 1.0 / numAlphas, 1.0 / numAlphas};
    float desempenho[numAlphas] = {0};
    int escolhaAlpha = 0;
    int arestasCobertas = 0;
    int qtdVerticesSolucao = 0; // Variável para contar a quantidade de vértices na solução

    if (numVertices <= 0 || numArestasGrafo <= 0) {
        cout << "Erro: O grafo deve conter vértices e arestas válidas." << endl;
        return 0;
    }

    bool* verticeEscolhido = new bool[numVertices + 1]();
    bool* arestaCoberta = new bool[numArestasGrafo + 1]();
    int* graus = new int[numVertices + 1]();
    int* somaVizinhos = new int[numVertices + 1]();

    // Inicializa graus e soma dos vizinhos
    for (int i = 1; i <= numVertices; i++) {
        graus[i] = listaAdjVertices->getVertice(i)->getNumVizinhos();
        NoAresta* arestaAtual = listaAdjVertices->getVertice(i)->getArestas()->getCabeca();
        while (arestaAtual != nullptr) {
            somaVizinhos[i] += listaAdjVertices->getVertice(arestaAtual->getDestino())->getNumVizinhos();
            arestaAtual = arestaAtual->getProximo();
        }
    }

    int iteracao = 0;
    while (arestasCobertas < numArestasGrafo) {
        iteracao++;

        // Ajusta as probabilidades dos alphas a cada 5 iterações
        if (iteracao % 5 == 0) {
            float somaDesempenho = 0;
            for (int i = 0; i < numAlphas; i++) {
                somaDesempenho += desempenho[i] + 0.0001;
            }
            for (int i = 0; i < numAlphas; i++) {
                probabilidades[i] = (desempenho[i] + 0.0001) / somaDesempenho;
            }
        }

        // Escolhe um alpha com base nas probabilidades ajustadas
        float r = (float)rand() / RAND_MAX;
        float acumulado = 0;
        for (int i = 0; i < numAlphas; i++) {
            acumulado += probabilidades[i];
            if (r <= acumulado) {
                escolhaAlpha = i;
                break;
            }
        }

        int* candidatos = new int[numVertices + 1];
        int numCandidatos = 0;
        int melhorSoma = 0;
        int melhorGrau = 0;

        // Seleciona vértices candidatos com base no alpha escolhido
        for (int i = 1; i <= numVertices; i++) {
            if (!verticeEscolhido[i]) {
                int somaAtual = somaVizinhos[i];
                int grauAtual = graus[i];
                if ((somaAtual > melhorSoma) || (somaAtual == melhorSoma && grauAtual > melhorGrau)) {
                    melhorSoma = somaAtual;
                    melhorGrau = grauAtual;
                    numCandidatos = 0;
                    candidatos[numCandidatos++] = i;
                } else if (somaAtual == melhorSoma) {
                    candidatos[numCandidatos++] = i;
                }
            }
        }

        if (numCandidatos == 0) {
            delete[] candidatos;
            break;
        }

        int escolhido = candidatos[rand() % numCandidatos];
        delete[] candidatos;

        verticeEscolhido[escolhido] = true;
        qtdVerticesSolucao++; // Incrementa a quantidade de vértices na solução
        NoAresta* arestaAtual = listaAdjVertices->getVertice(escolhido)->getArestas()->getCabeca();
        while (arestaAtual != nullptr) {
            int destino = arestaAtual->getDestino();
            int idAresta = arestaAtual->getIdAresta();
            if (!arestaCoberta[idAresta]) {
                arestaCoberta[idAresta] = true;
                arestasCobertas++;
                graus[destino]--;
                somaVizinhos[destino] -= graus[escolhido];

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
            }
            arestaAtual = arestaAtual->getProximo();
        }

        desempenho[escolhaAlpha] += 1.0 / numVertices;
    }

    // Imprime a melhor solução encontrada
    cout << endl << "*** Algoritmo Guloso Reativo para Cobertura de Vertices ***" << endl;
    cout << "Quantidade de Vertices na solucao reativa: " << qtdVerticesSolucao << endl;

    /*  Comentando a impressão do conjunto solução para evitar que o console trave
    cout << "Conjunto solucao: { ";
    for (int i = 1; i <= numVertices; i++) {
        if (verticeEscolhido[i]) {
            cout << i << " ";           // Imprime todos os vertices da solucao
        }
    }
    cout << "}" << endl;
    cout << "Quantidade de Arestas cobertas: " << arestasCobertas << endl;
    cout << "Quantidade de Arestas do grafo: " << numArestasGrafo << endl;
    */

    // Libera a memória alocada
    delete[] verticeEscolhido;
    delete[] arestaCoberta;
    delete[] graus;
    delete[] somaVizinhos;

    // Calcula e imprime o tempo de execução
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de execucao de alg_guloso_cobertura_vertices: " << duration << " segundos" << endl;
    return qtdVerticesSolucao;
}