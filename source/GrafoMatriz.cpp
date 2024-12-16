#include "GrafoMatriz.h"
#include <iostream>
#include <cmath>  // Para cálculos matemáticos
#include <cstdlib>  // Para manipulação de números aleatórios (se necessário)

using namespace std;

// Construtor
GrafoMatriz::GrafoMatriz(int nVertices, bool direcionado) {
    this->numVertices = nVertices;
    this->direcionado = direcionado;

    // Aloca a matriz de adjacência
    matrizAdj = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        matrizAdj[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j) {
            matrizAdj[i][j] = (direcionado) ? 0 : -1;  // Inicializa com 0 (se for direcionado) ou -1 (não direcionado)
        }
    }
}

// Destruidor
GrafoMatriz::~GrafoMatriz() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] matrizAdj[i];
    }
    delete[] matrizAdj;
}

// Função para adicionar uma aresta
void GrafoMatriz::adicionar_aresta(int vertice1, int vertice2, int peso) {
    if (vertice1 >= 0 && vertice1 < numVertices && vertice2 >= 0 && vertice2 < numVertices) {
        matrizAdj[vertice1][vertice2] = peso;
        if (!direcionado) {
            matrizAdj[vertice2][vertice1] = peso; // Se o grafo não for direcionado
        }
    }
}

void GrafoMatriz::remover_aresta(int vertice1, int vertice2) {
    if (vertice1 >= 0 && vertice1 < numVertices && vertice2 >= 0 && vertice2 < numVertices) {
        matrizAdj[vertice1][vertice2] = 0;
        if (!direcionado) {
            matrizAdj[vertice2][vertice1] = 0;
        }
    }
}

void GrafoMatriz::imprimir() const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << matrizAdj[i][j] << " ";
        }
        cout << endl;
    }
}
