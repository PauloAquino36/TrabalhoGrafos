#include "../include/GrafoMatriz.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>  // Biblioteca necessaria para setw()
#include <ctime>    // Biblioteca necessaria para time()

using namespace std;

// #region Contrutor e Destrutor
GrafoMatriz::GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(numVertices, direcionado, ponderadoVertices, ponderadoArestas)
{
    tamanhoMatriz = 10;

    if (numVertices <= 0)
    {
        numVertices = 1;
    }

    while (tamanhoMatriz < numVertices)
    {
        tamanhoMatriz *= 2;
    }

    matrizAdj = new int *[tamanhoMatriz];
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        matrizAdj[i] = new int[tamanhoMatriz];
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            matrizAdj[i][j] = 0; // Inicializa com 0 (sem aresta)
        }
    }
}

GrafoMatriz::~GrafoMatriz()
{
    if (matrizAdj != nullptr)
    { // Verifica se ha memoria alocada
        for (int i = 0; i < tamanhoMatriz; i++)
        {
            delete[] matrizAdj[i];
        }
        delete[] matrizAdj;
        matrizAdj = nullptr; // Evita ponteiro danificado
    }
}
// #endregion

// #region Funcoes auxiliares
// Adiciona um vértice ao grafo
void GrafoMatriz::adicionar_vertice(int id, float peso)
{
    int novoNumVertices = numVertices + 1;
    numVertices = novoNumVertices;

    if (novoNumVertices >= tamanhoMatriz)
    {
        cout << "Aumentando matriz de adjacencia...\n";
        int antigoTamanhoMatriz = tamanhoMatriz;
        tamanhoMatriz = max(tamanhoMatriz * 2, novoNumVertices); // Expansao mais segura
        int **novaMatriz = new int *[tamanhoMatriz];

        for (int i = 0; i < tamanhoMatriz; i++)
        {
            novaMatriz[i] = new int[tamanhoMatriz](); // Inicializa com 0
        }

        // Copia os valores da matriz antiga para a nova matriz
        for (int i = 0; i < antigoTamanhoMatriz; i++)
        {
            for (int j = 0; j < antigoTamanhoMatriz; j++)
            {
                novaMatriz[i][j] = matrizAdj[i][j];
            }
        }

        // Libera a matriz antiga corretamente
        for (int i = 0; i < antigoTamanhoMatriz; i++) // Correcao aqui
        {
            delete[] matrizAdj[i];
        }
        delete[] matrizAdj;

        matrizAdj = novaMatriz;
    }
}

// Remove um vertice do grafo
void GrafoMatriz::remover_vertice(int id)
{
    if (id < 0 || id >= numVertices)
    {
        cout << "Erro: indice de vertice invalido.\n";
        return;
    }
    // Atualiza o contador de arestas
    for (int i = 0; i < numVertices; i++)
    {
        if (matrizAdj[id][i] != 0)
        {
            decrementa_num_arestas_grafos();
            if (!direcionado)
            {
                decrementa_num_arestas_grafos();
            }
        }
        if (matrizAdj[i][id] != 0 && i != id)
        {
            decrementa_num_arestas_grafos();
        }
    }
    int novoNumVertices = numVertices - 1;
    int **novaMatriz = new int *[tamanhoMatriz];

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        novaMatriz[i] = new int[tamanhoMatriz]();
    }

    // Copia os valores da matriz antiga para a nova, excluindo o vertice removido
    for (int i = 0, ni = 0; i < tamanhoMatriz; i++)
    {
        if (i == id)
            continue;

        for (int j = 0, nj = 0; j < tamanhoMatriz; j++)
        {
            if (j == id)
                continue;

            novaMatriz[ni][nj] = matrizAdj[i][j];
            nj++;
        }
        ni++;
    }

    // Libera a matriz antiga
    for (int i = 0; i < numVertices; i++)
    {
        delete[] matrizAdj[i];
    }
    delete[] matrizAdj;

    matrizAdj = novaMatriz;
    numVertices = novoNumVertices;
}

void GrafoMatriz::remover_aresta(int origem, int destino)
{
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices)
    {
        cout << "Erro: indices de origem ou destino invalidos.\n";
        return;
    }

    matrizAdj[origem][destino] = 0;
    decrementa_num_arestas_grafos();
    if (!direcionado)
    {
        matrizAdj[destino][origem] = 0;
        decrementa_num_arestas_grafos();
    }
}

