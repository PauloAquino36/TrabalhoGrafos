/**
 * @file ListaAdjVertice.h
 * @brief Declaração da classe ListaAdjVertice, que gerencia a lista de adjacência para os vértices.
 */

#ifndef LISTA_ADJ_VERTICE_H
#define LISTA_ADJ_VERTICE_H

#include "NoVertice.h"

class GrafoLista;  // Declaração antecipada

/**
 * @class ListaAdjVertice
 * @brief Gerencia a lista encadeada de vértices em um grafo.
 */
class ListaAdjVertice {
private:
    NoVertice* cabeca;  ///< Ponteiro para o primeiro nó da lista de vértices.
    GrafoLista* grafo;  ///< Ponteiro para o grafo que utiliza essa lista.

public:
    /**
     * @brief Construtor da classe ListaAdjVertice.
     * @param grafo Ponteiro para o objeto GrafoLista que utiliza essa lista.
     */
    ListaAdjVertice(GrafoLista* grafo);

    /**
     * @brief Destrutor da classe ListaAdjVertice.
     */
    ~ListaAdjVertice();

    /**
     * @brief Retorna o primeiro nó (cabeça) da lista de vértices.
     * @return Ponteiro para o nó inicial da lista.
     */
    NoVertice* getCabeca();

    /**
     * @brief Retorna a quantidade total de vértices na lista.
     * @return Número de vértices.
     */
    int getNumVertices();

    /**
     * @brief Retorna um vértice específico da lista.
     * @param id Identificador do vértice.
     * @return Ponteiro para o nó do vértice.
     */
    NoVertice* getVertice(int id);

    /**
     * @brief Adiciona um vértice à lista.
     * @param id Identificador do novo vértice.
     * @param peso Peso do vértice.
     */
    void adicionar_vertice(int id, float peso);

    /**
     * @brief Adiciona uma aresta ao vértice.
     * @param origem Identificador do vértice de origem.
     * @param destino Identificador do vértice de destino.
     * @param peso Peso da aresta.
     */
    void adicionar_aresta(int origem, int destino, float peso);

    /**
     * @brief Remove uma aresta do vértice.
     * @param origem Identificador do vértice de origem.
     * @param destino Identificador do vértice de destino.
     */
    void remover_aresta(int origem, int destino);

    /**
     * @brief Remove a primeira aresta do vértice.
     * @param id Identificador do vértice.
     */
    void remover_primeira_aresta(int id);

    /**
     * @brief Remove um vértice da lista.
     * @param id Identificador do vértice a ser removido.
     */
    void remover_vertice(int id);

    /**
     * @brief Retorna o ID da aresta entre dois vértices.
     * @param origem Identificador do vértice de origem.
     * @param destino Identificador do vértice de destino.
     * @return ID da aresta.
     */
    int getIDAresta(int origem, int destino);

    /**
     * @brief Imprime a lista de adjacência dos vértices.
     */
    void imprimir();
};

#endif // LISTA_ADJ_VERTICE_H
