#include "../include/Vertice.h"
#include "../include/ListaAdjVertice.h"
#include <iostream>

using namespace std;

Vertice::Vertice(int id, int peso){
    this->id = id;
    this->peso = peso;
    this->arestas = new ListaAdjAresta[numArestas];
}

Vertice::~Vertice() {
    delete[] arestas;
}

int Vertice::getId() {
    return id;
}

int Vertice::getPeso() {
    return peso;
}

int Vertice::getNumArestas() {
    return numArestas;
}

ListaAdjAresta* Vertice::getArestas() {
    return arestas;
}

void Vertice::setId(int id) {
    this->id = id;
}

void Vertice::setPeso(int peso) {
    this->peso = peso;
}

void Vertice::setNumArestas(int numArestas) {
    this->numArestas = numArestas;
}

void Vertice::adicionarVertice(int id, int peso) {
    arestas->adicionar(id, peso);
}

void Vertice::adicionarAresta(int origem, int destino, int peso) {
    arestas->adicionar(origem, destino, peso);
}