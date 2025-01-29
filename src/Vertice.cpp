#include "../include/Vertice.h"
#include <iostream>

using namespace std;

Vertice::Vertice(){
    nArestas = 0; //Valor Padrao
    id = 0; //Valor Padrao
    peso = 0; //Valor Padrao
    arestas = nullptr; //Valor Padrao
}

Vertice::Vertice(int id, int peso){
    this->id = id;
    this->peso = peso;
    arestas = nullptr; //Valor Padrao
}

Vertice::~Vertice() {
    Aresta* atual = arestas;
    while (atual != nullptr) {
        Aresta* prox = atual->getProx();
        delete atual;
        atual = prox;
    }
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

Aresta* Vertice::getArestas() {
    return arestas;
}

bool Vertice::existeAresta(int destino) {
    Aresta* atual = arestas;
    while (atual != nullptr) {
        if (atual->getDestino() == destino) return true;
        atual = atual->getProx();
    }
    return false;
}

int Vertice::getGrauVertice() {
    int grau = 0;
    Aresta* atual = arestas;
    while (atual != nullptr) {
        grau++;
        atual = atual->getProx();
    }
    return grau;
}

void Vertice::setArestas(Aresta* arestas) {
    this->arestas = arestas;
}