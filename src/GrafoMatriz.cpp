#include "../include/GrafoMatriz.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib> // Para srand() e rand()
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
int GrafoMatriz::alg_guloso_cobertura_vertice() {
    // Inicializa o tempo de execução
    clock_t start = clock();

    // Aloca estruturas básicas
    bool *verticeEscolhido = new bool[numVertices + 1];
    bool **arestaCoberta = new bool*[numVertices + 1];
    int *graus = new int[numVertices + 1];
    int qtdVerticesSolucao = 0;

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
    int totalEdges = numArestasGrafo;

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
        qtdVerticesSolucao++;
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
    cout << "Quantidade de vertices na solucao: " << qtdVerticesSolucao << endl;

    /* Comentando a impressão do conjunto solução para evitar que o console trave
    cout << "Conjunto solucao: { ";
    for (int i = 1; i <= numVertices; i++) {
        if (verticeEscolhido[i]) {
            cout << i << " ";        // Imprime todos os vertices da solucao
        }
    }
    cout << "}" << endl;
    cout << "Quantidade de arestas cobertas: " << arestasCobertas << endl;
    cout << "Quantidade de Arestas do grafo: " << numArestasGrafo << endl;
    */

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
    cout << "Tempo de execucao de alg_guloso_cobertura_vertice: " << duration << " segundos" << endl;
    return qtdVerticesSolucao;
}

// Algoritmo guloso randomizado para cobertura de vertices
int GrafoMatriz::alg_randomizado_cobertura_vertice() {
    clock_t start = clock();

    double alpha = 0.3 + (rand() % 40) / 100.0; // Define um alpha aleatório entre 0.3 e 0.7
    srand(time(nullptr)); // Garante que a escolha aleatória seja diferente a cada execução

    bool *verticeEscolhido = new bool[numVertices + 1];
    bool **arestaCoberta = new bool*[numVertices + 1];
    int *graus = new int[numVertices + 1];
    int qtdVerticesSolucao = 0;
    int **vizinhos = new int*[numVertices + 1];
    int *contVizinhos = new int[numVertices + 1];

    for (int i = 1; i <= numVertices; i++) {
        verticeEscolhido[i] = false;
        arestaCoberta[i] = new bool[numVertices + 1];
        for (int j = 1; j <= numVertices; j++) {
            arestaCoberta[i][j] = false;
        }
        graus[i] = get_num_vizinhos(i);
        contVizinhos[i] = 0;
        vizinhos[i] = (graus[i] > 0) ? new int[graus[i]] : nullptr;
    }

    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            if (matrizAdj[i][j] != 0) {
                vizinhos[i][contVizinhos[i]++] = j;
            }
        }
    }

    int totalEdges = numArestasGrafo;
    int arestasCobertas = 0;

    auto calcularSomaVizinhos = [&](int v) {
        int soma = 0;
        for (int k = 0; k < contVizinhos[v]; k++) {
            int u = vizinhos[v][k];
            if (!verticeEscolhido[u] && !arestaCoberta[v][u])
                soma += graus[u];
        }
        return soma;
    };

    while (arestasCobertas < totalEdges) {
        int *candidatos = new int[numVertices];
        int *somas = new int[numVertices];
        int numCandidatos = 0;
        int melhorSoma = -1;

        for (int i = 1; i <= numVertices; i++) {
            if (!verticeEscolhido[i]) {
                int somaAtual = calcularSomaVizinhos(i);
                if (somaAtual > melhorSoma)
                    melhorSoma = somaAtual;
                candidatos[numCandidatos] = i;
                somas[numCandidatos] = somaAtual;
                numCandidatos++;
            }
        }

        int *listaRestrita = new int[numCandidatos];
        int numRestritos = 0;
        for (int i = 0; i < numCandidatos; i++) {
            if (somas[i] >= melhorSoma * alpha) {
                listaRestrita[numRestritos++] = candidatos[i];
            }
        }

        delete[] candidatos;
        delete[] somas;

        if (numRestritos == 0) {
            delete[] listaRestrita;
            break;
        }

        int escolhido = listaRestrita[rand() % numRestritos];
        delete[] listaRestrita;

        verticeEscolhido[escolhido] = true;
        qtdVerticesSolucao++;

        for (int k = 0; k < contVizinhos[escolhido]; k++) {
            int j = vizinhos[escolhido][k];
            if (!arestaCoberta[escolhido][j]) {
                arestaCoberta[escolhido][j] = true;
                arestasCobertas++;
                if (!direcionado) {
                    if (!arestaCoberta[j][escolhido]) {
                        arestaCoberta[j][escolhido] = true;
                        arestasCobertas++;
                    }
                    graus[j]--;
                }
            }
        }
    }

    cout << endl << "*** Algoritmo Guloso Randomizado para Cobertura de Vertices ***" << endl;
    cout << "Quantidade de vertices na solucao: " << qtdVerticesSolucao << endl;

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

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de execucao de alg_randomizado_cobertura_vertice: " << duration << " segundos" << endl;
    return qtdVerticesSolucao;
}
// Algoritmo guloso reativo para cobertura de vertices

