#include "../include/NoAresta.h"
#include <iostream>

using namespace std;

// Construtor
NoAresta::NoAresta(int idVerticeOrigem, int idVerticeDestino, int peso) {
    this->idVerticeOrigem = idVerticeOrigem;
    this->idVerticeDestino = idVerticeDestino;
    this->peso = peso;
    this->proximo = nullptr;
}

// Destrutor
NoAresta::~NoAresta() {

}

int NoAresta::getOrigem() {
    return idVerticeOrigem;
}

int NoAresta::getDestino() {
    return idVerticeDestino;
}

int NoAresta::getPeso() {
    return peso;
}

NoAresta* NoAresta::getProximo() {
    return proximo;
}

void NoAresta::setProximo(NoAresta* proximo) {
    this->proximo = proximo;
}

void NoAresta::setVerticeOrigem(int novoId) {
    this->idVerticeOrigem = novoId;
}

void NoAresta::setVerticeDestino(int novoId) {
    this->idVerticeDestino = novoId;
}