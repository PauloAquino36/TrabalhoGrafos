#include "../include/NoVertice.h"
#include <iostream>

using namespace std;

// Construtor
NoVertice::NoVertice(int idVertice, int peso) {
    this->idVertice = idVertice;
    this->peso = peso;
    this->proximo = nullptr;
    this->numArestas = 0;
    this->arestas = new ListaAdjAresta();
}

// Destrutor
NoVertice::~NoVertice() {
    delete[] arestas;
}

int NoVertice::getIdVertice() {
    return this->idVertice;
}

int NoVertice::getPesoVertice() {
    return this->peso;
}

NoVertice* NoVertice::getProximo() {
    return this->proximo;
}

void NoVertice::setProximo(NoVertice* proximo) {
    this->proximo = proximo;
}

ListaAdjAresta* NoVertice::getArestas() {
    return this->arestas;
}

int NoVertice::getNumArestas() {
    return this->numArestas;
}

int NoVertice::getNumVizinhos() {
    return this->arestas->getNumVertices();
}

void NoVertice::adicionar_aresta(int destino, int peso) {
    this->arestas->adicionar_aresta(this->idVertice, destino, peso);
    this->numArestas++;
}