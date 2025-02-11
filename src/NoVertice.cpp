#include "../include/NoVertice.h"
#include <iostream>

using namespace std;

// #region Construtor e Destrutor
NoVertice::NoVertice(int idVertice, float peso) {
    this->idVertice = idVertice;
    this->peso = peso;
    this->proximo = nullptr;
    this->numArestas = 0;
    this->arestas = new ListaAdjAresta();
}

NoVertice::~NoVertice() {
    delete arestas;
}
// #endregion

// Retorna o id do vertice
int NoVertice::getIdVertice() {
    return this->idVertice;
}

// Retorna o peso do vertice
float NoVertice::getPesoVertice() {
    return this->peso;
}

// Retorna o proximo no vertice
NoVertice* NoVertice::getProximo() {
    return this->proximo;
}

// Define o proximo no vertice
void NoVertice::setProximo(NoVertice* proximo) {
    this->proximo = proximo;
}

// Define o id do vertice
int NoVertice::setIdVertice(int novoId) {
    this->idVertice = novoId;
    return this->idVertice;
}

// Retorna a lista de arestas do vertice
ListaAdjAresta* NoVertice::getArestas() {
    return this->arestas;
}

// Retorna a quantidade de arestas do vertice
int NoVertice::getNumArestas() {
    return this->numArestas;
}

// Retorna a quantidade de vizinhos do vertice
int NoVertice::getNumVizinhos() {
    return this->arestas->getNumVerticesVizinhos();
}

// Adiciona uma aresta ao vertice
void NoVertice::adicionar_aresta(int destino, float peso) {
    this->arestas->adicionar_aresta(this->idVertice, destino, peso);
    this->numArestas++;
}

// Remove uma aresta do vertice
void NoVertice::remover_aresta(int destino) {
    this->arestas->remover_aresta(this->idVertice, destino);
    this->numArestas--;
}

// Remove a primeira aresta do vertice
void NoVertice::remover_primeira_aresta() {
    this->arestas->remover_primeira_aresta();
    this->numArestas--;
}