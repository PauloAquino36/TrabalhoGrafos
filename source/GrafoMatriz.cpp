#include "../headers/GrafoMatriz.h"
#include <iostream>

using namespace std;

GrafoMatriz::GrafoMatriz(int nVertices, bool direcionado) {
    this->numVertices = nVertices;
    this->direcionado = direcionado;

    matrizAdj = new Aresta**[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        matrizAdj[i] = new Aresta*[numVertices];
        for (int j = 0; j < numVertices; ++j) {
            matrizAdj[i][j] = nullptr; // Inicializa todos os ponteiros como nulos
        }
    }
}

GrafoMatriz::~GrafoMatriz() {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            delete matrizAdj[i][j]; // Libera as instâncias de Aresta
        }
        delete[] matrizAdj[i]; // Libera as linhas da matriz
    }
    delete[] matrizAdj; // Libera a matriz de ponteiros
}

void GrafoMatriz::adicionarAresta(int vertice1, int vertice2, int peso) {
    if (vertice1 < 0 || vertice1 >= numVertices || vertice2 < 0 || vertice2 >= numVertices) {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return;
    }

    delete matrizAdj[vertice1][vertice2]; // Libera a aresta anterior, se existir
    matrizAdj[vertice1][vertice2] = new Aresta(vertice2, peso);

    if (!direcionado) {
        delete matrizAdj[vertice2][vertice1]; // Libera a aresta anterior, se existir
        matrizAdj[vertice2][vertice1] = new Aresta(vertice1, peso);
    }
}

void GrafoMatriz::removerAresta(int vertice1, int vertice2) {
    if (vertice1 < 0 || vertice1 >= numVertices || vertice2 < 0 || vertice2 >= numVertices) {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return;
    }

    delete matrizAdj[vertice1][vertice2];
    matrizAdj[vertice1][vertice2] = nullptr;

    if (!direcionado) {
        delete matrizAdj[vertice2][vertice1];
        matrizAdj[vertice2][vertice1] = nullptr;
    }
}

void GrafoMatriz::imprimir() const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (matrizAdj[i][j] != nullptr) {
            cout <<  matrizAdj[i][j]->getPeso() << " "; 
            } else {
                cout << "0 "; // Representa ausência de aresta
            }
        }
        cout << endl;
    }
}

int GrafoMatriz::obterPeso(int vertice1, int vertice2) const {
    if (vertice1 < 0 || vertice1 >= numVertices || vertice2 < 0 || vertice2 >= numVertices) {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return 0;
    }

    if (matrizAdj[vertice1][vertice2] != nullptr) {
        return matrizAdj[vertice1][vertice2]->getPeso();
    }
    return 0; // Retorna 0 se não existir aresta
}

bool GrafoMatriz::existeAresta(int vertice1, int vertice2) const {
    if (vertice1 < 0 || vertice1 >= numVertices || vertice2 < 0 || vertice2 >= numVertices) {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return false;
    }

    return matrizAdj[vertice1][vertice2] != nullptr;
}
