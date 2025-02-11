#ifndef LISTA_ADJ_ARESTA_H
#define LISTA_ADJ_ARESTA_H

#include "NoAresta.h"

/**
 * @class ListaAdjAresta
 * @brief Classe que representa uma lista de adjacência de arestas.
 */
class ListaAdjAresta {
private:
    NoAresta* cabeca;           ///< Ponteiro para o primeiro no da lista

public:
    /**
     * @brief Construtor da classe ListaAdjAresta.
     */
    ListaAdjAresta();

    /**
     * @brief Destrutor da classe ListaAdjAresta.
     */
    ~ListaAdjAresta();

    /**
     * @brief Retorna a cabeca da lista de adjacencia de arestas.
     * @return Ponteiro para o primeiro no da lista.
     */
    NoAresta* getCabeca();

    /**
     * @brief Retorna a quantidade de vertices vizinhos.
     * @return Numero de vertices vizinhos.
     */
    int getNumVerticesVizinhos();

    /**
     * @brief Adiciona uma aresta à lista.
     * @param origem Identificador do vertice de origem.
     * @param destino Identificador do vertice de destino.
     * @param peso Peso da aresta.
     */
    void adicionar_aresta(int origem, int destino, float peso);

    /**
     * @brief Remove uma aresta da lista.
     * @param origem Identificador do vertice de origem.
     * @param destino Identificador do vertice de destino.
     */
    void remover_aresta(int origem, int destino);

    /**
     * @brief Remove a primeira aresta da lista.
     */
    void remover_primeira_aresta();
};

#endif // LISTA_ADJ_ARESTA_H