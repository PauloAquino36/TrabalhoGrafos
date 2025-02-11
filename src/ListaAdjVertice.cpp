#include "../include/ListaAdjVertice.h"
#include "../include/NoVertice.h"
#include <iostream>

using namespace std;

// #region Construtor e Destrutor

/**
 * @brief Construtor da classe ListaAdjVertice.
 */
ListaAdjVertice::ListaAdjVertice() {
    this->cabeca = nullptr;
}

/**
 * @brief Destrutor da classe ListaAdjVertice.
 */
ListaAdjVertice::~ListaAdjVertice() {
    // Desaloca a memoria para cada no da lista de vertices
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        NoVertice* next = atual->getProximo();
        delete atual;
        atual = next;
    }
}
// #endregion

/**
 * @brief Retorna o primeiro no da lista (primeiro vertice do grafo).
 * @return Ponteiro para o primeiro no da lista.
 */
NoVertice* ListaAdjVertice::getCabeca() {
    return this->cabeca;
}

/**
 * @brief Retorna a quantidade de vertices na lista (quantidade total de vertices no grafo).
 * @return Numero de vertices na lista.
 */
int ListaAdjVertice::getNumVertices() {
    int tamanho = 0;
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        tamanho++;
        atual = atual->getProximo();
    }
    return tamanho;
}

/**
 * @brief Retorna o vertice com o identificador especificado.
 * @param id Identificador do vertice.
 * @return Ponteiro para o vertice, ou nullptr se nao encontrado.
 */
NoVertice* ListaAdjVertice::getVertice(int id) {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == id) {
            return atual;
        }
        atual = atual->getProximo();
    }
    return nullptr;
}

/**
 * @brief Adiciona um vertice a lista.
 * @param id Identificador do vertice.
 * @param peso Peso do vertice.
 */
void ListaAdjVertice::adicionar_vertice(int id, float peso) {
    NoVertice* novoNo = new NoVertice(id, peso);
    novoNo->setProximo(this->cabeca);
    this->cabeca = novoNo;
}

/**
 * @brief Adiciona uma aresta ao vertice.
 * @param origem Identificador do vertice de origem.
 * @param destino Identificador do vertice de destino.
 * @param peso Peso da aresta.
 */
void ListaAdjVertice::adicionar_aresta(int origem, int destino, float peso) {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == origem) {
            atual->adicionar_aresta(destino, peso);
        }
        atual = atual->getProximo();
    }
}

/**
 * @brief Remove uma aresta do vertice.
 * @param origem Identificador do vertice de origem.
 * @param destino Identificador do vertice de destino.
 */
void ListaAdjVertice::remover_aresta(int origem, int destino) {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == origem) {
            atual->remover_aresta(destino);
        }
        atual = atual->getProximo();
    }
}

/**
 * @brief Remove a primeira aresta do vertice.
 * @param id Identificador do vertice.
 */
void ListaAdjVertice::remover_primeira_aresta(int id) {
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() == id) {
            atual->remover_primeira_aresta();
        }
        atual = atual->getProximo();
    }
}

/**
 * @brief Remove um vertice da lista.
 * @param id Identificador do vertice.
 */
void ListaAdjVertice::remover_vertice(int id) {
    NoVertice* atual = this->cabeca;
    NoVertice* anterior = nullptr;
    NoVertice* remover = nullptr;
    while (atual != nullptr) {
        if (atual->getIdVertice() == id) {
            if (anterior == nullptr) {
                this->cabeca = atual->getProximo();
            } else {
                anterior->setProximo(atual->getProximo());
            }
            remover = atual;
        }
        // Remove as arestas que apontam para o vertice a ser removido
        atual->remover_aresta(id);
        // Atualiza os ponteiros
        anterior = atual;
        atual = atual->getProximo();
    }
    // Remove o vertice
    delete remover;

    // Recalculando ID dos vertices
    atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->getIdVertice() > id) {
            atual->setIdVertice(atual->getIdVertice() - 1);
        }
        atual = atual->getProximo();
    }

    // Reorganizando as arestas
    atual = this->cabeca;
    while (atual != nullptr) {
        NoAresta* arestaAtual = atual->getArestas()->getCabeca();
        while (arestaAtual != nullptr) {
            if (arestaAtual->getDestino() > id) {
                arestaAtual->setVerticeDestino(arestaAtual->getDestino() - 1);
            }
            arestaAtual = arestaAtual->getProximo();
        }
        atual = atual->getProximo();
    }
}

/**
 * @brief Imprime a lista de adjacencia.
 */
void ListaAdjVertice::imprimir() {
    // Imprime a lista de adjacencia
    cout << "__________________________________________________________________" << endl;
    cout << endl << "--- Lista de Adjacencia ---" << endl << endl;
    NoVertice* atual = this->cabeca;
    while (atual != nullptr) {
        cout << "Vertice " << atual->getIdVertice() << " -> ";
        NoAresta* atualAresta = atual->getArestas()->getCabeca();
        while (atualAresta != nullptr) {
            cout << atualAresta->getDestino() << "(" << atualAresta->getPeso() << ")" << "  ";
            atualAresta = atualAresta->getProximo();
        }
        cout << endl;
        atual = atual->getProximo();
    }
    cout << "__________________________________________________________________" << endl << endl;
}