int GrafoMatriz::alg_reativo_cobertura_vertice() {
    clock_t start = clock();

    // Parâmetros internos
    const int numAlphas = 5; // Reduzido de 10 para 5
    const int maxIteracoes = 10; // Mantido em 10 iterações
    const int blocoIteracoes = 5; // Ajuste a cada 5 iterações

    // Valores de alpha (variando de 0.1 a 0.9)
    double alphas[numAlphas];
    for (int i = 0; i < numAlphas; i++) {
        alphas[i] = 0.1 + (0.8 * i) / (numAlphas - 1);
    }

    // Probabilidades iniciais (uniforme)
    double probabilidades[numAlphas];
    for (int i = 0; i < numAlphas; i++) {
        probabilidades[i] = 1.0 / numAlphas;
    }

    // Estruturas para armazenar o desempenho de cada alpha
    double somaQualidade[numAlphas] = {0};
    int contagemAlpha[numAlphas] = {0};

    // Melhor solução encontrada
    int qtdVerticesSolucao = numVertices; // Substitui INT_MAX
    int melhorIteracao = -1;

    // Loop principal do algoritmo reativo
    for (int iteracao = 1; iteracao <= maxIteracoes; iteracao++) {
        // Escolhe um alpha com base nas probabilidades atuais
        double r = (double)rand() / RAND_MAX;
        double somaProbabilidades = 0;
        int alphaEscolhido = 0;
        for (int i = 0; i < numAlphas; i++) {
            somaProbabilidades += probabilidades[i];
            if (r <= somaProbabilidades) {
                alphaEscolhido = i;
                break;
            }
        }

        // Executa o algoritmo guloso randomizado com o alpha escolhido
        int qtdVerticesAtual = alg_randomizado_cobertura_vertice_com_alpha(alphas[alphaEscolhido]);

        // Atualiza o desempenho do alpha escolhido
        somaQualidade[alphaEscolhido] += qtdVerticesAtual;
        contagemAlpha[alphaEscolhido]++;

        // Atualiza a melhor solução encontrada
        if (qtdVerticesAtual < qtdVerticesSolucao) {
            qtdVerticesSolucao = qtdVerticesAtual;
            melhorIteracao = iteracao;
        }

        // Ajusta as probabilidades após cada bloco de iterações
        if (iteracao % blocoIteracoes == 0) {
            double mediaQualidade[numAlphas];
            for (int i = 0; i < numAlphas; i++) {
                if (contagemAlpha[i] > 0) {
                    mediaQualidade[i] = somaQualidade[i] / contagemAlpha[i];
                } else {
                    mediaQualidade[i] = numVertices; // Penaliza alphas não utilizados
                }
            }

            // Calcula a qualidade relativa de cada alpha
            double somaInversos = 0;
            for (int i = 0; i < numAlphas; i++) {
                somaInversos += 1.0 / mediaQualidade[i];
            }

            // Atualiza as probabilidades
            for (int i = 0; i < numAlphas; i++) {
                probabilidades[i] = (1.0 / mediaQualidade[i]) / somaInversos;
            }

            // Reinicia as estruturas de desempenho
            for (int i = 0; i < numAlphas; i++) {
                somaQualidade[i] = 0;
                contagemAlpha[i] = 0;
            }
        }
    }

    // Imprime a melhor solução encontrada
    cout << endl << "*** Algoritmo Guloso Reativo para Cobertura de Vertices ***" << endl;
    cout << "Quantidade de vertices na solucao: " << qtdVerticesSolucao << endl;
    cout << "Melhor solucao encontrada na iteracao: " << melhorIteracao << endl;

    // Calcula e imprime o tempo de execução
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo de execucao de alg_reativo_cobertura_vertice: " << duration << " segundos" << endl;

    return qtdVerticesSolucao;
}