// Remove a primeira aresta de um vertice
void GrafoMatriz::remover_primeira_aresta(int id)
{
    if (id < 0 || id > numVertices)
    {
        cout << "Erro: indice de vertice invalido." << endl;
        return;
    }

    for (int i = 0; i <= numVertices; i++)
    {
        if (matrizAdj[id][i] != 0)
        {
            matrizAdj[id][i] = 0;
            decrementa_num_arestas_grafos();
            if (!direcionado)
            {
                matrizAdj[i][id] = 0;
                decrementa_num_arestas_grafos();
            }
            return;
        }
    }
}

void GrafoMatriz::adicionar_aresta(int origem, int destino, float peso)
{
    if (origem < 0 || origem > numVertices || destino < 0 || destino > numVertices)
    {
        cout << "Erro: indices de origem ou destino invalidos.\n";
        return;
    }
    if( origem == destino){
        cout << "Erro: origem e destino iguais.\n";
        return;
    }

    if(matrizAdj[origem][destino] != 0){
        cout << "Erro: aresta ja existe.\n";
        return;
    }


    if (ponderadoArestas)
    {
        matrizAdj[origem][destino] = peso;
        incrementa_num_arestas_grafos();
        if (!direcionado)
        {
            matrizAdj[destino][origem] = peso;
            incrementa_num_arestas_grafos();
        }
    }
    else
    {
        matrizAdj[origem][destino] = 1;
        incrementa_num_arestas_grafos();
        if (!direcionado)
        {
            matrizAdj[destino][origem] = 1;
            incrementa_num_arestas_grafos();
        }
    }
}

// Calcula menor distancia entre dois vertices
int GrafoMatriz::calcula_menor_dist(int origem, int destino)
{
    const int INF = 1000000; // Valor grande para representar infinito
    int *dist = new int[numVertices + 1];
    int *prev = new int[numVertices + 1];
    bool *visitado = new bool[numVertices + 1];

    for (int i = 1; i <= numVertices; i++)
    {
        dist[i] = INF;
        prev[i] = -1;
        visitado[i] = false;
    }

    dist[origem] = 0;

    // Loop principal do algoritmo de Dijkstra
    for (int i = 1; i <= numVertices; i++)
    {
        int u = -1;

        // Encontra o vertice nao visitado com a menor distancia
        for (int j = 1; j <= numVertices; j++)
        {
            if (!visitado[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }

        // Se a menor distancia e infinita, todos os vertices restantes sao inacessiveis
        if (dist[u] == INF)
        {
            break;
        }

        visitado[u] = true;

        // Atualiza as distancias dos vizinhos do vertice atual
        for (int v = 1; v <= numVertices; v++)
        {
            if (matrizAdj[u][v] != 0 && dist[u] + matrizAdj[u][v] < dist[v])
            {
                dist[v] = dist[u] + matrizAdj[u][v];
                prev[v] = u;
            }
        }
    }

    int menorDist = dist[destino];

    delete[] dist;
    delete[] prev;
    delete[] visitado;

    return menorDist;
}

// Retorna a quantidade de vizinhos de um vertice
int GrafoMatriz::get_num_vizinhos(int id)
{
    if (id < 0 || id > numVertices)
    {
        return 0; // Retorna 0 se o ID do vertice for invalido
    }

    int contador = 0;
    for (int i = 0; i <= numVertices; i++)
    {
        if (matrizAdj[id][i] != 0)
        { // Se houver uma aresta entre os vertices
            contador++;
        }
    }
    return contador;
}

// Funcao de busca em largura
void GrafoMatriz::dfs(int id, bool *visitado)
{
    if (id < 0 || id > numVertices || visitado[id])
    {
        return; // Verifica se o vertice eh valido ou ja foi visitado
    }

    visitado[id] = true; // Marca o vertice como visitado

    for (int i = 0; i <= numVertices; i++)
    {
        if (matrizAdj[id][i] != 0 && !visitado[i])
        { // Se houver uma aresta e o vertice nao foi visitado
            dfs(i, visitado);
        }
    }
}

// Verifica se o vertice existe no grafo
bool GrafoMatriz::existe_vertice(int id)
{
    return (id >= 0 && id <= numVertices);
}
// #endregion

// #region Funcoes de imprimir
// Imprime a matriz de adjacencia
void GrafoMatriz::imprimirMatrizAdj()
{
    cout << "__________________________________________________________________" << endl;
    cout << endl << "--- Matriz de Adjacencia ---" << endl << endl;

    // Imprime o cabecalho dos indices dos vertices
    cout << "  V";
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        cout << std::setw(3) << i << " ";
    }
    cout << endl;

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        // Imprime o indice do vertice na lateral esquerda
        cout << std::setw(3) << i;

        for (int j = 0; j < tamanhoMatriz; j++)
        {
            std::cout << std::setw(3) << matrizAdj[i][j] << " ";
        }
        std::cout << std::endl;
    }
    cout << "__________________________________________________________________" << endl;
}

