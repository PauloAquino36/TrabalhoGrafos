#include "../headers/Vertice.h"
#include <iostream>

using namespace std;

Vertice::Vertice() 
    : id(-1), peso(0), arestas(nullptr), numArestas(0), capacidade(2) {
    arestas = new Aresta[capacidade];
}

Vertice::Vertice(int id, int peso)
    : id(id), peso(peso), arestas(new Aresta[2]), numArestas(0), capacidade(2) {}

Vertice::Vertice(const Vertice& other)
    : id(other.id), peso(other.peso), numArestas(other.numArestas), capacidade(other.capacidade) {
    arestas = new Aresta[capacidade];
    for (int i = 0; i < numArestas; ++i) {
        arestas[i] = other.arestas[i];
    }
}

Vertice& Vertice::operator=(const Vertice& other) {
    if (this != &other) {
        delete[] arestas;

        id = other.id;
        peso = other.peso;
        numArestas = other.numArestas;
        capacidade = other.capacidade;

        arestas = new Aresta[capacidade];
        for (int i = 0; i < numArestas; ++i) {
            arestas[i] = other.arestas[i];
        }
    }
    return *this;
}

Vertice::~Vertice() {
    delete[] arestas;
}

int Vertice::getId() const {
    return id;
}

void Vertice::setId(int id) {
    this->id = id;
}

int Vertice::getPeso() const {
    return peso;
}

void Vertice::setPeso(int peso) {
    this->peso = peso;
}

void Vertice::adicionarAresta(int destino, int peso) {
    if (existeAresta(destino)) return;

    if (numArestas >= capacidade) redimensionarArestas();

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
}

bool Vertice::existeAresta(int destino) const {
    for (int i = 0; i < numArestas; ++i) {
        if (arestas[i].getDestino() == destino) return true;
    }
    return false;
}

int Vertice::getPesoAresta(int destino) const {
    for (int i = 0; i < numArestas; ++i) {
        if (arestas[i].getDestino() == destino) return arestas[i].getPeso();
    }
    return 0;
}

void Vertice::imprimirArestas() const {
    for (int i = 0; i < numArestas; ++i) {
        cout << "(" << arestas[i].getDestino() << ", " << arestas[i].getPeso() << ") ";
    }
    cout << endl;
}

void Vertice::redimensionarArestas() {
    capacidade *= 2;
    Aresta* novaLista = new Aresta[capacidade];
    for (int i = 0; i < numArestas; ++i) {
        novaLista[i] = arestas[i];
    }
    delete[] arestas;
    arestas = novaLista;
}
