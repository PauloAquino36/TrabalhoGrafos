#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include "../headers/GrafoMatriz.h"

using namespace std;

// #region Contrutor e Destrutor
GrafoMatriz::GrafoMatriz(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas) : Grafo(numVertices, direcionado, ponderadoVertices, ponderadoArestas) {  
    matrizAdj = new int*[nVertices];
    for (int i = 0; i < nVertices; i++) {
        matrizAdj[i] = new int[nVertices];
        for (int j = 0; j < nVertices; j++) {
            matrizAdj[i][j] = 0; // Inicializa com 0 (sem aresta)
        }
    }
}

GrafoMatriz::~GrafoMatriz() {
    for (int i = 0; i < nVertices; i++) {
        delete[] matrizAdj[i];
    }
    delete[] matrizAdj;
}
// #endregion

// #region Funcoes principais
bool GrafoMatriz::eh_bipartido()
{
    int* color = new int[nVertices];
    for (int i = 0; i < nVertices; i++) {
        color[i] = -1; // Inicializa todos os vértices como não coloridos
    }

    int* fila = new int[nVertices];
    int inicioFila = 0, fimFila = 0;

    for (int i = 0; i < nVertices; i++) {
        if (color[i] == -1) { // Vértice ainda não visitado
            fila[fimFila++] = i;
            color[i] = 0; // Começa colorindo com 0

            while (inicioFila < fimFila) {
                int v = fila[inicioFila++];

                for (int j = 0; j < nVertices; j++) {
                    if (matrizAdj[v][j] != 0) { // Existe uma aresta entre v e j
                        if (color[j] == -1) { // Se não foi colorido
                            color[j] = 1 - color[v]; // Colore com a cor oposta
                            fila[fimFila++] = j;
                        } else if (color[j] == color[v]) {
                            // Conflito de cores
                            delete[] color;
                            delete[] fila;
                            return false;
                        }
                    }
                }
            }
        }
    }

    delete[] color;
    delete[] fila;
    return true; // Se passou por todos os vértices sem conflitos, é bipartido
}

int GrafoMatriz::n_conexo() {
    bool* visitado = new bool[nVertices];
    for (int i = 0; i < nVertices; i++) {
        visitado[i] = false; // Inicializa todos os vértices como não visitados
    }

    int count = 0;
    for (int v = 0; v < nVertices; v++) {
        if (!visitado[v]) {
            DFS(v, visitado); // Realiza uma DFS a partir do vértice não visitado
            count++; // Incrementa o contador de componentes conexas
        }
    }

    delete[] visitado; // Libera a memória alocada para o array visitado
    return count;
}

int GrafoMatriz::get_grau() {
    int ordem = nVertices;
     // Certifique-se de que getOrdem é acessível
    int grauMaior = 0;
    for (int i = 0; i < ordem; i++) {
        int grauAtual = 0;
        for (int j = 0; j < ordem; j++) {
            if (matrizAdj[i][j] != 0) {
                grauAtual++;
            }
        }
        if (grauAtual > grauMaior) {
            grauMaior = grauAtual;
        }
    }
    return grauMaior;
}
// #endregion

// #region Funcoes auxiliares
void GrafoMatriz::adicionarAresta(int origem, int destino, int peso) {
    if (origem < 0 || origem > nVertices || destino < 0 || destino > nVertices) {
        cout << "Origem: " << origem << " / Destino: " << destino << " / Num Vertices:"<< nVertices << endl;
        std::cerr << "Erro: indices de origem ou destino invalidos.\n";
        return;
    }

    matrizAdj[origem][destino] = peso;
    if (!direcionado) {
        matrizAdj[destino][origem] = peso;
    }
    cout << "Aresta adicionada: Origem: " << origem << " Destino: " << destino << endl;
}

