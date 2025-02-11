#include "../include/NoVertice.h"
#include <iostream>

using namespace std;

// Construtor
NoVertice::NoVertice(int idVertice, float peso) {
    this->idVertice = idVertice;
    this->peso = peso;
    this->proximo = nullptr;
    this->numArestas = 0;
    this->arestas = new ListaAdjAresta();
}

// Destrutor
NoVertice::~NoVertice() {
    delete arestas;
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

int NoVertice::setIdVertice(int novoId) {
    this->idVertice = novoId;
    return this->idVertice;
}

ListaAdjAresta* NoVertice::getArestas() {
    return this->arestas;
}

int NoVertice::getNumArestas() {
    return this->numArestas;
}

int NoVertice::getNumVizinhos() {
    return this->arestas->getNumVerticesVizinhos();
}

void NoVertice::adicionar_aresta(int destino, float peso) {
    this->arestas->adicionar_aresta(this->idVertice, destino, peso);
    this->numArestas++;
}

void NoVertice::remover_aresta(int destino) {
    this->arestas->remover_aresta(this->idVertice, destino);
    this->numArestas--;
}

void NoVertice::remover_primeira_aresta() {
    this->arestas->remover_primeira_aresta();
    this->numArestas--;
}