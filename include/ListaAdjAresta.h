/**
 * @file ListaAdjAresta.h
 * @brief Declaração da classe ListaAdjAresta, que gerencia a lista de adjacência para as arestas.
 */

#ifndef LISTA_ADJ_ARESTA_H
#define LISTA_ADJ_ARESTA_H

#include "NoAresta.h"

class GrafoLista;  // Declaração antecipada para evitar dependências circulares

/**
 * @class ListaAdjAresta
 * @brief Gerencia a lista encadeada de arestas associadas a um vértice.
 */
class ListaAdjAresta {
private:
    NoAresta* cabeca;      ///< Ponteiro para o primeiro nó da lista de arestas.
    GrafoLista* grafo;     ///< Ponteiro para o grafo que utiliza essa lista.

public:
    /**
     * @brief Construtor da classe ListaAdjAresta.
     * @param grafo Ponteiro para o objeto GrafoLista que utiliza essa lista.
     */
    ListaAdjAresta(GrafoLista* grafo);

    /**
     * @brief Destrutor da classe ListaAdjAresta.
     */
    ~ListaAdjAresta();

    /**
     * @brief Retorna o primeiro nó (cabeça) da lista de arestas.
     * @return Ponteiro para o nó inicial da lista.
     */
    NoAresta* getCabeca();

    /**
     * @brief Retorna a quantidade de vértices vizinhos (número de arestas na lista).
     * @return Número de vértices vizinhos.
     */
    int getNumVerticesVizinhos();

    /**
     * @brief Adiciona uma aresta à lista.
     * @param origem Identificador do vértice de origem.
     * @param destino Identificador do vértice de destino.
     * @param peso Peso da aresta.
     */
    void adicionar_aresta(int origem, int destino, float peso);

    /**
     * @brief Remove uma aresta específica da lista.
     * @param origem Identificador do vértice de origem.
     * @param destino Identificador do vértice de destino.
     */
    void remover_aresta(int origem, int destino);

    /**
     * @brief Remove a primeira aresta da lista.
     */
    void remover_primeira_aresta();

    /**
     * @brief Retorna o identificador da aresta que termina no vértice destino.
     * @param destino Identificador do vértice de destino.
     * @return ID da aresta.
     */
    int getIdAresta(int destino);
};

#endif // LISTA_ADJ_ARESTA_H
