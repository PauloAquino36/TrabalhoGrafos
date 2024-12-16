#include "../headers/Aresta.h"

Aresta::Aresta(int destino, int peso) : destino(destino), peso(peso) {}
Aresta::~Aresta() {}

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

std::ostream& operator<<(std::ostream& os, const Aresta& aresta) {
    os << "(" << aresta.getDestino() << ", peso: " << aresta.getPeso() << ")";
    return os;
}