// Imprime os atributos do grafo
void GrafoMatriz::imprimeGrafoMatriz()
{
    cout << "__________________________________________________________________" << endl;
    cout << endl
         << "--- Grafo Matriz ---" << endl;
    cout << "__________________________________________________________________" << endl
         << endl;
    imprimir_descricao();
}
// #endregion

// #region Algoritmos Gulosos para cobertura de vertices
// Algoritmo guloso para cobertura de vertices
void GrafoMatriz::alg_guloso_cobertura_vertice() {
    // Inicializa o tempo de execução
    clock_t start = clock();

    // Aloca estruturas básicas
    bool *verticeEscolhido = new bool[numVertices + 1];
    bool **arestaCoberta = new bool*[numVertices + 1];
    int *graus = new int[numVertices + 1];

    // Aloca estruturas para listas de vizinhos
    int **vizinhos = new int*[numVertices + 1];
    int *contVizinhos = new int[numVertices + 1];  // Quantos vizinhos foram armazenados para cada vértice

    // Inicializa estruturas
    for (int i = 1; i <= numVertices; i++) {
        verticeEscolhido[i] = false;
        arestaCoberta[i] = new bool[numVertices + 1];
        for (int j = 1; j <= numVertices; j++) {
            arestaCoberta[i][j] = false;
        }
        graus[i] = get_num_vizinhos(i);
        contVizinhos[i] = 0;
        // Aloca espaço para a lista de vizinhos com tamanho igual ao grau inicial
        if (graus[i] > 0)
            vizinhos[i] = new int[graus[i]];
        else
            vizinhos[i] = nullptr;
    }

    // Preenche as listas de vizinhos com base na matriz de adjacência
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            if (matrizAdj[i][j] != 0) {
                vizinhos[i][contVizinhos[i]++] = j;
            }
        }
    }

    // Calcula o total de "entradas de arestas" (para grafos não direcionados, cada aresta aparece duas vezes)
    int totalEdges = 0;
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            if (matrizAdj[i][j] != 0)
                totalEdges++;
        }
    }

    int arestasCobertas = 0;

    // Função lambda que calcula a soma dos graus dos vizinhos não cobertos de v
    auto calcularSomaVizinhos = [&](int v) {
        int soma = 0;
        for (int k = 0; k < contVizinhos[v]; k++) {
            int u = vizinhos[v][k];
            if (!verticeEscolhido[u] && !arestaCoberta[v][u])
                soma += graus[u];
        }
        return soma;
    };

    // Loop principal do algoritmo guloso
    while (true) {
        int melhorVertice = -1;
        int melhorSoma = -1;
        int melhorGrau = -1;

        for (int i = 1; i <= numVertices; i++) {
            if (!verticeEscolhido[i]) {
                int somaAtual = calcularSomaVizinhos(i);
                int grauAtual = graus[i];
                // Critério de desempate: maior soma, depois maior grau e, por fim, menor índice
                if (somaAtual > melhorSoma ||
                   (somaAtual == melhorSoma && grauAtual > melhorGrau) ||
                   (somaAtual == melhorSoma && grauAtual == melhorGrau && (melhorVertice == -1 || i < melhorVertice))) {
                    melhorSoma = somaAtual;
                    melhorGrau = grauAtual;
                    melhorVertice = i;
                }
            }
        }

        if (melhorVertice == -1)
            break;

        verticeEscolhido[melhorVertice] = true;
        // Atualiza cobertura das arestas a partir do vértice escolhido, iterando somente sobre seus vizinhos
        for (int k = 0; k < contVizinhos[melhorVertice]; k++) {
            int j = vizinhos[melhorVertice][k];
            if (!arestaCoberta[melhorVertice][j]) {
                arestaCoberta[melhorVertice][j] = true;
                arestasCobertas++;
                if (!direcionado) {
                    if (!arestaCoberta[j][melhorVertice]) {
                        arestaCoberta[j][melhorVertice] = true;
                        arestasCobertas++;
                    }
                    // Atualiza o grau do vizinho
                    graus[j]--;
                }
            }
        }

        // Se todas as arestas estiverem cobertas, encerra o loop
        if (arestasCobertas == totalEdges)
            break;
    }

    // Imprime o conjunto solução
    cout << endl << "*** Algoritmo Guloso para Cobertura de Vertices ***" << endl;
    cout << "Conjunto solucao: { ";
    int qtdVerticesSolucao = 0;
    for (int i = 1; i <= numVertices; i++) {
        if (verticeEscolhido[i]) {
            qtdVerticesSolucao++;
            //cout << i << " ";        // Mostra conjunto solução
        }
    }
    cout << "Esta comentado no codigo pesquise por 'cout << i << " ";' e descomente";
    cout << "}" << endl;
    cout << "Alg guloso" << endl;
    cout << "Quantidade de vertices na solucao: " << qtdVerticesSolucao << endl;
    cout << "Quantidade de arestas cobertas: " << arestasCobertas << endl;
    cout << "Quantidade de Arestas do grafo: " << numArestasGrafo << endl;

    // Libera a memória alocada
    for (int i = 1; i <= numVertices; i++) {
        delete[] arestaCoberta[i];
        if (vizinhos[i] != nullptr)
            delete[] vizinhos[i];
    }
    delete[] arestaCoberta;
    delete[] verticeEscolhido;
    delete[] graus;
    delete[] vizinhos;
    delete[] contVizinhos;

    // Calcula e imprime o tempo de execução
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de execucao de coberturaVerticesGulosa: " << duration << " segundos" << endl;
}

