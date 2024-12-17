#include "../headers/Aresta.h"

// Construtor padrão
Aresta::Aresta() : destino(-1), peso(0) {
}

// Construtor parametrizad
Aresta::Aresta(int destino, int peso) : destino(destino), peso(peso) {
    // Inicializa os atributos com os valores fornecidos
}

// Destrutor
Aresta::~Aresta() {
    // Não há recursos dinâmicos para liberar
}

int Aresta::getDestino() const {
    return destino;
}

int Aresta::getPeso() const {
    return peso;
}

void Aresta::setDestino(int destino) {
    this->destino = destino;
}

void Aresta::setPeso(int peso) {
    this->peso = peso;
}
