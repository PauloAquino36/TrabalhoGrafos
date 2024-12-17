#include "../headers/GrafoMatriz.h"
#include <iostream>

using namespace std;

GrafoMatriz::GrafoMatriz(int nVertices, bool direcionado) 
    : numVertices(nVertices), direcionado(direcionado) {
    vertices = new Vertice[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        vertices[i] = Vertice(i); // Inicializa cada vértice com seu ID
    }
}

GrafoMatriz::~GrafoMatriz() {
    delete[] vertices; // Libera a memória alocada para os vértices
}

void GrafoMatriz::adicionarAresta(int origem, int destino, int peso) {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return;
    }

    vertices[origem].adicionarAresta(destino, peso);

    if (!direcionado) {
        vertices[destino].adicionarAresta(origem, peso);
    }
}

void GrafoMatriz::removerAresta(int origem, int destino) {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return;
    }

    vertices[origem].removerAresta(destino);

    if (!direcionado) {
        vertices[destino].removerAresta(origem);
    }
}

void GrafoMatriz::imprimir() {
    cout << "Matriz de Adjacencia:" << endl;

    // Imprime o cabeçalho com os índices das colunas
    cout << "    ";
    for (int i = 0; i < numVertices; ++i) {
        cout << i << " ";
    }
    cout << endl;

    // Imprime a matriz linha por linha
    for (int i = 0; i < numVertices; ++i) {
        cout << i << " | "; // Índice da linha
        for (int j = 0; j < numVertices; ++j) {
            // Verifica se existe uma aresta entre i e j
            if (vertices[i].existeAresta(j)) {
                cout << vertices[i].getPesoAresta(j) << " "; // Peso da aresta
            } else {
                cout << "0 "; // Sem aresta
            }
        }
        cout << endl;
    }
}


int GrafoMatriz::obterPeso(int origem, int destino) {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return 0;
    }

    return vertices[origem].getPeso();
}

bool GrafoMatriz::existeAresta(int origem, int destino) {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        cout << "Erro: Vértices fora do intervalo válido." << endl;
        return false;
    }

    return vertices[origem].existeAresta(destino);
}

int GrafoMatriz::getNumVertices() {
    return numVertices;
}

bool GrafoMatriz::ehDirecionado() {
    return direcionado;
}