// Algoritmo guloso randomizado para cobertura de vertices
void GrafoMatriz::alg_randomizado_cobertura_vertice() {
    // Inicializa o tempo de execução
    clock_t start = clock();

    bool* verticeEscolhido = new bool[numVertices + 1]();  // Inicializa com 'false'
    bool** arestaCoberta = new bool*[numVertices + 1];  // Aloca um vetor de ponteiros
    for (int i = 0; i <= numVertices; i++) {
        arestaCoberta[i] = new bool[numVertices + 1]();  // Inicializa cada linha com 'false'
    }

    int* graus = new int[numVertices + 1]();  // Inicializa com '0'
    int* somaVizinhos = new int[numVertices + 1]();  // Inicializa com '0'
    int arestasCobertas = 0;

    // Inicializa graus e soma dos vizinhos
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            if (matrizAdj[i][j] != 0) {
                graus[i]++;
                somaVizinhos[i] += graus[j];
            }
        }
    }
    cout << "Debug" << endl;

    // Algoritmo guloso randomizado
    while (arestasCobertas < numArestasGrafo) {
        int melhorSoma = 0;
        int melhorGrau = 0;
        int melhorVertice = -1;

        // Coleta o vértice com o maior valor de soma dos vizinhos
        for (int i = 1; i <= numVertices; i++) {
            if (!verticeEscolhido[i]) {
                int somaAtual = somaVizinhos[i];
                int grauAtual = graus[i];

                if ((somaAtual > melhorSoma) || (somaAtual == melhorSoma && grauAtual > melhorGrau)) {
                    melhorSoma = somaAtual;
                    melhorGrau = grauAtual;
                    melhorVertice = i;
                }
            }
        }

        if (melhorVertice == -1) break;  // Se não houver mais vértices para escolher, sai

        // Marca o vértice escolhido
        verticeEscolhido[melhorVertice] = true;

        // Atualiza graus e arestas cobertas
        for (int j = 1; j <= numVertices; j++) {
            if (matrizAdj[melhorVertice][j] != 0 && !arestaCoberta[melhorVertice][j]) {
                arestaCoberta[melhorVertice][j] = arestaCoberta[j][melhorVertice] = true;
                arestasCobertas++;
                graus[j]--;
                somaVizinhos[j] -= graus[melhorVertice];
            }
        }
    }

    // Imprime o conjunto solução
    cout << endl << "*** Algoritmo Guloso Randomizado para Cobertura de Vertices ***" << endl;
    cout << "Conjunto solucao: { ";
    int qtdVerticesSolucao = 0;
    for (int i = 1; i <= numVertices; i++) {
        if (verticeEscolhido[i]) {
            qtdVerticesSolucao++;
            //cout << i << " ";        // Mostra conjunto solução
        }
    }
    cout << "Esta comentado no codigo pesquise por 'cout << i << " ";' e descomente";
    cout << "}" << endl;
    cout << "Alg randomizado" << endl;
    cout << "Quantidade de Vertices na solucao: " << qtdVerticesSolucao << endl;
    cout << "Quantidade de Arestas cobertas: " << arestasCobertas << endl;
    cout << "Quantidade de Arestas do grafo: " << numArestasGrafo << endl;

    // Libera a memória alocada
    delete[] verticeEscolhido;
    delete[] graus;
    delete[] somaVizinhos;
    for (int i = 0; i <= numVertices; i++) {
        delete[] arestaCoberta[i];
    }
    delete[] arestaCoberta;

    // Calcula e imprime o tempo de execução
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de execucao de alg_randomizado_cobertura_vertice: " << duration << " segundos" << endl;
}

