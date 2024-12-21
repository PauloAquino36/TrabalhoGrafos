#include "../headers/Aresta.h"

// Construtor padrão
Aresta::Aresta(){
    this->destino = 0;
    this->peso = 0;
    this->origem = 0;
}

// Construtor parametrizad
Aresta::Aresta(int origem, int destino, int peso){
    this->destino = destino;
    this->peso = peso;
    this->origem = origem;
}

// Destrutor
Aresta::~Aresta() {
    // Não há recursos dinâmicos para liberar
}

int Aresta::getDestino() {
    return destino;
}

int Aresta::getPeso() {
    return peso;
}

int Aresta::getOrigem() {
    return origem;
}

void Aresta::setDestino(int destino) {
    this->destino = destino;
}

void Aresta::setPeso(int peso) {
    this->peso = peso;
}

void Aresta::setOrigem(int origem) {
    this->origem = origem;
}
