#include "../include/NoAresta.h"
#include <iostream>

using namespace std;

// #region Construtor e Destrutor

/**
 * @brief Construtor da classe NoAresta.
 * @param idVerticeOrigem Identificador do vertice de origem.
 * @param idVerticeDestino Identificador do vertice de destino.
 * @param peso Peso da aresta.
 */
NoAresta::NoAresta(int idVerticeOrigem, int idVerticeDestino, float peso) {
    this->idVerticeOrigem = idVerticeOrigem;
    this->idVerticeDestino = idVerticeDestino;
    this->peso = peso;
    this->proximo = nullptr;
}

/**
 * @brief Destrutor da classe NoAresta.
 */
NoAresta::~NoAresta() {

}
// #endregion

/**
 * @brief Retorna o vertice de origem da aresta.
 * @return Identificador do vertice de origem.
 */
int NoAresta::getOrigem() {
    return idVerticeOrigem;
}

/**
 * @brief Retorna o vertice de destino da aresta.
 * @return Identificador do vertice de destino.
 */
int NoAresta::getDestino() {
    return idVerticeDestino;
}

/**
 * @brief Retorna o peso da aresta.
 * @return Peso da aresta.
 */
float NoAresta::getPeso() {
    return peso;
}

/**
 * @brief Retorna o proximo Noh aresta.
 * @return Ponteiro para o proximo Noh aresta.
 */
NoAresta* NoAresta::getProximo() {
    return proximo;
}

/**
 * @brief Define o proximo Noh aresta.
 * @param proximo Ponteiro para o proximo Noh aresta.
 */
void NoAresta::setProximo(NoAresta* proximo) {
    this->proximo = proximo;
}

/**
 * @brief Define o id do vertice de origem.
 * @param novoId Novo identificador do vertice de origem.
 */
void NoAresta::setVerticeOrigem(int novoId) {
    this->idVerticeOrigem = novoId;
}

/**
 * @brief Define o id do vertice de destino.
 * @param novoId Novo identificador do vertice de destino.
 */
void NoAresta::setVerticeDestino(int novoId) {
    this->idVerticeDestino = novoId;
}