// Algoritmo guloso reativo para cobertura de vertices
void GrafoMatriz::alg_reativo_cobertura_vertice() {
    // Inicializa o tempo de execução
    clock_t start = clock();

    bool* verticeEscolhido = new bool[numVertices + 1]();
    
    // Aloca matriz dinamicamente
    bool** arestaCoberta = new bool*[numVertices + 1];
    for (int i = 0; i <= numVertices; i++) {
        arestaCoberta[i] = new bool[numVertices + 1](); // Inicializa com false
    }

    int* graus = new int[numVertices + 1]();
    int* somaVizinhos = new int[numVertices + 1]();
    int arestasCobertas = 0;
    double fatorAleatoriedade = 0.5;

    // Inicializa graus e soma dos vizinhos
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            if (matrizAdj[i][j] != 0) {
                graus[i]++;
                somaVizinhos[i] += graus[j];
            }
        }
    }

    while (arestasCobertas < numArestasGrafo) {
        int candidatos[numVertices + 1];
        int qtdCandidatos = 0;
        int melhorSoma = 0;
        int melhorGrau = 0;

        for (int i = 1; i <= numVertices; i++) {
            if (!verticeEscolhido[i]) {
                int somaAtual = somaVizinhos[i];
                int grauAtual = graus[i];

                if ((somaAtual > melhorSoma) || (somaAtual == melhorSoma && grauAtual > melhorGrau)) {
                    melhorSoma = somaAtual;
                    melhorGrau = grauAtual;
                    qtdCandidatos = 0;
                    candidatos[qtdCandidatos++] = i;
                } else if (somaAtual == melhorSoma && grauAtual == melhorGrau) {
                    candidatos[qtdCandidatos++] = i;
                }
            }
        }

        if (qtdCandidatos == 0) break;

        int escolhido;
        if ((double)rand() / RAND_MAX < fatorAleatoriedade) {
            escolhido = candidatos[rand() % qtdCandidatos];
        } else {
            escolhido = candidatos[0]; // Escolha gulosa
        }

        verticeEscolhido[escolhido] = true;

        // Atualiza graus e arestas cobertas
        for (int j = 1; j <= numVertices; j++) {
            if (matrizAdj[escolhido][j] != 0 && !arestaCoberta[escolhido][j]) {
                arestaCoberta[escolhido][j] = arestaCoberta[j][escolhido] = true;
                arestasCobertas++;
                graus[j]--;
                somaVizinhos[j] -= graus[escolhido];
            }
        }

        // Ajusta fator de aleatoriedade dinamicamente
        fatorAleatoriedade = 1.0 - ((double)arestasCobertas / numArestasGrafo);
    }

    // Imprime o conjunto solução
    cout << endl << "*** Algoritmo Reativo para Cobertura de Vertices ***" << endl;
    cout << "Conjunto solucao: { ";
    int qtdVerticesSolucao = 0;
    
    for (int i = 1; i <= numVertices; i++) {
        if (verticeEscolhido[i]) {
            qtdVerticesSolucao++;
            //cout << i << " ";        // Mostra conjunto solução
        }
    }
    cout << "Esta comentado no codigo pesquise por 'cout << i << " ";' e descomente";
    cout << "}" << endl;
    cout << "Alg reativo" << endl;
    cout << "Quantidade de Vertices na solucao: " << qtdVerticesSolucao << endl;
    cout << "Quantidade de Arestas cobertas: " << arestasCobertas << endl;
    cout << "Quantidade de Arestas do grafo: " << numArestasGrafo << endl;

    // Libera memória alocada
    delete[] verticeEscolhido;
    delete[] graus;
    delete[] somaVizinhos;
    for (int i = 0; i <= numVertices; i++) {
        delete[] arestaCoberta[i];
    }
    delete[] arestaCoberta;

    // Calcula e imprime o tempo de execução
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de execucao de alg_reativo_cobertura_vertice: " << duration << " segundos" << endl;
}
// #endregion