void GrafoMatriz::imprimirMatrizAdj() {
    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            std::cout << matrizAdj[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void GrafoMatriz::DFS(int v, bool visitado[]) {
    visitado[v] = true;
    for (int i = 0; i < nVertices; i++) {
        if (matrizAdj[v][i] != 0 && !visitado[i]) {
            DFS(i, visitado);
        }
    }
}

bool GrafoMatriz::ehConexo() {
    bool* visitado = new bool[nVertices]{false};
    DFS(0, visitado);

    for (int i = 0; i < nVertices; i++) {
        if (!visitado[i]) {
            delete[] visitado;
            return false;
        }
    }

    delete[] visitado;
    return true;
}

bool GrafoMatriz::temCicloDFS(int v, bool visitado[], int pai) {
    visitado[v] = true;
    for (int i = 0; i < nVertices; i++) {
        if (matrizAdj[v][i] != 0) {
            if (!visitado[i]) {
                if (temCicloDFS(i, visitado, v)) {
                    return true;
                }
            } else if (i != pai) {
                return true;
            }
        }
    }
    return false;
}


Vertice& GrafoMatriz::getVertice(int i) {
    return vertices[i];
}

void GrafoMatriz::imprimeGrafoMatriz(){
    cout << "__________________________________________________________________" << endl;
    cout << endl << "--- Grafo Matriz ---" << endl;
    cout << "__________________________________________________________________" << endl << endl;
    imprime();
}

GrafoMatriz* GrafoMatriz::carrega_grafo(const std::string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return nullptr;
    }

    int nVertices, direcionado, ponderadoVertices, ponderadoArestas;
    arquivo >> nVertices >> direcionado >> ponderadoVertices >> ponderadoArestas;

    // Cria uma instância de GrafoMatriz
    GrafoMatriz* grafo = new GrafoMatriz(nVertices, direcionado, ponderadoVertices, ponderadoArestas);


    if (ponderadoVertices == 1) {
        for (int i = 0; i < nVertices; ++i) {
            int peso;
            arquivo >> peso;
            grafo->getVertice(i).setPeso(peso);
        }
    }

    int origem, destino;
    while (arquivo >> origem >> destino) {
        if (ponderadoArestas == 1) {
            int peso;
            arquivo >> peso;
            grafo->adicionarAresta(origem, destino, peso);
        } else {
            grafo->adicionarAresta(origem, destino, 1);
            cout << "Aresta: Origem: " << origem << " Destino: " << destino << endl;
        }
    }
    arquivo.close();
    return grafo;
}

GrafoMatriz* GrafoMatriz::novo_grafo() {
    string nomeArquivoLido = "descricao.txt";
    string nomeArquivoEscrito = "grafo.txt";

    //Ler arquivo de descrição
    ifstream arquivo1(nomeArquivoLido);
    if (!arquivo1.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivoLido << endl;
        return nullptr;
    }

    int grau, ordem, direcionado, componentesConexas, ponderadoVertices, ponderadoArestas, completo, bipartido, arvore, arestaPonte, verticeArticulacao;
    arquivo1 >> grau >> ordem >> direcionado >> componentesConexas >> ponderadoVertices >> ponderadoArestas >> completo >> bipartido >> arvore >> arestaPonte >> verticeArticulacao;

    cout << "Grau: " << grau << " Ordem: " << ordem << " Direcionado: " << direcionado << " Componentes Conexas: " << componentesConexas << " Ponderado Vertices: " << ponderadoVertices << " Ponderado Arestas: " << ponderadoArestas << " Completo: " << completo << " Bipartido: " << bipartido << " Arvore: " << arvore << " Aresta Ponte: " << arestaPonte << " Vertice Articulacao: " << verticeArticulacao << endl;
    arquivo1.close();


    // Cria uma instância de GrafoMatriz
    GrafoMatriz* grafo = new GrafoMatriz(ordem, direcionado, ponderadoVertices, ponderadoArestas);
    arquivo1.close();

    //Gerar Grafo Aleatorio
    for(int i = 0; i < ordem; i++){
        for(int j = 0; j < grau; j++){
            int arestaOrigem = (rand() % ordem-1) + 1; // Gera um número aleatório entre 1 e ordem-1
            int arestaDestino = (rand() % ordem-1) + 1; // Gera um número aleatório entre 1 e ordem-1
            while (arestaOrigem == arestaDestino || grafo->get_grau() > grau){
                arestaDestino = (rand() % ordem-1) + 1;
            }
            grafo->adicionarAresta(arestaOrigem, arestaDestino);
        }
    }
    for(int i = 0; i < grafo->nVertices; i++){
        grafo->getVertice(i).setPeso(2); // Gera um número aleatório
    }

    cout << "Grafo Matriz gerado aleatoriamente!" << endl;
    //

    ofstream arquivo2(nomeArquivoEscrito);

    if (!arquivo2.is_open())
    {
        cerr << "Erro ao abrir o arquivo para escrita: " << nomeArquivoEscrito << endl;
        return nullptr;
    }

    cout << "Escrevendo no arquivo '" << nomeArquivoEscrito << "':" << endl;

    arquivo2 << grafo->get_ordem() << " " << grafo->eh_direcionado() << " " << grafo->vertice_ponderado() << " " << grafo->aresta_ponderada() << endl;
    if(grafo->vertice_ponderado()){
        for (int i = 0; i < grafo->get_ordem(); i++)
        {
            arquivo2 << grafo->getVertice(i).getPeso() << " ";
        }
        arquivo2 << endl;
    }
    
    for (int i = 0; i < grafo->get_ordem(); i++) {
        for (int j = 0; j < grafo->get_ordem(); j++) {
            int peso = grafo->matrizAdj[i][j]; // Obtém o peso diretamente da matriz de adjacência
            if (peso != 0) { // Verifica se existe uma aresta 
                arquivo2 << (i+1) << " " << (j+1) << " " << peso << std::endl; // Origem, Destino, Peso
            }
        }
    }


    arquivo2.close(); //esta quebrando o codigo
    cout << "Escrita concluida!" << endl;
    return nullptr;
}