int GrafoMatriz::alg_randomizado_cobertura_vertice_com_alpha(double alpha) {
    // Aloca e inicializa estruturas
    bool *verticeEscolhido = new bool[numVertices + 1];
    bool **arestaCoberta = new bool*[numVertices + 1];
    int *graus = new int[numVertices + 1];
    int qtdVerticesSolucao = 0;
    int **vizinhos = new int*[numVertices + 1];
    int *contVizinhos = new int[numVertices + 1];

    // Inicializa as estruturas
    for (int i = 1; i <= numVertices; i++) {
        verticeEscolhido[i] = false;
        arestaCoberta[i] = new bool[numVertices + 1];
        for (int j = 1; j <= numVertices; j++) {
            arestaCoberta[i][j] = false;
        }
        graus[i] = get_num_vizinhos(i); // Obtém o grau do vértice i
        contVizinhos[i] = 0;
        if (graus[i] > 0) {
            vizinhos[i] = new int[graus[i]]; // Aloca espaço para os vizinhos
        } else {
            vizinhos[i] = nullptr;
        }
    }

    // Preenche as listas de vizinhos com base na matriz de adjacência
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            if (matrizAdj[i][j] != 0) {
                vizinhos[i][contVizinhos[i]++] = j;
            }
        }
    }

    // Calcula o total de arestas no grafo
    int totalEdges = numArestasGrafo;
    int arestasCobertas = 0;

    // Função lambda para calcular a soma dos graus dos vizinhos não cobertos
    auto calcularSomaVizinhos = [&](int v) {
        int soma = 0;
        for (int k = 0; k < contVizinhos[v]; k++) {
            int u = vizinhos[v][k];
            if (!verticeEscolhido[u] && !arestaCoberta[v][u]) {
                soma += graus[u];
            }
        }
        return soma;
    };

    // Loop principal do algoritmo guloso randomizado
    while (arestasCobertas < totalEdges) {
        // Cria lista de candidatos e suas somas de vizinhos
        int *candidatos = new int[numVertices];
        int *somas = new int[numVertices];
        int numCandidatos = 0;
        int melhorSoma = -1;

        // Encontra todos os vértices não escolhidos e calcula suas somas
        for (int i = 1; i <= numVertices; i++) {
            if (!verticeEscolhido[i]) {
                int somaAtual = calcularSomaVizinhos(i);
                if (somaAtual > melhorSoma) {
                    melhorSoma = somaAtual;
                }
                candidatos[numCandidatos] = i;
                somas[numCandidatos] = somaAtual;
                numCandidatos++;
            }
        }

        // Cria a lista restrita de candidatos com base no alpha
        int *listaRestrita = new int[numCandidatos];
        int numRestritos = 0;
        for (int i = 0; i < numCandidatos; i++) {
            if (somas[i] >= melhorSoma * alpha) {
                listaRestrita[numRestritos++] = candidatos[i];
            }
        }

        // Libera a memória dos arrays temporários
        delete[] candidatos;
        delete[] somas;

        // Se não houver candidatos, encerra o loop
        if (numRestritos == 0) {
            delete[] listaRestrita;
            break;
        }

        // Escolhe um vértice aleatório da lista restrita
        int escolhido = listaRestrita[rand() % numRestritos];
        delete[] listaRestrita;

        // Marca o vértice escolhido como parte da solução
        verticeEscolhido[escolhido] = true;
        qtdVerticesSolucao++;

        // Cobre as arestas incidentes ao vértice escolhido
        for (int k = 0; k < contVizinhos[escolhido]; k++) {
            int j = vizinhos[escolhido][k];
            if (!arestaCoberta[escolhido][j]) {
                arestaCoberta[escolhido][j] = true;
                arestasCobertas++;
                if (!direcionado) {
                    if (!arestaCoberta[j][escolhido]) {
                        arestaCoberta[j][escolhido] = true;
                        arestasCobertas++;
                    }
                    // Atualiza o grau do vizinho
                    graus[j]--;
                }
            }
        }
    }

    // Libera a memória alocada
    for (int i = 1; i <= numVertices; i++) {
        delete[] arestaCoberta[i];
        if (vizinhos[i] != nullptr) {
            delete[] vizinhos[i];
        }
    }
    delete[] arestaCoberta;
    delete[] verticeEscolhido;
    delete[] graus;
    delete[] vizinhos;
    delete[] contVizinhos;

    // Retorna o número de vértices na solução
    return qtdVerticesSolucao;
}

// #endregion