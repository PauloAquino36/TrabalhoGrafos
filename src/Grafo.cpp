#include "../include/Grafo.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

/**
 * @brief Construtor da classe Grafo.
 * @param numVertices Numero de vertices do grafo.
 * @param direcionado Indica se o grafo eh direcionado.
 * @param ponderadoVertices Indica se o grafo possui peso nos vertices.
 * @param ponderadoArestas Indica se o grafo possui peso nas arestas.
 */
Grafo::Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas)
{
    this->numVertices = numVertices;
    this->direcionado = direcionado;
    this->ponderadoVertices = ponderadoVertices;
    this->ponderadoArestas = ponderadoArestas;
}

/**
 * @brief Destrutor da classe Grafo.
 */
Grafo::~Grafo()
{
}

/**
 * @brief Retorna a quantidade total de componentes conexas do grafo.
 * @return Numero de componentes conexas.
 */
int Grafo::n_conexo()
{
    bool* visitado = new bool[numVertices];

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

    delete[] visitado;
    return numComponentes;
}

/**
 * @brief Retorna o grau do grafo.
 * @return Grau do grafo.
 */
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

/**
 * @brief Retorna a ordem do grafo (numero de vertices do grafo).
 * @return Ordem do grafo.
 */
int Grafo::get_ordem()
{
    return numVertices;
}

/**
 * @brief Retorna se o grafo eh direcionado ou nao.
 * @return True se o grafo eh direcionado, false caso contrario.
 */
bool Grafo::eh_direcionado()
{
    return direcionado;
}

/**
 * @brief Retorna se o grafo possui peso nos vertices ou nao.
 * @return True se o grafo possui peso nos vertices, false caso contrario.
 */
bool Grafo::vertice_ponderado()
{
    return ponderadoVertices;
}

/**
 * @brief Retorna se o grafo possui peso nas arestas ou nao.
 * @return True se o grafo possui peso nas arestas, false caso contrario.
 */
bool Grafo::aresta_ponderada()
{
    return ponderadoArestas;
}

/**
 * @brief Verifica se o grafo eh completo ou nao.
 * @return True se o grafo eh completo, false caso contrario.
 */
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

/**
 * @brief Imprime os atributos do grafo.
 */
void Grafo::imprime()
{
    cout << "Excluindo Noh 1..." << endl;
    this->remover_vertice(1);
    cout << "Excluindo primeira aresta do Noh 2..." << endl << endl;
    this->remover_primeira_aresta(2);
    cout << "Grau: " << get_grau() << endl;
    cout << "Ordem: " << numVertices << endl;
    cout << "Direcionado: " << (eh_direcionado() ? "Sim" : "Nao") << endl;
    cout << "Componentes conexas: " << n_conexo() << endl;
    cout << "Vertices ponderados: " << (vertice_ponderado() ? "Sim" : "Nao") << endl;
    cout << "Arestas ponderadas: " << (aresta_ponderada() ? "Sim" : "Nao") << endl;
    cout << "Completo: " << (eh_completo() ? "Sim" : "Nao") << endl;
    this->calcula_maior_menor_dist();
    cout << "__________________________________________________________________" << endl << endl;
}

/**
 * @brief Gera um grafo a partir do arquivo grafo.txt.
 * @param grafo Ponteiro para o objeto Grafo.
 * @param nomeArquivo Nome do arquivo que contem o grafo.
 */
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