#include "../include/Aresta.h"

// Construtor
Aresta::Aresta(int idDestino, int peso){
    this->idDestino = idDestino;
    this->peso = peso;
    this->proxima = nullptr;
}

// Destrutor
Aresta::~Aresta() {
    delete[] proxima;
}

int Aresta::getIdOrigem() {
    return this->idOrigem;
}

int Aresta::getIdDestino() {
    return this->idDestino;
}

int Aresta::getPeso() {
    return this->peso;
}

Aresta* Aresta::getProxima() {
    return this->proxima;
}

void Aresta::setPeso(int peso) {
    this->peso = peso;
}

void Aresta::setProxima(Aresta* proxima) {
    if(getIdDestino() == proxima->getIdOrigem())
    this->proxima = proxima;
}
