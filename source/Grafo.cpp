#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cmath>
#include <string>
#include "../headers/Grafo.h"

using namespace std;

Grafo::Grafo(int numVertices, bool direcionado, bool ponderadoVertices, bool ponderadoArestas)
{
    this->nVertices = numVertices;
    this->direcionado = direcionado;
    this->ponderadoVertices = ponderadoVertices;
    this->ponderadoArestas = ponderadoArestas;

    vertices = new Vertice[nVertices];
    for (int i = 0; i < nVertices; ++i) {
        vertices[i] = Vertice(i, 0);
    }
}

Grafo::~Grafo()
{
    
}

int Grafo::get_ordem()
{
    return nVertices;
}

bool Grafo::eh_direcionado()
{
    return direcionado;
}

bool Grafo::vertice_ponderado()
{
    return ponderadoVertices;
}

bool Grafo::aresta_ponderada()
{
    return ponderadoArestas;
}

bool Grafo::eh_bipartido() {
    // Inicializa o array de cores com -1 (não colorido)
    int *color = new int [nVertices];
    for (int i = 0; i < nVertices; i++) {
        color[i] = -1;
    }

    int *fila = new int[nVertices];
    int inicioFila = 0, fimFila = 0;

    for (int i = 0; i < nVertices; i++) {
        if (color[i] == -1) { // Vértice ainda não visitado
            fila[fimFila++] = i;
            color[i] = 0; // Começa colorindo com 0

            while (inicioFila < fimFila) {
                int v = fila[inicioFila++];
                
                // Iterar sobre todos os vizinhos de v
                Aresta* aresta = vertices[v].getArestas();
                while (aresta != nullptr) {
                    int j = aresta->getDestino();
                    if (color[j] == -1) { // Se não foi colorido
                        color[j] = 1 - color[v]; // Colore com a cor oposta
                        fila[fimFila++] = j;
                    } else if (color[j] == color[v]) {
                        //Conflito de cores
                        delete[] color;
                        delete[] fila;
                        return false;
                    }
                    aresta = aresta->getProx();
                }
            }
        }
    }

    delete[] color;
    delete[] fila;
    return true; // Se passou por todos os vértices sem conflitos, é bipartido
}

int Grafo::get_grau()
{
    int grauMaior = 0;
    for (int i = 0; i < nVertices; ++i) {
        if(grauMaior < vertices[i].getGrauVertice())
            grauMaior = vertices[i].getGrauVertice();
    }
    return grauMaior;
}

Grafo* Grafo::carrega_grafo(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return nullptr;
    }

    int nVertices, direcionado, ponderadoVertices, ponderadoArestas;
    arquivo >> nVertices >> direcionado >> ponderadoVertices >> ponderadoArestas;

    Grafo* grafo = new Grafo(nVertices, direcionado, ponderadoVertices, ponderadoArestas);

    if (ponderadoVertices == 1) {
        for (int i = 0; i < nVertices; ++i) {
            int peso;
            arquivo >> peso;
            grafo->getVertices()[i].setPeso(peso);
        }
    }

    int origem, destino;
    while (arquivo >> origem >> destino) {
        if (ponderadoArestas == 1) {
            int peso;
            arquivo >> peso;
            grafo->adicionarAresta(origem, destino, peso);
        } else {
            grafo->adicionarAresta(origem, destino, 0);
        }
    }
    
    arquivo.close();
    return grafo;
}

void Grafo::novo_grafo(const string& nomeArquivoEntrada, const string& nomeArquivoSaida)
{
    ifstream arquivoEntrada(nomeArquivoEntrada);
    if (!arquivoEntrada.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivoEntrada << endl;
        return;
    }

    int grau, ordem, direcionado, compConexas, ponderadoVertices, ponderadoArestas, completo, bipartido, arvore, arestaPonte, verticeArticulacao;
    arquivoEntrada >> grau >> ordem >> direcionado >> ponderadoVertices >> ponderadoArestas >> grau >> compConexas >> completo >> bipartido >> arvore >> arestaPonte >> verticeArticulacao;
    arquivoEntrada.close();

    Grafo* grafo = new Grafo(ordem, direcionado, ponderadoVertices, ponderadoArestas);
    grafo->geraGrafoAleatorio(grau, ordem, direcionado, compConexas, ponderadoVertices, ponderadoArestas, completo, bipartido, arvore, arestaPonte, verticeArticulacao);

    ofstream arquivoSaida(nomeArquivoSaida);
    if (!arquivoSaida.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivoSaida << endl;
        delete grafo;
        return;
    }

    arquivoSaida << ordem << " " << direcionado << " " << ponderadoVertices << " " << ponderadoArestas << endl;
    if (ponderadoVertices) {
        for (int i = 0; i < ordem; ++i) {
            arquivoSaida << grafo->getVertices()[i].getPeso() << " ";
        }
        arquivoSaida << endl;
    }

    for (int i = 0; i < ordem; ++i) {
        Aresta* aresta = grafo->getVertices()[i].getArestas();
        while (aresta != nullptr) {
            arquivoSaida << i << " " << aresta->getDestino();
            if (ponderadoArestas) {
                arquivoSaida << " " << aresta->getPeso();
            }
            arquivoSaida << endl;
            aresta = aresta->getProx();
        }
    }

    arquivoSaida.close();
    delete grafo;
}

//Funcoes auxiliares
Vertice* Grafo::getVertices()
{
    return vertices;
}

void Grafo::adicionarAresta(int origem, int destino, int peso) {
    if (vertices[origem].getArestas() == nullptr) {
        vertices[origem].setArestas(new Aresta(origem, destino, peso));
    } else {
        Aresta* aresta = vertices[origem].getArestas();
        while (aresta->getProx() != nullptr) {
            aresta = aresta->getProx();
        }
        aresta->setProx(new Aresta(origem, destino, peso));
    }
}

void Grafo::geraGrafoAleatorio(int grau, int nVertices, bool direcionado, int compConexas, bool ponderadoVertices, bool ponderadoArestas, bool completo, bool bipartido, bool arvore, bool arestaPonte, bool verticeArticulacao) {
    // Adiciona arestas aleatórias
    for (int i = 0; i < nVertices; ++i) {
        for (int j = 0; j < nVertices; ++j) {
            if (i != j && (rand() % 2 == 0)) { // 50% de chance de adicionar uma aresta
                int peso = ponderadoArestas ? (rand() % 10 + 1) : 0; // Peso entre 1 e 10 se ponderado
                adicionarAresta(i, j, peso);
                if (!direcionado) {
                    adicionarAresta(j, i, peso);
                }
            }
        }
    }

    // Define pesos aleatórios para os vértices, se necessário
    if (ponderadoVertices) {
        for (int i = 0; i < nVertices; ++i) {
            int peso = rand() % 10 + 1; // Peso entre 1 e 10
            getVertices()[i].setPeso(peso);
        }
    }

    if (bipartido) {
        // Gera um grafo bipartido
        int metade = nVertices / 2;
        for (int i = 0; i < metade; ++i) {
            for (int j = metade; j < nVertices; ++j) {
                if (rand() % 2 == 0) { // 50% de chance de adicionar uma aresta
                    int peso = ponderadoArestas ? (rand() % 10 + 1) : 0; // Peso entre 1 e 10 se ponderado
                    adicionarAresta(i, j, peso);
                    if (!direcionado) {
                        adicionarAresta(j, i, peso);
                    }
                }
            }
        }
    }
}