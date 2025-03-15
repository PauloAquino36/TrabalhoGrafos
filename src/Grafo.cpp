#include "../include/Grafo.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

// #region Contrutor e Destrutor
Grafo::Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas)
{
    this->numVertices = numVertices;
    this->direcionado = direcionado;
    this->ponderadoVertices = ponderadoVertices;
    this->ponderadoArestas = ponderadoArestas;
    this->numArestasGrafo = 0;
}

Grafo::~Grafo()
{
}
// #endregion

// Retorna a quantidade de componentes conexas do grafo
int Grafo::n_conexo()
{
    bool visitado[numVertices];

    for (int i = 1; i <= numVertices; i++) {
        visitado[i] = false;
    }

    int numComponentes = 0;

    for (int i = 1; i <= numVertices; i++) {
        if (!visitado[i] && this->existe_vertice(i)) {
            dfs(i, visitado);
            numComponentes++;
        }
    }
    return numComponentes;
}

// Retorna o grau do grafo
int Grafo::get_grau()
{
    int grauMax = 0;
    for (int i = 1 ; i <= numVertices; i++) {
        if (get_num_vizinhos(i) > grauMax && existe_vertice(i)) {
            grauMax = get_num_vizinhos(i);
        }
    }
    return grauMax;
}

// Retorna a ordem do grafo (numero de vertices do grafo)
int Grafo::get_ordem()
{
    return numVertices;
}

// Retorna se o grafo eh direcionado
bool Grafo::eh_direcionado()
{
    return direcionado;
}

// Retorna se o grafo possui vertices ponderados (peso nos vertices)
bool Grafo::vertice_ponderado()
{
    return ponderadoVertices;
}

// Retorna se o grafo possui arestas ponderadas (peso nas arestas)
bool Grafo::aresta_ponderada()
{
    return ponderadoArestas;
}

// Retorna se o grafo eh completo
bool Grafo::eh_completo()
{
    for (int i = 1; i <= numVertices; i++) {
        int numVizinhos = get_num_vizinhos(i);
        if (numVizinhos != numVertices - 1) {
            return false;
        }
    }
    return true;
}

// Retrna o numero de arestas do grafo
int Grafo::get_num_arestas_grafo()
{
    return numArestasGrafo;
}

// Incrementa o numero de arestas do grafo
void Grafo::incrementa_num_arestas_grafos()
{
    numArestasGrafo++;
}

// Decrementa o numero de arestas do grafo 
void Grafo::decrementa_num_arestas_grafos()
{
    numArestasGrafo--;
}

// Diminui o numero de arestas do grafo 
void Grafo::diminui_num_arestas_grafos(int valor)
{
    numArestasGrafo = numArestasGrafo - valor;
}

// Incrementa o numero de vertices do grafo
void Grafo::incrementa_num_vertices_grafo()
{
    numVertices++;
}

// Decrementa o numero de vertices do grafo
void Grafo::decrementa_num_vertices_grafo()
{
    numVertices--;
}

// Imprime os atributos do grafo
void Grafo::imprimir_descricao()
{
    cout << "*** Descricao do Grafo ***" << endl;
    cout << "Grau: " << get_grau() << endl;
    cout << "Ordem: " << numVertices << endl;
    cout << "Direcionado: " << (eh_direcionado() ? "Sim" : "Nao") << endl;
    cout << "Componentes conexas: " << n_conexo() << endl;
    cout << "Vertices ponderados: " << (vertice_ponderado() ? "Sim" : "Nao") << endl;
    cout << "Arestas ponderadas: " << (aresta_ponderada() ? "Sim" : "Nao") << endl;
    cout << "Completo: " << (eh_completo() ? "Sim" : "Nao") << endl;
}

// Imprime algoritmos gulosos para cobertura de vertices
void Grafo::imprimir_algoritmos_cobertura_vertice(Grafo* grafo)
{
    grafo->alg_guloso_cobertura_vertice();
    grafo->alg_randomizado_cobertura_vertice();
    grafo->alg_reativo_cobertura_vertice();
}

#include <iostream>
#include <ctime>

using namespace std;

