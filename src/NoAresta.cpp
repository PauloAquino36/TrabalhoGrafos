#include "../include/NoAresta.h"
#include <iostream>

using namespace std;

// #region Construtor e Destrutor
NoAresta::NoAresta(int idVerticeOrigem, int idVerticeDestino, float peso, int idAresta) {
    this->idVerticeOrigem = idVerticeOrigem;
    this->idVerticeDestino = idVerticeDestino;
    this->peso = peso;
    this->proximo = nullptr;
    this->idAresta = idAresta;
}

NoAresta::~NoAresta() {

}
// #endregion

// Retorna o vertice de origem da aresta
int NoAresta::getOrigem() {
    return idVerticeOrigem;
}

// Retorna o vertice de destino da aresta
int NoAresta::getDestino() {
    return idVerticeDestino;
}

// Retorna o peso da aresta
float NoAresta::getPeso() {
    return peso;
}

int NoAresta::getIdAresta() {
    return idAresta;
}  
// Retorna o proximo Noh aresta
NoAresta* NoAresta::getProximo() {
    return proximo;
}

// Define o proximo Noh aresta
void NoAresta::setProximo(NoAresta* proximo) {
    this->proximo = proximo;
}

// Define o id do vertice de origem
void NoAresta::setVerticeOrigem(int novoId) {
    this->idVerticeOrigem = novoId;
}

// Define o id do vertice de destino
void NoAresta::setVerticeDestino(int novoId) {
    this->idVerticeDestino = novoId;
}