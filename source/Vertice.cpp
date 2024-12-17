#include "../headers/Vertice.h"
#include <iostream>

using namespace std;

Vertice::Vertice() 
    : id(-1), peso(0), arestas(nullptr), numArestas(0), capacidade(0) {}

Vertice::Vertice(int id, int peso)
    : id(id), peso(peso), arestas(nullptr), numArestas(0), capacidade(2) {
    arestas = new Aresta[capacidade];
}

Vertice::~Vertice() {
    delete[] arestas;
}

int Vertice::getId() {
    return id;
}

void Vertice::setId(int id) {
    this->id = id;
}

int Vertice::getPeso() {
    return peso;
}

void Vertice::setPeso(int peso) {
    this->peso = peso;
}

void Vertice::adicionarAresta(int destino, int peso) {
    if (existeAresta(destino)) {
        cout << "Aresta já existe para o destino " << destino << endl;
        return;
    }

    if (numArestas >= capacidade) {
        redimensionarArestas();
    }

    arestas[numArestas++] = Aresta(destino, peso);
}

void Vertice::removerAresta(int destino) {
    for (int i = 0; i < numArestas; ++i) {
        if (arestas[i].getDestino() == destino) {
            for (int j = i; j < numArestas - 1; ++j) {
                arestas[j] = arestas[j + 1];
            }
            --numArestas;
            return;
        }
    }
    cout << "Aresta para o destino " << destino << " não encontrada." << endl;
}

bool Vertice::existeAresta(int destino) {
    for (int i = 0; i < numArestas; ++i) {
        if (arestas[i].getDestino() == destino) {
            return true;
        }
    }
    return false;
}

void Vertice::imprimirArestas() {
    cout << "Arestas do vertice " << id << ": ";
    for (int i = 0; i < numArestas; ++i) {
        cout << "(" << arestas[i].getDestino() << ", " << arestas[i].getPeso() << ") ";
    }
    cout << endl;
}

void Vertice::redimensionarArestas() {
    capacidade *= 2; // Duplique a capacidade
    Aresta* novaLista = new Aresta[capacidade];
    for (int i = 0; i < numArestas; ++i) {
        novaLista[i] = arestas[i];
    }
    delete[] arestas; // Libere a memória antiga
    arestas = novaLista;
}

int Vertice::getPesoAresta(int destino) {
    for (int i = 0; i < numArestas; ++i) {
        if (arestas[i].getDestino() == destino) {
            return arestas[i].getPeso(); // Retorna o peso da aresta para o destino
        }
    }
    return 0; // Retorna 0 se não existir aresta para o destino
}