void Grafo::analise_algoritmos_cobertura_vertice(Grafo* grafo, int numVezes)
{
    double tempoGulosoTotal = 0.0, tempoRandomizadoTotal = 0.0, tempoReativoTotal = 0.0;
    int verticesSolucaoGuloso[numVezes], verticesSolucaoRandomizado[numVezes], verticesSolucaoReativo[numVezes];

    clock_t startFor = clock();
    for(int i = 0; i < numVezes; i++) {
        cout << endl << "-----------------------------------" << "Execucao " << i+1 << "-----------------------------------" << endl;
        
        // Mede o tempo do algoritmo guloso
        clock_t start = clock();
        verticesSolucaoGuloso[i] = grafo->alg_guloso_cobertura_vertice();
        clock_t end = clock();
        double tempoGuloso = double(end - start) / CLOCKS_PER_SEC;
        tempoGulosoTotal += tempoGuloso;

        // Mede o tempo do algoritmo randomizado
        start = clock();
        verticesSolucaoRandomizado[i] = grafo->alg_randomizado_cobertura_vertice();
        end = clock();
        double tempoRandomizado = double(end - start) / CLOCKS_PER_SEC;
        tempoRandomizadoTotal += tempoRandomizado;

        // Mede o tempo do algoritmo reativo
        start = clock();
        verticesSolucaoReativo[i] = grafo->alg_reativo_cobertura_vertice();
        end = clock();
        double tempoReativo = double(end - start) / CLOCKS_PER_SEC;
        tempoReativoTotal += tempoReativo;
    }
    clock_t endFor = clock();
    double durationFor = double(endFor - startFor) / CLOCKS_PER_SEC;

    int melhorGuloso = verticesSolucaoGuloso[0], melhorRandomizado = verticesSolucaoRandomizado[0], melhorReativo = verticesSolucaoReativo[0];
    int indiceMelhorGuloso = 0, indiceMelhorRandomizado = 0, indiceMelhorReativo = 0;
    int somaVerticesGuloso = 0, somaVerticesRandomizado = 0, somaVerticesReativo = 0;

    for(int i = 0; i < numVezes; i++) {
        if(verticesSolucaoGuloso[i] < melhorGuloso) {
            melhorGuloso = verticesSolucaoGuloso[i];
            indiceMelhorGuloso = i;
        }
        if(verticesSolucaoRandomizado[i] < melhorRandomizado) {
            melhorRandomizado = verticesSolucaoRandomizado[i];
            indiceMelhorRandomizado = i;
        }
        if(verticesSolucaoReativo[i] < melhorReativo) {
            melhorReativo = verticesSolucaoReativo[i];
            indiceMelhorReativo = i;
        }
        somaVerticesGuloso += verticesSolucaoGuloso[i];
        somaVerticesRandomizado += verticesSolucaoRandomizado[i];
        somaVerticesReativo += verticesSolucaoReativo[i];
    }

    cout << endl << "-----------------------------------------Analises----------------------------------------------" << endl;
    cout << "Tempo de execucao Total das " << numVezes << " execucoes: " << durationFor << " segundos" << endl;

    cout << left << setw(40) << "Tempo Total Algoritmo Guloso:" 
         << setw(10) << tempoGulosoTotal << " segundos | "
         << "Media: " << setw(10) << (tempoGulosoTotal / numVezes) << " segundos | "
         << "Media de vertices: " << setw(10) << (somaVerticesGuloso / numVezes) << " | "
         << "Melhor Solucao: " << setw(5) << melhorGuloso << " | "
         << "Execucao: " << indiceMelhorGuloso << endl;

    cout << left << setw(40) << "Tempo Total Algoritmo Randomizado:" 
         << setw(10) << tempoRandomizadoTotal << " segundos | "
         << "Media: " << setw(10) << (tempoRandomizadoTotal / numVezes) << " segundos | "
         << "Media de vertices: " << setw(10) << (somaVerticesRandomizado / numVezes) << " | "
         << "Melhor Solucao: " << setw(5) << melhorRandomizado << " | "
         << "Execucao: " << indiceMelhorRandomizado << endl;

    cout << left << setw(40) << "Tempo Total Algoritmo Reativo:" 
         << setw(10) << tempoReativoTotal << " segundos | "
         << "Media: " << setw(10) << (tempoReativoTotal / numVezes) << " segundos | "
         << "Media de vertices: " << setw(10) << (somaVerticesReativo / numVezes) << " | "
         << "Melhor Solucao: " << setw(5) << melhorReativo << " | "
         << "Execucao: " << indiceMelhorReativo << endl;
}


// Carrega o grafo a partir de um arquivo txt
void Grafo::carrega_grafo(Grafo* grafo, const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }
    int numVertices, direcionado, ponderadoVertices, ponderadoArestas;
    arquivo >> numVertices >> direcionado >> ponderadoVertices >> ponderadoArestas;

    grafo->direcionado = direcionado;
    grafo->ponderadoVertices = ponderadoVertices;
    grafo->ponderadoArestas = ponderadoArestas;

    for(int i = 1; i <= numVertices; i++) {
        if(ponderadoVertices == 1) {
            float peso;
            arquivo >> peso;
            grafo->adicionar_vertice(i, peso);
        } else {
            grafo->adicionar_vertice(i);
        }
        
    }
    
    int origem, destino;
    while (arquivo >> origem >> destino) {
        if (ponderadoArestas == 1) {
            float peso;
            arquivo >> peso;
            grafo->adicionar_aresta(origem, destino, peso);
        } else {
            grafo->adicionar_aresta(origem, destino);
        }
    }
    arquivo.close();
}

// Percorre todos os pares de vértices e busca a maior das menores distâncias
int Grafo::calcula_maior_menor_dist() {
    int maiorMenorDist = 0;
    int verticeOrigem = -1;
    int verticeDestino = -1;

    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            if (i != j) {
                int menorDist = calcula_menor_dist(i, j);
                if (menorDist != 1000000 && menorDist > maiorMenorDist) {
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

