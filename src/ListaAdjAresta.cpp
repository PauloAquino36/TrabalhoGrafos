#include "../include/ListaAdjAresta.h"
#include "../include/NoAresta.h"
#include <iostream>

using namespace std;

// #region Construtor e Destrutor

/**
 * @brief Construtor da classe ListaAdjAresta.
 */
ListaAdjAresta::ListaAdjAresta() {
    this->cabeca = nullptr;
}

/**
 * @brief Destrutor da classe ListaAdjAresta.
 */
ListaAdjAresta::~ListaAdjAresta() {
    // Desaloca a memoria para cada no da lista de arestas
    NoAresta* atual = this->cabeca;
    while (atual != nullptr) {
        NoAresta* next = atual->getProximo();
        delete atual;
        atual = next;
    }
}
// #endregion

// #region Funcoes auxiliares

/**
 * @brief Retorna o primeiro no da lista (primeira aresta do vertice).
 * @return Ponteiro para o primeiro no da lista.
 */
NoAresta* ListaAdjAresta::getCabeca() {
    return this->cabeca;
}

/**
 * @brief Adiciona uma aresta a lista.
 * @param origem Identificador do vertice de origem.
 * @param destino Identificador do vertice de destino.
 * @param peso Peso da aresta.
 */
void ListaAdjAresta::adicionar_aresta(int origem, int destino, float peso) {
    // Verifica se a aresta ja existe
    NoAresta* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getOrigem() == origem && atual->getDestino() == destino) {
            return;
        }
        atual = atual->getProximo();
    }

    // Adiciona uma nova aresta
    NoAresta* novaAresta = new NoAresta(origem, destino, peso);
    novaAresta->setProximo(this->cabeca);
    this->cabeca = novaAresta;
}

/**
 * @brief Remove uma aresta da lista.
 * @param origem Identificador do vertice de origem.
 * @param destino Identificador do vertice de destino.
 */
void ListaAdjAresta::remover_aresta(int origem, int destino) {
    NoAresta* atual = this->cabeca;
    NoAresta* anterior = nullptr;
    while (atual != nullptr) {
        if (atual->getOrigem() == origem && atual->getDestino() == destino) {
            if (anterior == nullptr) {
                this->cabeca = atual->getProximo();
            } else {
                anterior->setProximo(atual->getProximo());
            }
            delete atual;
            return;
        }
        anterior = atual;
        atual = atual->getProximo();
    }
}

/**
 * @brief Remove a primeira aresta da lista.
 */
void ListaAdjAresta::remover_primeira_aresta() {
    if (this->cabeca == nullptr) {
        cout << "Vertice nao possui arestas" << endl;
        return;
    }

    NoAresta* atual = this->cabeca;
    NoAresta* menor = this->cabeca;

    while (atual != nullptr) {
        if (atual->getDestino() < menor->getDestino()) {
            menor = atual;
        }
        atual = atual->getProximo();
    }
    remover_aresta(menor->getOrigem(), menor->getDestino());
}

/**
 * @brief Retorna o tamanho da lista / numero de vertices vizinhos / grau do vertice.
 * @return Numero de vertices vizinhos.
 */
int ListaAdjAresta::getNumVerticesVizinhos() {
    int tamanho = 0;
    NoAresta* atual = this->cabeca;
    while (atual != nullptr) {
        tamanho++;
        atual = atual->getProximo();
    }
    return tamanho;
}
// #endregion