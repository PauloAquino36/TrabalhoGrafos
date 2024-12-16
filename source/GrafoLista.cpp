#include "../headers/GrafoLista.h"
#include <iostream>

using namespace std;

GrafoLista::GrafoLista(int nVertices, bool direcionado) {
    this->numVertices = nVertices;
    this->direcionado = direcionado;

    // Aloca a matriz de adjacência (lista de adjacência)
    listaAdj = new Aresta**[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        listaAdj[i] = new Aresta*[numVertices];
        for (int j = 0; j < numVertices; ++j) {
            listaAdj[i][j] = nullptr; // Inicializa os ponteiros como nulos
        }
    }
}

GrafoLista::~GrafoLista() {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            delete listaAdj[i][j]; // Libera as arestas alocadas
        }
        delete[] listaAdj[i]; // Libera as listas individuais
    }
    delete[] listaAdj; // Libera a matriz de ponteiros
}

void GrafoLista::adicionarAresta(int origem, int destino, int peso) {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return;
    }

    delete listaAdj[origem][destino];

    listaAdj[origem][destino] = new Aresta(destino, peso);

    if (!direcionado) {
        delete listaAdj[destino][origem];
        listaAdj[destino][origem] = new Aresta(origem, peso);
    }
}

void GrafoLista::removerAresta(int origem, int destino) {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return;
    }

    delete listaAdj[origem][destino];
    listaAdj[origem][destino] = nullptr;

    if (!direcionado) {
        delete listaAdj[destino][origem];
        listaAdj[destino][origem] = nullptr;
    }
}

void GrafoLista::imprimir() const {
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertice " << i << ": ";
        for (int j = 0; j < numVertices; ++j) {
            if (listaAdj[i][j] != nullptr) {
                cout << "(" << listaAdj[i][j]->getDestino() << ", " << listaAdj[i][j]->getPeso() << ") ";
            }
        }
        cout << endl;
    }
}

bool GrafoLista::existeAresta(int origem, int destino) const {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return false;
    }

    return listaAdj[origem][destino] != nullptr;
}

int GrafoLista::obterPeso(int origem, int destino) const {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return 0;
    }

    if (listaAdj[origem][destino] != nullptr) {
        return listaAdj[origem][destino]->getPeso();
    }
    return 0;
}
